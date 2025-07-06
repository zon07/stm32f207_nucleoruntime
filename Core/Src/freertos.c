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

#include <string.h>
#include "can.h"

#include "arm_math.h"

//#include "simulink_app.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct {
    uint32_t txCount;
    uint32_t rxCount;
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
/* Definitions for can2_TxTask */
osThreadId_t can2_TxTaskHandle;
const osThreadAttr_t can2_TxTask_attributes = {
  .name = "can2_TxTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for can1_TxTask */
osThreadId_t can1_TxTaskHandle;
const osThreadAttr_t can1_TxTask_attributes = {
  .name = "can1_TxTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh,
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

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
HAL_StatusTypeDef CAN_SendMessage(CAN_HandleTypeDef *hcan, const CAN_Msg_t *msg);
void ProcessCanToQueue(CAN_HandleTypeDef *hcan, uint8_t fifo, osMessageQueueId_t queue);

/* USER CODE END FunctionPrototypes */

void StartCan2_TxTask(void *argument);
void StartCan1_TxTask(void *argument);
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
  /* creation of appCan1RxQueue */
  appCan1RxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &appCan1RxQueue_attributes);

  /* creation of appCan2RxQueue */
  appCan2RxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &appCan2RxQueue_attributes);

  /* creation of appCan1TxQueue */
  appCan1TxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &appCan1TxQueue_attributes);

  /* creation of appCan2TxQueue */
  appCan2TxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &appCan2TxQueue_attributes);

  /* creation of xcpCanRxQueue */
  xcpCanRxQueueHandle = osMessageQueueNew (128, sizeof(CAN_Msg_t), &xcpCanRxQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of can2_TxTask */
  can2_TxTaskHandle = osThreadNew(StartCan2_TxTask, NULL, &can2_TxTask_attributes);

  /* creation of can1_TxTask */
  can1_TxTaskHandle = osThreadNew(StartCan1_TxTask, NULL, &can1_TxTask_attributes);

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

/* USER CODE BEGIN Header_StartCan2_TxTask */
/**
  * @brief  Function implementing the canRxTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartCan2_TxTask */
void StartCan2_TxTask(void *argument)
{
  /* USER CODE BEGIN StartCan2_TxTask */
  CAN_Msg_t txMsg;
  CAN_TxHeaderTypeDef TxHeader;
  uint32_t TxMailbox;

  /* Infinite loop */
  for(;;)
  {
        // Обработка очереди APP (CAN2)
    if(osMessageQueueGet(appCan2TxQueueHandle, &txMsg, NULL, 0) == osOK)
    {
      CAN_SendMessage(&hcan2, &txMsg);
    }
    osDelay(1);
  }
  /* USER CODE END StartCan2_TxTask */
}

/* USER CODE BEGIN Header_StartCan1_TxTask */
/**
* @brief Function implementing the canTxTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCan1_TxTask */
void StartCan1_TxTask(void *argument)
{
  /* USER CODE BEGIN StartCan1_TxTask */
  CAN_Msg_t txMsg;
  CAN_TxHeaderTypeDef TxHeader;
  uint32_t TxMailbox;

  /* Infinite loop */
  for(;;)
  {
    // Обработка очереди APP (CAN1)
    if(osMessageQueueGet(appCan1TxQueueHandle, &txMsg, NULL, 0) == osOK)
    {
      CAN_SendMessage(&hcan1, &txMsg);
    }
    osDelay(1);
  }
  /* USER CODE END StartCan1_TxTask */
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
  // Константы времени
  const uint32_t interval_10ms = MS_TO_TICKS(10);    // 10 мс интервал
  const uint32_t interval_100ms = MS_TO_TICKS(100);  // 100 мс интервал
  const uint32_t interval_1000ms = MS_TO_TICKS(1000);// 1000 мс интервал
  
  // Параметры синусоидального сигнала RPM
  const float32_t RPM_MAX = 8031.875f;    // Максимальное значение RPM
  const float32_t WAVE_PERIOD_MS = 5000.0f; // Период волны 5 секунд
  float32_t phase = 0.0f;                 // Текущая фаза
  const float32_t PHASE_STEP = (2.0f * PI * 10.0f) / WAVE_PERIOD_MS; // Приращение фазы за 10 мс

  // Тайминги
  uint32_t tick = osKernelGetTickCount();
  uint32_t last_100ms_tick = tick;
  uint32_t last_1000ms_tick = tick;

  /* Infinite loop */
  for(;;)
  {
    /* Шаг функции Simulink */
    simulink_app_step();

    /* Жёсткая периодичность 10 мс */
    tick += interval_10ms;
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
  /* USER CODE BEGIN StartCanXcpTask */
  CAN_Msg_t rxMsg;
  const uint32_t interval10ms = MS_TO_TICKS(10);
  const uint32_t interval100ms = MS_TO_TICKS(100);
  uint32_t tick10ms = osKernelGetTickCount();
  uint32_t tick100ms = tick10ms;
  uint32_t messageCount = 0;
  const uint32_t maxMessagesPerCycle = 50; // Максимальное количество сообщений за цикл

  XcpInit();

  /* Infinite loop */
  for(;;)
  {
    // Обработка сообщений с ограничением количества
    messageCount = 0;
    while((osMessageQueueGet(xcpCanRxQueueHandle, &rxMsg, NULL, 0) == osOK) && 
          (messageCount < maxMessagesPerCycle))
    {
      XcpMessageHandler(&rxMsg);
      messageCount++;
    }
    
    // 10ms события
    XcpEvent(XcpEventChannel_10msEvent_1);
    
    // 100ms события (каждый 10-й вызов)
    if((tick10ms - tick100ms) >= interval100ms)
    {
      XcpEvent(XcpEventChannel_100msEvent_1);
      tick100ms = tick10ms;
    }
    
    tick10ms += interval10ms;
    osDelayUntil(tick10ms);
  }
  /* USER CODE END StartCanXcpTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/**
  * @brief Отправка CAN-сообщения с ожиданием свободного почтового ящика
  * @param hcan Указатель на структуру CAN_HandleTypeDef
  * @param msg Структура с данными сообщения (ID, Extended, Length, Data)
  * @param timeout_ms Таймаут ожидания свободного ящика в миллисекундах
  * @return
  */
HAL_StatusTypeDef CAN_SendMessage(CAN_HandleTypeDef *hcan, const CAN_Msg_t *msg)
{
    CAN_TxHeaderTypeDef TxHeader;
    
    // Настройка заголовка CAN сообщения
    TxHeader.IDE = msg->Extended ? CAN_ID_EXT : CAN_ID_STD;
    TxHeader.StdId = msg->Extended ? 0 : msg->ID;
    TxHeader.ExtId = msg->Extended ? msg->ID : 0;
    TxHeader.DLC = msg->Length;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.TransmitGlobalTime = DISABLE;

    // Ожидание свободного почтового ящика
    while (HAL_CAN_GetTxMailboxesFreeLevel(hcan) == 0)
    {
        osDelay(1);
    }

    // Отправка сообщения
    return HAL_CAN_AddTxMessage(hcan, &TxHeader, msg->Data, NULL);
}

// Общая функция для обработки CAN сообщений и помещения в очередь
void ProcessCanToQueue(CAN_HandleTypeDef *hcan, uint8_t fifo, osMessageQueueId_t queue) 
{
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t rxData[8];
    CAN_Msg_t canMsg;
    
    if (HAL_CAN_GetRxMessage(hcan, fifo, &rxHeader, rxData) == HAL_OK)
    {
        // Заполняем структуру CAN_Msg_t
        canMsg.Extended = (rxHeader.IDE == CAN_ID_EXT);
        canMsg.ID = canMsg.Extended ? rxHeader.ExtId : rxHeader.StdId;
        canMsg.Length = rxHeader.DLC;
        memcpy(canMsg.Data, rxData, 8);
        canMsg.Timestamp = HAL_GetTick();
        
        // Отправляем в очередь (без ожидания)
        osMessageQueuePut(queue, &canMsg, 0, 0);
    }
}


// Обработчик для CAN1 FIFO0 -> appCan1RxQueueHandle
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan == &hcan1)
    {
        ProcessCanToQueue(hcan, CAN_RX_FIFO0, appCan1RxQueueHandle);
        can1Stats.rxCount++;
    }
    else if (hcan == &hcan2)
    {
        ProcessCanToQueue(hcan, CAN_RX_FIFO0, appCan2RxQueueHandle);
        can2Stats.rxCount++;
    }
}

// Обработчик для CAN1 FIFO1 -> xcpCanRxQueueHandle
// Обработчик для CAN2 FIFO1 -> appCan2RxQueueHandle
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan == &hcan1)
    {
        ProcessCanToQueue(hcan, CAN_RX_FIFO1, xcpCanRxQueueHandle);
        can1Stats.rxCount++;
    }
    else if (hcan == &hcan2)
    {
        ProcessCanToQueue(hcan, CAN_RX_FIFO1, appCan2RxQueueHandle);
        can2Stats.rxCount++;
    }
}


// Вызывается при успешной отправке сообщения из почтового ящика
void HAL_CAN_TxMailboxCompleteCallback(CAN_HandleTypeDef *hcan, uint32_t TxMailbox)
{
  if (hcan == &hcan1) 
  {
    can1Stats.txCount++;
  }
  if (hcan == &hcan2) 
  {
    can2Stats.txCount++;
  }
  
}

// Вызывается при ошибке отправки
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)
{
  if (hcan == &hcan1) can1Stats.errorCount++;
  if (hcan == &hcan2) can2Stats.errorCount++;
}

/* USER CODE END Application */

