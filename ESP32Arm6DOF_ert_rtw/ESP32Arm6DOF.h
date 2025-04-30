/*
 * File: ESP32Arm6DOF.h
 *
 * Code generated for Simulink model 'ESP32Arm6DOF'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Apr 30 11:27:39 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ESP32Arm6DOF_h_
#define ESP32Arm6DOF_h_
#ifndef ESP32Arm6DOF_COMMON_INCLUDES_
#define ESP32Arm6DOF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#include "vl53l0x_main.h"
#endif                                 /* ESP32Arm6DOF_COMMON_INCLUDES_ */

#include "ESP32Arm6DOF_types.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S19>/Probe' */
  real_T Probe_f[2];                   /* '<S54>/Probe' */
  real_T Probe_a[2];                   /* '<S26>/Probe' */
  real_T Probe_e[2];                   /* '<S33>/Probe' */
  real_T Probe_m[2];                   /* '<S47>/Probe' */
  real_T Probe_fr[2];                  /* '<S40>/Probe' */
  real_T Saturation;                   /* '<S46>/Saturation' */
  real_T AvoidDividebyZero;            /* '<S40>/Avoid Divide by Zero' */
  real_T uT;                           /* '<S7>/1//T' */
  real_T Saturation_d;                 /* '<S25>/Saturation' */
  real_T AvoidDividebyZero_k;          /* '<S19>/Avoid Divide by Zero' */
  real_T uT_l;                         /* '<S4>/1//T' */
  real_T Saturation_n;                 /* '<S60>/Saturation' */
  real_T AvoidDividebyZero_l;          /* '<S54>/Avoid Divide by Zero' */
  real_T uT_j;                         /* '<S9>/1//T' */
  real_T Saturation_nm;                /* '<S32>/Saturation' */
  real_T AvoidDividebyZero_c;          /* '<S26>/Avoid Divide by Zero' */
  real_T uT_g;                         /* '<S5>/1//T' */
  real_T Saturation_h;                 /* '<S39>/Saturation' */
  real_T AvoidDividebyZero_o;          /* '<S33>/Avoid Divide by Zero' */
  real_T uT_f;                         /* '<S6>/1//T' */
  real_T Saturation_i;                 /* '<S53>/Saturation' */
  real_T AvoidDividebyZero_h;          /* '<S47>/Avoid Divide by Zero' */
  real_T uT_gp;                        /* '<S8>/1//T' */
  real_T DerivativeGain;               /* '<S87>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S97>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S91>/Integral Gain' */
  real_T BaseSig;                      /* '<S13>/fromWS_Signal 1' */
  real_T LowerSignal;                  /* '<S15>/fromWS_Signal 1' */
  real_T MidSignal;                    /* '<S16>/fromWS_Signal 1' */
  real_T UpperSignal;                  /* '<S18>/fromWS_Signal 1' */
  real_T RotationSignal;               /* '<S17>/fromWS_Signal 1' */
  real_T ClawSignal;                   /* '<S14>/fromWS_Signal 1' */
} B_ESP32Arm6DOF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_p_T obj;
                                   /* '<Root>/VL53L0X Time Of Flight Sensor.' */
  codertarget_arduinobase_int_p_T obj_i;
                                    /* '<Root>/VL53L0X Time Of Flight Sensor' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/Upper Servo' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/Standard Servo Write.' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Rotation Servo' */
  codertarget_arduinobase_inter_T obj_j;/* '<Root>/Mid Arm Servo' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Lower Arm Servo' */
  codertarget_arduinobase_inter_T obj_a;/* '<Root>/Claw Servo' */
  codertarget_arduinobase_inter_T obj_h5;/* '<Root>/Base Servo' */
  real_T Integrator_DSTATE;            /* '<S46>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S25>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S60>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S32>/Integrator' */
  real_T Integrator_DSTATE_c;          /* '<S39>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S53>/Integrator' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S13>/fromWS_Signal 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_p;            /* '<S15>/fromWS_Signal 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_n;            /* '<S16>/fromWS_Signal 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_d;            /* '<S18>/fromWS_Signal 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_f;            /* '<S17>/fromWS_Signal 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_nz;           /* '<S14>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S13>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_k;            /* '<S15>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_i;            /* '<S16>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_l;            /* '<S18>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_ko;           /* '<S17>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_a;            /* '<S14>/fromWS_Signal 1' */

  int8_T Integrator_PrevResetState;    /* '<S46>/Integrator' */
  int8_T Integrator_PrevResetState_a;  /* '<S25>/Integrator' */
  int8_T Integrator_PrevResetState_m;  /* '<S60>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S32>/Integrator' */
  int8_T Integrator_PrevResetState_ah; /* '<S39>/Integrator' */
  int8_T Integrator_PrevResetState_d;  /* '<S53>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S46>/Integrator' */
  uint8_T Integrator_IC_LOADING_l;     /* '<S25>/Integrator' */
  uint8_T Integrator_IC_LOADING_f;     /* '<S60>/Integrator' */
  uint8_T Integrator_IC_LOADING_o;     /* '<S32>/Integrator' */
  uint8_T Integrator_IC_LOADING_n;     /* '<S39>/Integrator' */
  uint8_T Integrator_IC_LOADING_b;     /* '<S53>/Integrator' */
  boolean_T EnabledSubsystem_MODE;     /* '<Root>/Enabled Subsystem' */
} DW_ESP32Arm6DOF_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S89>/Filter' */
  real_T Integrator_CSTATE;            /* '<S94>/Integrator' */
} X_ESP32Arm6DOF_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S89>/Filter' */
  real_T Integrator_CSTATE;            /* '<S94>/Integrator' */
} XDot_ESP32Arm6DOF_T;

