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
  /* Board & BMS peripherals init */
  BOARD_InitPins();
  BOARD_InitBootClocks();
  UART_Init();
  
  printf("\033[2J");
  printf("\033[0;0H"); 
  printf("Battery Management System v1.2 booting...\r\n");

  GPIO_Init(); 
  I2C_Init(); 
  TIMER_Init(); 
  SysTick_Init(1000);     
  printf("Boot complete!\r\n\r\n"); 
  
#ifdef I2CBMS  
  BMS_Init(BMS); 
  printf("BQ76920 BMS initializing...\r\n"); 
  
  printf("LED blinking, indicating system is powered on.\r\n\r\n");
  
  uint8_t fetIO = 1; 
  uint32_t uAhRemaining = CELL_CAPACITY*1000;
  
  while (1) {    
    uint16_t vCell1 = readCellVoltage(BMS, 1);
    uint16_t vCell2 = readCellVoltage(BMS, 2);
    uint16_t vCell3 = readCellVoltage(BMS, 3);
    uint16_t vCell4 = readCellVoltage(BMS, 4);
    printf("Cell 1 voltage: %d.%.3dV\r\n", vCell1 / 1000, vCell1 % 1000);     
    printf("Cell 2 voltage: %d.%.3dV\r\n", vCell2 / 1000, vCell2 % 1000);     
    printf("Cell 3 voltage: %d.%.3dV\r\n", vCell3 / 1000, vCell3 % 1000);     
    printf("Cell 4 voltage: %d.%.3dV\r\n", vCell4 / 1000, vCell4 % 1000);
            
    uint16_t vPack = readPackVoltage(BMS);
    printf("Pack voltage: %d.%.3dV\r\n", vPack / 1000, vPack % 1000);
    
    uint16_t packPercentage = calculatePackPercentageFromVoltage(vPack); 
    printf("Pack percentage: %d percent  \r\n", packPercentage); 
    
    uint16_t current = readCurrentDraw(BMS); 
    printf("Current draw: %d.%.4dA\r\n", current / 10000, current % 10000);
    
    SysTick_DelayTicks(250U);
    uint16_t current2 = readCurrentDraw(BMS); 
    
    uint32_t uAhUsed = calculateUsedCapacity(current*100, current*100);
    uAhRemaining = uAhRemaining - uAhUsed;
    printf("Capacity remaining: %d.%.3d mAh\r\n", uAhRemaining / 1000, uAhRemaining % 1000);
    
    uint16_t tempLM = readTemp(BMS); 
    printf("LM75 temperature: %dC\r\n\r\n", readTemp(BMS)); 
    printf("\033[J");
        
    if ((vCell1 == BALANCE_VOLTAGE) && (vCell2 == BALANCE_VOLTAGE) && (vCell3 == BALANCE_VOLTAGE) && (vCell4 == BALANCE_VOLTAGE)) {
      fetControl(BMS, 'B', 0); 
      balanceCell(BMS, 1, 0); 
      printf("Battery charged!\r\n"); 
    } else if ((vCell1 > BALANCE_VOLTAGE) && (vCell1 >= vCell2) && (vCell1 >= vCell3) && (vCell1 >= vCell4)) {
      fetIO = 0; 
      fetControl(BMS, 'B', fetIO); 
      balanceCell(BMS, 1, 1); 
      printf("Balancing cell 1!\r\n"); 
      if ((vCell1 <= vCell2) && (vCell1 <= vCell3) && (vCell1 <= vCell4)) {
        balanceCell(BMS, 1, 0); 
      }
    } else if ((vCell2 > BALANCE_VOLTAGE) && (vCell2 >= vCell1) && (vCell2 >= vCell3) && (vCell2 >= vCell4)) {
      fetIO = 0;
      fetControl(BMS, 'B', fetIO); 
      balanceCell(BMS, 2, 1); 
      printf("Balancing cell 2!\r\n"); 
      if ((vCell2 <= vCell1) && (vCell2 <= vCell3) && (vCell2 <= vCell4)) {
        balanceCell(BMS, 2, 0); 
      }
    } else if ((vCell3 > BALANCE_VOLTAGE) && (vCell3 >= vCell1) && (vCell3 >= vCell2) && (vCell3 >= vCell4)) {
      fetIO = 0; 
      fetControl(BMS, 'B', fetIO); 
      balanceCell(BMS, 3, 1); 
      printf("Balancing cell 3!\r\n"); 
      if ((vCell3 <= vCell1) && (vCell3 <= vCell2) && (vCell3 <= vCell4)) {
        balanceCell(BMS, 3, 0); 
      }
    } else if ((vCell4 > BALANCE_VOLTAGE) && (vCell4 >= vCell1) && (vCell4 >= vCell2) && (vCell4 >= vCell3)) {
      fetIO = 0; 
      fetControl(BMS, 'B', fetIO); 
      balanceCell(BMS, 4, 1); 
      printf("Balancing cell 4!\r\n"); 
      if ((vCell4 <= vCell1) && (vCell4 <= vCell2) && (vCell4 <= vCell3)) {
        balanceCell(BMS, 4, 0); 
      }
    } else {  
      fetIO = 1; 
      fetControl(BMS, 'B', fetIO); 
      balanceCell(BMS, 1, 0); 
    }
      
    if (fetIO) {
      printf("Both MOSFET's ON! \r\n");
    } else {
      printf("Both MOSFET's OFF!\r\n");
    }
    
    if (current >= CURRENT_DRAW_CUTOFF) {
      fetIO = 0;
      fetControl(BMS, 'B', fetIO);
      balanceCell(BMS, 1, 0); 
      printf("\r\nCurrent draw too high, turning MOSFET's OFF! Please reset to re-enable.\r\n");
      
      while(1) {
        /* Endless loop until the user reset's the BMS */
      }
    }
    
    if (tempLM >= TEMP_CUTOFF_HIGH) {
      fetIO = 0;
      fetControl(BMS, 'B', fetIO); 
      balanceCell(BMS, 1, 0); 
      printf("\r\nTemperature too high, turning MOSFET's OFF! \r\nPlease let the system cool down before further use.\r\n");
      
      while(tempLM >= TEMP_CUTOFF_LOW) {
        tempLM = readTemp(BMS); 
        printf("\rCurrent temperature: %dC, target: %dC ", tempLM, TEMP_CUTOFF_LOW-1);
        SysTick_DelayTicks(500U);
      }
      
      printf("\r\n");
      if (current <= CURRENT_DRAW_CUTOFF) {
        fetIO = 1;
      }
    }

    SysTick_DelayTicks(250U);
    printf("\033[7;0H"); 
  }
#endif
  
#ifdef ANALOGBMS
  printf("Analog BMS initializing...\r\n"); 
  
  TIMER_Init(); 
  printf("LED blinking, indicating system is powered on.\r\n");  
  
  while (1) {
    /* Temperature reading */
    uint16_t tempLM = readTemp(BMS); 
    printf("LM75 temperature: %dC\r\n\r\n", readTemp(BMS)); 
    
    if (tempLM >= TEMP_CUTOFF) {
      /* Turn off mosfets */
      printf("Temperature too high, turning MOSFET's OFF! Please reset to re-enable.\r\n");
    }    
    
    SysTick_DelayTicks(500U);
  }
#endif
}
