#include "stm32f2xx.h"
#include "main.h"
#include "hard_bsp.h"
#include "includes.h"
#include <stdio.h>


uint32 G_timeTicks;
uint32 sys_LED_state;
uint32 sys_LED_time;


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

                                                                /* ----------------- APPLICATION GLOBALS ------------------ */
static  OS_TCB   AppTaskStartTCB;
static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppTaskStart          (void             *p_arg);

static  void  AppTaskCreate         (void);
static  void  AppObjCreate          (void);


/*!
* @brief main()
* @param 	NONE 
* @return	NONE
* @note
*/
void main(){
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  timer4Init();
//  LED_Init();
//  UART_Init();
//  
//  printf("\r\n======================================================================");
//  printf("\r\n=               (C) COPYRIGHT 2017 onbon                             =");
//  printf("\r\n=                                                                    =");
//  printf("\r\n=                GD207_ETH Program Demo                              =");
//  printf("\r\n=                                                                    =");
//  printf("\r\n=                                           By cjd                   =");
//  printf("\r\n======================================================================");
//  printf("\r\n\r\n");
  
  
  OS_ERR  err;
  
  BSP_IntDisAll();                                            /* Disable all interrupts.                                  */
  
  CPU_Init();                                                 /* Initialize uC/CPU services.                              */
  
  OSInit(&err);                                               /* Init OS.                                                 */
  
  OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,                /* Create the start task                                    */
               (CPU_CHAR   *)"App Task Start",
               (OS_TASK_PTR ) AppTaskStart,
               (void       *) 0,
               (OS_PRIO     ) APP_TASK_START_PRIO,
               (CPU_STK    *)&AppTaskStartStk[0],
               (CPU_STK     )(APP_TASK_START_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_TASK_START_STK_SIZE,
               (OS_MSG_QTY  ) 0,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
  
  OSStart(&err);
  
  
  while(1){
    LED_ray_run();
  } 
}


static  void  AppTaskStart (void *p_arg)
{
    OS_ERR      os_err;


   (void)p_arg;

    BSP_Init();                                                 /* Init BSP fncts.                                          */

    CPU_Init();                                                 /* Init CPU name & int. dis. time measuring fncts.          */

    Mem_Init();                                                 /* Initialize Memory managment                              */

    BSP_CPU_TickInit();                                         /* Start Tick Initialization                                */

#if (OS_TASK_STAT_EN > 0)
    OSStatInit();                                               /* Determine CPU capacity                                   */
#endif

#if (APP_CFG_SERIAL_EN == DEF_ENABLED)
    BSP_Ser_Init(115200);                                       /* Initialize Serial Interface                              */
#endif

    APP_TRACE_INFO(("Creating Application Objects... \n\r"));
    AppObjCreate();                                             /* Create Application Kernel Objects                        */

    APP_TRACE_INFO(("Creating Application Tasks... \n\r"));
    AppTaskCreate();                                            /* Create Application Tasks                                 */

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.           */
        BSP_LED_Toggle(0);
        OSTimeDlyHMSM(0, 0, 0, 500,
                      OS_OPT_TIME_HMSM_STRICT, &os_err);
    }
}

/*
*********************************************************************************************************
*                                          AppTaskCreate()
*
* Description : Create application tasks.
*
* Argument(s) : none
*
* Return(s)   : none
*
* Caller(s)   : AppTaskStart()
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  AppTaskCreate (void)
{

}


/*
*********************************************************************************************************
*                                          AppObjCreate()
*
* Description : Create application kernel objects tasks.
*
* Argument(s) : none
*
* Return(s)   : none
*
* Caller(s)   : AppTaskStart()
*
* Note(s)     : none.
*********************************************************************************************************
*/
static  void  AppObjCreate (void)
{

}



