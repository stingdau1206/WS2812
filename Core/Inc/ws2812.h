#ifndef SRC_WS2812_H_
#define SRC_WS2812_H_

//--------------------------------------------------
/*INCLUDES*/
#include "stm32f1xx_hal.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
//--------------------------------------------------
/*USR SETTINGS*/
#define LED_COUNT 8						// Count of led in your strip
#define BRIGHT 90 							// 0-90
#define TIM_HANDLE	htim2					// use "htimX", where X is number of ur timer
#define TIM_CH	TIM_CHANNEL_2				// use "TIM_CHANNEL_X", where X is number of ur channel
//--------------------------------------------------
/*SYS DEFINES*/
#define DELAY_LEN 50						// Delay period of Restart
#define ARRAY_LEN 2*(DELAY_LEN + LED_COUNT*24)	// Length of DMA Buffer (Double Buffer)
#define HIGH 66								// HIGH Byte period
#define LOW 24								// LOW Byte period
extern TIM_HandleTypeDef TIM_HANDLE;		// Initalization of timer handler
//--------------------------------------------------

//--------------------------------------------------
#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)	// Check Bit = 1?
//--------------------------------------------------

void led_init(void);		// Initalization
void set_led(uint8_t Rpixel , uint8_t Gpixel, uint8_t Bpixel, uint16_t posX);  // Set led X to color 
void led_fill (uint8_t Rpix, uint8_t Gpix, uint8_t Bpix);	// all led with 1 color
void led_clear(void);	// turned off all led
void led_show(void);	// Send Data over DMA PWM
#endif 
