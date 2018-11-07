/*
 * The Clear BSD License
 * Copyright (c) 2018, NXP Semiconductors, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
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

/*
 * How to set up clock using clock driver functions:
 *
 * 1. Setup clock sources.
 *
 * 2. Set up all dividers.
 *
 * 3. Set up all selectors to provide selected clocks.
 */

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Clocks v4.1
processor: LPC804
package_id: LPC804M101JDH24
mcu_data: ksdk2_0
processor_version: 0.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

#include "fsl_power.h"
#include "fsl_clock.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 ************************ BOARD_InitBootClocks function ************************
 ******************************************************************************/
void BOARD_InitBootClocks(void)
{
	/* System clock frequency is half of FRO. */
    BOARD_BootClockFRO30M();
}

/*******************************************************************************
 ******************** Configuration BOARD_BootClockFRO18M **********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockFRO18M
outputs:
- {id: CAPT_clock.outFreq, value: 4.5 MHz}
- {id: FROHF_clock.outFreq, value: 18 MHz}
- {id: System_clock.outFreq, value: 9 MHz}
sources:
- {id: SYSCON.fro_osc.outFreq, value: 18 MHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockFRO18M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockFRO18M configuration
 ******************************************************************************/
void BOARD_BootClockFRO18M(void)
{
    /*!< Set up the clock sources */
    /*!< Set up FRO */
    POWER_DisablePD(kPDRUNCFG_PD_FRO_OUT);                   /*!< Ensure FRO is on  */
    POWER_DisablePD(kPDRUNCFG_PD_FRO);                      /*!< Ensure FRO is on  */
    CLOCK_SetFroOscFreq(kCLOCK_FroOscOut18M);                    /*!< Set up FRO freq */
    CLOCK_SetMainClkSrc(kCLOCK_MainClkSrcFro);            /*!< slecte fro for main clock */
    CLOCK_Select(kFRG0_Clk_From_Fro);                     /*!< slecte fro for frg0 */
    CLOCK_SetFRG0ClkFreq(9000000U);                     /*!< slecte frg0 freq */
    CLOCK_Select(kCLKOUT_From_Fro);                         /*!< slecte FRO for CLKOUT */
    CLOCK_Select(kCAPT_Clk_From_Fro_Div);                   /*!< slecte FRO_DIV for CAPT */
    CLOCK_Select(kADC_Clk_From_Fro);                       /*!< slecte FRO for ADC */
    CLOCK_SetCoreSysClkDiv(1U);
    CLOCK_SetClkDivider(kCLOCK_DivClkOut, 0U);    /*!< set ClkOut clock div */
    CLOCK_SetClkDivider(kCLOCK_DivAdcClk, 0U);     /*!< set ADC clock div */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKFRO18M_CORE_CLOCK;
}

/*******************************************************************************
 ******************** Configuration BOARD_BootClockFRO24M **********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockFRO24M
outputs:
- {id: CAPT_clock.outFreq, value: 6 MHz}
- {id: FROHF_clock.outFreq, value: 24 MHz}
- {id: System_clock.outFreq, value: 12 MHz}
sources:
- {id: SYSCON.fro_osc.outFreq, value: 24 MHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockFRO24M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockFRO24M configuration
 ******************************************************************************/
void BOARD_BootClockFRO24M(void)
{
    /*!< Set up the clock sources */
    /*!< Set up FRO */
    POWER_DisablePD(kPDRUNCFG_PD_FRO_OUT);                   /*!< Ensure FRO is on  */
    POWER_DisablePD(kPDRUNCFG_PD_FRO);                      /*!< Ensure FRO is on  */
    CLOCK_SetFroOscFreq(kCLOCK_FroOscOut24M);                    /*!< Set up FRO freq */
    CLOCK_SetMainClkSrc(kCLOCK_MainClkSrcFro);            /*!< slecte fro for main clock */
    CLOCK_Select(kFRG0_Clk_From_Fro);                     /*!< slecte fro for frg0 */
    CLOCK_SetFRG0ClkFreq(12000000U);                     /*!< slecte frg0 freq */
    CLOCK_Select(kCLKOUT_From_Fro);                         /*!< slecte FRO for CLKOUT */
    CLOCK_Select(kCAPT_Clk_From_Fro_Div);                   /*!< slecte FRO_DIV for CAPT */
    CLOCK_Select(kADC_Clk_From_Fro);                       /*!< slecte FRO for ADC */
    CLOCK_SetCoreSysClkDiv(1U);
    CLOCK_SetClkDivider(kCLOCK_DivClkOut, 0U);    /*!< set ClkOut clock div */
    CLOCK_SetClkDivider(kCLOCK_DivAdcClk, 0U);     /*!< set ADC clock div */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKFRO24M_CORE_CLOCK;
}

/*******************************************************************************
 ******************** Configuration BOARD_BootClockFRO30M **********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockFRO30M
called_from_default_init: true
outputs:
- {id: CAPT_clock.outFreq, value: 7.5 MHz}
- {id: FROHF_clock.outFreq, value: 30 MHz}
- {id: System_clock.outFreq, value: 15 MHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockFRO30M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockFRO30M configuration
 ******************************************************************************/
void BOARD_BootClockFRO30M(void)
{
    /*!< Set up the clock sources */
    /*!< Set up FRO */
    POWER_DisablePD(kPDRUNCFG_PD_FRO_OUT);                   /*!< Ensure FRO is on  */
    POWER_DisablePD(kPDRUNCFG_PD_FRO);                      /*!< Ensure FRO is on  */
    CLOCK_SetFroOscFreq(kCLOCK_FroOscOut30M);                    /*!< Set up FRO freq */
    CLOCK_SetMainClkSrc(kCLOCK_MainClkSrcFro);            /*!< slecte fro for main clock */
    CLOCK_Select(kFRG0_Clk_From_Fro);                     /*!< slecte fro for frg0 */
    CLOCK_SetFRG0ClkFreq(15000000U);                     /*!< slecte frg0 freq */
    CLOCK_Select(kCLKOUT_From_Fro);                         /*!< slecte FRO for CLKOUT */
    CLOCK_Select(kCAPT_Clk_From_Fro_Div);                   /*!< slecte FRO_DIV for CAPT */
    CLOCK_Select(kADC_Clk_From_Fro);                       /*!< slecte FRO for ADC */
    CLOCK_SetCoreSysClkDiv(1U);
    CLOCK_SetClkDivider(kCLOCK_DivClkOut, 0U);    /*!< set ClkOut clock div */
    CLOCK_SetClkDivider(kCLOCK_DivAdcClk, 0U);     /*!< set ADC clock div */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKFRO30M_CORE_CLOCK;
}

