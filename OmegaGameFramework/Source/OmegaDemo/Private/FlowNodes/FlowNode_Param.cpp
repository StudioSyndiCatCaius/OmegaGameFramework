// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Param.h"

#include "FlowMacros.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Functions/F_GlobalParam.h"
#include "Functions/F_Math.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Macros.h"

TArray<FName> UFlowNode_ParamBASE::L_GetParams() const
{
	return OGF_GAME_CORE()->L_GetGlobalParamKeys(SourceTarget,ParamType);
}

// ========================================================================================================
// BOOL
// ========================================================================================================
UFlowNode_ParamBool_Edit::UFlowNode_ParamBool_Edit()
{
	ParamType=0;
}

void UFlowNode_ParamBool_Edit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UOmegaFunctions_GlobalVars::SetGlobalVariable_Bool(GetWorld(),SourceTarget,Param,Value);
	TriggerFirstOutput(true);
}
#if WITH_EDITOR
FString UFlowNode_ParamBool_Edit::GetNodeDescription() const
{
	FString str="SET: "+Param.ToString()+" = "+UKismetStringLibrary::Conv_BoolToString(Value);
	return *str;
}
#endif
UFlowNode_ParamBool_Check::UFlowNode_ParamBool_Check()
{
	ParamType=0;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

void UFlowNode_ParamBool_Check::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	
	if (UOmegaFunctions_GlobalVars::GetGlobalVariable_Bool(GetWorld(),SourceTarget,Param))
	{
		TriggerOutput(TEXT("true"),true);
	}
	else
	{
		TriggerOutput(TEXT("false"),true);
	}
}
#if WITH_EDITOR
FString UFlowNode_ParamBool_Check::GetNodeDescription() const
{
	FString str="IF: "+Param.ToString()+" == true";
	return *str;
}
#endif
// ========================================================================================================
// INT
// ========================================================================================================
UFlowNode_ParamInt_Edit::UFlowNode_ParamInt_Edit()
{
	ParamType=1;
}

void UFlowNode_ParamInt_Edit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	int32 new_val=Value;
	if (bAdded)
	{
		new_val+=UOmegaFunctions_GlobalVars::GetGlobalVariable_Int32(GetWorld(),SourceTarget,Param);
	}
	UOmegaFunctions_GlobalVars::SetGlobalVariable_Int32(GetWorld(),SourceTarget,Param,new_val);
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_ParamInt_Edit::GetNodeDescription() const
{
	FString edit_str=" == ";
	if (bAdded) { edit_str=" += "; }
	FString str=Param.ToString()+edit_str+UKismetStringLibrary::Conv_IntToString(Value);
	return *str;
}
#endif

UFlowNode_ParamInt_Check::UFlowNode_ParamInt_Check()
{
	ParamType=1;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

void UFlowNode_ParamInt_Check::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	
	int32 gotVal=UOmegaFunctions_GlobalVars::GetGlobalVariable_Int32(GetWorld(),SourceTarget,Param);
	
	if (UOmegaMathFunctions::Compare_Int(gotVal,Method,Value))
	{
		TriggerOutput(TEXT("true"),true);
	}
	else
	{
		TriggerOutput(TEXT("false"),true);
	}
}
#if WITH_EDITOR
FString UFlowNode_ParamInt_Check::GetNodeDescription() const
{
	FString edit_str=" == ";
	switch (Method)
	{
	case 0: edit_str=" == ";
	case 1: edit_str=" > ";
	case 2: edit_str=" < ";
	case 3: edit_str=" >= ";
	case 4: edit_str=" <= ";
	default: edit_str=" == ";
	}
	
	FString str=Param.ToString()+edit_str+UKismetStringLibrary::Conv_IntToString(Value);
	return *str;
}

#endif

// ========================================================================================================
// DataAsset
// ========================================================================================================

UFlowNode_ParamDA_Edit::UFlowNode_ParamDA_Edit()
{
	ParamType=2;
}

void UFlowNode_ParamDA_Edit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UOmegaFunctions_GlobalVars::SetGlobalVariable_DataAsset(GetWorld(),SourceTarget,Param,Value);
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_ParamDA_Edit::GetNodeDescription() const
{
	if (Value)
	{
		return Param.ToString()+" = "+Value->GetName();
	}
	return "";
}
#endif


UFlowNode_ParamDA_Check::UFlowNode_ParamDA_Check()
{
	ParamType=2;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

void UFlowNode_ParamDA_Check::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UPrimaryDataAsset* gotVal=UOmegaFunctions_GlobalVars::GetGlobalVariable_DataAsset(GetWorld(),SourceTarget,Param);
	
	if (ValidPossibles.Contains(gotVal))
	{
		TriggerOutput(TEXT("true"),true);
	}
	else
	{
		TriggerOutput(TEXT("false"),true);
	}
}

#if WITH_EDITOR
FString UFlowNode_ParamDA_Check::GetNodeDescription() const
{
	return Super::GetNodeDescription();
}
#endif
