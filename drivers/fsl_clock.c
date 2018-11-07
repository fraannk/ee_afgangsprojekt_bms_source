/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_common.h"
#include "fsl_clock.h"
#include "rom_api.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

/* External clock rate.
 * Either external clk in rate or system oscillator frequency.
 */
uint32_t g_Ext_Clk_Freq = 0U;
/** Lower power oscillator rate in Hz.*/
uint32_t g_LP_Osc_Freq = 1000000U;
/** Fro oscillator rate in Hz */
uint32_t g_Fro_Osc_Freq = 0U;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 * @brief   Get FRG input clock frequency.
 * @param fractional clock register base address.
 * @return  input clock frequency.
 */
static uint32_t CLOCK_GetFRGInputClkFreq(volatile uint32_t *base);

/*
 * @brief Update clock source.
 * @param base clock register base address.
 * @param mask clock source update enable bit mask value.
 */
static void CLOCK_UpdateClkSrc(volatile uint32_t *base, uint32_t mask);

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t CLOCK_GetFRGInputClkFreq(volatile uint32_t *base)
{
    uint32_t sel = CLK_FRG_SEL_REG_MAP(base) & SYSCON_FRG_FRGCLKSEL_SEL_MASK;

    if (sel == 0U)
    {
        return CLOCK_GetFroFreq();
    }
    else if (sel == 1U)
    {
        return CLOCK_GetMainClkFreq();
    }
    else
    {
        return 0;
    }
}

static bool CLOCK_SetFRGClkFreq(volatile uint32_t *base, uint32_t freq)
{
    assert(freq);

    uint32_t input = CLOCK_GetFRGInputClkFreq(base);
    uint32_t mul;

    if ((freq > input) || (input / freq >= 2U))
    {
        return false;
    }

    mul = ((uint64_t)(input - freq) << 8U) / ((uint64_t)freq);

    CLK_FRG_DIV_REG_MAP(base) = SYSCON_FRG_FRGDIV_DIV_MASK;
    CLK_FRG_MUL_REG_MAP(base) = SYSCON_FRG_FRGMULT_MULT(mul);

    return true;
}

static void CLOCK_UpdateClkSrc(volatile uint32_t *base, uint32_t mask)
{
    assert(base);

    *base &= ~mask;
    *base |= mask;
    while ((*base & mask) == 0U)
    {
    }
}

bool CLOCK_SetFRG0ClkFreq(uint32_t freq)
{
    return CLOCK_SetFRGClkFreq(((volatile uint32_t *)(&SYSCON->FRG[0].FRGDIV)), freq);
}

uint32_t CLOCK_GetFRG0ClkFreq(void)
{
    return ((uint64_t)(CLOCK_GetFRGInputClkFreq((volatile uint32_t *)(&SYSCON->FRG[0].FRGDIV)) << 8U)) /
           ((SYSCON->FRG[0].FRGMULT & SYSCON_FRG_FRGMULT_MULT_MASK) + 256U);
}

uint32_t CLOCK_GetMainClkFreq(void)
{
    uint32_t freq = 0U;

    switch (SYSCON->MAINCLKSEL)
    {
        case 0U:
            freq = CLOCK_GetFroFreq();
            break;

        case 1U:
            freq = CLOCK_GetExtClkFreq();
            break;

        case 2U:
            freq = CLOCK_GetLPOscFreq();
            break;

        case 3U:
            freq = CLOCK_GetFroFreq() >> 1U;
            break;
        default:
            break;
    }

    return freq;
}

uint32_t CLOCK_GetFroFreq(void)
{
    return g_Fro_Osc_Freq / 2;
}

uint32_t CLOCK_GetClockOutClkFreq(void)
{
    uint32_t divider = SYSCON->CLKOUTDIV & 0xffU, freq = 0U;

    switch (SYSCON->CLKOUTSEL)
    {
        case 0U:
            freq = CLOCK_GetFroFreq();
            break;

        case 1U:
            freq = CLOCK_GetMainClkFreq();
            break;

        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;

        case 4U:
            freq = CLOCK_GetLPOscFreq();
            break;

        default:
            break;
    }

    return divider == 0U ? 0U : (freq / divider);
}

uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq;

    switch (clockName)
    {
        case kCLOCK_CoreSysClk:
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_MainClk:
            freq = CLOCK_GetMainClkFreq();
            break;
        case kCLOCK_Fro:
            freq = CLOCK_GetFroFreq();
            break;
        case kCLOCK_FroDiv:
            freq = CLOCK_GetFroFreq() >> 1U;
            break;
        case kCLOCK_ExtClk:
            freq = CLOCK_GetExtClkFreq();
            break;
        case kCLOCK_LPOsc:
            freq = CLOCK_GetLPOscFreq();
            break;
        case kCLOCK_Frg0:
            freq = CLOCK_GetFRG0ClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

void CLOCK_InitExtClkin(uint32_t clkInFreq)
{
    /* remove the pull up and pull down resistors in the IOCON */
    IOCON->PIO[IOCON_INDEX_PIO0_1] &= ~IOCON_PIO_MODE_MASK;
    /* enable the 1 bit functions for CLKIN */
    SWM0->PINENABLE0 &= ~SWM_PINENABLE0_CLKIN_MASK;
    /* record the external clock rate */
    g_Ext_Clk_Freq = clkInFreq;
}

void CLOCK_SetMainClkSrc(clock_main_clk_src_t src)
{
    uint32_t mainPreMux = CLK_MAIN_CLK_MUX_GET_PRE_MUX(src);

    SYSCON->MAINCLKSEL = (SYSCON->MAINCLKSEL & (~SYSCON_MAINCLKSEL_SEL_MASK)) | SYSCON_MAINCLKSEL_SEL(mainPreMux);
    CLOCK_UpdateClkSrc((volatile uint32_t *)(&(SYSCON->MAINCLKUEN)), SYSCON_MAINCLKUEN_ENA_MASK);
}

void CLOCK_SetFroOscFreq(clock_fro_osc_freq_t freq)
{
    g_Fro_Osc_Freq = freq * 1000;
    LPC_PWRD_API->set_fro_frequency(freq);
}
