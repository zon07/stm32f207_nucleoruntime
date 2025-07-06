/*
 * File: simulink_apptypes.h
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

#ifndef RTW_HEADER_simulink_apptypes_h_
#define RTW_HEADER_simulink_apptypes_h_
#include "can_control.h"
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DgVl0nMwADYdjH4ufj4U4B_
#define DEFINED_TYPEDEF_FOR_struct_DgVl0nMwADYdjH4ufj4U4B_

typedef struct {
  uint32_T ID_18F00F55;
} struct_DgVl0nMwADYdjH4ufj4U4B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WzikK1qbjf9I6jAd2rSR4F_
#define DEFINED_TYPEDEF_FOR_struct_WzikK1qbjf9I6jAd2rSR4F_

typedef struct {
  struct_DgVl0nMwADYdjH4ufj4U4B Pc;
} struct_WzikK1qbjf9I6jAd2rSR4F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ErBMq6nozVSYW4qq6jlGtB_
#define DEFINED_TYPEDEF_FOR_struct_ErBMq6nozVSYW4qq6jlGtB_

typedef struct {
  boolean_T Btn_1;
  boolean_T Btn_2;
  boolean_T Btn_3;
  boolean_T Btn_4;
  boolean_T Btn_5;
  boolean_T Btn_6;
  boolean_T Btn_7;
  boolean_T Btn_8;
} struct_ErBMq6nozVSYW4qq6jlGtB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vHtUVPyAYHJjgUMdIseD9D_
#define DEFINED_TYPEDEF_FOR_struct_vHtUVPyAYHJjgUMdIseD9D_

typedef struct {
  struct_ErBMq6nozVSYW4qq6jlGtB Pc;
} struct_vHtUVPyAYHJjgUMdIseD9D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tjolbYzHaYBM3fpriULadC_
#define DEFINED_TYPEDEF_FOR_struct_tjolbYzHaYBM3fpriULadC_

typedef struct {
  struct_DgVl0nMwADYdjH4ufj4U4B Test;
} struct_tjolbYzHaYBM3fpriULadC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BRX2eQGMKp0fq0Hy3caIa_
#define DEFINED_TYPEDEF_FOR_struct_BRX2eQGMKp0fq0Hy3caIa_

typedef struct {
  struct_ErBMq6nozVSYW4qq6jlGtB Test;
} struct_BRX2eQGMKp0fq0Hy3caIa;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_stm32f207_template_ap_T RT_MODEL_stm32f207_template_a_T;

#endif                                 /* RTW_HEADER_simulink_apptypes_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
