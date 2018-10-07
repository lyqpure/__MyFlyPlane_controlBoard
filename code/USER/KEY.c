#include "KEY.h"

void InitKEY(void){
    
    GPIO_InitTypeDef InitGPIO_KEY;
    
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    
    
    InitGPIO_KEY.Mode = GPIO_MODE_INPUT;
    InitGPIO_KEY.Pin = GPIO_PIN_2 | GPIO_PIN_3;
    InitGPIO_KEY.Pull = GPIO_PULLUP;
    InitGPIO_KEY.Speed = GPIO_SPEED_HIGH;
    
    HAL_GPIO_Init(GPIOH, &InitGPIO_KEY);
    
    InitGPIO_KEY.Mode = GPIO_MODE_INPUT;
    InitGPIO_KEY.Pin = GPIO_PIN_13;
    InitGPIO_KEY.Pull = GPIO_PULLUP;
    InitGPIO_KEY.Speed = GPIO_SPEED_HIGH;
    
    HAL_GPIO_Init(GPIOC, &InitGPIO_KEY);
    
    InitGPIO_KEY.Mode = GPIO_MODE_INPUT;
    InitGPIO_KEY.Pin = GPIO_PIN_0;
    InitGPIO_KEY.Pull = GPIO_PULLDOWN;
    InitGPIO_KEY.Speed = GPIO_SPEED_HIGH;
    
    HAL_GPIO_Init(GPIOA, &InitGPIO_KEY);
}
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，WKUP按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>WK_UP!!

u8 KeyMode(u8 mode){
    static u8 keyUp = 1;
    if(mode == 1 ) keyUp = 1;
    if(keyUp && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WakeUp == 1)){
       delay_ms(10);
        
       keyUp = 0;
       if(KEY0 == 1)    return KEY0Press;
       else if(KEY1 == 1)   return KEY1Press;
       else if(KEY2 == 1)   return KEY2Press;     
    }else if(KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WakeUp == 0){
       keyUp = 1;
       return 0; 
    }
}
