/*
** ###################################################################
**     Processors:          LPC804M101JDH20
**                          LPC804M101JDH24
**                          LPC804M101JHI33
**                          LPC804M111JDH24
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC804 User manual Rev.1.0  24 Jan 2018
**     Version:             rev. 1.0, 2018-01-09
**     Build:               b180529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC804
**
**     The Clear BSD License
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2018 NXP
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without
**     modification, are permitted (subject to the limitations in the
**     disclaimer below) provided that the following conditions are met:
**
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**
**     * Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from
**       this software without specific prior written permission.
**
**     NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
**     GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
**     HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
**     WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
**     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
**     LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
**     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
**     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
**     BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
**     WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
**     OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
**     IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-01-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file LPC804.h
 * @version 1.0
 * @date 2018-01-09
 * @brief CMSIS Peripheral Access Layer for LPC804
 *
 * CMSIS Peripheral Access Layer for LPC804
 */

#ifndef _LPC804_H_
#define _LPC804_H_                               /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  SPI0_IRQn                    = 0,                /**< SPI0 interrupt */
  Reserved17_IRQn              = 1,                /**< Reserved interrupt */
  DAC0_IRQn                    = 2,                /**< DAC0 interrupt */
  USART0_IRQn                  = 3,                /**< USART0 interrupt */
  USART1_IRQn                  = 4,                /**< USART1 interrupt */
  Reserved21_IRQn              = 5,                /**< Reserved interrupt */
  Reserved22_IRQn              = 6,                /**< Reserved interrupt */
  I2C1_IRQn                    = 7,                /**< I2C1 interrupt */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  Reserved25_IRQn              = 9,                /**< Reserved interrupt */
  MRT0_IRQn                    = 10,               /**< Multi-rate timer interrupt */
  CMP_CAPT_IRQn                = 11,               /**< Analog comparator interrupt or Capacitive Touch interrupt */
  WDT_IRQn                     = 12,               /**< Windowed watchdog timer interrupt */
  BOD_IRQn                     = 13,               /**< BOD interrupts */
  FLASH_IRQn                   = 14,               /**< flash interrupt */
  WKT_IRQn                     = 15,               /**< Self-wake-up timer interrupt */
  ADC_SEQA_IRQn                = 16,               /**< ADC sequence A completion. */
  ADC_SEQB_IRQn                = 17,               /**< ADC sequence B completion. */
  ADC_THCMP_IRQn               = 18,               /**< ADC threshold compare and error. */
  ADC_OVR_IRQn                 = 19,               /**< ADC overrun */
  Reserved36_IRQn              = 20,               /**< Reserved interrupt */
  Reserved37_IRQn              = 21,               /**< Reserved interrupt */
  Reserved38_IRQn              = 22,               /**< Reserved interrupt */
  CTIMER0_IRQn                 = 23,               /**< Timer interrupt */
  PIN_INT0_IRQn                = 24,               /**< Pin interrupt 0 or pattern match engine slice 0 interrupt */
  PIN_INT1_IRQn                = 25,               /**< Pin interrupt 1 or pattern match engine slice 1 interrupt */
  PIN_INT2_IRQn                = 26,               /**< Pin interrupt 2 or pattern match engine slice 2 interrupt */
  PIN_INT3_IRQn                = 27,               /**< Pin interrupt 3 or pattern match engine slice 3 interrupt */
  PIN_INT4_IRQn                = 28,               /**< Pin interrupt 4 or pattern match engine slice 4 interrupt */
  PIN_INT5_IRQn                = 29,               /**< Pin interrupt 5 or pattern match engine slice 5 interrupt */
  PIN_INT6_IRQn                = 30,               /**< Pin interrupt 6 or pattern match engine slice 6 interrupt */
  PIN_INT7_IRQn                = 31                /**< Pin interrupt 7 or pattern match engine slice 7 interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_LPC804.h"             /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ACOMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACOMP_Peripheral_Access_Layer ACOMP Peripheral Access Layer
 * @{
 */

/** ACOMP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Comparator control register, offset: 0x0 */
  __IO uint32_t LAD;                               /**< Voltage ladder register, offset: 0x4 */
} ACOMP_Type;

/* ----------------------------------------------------------------------------
   -- ACOMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACOMP_Register_Masks ACOMP Register Masks
 * @{
 */

/*! @name CTRL - Comparator control register */
/*! @{ */
#define ACOMP_CTRL_EDGESEL_MASK                  (0x18U)
#define ACOMP_CTRL_EDGESEL_SHIFT                 (3U)
#define ACOMP_CTRL_EDGESEL(x)                    (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_EDGESEL_SHIFT)) & ACOMP_CTRL_EDGESEL_MASK)
#define ACOMP_CTRL_COMPSA_MASK                   (0x40U)
#define ACOMP_CTRL_COMPSA_SHIFT                  (6U)
#define ACOMP_CTRL_COMPSA(x)                     (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMPSA_SHIFT)) & ACOMP_CTRL_COMPSA_MASK)
#define ACOMP_CTRL_COMP_VP_SEL_MASK              (0x700U)
#define ACOMP_CTRL_COMP_VP_SEL_SHIFT             (8U)
#define ACOMP_CTRL_COMP_VP_SEL(x)                (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMP_VP_SEL_SHIFT)) & ACOMP_CTRL_COMP_VP_SEL_MASK)
#define ACOMP_CTRL_COMP_VM_SEL_MASK              (0x3800U)
#define ACOMP_CTRL_COMP_VM_SEL_SHIFT             (11U)
#define ACOMP_CTRL_COMP_VM_SEL(x)                (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMP_VM_SEL_SHIFT)) & ACOMP_CTRL_COMP_VM_SEL_MASK)
#define ACOMP_CTRL_EDGECLR_MASK                  (0x100000U)
#define ACOMP_CTRL_EDGECLR_SHIFT                 (20U)
#define ACOMP_CTRL_EDGECLR(x)                    (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_EDGECLR_SHIFT)) & ACOMP_CTRL_EDGECLR_MASK)
#define ACOMP_CTRL_COMPSTAT_MASK                 (0x200000U)
#define ACOMP_CTRL_COMPSTAT_SHIFT                (21U)
#define ACOMP_CTRL_COMPSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMPSTAT_SHIFT)) & ACOMP_CTRL_COMPSTAT_MASK)
#define ACOMP_CTRL_COMPEDGE_MASK                 (0x800000U)
#define ACOMP_CTRL_COMPEDGE_SHIFT                (23U)
#define ACOMP_CTRL_COMPEDGE(x)                   (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMPEDGE_SHIFT)) & ACOMP_CTRL_COMPEDGE_MASK)
#define ACOMP_CTRL_INTENA_MASK                   (0x1000000U)
#define ACOMP_CTRL_INTENA_SHIFT                  (24U)
#define ACOMP_CTRL_INTENA(x)                     (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_INTENA_SHIFT)) & ACOMP_CTRL_INTENA_MASK)
#define ACOMP_CTRL_HYS_MASK                      (0x6000000U)
#define ACOMP_CTRL_HYS_SHIFT                     (25U)
#define ACOMP_CTRL_HYS(x)                        (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_HYS_SHIFT)) & ACOMP_CTRL_HYS_MASK)
/*! @} */

/*! @name LAD - Voltage ladder register */
/*! @{ */
#define ACOMP_LAD_LADEN_MASK                     (0x1U)
#define ACOMP_LAD_LADEN_SHIFT                    (0U)
#define ACOMP_LAD_LADEN(x)                       (((uint32_t)(((uint32_t)(x)) << ACOMP_LAD_LADEN_SHIFT)) & ACOMP_LAD_LADEN_MASK)
#define ACOMP_LAD_LADSEL_MASK                    (0x3EU)
#define ACOMP_LAD_LADSEL_SHIFT                   (1U)
#define ACOMP_LAD_LADSEL(x)                      (((uint32_t)(((uint32_t)(x)) << ACOMP_LAD_LADSEL_SHIFT)) & ACOMP_LAD_LADSEL_MASK)
#define ACOMP_LAD_LADREF_MASK                    (0x40U)
#define ACOMP_LAD_LADREF_SHIFT                   (6U)
#define ACOMP_LAD_LADREF(x)                      (((uint32_t)(((uint32_t)(x)) << ACOMP_LAD_LADREF_SHIFT)) & ACOMP_LAD_LADREF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ACOMP_Register_Masks */


/* ACOMP - Peripheral instance base addresses */
/** Peripheral ACOMP base address */
#define ACOMP_BASE                               (0x40024000u)
/** Peripheral ACOMP base pointer */
#define ACOMP                                    ((ACOMP_Type *)ACOMP_BASE)
/** Array initializer of ACOMP peripheral base addresses */
#define ACOMP_BASE_ADDRS                         { ACOMP_BASE }
/** Array initializer of ACOMP peripheral base pointers */
#define ACOMP_BASE_PTRS                          { ACOMP }

/*!
 * @}
 */ /* end of group ACOMP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< ADC Control register. Contains the clock divide value, resolution selection, sampling time selection, and mode controls., offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SEQ_CTRL[2];                       /**< ADC Conversion Sequence-n control register: Controls triggering and channel selection for conversion sequence-n. Also specifies interrupt mode for sequence-n., array offset: 0x8, array step: 0x4 */
  __I  uint32_t SEQ_GDAT[2];                       /**< ADC Sequence-n Global Data register. This register contains the result of the most recent ADC conversion performed under sequence-n., array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_1[8];
  __I  uint32_t DAT[12];                           /**< ADC Channel N Data register. This register contains the result of the most recent conversion completed on channel N., array offset: 0x20, array step: 0x4 */
  __IO uint32_t THR0_LOW;                          /**< ADC Low Compare Threshold register 0: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 0., offset: 0x50 */
  __IO uint32_t THR1_LOW;                          /**< ADC Low Compare Threshold register 1: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 1., offset: 0x54 */
  __IO uint32_t THR0_HIGH;                         /**< ADC High Compare Threshold register 0: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 0., offset: 0x58 */
  __IO uint32_t THR1_HIGH;                         /**< ADC High Compare Threshold register 1: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 1., offset: 0x5C */
  __IO uint32_t CHAN_THRSEL;                       /**< ADC Channel-Threshold Select register. Specifies which set of threshold compare registers are to be used for each channel, offset: 0x60 */
  __IO uint32_t INTEN;                             /**< ADC Interrupt Enable register. This register contains enable bits that enable the sequence-A, sequence-B, threshold compare and data overrun interrupts to be generated., offset: 0x64 */
  __IO uint32_t FLAGS;                             /**< ADC Flags register. Contains the four interrupt/DMA trigger flags and the individual component overrun and threshold-compare flags. (The overrun bits replicate information stored in the result registers)., offset: 0x68 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name CTRL - ADC Control register. Contains the clock divide value, resolution selection, sampling time selection, and mode controls. */
/*! @{ */
#define ADC_CTRL_CLKDIV_MASK                     (0xFFU)
#define ADC_CTRL_CLKDIV_SHIFT                    (0U)
#define ADC_CTRL_CLKDIV(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_CLKDIV_SHIFT)) & ADC_CTRL_CLKDIV_MASK)
#define ADC_CTRL_LPWRMODE_MASK                   (0x400U)
#define ADC_CTRL_LPWRMODE_SHIFT                  (10U)
#define ADC_CTRL_LPWRMODE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_LPWRMODE_SHIFT)) & ADC_CTRL_LPWRMODE_MASK)
/*! @} */

/*! @name SEQ_CTRL - ADC Conversion Sequence-n control register: Controls triggering and channel selection for conversion sequence-n. Also specifies interrupt mode for sequence-n. */
/*! @{ */
#define ADC_SEQ_CTRL_CHANNELS_MASK               (0xFFFU)
#define ADC_SEQ_CTRL_CHANNELS_SHIFT              (0U)
#define ADC_SEQ_CTRL_CHANNELS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_CHANNELS_SHIFT)) & ADC_SEQ_CTRL_CHANNELS_MASK)
#define ADC_SEQ_CTRL_TRIGGER_MASK                (0x7000U)
#define ADC_SEQ_CTRL_TRIGGER_SHIFT               (12U)
#define ADC_SEQ_CTRL_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_TRIGGER_SHIFT)) & ADC_SEQ_CTRL_TRIGGER_MASK)
#define ADC_SEQ_CTRL_TRIGPOL_MASK                (0x40000U)
#define ADC_SEQ_CTRL_TRIGPOL_SHIFT               (18U)
#define ADC_SEQ_CTRL_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_TRIGPOL_SHIFT)) & ADC_SEQ_CTRL_TRIGPOL_MASK)
#define ADC_SEQ_CTRL_SYNCBYPASS_MASK             (0x80000U)
#define ADC_SEQ_CTRL_SYNCBYPASS_SHIFT            (19U)
#define ADC_SEQ_CTRL_SYNCBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_SYNCBYPASS_SHIFT)) & ADC_SEQ_CTRL_SYNCBYPASS_MASK)
#define ADC_SEQ_CTRL_TSAMP_MASK                  (0x1F00000U)
#define ADC_SEQ_CTRL_TSAMP_SHIFT                 (20U)
#define ADC_SEQ_CTRL_TSAMP(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_TSAMP_SHIFT)) & ADC_SEQ_CTRL_TSAMP_MASK)
#define ADC_SEQ_CTRL_START_MASK                  (0x4000000U)
#define ADC_SEQ_CTRL_START_SHIFT                 (26U)
#define ADC_SEQ_CTRL_START(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_START_SHIFT)) & ADC_SEQ_CTRL_START_MASK)
#define ADC_SEQ_CTRL_BURST_MASK                  (0x8000000U)
#define ADC_SEQ_CTRL_BURST_SHIFT                 (27U)
#define ADC_SEQ_CTRL_BURST(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_BURST_SHIFT)) & ADC_SEQ_CTRL_BURST_MASK)
#define ADC_SEQ_CTRL_SINGLESTEP_MASK             (0x10000000U)
#define ADC_SEQ_CTRL_SINGLESTEP_SHIFT            (28U)
#define ADC_SEQ_CTRL_SINGLESTEP(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_SINGLESTEP_SHIFT)) & ADC_SEQ_CTRL_SINGLESTEP_MASK)
#define ADC_SEQ_CTRL_LOWPRIO_MASK                (0x20000000U)
#define ADC_SEQ_CTRL_LOWPRIO_SHIFT               (29U)
#define ADC_SEQ_CTRL_LOWPRIO(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_LOWPRIO_SHIFT)) & ADC_SEQ_CTRL_LOWPRIO_MASK)
#define ADC_SEQ_CTRL_MODE_MASK                   (0x40000000U)
#define ADC_SEQ_CTRL_MODE_SHIFT                  (30U)
#define ADC_SEQ_CTRL_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_MODE_SHIFT)) & ADC_SEQ_CTRL_MODE_MASK)
#define ADC_SEQ_CTRL_SEQ_ENA_MASK                (0x80000000U)
#define ADC_SEQ_CTRL_SEQ_ENA_SHIFT               (31U)
#define ADC_SEQ_CTRL_SEQ_ENA(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_SEQ_ENA_SHIFT)) & ADC_SEQ_CTRL_SEQ_ENA_MASK)
/*! @} */

/* The count of ADC_SEQ_CTRL */
#define ADC_SEQ_CTRL_COUNT                       (2U)

/*! @name SEQ_GDAT - ADC Sequence-n Global Data register. This register contains the result of the most recent ADC conversion performed under sequence-n. */
/*! @{ */
#define ADC_SEQ_GDAT_RESULT_MASK                 (0xFFF0U)
#define ADC_SEQ_GDAT_RESULT_SHIFT                (4U)
#define ADC_SEQ_GDAT_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_RESULT_SHIFT)) & ADC_SEQ_GDAT_RESULT_MASK)
#define ADC_SEQ_GDAT_THCMPRANGE_MASK             (0x30000U)
#define ADC_SEQ_GDAT_THCMPRANGE_SHIFT            (16U)
#define ADC_SEQ_GDAT_THCMPRANGE(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_THCMPRANGE_SHIFT)) & ADC_SEQ_GDAT_THCMPRANGE_MASK)
#define ADC_SEQ_GDAT_THCMPCROSS_MASK             (0xC0000U)
#define ADC_SEQ_GDAT_THCMPCROSS_SHIFT            (18U)
#define ADC_SEQ_GDAT_THCMPCROSS(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_THCMPCROSS_SHIFT)) & ADC_SEQ_GDAT_THCMPCROSS_MASK)
#define ADC_SEQ_GDAT_CHN_MASK                    (0x3C000000U)
#define ADC_SEQ_GDAT_CHN_SHIFT                   (26U)
#define ADC_SEQ_GDAT_CHN(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_CHN_SHIFT)) & ADC_SEQ_GDAT_CHN_MASK)
#define ADC_SEQ_GDAT_OVERRUN_MASK                (0x40000000U)
#define ADC_SEQ_GDAT_OVERRUN_SHIFT               (30U)
#define ADC_SEQ_GDAT_OVERRUN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_OVERRUN_SHIFT)) & ADC_SEQ_GDAT_OVERRUN_MASK)
#define ADC_SEQ_GDAT_DATAVALID_MASK              (0x80000000U)
#define ADC_SEQ_GDAT_DATAVALID_SHIFT             (31U)
#define ADC_SEQ_GDAT_DATAVALID(x)                (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_DATAVALID_SHIFT)) & ADC_SEQ_GDAT_DATAVALID_MASK)
/*! @} */

/* The count of ADC_SEQ_GDAT */
#define ADC_SEQ_GDAT_COUNT                       (2U)

/*! @name DAT - ADC Channel N Data register. This register contains the result of the most recent conversion completed on channel N. */
/*! @{ */
#define ADC_DAT_RESULT_MASK                      (0xFFF0U)
#define ADC_DAT_RESULT_SHIFT                     (4U)
#define ADC_DAT_RESULT(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DAT_RESULT_SHIFT)) & ADC_DAT_RESULT_MASK)
#define ADC_DAT_THCMPRANGE_MASK                  (0x30000U)
#define ADC_DAT_THCMPRANGE_SHIFT                 (16U)
#define ADC_DAT_THCMPRANGE(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_DAT_THCMPRANGE_SHIFT)) & ADC_DAT_THCMPRANGE_MASK)
#define ADC_DAT_THCMPCROSS_MASK                  (0xC0000U)
#define ADC_DAT_THCMPCROSS_SHIFT                 (18U)
#define ADC_DAT_THCMPCROSS(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_DAT_THCMPCROSS_SHIFT)) & ADC_DAT_THCMPCROSS_MASK)
#define ADC_DAT_CHANNEL_MASK                     (0x3C000000U)
#define ADC_DAT_CHANNEL_SHIFT                    (26U)
#define ADC_DAT_CHANNEL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DAT_CHANNEL_SHIFT)) & ADC_DAT_CHANNEL_MASK)
#define ADC_DAT_OVERRUN_MASK                     (0x40000000U)
#define ADC_DAT_OVERRUN_SHIFT                    (30U)
#define ADC_DAT_OVERRUN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DAT_OVERRUN_SHIFT)) & ADC_DAT_OVERRUN_MASK)
#define ADC_DAT_DATAVALID_MASK                   (0x80000000U)
#define ADC_DAT_DATAVALID_SHIFT                  (31U)
#define ADC_DAT_DATAVALID(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_DAT_DATAVALID_SHIFT)) & ADC_DAT_DATAVALID_MASK)
/*! @} */

/* The count of ADC_DAT */
#define ADC_DAT_COUNT                            (12U)

/*! @name THR0_LOW - ADC Low Compare Threshold register 0: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 0. */
/*! @{ */
#define ADC_THR0_LOW_THRLOW_MASK                 (0xFFF0U)
#define ADC_THR0_LOW_THRLOW_SHIFT                (4U)
#define ADC_THR0_LOW_THRLOW(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_THR0_LOW_THRLOW_SHIFT)) & ADC_THR0_LOW_THRLOW_MASK)
/*! @} */

/*! @name THR1_LOW - ADC Low Compare Threshold register 1: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 1. */
/*! @{ */
#define ADC_THR1_LOW_THRLOW_MASK                 (0xFFF0U)
#define ADC_THR1_LOW_THRLOW_SHIFT                (4U)
#define ADC_THR1_LOW_THRLOW(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_THR1_LOW_THRLOW_SHIFT)) & ADC_THR1_LOW_THRLOW_MASK)
/*! @} */

/*! @name THR0_HIGH - ADC High Compare Threshold register 0: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 0. */
/*! @{ */
#define ADC_THR0_HIGH_THRHIGH_MASK               (0xFFF0U)
#define ADC_THR0_HIGH_THRHIGH_SHIFT              (4U)
#define ADC_THR0_HIGH_THRHIGH(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_THR0_HIGH_THRHIGH_SHIFT)) & ADC_THR0_HIGH_THRHIGH_MASK)
/*! @} */

/*! @name THR1_HIGH - ADC High Compare Threshold register 1: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 1. */
/*! @{ */
#define ADC_THR1_HIGH_THRHIGH_MASK               (0xFFF0U)
#define ADC_THR1_HIGH_THRHIGH_SHIFT              (4U)
#define ADC_THR1_HIGH_THRHIGH(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_THR1_HIGH_THRHIGH_SHIFT)) & ADC_THR1_HIGH_THRHIGH_MASK)
/*! @} */

/*! @name CHAN_THRSEL - ADC Channel-Threshold Select register. Specifies which set of threshold compare registers are to be used for each channel */
/*! @{ */
#define ADC_CHAN_THRSEL_CH0_THRSEL_MASK          (0x1U)
#define ADC_CHAN_THRSEL_CH0_THRSEL_SHIFT         (0U)
#define ADC_CHAN_THRSEL_CH0_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH0_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH0_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH1_THRSEL_MASK          (0x2U)
#define ADC_CHAN_THRSEL_CH1_THRSEL_SHIFT         (1U)
#define ADC_CHAN_THRSEL_CH1_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH1_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH1_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH2_THRSEL_MASK          (0x4U)
#define ADC_CHAN_THRSEL_CH2_THRSEL_SHIFT         (2U)
#define ADC_CHAN_THRSEL_CH2_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH2_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH2_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH3_THRSEL_MASK          (0x8U)
#define ADC_CHAN_THRSEL_CH3_THRSEL_SHIFT         (3U)
#define ADC_CHAN_THRSEL_CH3_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH3_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH3_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH4_THRSEL_MASK          (0x10U)
#define ADC_CHAN_THRSEL_CH4_THRSEL_SHIFT         (4U)
#define ADC_CHAN_THRSEL_CH4_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH4_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH4_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH5_THRSEL_MASK          (0x20U)
#define ADC_CHAN_THRSEL_CH5_THRSEL_SHIFT         (5U)
#define ADC_CHAN_THRSEL_CH5_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH5_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH5_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH6_THRSEL_MASK          (0x40U)
#define ADC_CHAN_THRSEL_CH6_THRSEL_SHIFT         (6U)
#define ADC_CHAN_THRSEL_CH6_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH6_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH6_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH7_THRSEL_MASK          (0x80U)
#define ADC_CHAN_THRSEL_CH7_THRSEL_SHIFT         (7U)
#define ADC_CHAN_THRSEL_CH7_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH7_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH7_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH8_THRSEL_MASK          (0x100U)
#define ADC_CHAN_THRSEL_CH8_THRSEL_SHIFT         (8U)
#define ADC_CHAN_THRSEL_CH8_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH8_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH8_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH9_THRSEL_MASK          (0x200U)
#define ADC_CHAN_THRSEL_CH9_THRSEL_SHIFT         (9U)
#define ADC_CHAN_THRSEL_CH9_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH9_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH9_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH10_THRSEL_MASK         (0x400U)
#define ADC_CHAN_THRSEL_CH10_THRSEL_SHIFT        (10U)
#define ADC_CHAN_THRSEL_CH10_THRSEL(x)           (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH10_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH10_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH11_THRSEL_MASK         (0x800U)
#define ADC_CHAN_THRSEL_CH11_THRSEL_SHIFT        (11U)
#define ADC_CHAN_THRSEL_CH11_THRSEL(x)           (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH11_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH11_THRSEL_MASK)
/*! @} */

/*! @name INTEN - ADC Interrupt Enable register. This register contains enable bits that enable the sequence-A, sequence-B, threshold compare and data overrun interrupts to be generated. */
/*! @{ */
#define ADC_INTEN_SEQA_INTEN_MASK                (0x1U)
#define ADC_INTEN_SEQA_INTEN_SHIFT               (0U)
#define ADC_INTEN_SEQA_INTEN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_SEQA_INTEN_SHIFT)) & ADC_INTEN_SEQA_INTEN_MASK)
#define ADC_INTEN_SEQB_INTEN_MASK                (0x2U)
#define ADC_INTEN_SEQB_INTEN_SHIFT               (1U)
#define ADC_INTEN_SEQB_INTEN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_SEQB_INTEN_SHIFT)) & ADC_INTEN_SEQB_INTEN_MASK)
#define ADC_INTEN_OVR_INTEN_MASK                 (0x4U)
#define ADC_INTEN_OVR_INTEN_SHIFT                (2U)
#define ADC_INTEN_OVR_INTEN(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_OVR_INTEN_SHIFT)) & ADC_INTEN_OVR_INTEN_MASK)
#define ADC_INTEN_ADCMPINTEN0_MASK               (0x18U)
#define ADC_INTEN_ADCMPINTEN0_SHIFT              (3U)
#define ADC_INTEN_ADCMPINTEN0(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN0_SHIFT)) & ADC_INTEN_ADCMPINTEN0_MASK)
#define ADC_INTEN_ADCMPINTEN1_MASK               (0x60U)
#define ADC_INTEN_ADCMPINTEN1_SHIFT              (5U)
#define ADC_INTEN_ADCMPINTEN1(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN1_SHIFT)) & ADC_INTEN_ADCMPINTEN1_MASK)
#define ADC_INTEN_ADCMPINTEN2_MASK               (0x180U)
#define ADC_INTEN_ADCMPINTEN2_SHIFT              (7U)
#define ADC_INTEN_ADCMPINTEN2(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN2_SHIFT)) & ADC_INTEN_ADCMPINTEN2_MASK)
#define ADC_INTEN_ADCMPINTEN3_MASK               (0x600U)
#define ADC_INTEN_ADCMPINTEN3_SHIFT              (9U)
#define ADC_INTEN_ADCMPINTEN3(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN3_SHIFT)) & ADC_INTEN_ADCMPINTEN3_MASK)
#define ADC_INTEN_ADCMPINTEN4_MASK               (0x1800U)
#define ADC_INTEN_ADCMPINTEN4_SHIFT              (11U)
#define ADC_INTEN_ADCMPINTEN4(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN4_SHIFT)) & ADC_INTEN_ADCMPINTEN4_MASK)
#define ADC_INTEN_ADCMPINTEN5_MASK               (0x6000U)
#define ADC_INTEN_ADCMPINTEN5_SHIFT              (13U)
#define ADC_INTEN_ADCMPINTEN5(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN5_SHIFT)) & ADC_INTEN_ADCMPINTEN5_MASK)
#define ADC_INTEN_ADCMPINTEN6_MASK               (0x18000U)
#define ADC_INTEN_ADCMPINTEN6_SHIFT              (15U)
#define ADC_INTEN_ADCMPINTEN6(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN6_SHIFT)) & ADC_INTEN_ADCMPINTEN6_MASK)
#define ADC_INTEN_ADCMPINTEN7_MASK               (0x60000U)
#define ADC_INTEN_ADCMPINTEN7_SHIFT              (17U)
#define ADC_INTEN_ADCMPINTEN7(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN7_SHIFT)) & ADC_INTEN_ADCMPINTEN7_MASK)
#define ADC_INTEN_ADCMPINTEN8_MASK               (0x180000U)
#define ADC_INTEN_ADCMPINTEN8_SHIFT              (19U)
#define ADC_INTEN_ADCMPINTEN8(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN8_SHIFT)) & ADC_INTEN_ADCMPINTEN8_MASK)
#define ADC_INTEN_ADCMPINTEN9_MASK               (0x600000U)
#define ADC_INTEN_ADCMPINTEN9_SHIFT              (21U)
#define ADC_INTEN_ADCMPINTEN9(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN9_SHIFT)) & ADC_INTEN_ADCMPINTEN9_MASK)
#define ADC_INTEN_ADCMPINTEN10_MASK              (0x1800000U)
#define ADC_INTEN_ADCMPINTEN10_SHIFT             (23U)
#define ADC_INTEN_ADCMPINTEN10(x)                (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN10_SHIFT)) & ADC_INTEN_ADCMPINTEN10_MASK)
#define ADC_INTEN_ADCMPINTEN11_MASK              (0x6000000U)
#define ADC_INTEN_ADCMPINTEN11_SHIFT             (25U)
#define ADC_INTEN_ADCMPINTEN11(x)                (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN11_SHIFT)) & ADC_INTEN_ADCMPINTEN11_MASK)
/*! @} */

/*! @name FLAGS - ADC Flags register. Contains the four interrupt/DMA trigger flags and the individual component overrun and threshold-compare flags. (The overrun bits replicate information stored in the result registers). */
/*! @{ */
#define ADC_FLAGS_THCMP0_MASK                    (0x1U)
#define ADC_FLAGS_THCMP0_SHIFT                   (0U)
#define ADC_FLAGS_THCMP0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP0_SHIFT)) & ADC_FLAGS_THCMP0_MASK)
#define ADC_FLAGS_THCMP1_MASK                    (0x2U)
#define ADC_FLAGS_THCMP1_SHIFT                   (1U)
#define ADC_FLAGS_THCMP1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP1_SHIFT)) & ADC_FLAGS_THCMP1_MASK)
#define ADC_FLAGS_THCMP2_MASK                    (0x4U)
#define ADC_FLAGS_THCMP2_SHIFT                   (2U)
#define ADC_FLAGS_THCMP2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP2_SHIFT)) & ADC_FLAGS_THCMP2_MASK)
#define ADC_FLAGS_THCMP3_MASK                    (0x8U)
#define ADC_FLAGS_THCMP3_SHIFT                   (3U)
#define ADC_FLAGS_THCMP3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP3_SHIFT)) & ADC_FLAGS_THCMP3_MASK)
#define ADC_FLAGS_THCMP4_MASK                    (0x10U)
#define ADC_FLAGS_THCMP4_SHIFT                   (4U)
#define ADC_FLAGS_THCMP4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP4_SHIFT)) & ADC_FLAGS_THCMP4_MASK)
#define ADC_FLAGS_THCMP5_MASK                    (0x20U)
#define ADC_FLAGS_THCMP5_SHIFT                   (5U)
#define ADC_FLAGS_THCMP5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP5_SHIFT)) & ADC_FLAGS_THCMP5_MASK)
#define ADC_FLAGS_THCMP6_MASK                    (0x40U)
#define ADC_FLAGS_THCMP6_SHIFT                   (6U)
#define ADC_FLAGS_THCMP6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP6_SHIFT)) & ADC_FLAGS_THCMP6_MASK)
#define ADC_FLAGS_THCMP7_MASK                    (0x80U)
#define ADC_FLAGS_THCMP7_SHIFT                   (7U)
#define ADC_FLAGS_THCMP7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP7_SHIFT)) & ADC_FLAGS_THCMP7_MASK)
#define ADC_FLAGS_THCMP8_MASK                    (0x100U)
#define ADC_FLAGS_THCMP8_SHIFT                   (8U)
#define ADC_FLAGS_THCMP8(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP8_SHIFT)) & ADC_FLAGS_THCMP8_MASK)
#define ADC_FLAGS_THCMP9_MASK                    (0x200U)
#define ADC_FLAGS_THCMP9_SHIFT                   (9U)
#define ADC_FLAGS_THCMP9(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP9_SHIFT)) & ADC_FLAGS_THCMP9_MASK)
#define ADC_FLAGS_THCMP10_MASK                   (0x400U)
#define ADC_FLAGS_THCMP10_SHIFT                  (10U)
#define ADC_FLAGS_THCMP10(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP10_SHIFT)) & ADC_FLAGS_THCMP10_MASK)
#define ADC_FLAGS_THCMP11_MASK                   (0x800U)
#define ADC_FLAGS_THCMP11_SHIFT                  (11U)
#define ADC_FLAGS_THCMP11(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP11_SHIFT)) & ADC_FLAGS_THCMP11_MASK)
#define ADC_FLAGS_OVERRUN0_MASK                  (0x1000U)
#define ADC_FLAGS_OVERRUN0_SHIFT                 (12U)
#define ADC_FLAGS_OVERRUN0(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN0_SHIFT)) & ADC_FLAGS_OVERRUN0_MASK)
#define ADC_FLAGS_OVERRUN1_MASK                  (0x2000U)
#define ADC_FLAGS_OVERRUN1_SHIFT                 (13U)
#define ADC_FLAGS_OVERRUN1(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN1_SHIFT)) & ADC_FLAGS_OVERRUN1_MASK)
#define ADC_FLAGS_OVERRUN2_MASK                  (0x4000U)
#define ADC_FLAGS_OVERRUN2_SHIFT                 (14U)
#define ADC_FLAGS_OVERRUN2(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN2_SHIFT)) & ADC_FLAGS_OVERRUN2_MASK)
#define ADC_FLAGS_OVERRUN3_MASK                  (0x8000U)
#define ADC_FLAGS_OVERRUN3_SHIFT                 (15U)
#define ADC_FLAGS_OVERRUN3(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN3_SHIFT)) & ADC_FLAGS_OVERRUN3_MASK)
#define ADC_FLAGS_OVERRUN4_MASK                  (0x10000U)
#define ADC_FLAGS_OVERRUN4_SHIFT                 (16U)
#define ADC_FLAGS_OVERRUN4(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN4_SHIFT)) & ADC_FLAGS_OVERRUN4_MASK)
#define ADC_FLAGS_OVERRUN5_MASK                  (0x20000U)
#define ADC_FLAGS_OVERRUN5_SHIFT                 (17U)
#define ADC_FLAGS_OVERRUN5(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN5_SHIFT)) & ADC_FLAGS_OVERRUN5_MASK)
#define ADC_FLAGS_OVERRUN6_MASK                  (0x40000U)
#define ADC_FLAGS_OVERRUN6_SHIFT                 (18U)
#define ADC_FLAGS_OVERRUN6(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN6_SHIFT)) & ADC_FLAGS_OVERRUN6_MASK)
#define ADC_FLAGS_OVERRUN7_MASK                  (0x80000U)
#define ADC_FLAGS_OVERRUN7_SHIFT                 (19U)
#define ADC_FLAGS_OVERRUN7(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN7_SHIFT)) & ADC_FLAGS_OVERRUN7_MASK)
#define ADC_FLAGS_OVERRUN8_MASK                  (0x100000U)
#define ADC_FLAGS_OVERRUN8_SHIFT                 (20U)
#define ADC_FLAGS_OVERRUN8(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN8_SHIFT)) & ADC_FLAGS_OVERRUN8_MASK)
#define ADC_FLAGS_OVERRUN9_MASK                  (0x200000U)
#define ADC_FLAGS_OVERRUN9_SHIFT                 (21U)
#define ADC_FLAGS_OVERRUN9(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN9_SHIFT)) & ADC_FLAGS_OVERRUN9_MASK)
#define ADC_FLAGS_OVERRUN10_MASK                 (0x400000U)
#define ADC_FLAGS_OVERRUN10_SHIFT                (22U)
#define ADC_FLAGS_OVERRUN10(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN10_SHIFT)) & ADC_FLAGS_OVERRUN10_MASK)
#define ADC_FLAGS_OVERRUN11_MASK                 (0x800000U)
#define ADC_FLAGS_OVERRUN11_SHIFT                (23U)
#define ADC_FLAGS_OVERRUN11(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN11_SHIFT)) & ADC_FLAGS_OVERRUN11_MASK)
#define ADC_FLAGS_SEQA_OVR_MASK                  (0x1000000U)
#define ADC_FLAGS_SEQA_OVR_SHIFT                 (24U)
#define ADC_FLAGS_SEQA_OVR(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQA_OVR_SHIFT)) & ADC_FLAGS_SEQA_OVR_MASK)
#define ADC_FLAGS_SEQB_OVR_MASK                  (0x2000000U)
#define ADC_FLAGS_SEQB_OVR_SHIFT                 (25U)
#define ADC_FLAGS_SEQB_OVR(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQB_OVR_SHIFT)) & ADC_FLAGS_SEQB_OVR_MASK)
#define ADC_FLAGS_SEQA_INT_MASK                  (0x10000000U)
#define ADC_FLAGS_SEQA_INT_SHIFT                 (28U)
#define ADC_FLAGS_SEQA_INT(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQA_INT_SHIFT)) & ADC_FLAGS_SEQA_INT_MASK)
#define ADC_FLAGS_SEQB_INT_MASK                  (0x20000000U)
#define ADC_FLAGS_SEQB_INT_SHIFT                 (29U)
#define ADC_FLAGS_SEQB_INT(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQB_INT_SHIFT)) & ADC_FLAGS_SEQB_INT_MASK)
#define ADC_FLAGS_THCMP_INT_MASK                 (0x40000000U)
#define ADC_FLAGS_THCMP_INT_SHIFT                (30U)
#define ADC_FLAGS_THCMP_INT(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP_INT_SHIFT)) & ADC_FLAGS_THCMP_INT_MASK)
#define ADC_FLAGS_OVR_INT_MASK                   (0x80000000U)
#define ADC_FLAGS_OVR_INT_SHIFT                  (31U)
#define ADC_FLAGS_OVR_INT(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVR_INT_SHIFT)) & ADC_FLAGS_OVR_INT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base address */
#define ADC_BASE                                 (0x4001C000u)
/** Peripheral ADC base pointer */
#define ADC                                      ((ADC_Type *)ADC_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_SEQ_IRQS                             { ADC_SEQA_IRQn, ADC_SEQB_IRQn }
#define ADC_THCMP_IRQS                           { ADC_THCMP_IRQn }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CAPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAPT_Peripheral_Access_Layer CAPT Peripheral Access Layer
 * @{
 */

/** CAPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Configuration and control to setup the functional clock, the rules, and the pin selections and rules., offset: 0x0 */
  __IO uint32_t STATUS;                            /**< Status from triggers and time-outs including if in a poll now. Some are used for interrupts., offset: 0x4 */
  __IO uint32_t POLL_TCNT;                         /**< This sets up the polling counter and measurement counter rules., offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t INTENSET;                          /**< Interrupt enable, offset: 0x10 */
  __IO uint32_t INTENCLR;                          /**< Interrupt enable clear, offset: 0x14 */
  __I  uint32_t INTSTAT;                           /**< Interrupt status (mask of STATUS and INTEN), offset: 0x18 */
       uint8_t RESERVED_1[4];
  __I  uint32_t TOUCH;                             /**< Last touch event (touch or no-touch) in context., offset: 0x20 */
       uint8_t RESERVED_2[4056];
  __I  uint32_t ID;                                /**< Block ID., offset: 0xFFC */
} CAPT_Type;

