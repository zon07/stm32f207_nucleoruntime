/*
 * XcpPort.c
 *
 *  Created on: 2024 Mar 29
 *      Author: Tcukavin13
 */

#include "XcpPort.h"
#include "string.h"

/* Чтобы добавить новое событие, нужно добавить соответствующие
 * строчки в массивы ниже: */

/* Имя события */
V_MEMROM0 static vuint8 MEMORY_ROM kXcpEventName_0[] = "10ms";
V_MEMROM0 static vuint8 MEMORY_ROM kXcpEventName_1[] = "100ms";

/* Массив с именами событий */
V_MEMROM0 MEMORY_ROM vuint8* MEMORY_ROM kXcpEventName[] =
{
	&kXcpEventName_0[0],
	&kXcpEventName_1[0]
};

/* Длина имени события (количество символов в имени) */
V_MEMROM0 vuint8 MEMORY_ROM kXcpEventNameLength[] =
{
	sizeof(kXcpEventName_0) - 1U,
	sizeof(kXcpEventName_1) - 1U
};

/* Период события в циклах */
V_MEMROM0 vuint8 MEMORY_ROM kXcpEventCycle[] =
{
	10U,
	100U
};

/* Событие */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[] =
{
    (vuint8)DAQ_TIMESTAMP_UNIT_10MS,
    (vuint8)DAQ_TIMESTAMP_UNIT_100MS
};

/* Направление передачи данных события */
#define kXcpEventDirectionDaq	  (0x04U)
#define kXcpEventDirectionStim    (0x08U)

V_MEMROM0 vuint8 MEMORY_ROM kXcpEventDirection[] =
{
	kXcpEventDirectionDaq,
	kXcpEventDirectionDaq
};

//------------------------------------------------------------------------------
// Slave device id
#if defined ( kXcpStationIdLength )
  V_MEMROM0 MEMORY_ROM vuint8 kXcpStationId[kXcpStationIdLength] = kXcpStationIdString;
#endif

#define MEMORY_ROM const
//------------------------------------------------------------------------------
/* Transport Layer */

/* Receive handler */
/* Handle transmission done */
void XcpMessageHandler(const CanMessage *rxMsg)
{
    if(rxMsg->id == XCP_CAN_ID_RX)
    {
		XcpCommand((uint32_t*)&rxMsg->data);
    }
}

/* Transmit message */
void ApplXcpSend(vuint8 len, MEMORY_ROM BYTEPTR msg)
{
	CanMessage txMsg;

    /* Message prepare */
	txMsg.id = XCP_CAN_ID_TX;
	txMsg.length = len;
	
	memcpy(txMsg.data, msg, len);

    /* Put message */
	Can1::send(&txMsg);

    /* Сообщаем движку XCP об успешной отправке сообщения */
    XcpSendCallBack();
}

vuint8 ApplXcpSendStall(void)
{
  return 1U;
}

//------------------------------------------------------------------------------
// Platform dependend functions

// Convert a XCP address to a pointer
//MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr ) {
//
//  addr_ext = addr_ext;
//  return (MTABYTEPTR)addr;
//}