/* State disabled  */
typedef struct {
  boolean_T Filter_CSTATE;             /* '<S89>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S94>/Integrator' */
} XDis_ESP32Arm6DOF_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<Root>/Sample and Hold' */
} PrevZCX_ESP32Arm6DOF_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output.' */
} ExtY_ESP32Arm6DOF_T;

/* Parameters (default storage) */
struct P_ESP32Arm6DOF_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S87>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S91>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S89>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S94>/Integrator'
                               */
  real_T LowPassFilterDiscreteorContinuo;
                              /* Mask Parameter: LowPassFilterDiscreteorContinuo
                               * Referenced by: '<S7>/K'
                               */
  real_T LowPassFilterDiscreteorContin_p;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_p
                               * Referenced by: '<S4>/K'
                               */
  real_T LowPassFilterDiscreteorContin_h;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_h
                               * Referenced by: '<S9>/K'
                               */
  real_T LowPassFilterDiscreteorContin_j;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_j
                               * Referenced by: '<S5>/K'
                               */
  real_T LowPassFilterDiscreteorContin_l;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_l
                               * Referenced by: '<S6>/K'
                               */
  real_T LowPassFilterDiscreteorContin_f;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_f
                               * Referenced by: '<S8>/K'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S97>/Filter Coefficient'
                                        */
  real_T LowPassFilterDiscreteorContin_g;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_g
                               * Referenced by: '<S40>/Time constant'
                               */
  real_T LowPassFilterDiscreteorContin_o;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_o
                               * Referenced by: '<S19>/Time constant'
                               */
  real_T LowPassFilterDiscreteorContin_e;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_e
                               * Referenced by: '<S54>/Time constant'
                               */
  real_T LowPassFilterDiscreteorConti_jx;
                              /* Mask Parameter: LowPassFilterDiscreteorConti_jx
                               * Referenced by: '<S26>/Time constant'
                               */
  real_T LowPassFilterDiscreteorContin_d;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_d
                               * Referenced by: '<S33>/Time constant'
                               */
  real_T LowPassFilterDiscreteorContin_i;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_i
                               * Referenced by: '<S47>/Time constant'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S43>/Constant'
                                       */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S22>/Constant'
                                     */
  real_T CompareToConstant_const_k; /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S57>/Constant'
                                     */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S29>/Constant'
                                     */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S36>/Constant'
                                     */
  real_T CompareToConstant_const_f; /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S50>/Constant'
                                     */
  real_T LowPassFilterDiscreteorConti_dy;
                              /* Mask Parameter: LowPassFilterDiscreteorConti_dy
                               * Referenced by: '<S40>/Constant'
                               */
  real_T LowPassFilterDiscreteorConti_ly;
                              /* Mask Parameter: LowPassFilterDiscreteorConti_ly
                               * Referenced by: '<S19>/Constant'
                               */
  real_T LowPassFilterDiscreteorConti_gi;
                              /* Mask Parameter: LowPassFilterDiscreteorConti_gi
                               * Referenced by: '<S54>/Constant'
                               */
  real_T LowPassFilterDiscreteorContin_m;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_m
                               * Referenced by: '<S26>/Constant'
                               */
  real_T LowPassFilterDiscreteorConti_fo;
                              /* Mask Parameter: LowPassFilterDiscreteorConti_fo
                               * Referenced by: '<S33>/Constant'
                               */
  real_T LowPassFilterDiscreteorConti_jr;
                              /* Mask Parameter: LowPassFilterDiscreteorConti_jr
                               * Referenced by: '<S47>/Constant'
                               */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S2>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S2>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S2>/Out4'
                                        */
  real_T Out5_Y0;                      /* Computed Parameter: Out5_Y0
                                        * Referenced by: '<S2>/Out5'
                                        */
  real_T Out6_Y0;                      /* Computed Parameter: Out6_Y0
                                        * Referenced by: '<S2>/Out6'
                                        */
  real_T Out1_Y0_h;                    /* Computed Parameter: Out1_Y0_h
                                        * Referenced by: '<S3>/Out1'
                                        */
  real_T VL53L0XTimeOfFlightSensor_Sampl;/* Expression: -1
                                          * Referenced by: '<Root>/VL53L0X Time Of Flight Sensor'
                                          */
  real_T VL53L0XTimeOfFlightSensor_Sam_e;/* Expression: -1
                                          * Referenced by: '<Root>/VL53L0X Time Of Flight Sensor.'
                                          */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant_Value_o1;            /* Expression: 0
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Integrator_gainval_j;       /* Computed Parameter: Integrator_gainval_j
                                      * Referenced by: '<S25>/Integrator'
                                      */
  real_T Integrator_UpperSat_f;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S25>/Integrator'
                                        */
  real_T Integrator_LowerSat_f;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S25>/Integrator'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Integrator_gainval_g;       /* Computed Parameter: Integrator_gainval_g
                                      * Referenced by: '<S60>/Integrator'
                                      */
  real_T Integrator_UpperSat_g;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S60>/Integrator'
                                        */
  real_T Integrator_LowerSat_n;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S60>/Integrator'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S60>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S60>/Saturation'
                                        */
  real_T Integrator_gainval_c;       /* Computed Parameter: Integrator_gainval_c
                                      * Referenced by: '<S32>/Integrator'
                                      */
  real_T Integrator_UpperSat_i;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S32>/Integrator'
                                        */
  real_T Integrator_LowerSat_b;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S32>/Integrator'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S39>/Integrator'
                                      */
  real_T Integrator_UpperSat_p;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Integrator_LowerSat_o;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat_dj;       /* Expression: windupLowerLimit
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Integrator_gainval_n;       /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S53>/Integrator'
                                      */
  real_T Integrator_UpperSat_h;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S53>/Integrator'
                                        */
  real_T Integrator_LowerSat_be;       /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S53>/Integrator'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T SimulationPace_P1;            /* Expression: SimulationPace
                                        * Referenced by: '<Root>/Simulation Pace.'
                                        */
  real_T SimulationPace_P2;            /* Expression: 2
                                        * Referenced by: '<Root>/Simulation Pace.'
                                        */
  real_T SimulationPace_P3;            /* Expression: OutputPaceError
                                        * Referenced by: '<Root>/Simulation Pace.'
                                        */
  real_T SimulationPace_P4;            /* Expression: SampleTime
                                        * Referenced by: '<Root>/Simulation Pace.'
                                        */
  boolean_T Q_Y0;                      /* Computed Parameter: Q_Y0
                                        * Referenced by: '<S12>/Q'
                                        */
  boolean_T Q_Y0_n;                    /* Computed Parameter: Q_Y0_n
                                        * Referenced by: '<S12>/!Q'
                                        */
  boolean_T _Y0;                       /* Computed Parameter: _Y0
                                        * Referenced by: '<S11>/ '
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32Arm6DOF_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ESP32Arm6DOF_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ESP32Arm6DOF_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_ESP32Arm6DOF_T ESP32Arm6DOF_P;

/* Block signals (default storage) */
extern B_ESP32Arm6DOF_T ESP32Arm6DOF_B;

