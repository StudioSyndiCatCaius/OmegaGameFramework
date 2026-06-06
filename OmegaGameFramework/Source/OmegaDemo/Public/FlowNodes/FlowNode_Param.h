// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "Misc/OmegaUtils_Enums.h"
#include "FlowNode_Param.generated.h"


UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_ParamBASE : public UFlowNode
{
	GENERATED_BODY()
	
	
	UFUNCTION() TArray<FName> L_GetParams() const;
public:
	
	uint8 ParamType=0;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Param") TEnumAsByte<EOmegaGlobalParamTarget> SourceTarget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Param",meta=(GetOptions="L_GetParams")) FName Param;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override
	{
		return "Global Params";
	};
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override
	{
		if (ParamType==0) { OutColor=FLinearColor(FColor::Red); }
		else if (ParamType==1) { OutColor=FLinearColor(FColor::Green); }
		else if (ParamType==2) { OutColor=FLinearColor(0,0.8,1,1); }
		else { OutColor=FLinearColor(FColor::White); }
		 
		return true;
	};
	
#endif
};

// ========================================================================================================
// BOOL
// ========================================================================================================

UCLASS(DisplayName="🌎Param (Bool) - Edit")
class OMEGADEMO_API UFlowNode_ParamBool_Edit : public UFlowNode_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_ParamBool_Edit();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") bool Value;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🌎Param (Bool) - Check?")
class OMEGADEMO_API UFlowNode_ParamBool_Check : public UFlowNode_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_ParamBool_Check();
	virtual void ExecuteInput(const FName& PinName) override;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

// ========================================================================================================
// INT
// ========================================================================================================

UCLASS(DisplayName="🌎Param (Int32) - Edit")
class OMEGADEMO_API UFlowNode_ParamInt_Edit : public UFlowNode_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_ParamInt_Edit();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") int32 Value;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") bool bAdded;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🌎Param (Int32) - Check?")
class OMEGADEMO_API UFlowNode_ParamInt_Check : public UFlowNode_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_ParamInt_Check();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Check") int32 Value;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Check") TEnumAsByte<EOmegaComparisonMethod> Method;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};


// ========================================================================================================
// DataAsset
// ========================================================================================================

UCLASS(DisplayName="🌎Param (Data Asset) - Edit")
class OMEGADEMO_API UFlowNode_ParamDA_Edit : public UFlowNode_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_ParamDA_Edit();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") UPrimaryDataAsset* Value=nullptr;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🌎Param (Data Asset) - Check?")
class OMEGADEMO_API UFlowNode_ParamDA_Check : public UFlowNode_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_ParamDA_Check();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Check") TArray<UPrimaryDataAsset*> ValidPossibles;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};


