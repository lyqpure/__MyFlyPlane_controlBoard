#ifndef _LED_H 
#define _LED_H 
#include "sys.h"

#define LED1(n)      (n?HAL_GPIO_WritePin( GPIOB, GPIO_PIN_0, GPIO_PIN_SET) : HAL_GPIO_WritePin( GPIOB, GPIO_PIN_0, GPIO_PIN_RESET)) 
#define LED2(n)      (n?HAL_GPIO_WritePin( GPIOB, GPIO_PIN_1, GPIO_PIN_SET) : HAL_GPIO_WritePin( GPIOB, GPIO_PIN_1, GPIO_PIN_RESET))


void InitLED(void);


#endif
