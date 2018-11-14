/*
 * ee_afgangsprojekt_source_code - bms.h
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */

#ifndef _BMS_H_
#define _BMS_H_

#include "fsl_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define I2CBMS //Define as I2CBMS for BQ76920 IC, or ANALOGBMS for analog BMS.  
#define CELLCOUNT 4

/*******************************************************************************
 * Functions
 ******************************************************************************/

#ifdef I2CBMS 

/*!
 * @brief Reading cell voltage from BQ76920 IC via I2C.
 *
 * @note Please set up I2C and appropriate defines in the top of this file. 
 */
uint32_t readCellVoltage(uint8_t bmsAdr, uint8_t cellNumber);

/*!
 * @brief Reading entire pack voltage from BQ76920 IC via I2C
 */
uint32_t readPackVoltage(uint8_t bmsAdr); 

/*!
 * @brief Reading current current draw from BQ76920 IC via I2C
 */
uint32_t readCurrentDraw(uint8_t bmsAdr); 

/*!
 * @brief Initialize BQ76920 IC with appropiate settings.
 *
 * @note Please change register values for your own settings. 
 */
void BMS_Init(uint8_t bmsAdr); 

#endif

#endif