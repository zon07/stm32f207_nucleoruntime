/*
 * File: simulink_app.h
 *
 * Code generated for Simulink model 'stm32f207_template_app'.
 *
 * Model version                  : 1.536
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul  2 00:01:11 2025
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
#include "rtwtypes.h"
#endif                             /* stm32f207_template_app_COMMON_INCLUDES_ */

#include "simulink_apptypes.h"

/* user code (top of header file) */
#include "rtmodel.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_stm32f207_template;/* '<S1>/Chart' */
  uint8_T is_RED_LED;                  /* '<S1>/Chart' */
  uint8_T is_BLUE_LED;                 /* '<S1>/Chart' */
  uint8_T is_GREEN_LED;                /* '<S1>/Chart' */
  uint8_T temporalCounter_i1;          /* '<S1>/Chart' */
  uint8_T temporalCounter_i2;          /* '<S1>/Chart' */
  uint8_T temporalCounter_i3;          /* '<S1>/Chart' */
} DW_stm32f207_template_app_T;

/* Block signals and states (default storage) */
extern DW_stm32f207_template_app_T stm32f207_template_app_DW;

/* Model entry point functions */
extern void simulink_app_initialize(void);
extern void simulink_app_step(void);
extern void simulink_app_terminate(void);

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
 * '<S1>'   : 'stm32f207_template_app/MainLogic'
 * '<S2>'   : 'stm32f207_template_app/MainLogic/Chart'
 * '<S3>'   : 'stm32f207_template_app/MainLogic/Subsystem'
 * '<S4>'   : 'stm32f207_template_app/MainLogic/Subsystem1'
 * '<S5>'   : 'stm32f207_template_app/MainLogic/Subsystem2'
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
