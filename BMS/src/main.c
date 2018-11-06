/*
===============================================================================
 Name        : main.c
 Author      : Søren Bolding Frank
 Version     :
 Copyright   : $(copyright)
 Description : main definitions and functions
===============================================================================
*/
#include <stdio.h>
#include "LPC8xx.h"
#include "i2c.h"
#include "swm.h"
#include "system.h"
#include "syscon.h"
#include "uart.h"
#include "utilities.h"
#include "ctimer.h"
#include "gpio.h"

#define I2CBAUD 		100000

/* For more info, read TI's BQ769x0 datasheet */
#define BQ76920_ADDR		0x10
#define BQ76920_CONFIG		0x00

#define BUFSIZE       64

uint8_t I2CMasterBuffer[BUFSIZE];
uint8_t I2CSlaveBuffer[BUFSIZE];
uint32_t I2CReadLength, I2CWriteLength;
uint32_t tempReading;

void setup_debug_uart(void);

uint32_t getCellVoltage(int cellNumber) {
	uint32_t i;
	uint32_t cellVoltage;
	uint32_t configValue;

	WaitI2CMasterState(LPC_I2C0, I2C_STAT_MSTST_IDLE); // Wait for the master state to be idle

	/* clear buffer, then, get register reading from bq AFE */
	for ( i = 0; i < BUFSIZE; i++ )	{
		I2CMasterBuffer[i] = 0;
		I2CSlaveBuffer[i] = 0;
	}
	I2CWriteLength = 1;
	I2CReadLength = 2;
	I2CMasterBuffer[0] = BQ76920_ADDR;
	I2CMasterBuffer[1] = BQ76920_CONFIG;
	I2CmasterWriteRead( I2CMasterBuffer, I2CSlaveBuffer, I2CWriteLength, I2CReadLength );
	/* The temp reading value should reside in I2CSlaveBuffer... */
	configValue = (uint32_t)(((I2CSlaveBuffer[0]<<8) | I2CSlaveBuffer[1]) >> 5);

	/* clear buffer, then, get register reading from bq AFE */
	for ( i = 0; i < BUFSIZE; i++ )	{
		I2CMasterBuffer[i] = 0;
		I2CSlaveBuffer[i] = 0;
	}
	I2CWriteLength = 1;
	I2CReadLength = 2;
	I2CMasterBuffer[0] = BQ76920_ADDR;
	I2CMasterBuffer[1] = 0x0D;
	I2CmasterWriteRead( I2CMasterBuffer, I2CSlaveBuffer, I2CWriteLength, I2CReadLength );
	/* The temp reading value should reside in I2CSlaveBuffer... */
	cellVoltage = (uint32_t)(((I2CSlaveBuffer[0]<<8) | I2CSlaveBuffer[1]) >> 5);

	return cellVoltage;
}

void delayUs(uint32_t delayInUs) {
	// Timer counting setup
	LPC_SYSCON->PRESETCTRL1 &= (CTIMER0_RST_N); 			// Reset timer
	LPC_SYSCON->PRESETCTRL1 |= ~(CTIMER0_RST_N); 			// Reset timer
	LPC_CTIMER0->PR = 0x00; 								// Set prescale to 0
	LPC_CTIMER0->MR[0] = (delayInUs * (main_clk / 2000)); 	// Set delay prefix
	LPC_CTIMER0->IR = 0x00;									// Reset interrupts
	LPC_CTIMER0->MCR = 0x03;								// Stop timer on match
	LPC_CTIMER0->TCR = 0x01;								// Start timer

	while (LPC_CTIMER0->TC & 0x1);					// Wait until delay is done
}

/*****************************************************************************
*****************************************************************************/
int main(void) {

	uint32_t i;
	
	GPIOInit();
	GPIOSetDir(0, 11, 1);
	GPIOSetBitValue(0, 11, 0);

	// Configure the debug uart (see Serial.c)
	setup_debug_uart();
	printf("\r\nBattery Management System v0.1 booting...\r\n");
	SystemCoreClockUpdate();
	printf("Main clock: %d\r\n", main_clk);
	
	// Provide main_clk as function clock to I2C0
	LPC_SYSCON->I2C0CLKSEL = FCLKSEL_MAIN_CLK;
  
	// Enable bus clocks to I2C0, SWM
	LPC_SYSCON->SYSAHBCLKCTRL0 |= (I2C0 | SWM | CTIMER0);

	ConfigSWM(I2C0_SCL, TARTET_I2CSCL);               // Use for LPC804
	ConfigSWM(I2C0_SDA, TARTET_I2CSDA);               // Use for LPC804

	// Give I2C0 a reset
	LPC_SYSCON->PRESETCTRL0 &= (I2C0_RST_N);
	LPC_SYSCON->PRESETCTRL0 |= ~(I2C0_RST_N);

	// Reset CTIMER0
	LPC_SYSCON->PRESETCTRL1 &= (CTIMER0_RST_N);
	LPC_SYSCON->PRESETCTRL1 |= ~(CTIMER0_RST_N);

	// Configure the I2C0 clock divider
	// Desired bit rate = Fscl = 100,000 Hz (1/Fscl = 10 us, 5 us low and 5 us high)
	// Use default clock high and clock low times (= 2 clocks each)
	// So 4 I2C_PCLKs = 100,000/second, or 1 I2C_PCLK = 400,000/second
	// I2C_PCLK = SystemClock = 30,000,000/second, so we divide by 30000000/400000 = 75
	// Remember, value written to DIV divides by value+1.
	// main_clk value is updated inside setup_debug_uart() already.
	LPC_I2C0->DIV = (main_clk/(4*I2CBAUD)) - 1;
	LPC_I2C0->CFG = CFG_MSTENA;

	printf("Timer value before delay: %d\r\n", LPC_CTIMER0->TC);
	delayUs(1000);
	printf("Timer value after delay: %d\r\n", LPC_CTIMER0->TC);
	printf("Boot complete, running routine...\r\n");
	printf("Timer value after boot complete: %d\r\n", LPC_CTIMER0->TC);

	while(1) {
		delayUs(5000);

		printf("Reading cell voltages...\r\n");
		int cellVoltage1 = getCellVoltage(0x01);
		int cellVoltage2 = getCellVoltage(0x02);
		int cellVoltage3 = getCellVoltage(0x03);
		int cellVoltage4 = getCellVoltage(0x04);

		if (GPIOGetPinValue(0, 11)) {
			GPIOSetBitValue(0, 11, 0);
		} else {
			GPIOSetBitValue(0, 11, 1);
		}

		printf("Cell 1: %d\r\n", cellVoltage1);
		printf("Cell 2: %d\r\n", cellVoltage2);
		printf("Cell 3: %d\r\n", cellVoltage3);
		printf("Cell 4: %d\r\n", cellVoltage4);

//		/* The temp reading value should reside in I2CSlaveBuffer... */
//		tempValue = (uint32_t)(((I2CSlaveBuffer[0]<<8) | I2CSlaveBuffer[1]) >> 5);
//		/* D10 is the sign bit */
//		if ( tempValue & 0x400 ) {
//			/* after conversion, bit 16 is the sign bit */
//			tempValue = (int32_t)(((-tempValue+1)&0x3FF) * 0.125) | 0x10000;
//		}
//		else {
//			/* Bit 7 (D10) is the polarity, 0 is Plus temperature and 1 is Minus temperature */
//			tempValue = (int32_t)(tempValue * 0.125);
//		}
	}
} // end of main