/* ----------------------------------------------------------------------------
   -- CAPT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAPT_Register_Masks CAPT Register Masks
 * @{
 */

/*! @name CTRL - Configuration and control to setup the functional clock, the rules, and the pin selections and rules. */
/*! @{ */
#define CAPT_CTRL_POLLMODE_MASK                  (0x3U)
#define CAPT_CTRL_POLLMODE_SHIFT                 (0U)
#define CAPT_CTRL_POLLMODE(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_POLLMODE_SHIFT)) & CAPT_CTRL_POLLMODE_MASK)
#define CAPT_CTRL_TYPE_MASK                      (0xCU)
#define CAPT_CTRL_TYPE_SHIFT                     (2U)
#define CAPT_CTRL_TYPE(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_TYPE_SHIFT)) & CAPT_CTRL_TYPE_MASK)
#define CAPT_CTRL_TRIGGER_MASK                   (0x10U)
#define CAPT_CTRL_TRIGGER_SHIFT                  (4U)
#define CAPT_CTRL_TRIGGER(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_TRIGGER_SHIFT)) & CAPT_CTRL_TRIGGER_MASK)
#define CAPT_CTRL_WAIT_MASK                      (0x20U)
#define CAPT_CTRL_WAIT_SHIFT                     (5U)
#define CAPT_CTRL_WAIT(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_WAIT_SHIFT)) & CAPT_CTRL_WAIT_MASK)
#define CAPT_CTRL_FDIV_MASK                      (0xF00U)
#define CAPT_CTRL_FDIV_SHIFT                     (8U)
#define CAPT_CTRL_FDIV(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_FDIV_SHIFT)) & CAPT_CTRL_FDIV_MASK)
#define CAPT_CTRL_XPINUSE_MASK                   (0x3000U)
#define CAPT_CTRL_XPINUSE_SHIFT                  (12U)
#define CAPT_CTRL_XPINUSE(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_XPINUSE_SHIFT)) & CAPT_CTRL_XPINUSE_MASK)
#define CAPT_CTRL_INCHANGE_MASK                  (0x8000U)
#define CAPT_CTRL_INCHANGE_SHIFT                 (15U)
#define CAPT_CTRL_INCHANGE(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_INCHANGE_SHIFT)) & CAPT_CTRL_INCHANGE_MASK)
#define CAPT_CTRL_XPINSEL_MASK                   (0xFFFF0000U)
#define CAPT_CTRL_XPINSEL_SHIFT                  (16U)
#define CAPT_CTRL_XPINSEL(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_XPINSEL_SHIFT)) & CAPT_CTRL_XPINSEL_MASK)
/*! @} */

/*! @name STATUS - Status from triggers and time-outs including if in a poll now. Some are used for interrupts. */
/*! @{ */
#define CAPT_STATUS_YESTOUCH_MASK                (0x1U)
#define CAPT_STATUS_YESTOUCH_SHIFT               (0U)
#define CAPT_STATUS_YESTOUCH(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_YESTOUCH_SHIFT)) & CAPT_STATUS_YESTOUCH_MASK)
#define CAPT_STATUS_NOTOUCH_MASK                 (0x2U)
#define CAPT_STATUS_NOTOUCH_SHIFT                (1U)
#define CAPT_STATUS_NOTOUCH(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_NOTOUCH_SHIFT)) & CAPT_STATUS_NOTOUCH_MASK)
#define CAPT_STATUS_POLLDONE_MASK                (0x4U)
#define CAPT_STATUS_POLLDONE_SHIFT               (2U)
#define CAPT_STATUS_POLLDONE(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_POLLDONE_SHIFT)) & CAPT_STATUS_POLLDONE_MASK)
#define CAPT_STATUS_TIMEOUT_MASK                 (0x8U)
#define CAPT_STATUS_TIMEOUT_SHIFT                (3U)
#define CAPT_STATUS_TIMEOUT(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_TIMEOUT_SHIFT)) & CAPT_STATUS_TIMEOUT_MASK)
#define CAPT_STATUS_OVERUN_MASK                  (0x10U)
#define CAPT_STATUS_OVERUN_SHIFT                 (4U)
#define CAPT_STATUS_OVERUN(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_OVERUN_SHIFT)) & CAPT_STATUS_OVERUN_MASK)
#define CAPT_STATUS_BUSY_MASK                    (0x100U)
#define CAPT_STATUS_BUSY_SHIFT                   (8U)
#define CAPT_STATUS_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_BUSY_SHIFT)) & CAPT_STATUS_BUSY_MASK)
#define CAPT_STATUS_XMAX_MASK                    (0xF0000U)
#define CAPT_STATUS_XMAX_SHIFT                   (16U)
#define CAPT_STATUS_XMAX(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_XMAX_SHIFT)) & CAPT_STATUS_XMAX_MASK)
/*! @} */

/*! @name POLL_TCNT - This sets up the polling counter and measurement counter rules. */
/*! @{ */
#define CAPT_POLL_TCNT_TCNT_MASK                 (0xFFFU)
#define CAPT_POLL_TCNT_TCNT_SHIFT                (0U)
#define CAPT_POLL_TCNT_TCNT(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_TCNT_SHIFT)) & CAPT_POLL_TCNT_TCNT_MASK)
#define CAPT_POLL_TCNT_TOUT_MASK                 (0xF000U)
#define CAPT_POLL_TCNT_TOUT_SHIFT                (12U)
#define CAPT_POLL_TCNT_TOUT(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_TOUT_SHIFT)) & CAPT_POLL_TCNT_TOUT_MASK)
#define CAPT_POLL_TCNT_POLL_MASK                 (0xFF0000U)
#define CAPT_POLL_TCNT_POLL_SHIFT                (16U)
#define CAPT_POLL_TCNT_POLL(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_POLL_SHIFT)) & CAPT_POLL_TCNT_POLL_MASK)
#define CAPT_POLL_TCNT_MDELAY_MASK               (0x3000000U)
#define CAPT_POLL_TCNT_MDELAY_SHIFT              (24U)
#define CAPT_POLL_TCNT_MDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_MDELAY_SHIFT)) & CAPT_POLL_TCNT_MDELAY_MASK)
#define CAPT_POLL_TCNT_RDELAY_MASK               (0xC000000U)
#define CAPT_POLL_TCNT_RDELAY_SHIFT              (26U)
#define CAPT_POLL_TCNT_RDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_RDELAY_SHIFT)) & CAPT_POLL_TCNT_RDELAY_MASK)
#define CAPT_POLL_TCNT_TCHLOW_ER_MASK            (0x80000000U)
#define CAPT_POLL_TCNT_TCHLOW_ER_SHIFT           (31U)
#define CAPT_POLL_TCNT_TCHLOW_ER(x)              (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_TCHLOW_ER_SHIFT)) & CAPT_POLL_TCNT_TCHLOW_ER_MASK)
/*! @} */

/*! @name INTENSET - Interrupt enable */
/*! @{ */
#define CAPT_INTENSET_YESTOUCH_MASK              (0x1U)
#define CAPT_INTENSET_YESTOUCH_SHIFT             (0U)
#define CAPT_INTENSET_YESTOUCH(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_YESTOUCH_SHIFT)) & CAPT_INTENSET_YESTOUCH_MASK)
#define CAPT_INTENSET_NOTOUCH_MASK               (0x2U)
#define CAPT_INTENSET_NOTOUCH_SHIFT              (1U)
#define CAPT_INTENSET_NOTOUCH(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_NOTOUCH_SHIFT)) & CAPT_INTENSET_NOTOUCH_MASK)
#define CAPT_INTENSET_POLLDONE_MASK              (0x4U)
#define CAPT_INTENSET_POLLDONE_SHIFT             (2U)
#define CAPT_INTENSET_POLLDONE(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_POLLDONE_SHIFT)) & CAPT_INTENSET_POLLDONE_MASK)
#define CAPT_INTENSET_TIMEOUT_MASK               (0x8U)
#define CAPT_INTENSET_TIMEOUT_SHIFT              (3U)
#define CAPT_INTENSET_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_TIMEOUT_SHIFT)) & CAPT_INTENSET_TIMEOUT_MASK)
#define CAPT_INTENSET_OVERUN_MASK                (0x10U)
#define CAPT_INTENSET_OVERUN_SHIFT               (4U)
#define CAPT_INTENSET_OVERUN(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_OVERUN_SHIFT)) & CAPT_INTENSET_OVERUN_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt enable clear */
/*! @{ */
#define CAPT_INTENCLR_YESTOUCH_MASK              (0x1U)
#define CAPT_INTENCLR_YESTOUCH_SHIFT             (0U)
#define CAPT_INTENCLR_YESTOUCH(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_YESTOUCH_SHIFT)) & CAPT_INTENCLR_YESTOUCH_MASK)
#define CAPT_INTENCLR_NOTOUCH_MASK               (0x2U)
#define CAPT_INTENCLR_NOTOUCH_SHIFT              (1U)
#define CAPT_INTENCLR_NOTOUCH(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_NOTOUCH_SHIFT)) & CAPT_INTENCLR_NOTOUCH_MASK)
#define CAPT_INTENCLR_POLLDONE_MASK              (0x4U)
#define CAPT_INTENCLR_POLLDONE_SHIFT             (2U)
#define CAPT_INTENCLR_POLLDONE(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_POLLDONE_SHIFT)) & CAPT_INTENCLR_POLLDONE_MASK)
#define CAPT_INTENCLR_TIMEOUT_MASK               (0x8U)
#define CAPT_INTENCLR_TIMEOUT_SHIFT              (3U)
#define CAPT_INTENCLR_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_TIMEOUT_SHIFT)) & CAPT_INTENCLR_TIMEOUT_MASK)
#define CAPT_INTENCLR_OVERUN_MASK                (0x10U)
#define CAPT_INTENCLR_OVERUN_SHIFT               (4U)
#define CAPT_INTENCLR_OVERUN(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_OVERUN_SHIFT)) & CAPT_INTENCLR_OVERUN_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status (mask of STATUS and INTEN) */
/*! @{ */
#define CAPT_INTSTAT_YESTOUCH_MASK               (0x1U)
#define CAPT_INTSTAT_YESTOUCH_SHIFT              (0U)
#define CAPT_INTSTAT_YESTOUCH(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_YESTOUCH_SHIFT)) & CAPT_INTSTAT_YESTOUCH_MASK)
#define CAPT_INTSTAT_NOTOUCH_MASK                (0x2U)
#define CAPT_INTSTAT_NOTOUCH_SHIFT               (1U)
#define CAPT_INTSTAT_NOTOUCH(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_NOTOUCH_SHIFT)) & CAPT_INTSTAT_NOTOUCH_MASK)
#define CAPT_INTSTAT_POLLDONE_MASK               (0x4U)
#define CAPT_INTSTAT_POLLDONE_SHIFT              (2U)
#define CAPT_INTSTAT_POLLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_POLLDONE_SHIFT)) & CAPT_INTSTAT_POLLDONE_MASK)
#define CAPT_INTSTAT_TIMEOUT_MASK                (0x8U)
#define CAPT_INTSTAT_TIMEOUT_SHIFT               (3U)
#define CAPT_INTSTAT_TIMEOUT(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_TIMEOUT_SHIFT)) & CAPT_INTSTAT_TIMEOUT_MASK)
#define CAPT_INTSTAT_OVERUN_MASK                 (0x10U)
#define CAPT_INTSTAT_OVERUN_SHIFT                (4U)
#define CAPT_INTSTAT_OVERUN(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_OVERUN_SHIFT)) & CAPT_INTSTAT_OVERUN_MASK)
/*! @} */

/*! @name TOUCH - Last touch event (touch or no-touch) in context. */
/*! @{ */
#define CAPT_TOUCH_COUNT_MASK                    (0xFFFU)
#define CAPT_TOUCH_COUNT_SHIFT                   (0U)
#define CAPT_TOUCH_COUNT(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_COUNT_SHIFT)) & CAPT_TOUCH_COUNT_MASK)
#define CAPT_TOUCH_XVAL_MASK                     (0xF000U)
#define CAPT_TOUCH_XVAL_SHIFT                    (12U)
#define CAPT_TOUCH_XVAL(x)                       (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_XVAL_SHIFT)) & CAPT_TOUCH_XVAL_MASK)
#define CAPT_TOUCH_ISTOUCH_MASK                  (0x10000U)
#define CAPT_TOUCH_ISTOUCH_SHIFT                 (16U)
#define CAPT_TOUCH_ISTOUCH(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_ISTOUCH_SHIFT)) & CAPT_TOUCH_ISTOUCH_MASK)
#define CAPT_TOUCH_ISTO_MASK                     (0x20000U)
#define CAPT_TOUCH_ISTO_SHIFT                    (17U)
#define CAPT_TOUCH_ISTO(x)                       (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_ISTO_SHIFT)) & CAPT_TOUCH_ISTO_MASK)
#define CAPT_TOUCH_SEQ_MASK                      (0xF00000U)
#define CAPT_TOUCH_SEQ_SHIFT                     (20U)
#define CAPT_TOUCH_SEQ(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_SEQ_SHIFT)) & CAPT_TOUCH_SEQ_MASK)
#define CAPT_TOUCH_CHANGE_MASK                   (0x80000000U)
#define CAPT_TOUCH_CHANGE_SHIFT                  (31U)
#define CAPT_TOUCH_CHANGE(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_CHANGE_SHIFT)) & CAPT_TOUCH_CHANGE_MASK)
/*! @} */

/*! @name ID - Block ID. */
/*! @{ */
#define CAPT_ID_APERTURE_MASK                    (0xFFU)
#define CAPT_ID_APERTURE_SHIFT                   (0U)
#define CAPT_ID_APERTURE(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_ID_APERTURE_SHIFT)) & CAPT_ID_APERTURE_MASK)
#define CAPT_ID_MINOR_REV_MASK                   (0xF00U)
#define CAPT_ID_MINOR_REV_SHIFT                  (8U)
#define CAPT_ID_MINOR_REV(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_ID_MINOR_REV_SHIFT)) & CAPT_ID_MINOR_REV_MASK)
#define CAPT_ID_MAJOR_REV_MASK                   (0xF000U)
#define CAPT_ID_MAJOR_REV_SHIFT                  (12U)
#define CAPT_ID_MAJOR_REV(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_ID_MAJOR_REV_SHIFT)) & CAPT_ID_MAJOR_REV_MASK)
#define CAPT_ID_ID_MASK                          (0xFFFF0000U)
#define CAPT_ID_ID_SHIFT                         (16U)
#define CAPT_ID_ID(x)                            (((uint32_t)(((uint32_t)(x)) << CAPT_ID_ID_SHIFT)) & CAPT_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAPT_Register_Masks */


/* CAPT - Peripheral instance base addresses */
/** Peripheral CAPT base address */
#define CAPT_BASE                                (0x40060000u)
/** Peripheral CAPT base pointer */
#define CAPT                                     ((CAPT_Type *)CAPT_BASE)
/** Array initializer of CAPT peripheral base addresses */
#define CAPT_BASE_ADDRS                          { CAPT_BASE }
/** Array initializer of CAPT peripheral base pointers */
#define CAPT_BASE_PTRS                           { CAPT }

/*!
 * @}
 */ /* end of group CAPT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MODE;                              /**< CRC mode register, offset: 0x0 */
  __IO uint32_t SEED;                              /**< CRC seed register, offset: 0x4 */
  union {                                          /* offset: 0x8 */
    __I  uint32_t SUM;                               /**< CRC checksum register, offset: 0x8 */
    __O  uint32_t WR_DATA;                           /**< CRC data register, offset: 0x8 */
  };
} CRC_Type;

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name MODE - CRC mode register */
/*! @{ */
#define CRC_MODE_CRC_POLY_MASK                   (0x3U)
#define CRC_MODE_CRC_POLY_SHIFT                  (0U)
#define CRC_MODE_CRC_POLY(x)                     (((uint32_t)(((uint32_t)(x)) << CRC_MODE_CRC_POLY_SHIFT)) & CRC_MODE_CRC_POLY_MASK)
#define CRC_MODE_BIT_RVS_WR_MASK                 (0x4U)
#define CRC_MODE_BIT_RVS_WR_SHIFT                (2U)
#define CRC_MODE_BIT_RVS_WR(x)                   (((uint32_t)(((uint32_t)(x)) << CRC_MODE_BIT_RVS_WR_SHIFT)) & CRC_MODE_BIT_RVS_WR_MASK)
#define CRC_MODE_CMPL_WR_MASK                    (0x8U)
#define CRC_MODE_CMPL_WR_SHIFT                   (3U)
#define CRC_MODE_CMPL_WR(x)                      (((uint32_t)(((uint32_t)(x)) << CRC_MODE_CMPL_WR_SHIFT)) & CRC_MODE_CMPL_WR_MASK)
#define CRC_MODE_BIT_RVS_SUM_MASK                (0x10U)
#define CRC_MODE_BIT_RVS_SUM_SHIFT               (4U)
#define CRC_MODE_BIT_RVS_SUM(x)                  (((uint32_t)(((uint32_t)(x)) << CRC_MODE_BIT_RVS_SUM_SHIFT)) & CRC_MODE_BIT_RVS_SUM_MASK)
#define CRC_MODE_CMPL_SUM_MASK                   (0x20U)
#define CRC_MODE_CMPL_SUM_SHIFT                  (5U)
#define CRC_MODE_CMPL_SUM(x)                     (((uint32_t)(((uint32_t)(x)) << CRC_MODE_CMPL_SUM_SHIFT)) & CRC_MODE_CMPL_SUM_MASK)
/*! @} */

/*! @name SEED - CRC seed register */
/*! @{ */
#define CRC_SEED_CRC_SEED_MASK                   (0xFFFFFFFFU)
#define CRC_SEED_CRC_SEED_SHIFT                  (0U)
#define CRC_SEED_CRC_SEED(x)                     (((uint32_t)(((uint32_t)(x)) << CRC_SEED_CRC_SEED_SHIFT)) & CRC_SEED_CRC_SEED_MASK)
/*! @} */

/*! @name SUM - CRC checksum register */
/*! @{ */
#define CRC_SUM_CRC_SUM_MASK                     (0xFFFFFFFFU)
#define CRC_SUM_CRC_SUM_SHIFT                    (0U)
#define CRC_SUM_CRC_SUM(x)                       (((uint32_t)(((uint32_t)(x)) << CRC_SUM_CRC_SUM_SHIFT)) & CRC_SUM_CRC_SUM_MASK)
/*! @} */

/*! @name WR_DATA - CRC data register */
/*! @{ */
#define CRC_WR_DATA_CRC_WR_DATA_MASK             (0xFFFFFFFFU)
#define CRC_WR_DATA_CRC_WR_DATA_SHIFT            (0U)
#define CRC_WR_DATA_CRC_WR_DATA(x)               (((uint32_t)(((uint32_t)(x)) << CRC_WR_DATA_CRC_WR_DATA_SHIFT)) & CRC_WR_DATA_CRC_WR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x50000000u)
/** Peripheral CRC base pointer */
#define CRC                                      ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC }

/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CTIMER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTIMER_Peripheral_Access_Layer CTIMER Peripheral Access Layer
 * @{
 */

/** CTIMER - Register Layout Typedef */
typedef struct {
  __IO uint32_t IR;                                /**< Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending., offset: 0x0 */
  __IO uint32_t TCR;                               /**< Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR., offset: 0x4 */
  __IO uint32_t TC;                                /**< Timer Counter. The 32 bit TC is incremented every PR+1 cycles of the APB bus clock. The TC is controlled through the TCR., offset: 0x8 */
  __IO uint32_t PR;                                /**< Prescale Register. When the Prescale Counter (PC) is equal to this value, the next clock increments the TC and clears the PC., offset: 0xC */
  __IO uint32_t PC;                                /**< Prescale Counter. The 32 bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface., offset: 0x10 */
  __IO uint32_t MCR;                               /**< Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs., offset: 0x14 */
  __IO uint32_t MR[4];                             /**< Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC., array offset: 0x18, array step: 0x4 */
  __IO uint32_t CCR;                               /**< Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place., offset: 0x28 */
  __I  uint32_t CR[3];                             /**< Capture Register . CR is loaded with the value of TC when there is an event on the CAPn. input., array offset: 0x2C, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t EMR;                               /**< External Match Register. The EMR controls the match function and the external match pins., offset: 0x3C */
       uint8_t RESERVED_1[48];
  __IO uint32_t CTCR;                              /**< Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting., offset: 0x70 */
  __IO uint32_t PWMC;                              /**< PWM Control Register. The PWMCON enables PWM mode for the external match pins., offset: 0x74 */
  __IO uint32_t MSR[4];                            /**< Match Shadow Register . If enabled, the Match Register will be automatically reloaded with the contents of this register whenever the TC is reset to zero., array offset: 0x78, array step: 0x4 */
} CTIMER_Type;

/* ----------------------------------------------------------------------------
   -- CTIMER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTIMER_Register_Masks CTIMER Register Masks
 * @{
 */

/*! @name IR - Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending. */
/*! @{ */
#define CTIMER_IR_MR0INT_MASK                    (0x1U)
#define CTIMER_IR_MR0INT_SHIFT                   (0U)
#define CTIMER_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR0INT_SHIFT)) & CTIMER_IR_MR0INT_MASK)
#define CTIMER_IR_MR1INT_MASK                    (0x2U)
#define CTIMER_IR_MR1INT_SHIFT                   (1U)
#define CTIMER_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR1INT_SHIFT)) & CTIMER_IR_MR1INT_MASK)
#define CTIMER_IR_MR2INT_MASK                    (0x4U)
#define CTIMER_IR_MR2INT_SHIFT                   (2U)
#define CTIMER_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR2INT_SHIFT)) & CTIMER_IR_MR2INT_MASK)
#define CTIMER_IR_MR3INT_MASK                    (0x8U)
#define CTIMER_IR_MR3INT_SHIFT                   (3U)
#define CTIMER_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_MR3INT_SHIFT)) & CTIMER_IR_MR3INT_MASK)
#define CTIMER_IR_CR0INT_MASK                    (0x10U)
#define CTIMER_IR_CR0INT_SHIFT                   (4U)
#define CTIMER_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_CR0INT_SHIFT)) & CTIMER_IR_CR0INT_MASK)
#define CTIMER_IR_CR1INT_MASK                    (0x20U)
#define CTIMER_IR_CR1INT_SHIFT                   (5U)
#define CTIMER_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_CR1INT_SHIFT)) & CTIMER_IR_CR1INT_MASK)
#define CTIMER_IR_CR2INT_MASK                    (0x40U)
#define CTIMER_IR_CR2INT_SHIFT                   (6U)
#define CTIMER_IR_CR2INT(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_IR_CR2INT_SHIFT)) & CTIMER_IR_CR2INT_MASK)
/*! @} */

/*! @name TCR - Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR. */
/*! @{ */
#define CTIMER_TCR_CEN_MASK                      (0x1U)
#define CTIMER_TCR_CEN_SHIFT                     (0U)
#define CTIMER_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_TCR_CEN_SHIFT)) & CTIMER_TCR_CEN_MASK)
#define CTIMER_TCR_CRST_MASK                     (0x2U)
#define CTIMER_TCR_CRST_SHIFT                    (1U)
#define CTIMER_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_TCR_CRST_SHIFT)) & CTIMER_TCR_CRST_MASK)
/*! @} */

/*! @name TC - Timer Counter. The 32 bit TC is incremented every PR+1 cycles of the APB bus clock. The TC is controlled through the TCR. */
/*! @{ */
#define CTIMER_TC_TCVAL_MASK                     (0xFFFFFFFFU)
#define CTIMER_TC_TCVAL_SHIFT                    (0U)
#define CTIMER_TC_TCVAL(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_TC_TCVAL_SHIFT)) & CTIMER_TC_TCVAL_MASK)
/*! @} */

/*! @name PR - Prescale Register. When the Prescale Counter (PC) is equal to this value, the next clock increments the TC and clears the PC. */
/*! @{ */
#define CTIMER_PR_PRVAL_MASK                     (0xFFFFFFFFU)
#define CTIMER_PR_PRVAL_SHIFT                    (0U)
#define CTIMER_PR_PRVAL(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_PR_PRVAL_SHIFT)) & CTIMER_PR_PRVAL_MASK)
/*! @} */

/*! @name PC - Prescale Counter. The 32 bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface. */
/*! @{ */
#define CTIMER_PC_PCVAL_MASK                     (0xFFFFFFFFU)
#define CTIMER_PC_PCVAL_SHIFT                    (0U)
#define CTIMER_PC_PCVAL(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_PC_PCVAL_SHIFT)) & CTIMER_PC_PCVAL_MASK)
/*! @} */

/*! @name MCR - Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs. */
/*! @{ */
#define CTIMER_MCR_MR0I_MASK                     (0x1U)
#define CTIMER_MCR_MR0I_SHIFT                    (0U)
#define CTIMER_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0I_SHIFT)) & CTIMER_MCR_MR0I_MASK)
#define CTIMER_MCR_MR0R_MASK                     (0x2U)
#define CTIMER_MCR_MR0R_SHIFT                    (1U)
#define CTIMER_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0R_SHIFT)) & CTIMER_MCR_MR0R_MASK)
#define CTIMER_MCR_MR0S_MASK                     (0x4U)
#define CTIMER_MCR_MR0S_SHIFT                    (2U)
#define CTIMER_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0S_SHIFT)) & CTIMER_MCR_MR0S_MASK)
#define CTIMER_MCR_MR1I_MASK                     (0x8U)
#define CTIMER_MCR_MR1I_SHIFT                    (3U)
#define CTIMER_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1I_SHIFT)) & CTIMER_MCR_MR1I_MASK)
#define CTIMER_MCR_MR1R_MASK                     (0x10U)
#define CTIMER_MCR_MR1R_SHIFT                    (4U)
#define CTIMER_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1R_SHIFT)) & CTIMER_MCR_MR1R_MASK)
#define CTIMER_MCR_MR1S_MASK                     (0x20U)
#define CTIMER_MCR_MR1S_SHIFT                    (5U)
#define CTIMER_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1S_SHIFT)) & CTIMER_MCR_MR1S_MASK)
#define CTIMER_MCR_MR2I_MASK                     (0x40U)
#define CTIMER_MCR_MR2I_SHIFT                    (6U)
#define CTIMER_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2I_SHIFT)) & CTIMER_MCR_MR2I_MASK)
#define CTIMER_MCR_MR2R_MASK                     (0x80U)
#define CTIMER_MCR_MR2R_SHIFT                    (7U)
#define CTIMER_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2R_SHIFT)) & CTIMER_MCR_MR2R_MASK)
#define CTIMER_MCR_MR2S_MASK                     (0x100U)
#define CTIMER_MCR_MR2S_SHIFT                    (8U)
#define CTIMER_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2S_SHIFT)) & CTIMER_MCR_MR2S_MASK)
#define CTIMER_MCR_MR3I_MASK                     (0x200U)
#define CTIMER_MCR_MR3I_SHIFT                    (9U)
#define CTIMER_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3I_SHIFT)) & CTIMER_MCR_MR3I_MASK)
#define CTIMER_MCR_MR3R_MASK                     (0x400U)
#define CTIMER_MCR_MR3R_SHIFT                    (10U)
#define CTIMER_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3R_SHIFT)) & CTIMER_MCR_MR3R_MASK)
#define CTIMER_MCR_MR3S_MASK                     (0x800U)
#define CTIMER_MCR_MR3S_SHIFT                    (11U)
#define CTIMER_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3S_SHIFT)) & CTIMER_MCR_MR3S_MASK)
#define CTIMER_MCR_MR0RL_MASK                    (0x1000000U)
#define CTIMER_MCR_MR0RL_SHIFT                   (24U)
#define CTIMER_MCR_MR0RL(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR0RL_SHIFT)) & CTIMER_MCR_MR0RL_MASK)
#define CTIMER_MCR_MR1RL_MASK                    (0x2000000U)
#define CTIMER_MCR_MR1RL_SHIFT                   (25U)
#define CTIMER_MCR_MR1RL(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR1RL_SHIFT)) & CTIMER_MCR_MR1RL_MASK)
#define CTIMER_MCR_MR2RL_MASK                    (0x4000000U)
#define CTIMER_MCR_MR2RL_SHIFT                   (26U)
#define CTIMER_MCR_MR2RL(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR2RL_SHIFT)) & CTIMER_MCR_MR2RL_MASK)
#define CTIMER_MCR_MR3RL_MASK                    (0x8000000U)
#define CTIMER_MCR_MR3RL_SHIFT                   (27U)
#define CTIMER_MCR_MR3RL(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_MCR_MR3RL_SHIFT)) & CTIMER_MCR_MR3RL_MASK)
/*! @} */

/*! @name MR - Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC. */
/*! @{ */
#define CTIMER_MR_MATCH_MASK                     (0xFFFFFFFFU)
#define CTIMER_MR_MATCH_SHIFT                    (0U)
#define CTIMER_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_MR_MATCH_SHIFT)) & CTIMER_MR_MATCH_MASK)
/*! @} */

/* The count of CTIMER_MR */
#define CTIMER_MR_COUNT                          (4U)

/*! @name CCR - Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place. */
/*! @{ */
#define CTIMER_CCR_CAP0RE_MASK                   (0x1U)
#define CTIMER_CCR_CAP0RE_SHIFT                  (0U)
#define CTIMER_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP0RE_SHIFT)) & CTIMER_CCR_CAP0RE_MASK)
#define CTIMER_CCR_CAP0FE_MASK                   (0x2U)
#define CTIMER_CCR_CAP0FE_SHIFT                  (1U)
#define CTIMER_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP0FE_SHIFT)) & CTIMER_CCR_CAP0FE_MASK)
#define CTIMER_CCR_CAP0I_MASK                    (0x4U)
#define CTIMER_CCR_CAP0I_SHIFT                   (2U)
#define CTIMER_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP0I_SHIFT)) & CTIMER_CCR_CAP0I_MASK)
#define CTIMER_CCR_CAP1RE_MASK                   (0x8U)
#define CTIMER_CCR_CAP1RE_SHIFT                  (3U)
#define CTIMER_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP1RE_SHIFT)) & CTIMER_CCR_CAP1RE_MASK)
#define CTIMER_CCR_CAP1FE_MASK                   (0x10U)
#define CTIMER_CCR_CAP1FE_SHIFT                  (4U)
#define CTIMER_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP1FE_SHIFT)) & CTIMER_CCR_CAP1FE_MASK)
#define CTIMER_CCR_CAP1I_MASK                    (0x20U)
#define CTIMER_CCR_CAP1I_SHIFT                   (5U)
#define CTIMER_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP1I_SHIFT)) & CTIMER_CCR_CAP1I_MASK)
#define CTIMER_CCR_CAP2RE_MASK                   (0x40U)
#define CTIMER_CCR_CAP2RE_SHIFT                  (6U)
#define CTIMER_CCR_CAP2RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP2RE_SHIFT)) & CTIMER_CCR_CAP2RE_MASK)
#define CTIMER_CCR_CAP2FE_MASK                   (0x80U)
#define CTIMER_CCR_CAP2FE_SHIFT                  (7U)
#define CTIMER_CCR_CAP2FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP2FE_SHIFT)) & CTIMER_CCR_CAP2FE_MASK)
#define CTIMER_CCR_CAP2I_MASK                    (0x100U)
#define CTIMER_CCR_CAP2I_SHIFT                   (8U)
#define CTIMER_CCR_CAP2I(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_CCR_CAP2I_SHIFT)) & CTIMER_CCR_CAP2I_MASK)
/*! @} */

/*! @name CR - Capture Register . CR is loaded with the value of TC when there is an event on the CAPn. input. */
/*! @{ */
#define CTIMER_CR_CAP_MASK                       (0xFFFFFFFFU)
#define CTIMER_CR_CAP_SHIFT                      (0U)
#define CTIMER_CR_CAP(x)                         (((uint32_t)(((uint32_t)(x)) << CTIMER_CR_CAP_SHIFT)) & CTIMER_CR_CAP_MASK)
/*! @} */

/* The count of CTIMER_CR */
#define CTIMER_CR_COUNT                          (3U)

/*! @name EMR - External Match Register. The EMR controls the match function and the external match pins. */
/*! @{ */
#define CTIMER_EMR_EM0_MASK                      (0x1U)
#define CTIMER_EMR_EM0_SHIFT                     (0U)
#define CTIMER_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EM0_SHIFT)) & CTIMER_EMR_EM0_MASK)
#define CTIMER_EMR_EM1_MASK                      (0x2U)
#define CTIMER_EMR_EM1_SHIFT                     (1U)
#define CTIMER_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EM1_SHIFT)) & CTIMER_EMR_EM1_MASK)
#define CTIMER_EMR_EM2_MASK                      (0x4U)
#define CTIMER_EMR_EM2_SHIFT                     (2U)
#define CTIMER_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EM2_SHIFT)) & CTIMER_EMR_EM2_MASK)
#define CTIMER_EMR_EM3_MASK                      (0x8U)
#define CTIMER_EMR_EM3_SHIFT                     (3U)
#define CTIMER_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EM3_SHIFT)) & CTIMER_EMR_EM3_MASK)
#define CTIMER_EMR_EMC0_MASK                     (0x30U)
#define CTIMER_EMR_EMC0_SHIFT                    (4U)
#define CTIMER_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EMC0_SHIFT)) & CTIMER_EMR_EMC0_MASK)
#define CTIMER_EMR_EMC1_MASK                     (0xC0U)
#define CTIMER_EMR_EMC1_SHIFT                    (6U)
#define CTIMER_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EMC1_SHIFT)) & CTIMER_EMR_EMC1_MASK)
#define CTIMER_EMR_EMC2_MASK                     (0x300U)
#define CTIMER_EMR_EMC2_SHIFT                    (8U)
#define CTIMER_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EMC2_SHIFT)) & CTIMER_EMR_EMC2_MASK)
#define CTIMER_EMR_EMC3_MASK                     (0xC00U)
#define CTIMER_EMR_EMC3_SHIFT                    (10U)
#define CTIMER_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x)) << CTIMER_EMR_EMC3_SHIFT)) & CTIMER_EMR_EMC3_MASK)
/*! @} */

/*! @name CTCR - Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting. */
/*! @{ */
#define CTIMER_CTCR_CTMODE_MASK                  (0x3U)
#define CTIMER_CTCR_CTMODE_SHIFT                 (0U)
#define CTIMER_CTCR_CTMODE(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_CTCR_CTMODE_SHIFT)) & CTIMER_CTCR_CTMODE_MASK)
#define CTIMER_CTCR_CINSEL_MASK                  (0xCU)
#define CTIMER_CTCR_CINSEL_SHIFT                 (2U)
#define CTIMER_CTCR_CINSEL(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_CTCR_CINSEL_SHIFT)) & CTIMER_CTCR_CINSEL_MASK)
#define CTIMER_CTCR_ENCC_MASK                    (0x10U)
#define CTIMER_CTCR_ENCC_SHIFT                   (4U)
#define CTIMER_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x)) << CTIMER_CTCR_ENCC_SHIFT)) & CTIMER_CTCR_ENCC_MASK)
#define CTIMER_CTCR_SELCC_MASK                   (0xE0U)
#define CTIMER_CTCR_SELCC_SHIFT                  (5U)
#define CTIMER_CTCR_SELCC(x)                     (((uint32_t)(((uint32_t)(x)) << CTIMER_CTCR_SELCC_SHIFT)) & CTIMER_CTCR_SELCC_MASK)
/*! @} */

/*! @name PWMC - PWM Control Register. The PWMCON enables PWM mode for the external match pins. */
/*! @{ */
#define CTIMER_PWMC_PWMEN0_MASK                  (0x1U)
#define CTIMER_PWMC_PWMEN0_SHIFT                 (0U)
#define CTIMER_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_PWMC_PWMEN0_SHIFT)) & CTIMER_PWMC_PWMEN0_MASK)
#define CTIMER_PWMC_PWMEN1_MASK                  (0x2U)
#define CTIMER_PWMC_PWMEN1_SHIFT                 (1U)
#define CTIMER_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_PWMC_PWMEN1_SHIFT)) & CTIMER_PWMC_PWMEN1_MASK)
#define CTIMER_PWMC_PWMEN2_MASK                  (0x4U)
#define CTIMER_PWMC_PWMEN2_SHIFT                 (2U)
#define CTIMER_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_PWMC_PWMEN2_SHIFT)) & CTIMER_PWMC_PWMEN2_MASK)
#define CTIMER_PWMC_PWMEN3_MASK                  (0x8U)
#define CTIMER_PWMC_PWMEN3_SHIFT                 (3U)
#define CTIMER_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x)) << CTIMER_PWMC_PWMEN3_SHIFT)) & CTIMER_PWMC_PWMEN3_MASK)
/*! @} */

/*! @name MSR - Match Shadow Register . If enabled, the Match Register will be automatically reloaded with the contents of this register whenever the TC is reset to zero. */
/*! @{ */
#define CTIMER_MSR_MATCH_Shadow_MASK             (0xFFFFFFFFU)
#define CTIMER_MSR_MATCH_Shadow_SHIFT            (0U)
#define CTIMER_MSR_MATCH_Shadow(x)               (((uint32_t)(((uint32_t)(x)) << CTIMER_MSR_MATCH_Shadow_SHIFT)) & CTIMER_MSR_MATCH_Shadow_MASK)
/*! @} */

/* The count of CTIMER_MSR */
#define CTIMER_MSR_COUNT                         (4U)


/*!
 * @}
 */ /* end of group CTIMER_Register_Masks */


/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x40038000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn }

