/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

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
/* Definitions for canRxTask */
osThreadId_t canRxTaskHandle;
const osThreadAttr_t canRxTask_attributes = {
  .name = "canRxTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for canTxTask */
osThreadId_t canTxTaskHandle;
const osThreadAttr_t canTxTask_attributes = {
  .name = "canTxTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* Definitions for appTask */
osThreadId_t appTaskHandle;
const osThreadAttr_t appTask_attributes = {
  .name = "appTask",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for canXcpTask */
osThreadId_t canXcpTaskHandle;
const osThreadAttr_t canXcpTask_attributes = {
  .name = "canXcpTask",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for can1_rx_queue */
osMessageQueueId_t can1_rx_queueHandle;
const osMessageQueueAttr_t can1_rx_queue_attributes = {
  .name = "can1_rx_queue "
};
/* Definitions for can2_rx_queue */
osMessageQueueId_t can2_rx_queueHandle;
const osMessageQueueAttr_t can2_rx_queue_attributes = {
  .name = "can2_rx_queue "
};
/* Definitions for appCan1RxQueue */
osMessageQueueId_t appCan1RxQueueHandle;
const osMessageQueueAttr_t appCan1RxQueue_attributes = {
  .name = "appCan1RxQueue"
};
/* Definitions for appCan2RxQueue */
osMessageQueueId_t appCan2RxQueueHandle;
const osMessageQueueAttr_t appCan2RxQueue_attributes = {
  .name = "appCan2RxQueue"
};
/* Definitions for appCan1TxQueue */
osMessageQueueId_t appCan1TxQueueHandle;
const osMessageQueueAttr_t appCan1TxQueue_attributes = {
  .name = "appCan1TxQueue"
};
/* Definitions for appCan2TxQueue */
osMessageQueueId_t appCan2TxQueueHandle;
const osMessageQueueAttr_t appCan2TxQueue_attributes = {
  .name = "appCan2TxQueue"
};
/* Definitions for xcpCanRxQueue */
osMessageQueueId_t xcpCanRxQueueHandle;
const osMessageQueueAttr_t xcpCanRxQueue_attributes = {
  .name = "xcpCanRxQueue"
};
/* Definitions for xcpCanTxQueue */
osMessageQueueId_t xcpCanTxQueueHandle;
const osMessageQueueAttr_t xcpCanTxQueue_attributes = {
  .name = "xcpCanTxQueue"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartCanRxTask(void *argument);
void StartCanTxTask(void *argument);
void StartAppTask(void *argument);
void StartCanXcpTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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

  /* Create the queue(s) */
  /* creation of can1_rx_queue */
  can1_rx_queueHandle = osMessageQueueNew (16, sizeof(CAN_RxHeaderTypeDef), &can1_rx_queue_attributes);

  /* creation of can2_rx_queue */
  can2_rx_queueHandle = osMessageQueueNew (16, sizeof(CAN_RxHeaderTypeDef), &can2_rx_queue_attributes);

  /* creation of appCan1RxQueue */
  appCan1RxQueueHandle = osMessageQueueNew (16, sizeof(CAN_RxHeaderTypeDef), &appCan1RxQueue_attributes);

  /* creation of appCan2RxQueue */
  appCan2RxQueueHandle = osMessageQueueNew (16, sizeof(CAN_RxHeaderTypeDef), &appCan2RxQueue_attributes);

  /* creation of appCan1TxQueue */
  appCan1TxQueueHandle = osMessageQueueNew (128, sizeof(CAN_TxHeaderTypeDef), &appCan1TxQueue_attributes);

  /* creation of appCan2TxQueue */
  appCan2TxQueueHandle = osMessageQueueNew (128, sizeof(CAN_TxHeaderTypeDef), &appCan2TxQueue_attributes);

  /* creation of xcpCanRxQueue */
  xcpCanRxQueueHandle = osMessageQueueNew (16, sizeof(CAN_RxHeaderTypeDef), &xcpCanRxQueue_attributes);

  /* creation of xcpCanTxQueue */
  xcpCanTxQueueHandle = osMessageQueueNew (128, sizeof(CAN_TxHeaderTypeDef), &xcpCanTxQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of canRxTask */
  canRxTaskHandle = osThreadNew(StartCanRxTask, NULL, &canRxTask_attributes);

  /* creation of canTxTask */
  canTxTaskHandle = osThreadNew(StartCanTxTask, NULL, &canTxTask_attributes);

  /* creation of appTask */
  appTaskHandle = osThreadNew(StartAppTask, NULL, &appTask_attributes);

  /* creation of canXcpTask */
  canXcpTaskHandle = osThreadNew(StartCanXcpTask, NULL, &canXcpTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartCanRxTask */
/**
  * @brief  Function implementing the canRxTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartCanRxTask */
void StartCanRxTask(void *argument)
{
  /* USER CODE BEGIN StartCanRxTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCanRxTask */
}

/* USER CODE BEGIN Header_StartCanTxTask */
/**
* @brief Function implementing the canTxTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCanTxTask */
void StartCanTxTask(void *argument)
{
  /* USER CODE BEGIN StartCanTxTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCanTxTask */
}

/* USER CODE BEGIN Header_StartAppTask */
/**
* @brief Function implementing the appTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAppTask */
void StartAppTask(void *argument)
{
  /* USER CODE BEGIN StartAppTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartAppTask */
}

/* USER CODE BEGIN Header_StartCanXcpTask */
/**
* @brief Function implementing the canXcpTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCanXcpTask */
void StartCanXcpTask(void *argument)
{
  /* USER CODE BEGIN StartCanXcpTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCanXcpTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

