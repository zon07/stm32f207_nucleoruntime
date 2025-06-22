#ifndef __XCP_CFG_H__
#define __XCP_CFG_H__

#include "stdint.h"

/* Определите параметры конфигурации для настройки драйвера XCP */

#define XCP_ENABLE_GET_ID_GENERIC
#define XCP_ENABLE_CALIBRATION

#define XCP_ENABLE_DAQ
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_EVENT_INFO

#define XCP_ENABLE_STIM

#define kXcpMaxEvent			2
#define kXcpStimOdtCount		6

//#define kXcpSendQueueMinSize	1

//#define ApplXcpInit

//#define XCP_ENABLE_SERV_TEXT
//#define XCP_ENABLE_SERV_TEXT_PUTCHAR
//#define XCP_ENABLE_SERV_TEXT_PRINT
//#define XCP_ENABLE_SERV_TEXT_PRINTF
#define XCP_DISABLE_SERV_TEXT_PRINT

#define XCP_CPUTYPE_LITTLEENDIAN
#define C_CPUTYPE_LITTLEENDIAN
#define C_CPUTYPE_BITORDER_LSB2MSB

//#define ApplXcpGetPointer
//#define XCP_ENABLE_TESTMODE

//void ApplXcpInit(void);
uint32_t ApplXcpGetIdData(uint8_t **pData, uint8_t id);
//void ApplXcpPrint( const vsint8 *str, ... );

#endif /* __XCP_CFG_H__ */