/*!
 * @}
 */ /* end of group CTIMER_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< D/A Converter Register. This register contains the digital value to be converted to analog and a power control bit., offset: 0x0 */
  __IO uint32_t CTRL;                              /**< DAC Control register. This register controls DMA and timer operation., offset: 0x4 */
  __IO uint32_t CNTVAL;                            /**< DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer., offset: 0x8 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name CR - D/A Converter Register. This register contains the digital value to be converted to analog and a power control bit. */
/*! @{ */
#define DAC_CR_VALUE_MASK                        (0xFFC0U)
#define DAC_CR_VALUE_SHIFT                       (6U)
#define DAC_CR_VALUE(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_VALUE_SHIFT)) & DAC_CR_VALUE_MASK)
#define DAC_CR_BIAS_MASK                         (0x10000U)
#define DAC_CR_BIAS_SHIFT                        (16U)
#define DAC_CR_BIAS(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_BIAS_SHIFT)) & DAC_CR_BIAS_MASK)
/*! @} */

/*! @name CTRL - DAC Control register. This register controls DMA and timer operation. */
/*! @{ */
#define DAC_CTRL_INT_CPU_REQ_MASK                (0x1U)
#define DAC_CTRL_INT_CPU_REQ_SHIFT               (0U)
#define DAC_CTRL_INT_CPU_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_INT_CPU_REQ_SHIFT)) & DAC_CTRL_INT_CPU_REQ_MASK)
#define DAC_CTRL_DBLBUF_ENA_MASK                 (0x2U)
#define DAC_CTRL_DBLBUF_ENA_SHIFT                (1U)
#define DAC_CTRL_DBLBUF_ENA(x)                   (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_DBLBUF_ENA_SHIFT)) & DAC_CTRL_DBLBUF_ENA_MASK)
#define DAC_CTRL_CNT_ENA_MASK                    (0x4U)
#define DAC_CTRL_CNT_ENA_SHIFT                   (2U)
#define DAC_CTRL_CNT_ENA(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_CNT_ENA_SHIFT)) & DAC_CTRL_CNT_ENA_MASK)
/*! @} */

/*! @name CNTVAL - DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer. */
/*! @{ */
#define DAC_CNTVAL_VALUE_MASK                    (0xFFFFU)
#define DAC_CNTVAL_VALUE_SHIFT                   (0U)
#define DAC_CNTVAL_VALUE(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CNTVAL_VALUE_SHIFT)) & DAC_CNTVAL_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x40014000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0 }

/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint8_t B[1][31];                           /**< Byte pin registers for all port 0 and 1 GPIO pins, array offset: 0x0, array step: index*0x1F, index2*0x1 */
       uint8_t RESERVED_0[4065];
  __IO uint32_t W[1][31];                          /**< Word pin registers for all port 0 and 1 GPIO pins, array offset: 0x1000, array step: index*0x7C, index2*0x4 */
       uint8_t RESERVED_1[3972];
  __IO uint32_t DIR[1];                            /**< Direction registers, array offset: 0x2000, array step: 0x4 */
       uint8_t RESERVED_2[124];
  __IO uint32_t MASK[1];                           /**< Mask register, array offset: 0x2080, array step: 0x4 */
       uint8_t RESERVED_3[124];
  __IO uint32_t PIN[1];                            /**< Port pin register, array offset: 0x2100, array step: 0x4 */
       uint8_t RESERVED_4[124];
  __IO uint32_t MPIN[1];                           /**< Masked port register, array offset: 0x2180, array step: 0x4 */
       uint8_t RESERVED_5[124];
  __IO uint32_t SET[1];                            /**< Write: Set register for port Read: output bits for port, array offset: 0x2200, array step: 0x4 */
       uint8_t RESERVED_6[124];
  __O  uint32_t CLR[1];                            /**< Clear port, array offset: 0x2280, array step: 0x4 */
       uint8_t RESERVED_7[124];
  __O  uint32_t NOT[1];                            /**< Toggle port, array offset: 0x2300, array step: 0x4 */
       uint8_t RESERVED_8[124];
  __O  uint32_t DIRSET[1];                         /**< Set pin direction bits for port, array offset: 0x2380, array step: 0x4 */
       uint8_t RESERVED_9[124];
  __O  uint32_t DIRCLR[1];                         /**< Clear pin direction bits for port, array offset: 0x2400, array step: 0x4 */
       uint8_t RESERVED_10[124];
  __O  uint32_t DIRNOT[1];                         /**< Toggle pin direction bits for port, array offset: 0x2480, array step: 0x4 */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name B - Byte pin registers for all port 0 and 1 GPIO pins */
/*! @{ */
#define GPIO_B_PBYTE_MASK                        (0x1U)
#define GPIO_B_PBYTE_SHIFT                       (0U)
#define GPIO_B_PBYTE(x)                          (((uint8_t)(((uint8_t)(x)) << GPIO_B_PBYTE_SHIFT)) & GPIO_B_PBYTE_MASK)
/*! @} */

/* The count of GPIO_B */
#define GPIO_B_COUNT                             (1U)

/* The count of GPIO_B */
#define GPIO_B_COUNT2                            (31U)

/*! @name W - Word pin registers for all port 0 and 1 GPIO pins */
/*! @{ */
#define GPIO_W_PWORD_MASK                        (0xFFFFFFFFU)
#define GPIO_W_PWORD_SHIFT                       (0U)
#define GPIO_W_PWORD(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_W_PWORD_SHIFT)) & GPIO_W_PWORD_MASK)
/*! @} */

/* The count of GPIO_W */
#define GPIO_W_COUNT                             (1U)

/* The count of GPIO_W */
#define GPIO_W_COUNT2                            (31U)

/*! @name DIR - Direction registers */
/*! @{ */
#define GPIO_DIR_DIRP_MASK                       (0x7FFFFFFFU)
#define GPIO_DIR_DIRP_SHIFT                      (0U)
#define GPIO_DIR_DIRP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DIR_DIRP_SHIFT)) & GPIO_DIR_DIRP_MASK)
/*! @} */

/* The count of GPIO_DIR */
#define GPIO_DIR_COUNT                           (1U)

/*! @name MASK - Mask register */
/*! @{ */
#define GPIO_MASK_MASKP_MASK                     (0x7FFFFFFFU)
#define GPIO_MASK_MASKP_SHIFT                    (0U)
#define GPIO_MASK_MASKP(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_MASK_MASKP_SHIFT)) & GPIO_MASK_MASKP_MASK)
/*! @} */

/* The count of GPIO_MASK */
#define GPIO_MASK_COUNT                          (1U)

/*! @name PIN - Port pin register */
/*! @{ */
#define GPIO_PIN_PORT_MASK                       (0x7FFFFFFFU)
#define GPIO_PIN_PORT_SHIFT                      (0U)
#define GPIO_PIN_PORT(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_PIN_PORT_SHIFT)) & GPIO_PIN_PORT_MASK)
/*! @} */

/* The count of GPIO_PIN */
#define GPIO_PIN_COUNT                           (1U)

/*! @name MPIN - Masked port register */
/*! @{ */
#define GPIO_MPIN_MPORTP_MASK                    (0x7FFFFFFFU)
#define GPIO_MPIN_MPORTP_SHIFT                   (0U)
#define GPIO_MPIN_MPORTP(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_MPIN_MPORTP_SHIFT)) & GPIO_MPIN_MPORTP_MASK)
/*! @} */

/* The count of GPIO_MPIN */
#define GPIO_MPIN_COUNT                          (1U)

/*! @name SET - Write: Set register for port Read: output bits for port */
/*! @{ */
#define GPIO_SET_SETP_MASK                       (0x7FFFFFFFU)
#define GPIO_SET_SETP_SHIFT                      (0U)
#define GPIO_SET_SETP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_SET_SETP_SHIFT)) & GPIO_SET_SETP_MASK)
/*! @} */

/* The count of GPIO_SET */
#define GPIO_SET_COUNT                           (1U)

/*! @name CLR - Clear port */
/*! @{ */
#define GPIO_CLR_CLRP_MASK                       (0x7FFFFFFFU)
#define GPIO_CLR_CLRP_SHIFT                      (0U)
#define GPIO_CLR_CLRP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_CLR_CLRP_SHIFT)) & GPIO_CLR_CLRP_MASK)
/*! @} */

/* The count of GPIO_CLR */
#define GPIO_CLR_COUNT                           (1U)

/*! @name NOT - Toggle port */
/*! @{ */
#define GPIO_NOT_NOTP_MASK                       (0x7FFFFFFFU)
#define GPIO_NOT_NOTP_SHIFT                      (0U)
#define GPIO_NOT_NOTP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_NOT_NOTP_SHIFT)) & GPIO_NOT_NOTP_MASK)
/*! @} */

/* The count of GPIO_NOT */
#define GPIO_NOT_COUNT                           (1U)

/*! @name DIRSET - Set pin direction bits for port */
/*! @{ */
#define GPIO_DIRSET_DIRSETP_MASK                 (0x7FFFFFFFU)
#define GPIO_DIRSET_DIRSETP_SHIFT                (0U)
#define GPIO_DIRSET_DIRSETP(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_DIRSET_DIRSETP_SHIFT)) & GPIO_DIRSET_DIRSETP_MASK)
/*! @} */

/* The count of GPIO_DIRSET */
#define GPIO_DIRSET_COUNT                        (1U)

/*! @name DIRCLR - Clear pin direction bits for port */
/*! @{ */
#define GPIO_DIRCLR_DIRCLRP_MASK                 (0x7FFFFFFFU)
#define GPIO_DIRCLR_DIRCLRP_SHIFT                (0U)
#define GPIO_DIRCLR_DIRCLRP(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_DIRCLR_DIRCLRP_SHIFT)) & GPIO_DIRCLR_DIRCLRP_MASK)
/*! @} */

/* The count of GPIO_DIRCLR */
#define GPIO_DIRCLR_COUNT                        (1U)

/*! @name DIRNOT - Toggle pin direction bits for port */
/*! @{ */
#define GPIO_DIRNOT_DIRNOTP_MASK                 (0x7FFFFFFFU)
#define GPIO_DIRNOT_DIRNOTP_SHIFT                (0U)
#define GPIO_DIRNOT_DIRNOTP(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_DIRNOT_DIRNOTP_SHIFT)) & GPIO_DIRNOT_DIRNOTP_MASK)
/*! @} */

/* The count of GPIO_DIRNOT */
#define GPIO_DIRNOT_COUNT                        (1U)


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO base address */
#define GPIO_BASE                                (0xA0000000u)
/** Peripheral GPIO base pointer */
#define GPIO                                     ((GPIO_Type *)GPIO_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO }

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */

/** I2C - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG;                               /**< Configuration for shared functions., offset: 0x0 */
  __IO uint32_t STAT;                              /**< Status register for Master, Slave, and Monitor functions., offset: 0x4 */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable Set and read register., offset: 0x8 */
  __O  uint32_t INTENCLR;                          /**< Interrupt Enable Clear register., offset: 0xC */
  __IO uint32_t TIMEOUT;                           /**< Time-out value register., offset: 0x10 */
  __IO uint32_t CLKDIV;                            /**< Clock pre-divider for the entire I2C interface. This determines what time increments are used for the MSTTIME register, and controls some timing of the Slave function., offset: 0x14 */
  __I  uint32_t INTSTAT;                           /**< Interrupt Status register for Master, Slave, and Monitor functions., offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t MSTCTL;                            /**< Master control register., offset: 0x20 */
  __IO uint32_t MSTTIME;                           /**< Master timing configuration., offset: 0x24 */
  __IO uint32_t MSTDAT;                            /**< Combined Master receiver and transmitter data register., offset: 0x28 */
       uint8_t RESERVED_1[20];
  __IO uint32_t SLVCTL;                            /**< Slave control register., offset: 0x40 */
  __IO uint32_t SLVDAT;                            /**< Combined Slave receiver and transmitter data register., offset: 0x44 */
  __IO uint32_t SLVADR[4];                         /**< Slave address register., array offset: 0x48, array step: 0x4 */
  __IO uint32_t SLVQUAL0;                          /**< Slave Qualification for address 0., offset: 0x58 */
       uint8_t RESERVED_2[36];
  __I  uint32_t MONRXDAT;                          /**< Monitor receiver data register., offset: 0x80 */
} I2C_Type;

/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/*! @name CFG - Configuration for shared functions. */
/*! @{ */
#define I2C_CFG_MSTEN_MASK                       (0x1U)
#define I2C_CFG_MSTEN_SHIFT                      (0U)
#define I2C_CFG_MSTEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_CFG_MSTEN_SHIFT)) & I2C_CFG_MSTEN_MASK)
#define I2C_CFG_SLVEN_MASK                       (0x2U)
#define I2C_CFG_SLVEN_SHIFT                      (1U)
#define I2C_CFG_SLVEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_CFG_SLVEN_SHIFT)) & I2C_CFG_SLVEN_MASK)
#define I2C_CFG_MONEN_MASK                       (0x4U)
#define I2C_CFG_MONEN_SHIFT                      (2U)
#define I2C_CFG_MONEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_CFG_MONEN_SHIFT)) & I2C_CFG_MONEN_MASK)
#define I2C_CFG_TIMEOUTEN_MASK                   (0x8U)
#define I2C_CFG_TIMEOUTEN_SHIFT                  (3U)
#define I2C_CFG_TIMEOUTEN(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CFG_TIMEOUTEN_SHIFT)) & I2C_CFG_TIMEOUTEN_MASK)
#define I2C_CFG_MONCLKSTR_MASK                   (0x10U)
#define I2C_CFG_MONCLKSTR_SHIFT                  (4U)
#define I2C_CFG_MONCLKSTR(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CFG_MONCLKSTR_SHIFT)) & I2C_CFG_MONCLKSTR_MASK)
/*! @} */

/*! @name STAT - Status register for Master, Slave, and Monitor functions. */
/*! @{ */
#define I2C_STAT_MSTPENDING_MASK                 (0x1U)
#define I2C_STAT_MSTPENDING_SHIFT                (0U)
#define I2C_STAT_MSTPENDING(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MSTPENDING_SHIFT)) & I2C_STAT_MSTPENDING_MASK)
#define I2C_STAT_MSTSTATE_MASK                   (0xEU)
#define I2C_STAT_MSTSTATE_SHIFT                  (1U)
#define I2C_STAT_MSTSTATE(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MSTSTATE_SHIFT)) & I2C_STAT_MSTSTATE_MASK)
#define I2C_STAT_MSTARBLOSS_MASK                 (0x10U)
#define I2C_STAT_MSTARBLOSS_SHIFT                (4U)
#define I2C_STAT_MSTARBLOSS(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MSTARBLOSS_SHIFT)) & I2C_STAT_MSTARBLOSS_MASK)
#define I2C_STAT_MSTSTSTPERR_MASK                (0x40U)
#define I2C_STAT_MSTSTSTPERR_SHIFT               (6U)
#define I2C_STAT_MSTSTSTPERR(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MSTSTSTPERR_SHIFT)) & I2C_STAT_MSTSTSTPERR_MASK)
#define I2C_STAT_SLVPENDING_MASK                 (0x100U)
#define I2C_STAT_SLVPENDING_SHIFT                (8U)
#define I2C_STAT_SLVPENDING(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SLVPENDING_SHIFT)) & I2C_STAT_SLVPENDING_MASK)
#define I2C_STAT_SLVSTATE_MASK                   (0x600U)
#define I2C_STAT_SLVSTATE_SHIFT                  (9U)
#define I2C_STAT_SLVSTATE(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SLVSTATE_SHIFT)) & I2C_STAT_SLVSTATE_MASK)
#define I2C_STAT_SLVNOTSTR_MASK                  (0x800U)
#define I2C_STAT_SLVNOTSTR_SHIFT                 (11U)
#define I2C_STAT_SLVNOTSTR(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SLVNOTSTR_SHIFT)) & I2C_STAT_SLVNOTSTR_MASK)
#define I2C_STAT_SLVIDX_MASK                     (0x3000U)
#define I2C_STAT_SLVIDX_SHIFT                    (12U)
#define I2C_STAT_SLVIDX(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SLVIDX_SHIFT)) & I2C_STAT_SLVIDX_MASK)
#define I2C_STAT_SLVSEL_MASK                     (0x4000U)
#define I2C_STAT_SLVSEL_SHIFT                    (14U)
#define I2C_STAT_SLVSEL(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SLVSEL_SHIFT)) & I2C_STAT_SLVSEL_MASK)
#define I2C_STAT_SLVDESEL_MASK                   (0x8000U)
#define I2C_STAT_SLVDESEL_SHIFT                  (15U)
#define I2C_STAT_SLVDESEL(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SLVDESEL_SHIFT)) & I2C_STAT_SLVDESEL_MASK)
#define I2C_STAT_MONRDY_MASK                     (0x10000U)
#define I2C_STAT_MONRDY_SHIFT                    (16U)
#define I2C_STAT_MONRDY(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MONRDY_SHIFT)) & I2C_STAT_MONRDY_MASK)
#define I2C_STAT_MONOV_MASK                      (0x20000U)
#define I2C_STAT_MONOV_SHIFT                     (17U)
#define I2C_STAT_MONOV(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MONOV_SHIFT)) & I2C_STAT_MONOV_MASK)
#define I2C_STAT_MONACTIVE_MASK                  (0x40000U)
#define I2C_STAT_MONACTIVE_SHIFT                 (18U)
#define I2C_STAT_MONACTIVE(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MONACTIVE_SHIFT)) & I2C_STAT_MONACTIVE_MASK)
#define I2C_STAT_MONIDLE_MASK                    (0x80000U)
#define I2C_STAT_MONIDLE_SHIFT                   (19U)
#define I2C_STAT_MONIDLE(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_STAT_MONIDLE_SHIFT)) & I2C_STAT_MONIDLE_MASK)
#define I2C_STAT_EVENTTIMEOUT_MASK               (0x1000000U)
#define I2C_STAT_EVENTTIMEOUT_SHIFT              (24U)
#define I2C_STAT_EVENTTIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_STAT_EVENTTIMEOUT_SHIFT)) & I2C_STAT_EVENTTIMEOUT_MASK)
#define I2C_STAT_SCLTIMEOUT_MASK                 (0x2000000U)
#define I2C_STAT_SCLTIMEOUT_SHIFT                (25U)
#define I2C_STAT_SCLTIMEOUT(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_STAT_SCLTIMEOUT_SHIFT)) & I2C_STAT_SCLTIMEOUT_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable Set and read register. */
/*! @{ */
#define I2C_INTENSET_MSTPENDINGEN_MASK           (0x1U)
#define I2C_INTENSET_MSTPENDINGEN_SHIFT          (0U)
#define I2C_INTENSET_MSTPENDINGEN(x)             (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_MSTPENDINGEN_SHIFT)) & I2C_INTENSET_MSTPENDINGEN_MASK)
#define I2C_INTENSET_MSTARBLOSSEN_MASK           (0x10U)
#define I2C_INTENSET_MSTARBLOSSEN_SHIFT          (4U)
#define I2C_INTENSET_MSTARBLOSSEN(x)             (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_MSTARBLOSSEN_SHIFT)) & I2C_INTENSET_MSTARBLOSSEN_MASK)
#define I2C_INTENSET_MSTSTSTPERREN_MASK          (0x40U)
#define I2C_INTENSET_MSTSTSTPERREN_SHIFT         (6U)
#define I2C_INTENSET_MSTSTSTPERREN(x)            (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_MSTSTSTPERREN_SHIFT)) & I2C_INTENSET_MSTSTSTPERREN_MASK)
#define I2C_INTENSET_SLVPENDINGEN_MASK           (0x100U)
#define I2C_INTENSET_SLVPENDINGEN_SHIFT          (8U)
#define I2C_INTENSET_SLVPENDINGEN(x)             (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_SLVPENDINGEN_SHIFT)) & I2C_INTENSET_SLVPENDINGEN_MASK)
#define I2C_INTENSET_SLVNOTSTREN_MASK            (0x800U)
#define I2C_INTENSET_SLVNOTSTREN_SHIFT           (11U)
#define I2C_INTENSET_SLVNOTSTREN(x)              (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_SLVNOTSTREN_SHIFT)) & I2C_INTENSET_SLVNOTSTREN_MASK)
#define I2C_INTENSET_SLVDESELEN_MASK             (0x8000U)
#define I2C_INTENSET_SLVDESELEN_SHIFT            (15U)
#define I2C_INTENSET_SLVDESELEN(x)               (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_SLVDESELEN_SHIFT)) & I2C_INTENSET_SLVDESELEN_MASK)
#define I2C_INTENSET_MONRDYEN_MASK               (0x10000U)
#define I2C_INTENSET_MONRDYEN_SHIFT              (16U)
#define I2C_INTENSET_MONRDYEN(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_MONRDYEN_SHIFT)) & I2C_INTENSET_MONRDYEN_MASK)
#define I2C_INTENSET_MONOVEN_MASK                (0x20000U)
#define I2C_INTENSET_MONOVEN_SHIFT               (17U)
#define I2C_INTENSET_MONOVEN(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_MONOVEN_SHIFT)) & I2C_INTENSET_MONOVEN_MASK)
#define I2C_INTENSET_MONIDLEEN_MASK              (0x80000U)
#define I2C_INTENSET_MONIDLEEN_SHIFT             (19U)
#define I2C_INTENSET_MONIDLEEN(x)                (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_MONIDLEEN_SHIFT)) & I2C_INTENSET_MONIDLEEN_MASK)
#define I2C_INTENSET_EVENTTIMEOUTEN_MASK         (0x1000000U)
#define I2C_INTENSET_EVENTTIMEOUTEN_SHIFT        (24U)
#define I2C_INTENSET_EVENTTIMEOUTEN(x)           (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_EVENTTIMEOUTEN_SHIFT)) & I2C_INTENSET_EVENTTIMEOUTEN_MASK)
#define I2C_INTENSET_SCLTIMEOUTEN_MASK           (0x2000000U)
#define I2C_INTENSET_SCLTIMEOUTEN_SHIFT          (25U)
#define I2C_INTENSET_SCLTIMEOUTEN(x)             (((uint32_t)(((uint32_t)(x)) << I2C_INTENSET_SCLTIMEOUTEN_SHIFT)) & I2C_INTENSET_SCLTIMEOUTEN_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Enable Clear register. */
/*! @{ */
#define I2C_INTENCLR_MSTPENDINGCLR_MASK          (0x1U)
#define I2C_INTENCLR_MSTPENDINGCLR_SHIFT         (0U)
#define I2C_INTENCLR_MSTPENDINGCLR(x)            (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_MSTPENDINGCLR_SHIFT)) & I2C_INTENCLR_MSTPENDINGCLR_MASK)
#define I2C_INTENCLR_MSTARBLOSSCLR_MASK          (0x10U)
#define I2C_INTENCLR_MSTARBLOSSCLR_SHIFT         (4U)
#define I2C_INTENCLR_MSTARBLOSSCLR(x)            (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_MSTARBLOSSCLR_SHIFT)) & I2C_INTENCLR_MSTARBLOSSCLR_MASK)
#define I2C_INTENCLR_MSTSTSTPERRCLR_MASK         (0x40U)
#define I2C_INTENCLR_MSTSTSTPERRCLR_SHIFT        (6U)
#define I2C_INTENCLR_MSTSTSTPERRCLR(x)           (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_MSTSTSTPERRCLR_SHIFT)) & I2C_INTENCLR_MSTSTSTPERRCLR_MASK)
#define I2C_INTENCLR_SLVPENDINGCLR_MASK          (0x100U)
#define I2C_INTENCLR_SLVPENDINGCLR_SHIFT         (8U)
#define I2C_INTENCLR_SLVPENDINGCLR(x)            (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_SLVPENDINGCLR_SHIFT)) & I2C_INTENCLR_SLVPENDINGCLR_MASK)
#define I2C_INTENCLR_SLVNOTSTRCLR_MASK           (0x800U)
#define I2C_INTENCLR_SLVNOTSTRCLR_SHIFT          (11U)
#define I2C_INTENCLR_SLVNOTSTRCLR(x)             (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_SLVNOTSTRCLR_SHIFT)) & I2C_INTENCLR_SLVNOTSTRCLR_MASK)
#define I2C_INTENCLR_SLVDESELCLR_MASK            (0x8000U)
#define I2C_INTENCLR_SLVDESELCLR_SHIFT           (15U)
#define I2C_INTENCLR_SLVDESELCLR(x)              (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_SLVDESELCLR_SHIFT)) & I2C_INTENCLR_SLVDESELCLR_MASK)
#define I2C_INTENCLR_MONRDYCLR_MASK              (0x10000U)
#define I2C_INTENCLR_MONRDYCLR_SHIFT             (16U)
#define I2C_INTENCLR_MONRDYCLR(x)                (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_MONRDYCLR_SHIFT)) & I2C_INTENCLR_MONRDYCLR_MASK)
#define I2C_INTENCLR_MONOVCLR_MASK               (0x20000U)
#define I2C_INTENCLR_MONOVCLR_SHIFT              (17U)
#define I2C_INTENCLR_MONOVCLR(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_MONOVCLR_SHIFT)) & I2C_INTENCLR_MONOVCLR_MASK)
#define I2C_INTENCLR_MONIDLECLR_MASK             (0x80000U)
#define I2C_INTENCLR_MONIDLECLR_SHIFT            (19U)
#define I2C_INTENCLR_MONIDLECLR(x)               (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_MONIDLECLR_SHIFT)) & I2C_INTENCLR_MONIDLECLR_MASK)
#define I2C_INTENCLR_EVENTTIMEOUTCLR_MASK        (0x1000000U)
#define I2C_INTENCLR_EVENTTIMEOUTCLR_SHIFT       (24U)
#define I2C_INTENCLR_EVENTTIMEOUTCLR(x)          (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_EVENTTIMEOUTCLR_SHIFT)) & I2C_INTENCLR_EVENTTIMEOUTCLR_MASK)
#define I2C_INTENCLR_SCLTIMEOUTCLR_MASK          (0x2000000U)
#define I2C_INTENCLR_SCLTIMEOUTCLR_SHIFT         (25U)
#define I2C_INTENCLR_SCLTIMEOUTCLR(x)            (((uint32_t)(((uint32_t)(x)) << I2C_INTENCLR_SCLTIMEOUTCLR_SHIFT)) & I2C_INTENCLR_SCLTIMEOUTCLR_MASK)
/*! @} */

/*! @name TIMEOUT - Time-out value register. */
/*! @{ */
#define I2C_TIMEOUT_TOMIN_MASK                   (0xFU)
#define I2C_TIMEOUT_TOMIN_SHIFT                  (0U)
#define I2C_TIMEOUT_TOMIN(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_TIMEOUT_TOMIN_SHIFT)) & I2C_TIMEOUT_TOMIN_MASK)
#define I2C_TIMEOUT_TO_MASK                      (0xFFF0U)
#define I2C_TIMEOUT_TO_SHIFT                     (4U)
#define I2C_TIMEOUT_TO(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_TIMEOUT_TO_SHIFT)) & I2C_TIMEOUT_TO_MASK)
/*! @} */

