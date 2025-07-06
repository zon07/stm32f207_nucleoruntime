/*
 * File: simulink_appprivate.h
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

#ifndef RTW_HEADER_simulink_appprivate_h_
#define RTW_HEADER_simulink_appprivate_h_
#include "rtwtypes.h"
#include "simulink_apptypes.h"
#include "simulink_app.h"

extern void stm32f207_template_ap_anSendMsg(const CAN_MESSAGE_BUS *rtu_canMsg,
  boolean_T *rty_result);
extern void stm32f207_template_app_CANsend(const CAN_MESSAGE_BUS *rtu_canMsg,
  boolean_T *rty_result);

#endif                                 /* RTW_HEADER_simulink_appprivate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
