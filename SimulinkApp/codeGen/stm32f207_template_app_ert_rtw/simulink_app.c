/*
 * File: simulink_app.c
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

#include "simulink_app.h"
#include "simulink_apptypes.h"
#include "rtwtypes.h"
#include "simulink_appprivate.h"
#include "can_control.h"

/* Named constants for Chart: '<S3>/Chart' */
#define stm32f207_template_app_IN_OFF  ((uint8_T)1U)
#define stm32f207_template_app_IN_ON   ((uint8_T)2U)

/* Block signals and states (default storage) */
DW_stm32f207_template_app_T stm32f207_template_app_DW;

/* Real-time model */
static RT_MODEL_stm32f207_template_a_T stm32f207_template_app_M_;
RT_MODEL_stm32f207_template_a_T *const stm32f207_template_app_M =
  &stm32f207_template_app_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (stm32f207_template_app_M->Timing.TaskCounters.TID[1])++;
  if ((stm32f207_template_app_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.02s, 0.0s] */
    stm32f207_template_app_M->Timing.TaskCounters.TID[1] = 0;
  }

  (stm32f207_template_app_M->Timing.TaskCounters.TID[2])++;
  if ((stm32f207_template_app_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.5s, 0.0s] */
    stm32f207_template_app_M->Timing.TaskCounters.TID[2] = 0;
  }

  (stm32f207_template_app_M->Timing.TaskCounters.TID[3])++;
  if ((stm32f207_template_app_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [1.0s, 0.0s] */
    stm32f207_template_app_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * Output and update for function-call system:
 *    '<S2>/ÑanSendMsg'
 *    '<S2>/ÑanSendMsg1'
 */
void stm32f207_template_ap_anSendMsg(const CAN_MESSAGE_BUS *rtu_canMsg,
  boolean_T *rty_result)
{
  CAN_Msg_t rtb_BusAssignment;
  int32_T i;

  /* DataTypeConversion: '<S19>/Cast' */
  rtb_BusAssignment.Timestamp = (uint32_T)rtu_canMsg->Timestamp;

  /* BusAssignment: '<S19>/Bus Assignment' */
  rtb_BusAssignment.ID = rtu_canMsg->ID;
  rtb_BusAssignment.Length = rtu_canMsg->Length;
  for (i = 0; i < 8; i++) {
    uint8_T rtu_canMsg_0;
    rtu_canMsg_0 = rtu_canMsg->Data[i];
    rtb_BusAssignment.Data[i] = rtu_canMsg_0;
  }

  rtb_BusAssignment.Extended = rtu_canMsg->Extended;
  rtb_BusAssignment.Remote = rtu_canMsg->Remote;
  rtb_BusAssignment.Error = rtu_canMsg->Error;

  /* End of BusAssignment: '<S19>/Bus Assignment' */

  /* CCaller: '<S19>/CanSendMessage1' incorporates:
   *  Constant: '<S19>/can'
   */
  *rty_result = CanSendMessage(0, &rtb_BusAssignment);
}

/*
 * Output and update for function-call system:
 *    '<S24>/CAN send'
 *    '<S28>/CAN send'
 *    '<S32>/CAN send'
 */
void stm32f207_template_app_CANsend(const CAN_MESSAGE_BUS *rtu_canMsg, boolean_T
  *rty_result)
{
  CAN_Msg_t rtb_BusAssignment;
  int32_T i;
  uint32_T rtb_Cast_h;

  /* DataTypeConversion: '<S25>/Cast' */
  rtb_Cast_h = (uint32_T)rtu_canMsg->Timestamp;

  /* BusAssignment: '<S25>/Bus Assignment' */
  rtb_BusAssignment.ID = rtu_canMsg->ID;
  rtb_BusAssignment.Length = rtu_canMsg->Length;
  for (i = 0; i < 8; i++) {
    uint8_T rtu_canMsg_0;
    rtu_canMsg_0 = rtu_canMsg->Data[i];
    rtb_BusAssignment.Data[i] = rtu_canMsg_0;
  }

  rtb_BusAssignment.Extended = rtu_canMsg->Extended;
  rtb_BusAssignment.Remote = rtu_canMsg->Remote;
  rtb_BusAssignment.Error = rtu_canMsg->Error;
  rtb_BusAssignment.Timestamp = rtb_Cast_h;

  /* End of BusAssignment: '<S25>/Bus Assignment' */

  /* CCaller: '<S25>/CanSendMessage1' incorporates:
   *  Constant: '<S25>/can'
   */
  *rty_result = CanSendMessage(0, &rtb_BusAssignment);
}

/* Model step function */
void simulink_app_step(void)
{
  CAN_Msg_t rtb_CanGetAllMessages1_o2;
  CAN_Msg_t rtb_CanGetAllMessages1_o2_j;
  int32_T i;
  int32_T s6_iter;
  uint32_T rtb_CastToDouble;
  uint8_T rtb_Add;
  boolean_T rtb_RelationalOperator1_c[8];
  boolean_T loopCond;
  boolean_T rtb_outBlueLed;
  boolean_T rtb_outGreenLed;

  /* Outputs for Atomic SubSystem: '<Root>/CanRx' */
  /* Outputs for Iterator SubSystem: '<S4>/ParsingRxCanMsgs1' incorporates:
   *  WhileIterator: '<S6>/While Iterator'
   */
  s6_iter = 1;

  /* Constant: '<S4>/Constant1' */
  loopCond = true;
  while ((boolean_T)((int32_T)(((s6_iter <= 50) ? ((int32_T)1) : ((int32_T)0)) &
           (loopCond ? ((int32_T)1) : ((int32_T)0))))) {
    /* Outputs for Atomic SubSystem: '<S6>/ÑanReceiveMsgFromAll1' */
    /* CCaller: '<S9>/CanGetAllMessages1' incorporates:
     *  Constant: '<S9>/can'
     */
    loopCond = CanGetAllMessages(0, &rtb_CanGetAllMessages1_o2_j);

    /* DataTypeConversion: '<S9>/Cast To Double' */
    rtb_CastToDouble = rtb_CanGetAllMessages1_o2_j.Timestamp;

    /* BusAssignment: '<S9>/Bus Assignment' */
    stm32f207_template_app_DW.BusAssignment.ID = rtb_CanGetAllMessages1_o2_j.ID;
    stm32f207_template_app_DW.BusAssignment.Extended =
      rtb_CanGetAllMessages1_o2_j.Extended;
    for (i = 0; i < 8; i++) {
      stm32f207_template_app_DW.BusAssignment.Data[i] =
        rtb_CanGetAllMessages1_o2_j.Data[i];
    }

    stm32f207_template_app_DW.BusAssignment.Length =
      rtb_CanGetAllMessages1_o2_j.Length;
    stm32f207_template_app_DW.BusAssignment.Remote =
      rtb_CanGetAllMessages1_o2_j.Remote;
    stm32f207_template_app_DW.BusAssignment.Error =
      rtb_CanGetAllMessages1_o2_j.Error;
    stm32f207_template_app_DW.BusAssignment.Timestamp = (real_T)rtb_CastToDouble;

    /* End of BusAssignment: '<S9>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S6>/ÑanReceiveMsgFromAll1' */

    /* If: '<S6>/If' incorporates:
     *  DataTypeConversion: '<S6>/Cast'
     */
    if (loopCond) {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* S-Function (scanunpack): '<S10>/CAN Unpack' */
      {
        /* S-Function (scanunpack): '<S10>/CAN Unpack' */
        uint8_T msgReceived = 0;
        if ((8 == stm32f207_template_app_DW.BusAssignment.Length) &&
            (stm32f207_template_app_DW.BusAssignment.ID != INVALID_CAN_ID) ) {
          if ((418385749 == stm32f207_template_app_DW.BusAssignment.ID) && (1U ==
               stm32f207_template_app_DW.BusAssignment.Extended) ) {
            msgReceived = 1;
            (void) memcpy(&stm32f207_template_app_DW.CANUnpack_o1[0],
                          stm32f207_template_app_DW.BusAssignment.Data,
                          8 * sizeof(uint8_T));
          }
        }

        /* Status port */
        stm32f207_template_app_DW.CANUnpack_o2 = msgReceived;
      }

      /* DataTypeConversion: '<S10>/Cast To Boolean' */
      stm32f207_template_app_DW.CastToBoolean =
        (stm32f207_template_app_DW.CANUnpack_o1[0] != 0U);

      /* DataTypeConversion: '<S10>/Cast To Boolean1' */
      stm32f207_template_app_DW.CastToBoolean1 =
        (stm32f207_template_app_DW.CANUnpack_o1[1] != 0U);

      /* DataTypeConversion: '<S10>/Cast To Boolean3' */
      stm32f207_template_app_DW.CastToBoolean3 =
        (stm32f207_template_app_DW.CANUnpack_o1[2] != 0U);

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
    }

    /* End of If: '<S6>/If' */
    s6_iter++;
  }

  /* End of Outputs for SubSystem: '<S4>/ParsingRxCanMsgs1' */

  /* Outputs for Iterator SubSystem: '<S5>/ParsingRxCanMsgs2' incorporates:
   *  WhileIterator: '<S13>/While Iterator'
   */
  s6_iter = 1;

  /* Constant: '<S5>/Constant70' */
  loopCond = true;
  while ((boolean_T)((int32_T)(((s6_iter <= 50) ? ((int32_T)1) : ((int32_T)0)) &
           (loopCond ? ((int32_T)1) : ((int32_T)0))))) {
    /* Outputs for Atomic SubSystem: '<S13>/ÑanReceiveMsgFromAll1' */
    /* CCaller: '<S16>/CanGetAllMessages1' incorporates:
     *  Constant: '<S16>/can'
     */
    loopCond = CanGetAllMessages(1, &rtb_CanGetAllMessages1_o2);

    /* End of Outputs for SubSystem: '<S13>/ÑanReceiveMsgFromAll1' */
    s6_iter++;
  }

  /* End of Outputs for SubSystem: '<S5>/ParsingRxCanMsgs2' */
  /* End of Outputs for SubSystem: '<Root>/CanRx' */

  /* Outputs for Atomic SubSystem: '<Root>/MainLogic' */
  if (stm32f207_template_app_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S3>/Constant11'
     *  Delay: '<S3>/Delay One Step'
     */
    rtb_Add = (uint8_T)((uint32_T)stm32f207_template_app_DW.DelayOneStep_DSTATE
                        + 1U);
  }

  /* Chart: '<S3>/Chart' */
  /* Gateway: MainLogic/Chart */
  if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i1 < 31U) {
    stm32f207_template_app_DW.temporalCounter_i1 = (uint8_T)((uint32_T)
      stm32f207_template_app_DW.temporalCounter_i1 + 1U);
  }

  if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i2 < 63U) {
    stm32f207_template_app_DW.temporalCounter_i2 = (uint8_T)((uint32_T)
      stm32f207_template_app_DW.temporalCounter_i2 + 1U);
  }

  if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i3 < 127U) {
    stm32f207_template_app_DW.temporalCounter_i3 = (uint8_T)((uint32_T)
      stm32f207_template_app_DW.temporalCounter_i3 + 1U);
  }

  /* During: MainLogic/Chart */
  if ((uint32_T)stm32f207_template_app_DW.is_active_c3_stm32f207_template == 0U)
  {
    /* Entry: MainLogic/Chart */
    stm32f207_template_app_DW.is_active_c3_stm32f207_template = 1U;

    /* Entry Internal: MainLogic/Chart */
    /* Entry Internal 'RED_LED': '<S36>:25' */
    /* Transition: '<S36>:27' */
    stm32f207_template_app_DW.temporalCounter_i1 = 0U;
    stm32f207_template_app_DW.is_RED_LED = stm32f207_template_app_IN_OFF;

    /* Entry 'OFF': '<S36>:21' */
    /* '<S36>:21:3' outRedLed = true; */
    loopCond = true;

    /* Entry Internal 'BLUE_LED': '<S36>:26' */
    /* Transition: '<S36>:28' */
    stm32f207_template_app_DW.temporalCounter_i2 = 0U;
    stm32f207_template_app_DW.is_BLUE_LED = stm32f207_template_app_IN_OFF;

    /* Entry 'OFF': '<S36>:7' */
    /* '<S36>:7:3' outBlueLed = true; */
    rtb_outBlueLed = true;

    /* Entry Internal 'GREEN_LED': '<S36>:29' */
    /* Transition: '<S36>:32' */
    stm32f207_template_app_DW.temporalCounter_i3 = 0U;
    stm32f207_template_app_DW.is_GREEN_LED = stm32f207_template_app_IN_OFF;

    /* Entry 'OFF': '<S36>:12' */
    /* '<S36>:12:3' outGreenLed = true; */
    rtb_outGreenLed = true;
  } else {
    /* During 'RED_LED': '<S36>:25' */
    if ((uint32_T)stm32f207_template_app_DW.is_RED_LED ==
        stm32f207_template_app_IN_OFF) {
      loopCond = true;

      /* During 'OFF': '<S36>:21' */
      /* '<S36>:24:1' sf_internal_predicateOutput = after(100, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i1 >= 10U) {
        /* Transition: '<S36>:24' */
        stm32f207_template_app_DW.temporalCounter_i1 = 0U;
        stm32f207_template_app_DW.is_RED_LED = stm32f207_template_app_IN_ON;

        /* Entry 'ON': '<S36>:22' */
        /* '<S36>:22:3' outRedLed = false; */
        loopCond = false;
      }
    } else {
      loopCond = false;

      /* During 'ON': '<S36>:22' */
      /* '<S36>:23:1' sf_internal_predicateOutput = after(250, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i1 >= 25U) {
        /* Transition: '<S36>:23' */
        stm32f207_template_app_DW.temporalCounter_i1 = 0U;
        stm32f207_template_app_DW.is_RED_LED = stm32f207_template_app_IN_OFF;

        /* Entry 'OFF': '<S36>:21' */
        /* '<S36>:21:3' outRedLed = true; */
        loopCond = true;
      }
    }

    /* During 'BLUE_LED': '<S36>:26' */
    if ((uint32_T)stm32f207_template_app_DW.is_BLUE_LED ==
        stm32f207_template_app_IN_OFF) {
      rtb_outBlueLed = true;

      /* During 'OFF': '<S36>:7' */
      /* '<S36>:10:1' sf_internal_predicateOutput = after(500, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i2 >= 50U) {
        /* Transition: '<S36>:10' */
        stm32f207_template_app_DW.temporalCounter_i2 = 0U;
        stm32f207_template_app_DW.is_BLUE_LED = stm32f207_template_app_IN_ON;

        /* Entry 'ON': '<S36>:8' */
        /* '<S36>:8:3' outBlueLed = false; */
        rtb_outBlueLed = false;
      }
    } else {
      rtb_outBlueLed = false;

      /* During 'ON': '<S36>:8' */
      /* '<S36>:9:1' sf_internal_predicateOutput = after(500, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i2 >= 50U) {
        /* Transition: '<S36>:9' */
        stm32f207_template_app_DW.temporalCounter_i2 = 0U;
        stm32f207_template_app_DW.is_BLUE_LED = stm32f207_template_app_IN_OFF;

        /* Entry 'OFF': '<S36>:7' */
        /* '<S36>:7:3' outBlueLed = true; */
        rtb_outBlueLed = true;
      }
    }

    /* During 'GREEN_LED': '<S36>:29' */
    if ((uint32_T)stm32f207_template_app_DW.is_GREEN_LED ==
        stm32f207_template_app_IN_OFF) {
      rtb_outGreenLed = true;

      /* During 'OFF': '<S36>:12' */
      /* '<S36>:15:1' sf_internal_predicateOutput = after(1000, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i3 >= 100U) {
        /* Transition: '<S36>:15' */
        stm32f207_template_app_DW.temporalCounter_i3 = 0U;
        stm32f207_template_app_DW.is_GREEN_LED = stm32f207_template_app_IN_ON;

        /* Entry 'ON': '<S36>:13' */
        /* '<S36>:13:3' outGreenLed = false; */
        rtb_outGreenLed = false;
      }
    } else {
      rtb_outGreenLed = false;

      /* During 'ON': '<S36>:13' */
      /* '<S36>:14:1' sf_internal_predicateOutput = after(1000, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i3 >= 100U) {
        /* Transition: '<S36>:14' */
        stm32f207_template_app_DW.temporalCounter_i3 = 0U;
        stm32f207_template_app_DW.is_GREEN_LED = stm32f207_template_app_IN_OFF;

        /* Entry 'OFF': '<S36>:12' */
        /* '<S36>:12:3' outGreenLed = true; */
        rtb_outGreenLed = true;
      }
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* Logic: '<S3>/AND2' */
  stm32f207_template_app_DW.BlueSts = stm32f207_template_app_DW.CastToBoolean &
    rtb_outBlueLed;

  /* CCaller: '<S37>/SetLedState1' incorporates:
   *  Constant: '<S37>/Constant'
   *  DataTypeConversion: '<S37>/Cast'
   */
  SetLedState((uint8_T)2U, (uint8_T)stm32f207_template_app_DW.BlueSts);

  /* Logic: '<S3>/AND1' */
  stm32f207_template_app_DW.GreenSts = stm32f207_template_app_DW.CastToBoolean1
    & rtb_outGreenLed;

  /* CCaller: '<S38>/SetLedState1' incorporates:
   *  Constant: '<S38>/Constant'
   *  DataTypeConversion: '<S38>/Cast'
   */
  SetLedState((uint8_T)1U, (uint8_T)stm32f207_template_app_DW.GreenSts);

  /* Logic: '<S3>/AND' */
  stm32f207_template_app_DW.RedSts = stm32f207_template_app_DW.CastToBoolean3 &
    loopCond;

  /* CCaller: '<S39>/SetLedState1' incorporates:
   *  Constant: '<S39>/Constant'
   *  DataTypeConversion: '<S39>/Cast'
   */
  SetLedState((uint8_T)3U, (uint8_T)stm32f207_template_app_DW.RedSts);
  if (stm32f207_template_app_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<S3>/Delay One Step' */
    stm32f207_template_app_DW.DelayOneStep_DSTATE = rtb_Add;

    /* Outputs for Atomic SubSystem: '<Root>/CanTx' */
    /* Outputs for Atomic SubSystem: '<S21>/CanTxPMsg' */
    /* Memory: '<S27>/Memory4' */
    stm32f207_template_app_DW.Memory4_o =
      stm32f207_template_app_DW.Memory4_PreviousInput_e;

    /* S-Function (sdspcount2): '<S27>/Counter' incorporates:
     *  Memory: '<S27>/Memory1'
     */
    if (stm32f207_template_app_DW.Memory4_o) {
      stm32f207_template_app_DW.Counter_Count_n = 0U;
    }

    if (stm32f207_template_app_DW.Memory1_PreviousInput_a != 0U) {
      stm32f207_template_app_DW.Counter_Count_n++;
    }

    /* RelationalOperator: '<S27>/Relational Operator3' incorporates:
     *  Constant: '<S27>/Constant3'
     *  Product: '<S27>/Product'
     *  S-Function (sdspcount2): '<S27>/Counter'
     *  SampleTimeMath: '<S27>/Weighted Sample Time'
     *
     * About '<S27>/Weighted Sample Time':
     *  y = K where K = ( w * Ts )
     */
    rtb_outBlueLed = ((uint32_T)((real32_T)(20.0F * (real32_T)
      stm32f207_template_app_DW.Counter_Count_n)) >= 100U);

    /* Logic: '<S24>/AND' incorporates:
     *  Logic: '<S24>/OR'
     *  Logic: '<S27>/AND1'
     *  Memory: '<S24>/Memory3'
     */
    stm32f207_template_app_DW.AND_l =
      stm32f207_template_app_DW.Memory3_PreviousInput_f | rtb_outBlueLed;

    /* S-Function (fcgen): '<S24>/Function-Call Generator' */
    if (stm32f207_template_app_DW.AND_l) {
      /* Outputs for Function Call SubSystem: '<S24>/CAN send' */
      stm32f207_template_app_CANsend(&stm32f207_template_app_ConstB.CANPack,
        &stm32f207_template_app_DW.CanSendMessage1_m);

      /* End of Outputs for SubSystem: '<S24>/CAN send' */
    }

    /* End of Outputs for S-Function (fcgen): '<S24>/Function-Call Generator' */

    /* Update for Memory: '<S24>/Memory' */
    for (i = 0; i < 8; i++) {
      stm32f207_template_app_DW.Memory_PreviousInput_c[i] =
        stm32f207_template_app_ConstB.CANPack.Data[i];
    }

    /* End of Update for Memory: '<S24>/Memory' */

    /* Update for Memory: '<S27>/Memory1' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    stm32f207_template_app_DW.Memory1_PreviousInput_a = 1U;

    /* Update for Memory: '<S27>/Memory4' */
    stm32f207_template_app_DW.Memory4_PreviousInput_e = rtb_outBlueLed;

    /* Update for Memory: '<S24>/Memory3' incorporates:
     *  RelationalOperator: '<S26>/Compare'
     */
    stm32f207_template_app_DW.Memory3_PreviousInput_f =
      stm32f207_template_app_DW.CanSendMessage1_m ^ 1;

    /* End of Outputs for SubSystem: '<S21>/CanTxPMsg' */
    /* End of Outputs for SubSystem: '<Root>/CanTx' */
  }

  /* End of Outputs for SubSystem: '<Root>/MainLogic' */

  /* Outputs for Atomic SubSystem: '<Root>/CanTx' */
  /* Outputs for Atomic SubSystem: '<S22>/CanTxPMsg' */
  /* RelationalOperator: '<S28>/Relational Operator1' incorporates:
   *  Memory: '<S28>/Memory'
   */
  for (i = 0; i < 8; i++) {
    rtb_RelationalOperator1_c[i] =
      (stm32f207_template_app_ConstB.CANPack3.Data[i] !=
       stm32f207_template_app_DW.Memory_PreviousInput_d[i]);
  }

  /* End of RelationalOperator: '<S28>/Relational Operator1' */

  /* Memory: '<S31>/Memory4' */
  stm32f207_template_app_DW.Memory4_g =
    stm32f207_template_app_DW.Memory4_PreviousInput_m;

  /* S-Function (sdspcount2): '<S31>/Counter' incorporates:
   *  Memory: '<S31>/Memory1'
   */
  if (stm32f207_template_app_DW.Memory4_g) {
    stm32f207_template_app_DW.Counter_Count_k = 0U;
  }

  if (stm32f207_template_app_DW.Memory1_PreviousInput_h != 0U) {
    stm32f207_template_app_DW.Counter_Count_k++;
  }

  /* S-Function (sfix_bitop): '<S28>/Bitwise OR' */
  loopCond = rtb_RelationalOperator1_c[0];
  for (s6_iter = 0; s6_iter < 7; s6_iter++) {
    loopCond = rtb_RelationalOperator1_c[s6_iter + 1] | loopCond;
  }

  /* End of S-Function (sfix_bitop): '<S28>/Bitwise OR' */

  /* RelationalOperator: '<S31>/Relational Operator3' incorporates:
   *  Constant: '<S31>/Constant3'
   *  Product: '<S31>/Product'
   *  S-Function (sdspcount2): '<S31>/Counter'
   *  SampleTimeMath: '<S31>/Weighted Sample Time'
   *
   * About '<S31>/Weighted Sample Time':
   *  y = K where K = ( w * Ts )
   */
  rtb_outBlueLed = ((uint32_T)((real32_T)(10.0F * (real32_T)
    stm32f207_template_app_DW.Counter_Count_k)) >= 250U);

  /* Logic: '<S28>/AND' incorporates:
   *  Logic: '<S28>/OR'
   *  Logic: '<S31>/AND1'
   *  Memory: '<S28>/Memory3'
   */
  stm32f207_template_app_DW.AND_d =
    stm32f207_template_app_DW.Memory3_PreviousInput_j | rtb_outBlueLed;

  /* S-Function (fcgen): '<S28>/Function-Call Generator' */
  if (stm32f207_template_app_DW.AND_d) {
    /* Outputs for Function Call SubSystem: '<S28>/CAN send' */
    stm32f207_template_app_CANsend(&stm32f207_template_app_ConstB.CANPack3,
      &stm32f207_template_app_DW.CanSendMessage1_a);

    /* End of Outputs for SubSystem: '<S28>/CAN send' */
  }

  /* End of Outputs for S-Function (fcgen): '<S28>/Function-Call Generator' */

  /* Update for Memory: '<S28>/Memory' */
  for (i = 0; i < 8; i++) {
    stm32f207_template_app_DW.Memory_PreviousInput_d[i] =
      stm32f207_template_app_ConstB.CANPack3.Data[i];
  }

  /* End of Update for Memory: '<S28>/Memory' */

  /* Update for Memory: '<S31>/Memory1' incorporates:
   *  Constant: '<S31>/Constant2'
   */
  stm32f207_template_app_DW.Memory1_PreviousInput_h = 1U;

  /* Update for Memory: '<S31>/Memory4' */
  stm32f207_template_app_DW.Memory4_PreviousInput_m = rtb_outBlueLed;

  /* Update for Memory: '<S28>/Memory3' incorporates:
   *  RelationalOperator: '<S30>/Compare'
   */
  stm32f207_template_app_DW.Memory3_PreviousInput_j =
    stm32f207_template_app_DW.CanSendMessage1_a ^ 1;

  /* End of Outputs for SubSystem: '<S22>/CanTxPMsg' */
  if (stm32f207_template_app_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S2>/CAN Pack4' incorporates:
     *  Constant: '<S3>/Constant10'
     */
    stm32f207_template_app_DW.Data[0] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[1] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[2] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[3] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[4] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[5] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[6] = MAX_uint8_T;
    stm32f207_template_app_DW.Data[7] = rtb_Add;

    /* S-Function (scanpack): '<S2>/CAN Pack4' */
    /* S-Function (scanpack): '<S2>/CAN Pack4' */
    stm32f207_template_app_DW.CANPack4.ID = 418383107U;
    stm32f207_template_app_DW.CANPack4.Length = 8U;
    stm32f207_template_app_DW.CANPack4.Extended = 1U;
    stm32f207_template_app_DW.CANPack4.Remote = 0;
    stm32f207_template_app_DW.CANPack4.Data[0] = 0;
    stm32f207_template_app_DW.CANPack4.Data[1] = 0;
    stm32f207_template_app_DW.CANPack4.Data[2] = 0;
    stm32f207_template_app_DW.CANPack4.Data[3] = 0;
    stm32f207_template_app_DW.CANPack4.Data[4] = 0;
    stm32f207_template_app_DW.CANPack4.Data[5] = 0;
    stm32f207_template_app_DW.CANPack4.Data[6] = 0;
    stm32f207_template_app_DW.CANPack4.Data[7] = 0;

    {
      (void) memcpy((stm32f207_template_app_DW.CANPack4.Data),
                    &stm32f207_template_app_DW.Data[0],
                    8 * sizeof(uint8_T));
    }

    /* Outputs for Atomic SubSystem: '<S23>/CanTxPMsg' */
    /* RelationalOperator: '<S32>/Relational Operator1' incorporates:
     *  Memory: '<S32>/Memory'
     */
    for (i = 0; i < 8; i++) {
      rtb_RelationalOperator1_c[i] = (stm32f207_template_app_DW.CANPack4.Data[i]
        != stm32f207_template_app_DW.Memory_PreviousInput[i]);
    }

    /* End of RelationalOperator: '<S32>/Relational Operator1' */

    /* Memory: '<S35>/Memory4' */
    stm32f207_template_app_DW.Memory4 =
      stm32f207_template_app_DW.Memory4_PreviousInput;

    /* S-Function (sdspcount2): '<S35>/Counter' incorporates:
     *  Memory: '<S35>/Memory1'
     */
    if (stm32f207_template_app_DW.Memory4) {
      stm32f207_template_app_DW.Counter_Count = 0U;
    }

    if (stm32f207_template_app_DW.Memory1_PreviousInput != 0U) {
      stm32f207_template_app_DW.Counter_Count++;
    }

    /* S-Function (sfix_bitop): '<S32>/Bitwise OR' */
    loopCond = rtb_RelationalOperator1_c[0];
    for (s6_iter = 0; s6_iter < 7; s6_iter++) {
      loopCond = rtb_RelationalOperator1_c[s6_iter + 1] | loopCond;
    }

    /* RelationalOperator: '<S35>/Relational Operator3' incorporates:
     *  Constant: '<S35>/Constant3'
     *  Product: '<S35>/Product'
     *  S-Function (sdspcount2): '<S35>/Counter'
     *  SampleTimeMath: '<S35>/Weighted Sample Time'
     *
     * About '<S35>/Weighted Sample Time':
     *  y = K where K = ( w * Ts )
     */
    rtb_outBlueLed = ((uint32_T)((real32_T)(20.0F * (real32_T)
      stm32f207_template_app_DW.Counter_Count)) >= 500U);

    /* Logic: '<S32>/AND' incorporates:
     *  Logic: '<S32>/OR'
     *  Logic: '<S35>/AND1'
     *  Memory: '<S32>/Memory3'
     *  S-Function (sfix_bitop): '<S32>/Bitwise OR'
     */
    stm32f207_template_app_DW.AND = (boolean_T)((int32_T)
      ((stm32f207_template_app_DW.Memory3_PreviousInput ? ((int32_T)1) :
        ((int32_T)0)) | (rtb_outBlueLed ? ((int32_T)1) : ((int32_T)0)))) |
      loopCond;

    /* S-Function (fcgen): '<S32>/Function-Call Generator' */
    if (stm32f207_template_app_DW.AND) {
      /* Outputs for Function Call SubSystem: '<S32>/CAN send' */
      stm32f207_template_app_CANsend(&stm32f207_template_app_DW.CANPack4,
        &stm32f207_template_app_DW.CanSendMessage1);

      /* End of Outputs for SubSystem: '<S32>/CAN send' */
    }

    /* End of Outputs for S-Function (fcgen): '<S32>/Function-Call Generator' */

    /* Update for Memory: '<S32>/Memory' */
    for (i = 0; i < 8; i++) {
      stm32f207_template_app_DW.Memory_PreviousInput[i] =
        stm32f207_template_app_DW.CANPack4.Data[i];
    }

    /* End of Update for Memory: '<S32>/Memory' */

    /* Update for Memory: '<S35>/Memory1' incorporates:
     *  Constant: '<S35>/Constant2'
     */
    stm32f207_template_app_DW.Memory1_PreviousInput = 1U;

    /* Update for Memory: '<S35>/Memory4' */
    stm32f207_template_app_DW.Memory4_PreviousInput = rtb_outBlueLed;

    /* Update for Memory: '<S32>/Memory3' incorporates:
     *  RelationalOperator: '<S34>/Compare'
     */
    stm32f207_template_app_DW.Memory3_PreviousInput =
      stm32f207_template_app_DW.CanSendMessage1 ^ 1;

    /* End of Outputs for SubSystem: '<S23>/CanTxPMsg' */
  }

  if (stm32f207_template_app_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
     *  SubSystem: '<S2>/ÑanSendMsg'
     */
    stm32f207_template_ap_anSendMsg(&stm32f207_template_app_ConstB.CANPack1,
      &loopCond);

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator' */
  }

  if (stm32f207_template_app_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S2>/ÑanSendMsg1'
     */
    stm32f207_template_ap_anSendMsg(&stm32f207_template_app_ConstB.CANPack2,
      &loopCond);

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator1' */
  }

  /* End of Outputs for SubSystem: '<Root>/CanTx' */
  rate_scheduler();
}

/* Model initialize function */
void simulink_app_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/CanRx' */
  /* SystemInitialize for Iterator SubSystem: '<S4>/ParsingRxCanMsgs1' */
  /* SystemInitialize for IfAction SubSystem: '<S6>/If Action Subsystem' */
  /* Start for S-Function (scanunpack): '<S10>/CAN Unpack' */

  /*-----------S-Function Block: <S10>/CAN Unpack -----------------*/

  /* End of SystemInitialize for SubSystem: '<S6>/If Action Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S4>/ParsingRxCanMsgs1' */
  /* End of SystemInitialize for SubSystem: '<Root>/CanRx' */
}

/* Model terminate function */
void simulink_app_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
