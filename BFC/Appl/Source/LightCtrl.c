/**********************************************************************************************************************

 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Implementation template
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This implementation is incomplete and is neither intended nor qualified for use in series production
 *                without applying suitable quality measures. The implementation as well as any of its modifications
 *                must be tested with diligent care and must comply with all quality requirements which are necessary
 *                according to the state of the art before its use.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  LightCtrl.c
 *        SW-C Type:  LightCtrl
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.24
 *                    RTE Core Version 4.34.0
 *          License:  DVSwcGen
 *
 *      Description:  C-Code implementation template for SW-C <LightCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * HeadLightEncoded
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * LightSwitchEncoded
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_LightCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
struct P_LightCtrl_SWC_T_ {
	float64 HysteresisTimeToOff_Value;    /* Expression: 3
										 * Referenced by: '<S1>/HysteresisTimeToOff'
										 */
	float64 HysteresisTimeToOn_Value;     /* Expression: 2
										 * Referenced by: '<S1>/HysteresisTimeToOn'
										 */
	float64 CycleTime_Value;              /* Expression: 0.01
										 * Referenced by: '<S1>/CycleTime'
										 */
};

typedef struct P_LightCtrl_SWC_T_ P_LightCtrl_SWC_T;
/* Block parameters (auto storage) */
P_LightCtrl_SWC_T LightCtrl_SWC_P = {
	3.0,
	2.0,
	0.01
};



typedef struct tag_DW_LightCtrl_SWC_T {
	float64 HysteresisTimer;              /* '<S1>/Chart' */
	uint8 is_active_c1_LightCtrl_SWC;  /* '<S1>/Chart' */
	uint8 is_c1_LightCtrl_SWC;         /* '<S1>/Chart' */
	uint8 is_AutoMode;                 /* '<S1>/Chart' */
} DW_LightCtrl_SWC_T;


#define LightCtrl_SWC_IN_AutoMode      ((uint8)1U)
#define LightCtrl_SWC_IN_EnterAutoMode ((uint8)1U)
#define LightCtrl_SWC_IN_LightOff      ((uint8)2U)
#define LightCtrl_SWC_IN_LightOn       ((uint8)3U)
#define LightCtrl_SWC_IN_LightToOff    ((uint8)4U)
#define LightCtrl_SWC_IN_LightToOn     ((uint8)5U)
#define LightCtrl_SWC_IN_OffMode       ((uint8)2U)
#define LightCtrl_SWC_IN_OnMode        ((uint8)3U)
#define LightCtrl_SW_IN_NO_ACTIVE_CHILD ((uint8)0U)
#define Pipeline_Test_Signal           ((uint8)0U)

/* Block states (auto storage) */
DW_LightCtrl_SWC_T LightCtrl_SWC_DW;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ErrorCodeLightCtrl: Integer in interval [0...255]
 * HeadLightEncoded: Integer in interval [0...255]
 * LightSwitchEncoded: Integer in interval [0...255]
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_CalThreshold_Threshold_LightIntensityToOff(void)
 *   uint8 Rte_Prm_CalThreshold_Threshold_LightIntensityToOn(void)
 *
 *********************************************************************************************************************/


