/*
 * ee_afgangsprojekt_source_code - bms.c
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */

#include "bms.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/

uint32_t readCellVoltage(uint8_t bmsAdr, uint8_t cellNumber) {
  uint32_t cell = 0; 
#if CELLCOUNT == 5
  cell = I2C_Receive(bmsAdr, 0x0A + (2*cellNumber), 2);
#else
  switch (cellNumber) {
  case 3: 
    cell = I2C_Receive(bmsAdr, 0x10, 2);
    break;
  case 4:
    cell = I2C_Receive(bmsAdr, 0x14, 2);
    break;
  default: 
    cell = I2C_Receive(bmsAdr, 0x0A + (2*cellNumber), 2);
  }
#endif
  float retVal = cell;
  retVal = (retVal * 0.38) + 30;
  
  return (uint32_t)retVal; 
}

uint32_t readPackVoltage(uint8_t bmsAdr) {
  uint32_t cell[CELLCOUNT]; 
  uint32_t packVoltage = 0; 
  for (int i = 0; i < CELLCOUNT; i++) {
    cell[i] = readCellVoltage(bmsAdr, i+1); 
    packVoltage += cell[i];
  }
    
  return packVoltage;
}
