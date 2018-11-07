/*
 * ee_afgangsprojekt_source_code
 * Kenneth og Søren's Battery Management System
 * Copyright (c) 2018, Kenneth Lukas Petersen & Søren Bolding Frank
 * All rights reserved. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_i2c.h"
#include "fsl_systick.h"
#include "fsl_ctimer.h"
#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_PORT 0U
#define BOARD_LED_PIN1 11U
#define BOARD_LED_PIN2 12U
#define BOARD_LED_PIN3 13U

#define I2C_MASTER_BASE (I2C0_BASE)
#define I2C_MASTER_CLOCK_FREQUENCY (12000000)
#define I2C_MASTER ((I2C_Type *)I2C_MASTER_BASE)

#define I2C_MASTER_SLAVE_ADDR_7BIT 0x08U
#define I2C_BAUDRATE 100000U
#define I2C_DATA_LENGTH 33U

#define CTIMER CTIMER0                 /* Timer 0 */
#define CTIMER_MAT_OUT kCTIMER_Match_1 /* Match output 1 */
#define CTIMER_CLK_FREQ CLOCK_GetFreq(kCLOCK_CoreSysClk)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t g_master_txBuff[I2C_DATA_LENGTH];
uint8_t g_master_rxBuff[I2C_DATA_LENGTH];
volatile bool g_MasterCompletionFlag = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void) {
  /* Define the init structure for the output LED pin*/
  gpio_pin_config_t led_config = {
    kGPIO_DigitalOutput, 0,
  };
  
  /* Board pin init */
  BOARD_InitPins();
  
  /* Init output LED GPIO. */
  GPIO_PortInit(GPIO, BOARD_LED_PORT);
  GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN2, &led_config);
  GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN3, &led_config);
  
  GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN2);
  
  /* Set systick reload value to generate 1ms interrupt */
  SysTick_Config(SystemCoreClock / 1000U);
  
  /* I2C config variables */
  i2c_master_config_t masterConfig;
  
  /* CTIMER config variables */
  ctimer_config_t config;
  ctimer_match_config_t matchConfig;
  
  /* Attach 12 MHz clock to USART0 (debug console) */
  CLOCK_Select(kUART0_Clk_From_MainClk);
  /* Select the main clock as source clock of I2C0. */
  CLOCK_Select(kI2C0_Clk_From_MainClk);
  
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();
  
  printf("Battery Management System v0.2 booting...\r\n"); 
  printf("Boot complete!\r\n\r\n"); 
  
  printf("I2C transfer commencing...\r\n");
  
  /* Set up i2c master to send data to slave*/
  /* Get default I2C config */ 
  I2C_MasterGetDefaultConfig(&masterConfig);
  
  /* Change the default baudrate configuration */
  masterConfig.baudRate_Bps = I2C_BAUDRATE;
  
  /* Initialize the I2C master peripheral */
  I2C_MasterInit(I2C_MASTER, &masterConfig, I2C_MASTER_CLOCK_FREQUENCY);
  
  
  
  
  printf("Sending data to slave...\r\n");
  uint8_t registerAddress = 0x00U;
  
  /* First data in txBuff is data length of the transmiting data. */
  g_master_txBuff[0] = 0xAA;
  
  /* Send master blocking data to slave */
  I2C_MasterStart(I2C_MASTER, I2C_MASTER_SLAVE_ADDR_7BIT, kI2C_Write);
  
  /* subAddress = 0x01, data = g_master_txBuff - write to slave.
  start + slaveaddress(w) + subAddress + length of data buffer + data buffer + stop*/
  I2C_MasterWriteBlocking(I2C_MASTER, &registerAddress, 1, kI2C_TransferNoStopFlag);
  
  I2C_MasterWriteBlocking(I2C_MASTER, g_master_txBuff, 1, 0);
  I2C_MasterStop(I2C_MASTER);
  
  printf("Sent data 0xAA to register 0x00\r\n"); 
  

  
  printf("Receiving data from slave...\r\n");
  registerAddress = 0x0DU;
  
  /* Receive blocking data from slave */
  /* subAddress = 0x01, data = g_master_rxBuff - read from slave.
  start + slaveaddress(w) + subAddress + repeated start + slaveaddress(r) + rx data buffer + stop */
  I2C_MasterStart(I2C_MASTER, I2C_MASTER_SLAVE_ADDR_7BIT, kI2C_Write);
  
  /* subAddress = 0x01, data = g_master_txBuff - write to slave.
  start + slaveaddress(w) + subAddress + length of data buffer + data buffer + stop*/
  I2C_MasterWriteBlocking(I2C_MASTER, &registerAddress, 1, kI2C_TransferNoStopFlag);
  
  I2C_MasterRepeatedStart(I2C_MASTER, I2C_MASTER_SLAVE_ADDR_7BIT, kI2C_Read);
  I2C_MasterReadBlocking(I2C_MASTER, g_master_rxBuff, 1, 0);
  I2C_MasterStop(I2C_MASTER);
  
  printf("Cell 1 voltage: %d\r\n", g_master_rxBuff[0]); 
  
  printf("End of I2C transfer.\r\n\r\n");
  
  
  
  
  printf("CTIMER match to blink blue LED starting...\r\n");
  
  CTIMER_GetDefaultConfig(&config);
  CTIMER_Init(CTIMER, &config);
  
  matchConfig.enableCounterReset = true;
  matchConfig.enableCounterStop = false;
  matchConfig.matchValue = CTIMER_CLK_FREQ;
  matchConfig.outControl = kCTIMER_Output_Toggle;
  matchConfig.outPinInitState = true;
  matchConfig.enableInterrupt = false;
  CTIMER_SetupMatch(CTIMER, CTIMER_MAT_OUT, &matchConfig);
  CTIMER_StartTimer(CTIMER);
  
  printf("CTIMER modulating PWM signal with 50 percent duty cycle and 1hz.\r\n");
    
  printf("Red LED blinking means program idle.\r\n"); 
  
  while (1) {
    /* Delay 100 ms */
    SysTick_DelayTicks(100U);
    GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN3);
  }
}