/* Continuous states (default storage) */
extern X_ESP32Arm6DOF_T ESP32Arm6DOF_X;

/* Disabled states (default storage) */
extern XDis_ESP32Arm6DOF_T ESP32Arm6DOF_XDis;

/* Block states (default storage) */
extern DW_ESP32Arm6DOF_T ESP32Arm6DOF_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_ESP32Arm6DOF_T ESP32Arm6DOF_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ESP32Arm6DOF_T ESP32Arm6DOF_Y;

/* Model entry point functions */
extern void ESP32Arm6DOF_initialize(void);
extern void ESP32Arm6DOF_step(void);
extern void ESP32Arm6DOF_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ESP32Arm6DOF_T *const ESP32Arm6DOF_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant.' : Unused code path elimination
 * Block '<S12>/Logic' : Unused code path elimination
 * Block '<Root>/Distance in mm' : Unused code path elimination
 * Block '<S99>/Proportional Gain' : Unused code path elimination
 * Block '<S103>/Sum' : Unused code path elimination
 * Block '<Root>/Relational Operator.' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope.' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
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
 * '<Root>' : 'ESP32Arm6DOF'
 * '<S1>'   : 'ESP32Arm6DOF/D Latch.'
 * '<S2>'   : 'ESP32Arm6DOF/Enabled Subsystem'
 * '<S3>'   : 'ESP32Arm6DOF/Enabled Subsystem.'
 * '<S4>'   : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)'
 * '<S5>'   : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1'
 * '<S6>'   : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2'
 * '<S7>'   : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3'
 * '<S8>'   : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4'
 * '<S9>'   : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5'
 * '<S10>'  : 'ESP32Arm6DOF/PID Controller.'
 * '<S11>'  : 'ESP32Arm6DOF/Sample and Hold'
 * '<S12>'  : 'ESP32Arm6DOF/D Latch./D Latch'
 * '<S13>'  : 'ESP32Arm6DOF/Enabled Subsystem/Base Signal Editor'
 * '<S14>'  : 'ESP32Arm6DOF/Enabled Subsystem/Claw Signal Editor'
 * '<S15>'  : 'ESP32Arm6DOF/Enabled Subsystem/Lower Signal Editor'
 * '<S16>'  : 'ESP32Arm6DOF/Enabled Subsystem/Mid Signal Editor'
 * '<S17>'  : 'ESP32Arm6DOF/Enabled Subsystem/Rotation Signal Editor'
 * '<S18>'  : 'ESP32Arm6DOF/Enabled Subsystem/Upper Signal Editor'
 * '<S19>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S20>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S21>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S22>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Constant'
 * '<S23>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S24>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S25>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S26>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant'
 * '<S27>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Initialization'
 * '<S28>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
 * '<S29>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Constant'
 * '<S30>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Zero'
 * '<S31>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Initialization/Init_u'
 * '<S32>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
 * '<S33>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant'
 * '<S34>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Initialization'
 * '<S35>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)'
 * '<S36>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Constant'
 * '<S37>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Zero'
 * '<S38>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Initialization/Init_u'
 * '<S39>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)/Discrete'
 * '<S40>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant'
 * '<S41>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Initialization'
 * '<S42>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)'
 * '<S43>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Constant'
 * '<S44>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Zero'
 * '<S45>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Initialization/Init_u'
 * '<S46>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)/Discrete'
 * '<S47>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Enable//disable time constant'
 * '<S48>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Initialization'
 * '<S49>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Integrator (Discrete or Continuous)'
 * '<S50>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Enable//disable time constant/Compare To Constant'
 * '<S51>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Enable//disable time constant/Compare To Zero'
 * '<S52>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Initialization/Init_u'
 * '<S53>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)4/Integrator (Discrete or Continuous)/Discrete'
 * '<S54>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Enable//disable time constant'
 * '<S55>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Initialization'
 * '<S56>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Integrator (Discrete or Continuous)'
 * '<S57>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Enable//disable time constant/Compare To Constant'
 * '<S58>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Enable//disable time constant/Compare To Zero'
 * '<S59>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Initialization/Init_u'
 * '<S60>'  : 'ESP32Arm6DOF/Low-Pass Filter (Discrete or Continuous)5/Integrator (Discrete or Continuous)/Discrete'
 * '<S61>'  : 'ESP32Arm6DOF/PID Controller./Anti-windup'
 * '<S62>'  : 'ESP32Arm6DOF/PID Controller./D Gain'
 * '<S63>'  : 'ESP32Arm6DOF/PID Controller./External Derivative'
 * '<S64>'  : 'ESP32Arm6DOF/PID Controller./Filter'
 * '<S65>'  : 'ESP32Arm6DOF/PID Controller./Filter ICs'
 * '<S66>'  : 'ESP32Arm6DOF/PID Controller./I Gain'
 * '<S67>'  : 'ESP32Arm6DOF/PID Controller./Ideal P Gain'
 * '<S68>'  : 'ESP32Arm6DOF/PID Controller./Ideal P Gain Fdbk'
 * '<S69>'  : 'ESP32Arm6DOF/PID Controller./Integrator'
 * '<S70>'  : 'ESP32Arm6DOF/PID Controller./Integrator ICs'
 * '<S71>'  : 'ESP32Arm6DOF/PID Controller./N Copy'
 * '<S72>'  : 'ESP32Arm6DOF/PID Controller./N Gain'
 * '<S73>'  : 'ESP32Arm6DOF/PID Controller./P Copy'
 * '<S74>'  : 'ESP32Arm6DOF/PID Controller./Parallel P Gain'
 * '<S75>'  : 'ESP32Arm6DOF/PID Controller./Reset Signal'
 * '<S76>'  : 'ESP32Arm6DOF/PID Controller./Saturation'
 * '<S77>'  : 'ESP32Arm6DOF/PID Controller./Saturation Fdbk'
 * '<S78>'  : 'ESP32Arm6DOF/PID Controller./Sum'
 * '<S79>'  : 'ESP32Arm6DOF/PID Controller./Sum Fdbk'
 * '<S80>'  : 'ESP32Arm6DOF/PID Controller./Tracking Mode'
 * '<S81>'  : 'ESP32Arm6DOF/PID Controller./Tracking Mode Sum'
 * '<S82>'  : 'ESP32Arm6DOF/PID Controller./Tsamp - Integral'
 * '<S83>'  : 'ESP32Arm6DOF/PID Controller./Tsamp - Ngain'
 * '<S84>'  : 'ESP32Arm6DOF/PID Controller./postSat Signal'
 * '<S85>'  : 'ESP32Arm6DOF/PID Controller./preSat Signal'
 * '<S86>'  : 'ESP32Arm6DOF/PID Controller./Anti-windup/Passthrough'
 * '<S87>'  : 'ESP32Arm6DOF/PID Controller./D Gain/Internal Parameters'
 * '<S88>'  : 'ESP32Arm6DOF/PID Controller./External Derivative/Error'
 * '<S89>'  : 'ESP32Arm6DOF/PID Controller./Filter/Cont. Filter'
 * '<S90>'  : 'ESP32Arm6DOF/PID Controller./Filter ICs/Internal IC - Filter'
 * '<S91>'  : 'ESP32Arm6DOF/PID Controller./I Gain/Internal Parameters'
 * '<S92>'  : 'ESP32Arm6DOF/PID Controller./Ideal P Gain/Passthrough'
 * '<S93>'  : 'ESP32Arm6DOF/PID Controller./Ideal P Gain Fdbk/Disabled'
 * '<S94>'  : 'ESP32Arm6DOF/PID Controller./Integrator/Continuous'
 * '<S95>'  : 'ESP32Arm6DOF/PID Controller./Integrator ICs/Internal IC'
 * '<S96>'  : 'ESP32Arm6DOF/PID Controller./N Copy/Disabled'
 * '<S97>'  : 'ESP32Arm6DOF/PID Controller./N Gain/Internal Parameters'
 * '<S98>'  : 'ESP32Arm6DOF/PID Controller./P Copy/Disabled'
 * '<S99>'  : 'ESP32Arm6DOF/PID Controller./Parallel P Gain/Internal Parameters'
 * '<S100>' : 'ESP32Arm6DOF/PID Controller./Reset Signal/Disabled'
 * '<S101>' : 'ESP32Arm6DOF/PID Controller./Saturation/Passthrough'
 * '<S102>' : 'ESP32Arm6DOF/PID Controller./Saturation Fdbk/Disabled'
 * '<S103>' : 'ESP32Arm6DOF/PID Controller./Sum/Sum_PID'
 * '<S104>' : 'ESP32Arm6DOF/PID Controller./Sum Fdbk/Disabled'
 * '<S105>' : 'ESP32Arm6DOF/PID Controller./Tracking Mode/Disabled'
 * '<S106>' : 'ESP32Arm6DOF/PID Controller./Tracking Mode Sum/Passthrough'
 * '<S107>' : 'ESP32Arm6DOF/PID Controller./Tsamp - Integral/TsSignalSpecification'
 * '<S108>' : 'ESP32Arm6DOF/PID Controller./Tsamp - Ngain/Passthrough'
 * '<S109>' : 'ESP32Arm6DOF/PID Controller./postSat Signal/Forward_Path'
 * '<S110>' : 'ESP32Arm6DOF/PID Controller./preSat Signal/Forward_Path'
 */
#endif                                 /* ESP32Arm6DOF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
