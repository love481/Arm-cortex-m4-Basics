/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "usart.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId task1Handle;
osThreadId task2Handle;
osThreadId task3Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void start_task1(void const * argument);
void start_task2(void const * argument);
void start_task3(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of task1 */
  osThreadDef(task1, start_task1, osPriorityNormal, 0, 128);
  task1Handle = osThreadCreate(osThread(task1), NULL);

  /* definition and creation of task2 */
  osThreadDef(task2, start_task2, osPriorityNormal, 0, 128);
  task2Handle = osThreadCreate(osThread(task2), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	osThreadDef(task3,start_task3,osPriorityNormal,0,128);
	task3Handle= osThreadCreate(osThread(task3),NULL);
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_start_task1 */
/**
  * @brief  Function implementing the task1 thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_start_task1 */
void start_task1(void const * argument)
{
    
    
    

  /* USER CODE BEGIN start_task1 */
  /* Infinite loop */
	uint8_t data1[]="hi from task1\n";
  for(;;)
  {
		//HAL_UART_Transmit(&huart1,(uint8_t *)data1,sizeof(data1),100);
		printf("hi task1\n");
    osDelay(1000);
  }
  /* USER CODE END start_task1 */
}

/* USER CODE BEGIN Header_start_task2 */
/**
* @brief Function implementing the task2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_task2 */
void start_task2(void const * argument)
{
  /* USER CODE BEGIN start_task2 */
  /* Infinite loop */
  uint8_t data2[]="hi from task2\n";
  for(;;)
  {
		//HAL_UART_Transmit(&huart1,(uint8_t *)data2,sizeof(data2),100);
		printf("hi task2\n");
    osDelay(1000);
  }
  /* USER CODE END start_task2 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void start_task3(void const * argument)
{
  /* USER CODE BEGIN start_task2 */
  /* Infinite loop */
  uint8_t data3[]="hi from task3\n";
  for(;;)
  {
		//HAL_UART_Transmit(&huart1,(uint8_t *)data3,sizeof(data3),100);
		printf("hi task3\n");
    osDelay(1000);
  }
  /* USER CODE END start_task2 */
}     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
