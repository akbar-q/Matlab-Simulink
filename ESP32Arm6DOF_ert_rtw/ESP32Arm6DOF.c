/*
 * File: ESP32Arm6DOF.c
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
#include "ESP32Arm6DOF_private.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>

/* Block signals (default storage) */
B_ESP32Arm6DOF_T ESP32Arm6DOF_B;

/* Continuous states */
X_ESP32Arm6DOF_T ESP32Arm6DOF_X;

/* Disabled State Vector */
XDis_ESP32Arm6DOF_T ESP32Arm6DOF_XDis;

/* Block states (default storage) */
DW_ESP32Arm6DOF_T ESP32Arm6DOF_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ESP32Arm6DOF_T ESP32Arm6DOF_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ESP32Arm6DOF_T ESP32Arm6DOF_Y;

/* Real-time model */
static RT_MODEL_ESP32Arm6DOF_T ESP32Arm6DOF_M_;
RT_MODEL_ESP32Arm6DOF_T *const ESP32Arm6DOF_M = &ESP32Arm6DOF_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ESP32Arm6DOF_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ESP32Arm6DOF_step();
  ESP32Arm6DOF_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ESP32Arm6DOF_step();
  ESP32Arm6DOF_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void ESP32Arm6DOF_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_h;
  boolean_T rtb_LogicalOperator_g;
  boolean_T rtb_LogicalOperator_k;
  boolean_T rtb_LogicalOperator_gb;
  boolean_T rtb_LogicalOperator_e;
  real_T K;
  real_T rtb_Integrator_d;
  uint16_T y;
  uint8_T tmp;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ESP32Arm6DOF_M->solverInfo,
                          ((ESP32Arm6DOF_M->Timing.clockTick0+1)*
      ESP32Arm6DOF_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ESP32Arm6DOF_M)) {
    ESP32Arm6DOF_M->Timing.t[0] = rtsiGetT(&ESP32Arm6DOF_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Logic: '<S40>/Logical Operator' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Time constant'
     *  Constant: '<S43>/Constant'
     *  Constant: '<S44>/Constant'
     *  RelationalOperator: '<S43>/Compare'
     *  RelationalOperator: '<S44>/Compare'
     *  Sum: '<S40>/Sum1'
     */
    rtb_LogicalOperator = ((ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_g -
      ESP32Arm6DOF_B.Probe_fr[0] <= ESP32Arm6DOF_P.Constant_Value_c) &&
      (ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_dy <
       ESP32Arm6DOF_P.CompareToConstant_const));

    /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ESP32Arm6DOF_M->solverInfo)) {
      /* Constant: '<Root>/Constant' */
      ESP32Arm6DOF_DW.EnabledSubsystem_MODE = (ESP32Arm6DOF_P.Constant_Value_f >
        0.0);
    }

    /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (ESP32Arm6DOF_DW.EnabledSubsystem_MODE) {
    /* FromWorkspace: '<S13>/fromWS_Signal 1' */
    {
      real_T t = ESP32Arm6DOF_M->Timing.t[0];
      real_T *pTimeValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK.TimePtr;
      real_T *pDataValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK.DataPtr;
      if (t < pTimeValues[0]) {
        ESP32Arm6DOF_B.BaseSig = 0.0;
      } else if (t == pTimeValues[12]) {
        ESP32Arm6DOF_B.BaseSig = pDataValues[12];
      } else if (t > pTimeValues[12]) {
        ESP32Arm6DOF_B.BaseSig = 0.0;
      } else {
        int_T currTimeIndex = ESP32Arm6DOF_DW.fromWS_Signal1_IWORK.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        ESP32Arm6DOF_B.BaseSig = pDataValues[currTimeIndex];
        ESP32Arm6DOF_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
      }
    }

    /* FromWorkspace: '<S15>/fromWS_Signal 1' */
    {
      real_T t = ESP32Arm6DOF_M->Timing.t[0];
      real_T *pTimeValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_p.TimePtr;
      real_T *pDataValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_p.DataPtr;
      if (t < pTimeValues[0]) {
        ESP32Arm6DOF_B.LowerSignal = 0.0;
      } else if (t == pTimeValues[12]) {
        ESP32Arm6DOF_B.LowerSignal = pDataValues[12];
      } else if (t > pTimeValues[12]) {
        ESP32Arm6DOF_B.LowerSignal = 0.0;
      } else {
        int_T currTimeIndex = ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_k.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        ESP32Arm6DOF_B.LowerSignal = pDataValues[currTimeIndex];
        ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_k.PrevIndex = currTimeIndex;
      }
    }

    /* FromWorkspace: '<S16>/fromWS_Signal 1' */
    {
      real_T t = ESP32Arm6DOF_M->Timing.t[0];
      real_T *pTimeValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_n.TimePtr;
      real_T *pDataValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_n.DataPtr;
      if (t < pTimeValues[0]) {
        ESP32Arm6DOF_B.MidSignal = 0.0;
      } else if (t == pTimeValues[12]) {
        ESP32Arm6DOF_B.MidSignal = pDataValues[12];
      } else if (t > pTimeValues[12]) {
        ESP32Arm6DOF_B.MidSignal = 0.0;
      } else {
        int_T currTimeIndex = ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_i.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        ESP32Arm6DOF_B.MidSignal = pDataValues[currTimeIndex];
        ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_i.PrevIndex = currTimeIndex;
      }
    }

    /* FromWorkspace: '<S18>/fromWS_Signal 1' */
    {
      real_T t = ESP32Arm6DOF_M->Timing.t[0];
      real_T *pTimeValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_d.TimePtr;
      real_T *pDataValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_d.DataPtr;
      if (t < pTimeValues[0]) {
        ESP32Arm6DOF_B.UpperSignal = 0.0;
      } else if (t == pTimeValues[12]) {
        ESP32Arm6DOF_B.UpperSignal = pDataValues[12];
      } else if (t > pTimeValues[12]) {
        ESP32Arm6DOF_B.UpperSignal = 0.0;
      } else {
        int_T currTimeIndex = ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_l.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        ESP32Arm6DOF_B.UpperSignal = pDataValues[currTimeIndex];
        ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_l.PrevIndex = currTimeIndex;
      }
    }

    /* FromWorkspace: '<S17>/fromWS_Signal 1' */
    {
      real_T t = ESP32Arm6DOF_M->Timing.t[0];
      real_T *pTimeValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_f.TimePtr;
      real_T *pDataValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_f.DataPtr;
      if (t < pTimeValues[0]) {
        ESP32Arm6DOF_B.RotationSignal = 0.0;
      } else if (t == pTimeValues[12]) {
        ESP32Arm6DOF_B.RotationSignal = pDataValues[12];
      } else if (t > pTimeValues[12]) {
        ESP32Arm6DOF_B.RotationSignal = 0.0;
      } else {
        int_T currTimeIndex = ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_ko.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        ESP32Arm6DOF_B.RotationSignal = pDataValues[currTimeIndex];
        ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_ko.PrevIndex = currTimeIndex;
      }
    }

    /* FromWorkspace: '<S14>/fromWS_Signal 1' */
    {
      real_T t = ESP32Arm6DOF_M->Timing.t[0];
      real_T *pTimeValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_nz.TimePtr;
      real_T *pDataValues = (real_T *)
        ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_nz.DataPtr;
      if (t < pTimeValues[0]) {
        ESP32Arm6DOF_B.ClawSignal = 0.0;
      } else if (t == pTimeValues[12]) {
        ESP32Arm6DOF_B.ClawSignal = pDataValues[12];
      } else if (t > pTimeValues[12]) {
        ESP32Arm6DOF_B.ClawSignal = 0.0;
      } else {
        int_T currTimeIndex = ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_a.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        ESP32Arm6DOF_B.ClawSignal = pDataValues[currTimeIndex];
        ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_a.PrevIndex = currTimeIndex;
      }
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Gain: '<S7>/K' */
  K = ESP32Arm6DOF_P.LowPassFilterDiscreteorContinuo *
    ESP32Arm6DOF_B.UpperSignal;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* DiscreteIntegrator: '<S46>/Integrator' */
    if (ESP32Arm6DOF_DW.Integrator_IC_LOADING != 0) {
      ESP32Arm6DOF_DW.Integrator_DSTATE = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE > ESP32Arm6DOF_P.Integrator_UpperSat)
      {
        ESP32Arm6DOF_DW.Integrator_DSTATE = ESP32Arm6DOF_P.Integrator_UpperSat;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE <
                 ESP32Arm6DOF_P.Integrator_LowerSat) {
        ESP32Arm6DOF_DW.Integrator_DSTATE = ESP32Arm6DOF_P.Integrator_LowerSat;
      }
    }

    if (rtb_LogicalOperator || (ESP32Arm6DOF_DW.Integrator_PrevResetState != 0))
    {
      ESP32Arm6DOF_DW.Integrator_DSTATE = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE > ESP32Arm6DOF_P.Integrator_UpperSat)
      {
        ESP32Arm6DOF_DW.Integrator_DSTATE = ESP32Arm6DOF_P.Integrator_UpperSat;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE <
                 ESP32Arm6DOF_P.Integrator_LowerSat) {
        ESP32Arm6DOF_DW.Integrator_DSTATE = ESP32Arm6DOF_P.Integrator_LowerSat;
      }
    }

    /* Saturate: '<S46>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator'
     */
    if (ESP32Arm6DOF_DW.Integrator_DSTATE > ESP32Arm6DOF_P.Saturation_UpperSat)
    {
      /* Saturate: '<S46>/Saturation' */
      ESP32Arm6DOF_B.Saturation = ESP32Arm6DOF_P.Saturation_UpperSat;
    } else if (ESP32Arm6DOF_DW.Integrator_DSTATE <
               ESP32Arm6DOF_P.Saturation_LowerSat) {
      /* Saturate: '<S46>/Saturation' */
      ESP32Arm6DOF_B.Saturation = ESP32Arm6DOF_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S46>/Saturation' */
      ESP32Arm6DOF_B.Saturation = ESP32Arm6DOF_DW.Integrator_DSTATE;
    }

    /* End of Saturate: '<S46>/Saturation' */

    /* MATLABSystem: '<Root>/Upper Servo' */
    if (ESP32Arm6DOF_B.Saturation < 0.0) {
      tmp = 0U;
    } else if (ESP32Arm6DOF_B.Saturation > 180.0) {
      tmp = 180U;
    } else {
      rtb_Integrator_d = rt_roundd_snf(ESP32Arm6DOF_B.Saturation);
      if (rtb_Integrator_d < 256.0) {
        tmp = (uint8_T)rtb_Integrator_d;
      } else {
        tmp = MAX_uint8_T;
      }
    }

    MW_servoWrite(6, tmp);

    /* End of MATLABSystem: '<Root>/Upper Servo' */

    /* MinMax: '<S40>/Max' incorporates:
     *  Constant: '<S40>/Time constant'
     */
    if ((ESP32Arm6DOF_B.Probe_fr[0] >=
         ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_g) || rtIsNaN
        (ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_g)) {
      rtb_Integrator_d = ESP32Arm6DOF_B.Probe_fr[0];
    } else {
      rtb_Integrator_d = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_g;
    }

    /* End of MinMax: '<S40>/Max' */

    /* Fcn: '<S40>/Avoid Divide by Zero' */
    ESP32Arm6DOF_B.AvoidDividebyZero = (real_T)(rtb_Integrator_d == 0.0) *
      2.2204460492503131e-16 + rtb_Integrator_d;
  }

  /* Product: '<S7>/1//T' incorporates:
   *  Sum: '<S7>/Sum1'
   */
  ESP32Arm6DOF_B.uT = 1.0 / ESP32Arm6DOF_B.AvoidDividebyZero * (K -
    ESP32Arm6DOF_B.Saturation);

  /* Gain: '<S4>/K' */
  K = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_p * ESP32Arm6DOF_B.BaseSig;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Logic: '<S19>/Logical Operator' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S19>/Time constant'
     *  Constant: '<S22>/Constant'
     *  Constant: '<S23>/Constant'
     *  RelationalOperator: '<S22>/Compare'
     *  RelationalOperator: '<S23>/Compare'
     *  Sum: '<S19>/Sum1'
     */
    rtb_LogicalOperator_h = ((ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_o -
      ESP32Arm6DOF_B.Probe[0] <= ESP32Arm6DOF_P.Constant_Value) &&
      (ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_ly <
       ESP32Arm6DOF_P.CompareToConstant_const_h));

    /* DiscreteIntegrator: '<S25>/Integrator' */
    if (ESP32Arm6DOF_DW.Integrator_IC_LOADING_l != 0) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_k = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_k >
          ESP32Arm6DOF_P.Integrator_UpperSat_f) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_k =
          ESP32Arm6DOF_P.Integrator_UpperSat_f;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_k <
                 ESP32Arm6DOF_P.Integrator_LowerSat_f) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_k =
          ESP32Arm6DOF_P.Integrator_LowerSat_f;
      }
    }

    if (rtb_LogicalOperator_h || (ESP32Arm6DOF_DW.Integrator_PrevResetState_a !=
         0)) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_k = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_k >
          ESP32Arm6DOF_P.Integrator_UpperSat_f) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_k =
          ESP32Arm6DOF_P.Integrator_UpperSat_f;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_k <
                 ESP32Arm6DOF_P.Integrator_LowerSat_f) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_k =
          ESP32Arm6DOF_P.Integrator_LowerSat_f;
      }
    }

    /* Saturate: '<S25>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S25>/Integrator'
     */
    if (ESP32Arm6DOF_DW.Integrator_DSTATE_k >
        ESP32Arm6DOF_P.Saturation_UpperSat_b) {
      /* Saturate: '<S25>/Saturation' */
      ESP32Arm6DOF_B.Saturation_d = ESP32Arm6DOF_P.Saturation_UpperSat_b;
    } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_k <
               ESP32Arm6DOF_P.Saturation_LowerSat_d) {
      /* Saturate: '<S25>/Saturation' */
      ESP32Arm6DOF_B.Saturation_d = ESP32Arm6DOF_P.Saturation_LowerSat_d;
    } else {
      /* Saturate: '<S25>/Saturation' */
      ESP32Arm6DOF_B.Saturation_d = ESP32Arm6DOF_DW.Integrator_DSTATE_k;
    }

    /* End of Saturate: '<S25>/Saturation' */

    /* MATLABSystem: '<Root>/Base Servo' */
    if (ESP32Arm6DOF_B.Saturation_d < 0.0) {
      tmp = 0U;
    } else if (ESP32Arm6DOF_B.Saturation_d > 180.0) {
      tmp = 180U;
    } else {
      rtb_Integrator_d = rt_roundd_snf(ESP32Arm6DOF_B.Saturation_d);
      if (rtb_Integrator_d < 256.0) {
        tmp = (uint8_T)rtb_Integrator_d;
      } else {
        tmp = MAX_uint8_T;
      }
    }

    MW_servoWrite(0, tmp);

    /* End of MATLABSystem: '<Root>/Base Servo' */

    /* MinMax: '<S19>/Max' incorporates:
     *  Constant: '<S19>/Time constant'
     */
    if ((ESP32Arm6DOF_B.Probe[0] >=
         ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_o) || rtIsNaN
        (ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_o)) {
      rtb_Integrator_d = ESP32Arm6DOF_B.Probe[0];
    } else {
      rtb_Integrator_d = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_o;
    }

    /* End of MinMax: '<S19>/Max' */

    /* Fcn: '<S19>/Avoid Divide by Zero' */
    ESP32Arm6DOF_B.AvoidDividebyZero_k = (real_T)(rtb_Integrator_d == 0.0) *
      2.2204460492503131e-16 + rtb_Integrator_d;
  }

  /* Product: '<S4>/1//T' incorporates:
   *  Sum: '<S4>/Sum1'
   */
  ESP32Arm6DOF_B.uT_l = 1.0 / ESP32Arm6DOF_B.AvoidDividebyZero_k * (K -
    ESP32Arm6DOF_B.Saturation_d);

  /* Gain: '<S9>/K' */
  K = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_h * ESP32Arm6DOF_B.ClawSignal;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Logic: '<S54>/Logical Operator' incorporates:
     *  Constant: '<S54>/Constant'
     *  Constant: '<S54>/Time constant'
     *  Constant: '<S57>/Constant'
     *  Constant: '<S58>/Constant'
     *  RelationalOperator: '<S57>/Compare'
     *  RelationalOperator: '<S58>/Compare'
     *  Sum: '<S54>/Sum1'
     */
    rtb_LogicalOperator_g = ((ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_e -
      ESP32Arm6DOF_B.Probe_f[0] <= ESP32Arm6DOF_P.Constant_Value_p) &&
      (ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_gi <
       ESP32Arm6DOF_P.CompareToConstant_const_k));

    /* DiscreteIntegrator: '<S60>/Integrator' */
    if (ESP32Arm6DOF_DW.Integrator_IC_LOADING_f != 0) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_g = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_g >
          ESP32Arm6DOF_P.Integrator_UpperSat_g) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_g =
          ESP32Arm6DOF_P.Integrator_UpperSat_g;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_g <
                 ESP32Arm6DOF_P.Integrator_LowerSat_n) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_g =
          ESP32Arm6DOF_P.Integrator_LowerSat_n;
      }
    }

    if (rtb_LogicalOperator_g || (ESP32Arm6DOF_DW.Integrator_PrevResetState_m !=
         0)) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_g = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_g >
          ESP32Arm6DOF_P.Integrator_UpperSat_g) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_g =
          ESP32Arm6DOF_P.Integrator_UpperSat_g;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_g <
                 ESP32Arm6DOF_P.Integrator_LowerSat_n) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_g =
          ESP32Arm6DOF_P.Integrator_LowerSat_n;
      }
    }

    /* Saturate: '<S60>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S60>/Integrator'
     */
    if (ESP32Arm6DOF_DW.Integrator_DSTATE_g >
        ESP32Arm6DOF_P.Saturation_UpperSat_l) {
      /* Saturate: '<S60>/Saturation' */
      ESP32Arm6DOF_B.Saturation_n = ESP32Arm6DOF_P.Saturation_UpperSat_l;
    } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_g <
               ESP32Arm6DOF_P.Saturation_LowerSat_e) {
      /* Saturate: '<S60>/Saturation' */
      ESP32Arm6DOF_B.Saturation_n = ESP32Arm6DOF_P.Saturation_LowerSat_e;
    } else {
      /* Saturate: '<S60>/Saturation' */
      ESP32Arm6DOF_B.Saturation_n = ESP32Arm6DOF_DW.Integrator_DSTATE_g;
    }

    /* End of Saturate: '<S60>/Saturation' */

    /* MATLABSystem: '<Root>/Claw Servo' */
    if (ESP32Arm6DOF_B.Saturation_n < 0.0) {
      tmp = 0U;
    } else if (ESP32Arm6DOF_B.Saturation_n > 180.0) {
      tmp = 180U;
    } else {
      rtb_Integrator_d = rt_roundd_snf(ESP32Arm6DOF_B.Saturation_n);
      if (rtb_Integrator_d < 256.0) {
        tmp = (uint8_T)rtb_Integrator_d;
      } else {
        tmp = MAX_uint8_T;
      }
    }

    MW_servoWrite(1, tmp);

    /* End of MATLABSystem: '<Root>/Claw Servo' */

    /* MinMax: '<S54>/Max' incorporates:
     *  Constant: '<S54>/Time constant'
     */
    if ((ESP32Arm6DOF_B.Probe_f[0] >=
         ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_e) || rtIsNaN
        (ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_e)) {
      rtb_Integrator_d = ESP32Arm6DOF_B.Probe_f[0];
    } else {
      rtb_Integrator_d = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_e;
    }

    /* End of MinMax: '<S54>/Max' */

    /* Fcn: '<S54>/Avoid Divide by Zero' */
    ESP32Arm6DOF_B.AvoidDividebyZero_l = (real_T)(rtb_Integrator_d == 0.0) *
      2.2204460492503131e-16 + rtb_Integrator_d;
  }

  /* Product: '<S9>/1//T' incorporates:
   *  Sum: '<S9>/Sum1'
   */
  ESP32Arm6DOF_B.uT_j = 1.0 / ESP32Arm6DOF_B.AvoidDividebyZero_l * (K -
    ESP32Arm6DOF_B.Saturation_n);

  /* Gain: '<S5>/K' */
  K = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_j *
    ESP32Arm6DOF_B.LowerSignal;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Logic: '<S26>/Logical Operator' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S26>/Time constant'
     *  Constant: '<S29>/Constant'
     *  Constant: '<S30>/Constant'
     *  RelationalOperator: '<S29>/Compare'
     *  RelationalOperator: '<S30>/Compare'
     *  Sum: '<S26>/Sum1'
     */
    rtb_LogicalOperator_k = ((ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_jx -
      ESP32Arm6DOF_B.Probe_a[0] <= ESP32Arm6DOF_P.Constant_Value_b) &&
      (ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_m <
       ESP32Arm6DOF_P.CompareToConstant_const_m));

    /* DiscreteIntegrator: '<S32>/Integrator' */
    if (ESP32Arm6DOF_DW.Integrator_IC_LOADING_o != 0) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_n = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_n >
          ESP32Arm6DOF_P.Integrator_UpperSat_i) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_n =
          ESP32Arm6DOF_P.Integrator_UpperSat_i;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_n <
                 ESP32Arm6DOF_P.Integrator_LowerSat_b) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_n =
          ESP32Arm6DOF_P.Integrator_LowerSat_b;
      }
    }

    if (rtb_LogicalOperator_k || (ESP32Arm6DOF_DW.Integrator_PrevResetState_l !=
         0)) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_n = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_n >
          ESP32Arm6DOF_P.Integrator_UpperSat_i) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_n =
          ESP32Arm6DOF_P.Integrator_UpperSat_i;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_n <
                 ESP32Arm6DOF_P.Integrator_LowerSat_b) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_n =
          ESP32Arm6DOF_P.Integrator_LowerSat_b;
      }
    }

    /* Saturate: '<S32>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S32>/Integrator'
     */
    if (ESP32Arm6DOF_DW.Integrator_DSTATE_n >
        ESP32Arm6DOF_P.Saturation_UpperSat_o) {
      /* Saturate: '<S32>/Saturation' */
      ESP32Arm6DOF_B.Saturation_nm = ESP32Arm6DOF_P.Saturation_UpperSat_o;
    } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_n <
               ESP32Arm6DOF_P.Saturation_LowerSat_k) {
      /* Saturate: '<S32>/Saturation' */
      ESP32Arm6DOF_B.Saturation_nm = ESP32Arm6DOF_P.Saturation_LowerSat_k;
    } else {
      /* Saturate: '<S32>/Saturation' */
      ESP32Arm6DOF_B.Saturation_nm = ESP32Arm6DOF_DW.Integrator_DSTATE_n;
    }

    /* End of Saturate: '<S32>/Saturation' */

    /* MATLABSystem: '<Root>/Lower Arm Servo' */
    if (ESP32Arm6DOF_B.Saturation_nm < 0.0) {
      tmp = 0U;
    } else if (ESP32Arm6DOF_B.Saturation_nm > 180.0) {
      tmp = 180U;
    } else {
      rtb_Integrator_d = rt_roundd_snf(ESP32Arm6DOF_B.Saturation_nm);
      if (rtb_Integrator_d < 256.0) {
        tmp = (uint8_T)rtb_Integrator_d;
      } else {
        tmp = MAX_uint8_T;
      }
    }

    MW_servoWrite(2, tmp);

    /* End of MATLABSystem: '<Root>/Lower Arm Servo' */

    /* MinMax: '<S26>/Max' incorporates:
     *  Constant: '<S26>/Time constant'
     */
    if ((ESP32Arm6DOF_B.Probe_a[0] >=
         ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_jx) || rtIsNaN
        (ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_jx)) {
      rtb_Integrator_d = ESP32Arm6DOF_B.Probe_a[0];
    } else {
      rtb_Integrator_d = ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_jx;
    }

    /* End of MinMax: '<S26>/Max' */

    /* Fcn: '<S26>/Avoid Divide by Zero' */
    ESP32Arm6DOF_B.AvoidDividebyZero_c = (real_T)(rtb_Integrator_d == 0.0) *
      2.2204460492503131e-16 + rtb_Integrator_d;
  }

  /* Product: '<S5>/1//T' incorporates:
   *  Sum: '<S5>/Sum1'
   */
  ESP32Arm6DOF_B.uT_g = 1.0 / ESP32Arm6DOF_B.AvoidDividebyZero_c * (K -
    ESP32Arm6DOF_B.Saturation_nm);

  /* Gain: '<S6>/K' */
  K = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_l * ESP32Arm6DOF_B.MidSignal;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Logic: '<S33>/Logical Operator' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S33>/Time constant'
     *  Constant: '<S36>/Constant'
     *  Constant: '<S37>/Constant'
     *  RelationalOperator: '<S36>/Compare'
     *  RelationalOperator: '<S37>/Compare'
     *  Sum: '<S33>/Sum1'
     */
    rtb_LogicalOperator_gb = ((ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_d -
      ESP32Arm6DOF_B.Probe_e[0] <= ESP32Arm6DOF_P.Constant_Value_o) &&
      (ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_fo <
       ESP32Arm6DOF_P.CompareToConstant_const_g));

    /* DiscreteIntegrator: '<S39>/Integrator' */
    if (ESP32Arm6DOF_DW.Integrator_IC_LOADING_n != 0) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_c = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_c >
          ESP32Arm6DOF_P.Integrator_UpperSat_p) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_c =
          ESP32Arm6DOF_P.Integrator_UpperSat_p;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_c <
                 ESP32Arm6DOF_P.Integrator_LowerSat_o) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_c =
          ESP32Arm6DOF_P.Integrator_LowerSat_o;
      }
    }

    if (rtb_LogicalOperator_gb || (ESP32Arm6DOF_DW.Integrator_PrevResetState_ah
         != 0)) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_c = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_c >
          ESP32Arm6DOF_P.Integrator_UpperSat_p) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_c =
          ESP32Arm6DOF_P.Integrator_UpperSat_p;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_c <
                 ESP32Arm6DOF_P.Integrator_LowerSat_o) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_c =
          ESP32Arm6DOF_P.Integrator_LowerSat_o;
      }
    }

    /* Saturate: '<S39>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S39>/Integrator'
     */
    if (ESP32Arm6DOF_DW.Integrator_DSTATE_c >
        ESP32Arm6DOF_P.Saturation_UpperSat_g) {
      /* Saturate: '<S39>/Saturation' */
      ESP32Arm6DOF_B.Saturation_h = ESP32Arm6DOF_P.Saturation_UpperSat_g;
    } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_c <
               ESP32Arm6DOF_P.Saturation_LowerSat_dj) {
      /* Saturate: '<S39>/Saturation' */
      ESP32Arm6DOF_B.Saturation_h = ESP32Arm6DOF_P.Saturation_LowerSat_dj;
    } else {
      /* Saturate: '<S39>/Saturation' */
      ESP32Arm6DOF_B.Saturation_h = ESP32Arm6DOF_DW.Integrator_DSTATE_c;
    }

    /* End of Saturate: '<S39>/Saturation' */

    /* MATLABSystem: '<Root>/Mid Arm Servo' */
    if (ESP32Arm6DOF_B.Saturation_h < 0.0) {
      tmp = 0U;
    } else if (ESP32Arm6DOF_B.Saturation_h > 180.0) {
      tmp = 180U;
    } else {
      rtb_Integrator_d = rt_roundd_snf(ESP32Arm6DOF_B.Saturation_h);
      if (rtb_Integrator_d < 256.0) {
        tmp = (uint8_T)rtb_Integrator_d;
      } else {
        tmp = MAX_uint8_T;
      }
    }

    MW_servoWrite(3, tmp);

    /* End of MATLABSystem: '<Root>/Mid Arm Servo' */

    /* MinMax: '<S33>/Max' incorporates:
     *  Constant: '<S33>/Time constant'
     */
    if ((ESP32Arm6DOF_B.Probe_e[0] >=
         ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_d) || rtIsNaN
        (ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_d)) {
      rtb_Integrator_d = ESP32Arm6DOF_B.Probe_e[0];
    } else {
      rtb_Integrator_d = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_d;
    }

    /* End of MinMax: '<S33>/Max' */

    /* Fcn: '<S33>/Avoid Divide by Zero' */
    ESP32Arm6DOF_B.AvoidDividebyZero_o = (real_T)(rtb_Integrator_d == 0.0) *
      2.2204460492503131e-16 + rtb_Integrator_d;
  }

  /* Product: '<S6>/1//T' incorporates:
   *  Sum: '<S6>/Sum1'
   */
  ESP32Arm6DOF_B.uT_f = 1.0 / ESP32Arm6DOF_B.AvoidDividebyZero_o * (K -
    ESP32Arm6DOF_B.Saturation_h);

  /* Gain: '<S8>/K' */
  K = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_f *
    ESP32Arm6DOF_B.RotationSignal;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Logic: '<S47>/Logical Operator' incorporates:
     *  Constant: '<S47>/Constant'
     *  Constant: '<S47>/Time constant'
     *  Constant: '<S50>/Constant'
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S50>/Compare'
     *  RelationalOperator: '<S51>/Compare'
     *  Sum: '<S47>/Sum1'
     */
    rtb_LogicalOperator_e = ((ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_i -
      ESP32Arm6DOF_B.Probe_m[0] <= ESP32Arm6DOF_P.Constant_Value_o1) &&
      (ESP32Arm6DOF_P.LowPassFilterDiscreteorConti_jr <
       ESP32Arm6DOF_P.CompareToConstant_const_f));

    /* DiscreteIntegrator: '<S53>/Integrator' */
    if (ESP32Arm6DOF_DW.Integrator_IC_LOADING_b != 0) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_p = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_p >
          ESP32Arm6DOF_P.Integrator_UpperSat_h) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_p =
          ESP32Arm6DOF_P.Integrator_UpperSat_h;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_p <
                 ESP32Arm6DOF_P.Integrator_LowerSat_be) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_p =
          ESP32Arm6DOF_P.Integrator_LowerSat_be;
      }
    }

    if (rtb_LogicalOperator_e || (ESP32Arm6DOF_DW.Integrator_PrevResetState_d !=
         0)) {
      ESP32Arm6DOF_DW.Integrator_DSTATE_p = K;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_p >
          ESP32Arm6DOF_P.Integrator_UpperSat_h) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_p =
          ESP32Arm6DOF_P.Integrator_UpperSat_h;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_p <
                 ESP32Arm6DOF_P.Integrator_LowerSat_be) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_p =
          ESP32Arm6DOF_P.Integrator_LowerSat_be;
      }
    }

    /* Saturate: '<S53>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S53>/Integrator'
     */
    if (ESP32Arm6DOF_DW.Integrator_DSTATE_p >
        ESP32Arm6DOF_P.Saturation_UpperSat_e) {
      /* Saturate: '<S53>/Saturation' */
      ESP32Arm6DOF_B.Saturation_i = ESP32Arm6DOF_P.Saturation_UpperSat_e;
    } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_p <
               ESP32Arm6DOF_P.Saturation_LowerSat_n) {
      /* Saturate: '<S53>/Saturation' */
      ESP32Arm6DOF_B.Saturation_i = ESP32Arm6DOF_P.Saturation_LowerSat_n;
    } else {
      /* Saturate: '<S53>/Saturation' */
      ESP32Arm6DOF_B.Saturation_i = ESP32Arm6DOF_DW.Integrator_DSTATE_p;
    }

    /* End of Saturate: '<S53>/Saturation' */

    /* MATLABSystem: '<Root>/Rotation Servo' */
    if (ESP32Arm6DOF_B.Saturation_i < 0.0) {
      tmp = 0U;
    } else if (ESP32Arm6DOF_B.Saturation_i > 180.0) {
      tmp = 180U;
    } else {
      rtb_Integrator_d = rt_roundd_snf(ESP32Arm6DOF_B.Saturation_i);
      if (rtb_Integrator_d < 256.0) {
        tmp = (uint8_T)rtb_Integrator_d;
      } else {
        tmp = MAX_uint8_T;
      }
    }

    MW_servoWrite(4, tmp);

    /* End of MATLABSystem: '<Root>/Rotation Servo' */

    /* MinMax: '<S47>/Max' incorporates:
     *  Constant: '<S47>/Time constant'
     */
    if ((ESP32Arm6DOF_B.Probe_m[0] >=
         ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_i) || rtIsNaN
        (ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_i)) {
      rtb_Integrator_d = ESP32Arm6DOF_B.Probe_m[0];
    } else {
      rtb_Integrator_d = ESP32Arm6DOF_P.LowPassFilterDiscreteorContin_i;
    }

    /* End of MinMax: '<S47>/Max' */

    /* Fcn: '<S47>/Avoid Divide by Zero' */
    ESP32Arm6DOF_B.AvoidDividebyZero_h = (real_T)(rtb_Integrator_d == 0.0) *
      2.2204460492503131e-16 + rtb_Integrator_d;
  }

  /* Product: '<S8>/1//T' incorporates:
   *  Sum: '<S8>/Sum1'
   */
  ESP32Arm6DOF_B.uT_gp = 1.0 / ESP32Arm6DOF_B.AvoidDividebyZero_h * (K -
    ESP32Arm6DOF_B.Saturation_i);
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor' */
    if (ESP32Arm6DOF_DW.obj_i.SampleTime !=
        ESP32Arm6DOF_P.VL53L0XTimeOfFlightSensor_Sampl) {
      ESP32Arm6DOF_DW.obj_i.SampleTime =
        ESP32Arm6DOF_P.VL53L0XTimeOfFlightSensor_Sampl;
    }

    y = calculateRange();

    /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold' incorporates:
     *  TriggerPort: '<S11>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&ESP32Arm6DOF_M->solverInfo)) {
      /* RelationalOperator: '<Root>/If 50 is Bigger Than Sensor' incorporates:
       *  Constant: '<Root>/Constant2'
       *  MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor'
       */
      ESP32Arm6DOF_PrevZCX.SampleandHold_Trig_ZCE = (ZCSigState)
        (ESP32Arm6DOF_P.Constant2_Value > y);
    }

    /* End of Outputs for SubSystem: '<Root>/Sample and Hold' */

    /* Gain: '<S87>/Derivative Gain' */
    ESP32Arm6DOF_B.DerivativeGain = ESP32Arm6DOF_P.PIDController_D * 0.0;
  }

  /* Gain: '<S97>/Filter Coefficient' incorporates:
   *  Integrator: '<S89>/Filter'
   *  Sum: '<S89>/SumD'
   */
  ESP32Arm6DOF_B.FilterCoefficient = (ESP32Arm6DOF_B.DerivativeGain -
    ESP32Arm6DOF_X.Filter_CSTATE) * ESP32Arm6DOF_P.PIDController_N;
  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    /* Gain: '<S91>/Integral Gain' */
    ESP32Arm6DOF_B.IntegralGain = ESP32Arm6DOF_P.PIDController_I * 0.0;

    /* MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor.' */
    if (ESP32Arm6DOF_DW.obj.SampleTime !=
        ESP32Arm6DOF_P.VL53L0XTimeOfFlightSensor_Sam_e) {
      ESP32Arm6DOF_DW.obj.SampleTime =
        ESP32Arm6DOF_P.VL53L0XTimeOfFlightSensor_Sam_e;
    }

    calculateRange();

    /* End of MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor.' */

    /* MATLABSystem: '<Root>/Standard Servo Write.' */
    MW_servoWrite(5, 0);

    /* S-Function (saeroclockpacer): '<Root>/Simulation Pace.' */
    /*
     * The Clock Pacer generates no code, it is only active in
     * interpreted simulation.
     */
  }

  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
      /* Update for DiscreteIntegrator: '<S46>/Integrator' */
      ESP32Arm6DOF_DW.Integrator_IC_LOADING = 0U;
      ESP32Arm6DOF_DW.Integrator_DSTATE += ESP32Arm6DOF_P.Integrator_gainval *
        ESP32Arm6DOF_B.uT;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE > ESP32Arm6DOF_P.Integrator_UpperSat)
      {
        ESP32Arm6DOF_DW.Integrator_DSTATE = ESP32Arm6DOF_P.Integrator_UpperSat;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE <
                 ESP32Arm6DOF_P.Integrator_LowerSat) {
        ESP32Arm6DOF_DW.Integrator_DSTATE = ESP32Arm6DOF_P.Integrator_LowerSat;
      }

      ESP32Arm6DOF_DW.Integrator_PrevResetState = (int8_T)rtb_LogicalOperator;

      /* End of Update for DiscreteIntegrator: '<S46>/Integrator' */

      /* Update for DiscreteIntegrator: '<S25>/Integrator' */
      ESP32Arm6DOF_DW.Integrator_IC_LOADING_l = 0U;
      ESP32Arm6DOF_DW.Integrator_DSTATE_k += ESP32Arm6DOF_P.Integrator_gainval_j
        * ESP32Arm6DOF_B.uT_l;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_k >
          ESP32Arm6DOF_P.Integrator_UpperSat_f) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_k =
          ESP32Arm6DOF_P.Integrator_UpperSat_f;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_k <
                 ESP32Arm6DOF_P.Integrator_LowerSat_f) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_k =
          ESP32Arm6DOF_P.Integrator_LowerSat_f;
      }

      ESP32Arm6DOF_DW.Integrator_PrevResetState_a = (int8_T)
        rtb_LogicalOperator_h;

      /* End of Update for DiscreteIntegrator: '<S25>/Integrator' */

      /* Update for DiscreteIntegrator: '<S60>/Integrator' */
      ESP32Arm6DOF_DW.Integrator_IC_LOADING_f = 0U;
      ESP32Arm6DOF_DW.Integrator_DSTATE_g += ESP32Arm6DOF_P.Integrator_gainval_g
        * ESP32Arm6DOF_B.uT_j;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_g >
          ESP32Arm6DOF_P.Integrator_UpperSat_g) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_g =
          ESP32Arm6DOF_P.Integrator_UpperSat_g;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_g <
                 ESP32Arm6DOF_P.Integrator_LowerSat_n) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_g =
          ESP32Arm6DOF_P.Integrator_LowerSat_n;
      }

      ESP32Arm6DOF_DW.Integrator_PrevResetState_m = (int8_T)
        rtb_LogicalOperator_g;

      /* End of Update for DiscreteIntegrator: '<S60>/Integrator' */

      /* Update for DiscreteIntegrator: '<S32>/Integrator' */
      ESP32Arm6DOF_DW.Integrator_IC_LOADING_o = 0U;
      ESP32Arm6DOF_DW.Integrator_DSTATE_n += ESP32Arm6DOF_P.Integrator_gainval_c
        * ESP32Arm6DOF_B.uT_g;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_n >
          ESP32Arm6DOF_P.Integrator_UpperSat_i) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_n =
          ESP32Arm6DOF_P.Integrator_UpperSat_i;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_n <
                 ESP32Arm6DOF_P.Integrator_LowerSat_b) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_n =
          ESP32Arm6DOF_P.Integrator_LowerSat_b;
      }

      ESP32Arm6DOF_DW.Integrator_PrevResetState_l = (int8_T)
        rtb_LogicalOperator_k;

      /* End of Update for DiscreteIntegrator: '<S32>/Integrator' */

      /* Update for DiscreteIntegrator: '<S39>/Integrator' */
      ESP32Arm6DOF_DW.Integrator_IC_LOADING_n = 0U;
      ESP32Arm6DOF_DW.Integrator_DSTATE_c += ESP32Arm6DOF_P.Integrator_gainval_k
        * ESP32Arm6DOF_B.uT_f;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_c >
          ESP32Arm6DOF_P.Integrator_UpperSat_p) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_c =
          ESP32Arm6DOF_P.Integrator_UpperSat_p;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_c <
                 ESP32Arm6DOF_P.Integrator_LowerSat_o) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_c =
          ESP32Arm6DOF_P.Integrator_LowerSat_o;
      }

      ESP32Arm6DOF_DW.Integrator_PrevResetState_ah = (int8_T)
        rtb_LogicalOperator_gb;

      /* End of Update for DiscreteIntegrator: '<S39>/Integrator' */

      /* Update for DiscreteIntegrator: '<S53>/Integrator' */
      ESP32Arm6DOF_DW.Integrator_IC_LOADING_b = 0U;
      ESP32Arm6DOF_DW.Integrator_DSTATE_p += ESP32Arm6DOF_P.Integrator_gainval_n
        * ESP32Arm6DOF_B.uT_gp;
      if (ESP32Arm6DOF_DW.Integrator_DSTATE_p >
          ESP32Arm6DOF_P.Integrator_UpperSat_h) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_p =
          ESP32Arm6DOF_P.Integrator_UpperSat_h;
      } else if (ESP32Arm6DOF_DW.Integrator_DSTATE_p <
                 ESP32Arm6DOF_P.Integrator_LowerSat_be) {
        ESP32Arm6DOF_DW.Integrator_DSTATE_p =
          ESP32Arm6DOF_P.Integrator_LowerSat_be;
      }

      ESP32Arm6DOF_DW.Integrator_PrevResetState_d = (int8_T)
        rtb_LogicalOperator_e;

      /* End of Update for DiscreteIntegrator: '<S53>/Integrator' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ESP32Arm6DOF_M)) {
    rt_ertODEUpdateContinuousStates(&ESP32Arm6DOF_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ESP32Arm6DOF_M->Timing.clockTick0;
    ESP32Arm6DOF_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ESP32Arm6DOF_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.033333333333333333s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.033333333333333333, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      ESP32Arm6DOF_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ESP32Arm6DOF_derivatives(void)
{
  XDot_ESP32Arm6DOF_T *_rtXdot;
  _rtXdot = ((XDot_ESP32Arm6DOF_T *) ESP32Arm6DOF_M->derivs);

  /* Derivatives for Integrator: '<S89>/Filter' */
  _rtXdot->Filter_CSTATE = ESP32Arm6DOF_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S94>/Integrator' */
  _rtXdot->Integrator_CSTATE = ESP32Arm6DOF_B.IntegralGain;
}

