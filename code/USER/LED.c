#include "LED.h"

void InitLED(void){
    
    GPIO_InitTypeDef GPIO_Init;
    
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pin = GPIO_PIN_0 | GPIO_PIN_1;
    GPIO_Init.Pull = GPIO_PULLUP;
    GPIO_Init.Speed = GPIO_SPEED_HIGH;
    
    HAL_GPIO_Init(GPIOB, &GPIO_Init);
    
}
