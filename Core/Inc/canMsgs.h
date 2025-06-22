/**
  * @file canMsgs.h
  * @brief Заголовочный файл для работы с CAN-сообщениями (стандартными и расширенными).
  * @author Evgenii Shkliaev (zon07)
  * @date 10-06-2025
  * 
  * @defgroup CAN_Msgs CAN Messages Structures
  * @brief Унифицированная структура для работы с CAN-сообщениями.
  * @{
  */

#ifndef __CAN_MSGS_H__
#define __CAN_MSGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>

/**
  * @brief Универсальная структура CAN-сообщения.
  * @note Поддерживает стандартные (11-битные) и расширенные (29-битные) фреймы.
  */
typedef struct {
    uint8_t   Extended;   ///< Тип идентификатора: `0` (11-битный ID) или `1` (29-битный ID).
    uint8_t   Length;     ///< Длина данных в байтах (0..8). Соответствует полю `DLC` в CAN.
    uint8_t   Remote;     ///< Флаг удалённого запроса: `0` (данные) или `1` (remote frame).
    uint8_t   Error;      ///< Флаг ошибки (опционально, зависит от реализации драйвера).
    uint32_t  ID;         ///< Идентификатор: 11 или 29 бит (зависит от `Extended`).
    uint32_t  Timestamp;  ///< Метка времени приёма/отправки (в мкс или тиках системы).
    uint8_t   Data[8];    ///< Полезная нагрузка (максимум 8 байт).
} CAN_Msg_t;

/** @} */ // Конец группы CAN_Msgs

#ifdef __cplusplus
}
#endif
#endif /* __CAN_MSGS_H__ */