/* Model initialize function */
void ESP32Arm6DOF_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ESP32Arm6DOF_P.Integrator_UpperSat = rtInf;
  ESP32Arm6DOF_P.Integrator_LowerSat = rtMinusInf;
  ESP32Arm6DOF_P.Saturation_UpperSat = rtInf;
  ESP32Arm6DOF_P.Saturation_LowerSat = rtMinusInf;
  ESP32Arm6DOF_P.Integrator_UpperSat_f = rtInf;
  ESP32Arm6DOF_P.Integrator_LowerSat_f = rtMinusInf;
  ESP32Arm6DOF_P.Saturation_UpperSat_b = rtInf;
  ESP32Arm6DOF_P.Saturation_LowerSat_d = rtMinusInf;
  ESP32Arm6DOF_P.Integrator_UpperSat_g = rtInf;
  ESP32Arm6DOF_P.Integrator_LowerSat_n = rtMinusInf;
  ESP32Arm6DOF_P.Saturation_UpperSat_l = rtInf;
  ESP32Arm6DOF_P.Saturation_LowerSat_e = rtMinusInf;
  ESP32Arm6DOF_P.Integrator_UpperSat_i = rtInf;
  ESP32Arm6DOF_P.Integrator_LowerSat_b = rtMinusInf;
  ESP32Arm6DOF_P.Saturation_UpperSat_o = rtInf;
  ESP32Arm6DOF_P.Saturation_LowerSat_k = rtMinusInf;
  ESP32Arm6DOF_P.Integrator_UpperSat_p = rtInf;
  ESP32Arm6DOF_P.Integrator_LowerSat_o = rtMinusInf;
  ESP32Arm6DOF_P.Saturation_UpperSat_g = rtInf;
  ESP32Arm6DOF_P.Saturation_LowerSat_dj = rtMinusInf;
  ESP32Arm6DOF_P.Integrator_UpperSat_h = rtInf;
  ESP32Arm6DOF_P.Integrator_LowerSat_be = rtMinusInf;
  ESP32Arm6DOF_P.Saturation_UpperSat_e = rtInf;
  ESP32Arm6DOF_P.Saturation_LowerSat_n = rtMinusInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ESP32Arm6DOF_M->solverInfo,
                          &ESP32Arm6DOF_M->Timing.simTimeStep);
    rtsiSetTPtr(&ESP32Arm6DOF_M->solverInfo, &rtmGetTPtr(ESP32Arm6DOF_M));
    rtsiSetStepSizePtr(&ESP32Arm6DOF_M->solverInfo,
                       &ESP32Arm6DOF_M->Timing.stepSize0);
    rtsiSetdXPtr(&ESP32Arm6DOF_M->solverInfo, &ESP32Arm6DOF_M->derivs);
    rtsiSetContStatesPtr(&ESP32Arm6DOF_M->solverInfo, (real_T **)
                         &ESP32Arm6DOF_M->contStates);
    rtsiSetNumContStatesPtr(&ESP32Arm6DOF_M->solverInfo,
      &ESP32Arm6DOF_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ESP32Arm6DOF_M->solverInfo,
      &ESP32Arm6DOF_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ESP32Arm6DOF_M->solverInfo,
      &ESP32Arm6DOF_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ESP32Arm6DOF_M->solverInfo,
      &ESP32Arm6DOF_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ESP32Arm6DOF_M->solverInfo, (boolean_T**)
      &ESP32Arm6DOF_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ESP32Arm6DOF_M->solverInfo, (&rtmGetErrorStatus
      (ESP32Arm6DOF_M)));
    rtsiSetRTModelPtr(&ESP32Arm6DOF_M->solverInfo, ESP32Arm6DOF_M);
  }

  rtsiSetSimTimeStep(&ESP32Arm6DOF_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ESP32Arm6DOF_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&ESP32Arm6DOF_M->solverInfo, false);
  ESP32Arm6DOF_M->intgData.y = ESP32Arm6DOF_M->odeY;
  ESP32Arm6DOF_M->intgData.f[0] = ESP32Arm6DOF_M->odeF[0];
  ESP32Arm6DOF_M->intgData.f[1] = ESP32Arm6DOF_M->odeF[1];
  ESP32Arm6DOF_M->intgData.f[2] = ESP32Arm6DOF_M->odeF[2];
  ESP32Arm6DOF_M->contStates = ((X_ESP32Arm6DOF_T *) &ESP32Arm6DOF_X);
  ESP32Arm6DOF_M->contStateDisabled = ((XDis_ESP32Arm6DOF_T *)
    &ESP32Arm6DOF_XDis);
  ESP32Arm6DOF_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ESP32Arm6DOF_M->solverInfo, (void *)
                    &ESP32Arm6DOF_M->intgData);
  rtsiSetSolverName(&ESP32Arm6DOF_M->solverInfo,"ode3");
  rtmSetTPtr(ESP32Arm6DOF_M, &ESP32Arm6DOF_M->Timing.tArray[0]);
  ESP32Arm6DOF_M->Timing.stepSize0 = 0.033333333333333333;

  {
    int32_T i;
    char_T b[7];
    static const char_T b_0[7] = { 'D', 'e', 'f', 'a', 'u', 'l', 't' };

    /* Start for Probe: '<S19>/Probe' */
    ESP32Arm6DOF_B.Probe[0] = 0.033333333333333333;
    ESP32Arm6DOF_B.Probe[1] = 0.0;

    /* Start for Probe: '<S54>/Probe' */
    ESP32Arm6DOF_B.Probe_f[0] = 0.033333333333333333;
    ESP32Arm6DOF_B.Probe_f[1] = 0.0;

    /* Start for Probe: '<S26>/Probe' */
    ESP32Arm6DOF_B.Probe_a[0] = 0.033333333333333333;
    ESP32Arm6DOF_B.Probe_a[1] = 0.0;

    /* Start for Probe: '<S33>/Probe' */
    ESP32Arm6DOF_B.Probe_e[0] = 0.033333333333333333;
    ESP32Arm6DOF_B.Probe_e[1] = 0.0;

    /* Start for Probe: '<S47>/Probe' */
    ESP32Arm6DOF_B.Probe_m[0] = 0.033333333333333333;
    ESP32Arm6DOF_B.Probe_m[1] = 0.0;

    /* Start for Probe: '<S40>/Probe' */
    ESP32Arm6DOF_B.Probe_fr[0] = 0.033333333333333333;
    ESP32Arm6DOF_B.Probe_fr[1] = 0.0;
    ESP32Arm6DOF_PrevZCX.SampleandHold_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
    ESP32Arm6DOF_DW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S25>/Integrator' */
    ESP32Arm6DOF_DW.Integrator_IC_LOADING_l = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S60>/Integrator' */
    ESP32Arm6DOF_DW.Integrator_IC_LOADING_f = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S32>/Integrator' */
    ESP32Arm6DOF_DW.Integrator_IC_LOADING_o = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
    ESP32Arm6DOF_DW.Integrator_IC_LOADING_n = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S53>/Integrator' */
    ESP32Arm6DOF_DW.Integrator_IC_LOADING_b = 1U;

    /* InitializeConditions for Integrator: '<S89>/Filter' */
    ESP32Arm6DOF_X.Filter_CSTATE =
      ESP32Arm6DOF_P.PIDController_InitialConditionF;

    /* InitializeConditions for Integrator: '<S94>/Integrator' */
    ESP32Arm6DOF_X.Integrator_CSTATE =
      ESP32Arm6DOF_P.PIDController_InitialConditio_l;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
    /* Start for FromWorkspace: '<S13>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5,
        4.0, 4.5, 5.0, 5.5, 6.0 } ;

      static real_T pDataValues0[] = { 90.0, 180.0, 180.0, 180.0, 180.0, 180.0,
        180.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0 } ;

      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S15>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5,
        4.0, 4.5, 5.0, 5.5, 6.0 } ;

      static real_T pDataValues0[] = { 120.0, 120.0, 120.0, 120.0, 120.0, 120.0,
        120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0 } ;

      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_p.TimePtr = (void *) pTimeValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_p.DataPtr = (void *) pDataValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_k.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S16>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5,
        4.0, 4.5, 5.0, 5.5, 6.0 } ;

      static real_T pDataValues0[] = { 150.0, 150.0, 70.0, 70.0, 70.0, 150.0,
        150.0, 150.0, 70.0, 70.0, 70.0, 150.0, 150.0 } ;

      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_n.TimePtr = (void *) pTimeValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_n.DataPtr = (void *) pDataValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_i.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S18>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5,
        4.0, 4.5, 5.0, 5.5, 6.0 } ;

      static real_T pDataValues0[] = { 120.0, 120.0, 120.0, 85.0, 85.0, 120.0,
        120.0, 120.0, 120.0, 85.0, 85.0, 120.0, 120.0 } ;

      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_d.TimePtr = (void *) pTimeValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_d.DataPtr = (void *) pDataValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_l.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S17>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5,
        4.0, 4.5, 5.0, 5.5, 6.0 } ;

      static real_T pDataValues0[] = { 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0,
        60.0, 60.0, 60.0, 60.0, 60.0, 60.0 } ;

      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_f.TimePtr = (void *) pTimeValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_f.DataPtr = (void *) pDataValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_ko.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S14>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5,
        4.0, 4.5, 5.0, 5.5, 6.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 180.0, 180.0, 180.0,
        180.0, 180.0, 180.0, 0.0, 0.0, 0.0 } ;

      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_nz.TimePtr = (void *) pTimeValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_PWORK_nz.DataPtr = (void *) pDataValues0;
      ESP32Arm6DOF_DW.fromWS_Signal1_IWORK_a.PrevIndex = 0;
    }

    /* SystemInitialize for FromWorkspace: '<S13>/fromWS_Signal 1' incorporates:
     *  Outport: '<S2>/Out1'
     */
    ESP32Arm6DOF_B.BaseSig = ESP32Arm6DOF_P.Out1_Y0;

    /* SystemInitialize for FromWorkspace: '<S15>/fromWS_Signal 1' incorporates:
     *  Outport: '<S2>/Out2'
     */
    ESP32Arm6DOF_B.LowerSignal = ESP32Arm6DOF_P.Out2_Y0;

    /* SystemInitialize for FromWorkspace: '<S16>/fromWS_Signal 1' incorporates:
     *  Outport: '<S2>/Out3'
     */
    ESP32Arm6DOF_B.MidSignal = ESP32Arm6DOF_P.Out3_Y0;

    /* SystemInitialize for FromWorkspace: '<S18>/fromWS_Signal 1' incorporates:
     *  Outport: '<S2>/Out4'
     */
    ESP32Arm6DOF_B.UpperSignal = ESP32Arm6DOF_P.Out4_Y0;

    /* SystemInitialize for FromWorkspace: '<S17>/fromWS_Signal 1' incorporates:
     *  Outport: '<S2>/Out5'
     */
    ESP32Arm6DOF_B.RotationSignal = ESP32Arm6DOF_P.Out5_Y0;

    /* SystemInitialize for FromWorkspace: '<S14>/fromWS_Signal 1' incorporates:
     *  Outport: '<S2>/Out6'
     */
    ESP32Arm6DOF_B.ClawSignal = ESP32Arm6DOF_P.Out6_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */

    /* Start for MATLABSystem: '<Root>/Upper Servo' */
    ESP32Arm6DOF_DW.obj_b.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_b.isInitialized = 1;
    MW_servoAttach(6, 32);
    ESP32Arm6DOF_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Base Servo' */
    ESP32Arm6DOF_DW.obj_h5.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_h5.isInitialized = 1;
    MW_servoAttach(0, 33);
    ESP32Arm6DOF_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Claw Servo' */
    ESP32Arm6DOF_DW.obj_a.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_a.isInitialized = 1;
    MW_servoAttach(1, 12);
    ESP32Arm6DOF_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lower Arm Servo' */
    ESP32Arm6DOF_DW.obj_h.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_h.isInitialized = 1;
    MW_servoAttach(2, 26);
    ESP32Arm6DOF_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Mid Arm Servo' */
    ESP32Arm6DOF_DW.obj_j.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_j.isInitialized = 1;
    MW_servoAttach(3, 18);
    ESP32Arm6DOF_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Rotation Servo' */
    ESP32Arm6DOF_DW.obj_l.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_l.isInitialized = 1;
    MW_servoAttach(4, 13);
    ESP32Arm6DOF_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor' */
    ESP32Arm6DOF_DW.obj_i.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_i.SampleTime =
      ESP32Arm6DOF_P.VL53L0XTimeOfFlightSensor_Sampl;
    ESP32Arm6DOF_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b[i] = b_0[i];
    }

    initializeVL53L0X(41, 0U, &b[0]);
    ESP32Arm6DOF_DW.obj_i.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor' */

    /* Start for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor.' */
    ESP32Arm6DOF_DW.obj.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj.SampleTime =
      ESP32Arm6DOF_P.VL53L0XTimeOfFlightSensor_Sam_e;
    ESP32Arm6DOF_DW.obj.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b[i] = b_0[i];
    }

    initializeVL53L0X(39, 0U, &b[0]);
    ESP32Arm6DOF_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor.' */

    /* Start for MATLABSystem: '<Root>/Standard Servo Write.' */
    ESP32Arm6DOF_DW.obj_g.matlabCodegenIsDeleted = false;
    ESP32Arm6DOF_DW.obj_g.isInitialized = 1;
    MW_servoAttach(5, 5);
    ESP32Arm6DOF_DW.obj_g.isSetupComplete = true;
  }
}

