/*
 * ee_afgangsprojekt_source_code
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"
#include "fsl_debug_console.h"
//#include "fsl_device_registers.h" 
#include "fsl_gpio.h"
#include "fsl_i2c.h"
#include "fsl_usart.h"
//#include "fsl_adc.h"
//#include "fsl_power.h"
#include "fsl_systick.h"
#include "fsl_ctimer.h"
#include "bms.h" 
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
  BMS_Init(BMS); 
  
  /* Set systick reload value to generate 1ms interrupt */
  SysTick_Config(SystemCoreClock / 1000U);
  
  /* Communication protocols demos */ 
  printf("Battery Management System v0.2 booting...\r\nBoot complete!\r\n\r\n");   
  printf("I2C transfer commencing...\r\nSending data to slave...\r\n"); 
  I2C_Send(BMS, 0x00, 0xAB);
  printf("Sent data 0xAB to register 0x00\r\n\r\n"); 
  
  printf("CTIMER match is blinking blue LED.\r\n");  
  printf("CTIMER modulating PWM signal with 50 percent duty cycle and 1hz.\r\n");
  printf("Red LED blinking means program idle.\r\n\r\n"); 
  
  while (1) {
    /* Delay 100 ms */
    SysTick_DelayTicks(100U);
    
    /* Program idle indicator */
    GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN3);
    
    SysTick_DelayTicks(2000U); 
        
    printf("Cell 1 voltage: %d.%.3dV\r\n", readCellVoltage(BMS, 1) / 1000, readCellVoltage(BMS, 1) % 1000);     
    printf("Cell 2 voltage: %d.%.3dV\r\n", readCellVoltage(BMS, 2) / 1000, readCellVoltage(BMS, 2) % 1000);     
    printf("Cell 3 voltage: %d.%.3dV\r\n", readCellVoltage(BMS, 3) / 1000, readCellVoltage(BMS, 3) % 1000);     
    printf("Cell 4 voltage: %d.%.3dV\r\n\r\n", readCellVoltage(BMS, 4) / 1000, readCellVoltage(BMS, 4) % 1000);     

    printf("Pack voltage: %d.%.3dV\r\n\r\n", readPackVoltage(BMS) / 1000, readPackVoltage(BMS) % 1000);
    
    printf("Current draw: %dmA\r\n\r\n", readCurrentDraw(BMS));
    
    SysTick_DelayTicks(2000U);
    balanceCell(BMS, 1);
    SysTick_DelayTicks(2000U); 
    balanceCell(BMS, 2);
    SysTick_DelayTicks(2000U); 
    balanceCell(BMS, 3);
    SysTick_DelayTicks(2000U); 
    balanceCell(BMS, 4);    
  }
}
