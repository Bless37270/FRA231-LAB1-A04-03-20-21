/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BasicKit.h
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

#ifndef BasicKit_h_
#define BasicKit_h_
#ifndef BasicKit_COMMON_INCLUDES_
#define BasicKit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "main.h"
#endif                                 /* BasicKit_COMMON_INCLUDES_ */

#include "BasicKit_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T count;                        /* '<Root>/MATLAB Function5' */
  real_T count_i;                      /* '<Root>/MATLAB Function4' */
  real_T count_c;                      /* '<Root>/MATLAB Function3' */
  boolean_T DigitalPortRead;           /* '<S9>/Digital Port Read' */
  boolean_T DigitalPortRead_f;         /* '<S7>/Digital Port Read' */
} B_BasicKit_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T encoderCount;                 /* '<Root>/MATLAB Function5' */
  real_T encoderCount_j;               /* '<Root>/MATLAB Function4' */
  real_T encoderCount_n;               /* '<Root>/MATLAB Function3' */
  boolean_T lastA;                     /* '<Root>/MATLAB Function5' */
  boolean_T lastB;                     /* '<Root>/MATLAB Function5' */
  boolean_T encoderCount_not_empty;    /* '<Root>/MATLAB Function5' */
  boolean_T lastA_n;                   /* '<Root>/MATLAB Function4' */
  boolean_T encoderCount_not_empty_c;  /* '<Root>/MATLAB Function4' */
  boolean_T lastA_n4;                  /* '<Root>/MATLAB Function3' */
  boolean_T encoderCount_not_empty_h;  /* '<Root>/MATLAB Function3' */
} DW_BasicKit_T;

/* Real-time Model Data Structure */
struct tag_RTM_BasicKit_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_BasicKit_T BasicKit_B;

/* Block states (default storage) */
extern DW_BasicKit_T BasicKit_DW;

/* Model entry point functions */
extern void BasicKit_initialize(void);
extern void BasicKit_step(void);
extern void BasicKit_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BasicKit_T *const BasicKit_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'BasicKit'
 * '<S1>'   : 'BasicKit/Digital Port Read'
 * '<S2>'   : 'BasicKit/Digital Port Read7'
 * '<S3>'   : 'BasicKit/MATLAB Function3'
 * '<S4>'   : 'BasicKit/MATLAB Function4'
 * '<S5>'   : 'BasicKit/MATLAB Function5'
 * '<S6>'   : 'BasicKit/Digital Port Read/ECSoC'
 * '<S7>'   : 'BasicKit/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S8>'   : 'BasicKit/Digital Port Read7/ECSoC'
 * '<S9>'   : 'BasicKit/Digital Port Read7/ECSoC/ECSimCodegen'
 */
#endif                                 /* BasicKit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
