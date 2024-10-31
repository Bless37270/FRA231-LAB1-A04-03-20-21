/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BasicKit.c
 *
 * Code generated for Simulink model 'BasicKit'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 30 22:07:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BasicKit.h"
#include "BasicKit_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "BasicKit_private.h"

/* Block signals (default storage) */
B_BasicKit_T BasicKit_B;

/* Block states (default storage) */
DW_BasicKit_T BasicKit_DW;

/* Real-time model */
static RT_MODEL_BasicKit_T BasicKit_M_;
RT_MODEL_BasicKit_T *const BasicKit_M = &BasicKit_M_;

/* Forward declaration for local functions */
static void BasicKit_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void BasicKit_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder4' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void BasicKit_step(void)
{
  /* MATLABSystem: '<Root>/Encoder4' */
  BasicKit_B.pluse = getTimerCounterValueForG4(BasicKit_DW.obj.TimerHandle,
    false, NULL);

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
  BasicKit_M->Sizes.checksums[0] = (2780238372U);
  BasicKit_M->Sizes.checksums[1] = (3726408935U);
  BasicKit_M->Sizes.checksums[2] = (3706720655U);
  BasicKit_M->Sizes.checksums[3] = (3569618259U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    BasicKit_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BasicKit_M->extModeInfo,
      &BasicKit_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BasicKit_M->extModeInfo, BasicKit_M->Sizes.checksums);
    rteiSetTPtr(BasicKit_M->extModeInfo, rtmGetTPtr(BasicKit_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder4' */
  BasicKit_DW.obj.isInitialized = 0;
  BasicKit_DW.obj.matlabCodegenIsDeleted = false;
  BasicKit_SystemCore_setup(&BasicKit_DW.obj);
}

/* Model terminate function */
void BasicKit_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder4' */
  if (!BasicKit_DW.obj.matlabCodegenIsDeleted) {
    BasicKit_DW.obj.matlabCodegenIsDeleted = true;
    if ((BasicKit_DW.obj.isInitialized == 1) && BasicKit_DW.obj.isSetupComplete)
    {
      disableCounter(BasicKit_DW.obj.TimerHandle);
      disableTimerInterrupts(BasicKit_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(BasicKit_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(BasicKit_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