#define LightCtrl_START_SEC_CODE
#include "LightCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LightCtrl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Input_LightSwitch(LightSwitchEncoded *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Error_ErrorCode(ErrorCodeLightCtrl data)
 *   Std_ReturnType Rte_Write_Output_HeadLight(HeadLightEncoded data)
 *   Std_ReturnType Rte_Write_Output_Temperature(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Implicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvIRead_LightCtrl_InterRunnableVariable(void)
 *
 *   Implicit Write Access:
 *   ----------------------
 *   void Rte_IrvIWrite_LightCtrl_InterRunnableVariable(float32 data)
 *   float32 *Rte_IrvIWriteRef_LightCtrl_InterRunnableVariable(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_LightIntensity_LightIntensity(uint16 *io_signal)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LightCtrl_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LightCtrl_CODE) LightCtrl(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LightCtrl
 *********************************************************************************************************************/
 // values: 0 = Off; 1 = On; 2 = Auto
	uint8 input_LightSwitch_local_storage;

	uint16 rtb_LightIntensity_LightIntensity;

	Rte_Read_Input_LightSwitch(&input_LightSwitch_local_storage);
	Std_ReturnType errorOnReadingLightIntensity = Rte_Call_LightIntensity_LightIntensity(&rtb_LightIntensity_LightIntensity);

	uint8 lightIntensityThresholdTurnOff = Rte_Prm_CalThreshold_Threshold_LightIntensityToOff();
	uint8 lightIntensityThresholdTurnOn = Rte_Prm_CalThreshold_Threshold_LightIntensityToOn();

	// -----------------------------------
	// ------- CHECKING FOR ERRORS -------
	// -----------------------------------

	ErrorCodeLightCtrl errorCode = NoError;
	if (errorOnReadingLightIntensity != E_OK) errorCode = ErrorLightIntensity;
	if (input_LightSwitch_local_storage > 2) errorCode = ErrorLightSwitch;
	if (lightIntensityThresholdTurnOff < lightIntensityThresholdTurnOn) errorCode = ErrorThreshold;

	// On error turn always the head light ON. Reason: Error during the night, would be bad not turning the lights on.
	if (errorCode != NoError)
	{
		Rte_Write_Error_ErrorCode(errorCode);
		Rte_Write_Output_HeadLight(TRUE);
		return;
	}

	float32 temp = Rte_IrvIRead_LightCtrl_InterRunnableVariable();
	if (temp < 80.0)
	{
		temp += 1.0;
	}
	else
	{
		temp -= 1.0;
	}
	Rte_Write_LightCtrl_Output_Temperature(temp);
	Rte_IrvIWrite_LightCtrl_InterRunnableVariable(temp);

	// --------------------------------------
	// ------- HEAD LIGHT CALCULATION -------
	// --------------------------------------

	if (LightCtrl_SWC_DW.is_active_c1_LightCtrl_SWC == 0U) {
		LightCtrl_SWC_DW.is_active_c1_LightCtrl_SWC = 1U;
		LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OffMode;
	}
	else {
		switch (LightCtrl_SWC_DW.is_c1_LightCtrl_SWC) {
		case LightCtrl_SWC_IN_AutoMode:
			/* During 'AutoMode': '<S2>:34' */
			if (input_LightSwitch_local_storage == 1) {
				/* Transition: '<S2>:39' */
				/* Exit Internal 'AutoMode': '<S2>:34' */
				LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SW_IN_NO_ACTIVE_CHILD;
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OnMode;
			}
			else if (input_LightSwitch_local_storage == 0) {
				/* Transition: '<S2>:41' */
				/* Exit Internal 'AutoMode': '<S2>:34' */
				LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SW_IN_NO_ACTIVE_CHILD;
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OffMode;
			}
			else if (input_LightSwitch_local_storage == 2) {
				switch (LightCtrl_SWC_DW.is_AutoMode) {
				case LightCtrl_SWC_IN_EnterAutoMode:
					/* During 'EnterAutoMode': '<S2>:30' */
					if (rtb_LightIntensity_LightIntensity >
						lightIntensityThresholdTurnOff) {
						/* Transition: '<S2>:32' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOff;
					}
					else {
						/* Transition: '<S2>:33' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOn;
					}
					break;

				case LightCtrl_SWC_IN_LightOff:
					/* During 'LightOff': '<S2>:2' */
					if (rtb_LightIntensity_LightIntensity <
						lightIntensityThresholdTurnOn) {
						/* Transition: '<S2>:19' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightToOn;
					}
					else {
						/* Outport: '<Root>/Output_HeadLight' */
						/* Transition: '<S2>:29' */
						Rte_Write_Output_HeadLight(FALSE);
						LightCtrl_SWC_DW.HysteresisTimer = 0.0;
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOff;
					}
					break;

				case LightCtrl_SWC_IN_LightOn:
					/* During 'LightOn': '<S2>:1' */
					if (rtb_LightIntensity_LightIntensity >
						lightIntensityThresholdTurnOff) {
						/* Transition: '<S2>:20' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightToOff;
					}
					else {
						/* Outport: '<Root>/Output_HeadLight' */
						/* Transition: '<S2>:28' */
						Rte_Write_Output_HeadLight(TRUE);
						LightCtrl_SWC_DW.HysteresisTimer = 0.0;
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOn;
					}
					break;

				case LightCtrl_SWC_IN_LightToOff:
					/* During 'LightToOff': '<S2>:3' */
					if (rtb_LightIntensity_LightIntensity <=
						lightIntensityThresholdTurnOff) {
						/* Transition: '<S2>:23' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOn;
					}
					else if (LightCtrl_SWC_DW.HysteresisTimer >=
						LightCtrl_SWC_P.HysteresisTimeToOff_Value) {
						/* Transition: '<S2>:6' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOff;
					}
					else {
						/* Transition: '<S2>:25' */
						LightCtrl_SWC_DW.HysteresisTimer += LightCtrl_SWC_P.CycleTime_Value;
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightToOff;
					}
					break;

				default:
					/* During 'LightToOn': '<S2>:4' */
					if (rtb_LightIntensity_LightIntensity >=
						lightIntensityThresholdTurnOn) {
						/* Transition: '<S2>:22' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOff;
					}
					else if (LightCtrl_SWC_DW.HysteresisTimer >=
						LightCtrl_SWC_P.HysteresisTimeToOn_Value) {
						/* Transition: '<S2>:18' */
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightOn;
					}
					else {
						/* Transition: '<S2>:24' */
						LightCtrl_SWC_DW.HysteresisTimer += LightCtrl_SWC_P.CycleTime_Value;
						LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_LightToOn;
					}
					break;
				}
			}
			else {
				// invalid light switch state
				Rte_Write_Error_ErrorCode(ErrorInvalidState);
				Rte_Write_Output_HeadLight(TRUE);
				return;
			}
			break;

		case LightCtrl_SWC_IN_OffMode:
			/* During 'OffMode': '<S2>:35' */
			if (input_LightSwitch_local_storage == 2) {
				/* Transition: '<S2>:38' */
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_AutoMode;

				/* Entry Internal 'AutoMode': '<S2>:34' */
				/* Transition: '<S2>:31' */
				LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_EnterAutoMode;
			}
			else if (input_LightSwitch_local_storage == 1) {
				/* Transition: '<S2>:45' */
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OnMode;
			}
			else if (input_LightSwitch_local_storage == 0) {
				/* Outport: '<Root>/Output_HeadLight' */
				/* Transition: '<S2>:43' */
				Rte_Write_Output_HeadLight(FALSE);
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OffMode;
			}
			else {
				// invalid light switch state
				Rte_Write_Error_ErrorCode(ErrorInvalidState);
				Rte_Write_Output_HeadLight(TRUE);
				return;
			}
			break;

		default:
			/* During 'OnMode': '<S2>:36' */
			if (input_LightSwitch_local_storage == 0) {
				/* Transition: '<S2>:40' */
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OffMode;
			}
			else if (input_LightSwitch_local_storage == 2) {
				/* Transition: '<S2>:42' */
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_AutoMode;

				/* Entry Internal 'AutoMode': '<S2>:34' */
				/* Transition: '<S2>:31' */
				LightCtrl_SWC_DW.is_AutoMode = LightCtrl_SWC_IN_EnterAutoMode;
			}
			else if (input_LightSwitch_local_storage == 1) {
				/* Outport: '<Root>/Output_HeadLight' */
				/* Transition: '<S2>:44' */
				Rte_Write_Output_HeadLight(TRUE);
				LightCtrl_SWC_DW.is_c1_LightCtrl_SWC = LightCtrl_SWC_IN_OnMode;
			}
			else {
				// invalid light switch state
				Rte_Write_Error_ErrorCode(ErrorInvalidState);
				Rte_Write_Output_HeadLight(TRUE);
				return;
			}
			break;
		}
	}

	Rte_Write_Error_ErrorCode(NoError);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define LightCtrl_STOP_SEC_CODE
#include "LightCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
