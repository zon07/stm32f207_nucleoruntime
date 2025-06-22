#if defined ( __XCP_PAR_H__ )
#else
#define __XCP_PAR_H__

#include "XcpTypes.h"
#include "XcpDefines.h"
#include "XcpBasic.h"
#include "XcpConfig.h"
#include "stdarg.h"
/* MCU depends */
#include "canMsgs.h"

#define XCP_CAN_ID_RX				    (0x555)		/* ������������� ��� ����������� XCP ������� */
#define XCP_CAN_ID_TX		 		    (0x777)		/* ������������� ��� ��������� XCP ������� */
#define XCP_IS_CAN_ID_EXTENDED		    (0UL)		/* ��� ��������� ���������� ������� ���������� - 1UL */

/* Events */
#define XcpEventChannel_10msEvent_1     (0UL)
#define XcpEventChannel_100msEvent_1    (1UL)

extern V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 kXcpEventName[];
extern V_MEMROM1 vuint8 V_MEMROM2 kXcpEventNameLength[];
extern V_MEMROM1 vuint8 V_MEMROM2 kXcpEventCycle[];
extern V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[];
extern V_MEMROM1 vuint8 V_MEMROM2 kXcpEventDirection[];

void XcpMessageHandler(const CAN_Msg_t *rxMsg);

#endif