/*! @name CLKDIV - Clock pre-divider for the entire I2C interface. This determines what time increments are used for the MSTTIME register, and controls some timing of the Slave function. */
/*! @{ */
#define I2C_CLKDIV_DIVVAL_MASK                   (0xFFFFU)
#define I2C_CLKDIV_DIVVAL_SHIFT                  (0U)
#define I2C_CLKDIV_DIVVAL(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CLKDIV_DIVVAL_SHIFT)) & I2C_CLKDIV_DIVVAL_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt Status register for Master, Slave, and Monitor functions. */
/*! @{ */
#define I2C_INTSTAT_MSTPENDING_MASK              (0x1U)
#define I2C_INTSTAT_MSTPENDING_SHIFT             (0U)
#define I2C_INTSTAT_MSTPENDING(x)                (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_MSTPENDING_SHIFT)) & I2C_INTSTAT_MSTPENDING_MASK)
#define I2C_INTSTAT_MSTARBLOSS_MASK              (0x10U)
#define I2C_INTSTAT_MSTARBLOSS_SHIFT             (4U)
#define I2C_INTSTAT_MSTARBLOSS(x)                (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_MSTARBLOSS_SHIFT)) & I2C_INTSTAT_MSTARBLOSS_MASK)
#define I2C_INTSTAT_MSTSTSTPERR_MASK             (0x40U)
#define I2C_INTSTAT_MSTSTSTPERR_SHIFT            (6U)
#define I2C_INTSTAT_MSTSTSTPERR(x)               (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_MSTSTSTPERR_SHIFT)) & I2C_INTSTAT_MSTSTSTPERR_MASK)
#define I2C_INTSTAT_SLVPENDING_MASK              (0x100U)
#define I2C_INTSTAT_SLVPENDING_SHIFT             (8U)
#define I2C_INTSTAT_SLVPENDING(x)                (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_SLVPENDING_SHIFT)) & I2C_INTSTAT_SLVPENDING_MASK)
#define I2C_INTSTAT_SLVNOTSTR_MASK               (0x800U)
#define I2C_INTSTAT_SLVNOTSTR_SHIFT              (11U)
#define I2C_INTSTAT_SLVNOTSTR(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_SLVNOTSTR_SHIFT)) & I2C_INTSTAT_SLVNOTSTR_MASK)
#define I2C_INTSTAT_SLVDESEL_MASK                (0x8000U)
#define I2C_INTSTAT_SLVDESEL_SHIFT               (15U)
#define I2C_INTSTAT_SLVDESEL(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_SLVDESEL_SHIFT)) & I2C_INTSTAT_SLVDESEL_MASK)
#define I2C_INTSTAT_MONRDY_MASK                  (0x10000U)
#define I2C_INTSTAT_MONRDY_SHIFT                 (16U)
#define I2C_INTSTAT_MONRDY(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_MONRDY_SHIFT)) & I2C_INTSTAT_MONRDY_MASK)
#define I2C_INTSTAT_MONOV_MASK                   (0x20000U)
#define I2C_INTSTAT_MONOV_SHIFT                  (17U)
#define I2C_INTSTAT_MONOV(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_MONOV_SHIFT)) & I2C_INTSTAT_MONOV_MASK)
#define I2C_INTSTAT_MONIDLE_MASK                 (0x80000U)
#define I2C_INTSTAT_MONIDLE_SHIFT                (19U)
#define I2C_INTSTAT_MONIDLE(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_MONIDLE_SHIFT)) & I2C_INTSTAT_MONIDLE_MASK)
#define I2C_INTSTAT_EVENTTIMEOUT_MASK            (0x1000000U)
#define I2C_INTSTAT_EVENTTIMEOUT_SHIFT           (24U)
#define I2C_INTSTAT_EVENTTIMEOUT(x)              (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_EVENTTIMEOUT_SHIFT)) & I2C_INTSTAT_EVENTTIMEOUT_MASK)
#define I2C_INTSTAT_SCLTIMEOUT_MASK              (0x2000000U)
#define I2C_INTSTAT_SCLTIMEOUT_SHIFT             (25U)
#define I2C_INTSTAT_SCLTIMEOUT(x)                (((uint32_t)(((uint32_t)(x)) << I2C_INTSTAT_SCLTIMEOUT_SHIFT)) & I2C_INTSTAT_SCLTIMEOUT_MASK)
/*! @} */

/*! @name MSTCTL - Master control register. */
/*! @{ */
#define I2C_MSTCTL_MSTCONTINUE_MASK              (0x1U)
#define I2C_MSTCTL_MSTCONTINUE_SHIFT             (0U)
#define I2C_MSTCTL_MSTCONTINUE(x)                (((uint32_t)(((uint32_t)(x)) << I2C_MSTCTL_MSTCONTINUE_SHIFT)) & I2C_MSTCTL_MSTCONTINUE_MASK)
#define I2C_MSTCTL_MSTSTART_MASK                 (0x2U)
#define I2C_MSTCTL_MSTSTART_SHIFT                (1U)
#define I2C_MSTCTL_MSTSTART(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_MSTCTL_MSTSTART_SHIFT)) & I2C_MSTCTL_MSTSTART_MASK)
#define I2C_MSTCTL_MSTSTOP_MASK                  (0x4U)
#define I2C_MSTCTL_MSTSTOP_SHIFT                 (2U)
#define I2C_MSTCTL_MSTSTOP(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_MSTCTL_MSTSTOP_SHIFT)) & I2C_MSTCTL_MSTSTOP_MASK)
/*! @} */

/*! @name MSTTIME - Master timing configuration. */
/*! @{ */
#define I2C_MSTTIME_MSTSCLLOW_MASK               (0x7U)
#define I2C_MSTTIME_MSTSCLLOW_SHIFT              (0U)
#define I2C_MSTTIME_MSTSCLLOW(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_MSTTIME_MSTSCLLOW_SHIFT)) & I2C_MSTTIME_MSTSCLLOW_MASK)
#define I2C_MSTTIME_MSTSCLHIGH_MASK              (0x70U)
#define I2C_MSTTIME_MSTSCLHIGH_SHIFT             (4U)
#define I2C_MSTTIME_MSTSCLHIGH(x)                (((uint32_t)(((uint32_t)(x)) << I2C_MSTTIME_MSTSCLHIGH_SHIFT)) & I2C_MSTTIME_MSTSCLHIGH_MASK)
/*! @} */

/*! @name MSTDAT - Combined Master receiver and transmitter data register. */
/*! @{ */
#define I2C_MSTDAT_DATA_MASK                     (0xFFU)
#define I2C_MSTDAT_DATA_SHIFT                    (0U)
#define I2C_MSTDAT_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_MSTDAT_DATA_SHIFT)) & I2C_MSTDAT_DATA_MASK)
/*! @} */

/*! @name SLVCTL - Slave control register. */
/*! @{ */
#define I2C_SLVCTL_SLVCONTINUE_MASK              (0x1U)
#define I2C_SLVCTL_SLVCONTINUE_SHIFT             (0U)
#define I2C_SLVCTL_SLVCONTINUE(x)                (((uint32_t)(((uint32_t)(x)) << I2C_SLVCTL_SLVCONTINUE_SHIFT)) & I2C_SLVCTL_SLVCONTINUE_MASK)
#define I2C_SLVCTL_SLVNACK_MASK                  (0x2U)
#define I2C_SLVCTL_SLVNACK_SHIFT                 (1U)
#define I2C_SLVCTL_SLVNACK(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_SLVCTL_SLVNACK_SHIFT)) & I2C_SLVCTL_SLVNACK_MASK)
/*! @} */

/*! @name SLVDAT - Combined Slave receiver and transmitter data register. */
/*! @{ */
#define I2C_SLVDAT_DATA_MASK                     (0xFFU)
#define I2C_SLVDAT_DATA_SHIFT                    (0U)
#define I2C_SLVDAT_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_SLVDAT_DATA_SHIFT)) & I2C_SLVDAT_DATA_MASK)
/*! @} */

/*! @name SLVADR - Slave address register. */
/*! @{ */
#define I2C_SLVADR_SADISABLE_MASK                (0x1U)
#define I2C_SLVADR_SADISABLE_SHIFT               (0U)
#define I2C_SLVADR_SADISABLE(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_SLVADR_SADISABLE_SHIFT)) & I2C_SLVADR_SADISABLE_MASK)
#define I2C_SLVADR_SLVADR_MASK                   (0xFEU)
#define I2C_SLVADR_SLVADR_SHIFT                  (1U)
#define I2C_SLVADR_SLVADR(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_SLVADR_SLVADR_SHIFT)) & I2C_SLVADR_SLVADR_MASK)
/*! @} */

/* The count of I2C_SLVADR */
#define I2C_SLVADR_COUNT                         (4U)

/*! @name SLVQUAL0 - Slave Qualification for address 0. */
/*! @{ */
#define I2C_SLVQUAL0_QUALMODE0_MASK              (0x1U)
#define I2C_SLVQUAL0_QUALMODE0_SHIFT             (0U)
#define I2C_SLVQUAL0_QUALMODE0(x)                (((uint32_t)(((uint32_t)(x)) << I2C_SLVQUAL0_QUALMODE0_SHIFT)) & I2C_SLVQUAL0_QUALMODE0_MASK)
#define I2C_SLVQUAL0_SLVQUAL0_MASK               (0xFEU)
#define I2C_SLVQUAL0_SLVQUAL0_SHIFT              (1U)
#define I2C_SLVQUAL0_SLVQUAL0(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_SLVQUAL0_SLVQUAL0_SHIFT)) & I2C_SLVQUAL0_SLVQUAL0_MASK)
/*! @} */

/*! @name MONRXDAT - Monitor receiver data register. */
/*! @{ */
#define I2C_MONRXDAT_MONRXDAT_MASK               (0xFFU)
#define I2C_MONRXDAT_MONRXDAT_SHIFT              (0U)
#define I2C_MONRXDAT_MONRXDAT(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_MONRXDAT_MONRXDAT_SHIFT)) & I2C_MONRXDAT_MONRXDAT_MASK)
#define I2C_MONRXDAT_MONSTART_MASK               (0x100U)
#define I2C_MONRXDAT_MONSTART_SHIFT              (8U)
#define I2C_MONRXDAT_MONSTART(x)                 (((uint32_t)(((uint32_t)(x)) << I2C_MONRXDAT_MONSTART_SHIFT)) & I2C_MONRXDAT_MONSTART_MASK)
#define I2C_MONRXDAT_MONRESTART_MASK             (0x200U)
#define I2C_MONRXDAT_MONRESTART_SHIFT            (9U)
#define I2C_MONRXDAT_MONRESTART(x)               (((uint32_t)(((uint32_t)(x)) << I2C_MONRXDAT_MONRESTART_SHIFT)) & I2C_MONRXDAT_MONRESTART_MASK)
#define I2C_MONRXDAT_MONNACK_MASK                (0x400U)
#define I2C_MONRXDAT_MONNACK_SHIFT               (10U)
#define I2C_MONRXDAT_MONNACK(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_MONRXDAT_MONNACK_SHIFT)) & I2C_MONRXDAT_MONNACK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40050000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x40054000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0, I2C1 }
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { I2C0_IRQn, I2C1_IRQn }

/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IOCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Peripheral_Access_Layer IOCON Peripheral Access Layer
 * @{
 */

/** IOCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[30];                           /**< Digital I/O control for port 0 pins PIO0..Digital I/O control for port 0 pins PIO29, array offset: 0x0, array step: 0x4 */
} IOCON_Type;

/* ----------------------------------------------------------------------------
   -- IOCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Register_Masks IOCON Register Masks
 * @{
 */

/*! @name PIO - Digital I/O control for port 0 pins PIO0..Digital I/O control for port 0 pins PIO29 */
/*! @{ */
#define IOCON_PIO_MODE_MASK                      (0x18U)
#define IOCON_PIO_MODE_SHIFT                     (3U)
#define IOCON_PIO_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_MODE_SHIFT)) & IOCON_PIO_MODE_MASK)
#define IOCON_PIO_HYS_MASK                       (0x20U)
#define IOCON_PIO_HYS_SHIFT                      (5U)
#define IOCON_PIO_HYS(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_HYS_SHIFT)) & IOCON_PIO_HYS_MASK)
#define IOCON_PIO_INV_MASK                       (0x40U)
#define IOCON_PIO_INV_SHIFT                      (6U)
#define IOCON_PIO_INV(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_INV_SHIFT)) & IOCON_PIO_INV_MASK)
#define IOCON_PIO_OD_MASK                        (0x400U)
#define IOCON_PIO_OD_SHIFT                       (10U)
#define IOCON_PIO_OD(x)                          (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_OD_SHIFT)) & IOCON_PIO_OD_MASK)
#define IOCON_PIO_DACMODE_MASK                   (0x10000U)
#define IOCON_PIO_DACMODE_SHIFT                  (16U)
#define IOCON_PIO_DACMODE(x)                     (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_DACMODE_SHIFT)) & IOCON_PIO_DACMODE_MASK)
/*! @} */

/* The count of IOCON_PIO */
#define IOCON_PIO_COUNT                          (30U)


/*!
 * @}
 */ /* end of group IOCON_Register_Masks */


/* IOCON - Peripheral instance base addresses */
/** Peripheral IOCON base address */
#define IOCON_BASE                               (0x40044000u)
/** Peripheral IOCON base pointer */
#define IOCON                                    ((IOCON_Type *)IOCON_BASE)
/** Array initializer of IOCON peripheral base addresses */
#define IOCON_BASE_ADDRS                         { IOCON_BASE }
/** Array initializer of IOCON peripheral base pointers */
#define IOCON_BASE_PTRS                          { IOCON }

#define    IOCON_INDEX_PIO0_17       ( 0)
#define    IOCON_INDEX_PIO0_13       ( 1)
#define    IOCON_INDEX_PIO0_12       ( 2)
#define    IOCON_INDEX_PIO0_5        ( 3)
#define    IOCON_INDEX_PIO0_4        ( 4)
#define    IOCON_INDEX_PIO0_3        ( 5)
#define    IOCON_INDEX_PIO0_2        ( 6)
#define    IOCON_INDEX_PIO0_11       ( 7)
#define    IOCON_INDEX_PIO0_10       ( 8)
#define    IOCON_INDEX_PIO0_16       ( 9)
#define    IOCON_INDEX_PIO0_15       (10)
#define    IOCON_INDEX_PIO0_1        (11)
#define    IOCON_INDEX_PIO0_21       (12)
#define    IOCON_INDEX_PIO0_9        (13)
#define    IOCON_INDEX_PIO0_8        (14)
#define    IOCON_INDEX_PIO0_7        (15)
#define    IOCON_INDEX_PIO0_29       (16)
#define    IOCON_INDEX_PIO0_0        (17)
#define    IOCON_INDEX_PIO0_14       (18)
#define    IOCON_INDEX_PIO0_28       (19)
#define    IOCON_INDEX_PIO0_27       (20)
#define    IOCON_INDEX_PIO0_26       (21)
#define    IOCON_INDEX_PIO0_20       (22)
#define    IOCON_INDEX_PIO0_30       (23)
#define    IOCON_INDEX_PIO0_19       (24)
#define    IOCON_INDEX_PIO0_25       (25)
#define    IOCON_INDEX_PIO0_24       (26)
#define    IOCON_INDEX_PIO0_23       (27)
#define    IOCON_INDEX_PIO0_22       (28)
#define    IOCON_INDEX_PIO0_18       (29)


/*!
 * @}
 */ /* end of group IOCON_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MRT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRT_Peripheral_Access_Layer MRT Peripheral Access Layer
 * @{
 */

/** MRT - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t INTVAL;                            /**< MRT Time interval value register. This value is loaded into the TIMER register., array offset: 0x0, array step: 0x10 */
    __I  uint32_t TIMER;                             /**< MRT Timer register. This register reads the value of the down-counter., array offset: 0x4, array step: 0x10 */
    __IO uint32_t CTRL;                              /**< MRT Control register. This register controls the MRT modes., array offset: 0x8, array step: 0x10 */
    __IO uint32_t STAT;                              /**< MRT Status register., array offset: 0xC, array step: 0x10 */
  } CHANNEL[4];
       uint8_t RESERVED_0[176];
  __I  uint32_t MODCFG;                            /**< Module Configuration register. This register provides information about this particular MRT instance., offset: 0xF0 */
  __I  uint32_t IDLE_CH;                           /**< Idle channel register. This register returns the number of the first idle channel., offset: 0xF4 */
  __IO uint32_t IRQ_FLAG;                          /**< Global interrupt flag register, offset: 0xF8 */
} MRT_Type;

/* ----------------------------------------------------------------------------
   -- MRT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRT_Register_Masks MRT Register Masks
 * @{
 */

/*! @name CHANNEL_INTVAL - MRT Time interval value register. This value is loaded into the TIMER register. */
/*! @{ */
#define MRT_CHANNEL_INTVAL_IVALUE_MASK           (0x7FFFFFFFU)
#define MRT_CHANNEL_INTVAL_IVALUE_SHIFT          (0U)
#define MRT_CHANNEL_INTVAL_IVALUE(x)             (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_INTVAL_IVALUE_SHIFT)) & MRT_CHANNEL_INTVAL_IVALUE_MASK)
#define MRT_CHANNEL_INTVAL_LOAD_MASK             (0x80000000U)
#define MRT_CHANNEL_INTVAL_LOAD_SHIFT            (31U)
#define MRT_CHANNEL_INTVAL_LOAD(x)               (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_INTVAL_LOAD_SHIFT)) & MRT_CHANNEL_INTVAL_LOAD_MASK)
/*! @} */

/* The count of MRT_CHANNEL_INTVAL */
#define MRT_CHANNEL_INTVAL_COUNT                 (4U)

/*! @name CHANNEL_TIMER - MRT Timer register. This register reads the value of the down-counter. */
/*! @{ */
#define MRT_CHANNEL_TIMER_VALUE_MASK             (0x7FFFFFFFU)
#define MRT_CHANNEL_TIMER_VALUE_SHIFT            (0U)
#define MRT_CHANNEL_TIMER_VALUE(x)               (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_TIMER_VALUE_SHIFT)) & MRT_CHANNEL_TIMER_VALUE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_TIMER */
#define MRT_CHANNEL_TIMER_COUNT                  (4U)

/*! @name CHANNEL_CTRL - MRT Control register. This register controls the MRT modes. */
/*! @{ */
#define MRT_CHANNEL_CTRL_INTEN_MASK              (0x1U)
#define MRT_CHANNEL_CTRL_INTEN_SHIFT             (0U)
#define MRT_CHANNEL_CTRL_INTEN(x)                (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_CTRL_INTEN_SHIFT)) & MRT_CHANNEL_CTRL_INTEN_MASK)
#define MRT_CHANNEL_CTRL_MODE_MASK               (0x6U)
#define MRT_CHANNEL_CTRL_MODE_SHIFT              (1U)
#define MRT_CHANNEL_CTRL_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_CTRL_MODE_SHIFT)) & MRT_CHANNEL_CTRL_MODE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_CTRL */
#define MRT_CHANNEL_CTRL_COUNT                   (4U)

/*! @name CHANNEL_STAT - MRT Status register. */
/*! @{ */
#define MRT_CHANNEL_STAT_INTFLAG_MASK            (0x1U)
#define MRT_CHANNEL_STAT_INTFLAG_SHIFT           (0U)
#define MRT_CHANNEL_STAT_INTFLAG(x)              (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_INTFLAG_SHIFT)) & MRT_CHANNEL_STAT_INTFLAG_MASK)
#define MRT_CHANNEL_STAT_RUN_MASK                (0x2U)
#define MRT_CHANNEL_STAT_RUN_SHIFT               (1U)
#define MRT_CHANNEL_STAT_RUN(x)                  (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_RUN_SHIFT)) & MRT_CHANNEL_STAT_RUN_MASK)
/*! @} */

/* The count of MRT_CHANNEL_STAT */
#define MRT_CHANNEL_STAT_COUNT                   (4U)

/*! @name MODCFG - Module Configuration register. This register provides information about this particular MRT instance. */
/*! @{ */
#define MRT_MODCFG_NOC_MASK                      (0xFU)
#define MRT_MODCFG_NOC_SHIFT                     (0U)
#define MRT_MODCFG_NOC(x)                        (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_NOC_SHIFT)) & MRT_MODCFG_NOC_MASK)
#define MRT_MODCFG_NOB_MASK                      (0x1F0U)
#define MRT_MODCFG_NOB_SHIFT                     (4U)
#define MRT_MODCFG_NOB(x)                        (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_NOB_SHIFT)) & MRT_MODCFG_NOB_MASK)
/*! @} */

/*! @name IDLE_CH - Idle channel register. This register returns the number of the first idle channel. */
/*! @{ */
#define MRT_IDLE_CH_CHAN_MASK                    (0xF0U)
#define MRT_IDLE_CH_CHAN_SHIFT                   (4U)
#define MRT_IDLE_CH_CHAN(x)                      (((uint32_t)(((uint32_t)(x)) << MRT_IDLE_CH_CHAN_SHIFT)) & MRT_IDLE_CH_CHAN_MASK)
/*! @} */

/*! @name IRQ_FLAG - Global interrupt flag register */
/*! @{ */
#define MRT_IRQ_FLAG_GFLAG0_MASK                 (0x1U)
#define MRT_IRQ_FLAG_GFLAG0_SHIFT                (0U)
#define MRT_IRQ_FLAG_GFLAG0(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG0_SHIFT)) & MRT_IRQ_FLAG_GFLAG0_MASK)
#define MRT_IRQ_FLAG_GFLAG1_MASK                 (0x2U)
#define MRT_IRQ_FLAG_GFLAG1_SHIFT                (1U)
#define MRT_IRQ_FLAG_GFLAG1(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG1_SHIFT)) & MRT_IRQ_FLAG_GFLAG1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRT_Register_Masks */


/* MRT - Peripheral instance base addresses */
/** Peripheral MRT0 base address */
#define MRT0_BASE                                (0x40004000u)
/** Peripheral MRT0 base pointer */
#define MRT0                                     ((MRT_Type *)MRT0_BASE)
/** Array initializer of MRT peripheral base addresses */
#define MRT_BASE_ADDRS                           { MRT0_BASE }
/** Array initializer of MRT peripheral base pointers */
#define MRT_BASE_PTRS                            { MRT0 }

/*!
 * @}
 */ /* end of group MRT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PINT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PINT_Peripheral_Access_Layer PINT Peripheral Access Layer
 * @{
 */

/** PINT - Register Layout Typedef */
typedef struct {
  __IO uint32_t ISEL;                              /**< Pin Interrupt Mode register, offset: 0x0 */
  __IO uint32_t IENR;                              /**< Pin interrupt level or rising edge interrupt enable register, offset: 0x4 */
  __O  uint32_t SIENR;                             /**< Pin interrupt level or rising edge interrupt set register, offset: 0x8 */
  __O  uint32_t CIENR;                             /**< Pin interrupt level (rising edge interrupt) clear register, offset: 0xC */
  __IO uint32_t IENF;                              /**< Pin interrupt active level or falling edge interrupt enable register, offset: 0x10 */
  __O  uint32_t SIENF;                             /**< Pin interrupt active level or falling edge interrupt set register, offset: 0x14 */
  __O  uint32_t CIENF;                             /**< Pin interrupt active level or falling edge interrupt clear register, offset: 0x18 */
  __IO uint32_t RISE;                              /**< Pin interrupt rising edge register, offset: 0x1C */
  __IO uint32_t FALL;                              /**< Pin interrupt falling edge register, offset: 0x20 */
  __IO uint32_t IST;                               /**< Pin interrupt status register, offset: 0x24 */
  __IO uint32_t PMCTRL;                            /**< Pattern match interrupt control register, offset: 0x28 */
  __IO uint32_t PMSRC;                             /**< Pattern match interrupt bit-slice source register, offset: 0x2C */
  __IO uint32_t PMCFG;                             /**< Pattern match interrupt bit slice configuration register, offset: 0x30 */
} PINT_Type;

/* ----------------------------------------------------------------------------
   -- PINT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PINT_Register_Masks PINT Register Masks
 * @{
 */

/*! @name ISEL - Pin Interrupt Mode register */
/*! @{ */
#define PINT_ISEL_PMODE_MASK                     (0xFFU)
#define PINT_ISEL_PMODE_SHIFT                    (0U)
#define PINT_ISEL_PMODE(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_ISEL_PMODE_SHIFT)) & PINT_ISEL_PMODE_MASK)
/*! @} */

/*! @name IENR - Pin interrupt level or rising edge interrupt enable register */
/*! @{ */
#define PINT_IENR_ENRL_MASK                      (0xFFU)
#define PINT_IENR_ENRL_SHIFT                     (0U)
#define PINT_IENR_ENRL(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IENR_ENRL_SHIFT)) & PINT_IENR_ENRL_MASK)
/*! @} */

/*! @name SIENR - Pin interrupt level or rising edge interrupt set register */
/*! @{ */
#define PINT_SIENR_SETENRL_MASK                  (0xFFU)
#define PINT_SIENR_SETENRL_SHIFT                 (0U)
#define PINT_SIENR_SETENRL(x)                    (((uint32_t)(((uint32_t)(x)) << PINT_SIENR_SETENRL_SHIFT)) & PINT_SIENR_SETENRL_MASK)
/*! @} */

/*! @name CIENR - Pin interrupt level (rising edge interrupt) clear register */
/*! @{ */
#define PINT_CIENR_CENRL_MASK                    (0xFFU)
#define PINT_CIENR_CENRL_SHIFT                   (0U)
#define PINT_CIENR_CENRL(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_CIENR_CENRL_SHIFT)) & PINT_CIENR_CENRL_MASK)
/*! @} */

/*! @name IENF - Pin interrupt active level or falling edge interrupt enable register */
/*! @{ */
#define PINT_IENF_ENAF_MASK                      (0xFFU)
#define PINT_IENF_ENAF_SHIFT                     (0U)
#define PINT_IENF_ENAF(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IENF_ENAF_SHIFT)) & PINT_IENF_ENAF_MASK)
/*! @} */

/*! @name SIENF - Pin interrupt active level or falling edge interrupt set register */
/*! @{ */
#define PINT_SIENF_SETENAF_MASK                  (0xFFU)
#define PINT_SIENF_SETENAF_SHIFT                 (0U)
#define PINT_SIENF_SETENAF(x)                    (((uint32_t)(((uint32_t)(x)) << PINT_SIENF_SETENAF_SHIFT)) & PINT_SIENF_SETENAF_MASK)
/*! @} */

/*! @name CIENF - Pin interrupt active level or falling edge interrupt clear register */
/*! @{ */
#define PINT_CIENF_CENAF_MASK                    (0xFFU)
#define PINT_CIENF_CENAF_SHIFT                   (0U)
#define PINT_CIENF_CENAF(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_CIENF_CENAF_SHIFT)) & PINT_CIENF_CENAF_MASK)
/*! @} */

/*! @name RISE - Pin interrupt rising edge register */
/*! @{ */
#define PINT_RISE_RDET_MASK                      (0xFFU)
#define PINT_RISE_RDET_SHIFT                     (0U)
#define PINT_RISE_RDET(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_RISE_RDET_SHIFT)) & PINT_RISE_RDET_MASK)
/*! @} */

/*! @name FALL - Pin interrupt falling edge register */
/*! @{ */
#define PINT_FALL_FDET_MASK                      (0xFFU)
#define PINT_FALL_FDET_SHIFT                     (0U)
#define PINT_FALL_FDET(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_FALL_FDET_SHIFT)) & PINT_FALL_FDET_MASK)
/*! @} */

/*! @name IST - Pin interrupt status register */
/*! @{ */
#define PINT_IST_PSTAT_MASK                      (0xFFU)
#define PINT_IST_PSTAT_SHIFT                     (0U)
#define PINT_IST_PSTAT(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IST_PSTAT_SHIFT)) & PINT_IST_PSTAT_MASK)
/*! @} */

/*! @name PMCTRL - Pattern match interrupt control register */
/*! @{ */
#define PINT_PMCTRL_SEL_PMATCH_MASK              (0x1U)
#define PINT_PMCTRL_SEL_PMATCH_SHIFT             (0U)
#define PINT_PMCTRL_SEL_PMATCH(x)                (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_SEL_PMATCH_SHIFT)) & PINT_PMCTRL_SEL_PMATCH_MASK)
#define PINT_PMCTRL_ENA_RXEV_MASK                (0x2U)
#define PINT_PMCTRL_ENA_RXEV_SHIFT               (1U)
#define PINT_PMCTRL_ENA_RXEV(x)                  (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_ENA_RXEV_SHIFT)) & PINT_PMCTRL_ENA_RXEV_MASK)
#define PINT_PMCTRL_PMAT_MASK                    (0xFF000000U)
#define PINT_PMCTRL_PMAT_SHIFT                   (24U)
#define PINT_PMCTRL_PMAT(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_PMAT_SHIFT)) & PINT_PMCTRL_PMAT_MASK)
/*! @} */

/*! @name PMSRC - Pattern match interrupt bit-slice source register */
/*! @{ */
#define PINT_PMSRC_SRC0_MASK                     (0x700U)
#define PINT_PMSRC_SRC0_SHIFT                    (8U)
#define PINT_PMSRC_SRC0(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC0_SHIFT)) & PINT_PMSRC_SRC0_MASK)
#define PINT_PMSRC_SRC1_MASK                     (0x3800U)
#define PINT_PMSRC_SRC1_SHIFT                    (11U)
#define PINT_PMSRC_SRC1(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC1_SHIFT)) & PINT_PMSRC_SRC1_MASK)
#define PINT_PMSRC_SRC2_MASK                     (0x1C000U)
#define PINT_PMSRC_SRC2_SHIFT                    (14U)
#define PINT_PMSRC_SRC2(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC2_SHIFT)) & PINT_PMSRC_SRC2_MASK)
#define PINT_PMSRC_SRC3_MASK                     (0xE0000U)
#define PINT_PMSRC_SRC3_SHIFT                    (17U)
#define PINT_PMSRC_SRC3(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC3_SHIFT)) & PINT_PMSRC_SRC3_MASK)
#define PINT_PMSRC_SRC4_MASK                     (0x700000U)
#define PINT_PMSRC_SRC4_SHIFT                    (20U)
#define PINT_PMSRC_SRC4(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC4_SHIFT)) & PINT_PMSRC_SRC4_MASK)
#define PINT_PMSRC_SRC5_MASK                     (0x3800000U)
#define PINT_PMSRC_SRC5_SHIFT                    (23U)
#define PINT_PMSRC_SRC5(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC5_SHIFT)) & PINT_PMSRC_SRC5_MASK)
#define PINT_PMSRC_SRC6_MASK                     (0x1C000000U)
#define PINT_PMSRC_SRC6_SHIFT                    (26U)
#define PINT_PMSRC_SRC6(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC6_SHIFT)) & PINT_PMSRC_SRC6_MASK)
#define PINT_PMSRC_SRC7_MASK                     (0xE0000000U)
#define PINT_PMSRC_SRC7_SHIFT                    (29U)
#define PINT_PMSRC_SRC7(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC7_SHIFT)) & PINT_PMSRC_SRC7_MASK)
/*! @} */

/*! @name PMCFG - Pattern match interrupt bit slice configuration register */
/*! @{ */
#define PINT_PMCFG_PROD_ENDPTS0_MASK             (0x1U)
#define PINT_PMCFG_PROD_ENDPTS0_SHIFT            (0U)
#define PINT_PMCFG_PROD_ENDPTS0(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS0_SHIFT)) & PINT_PMCFG_PROD_ENDPTS0_MASK)
#define PINT_PMCFG_PROD_ENDPTS1_MASK             (0x2U)
#define PINT_PMCFG_PROD_ENDPTS1_SHIFT            (1U)
#define PINT_PMCFG_PROD_ENDPTS1(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS1_SHIFT)) & PINT_PMCFG_PROD_ENDPTS1_MASK)
#define PINT_PMCFG_PROD_ENDPTS2_MASK             (0x4U)
#define PINT_PMCFG_PROD_ENDPTS2_SHIFT            (2U)
#define PINT_PMCFG_PROD_ENDPTS2(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS2_SHIFT)) & PINT_PMCFG_PROD_ENDPTS2_MASK)
#define PINT_PMCFG_PROD_ENDPTS3_MASK             (0x8U)
#define PINT_PMCFG_PROD_ENDPTS3_SHIFT            (3U)
#define PINT_PMCFG_PROD_ENDPTS3(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS3_SHIFT)) & PINT_PMCFG_PROD_ENDPTS3_MASK)
#define PINT_PMCFG_PROD_ENDPTS4_MASK             (0x10U)
#define PINT_PMCFG_PROD_ENDPTS4_SHIFT            (4U)
#define PINT_PMCFG_PROD_ENDPTS4(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS4_SHIFT)) & PINT_PMCFG_PROD_ENDPTS4_MASK)
#define PINT_PMCFG_PROD_ENDPTS5_MASK             (0x20U)
#define PINT_PMCFG_PROD_ENDPTS5_SHIFT            (5U)
#define PINT_PMCFG_PROD_ENDPTS5(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS5_SHIFT)) & PINT_PMCFG_PROD_ENDPTS5_MASK)
#define PINT_PMCFG_PROD_ENDPTS6_MASK             (0x40U)
#define PINT_PMCFG_PROD_ENDPTS6_SHIFT            (6U)
#define PINT_PMCFG_PROD_ENDPTS6(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS6_SHIFT)) & PINT_PMCFG_PROD_ENDPTS6_MASK)
#define PINT_PMCFG_CFG0_MASK                     (0x700U)
#define PINT_PMCFG_CFG0_SHIFT                    (8U)
#define PINT_PMCFG_CFG0(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG0_SHIFT)) & PINT_PMCFG_CFG0_MASK)
#define PINT_PMCFG_CFG1_MASK                     (0x3800U)
#define PINT_PMCFG_CFG1_SHIFT                    (11U)
#define PINT_PMCFG_CFG1(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG1_SHIFT)) & PINT_PMCFG_CFG1_MASK)
#define PINT_PMCFG_CFG2_MASK                     (0x1C000U)
#define PINT_PMCFG_CFG2_SHIFT                    (14U)
#define PINT_PMCFG_CFG2(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG2_SHIFT)) & PINT_PMCFG_CFG2_MASK)
#define PINT_PMCFG_CFG3_MASK                     (0xE0000U)
#define PINT_PMCFG_CFG3_SHIFT                    (17U)
#define PINT_PMCFG_CFG3(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG3_SHIFT)) & PINT_PMCFG_CFG3_MASK)
#define PINT_PMCFG_CFG4_MASK                     (0x700000U)
#define PINT_PMCFG_CFG4_SHIFT                    (20U)
#define PINT_PMCFG_CFG4(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG4_SHIFT)) & PINT_PMCFG_CFG4_MASK)
#define PINT_PMCFG_CFG5_MASK                     (0x3800000U)
#define PINT_PMCFG_CFG5_SHIFT                    (23U)
#define PINT_PMCFG_CFG5(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG5_SHIFT)) & PINT_PMCFG_CFG5_MASK)
#define PINT_PMCFG_CFG6_MASK                     (0x1C000000U)
#define PINT_PMCFG_CFG6_SHIFT                    (26U)
#define PINT_PMCFG_CFG6(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG6_SHIFT)) & PINT_PMCFG_CFG6_MASK)
#define PINT_PMCFG_CFG7_MASK                     (0xE0000000U)
#define PINT_PMCFG_CFG7_SHIFT                    (29U)
#define PINT_PMCFG_CFG7(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG7_SHIFT)) & PINT_PMCFG_CFG7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PINT_Register_Masks */


