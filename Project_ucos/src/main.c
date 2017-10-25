#include "stm32f2xx.h"
#include "main.h"
#include "hard_bsp.h"
#include <stdio.h>


uint32 G_timeTicks;
uint32 sys_LED_state;
uint32 sys_LED_time;


/*!
* @brief main()
* @param 	NONE 
* @return	NONE
* @note
*/
void main(){
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  timer4Init();
  LED_Init();
  UART_Init();
  
  printf("\r\n======================================================================");
  printf("\r\n=               (C) COPYRIGHT 2017 onbon                             =");
  printf("\r\n=                                                                    =");
  printf("\r\n=                GD207_ETH Program Demo                              =");
  printf("\r\n=                                                                    =");
  printf("\r\n=                                           By cjd                   =");
  printf("\r\n======================================================================");
  printf("\r\n\r\n");
  
  while(1){
    LED_ray_run();
  } 
}

