#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "LED.h"
#include "KEY.h"
int main(void)
{
	

	u8 KeyValue = 0;
    u8 LED1_State = 1;
    u8 LED2_State = 1;
    
    Cache_Enable();                 //打开L1-Cache
	HAL_Init();				        //初始化HAL库
	Stm32_Clock_Init(432,25,2,9);   //设置时钟,216Mhz 
	__HAL_RCC_GPIOB_CLK_ENABLE();           //开启GPIOB时钟
    InitLED();
    InitKEY();
    
    LED1(LED1_State);
    LED2(LED2_State);
    
    while(1){
        KeyValue = KeyMode(0);
        if(KeyValue){
            switch(KeyValue){
                case KEY0Press : 
                    LED1_State = !LED1_State;
                    LED1(LED1_State);
                    LED2_State = 1;
                    LED2(LED2_State);
                    break;
                case KEY1Press :
                    LED2_State = !LED2_State;
                    LED2(LED2_State);
                    LED1_State = 1;
                    LED1(LED1_State);
                    break;
                case KEY2Press :
                    LED2_State = !LED2_State;
                    LED1_State = !LED1_State;
                    
                    LED1(LED1_State);
                    LED2(LED2_State);
                    break;
                case 0 :
                    LED2_State = 1;
                    LED1_State = 1;
                    LED1(LED1_State);
                    LED2(LED2_State);
                    break;
            }
        }else{
            delay_ms(50);
        }
    }
    
}