/* PINT - Peripheral instance base addresses */
/** Peripheral PINT base address */
#define PINT_BASE                                (0xA0004000u)
/** Peripheral PINT base pointer */
#define PINT                                     ((PINT_Type *)PINT_BASE)
/** Array initializer of PINT peripheral base addresses */
#define PINT_BASE_ADDRS                          { PINT_BASE }
/** Array initializer of PINT peripheral base pointers */
#define PINT_BASE_PTRS                           { PINT }
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn }

/*!
 * @}
 */ /* end of group PINT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PLU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLU_Peripheral_Access_Layer PLU Peripheral Access Layer
 * @{
 */

/** PLU - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x20 */
    __IO uint32_t INP[5];                            /**< LUT0 input 0 MUX..LUT25 input 4 MUX, array offset: 0x0, array step: index*0x20, index2*0x4 */
         uint8_t RESERVED_0[12];
  } LUT[26];
       uint8_t RESERVED_0[1216];
  __IO uint32_t LUT_TRUTH[26];                     /**< Specifies the Truth Table contents for LUT0..Specifies the Truth Table contents for LUT25, array offset: 0x800, array step: 0x4 */
       uint8_t RESERVED_1[152];
  __I  uint32_t OUTPUTS;                           /**< Provides the current state of the 8 designated PLU Outputs., offset: 0x900 */
       uint8_t RESERVED_2[764];
  __IO uint32_t OUTPUT_MUX[8];                     /**< Selects the source to be connected to PLU Output 0..Selects the source to be connected to PLU Output 7, array offset: 0xC00, array step: 0x4 */
} PLU_Type;

/* ----------------------------------------------------------------------------
   -- PLU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLU_Register_Masks PLU Register Masks
 * @{
 */

/*! @name LUT_INP - LUT0 input 0 MUX..LUT25 input 4 MUX */
/*! @{ */
#define PLU_LUT_INP_LUT_INP_MASK                 (0x3FU)
#define PLU_LUT_INP_LUT_INP_SHIFT                (0U)
#define PLU_LUT_INP_LUT_INP(x)                   (((uint32_t)(((uint32_t)(x)) << PLU_LUT_INP_LUT_INP_SHIFT)) & PLU_LUT_INP_LUT_INP_MASK)
/*! @} */

/* The count of PLU_LUT_INP */
#define PLU_LUT_INP_COUNT                        (26U)

/* The count of PLU_LUT_INP */
#define PLU_LUT_INP_COUNT2                       (5U)

/*! @name LUT_T_LUT_TRUTH - Specifies the Truth Table contents for LUT0..Specifies the Truth Table contents for LUT25 */
/*! @{ */
#define PLU_LUT_T_LUT_TRUTH_TRUTH_TABLE_MASK     (0xFFFFFFFFU)
#define PLU_LUT_T_LUT_TRUTH_TRUTH_TABLE_SHIFT    (0U)
#define PLU_LUT_T_LUT_TRUTH_TRUTH_TABLE(x)       (((uint32_t)(((uint32_t)(x)) << PLU_LUT_T_LUT_TRUTH_TRUTH_TABLE_SHIFT)) & PLU_LUT_T_LUT_TRUTH_TRUTH_TABLE_MASK)
/*! @} */

/* The count of PLU_LUT_T_LUT_TRUTH */
#define PLU_LUT_T_LUT_TRUTH_COUNT                (26U)

/*! @name OUTPUTS - Provides the current state of the 8 designated PLU Outputs. */
/*! @{ */
#define PLU_OUTPUTS_OUTPUT_STATE_MASK            (0xFFU)
#define PLU_OUTPUTS_OUTPUT_STATE_SHIFT           (0U)
#define PLU_OUTPUTS_OUTPUT_STATE(x)              (((uint32_t)(((uint32_t)(x)) << PLU_OUTPUTS_OUTPUT_STATE_SHIFT)) & PLU_OUTPUTS_OUTPUT_STATE_MASK)
/*! @} */

/*! @name OUTPUT_MUX - Selects the source to be connected to PLU Output 0..Selects the source to be connected to PLU Output 7 */
/*! @{ */
#define PLU_OUTPUT_MUX_OUTPUTn_MASK              (0x1FU)
#define PLU_OUTPUT_MUX_OUTPUTn_SHIFT             (0U)
#define PLU_OUTPUT_MUX_OUTPUTn(x)                (((uint32_t)(((uint32_t)(x)) << PLU_OUTPUT_MUX_OUTPUTn_SHIFT)) & PLU_OUTPUT_MUX_OUTPUTn_MASK)
/*! @} */

/* The count of PLU_OUTPUT_MUX */
#define PLU_OUTPUT_MUX_COUNT                     (8U)


/*!
 * @}
 */ /* end of group PLU_Register_Masks */


/* PLU - Peripheral instance base addresses */
/** Peripheral PLU base address */
#define PLU_BASE                                 (0x40028000u)
/** Peripheral PLU base pointer */
#define PLU                                      ((PLU_Type *)PLU_BASE)
/** Array initializer of PLU peripheral base addresses */
#define PLU_BASE_ADDRS                           { PLU_BASE }
/** Array initializer of PLU peripheral base pointers */
#define PLU_BASE_PTRS                            { PLU }

/*!
 * @}
 */ /* end of group PLU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCON;                              /**< Power control register, offset: 0x0 */
  __IO uint32_t GPREG[5];                          /**< General purpose register N, array offset: 0x4, array step: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t WUSRCREG;                          /**< Pin wake-up source register, offset: 0x20 */
  __IO uint32_t WUENAREG;                          /**< Pin wake-up enable register, offset: 0x24 */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name PCON - Power control register */
/*! @{ */
#define PMU_PCON_PM_MASK                         (0x7U)
#define PMU_PCON_PM_SHIFT                        (0U)
#define PMU_PCON_PM(x)                           (((uint32_t)(((uint32_t)(x)) << PMU_PCON_PM_SHIFT)) & PMU_PCON_PM_MASK)
#define PMU_PCON_NODPD_MASK                      (0x8U)
#define PMU_PCON_NODPD_SHIFT                     (3U)
#define PMU_PCON_NODPD(x)                        (((uint32_t)(((uint32_t)(x)) << PMU_PCON_NODPD_SHIFT)) & PMU_PCON_NODPD_MASK)
#define PMU_PCON_SLEEPFLAG_MASK                  (0x100U)
#define PMU_PCON_SLEEPFLAG_SHIFT                 (8U)
#define PMU_PCON_SLEEPFLAG(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_PCON_SLEEPFLAG_SHIFT)) & PMU_PCON_SLEEPFLAG_MASK)
#define PMU_PCON_DPDFLAG_MASK                    (0x800U)
#define PMU_PCON_DPDFLAG_SHIFT                   (11U)
#define PMU_PCON_DPDFLAG(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PCON_DPDFLAG_SHIFT)) & PMU_PCON_DPDFLAG_MASK)
/*! @} */

/*! @name GPREG - General purpose register N */
/*! @{ */
#define PMU_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)
#define PMU_GPREG_GPDATA_SHIFT                   (0U)
#define PMU_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_GPREG_GPDATA_SHIFT)) & PMU_GPREG_GPDATA_MASK)
/*! @} */

/* The count of PMU_GPREG */
#define PMU_GPREG_COUNT                          (5U)

/*! @name WUSRCREG - Pin wake-up source register */
/*! @{ */
#define PMU_WUSRCREG_WUSRCREG_MASK               (0xFFU)
#define PMU_WUSRCREG_WUSRCREG_SHIFT              (0U)
#define PMU_WUSRCREG_WUSRCREG(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_WUSRCREG_WUSRCREG_SHIFT)) & PMU_WUSRCREG_WUSRCREG_MASK)
/*! @} */

/*! @name WUENAREG - Pin wake-up enable register */
/*! @{ */
#define PMU_WUENAREG_WUENAREG_MASK               (0xFFU)
#define PMU_WUENAREG_WUENAREG_SHIFT              (0U)
#define PMU_WUENAREG_WUENAREG(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_WUENAREG_WUENAREG_SHIFT)) & PMU_WUENAREG_WUENAREG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMU_Register_Masks */


/* PMU - Peripheral instance base addresses */
/** Peripheral PMU base address */
#define PMU_BASE                                 (0x40020000u)
/** Peripheral PMU base pointer */
#define PMU                                      ((PMU_Type *)PMU_BASE)
/** Array initializer of PMU peripheral base addresses */
#define PMU_BASE_ADDRS                           { PMU_BASE }
/** Array initializer of PMU peripheral base pointers */
#define PMU_BASE_PTRS                            { PMU }

/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG;                               /**< SPI Configuration register, offset: 0x0 */
  __IO uint32_t DLY;                               /**< SPI Delay register, offset: 0x4 */
  __IO uint32_t STAT;                              /**< SPI Status. Some status flags can be cleared by writing a 1 to that bit position, offset: 0x8 */
  __IO uint32_t INTENSET;                          /**< SPI Interrupt Enable read and Set. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., offset: 0xC */
  __O  uint32_t INTENCLR;                          /**< SPI Interrupt Enable Clear. Writing a 1 to any implemented bit position causes the corresponding bit in INTENSET to be cleared., offset: 0x10 */
  __I  uint32_t RXDAT;                             /**< SPI Receive Data, offset: 0x14 */
  __IO uint32_t TXDATCTL;                          /**< SPI Transmit Data with Control, offset: 0x18 */
  __IO uint32_t TXDAT;                             /**< SPI Transmit Data., offset: 0x1C */
  __IO uint32_t TXCTL;                             /**< SPI Transmit Control, offset: 0x20 */
  __IO uint32_t DIV;                               /**< SPI clock Divider, offset: 0x24 */
  __I  uint32_t INTSTAT;                           /**< SPI Interrupt Status, offset: 0x28 */
} SPI_Type;

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/*! @name CFG - SPI Configuration register */
/*! @{ */
#define SPI_CFG_ENABLE_MASK                      (0x1U)
#define SPI_CFG_ENABLE_SHIFT                     (0U)
#define SPI_CFG_ENABLE(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CFG_ENABLE_SHIFT)) & SPI_CFG_ENABLE_MASK)
#define SPI_CFG_MASTER_MASK                      (0x4U)
#define SPI_CFG_MASTER_SHIFT                     (2U)
#define SPI_CFG_MASTER(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CFG_MASTER_SHIFT)) & SPI_CFG_MASTER_MASK)
#define SPI_CFG_LSBF_MASK                        (0x8U)
#define SPI_CFG_LSBF_SHIFT                       (3U)
#define SPI_CFG_LSBF(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CFG_LSBF_SHIFT)) & SPI_CFG_LSBF_MASK)
#define SPI_CFG_CPHA_MASK                        (0x10U)
#define SPI_CFG_CPHA_SHIFT                       (4U)
#define SPI_CFG_CPHA(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CFG_CPHA_SHIFT)) & SPI_CFG_CPHA_MASK)
#define SPI_CFG_CPOL_MASK                        (0x20U)
#define SPI_CFG_CPOL_SHIFT                       (5U)
#define SPI_CFG_CPOL(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CFG_CPOL_SHIFT)) & SPI_CFG_CPOL_MASK)
#define SPI_CFG_LOOP_MASK                        (0x80U)
#define SPI_CFG_LOOP_SHIFT                       (7U)
#define SPI_CFG_LOOP(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CFG_LOOP_SHIFT)) & SPI_CFG_LOOP_MASK)
#define SPI_CFG_SPOL0_MASK                       (0x100U)
#define SPI_CFG_SPOL0_SHIFT                      (8U)
#define SPI_CFG_SPOL0(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CFG_SPOL0_SHIFT)) & SPI_CFG_SPOL0_MASK)
#define SPI_CFG_SPOL1_MASK                       (0x200U)
#define SPI_CFG_SPOL1_SHIFT                      (9U)
#define SPI_CFG_SPOL1(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CFG_SPOL1_SHIFT)) & SPI_CFG_SPOL1_MASK)
/*! @} */

/*! @name DLY - SPI Delay register */
/*! @{ */
#define SPI_DLY_PRE_DELAY_MASK                   (0xFU)
#define SPI_DLY_PRE_DELAY_SHIFT                  (0U)
#define SPI_DLY_PRE_DELAY(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_DLY_PRE_DELAY_SHIFT)) & SPI_DLY_PRE_DELAY_MASK)
#define SPI_DLY_POST_DELAY_MASK                  (0xF0U)
#define SPI_DLY_POST_DELAY_SHIFT                 (4U)
#define SPI_DLY_POST_DELAY(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_DLY_POST_DELAY_SHIFT)) & SPI_DLY_POST_DELAY_MASK)
#define SPI_DLY_FRAME_DELAY_MASK                 (0xF00U)
#define SPI_DLY_FRAME_DELAY_SHIFT                (8U)
#define SPI_DLY_FRAME_DELAY(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_DLY_FRAME_DELAY_SHIFT)) & SPI_DLY_FRAME_DELAY_MASK)
#define SPI_DLY_TRANSFER_DELAY_MASK              (0xF000U)
#define SPI_DLY_TRANSFER_DELAY_SHIFT             (12U)
#define SPI_DLY_TRANSFER_DELAY(x)                (((uint32_t)(((uint32_t)(x)) << SPI_DLY_TRANSFER_DELAY_SHIFT)) & SPI_DLY_TRANSFER_DELAY_MASK)
/*! @} */

/*! @name STAT - SPI Status. Some status flags can be cleared by writing a 1 to that bit position */
/*! @{ */
#define SPI_STAT_RXRDY_MASK                      (0x1U)
#define SPI_STAT_RXRDY_SHIFT                     (0U)
#define SPI_STAT_RXRDY(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_STAT_RXRDY_SHIFT)) & SPI_STAT_RXRDY_MASK)
#define SPI_STAT_TXRDY_MASK                      (0x2U)
#define SPI_STAT_TXRDY_SHIFT                     (1U)
#define SPI_STAT_TXRDY(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_STAT_TXRDY_SHIFT)) & SPI_STAT_TXRDY_MASK)
#define SPI_STAT_RXOV_MASK                       (0x4U)
#define SPI_STAT_RXOV_SHIFT                      (2U)
#define SPI_STAT_RXOV(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_STAT_RXOV_SHIFT)) & SPI_STAT_RXOV_MASK)
#define SPI_STAT_TXUR_MASK                       (0x8U)
#define SPI_STAT_TXUR_SHIFT                      (3U)
#define SPI_STAT_TXUR(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_STAT_TXUR_SHIFT)) & SPI_STAT_TXUR_MASK)
#define SPI_STAT_SSA_MASK                        (0x10U)
#define SPI_STAT_SSA_SHIFT                       (4U)
#define SPI_STAT_SSA(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_STAT_SSA_SHIFT)) & SPI_STAT_SSA_MASK)
#define SPI_STAT_SSD_MASK                        (0x20U)
#define SPI_STAT_SSD_SHIFT                       (5U)
#define SPI_STAT_SSD(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_STAT_SSD_SHIFT)) & SPI_STAT_SSD_MASK)
#define SPI_STAT_STALLED_MASK                    (0x40U)
#define SPI_STAT_STALLED_SHIFT                   (6U)
#define SPI_STAT_STALLED(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_STAT_STALLED_SHIFT)) & SPI_STAT_STALLED_MASK)
#define SPI_STAT_ENDTRANSFER_MASK                (0x80U)
#define SPI_STAT_ENDTRANSFER_SHIFT               (7U)
#define SPI_STAT_ENDTRANSFER(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_STAT_ENDTRANSFER_SHIFT)) & SPI_STAT_ENDTRANSFER_MASK)
#define SPI_STAT_MSTIDLE_MASK                    (0x100U)
#define SPI_STAT_MSTIDLE_SHIFT                   (8U)
#define SPI_STAT_MSTIDLE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_STAT_MSTIDLE_SHIFT)) & SPI_STAT_MSTIDLE_MASK)
/*! @} */

/*! @name INTENSET - SPI Interrupt Enable read and Set. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set. */
/*! @{ */
#define SPI_INTENSET_RXRDYEN_MASK                (0x1U)
#define SPI_INTENSET_RXRDYEN_SHIFT               (0U)
#define SPI_INTENSET_RXRDYEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_RXRDYEN_SHIFT)) & SPI_INTENSET_RXRDYEN_MASK)
#define SPI_INTENSET_TXRDYEN_MASK                (0x2U)
#define SPI_INTENSET_TXRDYEN_SHIFT               (1U)
#define SPI_INTENSET_TXRDYEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_TXRDYEN_SHIFT)) & SPI_INTENSET_TXRDYEN_MASK)
#define SPI_INTENSET_RXOVEN_MASK                 (0x4U)
#define SPI_INTENSET_RXOVEN_SHIFT                (2U)
#define SPI_INTENSET_RXOVEN(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_RXOVEN_SHIFT)) & SPI_INTENSET_RXOVEN_MASK)
#define SPI_INTENSET_TXUREN_MASK                 (0x8U)
#define SPI_INTENSET_TXUREN_SHIFT                (3U)
#define SPI_INTENSET_TXUREN(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_TXUREN_SHIFT)) & SPI_INTENSET_TXUREN_MASK)
#define SPI_INTENSET_SSAEN_MASK                  (0x10U)
#define SPI_INTENSET_SSAEN_SHIFT                 (4U)
#define SPI_INTENSET_SSAEN(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_SSAEN_SHIFT)) & SPI_INTENSET_SSAEN_MASK)
#define SPI_INTENSET_SSDEN_MASK                  (0x20U)
#define SPI_INTENSET_SSDEN_SHIFT                 (5U)
#define SPI_INTENSET_SSDEN(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_SSDEN_SHIFT)) & SPI_INTENSET_SSDEN_MASK)
#define SPI_INTENSET_MSTIDLEEN_MASK              (0x100U)
#define SPI_INTENSET_MSTIDLEEN_SHIFT             (8U)
#define SPI_INTENSET_MSTIDLEEN(x)                (((uint32_t)(((uint32_t)(x)) << SPI_INTENSET_MSTIDLEEN_SHIFT)) & SPI_INTENSET_MSTIDLEEN_MASK)
/*! @} */

/*! @name INTENCLR - SPI Interrupt Enable Clear. Writing a 1 to any implemented bit position causes the corresponding bit in INTENSET to be cleared. */
/*! @{ */
#define SPI_INTENCLR_RXRDYEN_MASK                (0x1U)
#define SPI_INTENCLR_RXRDYEN_SHIFT               (0U)
#define SPI_INTENCLR_RXRDYEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_RXRDYEN_SHIFT)) & SPI_INTENCLR_RXRDYEN_MASK)
#define SPI_INTENCLR_TXRDYEN_MASK                (0x2U)
#define SPI_INTENCLR_TXRDYEN_SHIFT               (1U)
#define SPI_INTENCLR_TXRDYEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_TXRDYEN_SHIFT)) & SPI_INTENCLR_TXRDYEN_MASK)
#define SPI_INTENCLR_RXOVEN_MASK                 (0x4U)
#define SPI_INTENCLR_RXOVEN_SHIFT                (2U)
#define SPI_INTENCLR_RXOVEN(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_RXOVEN_SHIFT)) & SPI_INTENCLR_RXOVEN_MASK)
#define SPI_INTENCLR_TXUREN_MASK                 (0x8U)
#define SPI_INTENCLR_TXUREN_SHIFT                (3U)
#define SPI_INTENCLR_TXUREN(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_TXUREN_SHIFT)) & SPI_INTENCLR_TXUREN_MASK)
#define SPI_INTENCLR_SSAEN_MASK                  (0x10U)
#define SPI_INTENCLR_SSAEN_SHIFT                 (4U)
#define SPI_INTENCLR_SSAEN(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_SSAEN_SHIFT)) & SPI_INTENCLR_SSAEN_MASK)
#define SPI_INTENCLR_SSDEN_MASK                  (0x20U)
#define SPI_INTENCLR_SSDEN_SHIFT                 (5U)
#define SPI_INTENCLR_SSDEN(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_SSDEN_SHIFT)) & SPI_INTENCLR_SSDEN_MASK)
#define SPI_INTENCLR_MSTIDLE_MASK                (0x100U)
#define SPI_INTENCLR_MSTIDLE_SHIFT               (8U)
#define SPI_INTENCLR_MSTIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_INTENCLR_MSTIDLE_SHIFT)) & SPI_INTENCLR_MSTIDLE_MASK)
/*! @} */

/*! @name RXDAT - SPI Receive Data */
/*! @{ */
#define SPI_RXDAT_RXDAT_MASK                     (0xFFFFU)
#define SPI_RXDAT_RXDAT_SHIFT                    (0U)
#define SPI_RXDAT_RXDAT(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_RXDAT_RXDAT_SHIFT)) & SPI_RXDAT_RXDAT_MASK)
#define SPI_RXDAT_RXSSEL0_N_MASK                 (0x10000U)
#define SPI_RXDAT_RXSSEL0_N_SHIFT                (16U)
#define SPI_RXDAT_RXSSEL0_N(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_RXDAT_RXSSEL0_N_SHIFT)) & SPI_RXDAT_RXSSEL0_N_MASK)
#define SPI_RXDAT_RXSSEL1_N_MASK                 (0x20000U)
#define SPI_RXDAT_RXSSEL1_N_SHIFT                (17U)
#define SPI_RXDAT_RXSSEL1_N(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_RXDAT_RXSSEL1_N_SHIFT)) & SPI_RXDAT_RXSSEL1_N_MASK)
#define SPI_RXDAT_RXSSEL2_N_MASK                 (0x40000U)
#define SPI_RXDAT_RXSSEL2_N_SHIFT                (18U)
#define SPI_RXDAT_RXSSEL2_N(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_RXDAT_RXSSEL2_N_SHIFT)) & SPI_RXDAT_RXSSEL2_N_MASK)
#define SPI_RXDAT_RXSSEL3_N_MASK                 (0x80000U)
#define SPI_RXDAT_RXSSEL3_N_SHIFT                (19U)
#define SPI_RXDAT_RXSSEL3_N(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_RXDAT_RXSSEL3_N_SHIFT)) & SPI_RXDAT_RXSSEL3_N_MASK)
#define SPI_RXDAT_SOT_MASK                       (0x100000U)
#define SPI_RXDAT_SOT_SHIFT                      (20U)
#define SPI_RXDAT_SOT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_RXDAT_SOT_SHIFT)) & SPI_RXDAT_SOT_MASK)
/*! @} */

/*! @name TXDATCTL - SPI Transmit Data with Control */
/*! @{ */
#define SPI_TXDATCTL_TXDAT_MASK                  (0xFFFFU)
#define SPI_TXDATCTL_TXDAT_SHIFT                 (0U)
#define SPI_TXDATCTL_TXDAT(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_TXDAT_SHIFT)) & SPI_TXDATCTL_TXDAT_MASK)
#define SPI_TXDATCTL_TXSSEL0_N_MASK              (0x10000U)
#define SPI_TXDATCTL_TXSSEL0_N_SHIFT             (16U)
#define SPI_TXDATCTL_TXSSEL0_N(x)                (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_TXSSEL0_N_SHIFT)) & SPI_TXDATCTL_TXSSEL0_N_MASK)
#define SPI_TXDATCTL_TXSSEL1_N_MASK              (0x20000U)
#define SPI_TXDATCTL_TXSSEL1_N_SHIFT             (17U)
#define SPI_TXDATCTL_TXSSEL1_N(x)                (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_TXSSEL1_N_SHIFT)) & SPI_TXDATCTL_TXSSEL1_N_MASK)
#define SPI_TXDATCTL_EOT_MASK                    (0x100000U)
#define SPI_TXDATCTL_EOT_SHIFT                   (20U)
#define SPI_TXDATCTL_EOT(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_EOT_SHIFT)) & SPI_TXDATCTL_EOT_MASK)
#define SPI_TXDATCTL_EOF_MASK                    (0x200000U)
#define SPI_TXDATCTL_EOF_SHIFT                   (21U)
#define SPI_TXDATCTL_EOF(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_EOF_SHIFT)) & SPI_TXDATCTL_EOF_MASK)
#define SPI_TXDATCTL_RXIGNORE_MASK               (0x400000U)
#define SPI_TXDATCTL_RXIGNORE_SHIFT              (22U)
#define SPI_TXDATCTL_RXIGNORE(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_RXIGNORE_SHIFT)) & SPI_TXDATCTL_RXIGNORE_MASK)
#define SPI_TXDATCTL_LEN_MASK                    (0xF000000U)
#define SPI_TXDATCTL_LEN_SHIFT                   (24U)
#define SPI_TXDATCTL_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXDATCTL_LEN_SHIFT)) & SPI_TXDATCTL_LEN_MASK)
/*! @} */

/*! @name TXDAT - SPI Transmit Data. */
/*! @{ */
#define SPI_TXDAT_DATA_MASK                      (0xFFFFU)
#define SPI_TXDAT_DATA_SHIFT                     (0U)
#define SPI_TXDAT_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_TXDAT_DATA_SHIFT)) & SPI_TXDAT_DATA_MASK)
/*! @} */

/*! @name TXCTL - SPI Transmit Control */
/*! @{ */
#define SPI_TXCTL_TXSSEL0_N_MASK                 (0x10000U)
#define SPI_TXCTL_TXSSEL0_N_SHIFT                (16U)
#define SPI_TXCTL_TXSSEL0_N(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_TXCTL_TXSSEL0_N_SHIFT)) & SPI_TXCTL_TXSSEL0_N_MASK)
#define SPI_TXCTL_TXSSEL1_N_MASK                 (0x20000U)
#define SPI_TXCTL_TXSSEL1_N_SHIFT                (17U)
#define SPI_TXCTL_TXSSEL1_N(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_TXCTL_TXSSEL1_N_SHIFT)) & SPI_TXCTL_TXSSEL1_N_MASK)
#define SPI_TXCTL_EOT_MASK                       (0x100000U)
#define SPI_TXCTL_EOT_SHIFT                      (20U)
#define SPI_TXCTL_EOT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_TXCTL_EOT_SHIFT)) & SPI_TXCTL_EOT_MASK)
#define SPI_TXCTL_EOF_MASK                       (0x200000U)
#define SPI_TXCTL_EOF_SHIFT                      (21U)
#define SPI_TXCTL_EOF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_TXCTL_EOF_SHIFT)) & SPI_TXCTL_EOF_MASK)
#define SPI_TXCTL_RXIGNORE_MASK                  (0x400000U)
#define SPI_TXCTL_RXIGNORE_SHIFT                 (22U)
#define SPI_TXCTL_RXIGNORE(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TXCTL_RXIGNORE_SHIFT)) & SPI_TXCTL_RXIGNORE_MASK)
#define SPI_TXCTL_LEN_MASK                       (0xF000000U)
#define SPI_TXCTL_LEN_SHIFT                      (24U)
#define SPI_TXCTL_LEN(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_TXCTL_LEN_SHIFT)) & SPI_TXCTL_LEN_MASK)
/*! @} */

/*! @name DIV - SPI clock Divider */
/*! @{ */
#define SPI_DIV_DIVVAL_MASK                      (0xFFFFU)
#define SPI_DIV_DIVVAL_SHIFT                     (0U)
#define SPI_DIV_DIVVAL(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_DIV_DIVVAL_SHIFT)) & SPI_DIV_DIVVAL_MASK)
/*! @} */

/*! @name INTSTAT - SPI Interrupt Status */
/*! @{ */
#define SPI_INTSTAT_RXRDY_MASK                   (0x1U)
#define SPI_INTSTAT_RXRDY_SHIFT                  (0U)
#define SPI_INTSTAT_RXRDY(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_RXRDY_SHIFT)) & SPI_INTSTAT_RXRDY_MASK)
#define SPI_INTSTAT_TXRDY_MASK                   (0x2U)
#define SPI_INTSTAT_TXRDY_SHIFT                  (1U)
#define SPI_INTSTAT_TXRDY(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_TXRDY_SHIFT)) & SPI_INTSTAT_TXRDY_MASK)
#define SPI_INTSTAT_RXOV_MASK                    (0x4U)
#define SPI_INTSTAT_RXOV_SHIFT                   (2U)
#define SPI_INTSTAT_RXOV(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_RXOV_SHIFT)) & SPI_INTSTAT_RXOV_MASK)
#define SPI_INTSTAT_TXUR_MASK                    (0x8U)
#define SPI_INTSTAT_TXUR_SHIFT                   (3U)
#define SPI_INTSTAT_TXUR(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_TXUR_SHIFT)) & SPI_INTSTAT_TXUR_MASK)
#define SPI_INTSTAT_SSA_MASK                     (0x10U)
#define SPI_INTSTAT_SSA_SHIFT                    (4U)
#define SPI_INTSTAT_SSA(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_SSA_SHIFT)) & SPI_INTSTAT_SSA_MASK)
#define SPI_INTSTAT_SSD_MASK                     (0x20U)
#define SPI_INTSTAT_SSD_SHIFT                    (5U)
#define SPI_INTSTAT_SSD(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_SSD_SHIFT)) & SPI_INTSTAT_SSD_MASK)
#define SPI_INTSTAT_MSTIDLE_MASK                 (0x100U)
#define SPI_INTSTAT_MSTIDLE_SHIFT                (8U)
#define SPI_INTSTAT_MSTIDLE(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_INTSTAT_MSTIDLE_SHIFT)) & SPI_INTSTAT_MSTIDLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40058000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI0_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI0 }
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { SPI0_IRQn }

/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWM_Peripheral_Access_Layer SWM Peripheral Access Layer
 * @{
 */

/** SWM - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint32_t PINASSIGN0;                        /**< Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS., offset: 0x0 */
      __IO uint32_t PINASSIGN1;                        /**< Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_SCLK., offset: 0x4 */
      __IO uint32_t PINASSIGN2;                        /**< Pin assign register 2. Assign movable functions SPI0_SCK, SPI0_MOSI,SPI0_MISO,SPI0_SSEL0., offset: 0x8 */
      __IO uint32_t PINASSIGN3;                        /**< Pin assign register 3. Assign movable function SPI0_SSEL1, T0_CAP0, T0_CAP1, T0_CAP2., offset: 0xC */
      __IO uint32_t PINASSIGN4;                        /**< Pin assign register 4. Assign movable functions T0_MAT0, T0_MAT1,T0_MAT2,T0_MAT3., offset: 0x10 */
      __IO uint32_t PINASSIGN5;                        /**< Pin assign register 5. Assign movable functions I2C0_SDA, I2C0_SCL, COMP0_OUT, CLKOUT, offset: 0x14 */
      __IO uint32_t PINASSIGN6;                        /**< Pin assign register 6. Assign movable functions GPIO_INT_BMAT, LVLSHFT_IN0, LVLSHFT_IN1, LVLSHFT_OUT0., offset: 0x18 */
      __IO uint32_t PINASSIGN7;                        /**< Pin assign register 7. Assign movable functions LVLSHFT_OUT1, I2C1_SDA, I2C1_SCL, PLU_CLKIN., offset: 0x1C */
      __IO uint32_t PINASSIGN8;                        /**< Pin assign register 8. Assign movable functions CAPT_X0, CAPT_X1, CAPT_X2, CAPT_X3., offset: 0x20 */
      __IO uint32_t PINASSIGN9;                        /**< Pin assign register 9. Assign movable functions CAPT_X4, CAPT_YL, CAPT_YH., offset: 0x24 */
    } ;
    __IO uint32_t PINASSIGN_DATA[10];                /**< Pin assign register, array offset: 0x0, array step: 0x4 */
  };
       uint8_t RESERVED_0[344];
  __IO uint32_t PINASSIGNFIXED0;                   /**< Pin assign to fixed bits register 0. Pin assign to fixed bits register 0. Assign movable functions PLU_INPUT0 to PLU_INPUT5 and PLU_OUT0 to PLU_INPUT7., offset: 0x180 */
       uint8_t RESERVED_1[60];
  __IO uint32_t PINENABLE0;                        /**< Pin enable register 0. Enables fixed-pin functions ACMP_I1, ACMP_I2, ACMP_I3,ACMP_I4, SWCLK, SWDIO, RESETN, CLKIN,WKCLK_IN, VDDCMP, ADC_0 - ADC_11,ACMP_I5,DACOUT0., offset: 0x1C0 */
} SWM_Type;

/* ----------------------------------------------------------------------------
   -- SWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWM_Register_Masks SWM Register Masks
 * @{
 */

/*! @name PINASSIGN0 - Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS. */
/*! @{ */
#define SWM_PINASSIGN0_U0_TXD_O_MASK             (0xFFU)
#define SWM_PINASSIGN0_U0_TXD_O_SHIFT            (0U)
#define SWM_PINASSIGN0_U0_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_TXD_O_SHIFT)) & SWM_PINASSIGN0_U0_TXD_O_MASK)
#define SWM_PINASSIGN0_U0_RXD_I_MASK             (0xFF00U)
#define SWM_PINASSIGN0_U0_RXD_I_SHIFT            (8U)
#define SWM_PINASSIGN0_U0_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RXD_I_SHIFT)) & SWM_PINASSIGN0_U0_RXD_I_MASK)
#define SWM_PINASSIGN0_U0_RTS_O_MASK             (0xFF0000U)
#define SWM_PINASSIGN0_U0_RTS_O_SHIFT            (16U)
#define SWM_PINASSIGN0_U0_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RTS_O_SHIFT)) & SWM_PINASSIGN0_U0_RTS_O_MASK)
#define SWM_PINASSIGN0_U0_CTS_I_MASK             (0xFF000000U)
#define SWM_PINASSIGN0_U0_CTS_I_SHIFT            (24U)
#define SWM_PINASSIGN0_U0_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_CTS_I_SHIFT)) & SWM_PINASSIGN0_U0_CTS_I_MASK)
/*! @} */

