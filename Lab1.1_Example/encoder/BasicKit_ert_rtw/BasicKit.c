/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BasicKit.c
 *
 * Code generated for Simulink model 'BasicKit'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 30 21:38:58 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BasicKit.h"
#include "rtwtypes.h"
#include "BasicKit_private.h"

/* Block signals (default storage) */
B_BasicKit_T BasicKit_B;

/* Block states (default storage) */
DW_BasicKit_T BasicKit_DW;

/* Real-time model */
static RT_MODEL_BasicKit_T BasicKit_M_;
RT_MODEL_BasicKit_T *const BasicKit_M = &BasicKit_M_;

/* Model step function */
void BasicKit_step(void)
{
  uint32_T pinReadLoc;
  boolean_T tmp;

  /* MATLABSystem: '<S7>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S7>/Digital Port Read' */
  BasicKit_B.DigitalPortRead_f = ((pinReadLoc & 2U) != 0U);

  /* MATLABSystem: '<S9>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S9>/Digital Port Read' */
  BasicKit_B.DigitalPortRead = ((pinReadLoc & 16U) != 0U);

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  if (!BasicKit_DW.encoderCount_not_empty_h) {
    BasicKit_DW.encoderCount_not_empty_h = true;
    BasicKit_DW.lastA_n4 = BasicKit_B.DigitalPortRead_f;
  }

  if ((!BasicKit_DW.lastA_n4) && BasicKit_B.DigitalPortRead_f) {
    if (!BasicKit_B.DigitalPortRead) {
      BasicKit_DW.encoderCount_n++;
    } else {
      BasicKit_DW.encoderCount_n--;
    }
  }

  BasicKit_DW.lastA_n4 = BasicKit_B.DigitalPortRead_f;
  BasicKit_B.count_c = BasicKit_DW.encoderCount_n;

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */
  /* MATLAB Function: '<Root>/MATLAB Function5' */
  if (!BasicKit_DW.encoderCount_not_empty) {
    BasicKit_DW.encoderCount_not_empty = true;
    BasicKit_DW.lastA = BasicKit_B.DigitalPortRead_f;
    BasicKit_DW.lastB = BasicKit_B.DigitalPortRead;
  }

  if ((BasicKit_B.DigitalPortRead_f != BasicKit_DW.lastA) ||
      (BasicKit_B.DigitalPortRead != BasicKit_DW.lastB)) {
    if ((!BasicKit_DW.lastA) && BasicKit_B.DigitalPortRead_f) {
      if (!BasicKit_B.DigitalPortRead) {
        BasicKit_DW.encoderCount++;
      } else {
        BasicKit_DW.encoderCount--;
      }
    } else {
      tmp = !BasicKit_B.DigitalPortRead_f;
      if (BasicKit_DW.lastA && tmp) {
        if (BasicKit_B.DigitalPortRead) {
          BasicKit_DW.encoderCount++;
        } else {
          BasicKit_DW.encoderCount--;
        }
      } else if ((!BasicKit_DW.lastB) && BasicKit_B.DigitalPortRead) {
        if (BasicKit_B.DigitalPortRead_f) {
          BasicKit_DW.encoderCount++;
        } else {
          BasicKit_DW.encoderCount--;
        }
      } else if (BasicKit_DW.lastB && (!BasicKit_B.DigitalPortRead)) {
        if (tmp) {
          BasicKit_DW.encoderCount++;
        } else {
          BasicKit_DW.encoderCount--;
        }
      }
    }
  }

  BasicKit_DW.lastA = BasicKit_B.DigitalPortRead_f;
  BasicKit_DW.lastB = BasicKit_B.DigitalPortRead;
  BasicKit_B.count = BasicKit_DW.encoderCount;

  /* End of MATLAB Function: '<Root>/MATLAB Function5' */
  /* MATLAB Function: '<Root>/MATLAB Function4' */
  if (!BasicKit_DW.encoderCount_not_empty_c) {
    BasicKit_DW.encoderCount_not_empty_c = true;
    BasicKit_DW.lastA_n = BasicKit_B.DigitalPortRead_f;
  }

  if (BasicKit_DW.lastA_n != BasicKit_B.DigitalPortRead_f) {
    if (BasicKit_B.DigitalPortRead_f) {
      if (!BasicKit_B.DigitalPortRead) {
        BasicKit_DW.encoderCount_j++;
      } else {
        BasicKit_DW.encoderCount_j--;
      }
    } else if (BasicKit_B.DigitalPortRead) {
      BasicKit_DW.encoderCount_j++;
    } else {
      BasicKit_DW.encoderCount_j--;
    }
  }

  BasicKit_DW.lastA_n = BasicKit_B.DigitalPortRead_f;
  BasicKit_B.count_i = BasicKit_DW.encoderCount_j;

  /* End of MATLAB Function: '<Root>/MATLAB Function4' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  BasicKit_M->Timing.taskTime0 =
    ((time_T)(++BasicKit_M->Timing.clockTick0)) * BasicKit_M->Timing.stepSize0;
}

/* Model initialize function */
void BasicKit_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(BasicKit_M, -1);
  BasicKit_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  BasicKit_M->Sizes.checksums[0] = (3965904464U);
  BasicKit_M->Sizes.checksums[1] = (2516327938U);
  BasicKit_M->Sizes.checksums[2] = (221523236U);
  BasicKit_M->Sizes.checksums[3] = (286431770U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    BasicKit_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BasicKit_M->extModeInfo,
      &BasicKit_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BasicKit_M->extModeInfo, BasicKit_M->Sizes.checksums);
    rteiSetTPtr(BasicKit_M->extModeInfo, rtmGetTPtr(BasicKit_M));
  }
}

/* Model terminate function */
void BasicKit_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
