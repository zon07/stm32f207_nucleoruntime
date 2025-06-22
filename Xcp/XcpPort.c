/*
 * XcpPort.c
 *
 *  Created on: 2024 Mar 29
 *      Author: Tcukavin13
 */

#include "XcpPort.h"
#include "string.h"

#include "cmsis_os2.h"

osMessageQueueId_t xcpCanTxQueueHandle;

/* ����� �������� ����� �������, ����� �������� ���������������
 * ������� � ������� ����: */

/* ��� ������� */
V_MEMROM0 static vuint8 MEMORY_ROM kXcpEventName_0[] = "10ms";
V_MEMROM0 static vuint8 MEMORY_ROM kXcpEventName_1[] = "100ms";

/* ������ � ������� ������� */
V_MEMROM0 MEMORY_ROM vuint8* MEMORY_ROM kXcpEventName[] =
{
	&kXcpEventName_0[0],
	&kXcpEventName_1[0]
};

/* ����� ����� ������� (���������� �������� � �����) */
V_MEMROM0 vuint8 MEMORY_ROM kXcpEventNameLength[] =
{
	sizeof(kXcpEventName_0) - 1U,
	sizeof(kXcpEventName_1) - 1U
};

/* ������ ������� � ������ */
V_MEMROM0 vuint8 MEMORY_ROM kXcpEventCycle[] =
{
	10U,
	100U
};

/* ������� */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[] =
{
    (vuint8)DAQ_TIMESTAMP_UNIT_10MS,
    (vuint8)DAQ_TIMESTAMP_UNIT_100MS
};

/* ����������� �������� ������ ������� */
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
void XcpMessageHandler(const CAN_Msg_t *rxMsg)
{
    if(rxMsg->ID == XCP_CAN_ID_RX && rxMsg->Extended == XCP_IS_CAN_ID_EXTENDED)
    {
		XcpCommand((uint32_t*)&rxMsg->Data);
    }
}

/* Transmit message */
void ApplXcpSend(vuint8 len, MEMORY_ROM BYTEPTR msg)
{
	CAN_Msg_t txMsg = {0};

	/* Message prepare */
	txMsg.Extended = 0;
	txMsg.ID = XCP_CAN_ID_TX;
	txMsg.Length = len;

	memcpy(txMsg.Data, msg, len);

    /* Put message in queue */
    osMessageQueuePut(xcpCanTxQueueHandle, &txMsg, 0, 0);

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