/*! @name PINASSIGN1 - Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_SCLK. */
/*! @{ */
#define SWM_PINASSIGN1_U0_SCLK_IO_MASK           (0xFFU)
#define SWM_PINASSIGN1_U0_SCLK_IO_SHIFT          (0U)
#define SWM_PINASSIGN1_U0_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U0_SCLK_IO_SHIFT)) & SWM_PINASSIGN1_U0_SCLK_IO_MASK)
#define SWM_PINASSIGN1_U1_TXD_O_MASK             (0xFF00U)
#define SWM_PINASSIGN1_U1_TXD_O_SHIFT            (8U)
#define SWM_PINASSIGN1_U1_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_TXD_O_SHIFT)) & SWM_PINASSIGN1_U1_TXD_O_MASK)
#define SWM_PINASSIGN1_U1_RXD_I_MASK             (0xFF0000U)
#define SWM_PINASSIGN1_U1_RXD_I_SHIFT            (16U)
#define SWM_PINASSIGN1_U1_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_RXD_I_SHIFT)) & SWM_PINASSIGN1_U1_RXD_I_MASK)
#define SWM_PINASSIGN1_U1_SCLK_IO_MASK           (0xFF000000U)
#define SWM_PINASSIGN1_U1_SCLK_IO_SHIFT          (24U)
#define SWM_PINASSIGN1_U1_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_SCLK_IO_SHIFT)) & SWM_PINASSIGN1_U1_SCLK_IO_MASK)
/*! @} */

/*! @name PINASSIGN2 - Pin assign register 2. Assign movable functions SPI0_SCK, SPI0_MOSI,SPI0_MISO,SPI0_SSEL0. */
/*! @{ */
#define SWM_PINASSIGN2_SPI0_SCK_IO_MASK          (0xFFU)
#define SWM_PINASSIGN2_SPI0_SCK_IO_SHIFT         (0U)
#define SWM_PINASSIGN2_SPI0_SCK_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_SCK_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_SCK_IO_MASK)
#define SWM_PINASSIGN2_SPI0_MOSI_IO_MASK         (0xFF00U)
#define SWM_PINASSIGN2_SPI0_MOSI_IO_SHIFT        (8U)
#define SWM_PINASSIGN2_SPI0_MOSI_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_MOSI_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_MOSI_IO_MASK)
#define SWM_PINASSIGN2_SPI0_MISO_IO_MASK         (0xFF0000U)
#define SWM_PINASSIGN2_SPI0_MISO_IO_SHIFT        (16U)
#define SWM_PINASSIGN2_SPI0_MISO_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_MISO_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_MISO_IO_MASK)
#define SWM_PINASSIGN2_SPI0_SSEL0_IO_MASK        (0xFF000000U)
#define SWM_PINASSIGN2_SPI0_SSEL0_IO_SHIFT       (24U)
#define SWM_PINASSIGN2_SPI0_SSEL0_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_SSEL0_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_SSEL0_IO_MASK)
/*! @} */

/*! @name PINASSIGN3 - Pin assign register 3. Assign movable function SPI0_SSEL1, T0_CAP0, T0_CAP1, T0_CAP2. */
/*! @{ */
#define SWM_PINASSIGN3_SPI0_SSEL1_IO_MASK        (0xFFU)
#define SWM_PINASSIGN3_SPI0_SSEL1_IO_SHIFT       (0U)
#define SWM_PINASSIGN3_SPI0_SSEL1_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_SPI0_SSEL1_IO_SHIFT)) & SWM_PINASSIGN3_SPI0_SSEL1_IO_MASK)
#define SWM_PINASSIGN3_T0_CAP0_MASK              (0xFF00U)
#define SWM_PINASSIGN3_T0_CAP0_SHIFT             (8U)
#define SWM_PINASSIGN3_T0_CAP0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_T0_CAP0_SHIFT)) & SWM_PINASSIGN3_T0_CAP0_MASK)
#define SWM_PINASSIGN3_T0_CAP1_MASK              (0xFF0000U)
#define SWM_PINASSIGN3_T0_CAP1_SHIFT             (16U)
#define SWM_PINASSIGN3_T0_CAP1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_T0_CAP1_SHIFT)) & SWM_PINASSIGN3_T0_CAP1_MASK)
#define SWM_PINASSIGN3_T0_CAP2_MASK              (0xFF000000U)
#define SWM_PINASSIGN3_T0_CAP2_SHIFT             (24U)
#define SWM_PINASSIGN3_T0_CAP2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_T0_CAP2_SHIFT)) & SWM_PINASSIGN3_T0_CAP2_MASK)
/*! @} */

/*! @name PINASSIGN4 - Pin assign register 4. Assign movable functions T0_MAT0, T0_MAT1,T0_MAT2,T0_MAT3. */
/*! @{ */
#define SWM_PINASSIGN4_T0_MAT0_MASK              (0xFFU)
#define SWM_PINASSIGN4_T0_MAT0_SHIFT             (0U)
#define SWM_PINASSIGN4_T0_MAT0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT0_SHIFT)) & SWM_PINASSIGN4_T0_MAT0_MASK)
#define SWM_PINASSIGN4_T0_MAT1_MASK              (0xFF00U)
#define SWM_PINASSIGN4_T0_MAT1_SHIFT             (8U)
#define SWM_PINASSIGN4_T0_MAT1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT1_SHIFT)) & SWM_PINASSIGN4_T0_MAT1_MASK)
#define SWM_PINASSIGN4_T0_MAT2_MASK              (0xFF0000U)
#define SWM_PINASSIGN4_T0_MAT2_SHIFT             (16U)
#define SWM_PINASSIGN4_T0_MAT2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT2_SHIFT)) & SWM_PINASSIGN4_T0_MAT2_MASK)
#define SWM_PINASSIGN4_T0_MAT3_MASK              (0xFF000000U)
#define SWM_PINASSIGN4_T0_MAT3_SHIFT             (24U)
#define SWM_PINASSIGN4_T0_MAT3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT3_SHIFT)) & SWM_PINASSIGN4_T0_MAT3_MASK)
/*! @} */

/*! @name PINASSIGN5 - Pin assign register 5. Assign movable functions I2C0_SDA, I2C0_SCL, COMP0_OUT, CLKOUT */
/*! @{ */
#define SWM_PINASSIGN5_I2C0_SDA_IO_MASK          (0xFFU)
#define SWM_PINASSIGN5_I2C0_SDA_IO_SHIFT         (0U)
#define SWM_PINASSIGN5_I2C0_SDA_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_I2C0_SDA_IO_SHIFT)) & SWM_PINASSIGN5_I2C0_SDA_IO_MASK)
#define SWM_PINASSIGN5_I2C0_SCL_IO_MASK          (0xFF00U)
#define SWM_PINASSIGN5_I2C0_SCL_IO_SHIFT         (8U)
#define SWM_PINASSIGN5_I2C0_SCL_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_I2C0_SCL_IO_SHIFT)) & SWM_PINASSIGN5_I2C0_SCL_IO_MASK)
#define SWM_PINASSIGN5_COMP0_OUT_O_MASK          (0xFF0000U)
#define SWM_PINASSIGN5_COMP0_OUT_O_SHIFT         (16U)
#define SWM_PINASSIGN5_COMP0_OUT_O(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_COMP0_OUT_O_SHIFT)) & SWM_PINASSIGN5_COMP0_OUT_O_MASK)
#define SWM_PINASSIGN5_CLKOUT_O_MASK             (0xFF000000U)
#define SWM_PINASSIGN5_CLKOUT_O_SHIFT            (24U)
#define SWM_PINASSIGN5_CLKOUT_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_CLKOUT_O_SHIFT)) & SWM_PINASSIGN5_CLKOUT_O_MASK)
/*! @} */

/*! @name PINASSIGN6 - Pin assign register 6. Assign movable functions GPIO_INT_BMAT, LVLSHFT_IN0, LVLSHFT_IN1, LVLSHFT_OUT0. */
/*! @{ */
#define SWM_PINASSIGN6_GPIO_INT_BMAT_O_MASK      (0xFFU)
#define SWM_PINASSIGN6_GPIO_INT_BMAT_O_SHIFT     (0U)
#define SWM_PINASSIGN6_GPIO_INT_BMAT_O(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_GPIO_INT_BMAT_O_SHIFT)) & SWM_PINASSIGN6_GPIO_INT_BMAT_O_MASK)
#define SWM_PINASSIGN6_LVLSHFT_IN0_MASK          (0xFF00U)
#define SWM_PINASSIGN6_LVLSHFT_IN0_SHIFT         (8U)
#define SWM_PINASSIGN6_LVLSHFT_IN0(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_LVLSHFT_IN0_SHIFT)) & SWM_PINASSIGN6_LVLSHFT_IN0_MASK)
#define SWM_PINASSIGN6_LVLSHFT_IN1_MASK          (0xFF0000U)
#define SWM_PINASSIGN6_LVLSHFT_IN1_SHIFT         (16U)
#define SWM_PINASSIGN6_LVLSHFT_IN1(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_LVLSHFT_IN1_SHIFT)) & SWM_PINASSIGN6_LVLSHFT_IN1_MASK)
#define SWM_PINASSIGN6_LVLSHFT_OUT0_MASK         (0xFF000000U)
#define SWM_PINASSIGN6_LVLSHFT_OUT0_SHIFT        (24U)
#define SWM_PINASSIGN6_LVLSHFT_OUT0(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_LVLSHFT_OUT0_SHIFT)) & SWM_PINASSIGN6_LVLSHFT_OUT0_MASK)
/*! @} */

/*! @name PINASSIGN7 - Pin assign register 7. Assign movable functions LVLSHFT_OUT1, I2C1_SDA, I2C1_SCL, PLU_CLKIN. */
/*! @{ */
#define SWM_PINASSIGN7_LVLSHFT_OUT1_MASK         (0xFFU)
#define SWM_PINASSIGN7_LVLSHFT_OUT1_SHIFT        (0U)
#define SWM_PINASSIGN7_LVLSHFT_OUT1(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_LVLSHFT_OUT1_SHIFT)) & SWM_PINASSIGN7_LVLSHFT_OUT1_MASK)
#define SWM_PINASSIGN7_I2C1_SDA_IO_MASK          (0xFF00U)
#define SWM_PINASSIGN7_I2C1_SDA_IO_SHIFT         (8U)
#define SWM_PINASSIGN7_I2C1_SDA_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_I2C1_SDA_IO_SHIFT)) & SWM_PINASSIGN7_I2C1_SDA_IO_MASK)
#define SWM_PINASSIGN7_I2C1_SCL_IO_MASK          (0xFF0000U)
#define SWM_PINASSIGN7_I2C1_SCL_IO_SHIFT         (16U)
#define SWM_PINASSIGN7_I2C1_SCL_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_I2C1_SCL_IO_SHIFT)) & SWM_PINASSIGN7_I2C1_SCL_IO_MASK)
#define SWM_PINASSIGN7_PLU_CLKIN_IN_MASK         (0xFF000000U)
#define SWM_PINASSIGN7_PLU_CLKIN_IN_SHIFT        (24U)
#define SWM_PINASSIGN7_PLU_CLKIN_IN(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_PLU_CLKIN_IN_SHIFT)) & SWM_PINASSIGN7_PLU_CLKIN_IN_MASK)
/*! @} */

/*! @name PINASSIGN8 - Pin assign register 8. Assign movable functions CAPT_X0, CAPT_X1, CAPT_X2, CAPT_X3. */
/*! @{ */
#define SWM_PINASSIGN8_CAPT_X0_O_MASK            (0xFFU)
#define SWM_PINASSIGN8_CAPT_X0_O_SHIFT           (0U)
#define SWM_PINASSIGN8_CAPT_X0_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_CAPT_X0_O_SHIFT)) & SWM_PINASSIGN8_CAPT_X0_O_MASK)
#define SWM_PINASSIGN8_CAPT_X1_O_MASK            (0xFF00U)
#define SWM_PINASSIGN8_CAPT_X1_O_SHIFT           (8U)
#define SWM_PINASSIGN8_CAPT_X1_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_CAPT_X1_O_SHIFT)) & SWM_PINASSIGN8_CAPT_X1_O_MASK)
#define SWM_PINASSIGN8_CAPT_X2_O_MASK            (0xFF0000U)
#define SWM_PINASSIGN8_CAPT_X2_O_SHIFT           (16U)
#define SWM_PINASSIGN8_CAPT_X2_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_CAPT_X2_O_SHIFT)) & SWM_PINASSIGN8_CAPT_X2_O_MASK)
#define SWM_PINASSIGN8_CAPT_X3_O_MASK            (0xFF000000U)
#define SWM_PINASSIGN8_CAPT_X3_O_SHIFT           (24U)
#define SWM_PINASSIGN8_CAPT_X3_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_CAPT_X3_O_SHIFT)) & SWM_PINASSIGN8_CAPT_X3_O_MASK)
/*! @} */

/*! @name PINASSIGN9 - Pin assign register 9. Assign movable functions CAPT_X4, CAPT_YL, CAPT_YH. */
/*! @{ */
#define SWM_PINASSIGN9_CAPT_X4_O_MASK            (0xFFU)
#define SWM_PINASSIGN9_CAPT_X4_O_SHIFT           (0U)
#define SWM_PINASSIGN9_CAPT_X4_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_CAPT_X4_O_SHIFT)) & SWM_PINASSIGN9_CAPT_X4_O_MASK)
#define SWM_PINASSIGN9_CAPT_YL_O_MASK            (0xFF00U)
#define SWM_PINASSIGN9_CAPT_YL_O_SHIFT           (8U)
#define SWM_PINASSIGN9_CAPT_YL_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_CAPT_YL_O_SHIFT)) & SWM_PINASSIGN9_CAPT_YL_O_MASK)
#define SWM_PINASSIGN9_CAPT_YH_O_MASK            (0xFF0000U)
#define SWM_PINASSIGN9_CAPT_YH_O_SHIFT           (16U)
#define SWM_PINASSIGN9_CAPT_YH_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_CAPT_YH_O_SHIFT)) & SWM_PINASSIGN9_CAPT_YH_O_MASK)
/*! @} */

/*! @name PINASSIGN_DATA - Pin assign register */
/*! @{ */
#define SWM_PINASSIGN_DATA_T0_MAT3_MASK          (0xFFU)
#define SWM_PINASSIGN_DATA_T0_MAT3_SHIFT         (0U)
#define SWM_PINASSIGN_DATA_T0_MAT3(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_T0_MAT3_SHIFT)) & SWM_PINASSIGN_DATA_T0_MAT3_MASK)
#define SWM_PINASSIGN_DATA_T0_CAP0_MASK          (0xFF00U)
#define SWM_PINASSIGN_DATA_T0_CAP0_SHIFT         (8U)
#define SWM_PINASSIGN_DATA_T0_CAP0(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_T0_CAP0_SHIFT)) & SWM_PINASSIGN_DATA_T0_CAP0_MASK)
#define SWM_PINASSIGN_DATA_T0_CAP1_MASK          (0xFF0000U)
#define SWM_PINASSIGN_DATA_T0_CAP1_SHIFT         (16U)
#define SWM_PINASSIGN_DATA_T0_CAP1(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_T0_CAP1_SHIFT)) & SWM_PINASSIGN_DATA_T0_CAP1_MASK)
#define SWM_PINASSIGN_DATA_T0_CAP2_MASK          (0xFF000000U)
#define SWM_PINASSIGN_DATA_T0_CAP2_SHIFT         (24U)
#define SWM_PINASSIGN_DATA_T0_CAP2(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_T0_CAP2_SHIFT)) & SWM_PINASSIGN_DATA_T0_CAP2_MASK)
/*! @} */

/* The count of SWM_PINASSIGN_DATA */
#define SWM_PINASSIGN_DATA_COUNT                 (10U)

/*! @name PINASSIGNFIXED0 - Pin assign to fixed bits register 0. Pin assign to fixed bits register 0. Assign movable functions PLU_INPUT0 to PLU_INPUT5 and PLU_OUT0 to PLU_INPUT7. */
/*! @{ */
#define SWM_PINASSIGNFIXED0_PLU_INPUT0_MASK      (0x3U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT0_SHIFT     (0U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT0(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_INPUT0_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_INPUT0_MASK)
#define SWM_PINASSIGNFIXED0_PLU_INPUT1_MASK      (0xCU)
#define SWM_PINASSIGNFIXED0_PLU_INPUT1_SHIFT     (2U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT1(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_INPUT1_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_INPUT1_MASK)
#define SWM_PINASSIGNFIXED0_PLU_INPUT2_MASK      (0x30U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT2_SHIFT     (4U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT2(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_INPUT2_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_INPUT2_MASK)
#define SWM_PINASSIGNFIXED0_PLU_INPUT3_MASK      (0xC0U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT3_SHIFT     (6U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT3(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_INPUT3_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_INPUT3_MASK)
#define SWM_PINASSIGNFIXED0_PLU_INPUT4_MASK      (0x300U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT4_SHIFT     (8U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT4(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_INPUT4_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_INPUT4_MASK)
#define SWM_PINASSIGNFIXED0_PLU_INPUT5_MASK      (0xC00U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT5_SHIFT     (10U)
#define SWM_PINASSIGNFIXED0_PLU_INPUT5(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_INPUT5_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_INPUT5_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT0_MASK        (0x3000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT0_SHIFT       (12U)
#define SWM_PINASSIGNFIXED0_PLU_OUT0(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT0_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT0_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT1_MASK        (0xC000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT1_SHIFT       (14U)
#define SWM_PINASSIGNFIXED0_PLU_OUT1(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT1_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT1_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT2_MASK        (0x30000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT2_SHIFT       (16U)
#define SWM_PINASSIGNFIXED0_PLU_OUT2(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT2_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT2_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT3_MASK        (0xC0000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT3_SHIFT       (18U)
#define SWM_PINASSIGNFIXED0_PLU_OUT3(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT3_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT3_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT4_MASK        (0x300000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT4_SHIFT       (20U)
#define SWM_PINASSIGNFIXED0_PLU_OUT4(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT4_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT4_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT5_MASK        (0xC00000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT5_SHIFT       (22U)
#define SWM_PINASSIGNFIXED0_PLU_OUT5(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT5_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT5_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT6_MASK        (0x3000000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT6_SHIFT       (24U)
#define SWM_PINASSIGNFIXED0_PLU_OUT6(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT6_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT6_MASK)
#define SWM_PINASSIGNFIXED0_PLU_OUT7_MASK        (0xC000000U)
#define SWM_PINASSIGNFIXED0_PLU_OUT7_SHIFT       (26U)
#define SWM_PINASSIGNFIXED0_PLU_OUT7(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGNFIXED0_PLU_OUT7_SHIFT)) & SWM_PINASSIGNFIXED0_PLU_OUT7_MASK)
/*! @} */

/*! @name PINENABLE0 - Pin enable register 0. Enables fixed-pin functions ACMP_I1, ACMP_I2, ACMP_I3,ACMP_I4, SWCLK, SWDIO, RESETN, CLKIN,WKCLK_IN, VDDCMP, ADC_0 - ADC_11,ACMP_I5,DACOUT0. */
/*! @{ */
#define SWM_PINENABLE0_ACMP_I1_MASK              (0x1U)
#define SWM_PINENABLE0_ACMP_I1_SHIFT             (0U)
#define SWM_PINENABLE0_ACMP_I1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I1_SHIFT)) & SWM_PINENABLE0_ACMP_I1_MASK)
#define SWM_PINENABLE0_ACMP_I2_MASK              (0x2U)
#define SWM_PINENABLE0_ACMP_I2_SHIFT             (1U)
#define SWM_PINENABLE0_ACMP_I2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I2_SHIFT)) & SWM_PINENABLE0_ACMP_I2_MASK)
#define SWM_PINENABLE0_ACMP_I3_MASK              (0x4U)
#define SWM_PINENABLE0_ACMP_I3_SHIFT             (2U)
#define SWM_PINENABLE0_ACMP_I3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I3_SHIFT)) & SWM_PINENABLE0_ACMP_I3_MASK)
#define SWM_PINENABLE0_ACMP_I4_MASK              (0x8U)
#define SWM_PINENABLE0_ACMP_I4_SHIFT             (3U)
#define SWM_PINENABLE0_ACMP_I4(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I4_SHIFT)) & SWM_PINENABLE0_ACMP_I4_MASK)
#define SWM_PINENABLE0_SWCLK_MASK                (0x10U)
#define SWM_PINENABLE0_SWCLK_SHIFT               (4U)
#define SWM_PINENABLE0_SWCLK(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWCLK_SHIFT)) & SWM_PINENABLE0_SWCLK_MASK)
#define SWM_PINENABLE0_SWDIO_MASK                (0x20U)
#define SWM_PINENABLE0_SWDIO_SHIFT               (5U)
#define SWM_PINENABLE0_SWDIO(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWDIO_SHIFT)) & SWM_PINENABLE0_SWDIO_MASK)
#define SWM_PINENABLE0_RESETN_MASK               (0x40U)
#define SWM_PINENABLE0_RESETN_SHIFT              (6U)
#define SWM_PINENABLE0_RESETN(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_RESETN_SHIFT)) & SWM_PINENABLE0_RESETN_MASK)
#define SWM_PINENABLE0_CLKIN_MASK                (0x80U)
#define SWM_PINENABLE0_CLKIN_SHIFT               (7U)
#define SWM_PINENABLE0_CLKIN(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CLKIN_SHIFT)) & SWM_PINENABLE0_CLKIN_MASK)
#define SWM_PINENABLE0_WKCLKIN_MASK              (0x100U)
#define SWM_PINENABLE0_WKCLKIN_SHIFT             (8U)
#define SWM_PINENABLE0_WKCLKIN(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_WKCLKIN_SHIFT)) & SWM_PINENABLE0_WKCLKIN_MASK)
#define SWM_PINENABLE0_VDDCMP_MASK               (0x200U)
#define SWM_PINENABLE0_VDDCMP_SHIFT              (9U)
#define SWM_PINENABLE0_VDDCMP(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_VDDCMP_SHIFT)) & SWM_PINENABLE0_VDDCMP_MASK)
#define SWM_PINENABLE0_ADC_0_MASK                (0x400U)
#define SWM_PINENABLE0_ADC_0_SHIFT               (10U)
#define SWM_PINENABLE0_ADC_0(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_0_SHIFT)) & SWM_PINENABLE0_ADC_0_MASK)
#define SWM_PINENABLE0_ADC_1_MASK                (0x800U)
#define SWM_PINENABLE0_ADC_1_SHIFT               (11U)
#define SWM_PINENABLE0_ADC_1(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_1_SHIFT)) & SWM_PINENABLE0_ADC_1_MASK)
#define SWM_PINENABLE0_ADC_2_MASK                (0x1000U)
#define SWM_PINENABLE0_ADC_2_SHIFT               (12U)
#define SWM_PINENABLE0_ADC_2(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_2_SHIFT)) & SWM_PINENABLE0_ADC_2_MASK)
#define SWM_PINENABLE0_ADC_3_MASK                (0x2000U)
#define SWM_PINENABLE0_ADC_3_SHIFT               (13U)
#define SWM_PINENABLE0_ADC_3(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_3_SHIFT)) & SWM_PINENABLE0_ADC_3_MASK)
#define SWM_PINENABLE0_ADC_4_MASK                (0x4000U)
#define SWM_PINENABLE0_ADC_4_SHIFT               (14U)
#define SWM_PINENABLE0_ADC_4(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_4_SHIFT)) & SWM_PINENABLE0_ADC_4_MASK)
#define SWM_PINENABLE0_ADC_5_MASK                (0x8000U)
#define SWM_PINENABLE0_ADC_5_SHIFT               (15U)
#define SWM_PINENABLE0_ADC_5(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_5_SHIFT)) & SWM_PINENABLE0_ADC_5_MASK)
#define SWM_PINENABLE0_ADC_6_MASK                (0x10000U)
#define SWM_PINENABLE0_ADC_6_SHIFT               (16U)
#define SWM_PINENABLE0_ADC_6(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_6_SHIFT)) & SWM_PINENABLE0_ADC_6_MASK)
#define SWM_PINENABLE0_ADC_7_MASK                (0x20000U)
#define SWM_PINENABLE0_ADC_7_SHIFT               (17U)
#define SWM_PINENABLE0_ADC_7(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_7_SHIFT)) & SWM_PINENABLE0_ADC_7_MASK)
#define SWM_PINENABLE0_ADC_8_MASK                (0x40000U)
#define SWM_PINENABLE0_ADC_8_SHIFT               (18U)
#define SWM_PINENABLE0_ADC_8(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_8_SHIFT)) & SWM_PINENABLE0_ADC_8_MASK)
#define SWM_PINENABLE0_ADC_9_MASK                (0x80000U)
#define SWM_PINENABLE0_ADC_9_SHIFT               (19U)
#define SWM_PINENABLE0_ADC_9(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_9_SHIFT)) & SWM_PINENABLE0_ADC_9_MASK)
#define SWM_PINENABLE0_ADC_10_MASK               (0x100000U)
#define SWM_PINENABLE0_ADC_10_SHIFT              (20U)
#define SWM_PINENABLE0_ADC_10(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_10_SHIFT)) & SWM_PINENABLE0_ADC_10_MASK)
#define SWM_PINENABLE0_ADC_11_MASK               (0x200000U)
#define SWM_PINENABLE0_ADC_11_SHIFT              (21U)
#define SWM_PINENABLE0_ADC_11(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_11_SHIFT)) & SWM_PINENABLE0_ADC_11_MASK)
#define SWM_PINENABLE0_ACMP_I5_MASK              (0x400000U)
#define SWM_PINENABLE0_ACMP_I5_SHIFT             (22U)
#define SWM_PINENABLE0_ACMP_I5(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I5_SHIFT)) & SWM_PINENABLE0_ACMP_I5_MASK)
#define SWM_PINENABLE0_DACOUT0_MASK              (0x800000U)
#define SWM_PINENABLE0_DACOUT0_SHIFT             (23U)
#define SWM_PINENABLE0_DACOUT0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_DACOUT0_SHIFT)) & SWM_PINENABLE0_DACOUT0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SWM_Register_Masks */


/* SWM - Peripheral instance base addresses */
/** Peripheral SWM0 base address */
#define SWM0_BASE                                (0x4000C000u)
/** Peripheral SWM0 base pointer */
#define SWM0                                     ((SWM_Type *)SWM0_BASE)
/** Array initializer of SWM peripheral base addresses */
#define SWM_BASE_ADDRS                           { SWM0_BASE }
/** Array initializer of SWM peripheral base pointers */
#define SWM_BASE_PTRS                            { SWM0 }

/*!
 * @}
 */ /* end of group SWM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
 * @{
 */

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< System Remap register, offset: 0x0 */
       uint8_t RESERVED_0[52];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register., offset: 0x38 */
       uint8_t RESERVED_1[20];
  __IO uint32_t MAINCLKSEL;                        /**< Main clock source select register, offset: 0x50 */
  __IO uint32_t MAINCLKUEN;                        /**< Main clock source update enable register., offset: 0x54 */
  __IO uint32_t SYSAHBCLKDIV;                      /**< System clock divider register, offset: 0x58 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CAPTCLKSEL;                        /**< Capacitive Touch clock source select., offset: 0x60 */
  __IO uint32_t ADCCLKSEL;                         /**< ADC clock source select register, offset: 0x64 */
  __IO uint32_t ADCCLKDIV;                         /**< ADC clock divider register, offset: 0x68 */
       uint8_t RESERVED_3[16];
  __IO uint32_t LPOSCCLKEN;                        /**< WDT and Wake Timer clock enable control., offset: 0x7C */
  __IO uint32_t SYSAHBCLKCTRL0;                    /**< System clock group 0 control register, offset: 0x80 */
  __IO uint32_t SYSAHBCLKCTRL1;                    /**< System clock group 1 control register, offset: 0x84 */
  __IO uint32_t PRESETCTRL0;                       /**< Peripheral reset group 0 control register, offset: 0x88 */
  __IO uint32_t PRESETCTRL1;                       /**< Peripheral reset group 1 control register, offset: 0x8C */
  __IO uint32_t UART0CLKSEL;                       /**< Function clock source select for UART0., offset: 0x90 */
  __IO uint32_t UART1CLKSEL;                       /**< Function clock source select for UART1., offset: 0x94 */
       uint8_t RESERVED_4[12];
  __IO uint32_t I2C0CLKSEL;                        /**< Function clock source select for I2C0., offset: 0xA4 */
  __IO uint32_t I2C1CLKSEL;                        /**< Function clock source select for I2C1., offset: 0xA8 */
       uint8_t RESERVED_5[8];
  __IO uint32_t SPI0CLKSEL;                        /**< Function clock source select for SPI0., offset: 0xB4 */
       uint8_t RESERVED_6[24];
  struct {                                         /* offset: 0xD0, array step: 0xC */
    __IO uint32_t FRGDIV;                            /**< fractional generator divider value register, array offset: 0xD0, array step: 0xC */
    __IO uint32_t FRGMULT;                           /**< fractional generator multiplier value register, array offset: 0xD4, array step: 0xC */
    __IO uint32_t FRGCLKSEL;                         /**< FRG clock source select register, array offset: 0xD8, array step: 0xC */
  } FRG[1];
       uint8_t RESERVED_7[20];
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT clock source select register, offset: 0xF0 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider registers, offset: 0xF4 */
       uint8_t RESERVED_8[8];
  __IO uint32_t PIOPORACP;                         /**< POR captured PIO0 status 0, offset: 0x100 */
       uint8_t RESERVED_9[76];
  __IO uint32_t BODCTRL;                           /**< BOD control register, offset: 0x150 */
  __IO uint32_t SYSTCKCAL;                         /**< System tick timer calibration register, offset: 0x154 */
       uint8_t RESERVED_10[24];
  __IO uint32_t IRQLATENCY;                        /**< IRQ latency register, offset: 0x170 */
  __IO uint32_t NMISRC;                            /**< NMI source selection register, offset: 0x174 */
  __IO uint32_t PINTSEL[8];                        /**< Pin interrupt select registers N, array offset: 0x178, array step: 0x4 */
       uint8_t RESERVED_11[108];
  __IO uint32_t STARTERP0;                         /**< Start logic 0 pin wake-up enable register 0, offset: 0x204 */
       uint8_t RESERVED_12[12];
  __IO uint32_t STARTERP1;                         /**< Start logic 0 pin wake-up enable register 1, offset: 0x214 */
       uint8_t RESERVED_13[24];
  __IO uint32_t PDSLEEPCFG;                        /**< Deep-sleep configuration register, offset: 0x230 */
  __IO uint32_t PDAWAKECFG;                        /**< Wake-up configuration register, offset: 0x234 */
  __IO uint32_t PDRUNCFG;                          /**< Power configuration register, offset: 0x238 */
       uint8_t RESERVED_14[444];
  __I  uint32_t DEVICE_ID;                         /**< Device ID register, offset: 0x3F8 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name SYSMEMREMAP - System Remap register */
/*! @{ */
#define SYSCON_SYSMEMREMAP_MAP_MASK              (0x3U)
#define SYSCON_SYSMEMREMAP_MAP_SHIFT             (0U)
#define SYSCON_SYSMEMREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSMEMREMAP_MAP_SHIFT)) & SYSCON_SYSMEMREMAP_MAP_MASK)
/*! @} */

/*! @name SYSRSTSTAT - System reset status register. */
/*! @{ */
#define SYSCON_SYSRSTSTAT_POR_BOD_MASK           (0x1U)
#define SYSCON_SYSRSTSTAT_POR_BOD_SHIFT          (0U)
#define SYSCON_SYSRSTSTAT_POR_BOD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_POR_BOD_SHIFT)) & SYSCON_SYSRSTSTAT_POR_BOD_MASK)
#define SYSCON_SYSRSTSTAT_EXTRST_MASK            (0x2U)
#define SYSCON_SYSRSTSTAT_EXTRST_SHIFT           (1U)
#define SYSCON_SYSRSTSTAT_EXTRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_EXTRST_SHIFT)) & SYSCON_SYSRSTSTAT_EXTRST_MASK)
#define SYSCON_SYSRSTSTAT_WDT_MASK               (0x4U)
#define SYSCON_SYSRSTSTAT_WDT_SHIFT              (2U)
#define SYSCON_SYSRSTSTAT_WDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_WDT_SHIFT)) & SYSCON_SYSRSTSTAT_WDT_MASK)
#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x10U)
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (4U)
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_SYSRST_SHIFT)) & SYSCON_SYSRSTSTAT_SYSRST_MASK)
/*! @} */

/*! @name MAINCLKSEL - Main clock source select register */
/*! @{ */
#define SYSCON_MAINCLKSEL_SEL_MASK               (0x3U)
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSEL_SEL_SHIFT)) & SYSCON_MAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKUEN - Main clock source update enable register. */
/*! @{ */
#define SYSCON_MAINCLKUEN_ENA_MASK               (0x1U)
#define SYSCON_MAINCLKUEN_ENA_SHIFT              (0U)
#define SYSCON_MAINCLKUEN_ENA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKUEN_ENA_SHIFT)) & SYSCON_MAINCLKUEN_ENA_MASK)
/*! @} */

/*! @name SYSAHBCLKDIV - System clock divider register */
/*! @{ */
#define SYSCON_SYSAHBCLKDIV_DIV_MASK             (0xFFU)
#define SYSCON_SYSAHBCLKDIV_DIV_SHIFT            (0U)
#define SYSCON_SYSAHBCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKDIV_DIV_SHIFT)) & SYSCON_SYSAHBCLKDIV_DIV_MASK)
/*! @} */

/*! @name CAPTCLKSEL - Capacitive Touch clock source select. */
/*! @{ */
#define SYSCON_CAPTCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_CAPTCLKSEL_SEL_SHIFT              (0U)
#define SYSCON_CAPTCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CAPTCLKSEL_SEL_SHIFT)) & SYSCON_CAPTCLKSEL_SEL_MASK)
/*! @} */

/*! @name ADCCLKSEL - ADC clock source select register */
/*! @{ */
#define SYSCON_ADCCLKSEL_SEL_MASK                (0x3U)
#define SYSCON_ADCCLKSEL_SEL_SHIFT               (0U)
#define SYSCON_ADCCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKSEL_SEL_SHIFT)) & SYSCON_ADCCLKSEL_SEL_MASK)
/*! @} */

/*! @name ADCCLKDIV - ADC clock divider register */
/*! @{ */
#define SYSCON_ADCCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_ADCCLKDIV_DIV_SHIFT               (0U)
#define SYSCON_ADCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_DIV_SHIFT)) & SYSCON_ADCCLKDIV_DIV_MASK)
/*! @} */

