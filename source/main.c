/*
 * ee_afgangsprojekt_source_code
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_i2c.h"
#include "fsl_systick.h"
#include "fsl_ctimer.h"
#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_PORT 0U
#define BOARD_LED_PIN1 11U
#define BOARD_LED_PIN2 12U
#define BOARD_LED_PIN3 13U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void) {
  /* Define the init structure for the output LED pin*/
  gpio_pin_config_t led_config = {
    kGPIO_DigitalOutput, 0,
  };
  
  /* Board pin init */
  BOARD_InitPins();
  
  /* Init output LED GPIO. */
  GPIO_PortInit(GPIO, BOARD_LED_PORT);
  GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN2, &led_config);
  GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN3, &led_config);
  
  GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN2);
  
  /* Set systick reload value to generate 1ms interrupt */
  SysTick_Config(SystemCoreClock / 1000U);
  
  /* Attach 12 MHz clock to USART0 (debug console) */
  CLOCK_Select(kUART0_Clk_From_MainClk);
  
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();
  
  printf("Battery Management System v0.2 booting...\r\n"); 
  printf("Boot complete!\r\n\r\n"); 
  
  
  
  printf("I2C transfer commencing...\r\n"); 
  I2C_Init(); 
  
  printf("Sending data to slave...\r\n");
  I2C_Send(BMS, 0x00, 0xAB);
  
  printf("Sent data 0xAB to register 0x00\r\n"); 
  printf("Receiving data from slave...\r\n");
  printf("Cell 1 voltage: %d\r\n", I2C_Receive(BMS, 0x0D)); 
  printf("End of I2C transfer.\r\n\r\n");
  
  
  
  printf("CTIMER match to blink blue LED starting...\r\n");
  TIMER_Init();
  
  printf("CTIMER modulating PWM signal with 50 percent duty cycle and 1hz.\r\n");
  printf("Red LED blinking means program idle.\r\n"); 
  
  while (1) {
    /* Delay 100 ms */
    SysTick_DelayTicks(100U);
    GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN3);
  }
}
