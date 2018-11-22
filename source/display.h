/*
 * ee_afgangsprojekt_source_code - display.h
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "fsl_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define DISPLAY 0x7C    /* Display I2C address */  

/*******************************************************************************
 * Functions
 ******************************************************************************/

void Init_Display(uint8_t displayAdr); 
   
#endif