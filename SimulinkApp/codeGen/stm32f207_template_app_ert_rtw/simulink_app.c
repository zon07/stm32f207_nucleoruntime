/*
 * File: simulink_app.c
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

#include "simulink_app.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<S1>/Chart' */
#define stm32f207_template_app_IN_OFF  ((uint8_T)1U)
#define stm32f207_template_app_IN_ON   ((uint8_T)2U)

/* Block signals and states (default storage) */
DW_stm32f207_template_app_T stm32f207_template_app_DW;

/* Model step function */
void simulink_app_step(void)
{
  uint8_T rtb_outBlueLed;
  uint8_T rtb_outGreenLed;
  uint8_T rtb_outRedLed;

  /* Outputs for Atomic SubSystem: '<Root>/MainLogic' */
  /* Chart: '<S1>/Chart' */
  /* Gateway: MainLogic/Chart */
  if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i1 < 15U) {
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
    /* Entry Internal 'RED_LED': '<S2>:25' */
    /* Transition: '<S2>:27' */
    stm32f207_template_app_DW.temporalCounter_i1 = 0U;
    stm32f207_template_app_DW.is_RED_LED = stm32f207_template_app_IN_OFF;

    /* Entry 'OFF': '<S2>:21' */
    /* '<S2>:21:3' outRedLed = 1; */
    rtb_outRedLed = 1U;

    /* Entry Internal 'BLUE_LED': '<S2>:26' */
    /* Transition: '<S2>:28' */
    stm32f207_template_app_DW.temporalCounter_i2 = 0U;
    stm32f207_template_app_DW.is_BLUE_LED = stm32f207_template_app_IN_OFF;

    /* Entry 'OFF': '<S2>:7' */
    /* '<S2>:7:3' outBlueLed = 1; */
    rtb_outBlueLed = 1U;

    /* Entry Internal 'GREEN_LED': '<S2>:29' */
    /* Transition: '<S2>:32' */
    stm32f207_template_app_DW.temporalCounter_i3 = 0U;
    stm32f207_template_app_DW.is_GREEN_LED = stm32f207_template_app_IN_OFF;

    /* Entry 'OFF': '<S2>:12' */
    /* '<S2>:12:3' outGreenLed = 1; */
    rtb_outGreenLed = 1U;
  } else {
    /* During 'RED_LED': '<S2>:25' */
    if ((uint32_T)stm32f207_template_app_DW.is_RED_LED ==
        stm32f207_template_app_IN_OFF) {
      rtb_outRedLed = 1U;

      /* During 'OFF': '<S2>:21' */
      /* '<S2>:24:1' sf_internal_predicateOutput = after(100, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i1 >= 10U) {
        /* Transition: '<S2>:24' */
        stm32f207_template_app_DW.temporalCounter_i1 = 0U;
        stm32f207_template_app_DW.is_RED_LED = stm32f207_template_app_IN_ON;

        /* Entry 'ON': '<S2>:22' */
        /* '<S2>:22:3' outRedLed = 0; */
        rtb_outRedLed = 0U;
      }
    } else {
      rtb_outRedLed = 0U;

      /* During 'ON': '<S2>:22' */
      /* '<S2>:23:1' sf_internal_predicateOutput = after(100, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i1 >= 10U) {
        /* Transition: '<S2>:23' */
        stm32f207_template_app_DW.temporalCounter_i1 = 0U;
        stm32f207_template_app_DW.is_RED_LED = stm32f207_template_app_IN_OFF;

        /* Entry 'OFF': '<S2>:21' */
        /* '<S2>:21:3' outRedLed = 1; */
        rtb_outRedLed = 1U;
      }
    }

    /* During 'BLUE_LED': '<S2>:26' */
    if ((uint32_T)stm32f207_template_app_DW.is_BLUE_LED ==
        stm32f207_template_app_IN_OFF) {
      rtb_outBlueLed = 1U;

      /* During 'OFF': '<S2>:7' */
      /* '<S2>:10:1' sf_internal_predicateOutput = after(500, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i2 >= 50U) {
        /* Transition: '<S2>:10' */
        stm32f207_template_app_DW.temporalCounter_i2 = 0U;
        stm32f207_template_app_DW.is_BLUE_LED = stm32f207_template_app_IN_ON;

        /* Entry 'ON': '<S2>:8' */
        /* '<S2>:8:3' outBlueLed = 0; */
        rtb_outBlueLed = 0U;
      }
    } else {
      rtb_outBlueLed = 0U;

      /* During 'ON': '<S2>:8' */
      /* '<S2>:9:1' sf_internal_predicateOutput = after(500, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i2 >= 50U) {
        /* Transition: '<S2>:9' */
        stm32f207_template_app_DW.temporalCounter_i2 = 0U;
        stm32f207_template_app_DW.is_BLUE_LED = stm32f207_template_app_IN_OFF;

        /* Entry 'OFF': '<S2>:7' */
        /* '<S2>:7:3' outBlueLed = 1; */
        rtb_outBlueLed = 1U;
      }
    }

    /* During 'GREEN_LED': '<S2>:29' */
    if ((uint32_T)stm32f207_template_app_DW.is_GREEN_LED ==
        stm32f207_template_app_IN_OFF) {
      rtb_outGreenLed = 1U;

      /* During 'OFF': '<S2>:12' */
      /* '<S2>:15:1' sf_internal_predicateOutput = after(1000, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i3 >= 100U) {
        /* Transition: '<S2>:15' */
        stm32f207_template_app_DW.temporalCounter_i3 = 0U;
        stm32f207_template_app_DW.is_GREEN_LED = stm32f207_template_app_IN_ON;

        /* Entry 'ON': '<S2>:13' */
        /* '<S2>:13:3' outGreenLed = 0; */
        rtb_outGreenLed = 0U;
      }
    } else {
      rtb_outGreenLed = 0U;

      /* During 'ON': '<S2>:13' */
      /* '<S2>:14:1' sf_internal_predicateOutput = after(1000, msec); */
      if ((uint32_T)stm32f207_template_app_DW.temporalCounter_i3 >= 100U) {
        /* Transition: '<S2>:14' */
        stm32f207_template_app_DW.temporalCounter_i3 = 0U;
        stm32f207_template_app_DW.is_GREEN_LED = stm32f207_template_app_IN_OFF;

        /* Entry 'OFF': '<S2>:12' */
        /* '<S2>:12:3' outGreenLed = 1; */
        rtb_outGreenLed = 1U;
      }
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* CCaller: '<S3>/SetLedState' incorporates:
   *  Constant: '<S3>/Constant'
   */
  SetLedState((uint8_T)1U, rtb_outBlueLed);

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem1' */
  /* CCaller: '<S4>/SetLedState2' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  SetLedState((uint8_T)3U, rtb_outRedLed);

  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem2' */
  /* CCaller: '<S5>/SetLedState1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  SetLedState((uint8_T)2U, rtb_outGreenLed);

  /* End of Outputs for SubSystem: '<S1>/Subsystem2' */
  /* End of Outputs for SubSystem: '<Root>/MainLogic' */
}

/* Model initialize function */
void simulink_app_initialize(void)
{
  /* (no initialization code required) */
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
