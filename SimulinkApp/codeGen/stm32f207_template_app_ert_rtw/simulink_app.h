/*
 * File: simulink_app.h
 *
 * Code generated for Simulink model 'stm32f207_template_app'.
 *
 * Model version                  : 1.590
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Jul  6 13:54:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. ROM efficiency
 *    4. RAM efficiency
 *    5. Traceability
 *    6. Safety precaution
 *    7. Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simulink_app_h_
#define RTW_HEADER_simulink_app_h_
#ifndef stm32f207_template_app_COMMON_INCLUDES_
#define stm32f207_template_app_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "can_message.h"
#endif                             /* stm32f207_template_app_COMMON_INCLUDES_ */

#include "simulink_apptypes.h"
#include "can_control.h"
#include <string.h>

/* user code (top of header file) */
#include "rtmodel.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  CAN_MESSAGE_BUS CANPack4;            /* '<S2>/CAN Pack4' */
  CAN_MESSAGE_BUS BusAssignment;       /* '<S9>/Bus Assignment' */
  int_T CANUnpack_ModeSignalID;        /* '<S10>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S10>/CAN Unpack' */
  uint32_T Memory1_PreviousInput;      /* '<S35>/Memory1' */
  uint32_T Counter_Count;              /* '<S35>/Counter' */
  uint32_T Memory1_PreviousInput_h;    /* '<S31>/Memory1' */
  uint32_T Counter_Count_k;            /* '<S31>/Counter' */
  uint32_T Memory1_PreviousInput_a;    /* '<S27>/Memory1' */
  uint32_T Counter_Count_n;            /* '<S27>/Counter' */
  uint8_T Data[8];
  uint8_T CANUnpack_o1[8];             /* '<S10>/CAN Unpack' */
  uint8_T Memory_PreviousInput[8];     /* '<S32>/Memory' */
  uint8_T Memory_PreviousInput_d[8];   /* '<S28>/Memory' */
  uint8_T Memory_PreviousInput_c[8];   /* '<S24>/Memory' */
  uint8_T CANUnpack_o2;                /* '<S10>/CAN Unpack' */
  uint8_T DelayOneStep_DSTATE;         /* '<S3>/Delay One Step' */
  uint8_T is_active_c3_stm32f207_template;/* '<S3>/Chart' */
  uint8_T is_RED_LED;                  /* '<S3>/Chart' */
  uint8_T is_BLUE_LED;                 /* '<S3>/Chart' */
  uint8_T is_GREEN_LED;                /* '<S3>/Chart' */
  uint8_T temporalCounter_i1;          /* '<S3>/Chart' */
  uint8_T temporalCounter_i2;          /* '<S3>/Chart' */
  uint8_T temporalCounter_i3;          /* '<S3>/Chart' */
  boolean_T BlueSts;                   /* '<S3>/AND2' */
  boolean_T GreenSts;                  /* '<S3>/AND1' */
  boolean_T RedSts;                    /* '<S3>/AND' */
  boolean_T Memory4;                   /* '<S35>/Memory4' */
  boolean_T AND;                       /* '<S32>/AND' */
  boolean_T CanSendMessage1;           /* '<S33>/CanSendMessage1' */
  boolean_T Memory4_g;                 /* '<S31>/Memory4' */
  boolean_T AND_d;                     /* '<S28>/AND' */
  boolean_T CanSendMessage1_a;         /* '<S29>/CanSendMessage1' */
  boolean_T Memory4_o;                 /* '<S27>/Memory4' */
  boolean_T AND_l;                     /* '<S24>/AND' */
  boolean_T CanSendMessage1_m;         /* '<S25>/CanSendMessage1' */
  boolean_T CastToBoolean;             /* '<S10>/Cast To Boolean' */
  boolean_T CastToBoolean1;            /* '<S10>/Cast To Boolean1' */
  boolean_T CastToBoolean3;            /* '<S10>/Cast To Boolean3' */
  boolean_T Memory4_PreviousInput;     /* '<S35>/Memory4' */
  boolean_T Memory3_PreviousInput;     /* '<S32>/Memory3' */
  boolean_T Memory4_PreviousInput_m;   /* '<S31>/Memory4' */
  boolean_T Memory3_PreviousInput_j;   /* '<S28>/Memory3' */
  boolean_T Memory4_PreviousInput_e;   /* '<S27>/Memory4' */
  boolean_T Memory3_PreviousInput_f;   /* '<S24>/Memory3' */
} DW_stm32f207_template_app_T;

