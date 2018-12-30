/*
 * ee_afgangsprojekt_source_code - bms.h
 * Kenneth & Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */

#ifndef _BMS_H_
#define _BMS_H_

#include "fsl_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define ANALOGBMS          /* Define as I2CBMS for BQ76920 IC, or ANALOGBMS for analog BMS. */  
#define CELLCOUNT 4     /* Set cellcount number to appropiate cellcount (3-5) */
#define INTERNALTEMP 0  /* 0 for LPC804 onboard I2C temp sensor (eval), 1 for IC internal die temp */

#define MIN_CELL_VOLTAGE 3200
#define BALANCE_VOLTAGE 4100
#define BALANCE_STOP 4000
#define CELL_CAPACITY 2600
#define CURRENT_DRAW_CUTOFF 60000
#define TEMP_CUTOFF_HIGH 35
#define TEMP_CUTOFF_LOW 30
#define MAX_PACK_VOLTAGE (BALANCE_VOLTAGE*4)
#define MIN_PACK_VOLTAGE (MIN_CELL_VOLTAGE*4)


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
 * @brief Initialize BMS with appropriate settings
 */
void BMS_Init(uint8_t bmsAdr); 

#endif

/* COMMON FUNCTIONS */

/*!
 * @brief Read temperature from the BMS or LPC804 onboard LM75 (eval)
 */
uint32_t readTemp(uint8_t bmsAdr);

/*!
 * @brief Calculate current battery percentage based on the voltage. 
 */
uint16_t calculatePackPercentageFromVoltage(uint16_t currentVoltage);

/*!
 * @brief Calculate capacity remaining from coulomb counter. 
 */
uint32_t calculateUsedCapacity(uint32_t current1, uint32_t current2);  

#ifdef ANALOGBMS 

/*!
 * @brief Reading cell voltage from the analog BMS from the ADC's.
 *
 */
uint32_t readADCCellVoltage(uint8_t cellNumber);

/*!
 * @brief Reading entire pack voltage from the analog BMS. 
 */
uint32_t calculateADCPackVoltage(void);

/*!
 * @brief Reading current current draw from BQ76920 IC via I2C
 */
uint32_t readADCCurrentDraw(void); 

/*!
 * @brief Balance on a single cell.
 *
 */
void balanceCellGPIO(uint8_t cellNumber, uint8_t io);

/*!
 * @brief Control charge or discharge fet on/off
 */
void fetControlPWM(char fet, uint8_t io); 

#endif 

#endif