/*! @name LPOSCCLKEN - WDT and Wake Timer clock enable control. */
/*! @{ */
#define SYSCON_LPOSCCLKEN_WDT_MASK               (0x1U)
#define SYSCON_LPOSCCLKEN_WDT_SHIFT              (0U)
#define SYSCON_LPOSCCLKEN_WDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_LPOSCCLKEN_WDT_SHIFT)) & SYSCON_LPOSCCLKEN_WDT_MASK)
#define SYSCON_LPOSCCLKEN_WKT_MASK               (0x2U)
#define SYSCON_LPOSCCLKEN_WKT_SHIFT              (1U)
#define SYSCON_LPOSCCLKEN_WKT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_LPOSCCLKEN_WKT_SHIFT)) & SYSCON_LPOSCCLKEN_WKT_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL0 - System clock group 0 control register */
/*! @{ */
#define SYSCON_SYSAHBCLKCTRL0_SYS_MASK           (0x1U)
#define SYSCON_SYSAHBCLKCTRL0_SYS_SHIFT          (0U)
#define SYSCON_SYSAHBCLKCTRL0_SYS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SYS_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SYS_MASK)
#define SYSCON_SYSAHBCLKCTRL0_ROM_MASK           (0x2U)
#define SYSCON_SYSAHBCLKCTRL0_ROM_SHIFT          (1U)
#define SYSCON_SYSAHBCLKCTRL0_ROM(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_ROM_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_ROM_MASK)
#define SYSCON_SYSAHBCLKCTRL0_RAM0_MASK          (0x4U)
#define SYSCON_SYSAHBCLKCTRL0_RAM0_SHIFT         (2U)
#define SYSCON_SYSAHBCLKCTRL0_RAM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_RAM0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_RAM0_MASK)
#define SYSCON_SYSAHBCLKCTRL0_FLASH_MASK         (0x10U)
#define SYSCON_SYSAHBCLKCTRL0_FLASH_SHIFT        (4U)
#define SYSCON_SYSAHBCLKCTRL0_FLASH(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_FLASH_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_FLASH_MASK)
#define SYSCON_SYSAHBCLKCTRL0_I2C0_MASK          (0x20U)
#define SYSCON_SYSAHBCLKCTRL0_I2C0_SHIFT         (5U)
#define SYSCON_SYSAHBCLKCTRL0_I2C0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C0_MASK)
#define SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK         (0x40U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT        (6U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK)
#define SYSCON_SYSAHBCLKCTRL0_SWM_MASK           (0x80U)
#define SYSCON_SYSAHBCLKCTRL0_SWM_SHIFT          (7U)
#define SYSCON_SYSAHBCLKCTRL0_SWM(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SWM_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SWM_MASK)
#define SYSCON_SYSAHBCLKCTRL0_WKT_MASK           (0x200U)
#define SYSCON_SYSAHBCLKCTRL0_WKT_SHIFT          (9U)
#define SYSCON_SYSAHBCLKCTRL0_WKT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_WKT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_WKT_MASK)
#define SYSCON_SYSAHBCLKCTRL0_MRT_MASK           (0x400U)
#define SYSCON_SYSAHBCLKCTRL0_MRT_SHIFT          (10U)
#define SYSCON_SYSAHBCLKCTRL0_MRT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_MRT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_MRT_MASK)
#define SYSCON_SYSAHBCLKCTRL0_SPI0_MASK          (0x800U)
#define SYSCON_SYSAHBCLKCTRL0_SPI0_SHIFT         (11U)
#define SYSCON_SYSAHBCLKCTRL0_SPI0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SPI0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SPI0_MASK)
#define SYSCON_SYSAHBCLKCTRL0_CRC_MASK           (0x2000U)
#define SYSCON_SYSAHBCLKCTRL0_CRC_SHIFT          (13U)
#define SYSCON_SYSAHBCLKCTRL0_CRC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_CRC_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_CRC_MASK)
#define SYSCON_SYSAHBCLKCTRL0_UART0_MASK         (0x4000U)
#define SYSCON_SYSAHBCLKCTRL0_UART0_SHIFT        (14U)
#define SYSCON_SYSAHBCLKCTRL0_UART0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART0_MASK)
#define SYSCON_SYSAHBCLKCTRL0_UART1_MASK         (0x8000U)
#define SYSCON_SYSAHBCLKCTRL0_UART1_SHIFT        (15U)
#define SYSCON_SYSAHBCLKCTRL0_UART1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART1_MASK)
#define SYSCON_SYSAHBCLKCTRL0_WWDT_MASK          (0x20000U)
#define SYSCON_SYSAHBCLKCTRL0_WWDT_SHIFT         (17U)
#define SYSCON_SYSAHBCLKCTRL0_WWDT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_WWDT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_WWDT_MASK)
#define SYSCON_SYSAHBCLKCTRL0_IOCON_MASK         (0x40000U)
#define SYSCON_SYSAHBCLKCTRL0_IOCON_SHIFT        (18U)
#define SYSCON_SYSAHBCLKCTRL0_IOCON(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_IOCON_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_IOCON_MASK)
#define SYSCON_SYSAHBCLKCTRL0_ACMP_MASK          (0x80000U)
#define SYSCON_SYSAHBCLKCTRL0_ACMP_SHIFT         (19U)
#define SYSCON_SYSAHBCLKCTRL0_ACMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_ACMP_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_ACMP_MASK)
#define SYSCON_SYSAHBCLKCTRL0_I2C1_MASK          (0x200000U)
#define SYSCON_SYSAHBCLKCTRL0_I2C1_SHIFT         (21U)
#define SYSCON_SYSAHBCLKCTRL0_I2C1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C1_MASK)
#define SYSCON_SYSAHBCLKCTRL0_ADC_MASK           (0x1000000U)
#define SYSCON_SYSAHBCLKCTRL0_ADC_SHIFT          (24U)
#define SYSCON_SYSAHBCLKCTRL0_ADC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_ADC_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_ADC_MASK)
#define SYSCON_SYSAHBCLKCTRL0_CTIMER_MASK        (0x2000000U)
#define SYSCON_SYSAHBCLKCTRL0_CTIMER_SHIFT       (25U)
#define SYSCON_SYSAHBCLKCTRL0_CTIMER(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_CTIMER_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_CTIMER_MASK)
#define SYSCON_SYSAHBCLKCTRL0_DAC_MASK           (0x8000000U)
#define SYSCON_SYSAHBCLKCTRL0_DAC_SHIFT          (27U)
#define SYSCON_SYSAHBCLKCTRL0_DAC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_DAC_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_DAC_MASK)
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK      (0x10000000U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT_SHIFT     (28U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_GPIO_INT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL1 - System clock group 1 control register */
/*! @{ */
#define SYSCON_SYSAHBCLKCTRL1_CAPT_MASK          (0x1U)
#define SYSCON_SYSAHBCLKCTRL1_CAPT_SHIFT         (0U)
#define SYSCON_SYSAHBCLKCTRL1_CAPT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL1_CAPT_SHIFT)) & SYSCON_SYSAHBCLKCTRL1_CAPT_MASK)
#define SYSCON_SYSAHBCLKCTRL1_PLU_MASK           (0x20U)
#define SYSCON_SYSAHBCLKCTRL1_PLU_SHIFT          (5U)
#define SYSCON_SYSAHBCLKCTRL1_PLU(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL1_PLU_SHIFT)) & SYSCON_SYSAHBCLKCTRL1_PLU_MASK)
/*! @} */

/*! @name PRESETCTRL0 - Peripheral reset group 0 control register */
/*! @{ */
#define SYSCON_PRESETCTRL0_FLASH_RST_N_MASK      (0x10U)
#define SYSCON_PRESETCTRL0_FLASH_RST_N_SHIFT     (4U)
#define SYSCON_PRESETCTRL0_FLASH_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FLASH_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_FLASH_RST_N_MASK)
#define SYSCON_PRESETCTRL0_I2C0_RST_N_MASK       (0x20U)
#define SYSCON_PRESETCTRL0_I2C0_RST_N_SHIFT      (5U)
#define SYSCON_PRESETCTRL0_I2C0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C0_RST_N_MASK)
#define SYSCON_PRESETCTRL0_GPIO0_RST_N_MASK      (0x40U)
#define SYSCON_PRESETCTRL0_GPIO0_RST_N_SHIFT     (6U)
#define SYSCON_PRESETCTRL0_GPIO0_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_GPIO0_RST_N_MASK)
#define SYSCON_PRESETCTRL0_SWM_RST_N_MASK        (0x80U)
#define SYSCON_PRESETCTRL0_SWM_RST_N_SHIFT       (7U)
#define SYSCON_PRESETCTRL0_SWM_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SWM_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_SWM_RST_N_MASK)
#define SYSCON_PRESETCTRL0_WKT_RST_N_MASK        (0x200U)
#define SYSCON_PRESETCTRL0_WKT_RST_N_SHIFT       (9U)
#define SYSCON_PRESETCTRL0_WKT_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_WKT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_WKT_RST_N_MASK)
#define SYSCON_PRESETCTRL0_MRT_RST_N_MASK        (0x400U)
#define SYSCON_PRESETCTRL0_MRT_RST_N_SHIFT       (10U)
#define SYSCON_PRESETCTRL0_MRT_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_MRT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_MRT_RST_N_MASK)
#define SYSCON_PRESETCTRL0_SPI0_RST_N_MASK       (0x800U)
#define SYSCON_PRESETCTRL0_SPI0_RST_N_SHIFT      (11U)
#define SYSCON_PRESETCTRL0_SPI0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SPI0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_SPI0_RST_N_MASK)
#define SYSCON_PRESETCTRL0_CRC_RST_N_MASK        (0x2000U)
#define SYSCON_PRESETCTRL0_CRC_RST_N_SHIFT       (13U)
#define SYSCON_PRESETCTRL0_CRC_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CRC_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_CRC_RST_N_MASK)
#define SYSCON_PRESETCTRL0_UART0_RST_N_MASK      (0x4000U)
#define SYSCON_PRESETCTRL0_UART0_RST_N_SHIFT     (14U)
#define SYSCON_PRESETCTRL0_UART0_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART0_RST_N_MASK)
#define SYSCON_PRESETCTRL0_UART1_RST_N_MASK      (0x8000U)
#define SYSCON_PRESETCTRL0_UART1_RST_N_SHIFT     (15U)
#define SYSCON_PRESETCTRL0_UART1_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART1_RST_N_MASK)
#define SYSCON_PRESETCTRL0_IOCON_RST_N_MASK      (0x40000U)
#define SYSCON_PRESETCTRL0_IOCON_RST_N_SHIFT     (18U)
#define SYSCON_PRESETCTRL0_IOCON_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_IOCON_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_IOCON_RST_N_MASK)
#define SYSCON_PRESETCTRL0_ACMP_RST_N_MASK       (0x80000U)
#define SYSCON_PRESETCTRL0_ACMP_RST_N_SHIFT      (19U)
#define SYSCON_PRESETCTRL0_ACMP_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ACMP_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_ACMP_RST_N_MASK)
#define SYSCON_PRESETCTRL0_I2C1_RST_N_MASK       (0x200000U)
#define SYSCON_PRESETCTRL0_I2C1_RST_N_SHIFT      (21U)
#define SYSCON_PRESETCTRL0_I2C1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C1_RST_N_MASK)
#define SYSCON_PRESETCTRL0_ADC_RST_N_MASK        (0x1000000U)
#define SYSCON_PRESETCTRL0_ADC_RST_N_SHIFT       (24U)
#define SYSCON_PRESETCTRL0_ADC_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ADC_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_ADC_RST_N_MASK)
#define SYSCON_PRESETCTRL0_CTIMER0_RST_N_MASK    (0x2000000U)
#define SYSCON_PRESETCTRL0_CTIMER0_RST_N_SHIFT   (25U)
#define SYSCON_PRESETCTRL0_CTIMER0_RST_N(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CTIMER0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_CTIMER0_RST_N_MASK)
#define SYSCON_PRESETCTRL0_DAC0_RST_N_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL0_DAC0_RST_N_SHIFT      (27U)
#define SYSCON_PRESETCTRL0_DAC0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DAC0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_DAC0_RST_N_MASK)
#define SYSCON_PRESETCTRL0_GPIOINT_RST_N_MASK    (0x10000000U)
#define SYSCON_PRESETCTRL0_GPIOINT_RST_N_SHIFT   (28U)
#define SYSCON_PRESETCTRL0_GPIOINT_RST_N(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIOINT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_GPIOINT_RST_N_MASK)
/*! @} */

/*! @name PRESETCTRL1 - Peripheral reset group 1 control register */
/*! @{ */
#define SYSCON_PRESETCTRL1_CAPT_RST_N_MASK       (0x1U)
#define SYSCON_PRESETCTRL1_CAPT_RST_N_SHIFT      (0U)
#define SYSCON_PRESETCTRL1_CAPT_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_CAPT_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_CAPT_RST_N_MASK)
#define SYSCON_PRESETCTRL1_FRG0_RST_N_MASK       (0x8U)
#define SYSCON_PRESETCTRL1_FRG0_RST_N_SHIFT      (3U)
#define SYSCON_PRESETCTRL1_FRG0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FRG0_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_FRG0_RST_N_MASK)
#define SYSCON_PRESETCTRL1_PLU_RST_N_MASK        (0x20U)
#define SYSCON_PRESETCTRL1_PLU_RST_N_SHIFT       (5U)
#define SYSCON_PRESETCTRL1_PLU_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_PLU_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_PLU_RST_N_MASK)
/*! @} */

/*! @name UART0CLKSEL - Function clock source select for UART0. */
/*! @{ */
#define SYSCON_UART0CLKSEL_SEL_MASK              (0x7U)
#define SYSCON_UART0CLKSEL_SEL_SHIFT             (0U)
#define SYSCON_UART0CLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_UART0CLKSEL_SEL_SHIFT)) & SYSCON_UART0CLKSEL_SEL_MASK)
/*! @} */

/*! @name UART1CLKSEL - Function clock source select for UART1. */
/*! @{ */
#define SYSCON_UART1CLKSEL_SEL_MASK              (0x7U)
#define SYSCON_UART1CLKSEL_SEL_SHIFT             (0U)
#define SYSCON_UART1CLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_UART1CLKSEL_SEL_SHIFT)) & SYSCON_UART1CLKSEL_SEL_MASK)
/*! @} */

/*! @name I2C0CLKSEL - Function clock source select for I2C0. */
/*! @{ */
#define SYSCON_I2C0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_I2C0CLKSEL_SEL_SHIFT              (0U)
#define SYSCON_I2C0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_I2C0CLKSEL_SEL_SHIFT)) & SYSCON_I2C0CLKSEL_SEL_MASK)
/*! @} */

/*! @name I2C1CLKSEL - Function clock source select for I2C1. */
/*! @{ */
#define SYSCON_I2C1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_I2C1CLKSEL_SEL_SHIFT              (0U)
#define SYSCON_I2C1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_I2C1CLKSEL_SEL_SHIFT)) & SYSCON_I2C1CLKSEL_SEL_MASK)
/*! @} */

/*! @name SPI0CLKSEL - Function clock source select for SPI0. */
/*! @{ */
#define SYSCON_SPI0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_SPI0CLKSEL_SEL_SHIFT              (0U)
#define SYSCON_SPI0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SPI0CLKSEL_SEL_SHIFT)) & SYSCON_SPI0CLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG_FRGDIV - fractional generator divider value register */
/*! @{ */
#define SYSCON_FRG_FRGDIV_DIV_MASK               (0xFFU)
#define SYSCON_FRG_FRGDIV_DIV_SHIFT              (0U)
#define SYSCON_FRG_FRGDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGDIV_DIV_SHIFT)) & SYSCON_FRG_FRGDIV_DIV_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGDIV */
#define SYSCON_FRG_FRGDIV_COUNT                  (1U)

/*! @name FRG_FRGMULT - fractional generator multiplier value register */
/*! @{ */
#define SYSCON_FRG_FRGMULT_MULT_MASK             (0xFFU)
#define SYSCON_FRG_FRGMULT_MULT_SHIFT            (0U)
#define SYSCON_FRG_FRGMULT_MULT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGMULT_MULT_SHIFT)) & SYSCON_FRG_FRGMULT_MULT_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGMULT */
#define SYSCON_FRG_FRGMULT_COUNT                 (1U)

/*! @name FRG_FRGCLKSEL - FRG clock source select register */
/*! @{ */
#define SYSCON_FRG_FRGCLKSEL_SEL_MASK            (0x3U)
#define SYSCON_FRG_FRGCLKSEL_SEL_SHIFT           (0U)
#define SYSCON_FRG_FRGCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGCLKSEL_SEL_SHIFT)) & SYSCON_FRG_FRGCLKSEL_SEL_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGCLKSEL */
#define SYSCON_FRG_FRGCLKSEL_COUNT               (1U)

/*! @name CLKOUTSEL - CLKOUT clock source select register */
/*! @{ */
#define SYSCON_CLKOUTSEL_SEL_MASK                (0x7U)
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSEL_SEL_SHIFT)) & SYSCON_CLKOUTSEL_SEL_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider registers */
/*! @{ */
#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)
/*! @} */

/*! @name PIOPORACP - POR captured PIO0 status 0 */
/*! @{ */
#define SYSCON_PIOPORACP_PIOSTAT_MASK            (0xFFFFFFFFU)
#define SYSCON_PIOPORACP_PIOSTAT_SHIFT           (0U)
#define SYSCON_PIOPORACP_PIOSTAT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORACP_PIOSTAT_SHIFT)) & SYSCON_PIOPORACP_PIOSTAT_MASK)
/*! @} */

/*! @name BODCTRL - BOD control register */
/*! @{ */
#define SYSCON_BODCTRL_BODRSTLEV_MASK            (0x3U)
#define SYSCON_BODCTRL_BODRSTLEV_SHIFT           (0U)
#define SYSCON_BODCTRL_BODRSTLEV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTLEV_SHIFT)) & SYSCON_BODCTRL_BODRSTLEV_MASK)
#define SYSCON_BODCTRL_BODINTVAL_MASK            (0xCU)
#define SYSCON_BODCTRL_BODINTVAL_SHIFT           (2U)
#define SYSCON_BODCTRL_BODINTVAL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODINTVAL_SHIFT)) & SYSCON_BODCTRL_BODINTVAL_MASK)
#define SYSCON_BODCTRL_BODRSTENA_MASK            (0x10U)
#define SYSCON_BODCTRL_BODRSTENA_SHIFT           (4U)
#define SYSCON_BODCTRL_BODRSTENA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTENA_SHIFT)) & SYSCON_BODCTRL_BODRSTENA_MASK)
/*! @} */

/*! @name SYSTCKCAL - System tick timer calibration register */
/*! @{ */
#define SYSCON_SYSTCKCAL_CAL_MASK                (0x3FFFFFFU)
#define SYSCON_SYSTCKCAL_CAL_SHIFT               (0U)
#define SYSCON_SYSTCKCAL_CAL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTCKCAL_CAL_SHIFT)) & SYSCON_SYSTCKCAL_CAL_MASK)
/*! @} */

/*! @name IRQLATENCY - IRQ latency register */
/*! @{ */
#define SYSCON_IRQLATENCY_LATENCY_MASK           (0xFFU)
#define SYSCON_IRQLATENCY_LATENCY_SHIFT          (0U)
#define SYSCON_IRQLATENCY_LATENCY(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_IRQLATENCY_LATENCY_SHIFT)) & SYSCON_IRQLATENCY_LATENCY_MASK)
/*! @} */

/*! @name NMISRC - NMI source selection register */
/*! @{ */
#define SYSCON_NMISRC_IRQN_MASK                  (0x1FU)
#define SYSCON_NMISRC_IRQN_SHIFT                 (0U)
#define SYSCON_NMISRC_IRQN(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQN_SHIFT)) & SYSCON_NMISRC_IRQN_MASK)
#define SYSCON_NMISRC_NMIEN_MASK                 (0x80000000U)
#define SYSCON_NMISRC_NMIEN_SHIFT                (31U)
#define SYSCON_NMISRC_NMIEN(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIEN_SHIFT)) & SYSCON_NMISRC_NMIEN_MASK)
/*! @} */

/*! @name PINTSEL - Pin interrupt select registers N */
/*! @{ */
#define SYSCON_PINTSEL_INTPIN_MASK               (0x3FU)
#define SYSCON_PINTSEL_INTPIN_SHIFT              (0U)
#define SYSCON_PINTSEL_INTPIN(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PINTSEL_INTPIN_SHIFT)) & SYSCON_PINTSEL_INTPIN_MASK)
/*! @} */

/* The count of SYSCON_PINTSEL */
#define SYSCON_PINTSEL_COUNT                     (8U)

/*! @name STARTERP0 - Start logic 0 pin wake-up enable register 0 */
/*! @{ */
#define SYSCON_STARTERP0_PINT0_MASK              (0x1U)
#define SYSCON_STARTERP0_PINT0_SHIFT             (0U)
#define SYSCON_STARTERP0_PINT0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT0_SHIFT)) & SYSCON_STARTERP0_PINT0_MASK)
#define SYSCON_STARTERP0_PINT1_MASK              (0x2U)
#define SYSCON_STARTERP0_PINT1_SHIFT             (1U)
#define SYSCON_STARTERP0_PINT1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT1_SHIFT)) & SYSCON_STARTERP0_PINT1_MASK)
#define SYSCON_STARTERP0_PINT2_MASK              (0x4U)
#define SYSCON_STARTERP0_PINT2_SHIFT             (2U)
#define SYSCON_STARTERP0_PINT2(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT2_SHIFT)) & SYSCON_STARTERP0_PINT2_MASK)
#define SYSCON_STARTERP0_PINT3_MASK              (0x8U)
#define SYSCON_STARTERP0_PINT3_SHIFT             (3U)
#define SYSCON_STARTERP0_PINT3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT3_SHIFT)) & SYSCON_STARTERP0_PINT3_MASK)
#define SYSCON_STARTERP0_PINT4_MASK              (0x10U)
#define SYSCON_STARTERP0_PINT4_SHIFT             (4U)
#define SYSCON_STARTERP0_PINT4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT4_SHIFT)) & SYSCON_STARTERP0_PINT4_MASK)
#define SYSCON_STARTERP0_PINT5_MASK              (0x20U)
#define SYSCON_STARTERP0_PINT5_SHIFT             (5U)
#define SYSCON_STARTERP0_PINT5(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT5_SHIFT)) & SYSCON_STARTERP0_PINT5_MASK)
#define SYSCON_STARTERP0_PINT6_MASK              (0x40U)
#define SYSCON_STARTERP0_PINT6_SHIFT             (6U)
#define SYSCON_STARTERP0_PINT6(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT6_SHIFT)) & SYSCON_STARTERP0_PINT6_MASK)
#define SYSCON_STARTERP0_PINT7_MASK              (0x80U)
#define SYSCON_STARTERP0_PINT7_SHIFT             (7U)
#define SYSCON_STARTERP0_PINT7(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT7_SHIFT)) & SYSCON_STARTERP0_PINT7_MASK)
/*! @} */

/*! @name STARTERP1 - Start logic 0 pin wake-up enable register 1 */
/*! @{ */
#define SYSCON_STARTERP1_SPI0_MASK               (0x1U)
#define SYSCON_STARTERP1_SPI0_SHIFT              (0U)
#define SYSCON_STARTERP1_SPI0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_SPI0_SHIFT)) & SYSCON_STARTERP1_SPI0_MASK)
#define SYSCON_STARTERP1_USART0_MASK             (0x8U)
#define SYSCON_STARTERP1_USART0_SHIFT            (3U)
#define SYSCON_STARTERP1_USART0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_USART0_SHIFT)) & SYSCON_STARTERP1_USART0_MASK)
#define SYSCON_STARTERP1_USART1_MASK             (0x10U)
#define SYSCON_STARTERP1_USART1_SHIFT            (4U)
#define SYSCON_STARTERP1_USART1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_USART1_SHIFT)) & SYSCON_STARTERP1_USART1_MASK)
#define SYSCON_STARTERP1_PLU_MASK                (0x40U)
#define SYSCON_STARTERP1_PLU_SHIFT               (6U)
#define SYSCON_STARTERP1_PLU(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_PLU_SHIFT)) & SYSCON_STARTERP1_PLU_MASK)
#define SYSCON_STARTERP1_I2C1_MASK               (0x80U)
#define SYSCON_STARTERP1_I2C1_SHIFT              (7U)
#define SYSCON_STARTERP1_I2C1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_I2C1_SHIFT)) & SYSCON_STARTERP1_I2C1_MASK)
#define SYSCON_STARTERP1_I2C0_MASK               (0x100U)
#define SYSCON_STARTERP1_I2C0_SHIFT              (8U)
#define SYSCON_STARTERP1_I2C0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_I2C0_SHIFT)) & SYSCON_STARTERP1_I2C0_MASK)
#define SYSCON_STARTERP1_CAPT_MASK               (0x800U)
#define SYSCON_STARTERP1_CAPT_SHIFT              (11U)
#define SYSCON_STARTERP1_CAPT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_CAPT_SHIFT)) & SYSCON_STARTERP1_CAPT_MASK)
#define SYSCON_STARTERP1_WWDT_MASK               (0x1000U)
#define SYSCON_STARTERP1_WWDT_SHIFT              (12U)
#define SYSCON_STARTERP1_WWDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_WWDT_SHIFT)) & SYSCON_STARTERP1_WWDT_MASK)
#define SYSCON_STARTERP1_BOD_MASK                (0x2000U)
#define SYSCON_STARTERP1_BOD_SHIFT               (13U)
#define SYSCON_STARTERP1_BOD(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_BOD_SHIFT)) & SYSCON_STARTERP1_BOD_MASK)
#define SYSCON_STARTERP1_WKT_MASK                (0x8000U)
#define SYSCON_STARTERP1_WKT_SHIFT               (15U)
#define SYSCON_STARTERP1_WKT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_WKT_SHIFT)) & SYSCON_STARTERP1_WKT_MASK)
/*! @} */

/*! @name PDSLEEPCFG - Deep-sleep configuration register */
/*! @{ */
#define SYSCON_PDSLEEPCFG_BOD_PD_MASK            (0x8U)
#define SYSCON_PDSLEEPCFG_BOD_PD_SHIFT           (3U)
#define SYSCON_PDSLEEPCFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_BOD_PD_SHIFT)) & SYSCON_PDSLEEPCFG_BOD_PD_MASK)
#define SYSCON_PDSLEEPCFG_LPOSC_PD_MASK          (0x40U)
#define SYSCON_PDSLEEPCFG_LPOSC_PD_SHIFT         (6U)
#define SYSCON_PDSLEEPCFG_LPOSC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_LPOSC_PD_SHIFT)) & SYSCON_PDSLEEPCFG_LPOSC_PD_MASK)
/*! @} */

/*! @name PDAWAKECFG - Wake-up configuration register */
/*! @{ */
#define SYSCON_PDAWAKECFG_FROOUT_PD_MASK         (0x1U)
#define SYSCON_PDAWAKECFG_FROOUT_PD_SHIFT        (0U)
#define SYSCON_PDAWAKECFG_FROOUT_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FROOUT_PD_SHIFT)) & SYSCON_PDAWAKECFG_FROOUT_PD_MASK)
#define SYSCON_PDAWAKECFG_FRO_PD_MASK            (0x2U)
#define SYSCON_PDAWAKECFG_FRO_PD_SHIFT           (1U)
#define SYSCON_PDAWAKECFG_FRO_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FRO_PD_SHIFT)) & SYSCON_PDAWAKECFG_FRO_PD_MASK)
#define SYSCON_PDAWAKECFG_FLASH_PD_MASK          (0x4U)
#define SYSCON_PDAWAKECFG_FLASH_PD_SHIFT         (2U)
#define SYSCON_PDAWAKECFG_FLASH_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FLASH_PD_SHIFT)) & SYSCON_PDAWAKECFG_FLASH_PD_MASK)
#define SYSCON_PDAWAKECFG_BOD_PD_MASK            (0x8U)
#define SYSCON_PDAWAKECFG_BOD_PD_SHIFT           (3U)
#define SYSCON_PDAWAKECFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_BOD_PD_SHIFT)) & SYSCON_PDAWAKECFG_BOD_PD_MASK)
#define SYSCON_PDAWAKECFG_ADC_PD_MASK            (0x10U)
#define SYSCON_PDAWAKECFG_ADC_PD_SHIFT           (4U)
#define SYSCON_PDAWAKECFG_ADC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_ADC_PD_SHIFT)) & SYSCON_PDAWAKECFG_ADC_PD_MASK)
#define SYSCON_PDAWAKECFG_LPOSC_PD_MASK          (0x40U)
#define SYSCON_PDAWAKECFG_LPOSC_PD_SHIFT         (6U)
#define SYSCON_PDAWAKECFG_LPOSC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_LPOSC_PD_SHIFT)) & SYSCON_PDAWAKECFG_LPOSC_PD_MASK)
#define SYSCON_PDAWAKECFG_DAC_MASK               (0x2000U)
#define SYSCON_PDAWAKECFG_DAC_SHIFT              (13U)
#define SYSCON_PDAWAKECFG_DAC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_DAC_SHIFT)) & SYSCON_PDAWAKECFG_DAC_MASK)
#define SYSCON_PDAWAKECFG_ACMP_MASK              (0x8000U)
#define SYSCON_PDAWAKECFG_ACMP_SHIFT             (15U)
#define SYSCON_PDAWAKECFG_ACMP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_ACMP_SHIFT)) & SYSCON_PDAWAKECFG_ACMP_MASK)
/*! @} */

/*! @name PDRUNCFG - Power configuration register */
/*! @{ */
#define SYSCON_PDRUNCFG_FROOUT_PD_MASK           (0x1U)
#define SYSCON_PDRUNCFG_FROOUT_PD_SHIFT          (0U)
#define SYSCON_PDRUNCFG_FROOUT_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FROOUT_PD_SHIFT)) & SYSCON_PDRUNCFG_FROOUT_PD_MASK)
#define SYSCON_PDRUNCFG_FRO_PD_MASK              (0x2U)
#define SYSCON_PDRUNCFG_FRO_PD_SHIFT             (1U)
#define SYSCON_PDRUNCFG_FRO_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FRO_PD_SHIFT)) & SYSCON_PDRUNCFG_FRO_PD_MASK)
#define SYSCON_PDRUNCFG_FLASH_PD_MASK            (0x4U)
#define SYSCON_PDRUNCFG_FLASH_PD_SHIFT           (2U)
#define SYSCON_PDRUNCFG_FLASH_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FLASH_PD_SHIFT)) & SYSCON_PDRUNCFG_FLASH_PD_MASK)
#define SYSCON_PDRUNCFG_BOD_PD_MASK              (0x8U)
#define SYSCON_PDRUNCFG_BOD_PD_SHIFT             (3U)
#define SYSCON_PDRUNCFG_BOD_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_BOD_PD_SHIFT)) & SYSCON_PDRUNCFG_BOD_PD_MASK)
#define SYSCON_PDRUNCFG_ADC_PD_MASK              (0x10U)
#define SYSCON_PDRUNCFG_ADC_PD_SHIFT             (4U)
#define SYSCON_PDRUNCFG_ADC_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_ADC_PD_SHIFT)) & SYSCON_PDRUNCFG_ADC_PD_MASK)
#define SYSCON_PDRUNCFG_LPOSC_PD_MASK            (0x40U)
#define SYSCON_PDRUNCFG_LPOSC_PD_SHIFT           (6U)
#define SYSCON_PDRUNCFG_LPOSC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_LPOSC_PD_SHIFT)) & SYSCON_PDRUNCFG_LPOSC_PD_MASK)
#define SYSCON_PDRUNCFG_DAC0_MASK                (0x2000U)
#define SYSCON_PDRUNCFG_DAC0_SHIFT               (13U)
#define SYSCON_PDRUNCFG_DAC0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_DAC0_SHIFT)) & SYSCON_PDRUNCFG_DAC0_MASK)
#define SYSCON_PDRUNCFG_ACMP_MASK                (0x8000U)
#define SYSCON_PDRUNCFG_ACMP_SHIFT               (15U)
#define SYSCON_PDRUNCFG_ACMP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_ACMP_SHIFT)) & SYSCON_PDRUNCFG_ACMP_MASK)
/*! @} */

/*! @name DEVICE_ID - Device ID register */
/*! @{ */
#define SYSCON_DEVICE_ID_DEVICEID_MASK           (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_DEVICEID_SHIFT          (0U)
#define SYSCON_DEVICE_ID_DEVICEID(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID_DEVICEID_SHIFT)) & SYSCON_DEVICE_ID_DEVICEID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */


/* SYSCON - Peripheral instance base addresses */
/** Peripheral SYSCON base address */
#define SYSCON_BASE                              (0x40048000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array initializer of SYSCON peripheral base addresses */
#define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
/** Array initializer of SYSCON peripheral base pointers */
#define SYSCON_BASE_PTRS                         { SYSCON }

/*!
 * @}
 */ /* end of group SYSCON_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- USART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USART_Peripheral_Access_Layer USART Peripheral Access Layer
 * @{
 */

/** USART - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG;                               /**< USART Configuration register. Basic USART configuration settings that typically are not changed during operation., offset: 0x0 */
  __IO uint32_t CTL;                               /**< USART Control register. USART control settings that are more likely to change during operation., offset: 0x4 */
  __IO uint32_t STAT;                              /**< USART Status register. The complete status value can be read here. Writing ones clears some bits in the register. Some bits can be cleared by writing a 1 to them., offset: 0x8 */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., offset: 0xC */
  __O  uint32_t INTENCLR;                          /**< Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared., offset: 0x10 */
  __I  uint32_t RXDAT;                             /**< Receiver Data register. Contains the last character received., offset: 0x14 */
  __I  uint32_t RXDATSTAT;                         /**< Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows DMA or software to recover incoming data and status together., offset: 0x18 */
  __IO uint32_t TXDAT;                             /**< Transmit Data register. Data to be transmitted is written here., offset: 0x1C */
  __IO uint32_t BRG;                               /**< Baud Rate Generator register. 16-bit integer baud rate divisor value., offset: 0x20 */
  __I  uint32_t INTSTAT;                           /**< Interrupt status register. Reflects interrupts that are currently enabled., offset: 0x24 */
  __IO uint32_t OSR;                               /**< Oversample selection register for asynchronous communication., offset: 0x28 */
  __IO uint32_t ADDR;                              /**< Address register for automatic address matching., offset: 0x2C */
} USART_Type;