/* Model terminate function */
void ESP32Arm6DOF_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Upper Servo' */
  if (!ESP32Arm6DOF_DW.obj_b.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Upper Servo' */

  /* Terminate for MATLABSystem: '<Root>/Base Servo' */
  if (!ESP32Arm6DOF_DW.obj_h5.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_h5.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Base Servo' */

  /* Terminate for MATLABSystem: '<Root>/Claw Servo' */
  if (!ESP32Arm6DOF_DW.obj_a.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Claw Servo' */

  /* Terminate for MATLABSystem: '<Root>/Lower Arm Servo' */
  if (!ESP32Arm6DOF_DW.obj_h.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lower Arm Servo' */

  /* Terminate for MATLABSystem: '<Root>/Mid Arm Servo' */
  if (!ESP32Arm6DOF_DW.obj_j.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Mid Arm Servo' */

  /* Terminate for MATLABSystem: '<Root>/Rotation Servo' */
  if (!ESP32Arm6DOF_DW.obj_l.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Rotation Servo' */

  /* Terminate for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor' */
  if (!ESP32Arm6DOF_DW.obj_i.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor' */

  /* Terminate for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor.' */
  if (!ESP32Arm6DOF_DW.obj.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/VL53L0X Time Of Flight Sensor.' */

  /* Terminate for MATLABSystem: '<Root>/Standard Servo Write.' */
  if (!ESP32Arm6DOF_DW.obj_g.matlabCodegenIsDeleted) {
    ESP32Arm6DOF_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Standard Servo Write.' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
