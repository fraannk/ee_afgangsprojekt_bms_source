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
  UART_Init();
  
  printf("Battery Management System v0.2 booting...\r\n");

  GPIO_Init(); 
  I2C_Init(); 
  TIMER_Init(); 
  BMS_Init(BMS); 
  
  /* Set systick reload value to generate 1ms interrupt */
  SysTick_Config(SystemCoreClock / 1000U);
  
  printf("Boot complete!\r\n\r\n");   
  
  printf("CTIMER match is blinking blue LED.\r\n");  
  printf("CTIMER modulating PWM signal with 50 percent duty cycle and 1hz.\r\n");
  printf("Red LED means discharge FET ON!\r\n\r\n"); 
  
  while (1) {
    GPIO_PinWrite(GPIO, BOARD_LED_PORT, BOARD_LED_PIN3, 0);
    fetControl(BMS, 'D', 1); 
    SysTick_DelayTicks(500U);     
    printf("FET on, current draw: %dmA\r\n", readCurrentDraw(BMS));
    fetControl(BMS, 'D', 0); 
    GPIO_PinWrite(GPIO, BOARD_LED_PORT, BOARD_LED_PIN3, 1);
    SysTick_DelayTicks(500U);     
    printf("FET off, current draw: %dmA\r\n\r\n", readCurrentDraw(BMS));
            
    printf("Cell 1 voltage: %d.%.3dV\r\n", readCellVoltage(BMS, 1) / 1000, readCellVoltage(BMS, 1) % 1000);     
    printf("Cell 2 voltage: %d.%.3dV\r\n", readCellVoltage(BMS, 2) / 1000, readCellVoltage(BMS, 2) % 1000);     
    printf("Cell 3 voltage: %d.%.3dV\r\n", readCellVoltage(BMS, 3) / 1000, readCellVoltage(BMS, 3) % 1000);     
    printf("Cell 4 voltage: %d.%.3dV\r\n\r\n", readCellVoltage(BMS, 4) / 1000, readCellVoltage(BMS, 4) % 1000);     

    printf("Pack voltage: %d.%.3dV\r\n", readPackVoltage(BMS) / 1000, readPackVoltage(BMS) % 1000);
    printf("Die temperature: %dC\r\n\r\n", readTemp(BMS)); 
//    printf("LM57 temperature: %dC\r\n\r\n", readTemp(BMS)); 
    
    SysTick_DelayTicks(2000U);
    printf("Balancing cell 1\r\n");
    balanceCell(BMS, 1, 1);
    SysTick_DelayTicks(2000U); 
    printf("Balancing cell 2\r\n");
    balanceCell(BMS, 2, 1);
    SysTick_DelayTicks(2000U); 
    printf("Balancing cell 3\r\n");
    balanceCell(BMS, 3, 1);
    SysTick_DelayTicks(2000U); 
    printf("Balancing cell 4\r\n\r\n");
    balanceCell(BMS, 4, 1);  
    SysTick_DelayTicks(2000U); 
    balanceCell(BMS, 4, 0);  
  }
}
