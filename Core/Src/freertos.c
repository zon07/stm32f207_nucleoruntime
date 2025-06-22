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
#include "canMsgs.h"
#include "XcpBasic.h"
#include "XcpPort.h"

#include "can.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct {
    uint32_t sentCount;
    uint32_t errorCount;
} CanStats;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MS_TO_TICKS(ms)  ((osKernelGetTickFreq() * (ms)) / 1000)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
CanStats can1Stats;
CanStats can2Stats;


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
HAL_StatusTypeDef CAN_SendMessage(CAN_HandleTypeDef *hcan, const CAN_Msg_t *msg, uint32_t timeout_ms);

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
  can1_rx_queueHandle = osMessageQueueNew (16, sizeof(CAN_Msg_t), &can1_rx_queue_attributes);

  /* creation of can2_rx_queue */
  can2_rx_queueHandle = osMessageQueueNew (16, sizeof(CAN_Msg_t), &can2_rx_queue_attributes);

  /* creation of appCan1RxQueue */
  appCan1RxQueueHandle = osMessageQueueNew (16, sizeof(CAN_Msg_t), &appCan1RxQueue_attributes);

  /* creation of appCan2RxQueue */
  appCan2RxQueueHandle = osMessageQueueNew (16, sizeof(CAN_Msg_t), &appCan2RxQueue_attributes);

  /* creation of appCan1TxQueue */
  appCan1TxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &appCan1TxQueue_attributes);

  /* creation of appCan2TxQueue */
  appCan2TxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &appCan2TxQueue_attributes);

  /* creation of xcpCanRxQueue */
  xcpCanRxQueueHandle = osMessageQueueNew (16, sizeof(CAN_Msg_t), &xcpCanRxQueue_attributes);

  /* creation of xcpCanTxQueue */
  xcpCanTxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &xcpCanTxQueue_attributes);

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
  CAN_Msg_t txMsg;
  CAN_TxHeaderTypeDef TxHeader;
  uint32_t TxMailbox;

  /* Infinite loop */
  for(;;)
  {

    // Обработка очереди XCP (CAN1)
    while (osMessageQueueGet(xcpCanTxQueueHandle, &txMsg, NULL, 0) == osOK)
    {
      CAN_SendMessage(&hcan1, &txMsg, 10);
    }

    // Обработка очереди APP (CAN1)
    while(osMessageQueueGet(appCan1TxQueueHandle, &txMsg, NULL, 0) == osOK)
    {
      CAN_SendMessage(&hcan1, &txMsg, 10);
    }

    // Обработка очереди APP (CAN2)
    while(osMessageQueueGet(appCan2TxQueueHandle, &txMsg, NULL, 0) == osOK)
    {
      CAN_SendMessage(&hcan2, &txMsg, 10);
    }

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
  const uint32_t interval = MS_TO_TICKS(10); // 10 мс в тиках
  uint32_t tick = osKernelGetTickCount(); 
  /* Infinite loop */
  for(;;)
  {

    // Жёсткая периодичность 10 мс
    tick += interval;
    osDelayUntil(tick);
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
  CAN_Msg_t rxMsg;
  const uint32_t interval = MS_TO_TICKS(10); // 10 мс в тиках
  uint32_t tick = osKernelGetTickCount(); 

  XcpInit();
  ApplXcpInit();

  for(;;)
  {
    // Обработка всех сообщений в очереди
    while(osMessageQueueGet(xcpCanRxQueueHandle, &rxMsg, NULL, 0) == osOK)
    {
      XcpMessageHandler(&rxMsg);
    }
    
    XcpEvent(XcpEventChannel_10msEvent_1);
    XcpBackground();
    
    // Жёсткая периодичность 10 мс
    tick += interval;
    osDelayUntil(tick);
  }
}

/* Private application code --------------------------------------------------*/

/* USER CODE BEGIN Application */
/**
  * @brief Отправка CAN-сообщения с ожиданием свободного почтового ящика
  * @param hcan Указатель на структуру CAN_HandleTypeDef
  * @param msg Структура с данными сообщения (ID, Extended, Length, Data)
  * @param timeout_ms Таймаут ожидания свободного ящика в миллисекундах
  * @return HAL_StatusTypeDef Результат операции (HAL_OK, HAL_ERROR или HAL_TIMEOUT)
  */
HAL_StatusTypeDef CAN_SendMessage(CAN_HandleTypeDef *hcan, const CAN_Msg_t *msg, uint32_t timeout_ms)
{
    CAN_TxHeaderTypeDef TxHeader;
    uint32_t start_tick = osKernelGetTickCount();
    
    // Настройка заголовка CAN сообщения
    TxHeader.IDE = msg->Extended ? CAN_ID_EXT : CAN_ID_STD;
    TxHeader.StdId = msg->Extended ? 0 : msg->ID;
    TxHeader.ExtId = msg->Extended ? msg->ID : 0;
    TxHeader.DLC = msg->Length;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.TransmitGlobalTime = DISABLE;

    // Ожидание свободного почтового ящика
    while (HAL_CAN_GetTxMailboxesFreeLevel(hcan) == 0) {
        if (osKernelGetTickCount() - start_tick > timeout_ms) {
            return HAL_TIMEOUT;
        }
        osDelay(1);
    }

    // Отправка сообщения
    return HAL_CAN_AddTxMessage(hcan, &TxHeader, msg->Data, NULL);
}



// Вызывается при успешной отправке сообщения из почтового ящика
void HAL_CAN_TxMailboxCompleteCallback(CAN_HandleTypeDef *hcan, uint32_t TxMailbox)
{
  if (hcan == &hcan1) 
  {
    can1Stats.sentCount++;
  }
  if (hcan == &hcan2) 
  {
    can2Stats.sentCount++;
  }
  
}

// Вызывается при ошибке отправки
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)
{
  if (hcan == &hcan1) can1Stats.errorCount++;
  if (hcan == &hcan2) can2Stats.errorCount++;
}

/* USER CODE END Application */

