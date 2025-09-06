// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDemo_Const.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Flow.generated.h"

	
UCLASS(DisplayName="Subflow - Tagged",Category="Flow")
class OMEGADEMO_API UFlowNode_SubflowTagged : public UFlowNode
{
	GENERATED_BODY()

	UFUNCTION() void L_End(UFlowAsset* FlowAsset, FName Output, const FString& Flag);
	UPROPERTY() UFlowAsset* l_subflowinst=nullptr;

public:
	UFlowNode_SubflowTagged();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Flow"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_DEBUG; return true;};
#endif

	virtual void FlowNotified_Implementation(FName Notify, UObject* Context) override;
	
	UPROPERTY(EditAnywhere,Instanced,Category="Flow") UOmegaSelector_Object* SourceObject;
	UPROPERTY(EditAnywhere,Category="Flow") FGameplayTag Tag;
	UPROPERTY(EditAnywhere,Category="Flow") FFlowAssetOverrideData OverrideData;
	UPROPERTY(EditAnywhere,Category="Flow") bool ReplicateNotifies=true;
};

