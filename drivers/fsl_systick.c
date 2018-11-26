/*
 * ee_afgangsprojekt_source_code - systick.c
 * Kenneth & Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 */

#include "fsl_systick.h"

volatile uint32_t g_systickCounter;

void SysTick_Handler(void) {
    if (g_systickCounter != 0U) { 
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n) {
    g_systickCounter = n;
    while(g_systickCounter != 0U) {
    }
}

void SysTick_Init(uint16_t msInterval) {
    SysTick_Config(SystemCoreClock / msInterval);
}