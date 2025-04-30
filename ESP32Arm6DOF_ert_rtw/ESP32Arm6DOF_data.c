/*
 * File: ESP32Arm6DOF_data.c
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

#include "ESP32Arm6DOF.h"

/* Block parameters (default storage) */
P_ESP32Arm6DOF_T ESP32Arm6DOF_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S87>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S91>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S89>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S94>/Integrator'
   */
  0.0,

  /* Mask Parameter: LowPassFilterDiscreteorContinuo
   * Referenced by: '<S7>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_p
   * Referenced by: '<S4>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_h
   * Referenced by: '<S9>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_j
   * Referenced by: '<S5>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_l
   * Referenced by: '<S6>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_f
   * Referenced by: '<S8>/K'
   */
  1.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S97>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_g
   * Referenced by: '<S40>/Time constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_o
   * Referenced by: '<S19>/Time constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_e
   * Referenced by: '<S54>/Time constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorConti_jx
   * Referenced by: '<S26>/Time constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_d
   * Referenced by: '<S33>/Time constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_i
   * Referenced by: '<S47>/Time constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S43>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S22>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_k
   * Referenced by: '<S57>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S29>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S36>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S50>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilterDiscreteorConti_dy
   * Referenced by: '<S40>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorConti_ly
   * Referenced by: '<S19>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorConti_gi
   * Referenced by: '<S54>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_m
   * Referenced by: '<S26>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorConti_fo
   * Referenced by: '<S33>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorConti_jr
   * Referenced by: '<S47>/Constant'
   */
  1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S2>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S2>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S2>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S2>/Out4'
   */
  0.0,

  /* Computed Parameter: Out5_Y0
   * Referenced by: '<S2>/Out5'
   */
  0.0,

  /* Computed Parameter: Out6_Y0
   * Referenced by: '<S2>/Out6'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_h
   * Referenced by: '<S3>/Out1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/VL53L0X Time Of Flight Sensor'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/VL53L0X Time Of Flight Sensor.'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S30>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S37>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S44>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S51>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S58>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S46>/Integrator'
   */
  0.033333333333333333,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S46>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S46>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S46>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S46>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S25>/Integrator'
   */
  0.033333333333333333,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S25>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S25>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S25>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S25>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_g
   * Referenced by: '<S60>/Integrator'
   */
  0.033333333333333333,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S60>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S60>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S60>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S60>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_c
   * Referenced by: '<S32>/Integrator'
   */
  0.033333333333333333,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S32>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S32>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S32>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S32>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S39>/Integrator'
   */
  0.033333333333333333,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S39>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S39>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S53>/Integrator'
   */
  0.033333333333333333,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S53>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S53>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S53>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S53>/Saturation'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Expression: SimulationPace
   * Referenced by: '<Root>/Simulation Pace.'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Simulation Pace.'
   */
  2.0,

  /* Expression: OutputPaceError
   * Referenced by: '<Root>/Simulation Pace.'
   */
  0.0,

  /* Expression: SampleTime
   * Referenced by: '<Root>/Simulation Pace.'
   */
  0.033333333333333333,

  /* Computed Parameter: Q_Y0
   * Referenced by: '<S12>/Q'
   */
  false,

  /* Computed Parameter: Q_Y0_n
   * Referenced by: '<S12>/!Q'
   */
  true,

  /* Computed Parameter: _Y0
   * Referenced by: '<S11>/ '
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
