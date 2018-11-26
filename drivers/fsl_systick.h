/*
 * ee_afgangsprojekt_source_code - systick.h
 * Kenneth & Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */

#ifndef _LPC_SYSTICK_H_
#define _LPC_SYSTICK_H_

#include "board.h"

void SysTick_Handler(void);

void SysTick_DelayTicks(uint32_t n);

void SysTick_Init(uint16_t msInterval); 

#endif