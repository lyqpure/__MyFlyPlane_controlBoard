#ifndef _KEY_H
#define _KEY_H
#include "sys.h"
#include "delay.h"

#define WakeUp  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)
#define KEY0    HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_3)
#define KEY1    HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_2)
#define KEY2    HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)

#define KEY0Press    1
#define KEY1Press    2
#define KEY2Press    3

void InitKEY(void);

u8 KeyMode(u8 mode);
#endif
