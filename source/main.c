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
#include "fsl_usart.h"
#include "fsl_systick.h"
#include "fsl_ctimer.h"
#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

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
  /* Board peripherals init */
  BOARD_InitPins();
  BOARD_InitBootClocks();
  GPIO_Init(); 
  I2C_Init(); 
  UART_Init();
  TIMER_Init(); 
  
  /* Set systick reload value to generate 1ms interrupt */
  SysTick_Config(SystemCoreClock / 1000U);
  
  printf("Battery Management System v0.2 booting...\r\nBoot complete!\r\n\r\n");   
  printf("I2C transfer commencing...\r\nSending data to slave...\r\n"); 
  I2C_Send(BMS, 0x00, 0xAB);
  printf("Sent data 0xAB to register 0x00\r\n"); 
  
  printf("Receiving data from slave...\r\n");
  printf("Cell 1 voltage: %d\r\n", I2C_Receive(BMS, 0x0D)); 
  printf("End of I2C transfer!\r\n\r\n");
  
  printf("CTIMER match is blinking blue LED.\r\n");  
  printf("CTIMER modulating PWM signal with 50 percent duty cycle and 1hz.\r\n");
  printf("Red LED blinking means program idle.\r\n"); 
  
  while (1) {
    /* Delay 100 ms */
    SysTick_DelayTicks(100U);
    GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN3);
  }
}