/* ----------------------------------------------------------------------------
   -- USART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USART_Register_Masks USART Register Masks
 * @{
 */

/*! @name CFG - USART Configuration register. Basic USART configuration settings that typically are not changed during operation. */
/*! @{ */
#define USART_CFG_ENABLE_MASK                    (0x1U)
#define USART_CFG_ENABLE_SHIFT                   (0U)
#define USART_CFG_ENABLE(x)                      (((uint32_t)(((uint32_t)(x)) << USART_CFG_ENABLE_SHIFT)) & USART_CFG_ENABLE_MASK)
#define USART_CFG_DATALEN_MASK                   (0xCU)
#define USART_CFG_DATALEN_SHIFT                  (2U)
#define USART_CFG_DATALEN(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CFG_DATALEN_SHIFT)) & USART_CFG_DATALEN_MASK)
#define USART_CFG_PARITYSEL_MASK                 (0x30U)
#define USART_CFG_PARITYSEL_SHIFT                (4U)
#define USART_CFG_PARITYSEL(x)                   (((uint32_t)(((uint32_t)(x)) << USART_CFG_PARITYSEL_SHIFT)) & USART_CFG_PARITYSEL_MASK)
#define USART_CFG_STOPLEN_MASK                   (0x40U)
#define USART_CFG_STOPLEN_SHIFT                  (6U)
#define USART_CFG_STOPLEN(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CFG_STOPLEN_SHIFT)) & USART_CFG_STOPLEN_MASK)
#define USART_CFG_CTSEN_MASK                     (0x200U)
#define USART_CFG_CTSEN_SHIFT                    (9U)
#define USART_CFG_CTSEN(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_CTSEN_SHIFT)) & USART_CFG_CTSEN_MASK)
#define USART_CFG_SYNCEN_MASK                    (0x800U)
#define USART_CFG_SYNCEN_SHIFT                   (11U)
#define USART_CFG_SYNCEN(x)                      (((uint32_t)(((uint32_t)(x)) << USART_CFG_SYNCEN_SHIFT)) & USART_CFG_SYNCEN_MASK)
#define USART_CFG_CLKPOL_MASK                    (0x1000U)
#define USART_CFG_CLKPOL_SHIFT                   (12U)
#define USART_CFG_CLKPOL(x)                      (((uint32_t)(((uint32_t)(x)) << USART_CFG_CLKPOL_SHIFT)) & USART_CFG_CLKPOL_MASK)
#define USART_CFG_SYNCMST_MASK                   (0x4000U)
#define USART_CFG_SYNCMST_SHIFT                  (14U)
#define USART_CFG_SYNCMST(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CFG_SYNCMST_SHIFT)) & USART_CFG_SYNCMST_MASK)
#define USART_CFG_LOOP_MASK                      (0x8000U)
#define USART_CFG_LOOP_SHIFT                     (15U)
#define USART_CFG_LOOP(x)                        (((uint32_t)(((uint32_t)(x)) << USART_CFG_LOOP_SHIFT)) & USART_CFG_LOOP_MASK)
#define USART_CFG_OETA_MASK                      (0x40000U)
#define USART_CFG_OETA_SHIFT                     (18U)
#define USART_CFG_OETA(x)                        (((uint32_t)(((uint32_t)(x)) << USART_CFG_OETA_SHIFT)) & USART_CFG_OETA_MASK)
#define USART_CFG_AUTOADDR_MASK                  (0x80000U)
#define USART_CFG_AUTOADDR_SHIFT                 (19U)
#define USART_CFG_AUTOADDR(x)                    (((uint32_t)(((uint32_t)(x)) << USART_CFG_AUTOADDR_SHIFT)) & USART_CFG_AUTOADDR_MASK)
#define USART_CFG_OESEL_MASK                     (0x100000U)
#define USART_CFG_OESEL_SHIFT                    (20U)
#define USART_CFG_OESEL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_OESEL_SHIFT)) & USART_CFG_OESEL_MASK)
#define USART_CFG_OEPOL_MASK                     (0x200000U)
#define USART_CFG_OEPOL_SHIFT                    (21U)
#define USART_CFG_OEPOL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_OEPOL_SHIFT)) & USART_CFG_OEPOL_MASK)
#define USART_CFG_RXPOL_MASK                     (0x400000U)
#define USART_CFG_RXPOL_SHIFT                    (22U)
#define USART_CFG_RXPOL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_RXPOL_SHIFT)) & USART_CFG_RXPOL_MASK)
#define USART_CFG_TXPOL_MASK                     (0x800000U)
#define USART_CFG_TXPOL_SHIFT                    (23U)
#define USART_CFG_TXPOL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_TXPOL_SHIFT)) & USART_CFG_TXPOL_MASK)
/*! @} */

/*! @name CTL - USART Control register. USART control settings that are more likely to change during operation. */
/*! @{ */
#define USART_CTL_TXBRKEN_MASK                   (0x2U)
#define USART_CTL_TXBRKEN_SHIFT                  (1U)
#define USART_CTL_TXBRKEN(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CTL_TXBRKEN_SHIFT)) & USART_CTL_TXBRKEN_MASK)
#define USART_CTL_ADDRDET_MASK                   (0x4U)
#define USART_CTL_ADDRDET_SHIFT                  (2U)
#define USART_CTL_ADDRDET(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CTL_ADDRDET_SHIFT)) & USART_CTL_ADDRDET_MASK)
#define USART_CTL_TXDIS_MASK                     (0x40U)
#define USART_CTL_TXDIS_SHIFT                    (6U)
#define USART_CTL_TXDIS(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CTL_TXDIS_SHIFT)) & USART_CTL_TXDIS_MASK)
#define USART_CTL_CC_MASK                        (0x100U)
#define USART_CTL_CC_SHIFT                       (8U)
#define USART_CTL_CC(x)                          (((uint32_t)(((uint32_t)(x)) << USART_CTL_CC_SHIFT)) & USART_CTL_CC_MASK)
#define USART_CTL_CLRCCONRX_MASK                 (0x200U)
#define USART_CTL_CLRCCONRX_SHIFT                (9U)
#define USART_CTL_CLRCCONRX(x)                   (((uint32_t)(((uint32_t)(x)) << USART_CTL_CLRCCONRX_SHIFT)) & USART_CTL_CLRCCONRX_MASK)
#define USART_CTL_AUTOBAUD_MASK                  (0x10000U)
#define USART_CTL_AUTOBAUD_SHIFT                 (16U)
#define USART_CTL_AUTOBAUD(x)                    (((uint32_t)(((uint32_t)(x)) << USART_CTL_AUTOBAUD_SHIFT)) & USART_CTL_AUTOBAUD_MASK)
/*! @} */

/*! @name STAT - USART Status register. The complete status value can be read here. Writing ones clears some bits in the register. Some bits can be cleared by writing a 1 to them. */
/*! @{ */
#define USART_STAT_RXRDY_MASK                    (0x1U)
#define USART_STAT_RXRDY_SHIFT                   (0U)
#define USART_STAT_RXRDY(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXRDY_SHIFT)) & USART_STAT_RXRDY_MASK)
#define USART_STAT_RXIDLE_MASK                   (0x2U)
#define USART_STAT_RXIDLE_SHIFT                  (1U)
#define USART_STAT_RXIDLE(x)                     (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXIDLE_SHIFT)) & USART_STAT_RXIDLE_MASK)
#define USART_STAT_TXRDY_MASK                    (0x4U)
#define USART_STAT_TXRDY_SHIFT                   (2U)
#define USART_STAT_TXRDY(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_TXRDY_SHIFT)) & USART_STAT_TXRDY_MASK)
#define USART_STAT_TXIDLE_MASK                   (0x8U)
#define USART_STAT_TXIDLE_SHIFT                  (3U)
#define USART_STAT_TXIDLE(x)                     (((uint32_t)(((uint32_t)(x)) << USART_STAT_TXIDLE_SHIFT)) & USART_STAT_TXIDLE_MASK)
#define USART_STAT_CTS_MASK                      (0x10U)
#define USART_STAT_CTS_SHIFT                     (4U)
#define USART_STAT_CTS(x)                        (((uint32_t)(((uint32_t)(x)) << USART_STAT_CTS_SHIFT)) & USART_STAT_CTS_MASK)
#define USART_STAT_DELTACTS_MASK                 (0x20U)
#define USART_STAT_DELTACTS_SHIFT                (5U)
#define USART_STAT_DELTACTS(x)                   (((uint32_t)(((uint32_t)(x)) << USART_STAT_DELTACTS_SHIFT)) & USART_STAT_DELTACTS_MASK)
#define USART_STAT_TXDISSTAT_MASK                (0x40U)
#define USART_STAT_TXDISSTAT_SHIFT               (6U)
#define USART_STAT_TXDISSTAT(x)                  (((uint32_t)(((uint32_t)(x)) << USART_STAT_TXDISSTAT_SHIFT)) & USART_STAT_TXDISSTAT_MASK)
#define USART_STAT_OVERRUNINT_MASK               (0x100U)
#define USART_STAT_OVERRUNINT_SHIFT              (8U)
#define USART_STAT_OVERRUNINT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_OVERRUNINT_SHIFT)) & USART_STAT_OVERRUNINT_MASK)
#define USART_STAT_RXBRK_MASK                    (0x400U)
#define USART_STAT_RXBRK_SHIFT                   (10U)
#define USART_STAT_RXBRK(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXBRK_SHIFT)) & USART_STAT_RXBRK_MASK)
#define USART_STAT_DELTARXBRK_MASK               (0x800U)
#define USART_STAT_DELTARXBRK_SHIFT              (11U)
#define USART_STAT_DELTARXBRK(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_DELTARXBRK_SHIFT)) & USART_STAT_DELTARXBRK_MASK)
#define USART_STAT_START_MASK                    (0x1000U)
#define USART_STAT_START_SHIFT                   (12U)
#define USART_STAT_START(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_START_SHIFT)) & USART_STAT_START_MASK)
#define USART_STAT_FRAMERRINT_MASK               (0x2000U)
#define USART_STAT_FRAMERRINT_SHIFT              (13U)
#define USART_STAT_FRAMERRINT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_FRAMERRINT_SHIFT)) & USART_STAT_FRAMERRINT_MASK)
#define USART_STAT_PARITYERRINT_MASK             (0x4000U)
#define USART_STAT_PARITYERRINT_SHIFT            (14U)
#define USART_STAT_PARITYERRINT(x)               (((uint32_t)(((uint32_t)(x)) << USART_STAT_PARITYERRINT_SHIFT)) & USART_STAT_PARITYERRINT_MASK)
#define USART_STAT_RXNOISEINT_MASK               (0x8000U)
#define USART_STAT_RXNOISEINT_SHIFT              (15U)
#define USART_STAT_RXNOISEINT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXNOISEINT_SHIFT)) & USART_STAT_RXNOISEINT_MASK)
#define USART_STAT_ABERR_MASK                    (0x10000U)
#define USART_STAT_ABERR_SHIFT                   (16U)
#define USART_STAT_ABERR(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_ABERR_SHIFT)) & USART_STAT_ABERR_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set. */
/*! @{ */
#define USART_INTENSET_RXRDYEN_MASK              (0x1U)
#define USART_INTENSET_RXRDYEN_SHIFT             (0U)
#define USART_INTENSET_RXRDYEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_RXRDYEN_SHIFT)) & USART_INTENSET_RXRDYEN_MASK)
#define USART_INTENSET_TXRDYEN_MASK              (0x4U)
#define USART_INTENSET_TXRDYEN_SHIFT             (2U)
#define USART_INTENSET_TXRDYEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_TXRDYEN_SHIFT)) & USART_INTENSET_TXRDYEN_MASK)
#define USART_INTENSET_TXIDLEEN_MASK             (0x8U)
#define USART_INTENSET_TXIDLEEN_SHIFT            (3U)
#define USART_INTENSET_TXIDLEEN(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_TXIDLEEN_SHIFT)) & USART_INTENSET_TXIDLEEN_MASK)
#define USART_INTENSET_DELTACTSEN_MASK           (0x20U)
#define USART_INTENSET_DELTACTSEN_SHIFT          (5U)
#define USART_INTENSET_DELTACTSEN(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_DELTACTSEN_SHIFT)) & USART_INTENSET_DELTACTSEN_MASK)
#define USART_INTENSET_TXDISEN_MASK              (0x40U)
#define USART_INTENSET_TXDISEN_SHIFT             (6U)
#define USART_INTENSET_TXDISEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_TXDISEN_SHIFT)) & USART_INTENSET_TXDISEN_MASK)
#define USART_INTENSET_OVERRUNEN_MASK            (0x100U)
#define USART_INTENSET_OVERRUNEN_SHIFT           (8U)
#define USART_INTENSET_OVERRUNEN(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_OVERRUNEN_SHIFT)) & USART_INTENSET_OVERRUNEN_MASK)
#define USART_INTENSET_DELTARXBRKEN_MASK         (0x800U)
#define USART_INTENSET_DELTARXBRKEN_SHIFT        (11U)
#define USART_INTENSET_DELTARXBRKEN(x)           (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_DELTARXBRKEN_SHIFT)) & USART_INTENSET_DELTARXBRKEN_MASK)
#define USART_INTENSET_STARTEN_MASK              (0x1000U)
#define USART_INTENSET_STARTEN_SHIFT             (12U)
#define USART_INTENSET_STARTEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_STARTEN_SHIFT)) & USART_INTENSET_STARTEN_MASK)
#define USART_INTENSET_FRAMERREN_MASK            (0x2000U)
#define USART_INTENSET_FRAMERREN_SHIFT           (13U)
#define USART_INTENSET_FRAMERREN(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_FRAMERREN_SHIFT)) & USART_INTENSET_FRAMERREN_MASK)
#define USART_INTENSET_PARITYERREN_MASK          (0x4000U)
#define USART_INTENSET_PARITYERREN_SHIFT         (14U)
#define USART_INTENSET_PARITYERREN(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_PARITYERREN_SHIFT)) & USART_INTENSET_PARITYERREN_MASK)
#define USART_INTENSET_RXNOISEEN_MASK            (0x8000U)
#define USART_INTENSET_RXNOISEEN_SHIFT           (15U)
#define USART_INTENSET_RXNOISEEN(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_RXNOISEEN_SHIFT)) & USART_INTENSET_RXNOISEEN_MASK)
#define USART_INTENSET_ABERREN_MASK              (0x10000U)
#define USART_INTENSET_ABERREN_SHIFT             (16U)
#define USART_INTENSET_ABERREN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_ABERREN_SHIFT)) & USART_INTENSET_ABERREN_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared. */
/*! @{ */
#define USART_INTENCLR_RXRDYCLR_MASK             (0x1U)
#define USART_INTENCLR_RXRDYCLR_SHIFT            (0U)
#define USART_INTENCLR_RXRDYCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_RXRDYCLR_SHIFT)) & USART_INTENCLR_RXRDYCLR_MASK)
#define USART_INTENCLR_TXRDYCLR_MASK             (0x4U)
#define USART_INTENCLR_TXRDYCLR_SHIFT            (2U)
#define USART_INTENCLR_TXRDYCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_TXRDYCLR_SHIFT)) & USART_INTENCLR_TXRDYCLR_MASK)
#define USART_INTENCLR_TXIDLECLR_MASK            (0x8U)
#define USART_INTENCLR_TXIDLECLR_SHIFT           (3U)
#define USART_INTENCLR_TXIDLECLR(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_TXIDLECLR_SHIFT)) & USART_INTENCLR_TXIDLECLR_MASK)
#define USART_INTENCLR_DELTACTSCLR_MASK          (0x20U)
#define USART_INTENCLR_DELTACTSCLR_SHIFT         (5U)
#define USART_INTENCLR_DELTACTSCLR(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_DELTACTSCLR_SHIFT)) & USART_INTENCLR_DELTACTSCLR_MASK)
#define USART_INTENCLR_TXDISINTCLR_MASK          (0x40U)
#define USART_INTENCLR_TXDISINTCLR_SHIFT         (6U)
#define USART_INTENCLR_TXDISINTCLR(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_TXDISINTCLR_SHIFT)) & USART_INTENCLR_TXDISINTCLR_MASK)
#define USART_INTENCLR_OVERRUNCLR_MASK           (0x100U)
#define USART_INTENCLR_OVERRUNCLR_SHIFT          (8U)
#define USART_INTENCLR_OVERRUNCLR(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_OVERRUNCLR_SHIFT)) & USART_INTENCLR_OVERRUNCLR_MASK)
#define USART_INTENCLR_DELTARXBRKCLR_MASK        (0x800U)
#define USART_INTENCLR_DELTARXBRKCLR_SHIFT       (11U)
#define USART_INTENCLR_DELTARXBRKCLR(x)          (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_DELTARXBRKCLR_SHIFT)) & USART_INTENCLR_DELTARXBRKCLR_MASK)
#define USART_INTENCLR_STARTCLR_MASK             (0x1000U)
#define USART_INTENCLR_STARTCLR_SHIFT            (12U)
#define USART_INTENCLR_STARTCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_STARTCLR_SHIFT)) & USART_INTENCLR_STARTCLR_MASK)
#define USART_INTENCLR_FRAMERRCLR_MASK           (0x2000U)
#define USART_INTENCLR_FRAMERRCLR_SHIFT          (13U)
#define USART_INTENCLR_FRAMERRCLR(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_FRAMERRCLR_SHIFT)) & USART_INTENCLR_FRAMERRCLR_MASK)
#define USART_INTENCLR_PARITYERRCLR_MASK         (0x4000U)
#define USART_INTENCLR_PARITYERRCLR_SHIFT        (14U)
#define USART_INTENCLR_PARITYERRCLR(x)           (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_PARITYERRCLR_SHIFT)) & USART_INTENCLR_PARITYERRCLR_MASK)
#define USART_INTENCLR_RXNOISECLR_MASK           (0x8000U)
#define USART_INTENCLR_RXNOISECLR_SHIFT          (15U)
#define USART_INTENCLR_RXNOISECLR(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_RXNOISECLR_SHIFT)) & USART_INTENCLR_RXNOISECLR_MASK)
#define USART_INTENCLR_ABERRCLR_MASK             (0x10000U)
#define USART_INTENCLR_ABERRCLR_SHIFT            (16U)
#define USART_INTENCLR_ABERRCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_ABERRCLR_SHIFT)) & USART_INTENCLR_ABERRCLR_MASK)
/*! @} */

/*! @name RXDAT - Receiver Data register. Contains the last character received. */
/*! @{ */
#define USART_RXDAT_RXDAT_MASK                   (0x1FFU)
#define USART_RXDAT_RXDAT_SHIFT                  (0U)
#define USART_RXDAT_RXDAT(x)                     (((uint32_t)(((uint32_t)(x)) << USART_RXDAT_RXDAT_SHIFT)) & USART_RXDAT_RXDAT_MASK)
/*! @} */

/*! @name RXDATSTAT - Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows DMA or software to recover incoming data and status together. */
/*! @{ */
#define USART_RXDATSTAT_RXDAT_MASK               (0x1FFU)
#define USART_RXDATSTAT_RXDAT_SHIFT              (0U)
#define USART_RXDATSTAT_RXDAT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_RXDAT_SHIFT)) & USART_RXDATSTAT_RXDAT_MASK)
#define USART_RXDATSTAT_FRAMERR_MASK             (0x2000U)
#define USART_RXDATSTAT_FRAMERR_SHIFT            (13U)
#define USART_RXDATSTAT_FRAMERR(x)               (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_FRAMERR_SHIFT)) & USART_RXDATSTAT_FRAMERR_MASK)
#define USART_RXDATSTAT_PARITYERR_MASK           (0x4000U)
#define USART_RXDATSTAT_PARITYERR_SHIFT          (14U)
#define USART_RXDATSTAT_PARITYERR(x)             (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_PARITYERR_SHIFT)) & USART_RXDATSTAT_PARITYERR_MASK)
#define USART_RXDATSTAT_RXNOISE_MASK             (0x8000U)
#define USART_RXDATSTAT_RXNOISE_SHIFT            (15U)
#define USART_RXDATSTAT_RXNOISE(x)               (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_RXNOISE_SHIFT)) & USART_RXDATSTAT_RXNOISE_MASK)
/*! @} */

/*! @name TXDAT - Transmit Data register. Data to be transmitted is written here. */
/*! @{ */
#define USART_TXDAT_TXDAT_MASK                   (0x1FFU)
#define USART_TXDAT_TXDAT_SHIFT                  (0U)
#define USART_TXDAT_TXDAT(x)                     (((uint32_t)(((uint32_t)(x)) << USART_TXDAT_TXDAT_SHIFT)) & USART_TXDAT_TXDAT_MASK)
/*! @} */

/*! @name BRG - Baud Rate Generator register. 16-bit integer baud rate divisor value. */
/*! @{ */
#define USART_BRG_BRGVAL_MASK                    (0xFFFFU)
#define USART_BRG_BRGVAL_SHIFT                   (0U)
#define USART_BRG_BRGVAL(x)                      (((uint32_t)(((uint32_t)(x)) << USART_BRG_BRGVAL_SHIFT)) & USART_BRG_BRGVAL_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status register. Reflects interrupts that are currently enabled. */
/*! @{ */
#define USART_INTSTAT_RXRDY_MASK                 (0x1U)
#define USART_INTSTAT_RXRDY_SHIFT                (0U)
#define USART_INTSTAT_RXRDY(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_RXRDY_SHIFT)) & USART_INTSTAT_RXRDY_MASK)
#define USART_INTSTAT_TXRDY_MASK                 (0x4U)
#define USART_INTSTAT_TXRDY_SHIFT                (2U)
#define USART_INTSTAT_TXRDY(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_TXRDY_SHIFT)) & USART_INTSTAT_TXRDY_MASK)
#define USART_INTSTAT_TXIDLE_MASK                (0x8U)
#define USART_INTSTAT_TXIDLE_SHIFT               (3U)
#define USART_INTSTAT_TXIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_TXIDLE_SHIFT)) & USART_INTSTAT_TXIDLE_MASK)
#define USART_INTSTAT_DELTACTS_MASK              (0x20U)
#define USART_INTSTAT_DELTACTS_SHIFT             (5U)
#define USART_INTSTAT_DELTACTS(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_DELTACTS_SHIFT)) & USART_INTSTAT_DELTACTS_MASK)
#define USART_INTSTAT_TXDISINT_MASK              (0x40U)
#define USART_INTSTAT_TXDISINT_SHIFT             (6U)
#define USART_INTSTAT_TXDISINT(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_TXDISINT_SHIFT)) & USART_INTSTAT_TXDISINT_MASK)
#define USART_INTSTAT_OVERRUNINT_MASK            (0x100U)
#define USART_INTSTAT_OVERRUNINT_SHIFT           (8U)
#define USART_INTSTAT_OVERRUNINT(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_OVERRUNINT_SHIFT)) & USART_INTSTAT_OVERRUNINT_MASK)
#define USART_INTSTAT_DELTARXBRK_MASK            (0x800U)
#define USART_INTSTAT_DELTARXBRK_SHIFT           (11U)
#define USART_INTSTAT_DELTARXBRK(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_DELTARXBRK_SHIFT)) & USART_INTSTAT_DELTARXBRK_MASK)
#define USART_INTSTAT_START_MASK                 (0x1000U)
#define USART_INTSTAT_START_SHIFT                (12U)
#define USART_INTSTAT_START(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_START_SHIFT)) & USART_INTSTAT_START_MASK)
#define USART_INTSTAT_FRAMERRINT_MASK            (0x2000U)
#define USART_INTSTAT_FRAMERRINT_SHIFT           (13U)
#define USART_INTSTAT_FRAMERRINT(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_FRAMERRINT_SHIFT)) & USART_INTSTAT_FRAMERRINT_MASK)
#define USART_INTSTAT_PARITYERRINT_MASK          (0x4000U)
#define USART_INTSTAT_PARITYERRINT_SHIFT         (14U)
#define USART_INTSTAT_PARITYERRINT(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_PARITYERRINT_SHIFT)) & USART_INTSTAT_PARITYERRINT_MASK)
#define USART_INTSTAT_RXNOISEINT_MASK            (0x8000U)
#define USART_INTSTAT_RXNOISEINT_SHIFT           (15U)
#define USART_INTSTAT_RXNOISEINT(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_RXNOISEINT_SHIFT)) & USART_INTSTAT_RXNOISEINT_MASK)
#define USART_INTSTAT_ABERR_MASK                 (0x10000U)
#define USART_INTSTAT_ABERR_SHIFT                (16U)
#define USART_INTSTAT_ABERR(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_ABERR_SHIFT)) & USART_INTSTAT_ABERR_MASK)
/*! @} */

/*! @name OSR - Oversample selection register for asynchronous communication. */
/*! @{ */
#define USART_OSR_OSRVAL_MASK                    (0xFU)
#define USART_OSR_OSRVAL_SHIFT                   (0U)
#define USART_OSR_OSRVAL(x)                      (((uint32_t)(((uint32_t)(x)) << USART_OSR_OSRVAL_SHIFT)) & USART_OSR_OSRVAL_MASK)
/*! @} */

/*! @name ADDR - Address register for automatic address matching. */
/*! @{ */
#define USART_ADDR_ADDRESS_MASK                  (0xFFU)
#define USART_ADDR_ADDRESS_SHIFT                 (0U)
#define USART_ADDR_ADDRESS(x)                    (((uint32_t)(((uint32_t)(x)) << USART_ADDR_ADDRESS_SHIFT)) & USART_ADDR_ADDRESS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USART_Register_Masks */


/* USART - Peripheral instance base addresses */
/** Peripheral USART0 base address */
#define USART0_BASE                              (0x40064000u)
/** Peripheral USART0 base pointer */
#define USART0                                   ((USART_Type *)USART0_BASE)
/** Peripheral USART1 base address */
#define USART1_BASE                              (0x40068000u)
/** Peripheral USART1 base pointer */
#define USART1                                   ((USART_Type *)USART1_BASE)
/** Array initializer of USART peripheral base addresses */
#define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE }
/** Array initializer of USART peripheral base pointers */
#define USART_BASE_PTRS                          { USART0, USART1 }
/** Interrupt vectors for the USART peripheral type */
#define USART_IRQS                               { USART0_IRQn, USART1_IRQn }

/*!
 * @}
 */ /* end of group USART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WKT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKT_Peripheral_Access_Layer WKT Peripheral Access Layer
 * @{
 */

/** WKT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Self wake-up timer control register., offset: 0x0 */
       uint8_t RESERVED_0[8];
  __IO uint32_t COUNT;                             /**< Counter register., offset: 0xC */
} WKT_Type;

/* ----------------------------------------------------------------------------
   -- WKT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKT_Register_Masks WKT Register Masks
 * @{
 */

/*! @name CTRL - Self wake-up timer control register. */
/*! @{ */
#define WKT_CTRL_CLKSEL_MASK                     (0x1U)
#define WKT_CTRL_CLKSEL_SHIFT                    (0U)
#define WKT_CTRL_CLKSEL(x)                       (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_CLKSEL_SHIFT)) & WKT_CTRL_CLKSEL_MASK)
#define WKT_CTRL_ALARMFLAG_MASK                  (0x2U)
#define WKT_CTRL_ALARMFLAG_SHIFT                 (1U)
#define WKT_CTRL_ALARMFLAG(x)                    (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_ALARMFLAG_SHIFT)) & WKT_CTRL_ALARMFLAG_MASK)
#define WKT_CTRL_CLEARCTR_MASK                   (0x4U)
#define WKT_CTRL_CLEARCTR_SHIFT                  (2U)
#define WKT_CTRL_CLEARCTR(x)                     (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_CLEARCTR_SHIFT)) & WKT_CTRL_CLEARCTR_MASK)
#define WKT_CTRL_SEL_EXTCLK_MASK                 (0x8U)
#define WKT_CTRL_SEL_EXTCLK_SHIFT                (3U)
#define WKT_CTRL_SEL_EXTCLK(x)                   (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_SEL_EXTCLK_SHIFT)) & WKT_CTRL_SEL_EXTCLK_MASK)
/*! @} */

/*! @name COUNT - Counter register. */
/*! @{ */
#define WKT_COUNT_VALUE_MASK                     (0xFFFFFFFFU)
#define WKT_COUNT_VALUE_SHIFT                    (0U)
#define WKT_COUNT_VALUE(x)                       (((uint32_t)(((uint32_t)(x)) << WKT_COUNT_VALUE_SHIFT)) & WKT_COUNT_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WKT_Register_Masks */


/* WKT - Peripheral instance base addresses */
/** Peripheral WKT base address */
#define WKT_BASE                                 (0x40008000u)
/** Peripheral WKT base pointer */
#define WKT                                      ((WKT_Type *)WKT_BASE)
/** Array initializer of WKT peripheral base addresses */
#define WKT_BASE_ADDRS                           { WKT_BASE }
/** Array initializer of WKT peripheral base pointers */
#define WKT_BASE_PTRS                            { WKT }
/** Interrupt vectors for the WKT peripheral type */
#define WKT_IRQS                                 { WKT_IRQn }

/*!
 * @}
 */ /* end of group WKT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WWDT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WWDT_Peripheral_Access_Layer WWDT Peripheral Access Layer
 * @{
 */

/** WWDT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MOD;                               /**< Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer., offset: 0x0 */
  __IO uint32_t TC;                                /**< Watchdog timer constant register. This 24-bit register determines the time-out value., offset: 0x4 */
  __O  uint32_t FEED;                              /**< Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in TC., offset: 0x8 */
  __I  uint32_t TV;                                /**< Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer., offset: 0xC */
       uint8_t RESERVED_0[4];
  __IO uint32_t WARNINT;                           /**< Watchdog Warning Interrupt compare value., offset: 0x14 */
  __IO uint32_t WINDOW;                            /**< Watchdog Window compare value., offset: 0x18 */
} WWDT_Type;

/* ----------------------------------------------------------------------------
   -- WWDT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WWDT_Register_Masks WWDT Register Masks
 * @{
 */

/*! @name MOD - Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer. */
/*! @{ */
#define WWDT_MOD_WDEN_MASK                       (0x1U)
#define WWDT_MOD_WDEN_SHIFT                      (0U)
#define WWDT_MOD_WDEN(x)                         (((uint32_t)(((uint32_t)(x)) << WWDT_MOD_WDEN_SHIFT)) & WWDT_MOD_WDEN_MASK)
#define WWDT_MOD_WDRESET_MASK                    (0x2U)
#define WWDT_MOD_WDRESET_SHIFT                   (1U)
#define WWDT_MOD_WDRESET(x)                      (((uint32_t)(((uint32_t)(x)) << WWDT_MOD_WDRESET_SHIFT)) & WWDT_MOD_WDRESET_MASK)
#define WWDT_MOD_WDTOF_MASK                      (0x4U)
#define WWDT_MOD_WDTOF_SHIFT                     (2U)
#define WWDT_MOD_WDTOF(x)                        (((uint32_t)(((uint32_t)(x)) << WWDT_MOD_WDTOF_SHIFT)) & WWDT_MOD_WDTOF_MASK)
#define WWDT_MOD_WDINT_MASK                      (0x8U)
#define WWDT_MOD_WDINT_SHIFT                     (3U)
#define WWDT_MOD_WDINT(x)                        (((uint32_t)(((uint32_t)(x)) << WWDT_MOD_WDINT_SHIFT)) & WWDT_MOD_WDINT_MASK)
#define WWDT_MOD_WDPROTECT_MASK                  (0x10U)
#define WWDT_MOD_WDPROTECT_SHIFT                 (4U)
#define WWDT_MOD_WDPROTECT(x)                    (((uint32_t)(((uint32_t)(x)) << WWDT_MOD_WDPROTECT_SHIFT)) & WWDT_MOD_WDPROTECT_MASK)
#define WWDT_MOD_LOCK_MASK                       (0x20U)
#define WWDT_MOD_LOCK_SHIFT                      (5U)
#define WWDT_MOD_LOCK(x)                         (((uint32_t)(((uint32_t)(x)) << WWDT_MOD_LOCK_SHIFT)) & WWDT_MOD_LOCK_MASK)
/*! @} */

/*! @name TC - Watchdog timer constant register. This 24-bit register determines the time-out value. */
/*! @{ */
#define WWDT_TC_COUNT_MASK                       (0xFFFFFFU)
#define WWDT_TC_COUNT_SHIFT                      (0U)
#define WWDT_TC_COUNT(x)                         (((uint32_t)(((uint32_t)(x)) << WWDT_TC_COUNT_SHIFT)) & WWDT_TC_COUNT_MASK)
/*! @} */

/*! @name FEED - Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in TC. */
/*! @{ */
#define WWDT_FEED_FEED_MASK                      (0xFFU)
#define WWDT_FEED_FEED_SHIFT                     (0U)
#define WWDT_FEED_FEED(x)                        (((uint32_t)(((uint32_t)(x)) << WWDT_FEED_FEED_SHIFT)) & WWDT_FEED_FEED_MASK)
/*! @} */

/*! @name TV - Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer. */
/*! @{ */
#define WWDT_TV_COUNT_MASK                       (0xFFFFFFU)
#define WWDT_TV_COUNT_SHIFT                      (0U)
#define WWDT_TV_COUNT(x)                         (((uint32_t)(((uint32_t)(x)) << WWDT_TV_COUNT_SHIFT)) & WWDT_TV_COUNT_MASK)
/*! @} */

/*! @name WARNINT - Watchdog Warning Interrupt compare value. */
/*! @{ */
#define WWDT_WARNINT_WARNINT_MASK                (0x3FFU)
#define WWDT_WARNINT_WARNINT_SHIFT               (0U)
#define WWDT_WARNINT_WARNINT(x)                  (((uint32_t)(((uint32_t)(x)) << WWDT_WARNINT_WARNINT_SHIFT)) & WWDT_WARNINT_WARNINT_MASK)
/*! @} */

/*! @name WINDOW - Watchdog Window compare value. */
/*! @{ */
#define WWDT_WINDOW_WINDOW_MASK                  (0xFFFFFFU)
#define WWDT_WINDOW_WINDOW_SHIFT                 (0U)
#define WWDT_WINDOW_WINDOW(x)                    (((uint32_t)(((uint32_t)(x)) << WWDT_WINDOW_WINDOW_SHIFT)) & WWDT_WINDOW_WINDOW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WWDT_Register_Masks */


/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT base address */
#define WWDT_BASE                                (0x40000000u)
/** Peripheral WWDT base pointer */
#define WWDT                                     ((WWDT_Type *)WWDT_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT }

/*!
 * @}
 */ /* end of group WWDT_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* _LPC804_H_ */

