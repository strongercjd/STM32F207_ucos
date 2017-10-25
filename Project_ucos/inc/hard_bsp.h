#ifndef _HARD_BSP_H
#define _HARD_BSP_H 
#include "main.h"
   

extern uint32 G_timeTicks;
extern uint32 sys_LED_state;
extern uint32 sys_LED_time;


void LED_Init(void);
void LED_ray_run(void);
void timer4Init(void);
void UART_Init();

#endif













