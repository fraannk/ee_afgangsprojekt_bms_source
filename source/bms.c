/*
 * ee_afgangsprojekt_source_code - bms.c
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 * Driver documentation: http://mcuxpresso.nxp.com/api_doc/dev/802/group__lpc__adc.html
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
  retVal = (retVal * 0.38) + 30; /* Datasheet formula */
  
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

uint32_t readCurrentDraw(uint8_t bmsAdr) {
  uint32_t uV = I2C_Receive(bmsAdr, 0x32, 2); 
  
  if(uV == 0x0000 || uV == 0x0001) {
    uV = 0xFFFF;
  }
  uV = 0x10000 - uV;

  float retVal = uV;
  if (retVal == 0x0001) {
    retVal = 0x0000; 
  } else {
    retVal = retVal * 8.44; /* Datasheet formula */
  }
  
  return (uint32_t)retVal; 
}

void balanceCell(uint8_t bmsAdr, uint8_t cellNumber, uint8_t io) {
  if (io) {
    if (cellNumber == CELLCOUNT) {
      I2C_Send(bmsAdr, 0x01, 0x10);
    } else {
      I2C_Send(bmsAdr, 0x01, 0x01 << (cellNumber-1));
    }
  } else {
    I2C_Send(bmsAdr, 0x01, 0x00);
  }
}

void fetControl(uint8_t bmsAdr, char fet, uint8_t io) {
  if (io == 1) {
    if (fet == 'C') {
      I2C_Send(bmsAdr, 0x05, 0x41);
    } else if (fet == 'D') {
      I2C_Send(bmsAdr, 0x05, 0x42); 
    } else if (fet == 'B') {
      I2C_Send(bmsAdr, 0x05, 0x43); 
    }
  } else {
    I2C_Send(bmsAdr, 0x05, 0x40); 
  }
}

uint32_t readTemp(uint8_t bmsAdr) {
  uint32_t temp = 0; 
#if INTERNALTEMP == 1
  temp = I2C_Receive(bmsAdr, 0x2C, 2);
  
  float tempV = temp * (float)382; /* 382uV/LSB */
  tempV /= (float)1000000; /* Divided by 100000 to convert to V */
  float temperatureC = 25.0 - ((tempV - 1.2) / 0.0042); /* Datasheet formula */ 
  return (int32_t)temperatureC; 
#else
  I2C_Send(0x48, 0x01, 0x00); 
  temp = I2C_Receive(0x48, 0x00, 2); 
  temp = (uint32_t)(temp>>5);
  /* D10 is the sign bit */
  if (temp & 0x400) {
    /* after conversion, bit 16 is the sign bit */
    temp = (int32_t)(((-temp+1)&0x3FF) * 0.125) | 0x10000;
  } else {
    /* Bit 7 (D10) is the polarity, 0 is Plus temperature and 1 is Minus temperature */
    temp = (int32_t)(temp * 0.125);
  }
  return (temp);
#endif
}

void BMS_Init(uint8_t bmsAdr) {
  I2C_Send(bmsAdr, 0x04, 0x10); 
  I2C_Send(bmsAdr, 0x0B, 0x19);
  I2C_Send(bmsAdr, 0x05, 0x40); 
}


