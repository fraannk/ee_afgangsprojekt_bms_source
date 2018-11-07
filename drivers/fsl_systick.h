//fsl_systick.h

#ifndef _LPC_SYSTICK_H_
#define _LPC_SYSTICK_H_

#include "board.h"

void SysTick_Handler(void);

void SysTick_DelayTicks(uint32_t n);

#endif