/* Invariant block signals (default storage) */
typedef struct {
  const CAN_MESSAGE_BUS CANPack;       /* '<S2>/CAN Pack' */
  const CAN_MESSAGE_BUS CANPack1;      /* '<S2>/CAN Pack1' */
  const CAN_MESSAGE_BUS CANPack2;      /* '<S2>/CAN Pack2' */
  const CAN_MESSAGE_BUS CANPack3;      /* '<S2>/CAN Pack3' */
} ConstB_stm32f207_template_app_T;

/* Real-time Model Data Structure */
struct tag_RTM_stm32f207_template_ap_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_stm32f207_template_app_T stm32f207_template_app_DW;
extern const ConstB_stm32f207_template_app_T stm32f207_template_app_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void simulink_app_initialize(void);
extern void simulink_app_step(void);
extern void simulink_app_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stm32f207_template_a_T *const stm32f207_template_app_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Memory' : Unused code path elimination
 * Block '<S10>/Cast To Boolean10' : Unused code path elimination
 * Block '<S10>/Cast To Boolean11' : Unused code path elimination
 * Block '<S10>/Cast To Boolean13' : Unused code path elimination
 * Block '<S10>/Cast To Boolean14' : Unused code path elimination
 * Block '<S10>/Cast To Boolean15' : Unused code path elimination
 * Block '<S10>/Cast To Boolean5' : Unused code path elimination
 * Block '<S10>/Cast To Boolean6' : Unused code path elimination
 * Block '<S10>/Cast To Boolean7' : Unused code path elimination
 * Block '<S10>/Cast To Boolean8' : Unused code path elimination
 * Block '<S10>/Cast To Boolean9' : Unused code path elimination
 * Block '<S11>/Add1' : Unused code path elimination
 * Block '<S11>/Cast1' : Unused code path elimination
 * Block '<S11>/Memory1' : Unused code path elimination
 * Block '<S7>/Constant72' : Unused code path elimination
 * Block '<S12>/AND' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S12>/Constant2' : Unused code path elimination
 * Block '<S12>/Counter' : Unused code path elimination
 * Block '<S12>/Gain' : Unused code path elimination
 * Block '<S12>/Memory' : Unused code path elimination
 * Block '<S12>/Memory1' : Unused code path elimination
 * Block '<S12>/NOT' : Unused code path elimination
 * Block '<S12>/Product' : Unused code path elimination
 * Block '<S12>/Relational Operator' : Unused code path elimination
 * Block '<S12>/Relational Operator1' : Unused code path elimination
 * Block '<S12>/Weighted Sample Time' : Unused code path elimination
 * Block '<S12>/XOR' : Unused code path elimination
 * Block '<S15>/CAN Unpack' : Unused code path elimination
 * Block '<S15>/Cast To Boolean' : Unused code path elimination
 * Block '<S15>/Cast To Boolean1' : Unused code path elimination
 * Block '<S15>/Cast To Boolean10' : Unused code path elimination
 * Block '<S15>/Cast To Boolean11' : Unused code path elimination
 * Block '<S15>/Cast To Boolean12' : Unused code path elimination
 * Block '<S15>/Cast To Boolean13' : Unused code path elimination
 * Block '<S15>/Cast To Boolean14' : Unused code path elimination
 * Block '<S15>/Cast To Boolean15' : Unused code path elimination
 * Block '<S15>/Cast To Boolean2' : Unused code path elimination
 * Block '<S15>/Cast To Boolean3' : Unused code path elimination
 * Block '<S15>/Cast To Boolean4' : Unused code path elimination
 * Block '<S15>/Cast To Boolean5' : Unused code path elimination
 * Block '<S15>/Cast To Boolean6' : Unused code path elimination
 * Block '<S15>/Cast To Boolean7' : Unused code path elimination
 * Block '<S15>/Cast To Boolean8' : Unused code path elimination
 * Block '<S15>/Cast To Boolean9' : Unused code path elimination
 * Block '<S17>/Add1' : Unused code path elimination
 * Block '<S17>/Cast1' : Unused code path elimination
 * Block '<S17>/Memory1' : Unused code path elimination
 * Block '<S16>/Bus Assignment' : Unused code path elimination
 * Block '<S16>/Cast To Double' : Unused code path elimination
 * Block '<S16>/initCanBus' : Unused code path elimination
 * Block '<S14>/Constant2' : Unused code path elimination
 * Block '<S18>/AND' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S18>/Constant2' : Unused code path elimination
 * Block '<S18>/Counter' : Unused code path elimination
 * Block '<S18>/Gain' : Unused code path elimination
 * Block '<S18>/Memory' : Unused code path elimination
 * Block '<S18>/Memory1' : Unused code path elimination
 * Block '<S18>/NOT' : Unused code path elimination
 * Block '<S18>/Product' : Unused code path elimination
 * Block '<S18>/Relational Operator' : Unused code path elimination
 * Block '<S18>/Relational Operator1' : Unused code path elimination
 * Block '<S18>/Weighted Sample Time' : Unused code path elimination
 * Block '<S18>/XOR' : Unused code path elimination
 * Block '<S10>/Cast To Boolean12' : Eliminate redundant data type conversion
 * Block '<S10>/Cast To Boolean2' : Eliminate redundant data type conversion
 * Block '<S10>/Cast To Boolean4' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'stm32f207_template_app'
 * '<S1>'   : 'stm32f207_template_app/CanRx'
 * '<S2>'   : 'stm32f207_template_app/CanTx'
 * '<S3>'   : 'stm32f207_template_app/MainLogic'
 * '<S4>'   : 'stm32f207_template_app/CanRx/Can1RxProcces'
 * '<S5>'   : 'stm32f207_template_app/CanRx/Can2RxProcces'
 * '<S6>'   : 'stm32f207_template_app/CanRx/Can1RxProcces/ParsingRxCanMsgs1'
 * '<S7>'   : 'stm32f207_template_app/CanRx/Can1RxProcces/TimeoutsCheck1'
 * '<S8>'   : 'stm32f207_template_app/CanRx/Can1RxProcces/ParsingRxCanMsgs1/If Action Subsystem'
 * '<S9>'   : 'stm32f207_template_app/CanRx/Can1RxProcces/ParsingRxCanMsgs1/ÑanReceiveMsgFromAll1'
 * '<S10>'  : 'stm32f207_template_app/CanRx/Can1RxProcces/ParsingRxCanMsgs1/If Action Subsystem/Can_ButtonsProtocolRx'
 * '<S11>'  : 'stm32f207_template_app/CanRx/Can1RxProcces/ParsingRxCanMsgs1/If Action Subsystem/Can_ButtonsProtocolRx/msgCntr2'
 * '<S12>'  : 'stm32f207_template_app/CanRx/Can1RxProcces/TimeoutsCheck1/TimeoutCheck2'
 * '<S13>'  : 'stm32f207_template_app/CanRx/Can2RxProcces/ParsingRxCanMsgs2'
 * '<S14>'  : 'stm32f207_template_app/CanRx/Can2RxProcces/TimeoutsCheck'
 * '<S15>'  : 'stm32f207_template_app/CanRx/Can2RxProcces/ParsingRxCanMsgs2/Can_ButtonsProtocolRx'
 * '<S16>'  : 'stm32f207_template_app/CanRx/Can2RxProcces/ParsingRxCanMsgs2/ÑanReceiveMsgFromAll1'
 * '<S17>'  : 'stm32f207_template_app/CanRx/Can2RxProcces/ParsingRxCanMsgs2/Can_ButtonsProtocolRx/msgCntr2'
 * '<S18>'  : 'stm32f207_template_app/CanRx/Can2RxProcces/TimeoutsCheck/TimeoutCheck'
 * '<S19>'  : 'stm32f207_template_app/CanTx/ÑanSendMsg'
 * '<S20>'  : 'stm32f207_template_app/CanTx/ÑanSendMsg1'
 * '<S21>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg'
 * '<S22>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg1'
 * '<S23>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg2'
 * '<S24>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg/CanTxPMsg'
 * '<S25>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg/CanTxPMsg/CAN send'
 * '<S26>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg/CanTxPMsg/Compare To Constant'
 * '<S27>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg/CanTxPMsg/PeriodSendGenerator'
 * '<S28>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg1/CanTxPMsg'
 * '<S29>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg1/CanTxPMsg/CAN send'
 * '<S30>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg1/CanTxPMsg/Compare To Constant'
 * '<S31>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg1/CanTxPMsg/PeriodSendGenerator'
 * '<S32>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg2/CanTxPMsg'
 * '<S33>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg2/CanTxPMsg/CAN send'
 * '<S34>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg2/CanTxPMsg/Compare To Constant'
 * '<S35>'  : 'stm32f207_template_app/CanTx/ÑanSendPeriodMsg2/CanTxPMsg/PeriodSendGenerator'
 * '<S36>'  : 'stm32f207_template_app/MainLogic/Chart'
 * '<S37>'  : 'stm32f207_template_app/MainLogic/LedControl'
 * '<S38>'  : 'stm32f207_template_app/MainLogic/LedControl1'
 * '<S39>'  : 'stm32f207_template_app/MainLogic/LedControl2'
 */

/*-
 * Requirements for '<Root>': stm32f207_template_app

 */
#endif                                 /* RTW_HEADER_simulink_app_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
