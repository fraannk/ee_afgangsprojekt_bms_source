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

#define I2CBMS          /* Define as I2CBMS for BQ76920 IC, or ANALOGBMS for analog BMS. */  
#define CELLCOUNT 4     /* Set cellcount number to appropiate cellcount (3-5) */
#define INTERNALTEMP 1  /* 0 for LPC804 onboard I2C temp sensor (eval), 1 for IC internal die temp */

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
 * @brief Balance on a single cell.
 *
 * @note I'ts not recommended to balance on adjacent cells, which is why this
 * function ovewrwrites previous balancing cell. 
 */
void balanceCell(uint8_t bmsAdr, uint8_t cellNumber, uint8_t io);

/*!
 * @brief Control charge or discharge fet on/off
 */
void fetControl(uint8_t bmsAdr, char fet, uint8_t io); 

/*!
 * @brief Read temperature from the BMS or LPC804 onboard LM75 (eval)
 */
uint32_t readTemp(uint8_t bmsAdr);

/*!
 * @brief Initialize BMS with appropriate settings
 */
void BMS_Init(uint8_t bmsAdr); 

#endif

#endif