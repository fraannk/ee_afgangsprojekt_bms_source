/*
 * The Clear BSD License
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
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

#include "fsl_gpio.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpc_gpio"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map FGPIO instance number to clock name. */
static const clock_ip_name_t s_gpioClockName[] = GPIO_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
/*******************************************************************************
* Prototypes
************ ******************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void GPIO_PortInit(GPIO_Type *base, uint32_t port)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    assert(port < ARRAY_SIZE(s_gpioClockName));

    /* Upgate the GPIO clock */
    CLOCK_EnableClock(s_gpioClockName[port]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void GPIO_PinInit(GPIO_Type *base, uint32_t port, uint32_t pin, const gpio_pin_config_t *config)
{
    if (config->pinDirection == kGPIO_DigitalInput)
    {
        base->DIR[port] &= ~(1U << pin);
    }
    else
    {
        /* Set default output value */
        if (config->outputLogic == 0U)
        {
            base->CLR[port] = (1U << pin);
        }
        else
        {
            base->SET[port] = (1U << pin);
        }
        /* Set pin direction */
        base->DIR[port] |= 1U << pin;
    }
}

void GPIO_Init(void) {
  /* Define the init structure for the output LED pin*/
  gpio_pin_config_t led_config = {
    kGPIO_DigitalOutput, 0,
  };
  
  /* Init output LED GPIO. */
  GPIO_PortInit(GPIO, BOARD_LED_PORT);
  GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN2, &led_config);
  GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN3, &led_config);
  
  GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN2);
}