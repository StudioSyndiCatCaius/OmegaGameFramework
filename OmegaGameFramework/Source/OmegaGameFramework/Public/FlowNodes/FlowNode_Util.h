// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameAsset.h"
#include "Statics/OMEGA_Content.h"
#include "FlowNode_Util.generated.h"

const FLinearColor node_col=FLinearColor(0.1,0.1,0.1,1);
const int32 node_ico_size=32;

#define pin_init_in() \
TArray<FOmegaGameplayAssetFlowPin> pin; \
FOmegaGameplayAssetFlowPin _pin; \
_pin.PinName="in"; \
pin.Add(_pin); \
Inputs=pin; \

#define pin_init_out() \
TArray<FOmegaGameplayAssetFlowPin> pin; \
FOmegaGameplayAssetFlowPin _pin; \
_pin.PinName="out"; \
pin.Add(_pin); \
Outputs=pin; \

UCLASS(Category="Util")
class OMEGAGAMEFRAMEWORK_API UFlowNode_UTIL_Begin : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Begin"); };
	virtual FLinearColor FlowNode_GetColor_Implementation() const override { return node_col; };
	virtual void FlowNode_GetConnectionPorts_Implementation(TArray<FOmegaGameplayAssetFlowPin>& Inputs, TArray<FOmegaGameplayAssetFlowPin>& Outputs) const override
	{;
		pin_init_out()
	};
	virtual FSlateBrush FlowNode_GetPortrait_Implementation() const override { return OMEGA_Content::Load_Icon_AsBrush(GetOwningGameplayAsset(),"t_OMEGA_ico_64x_node_start",node_ico_size);}
};

UCLASS(Category="Util")
class OMEGAGAMEFRAMEWORK_API UFlowNode_UTIL_Finish : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Finish"); };
	virtual FLinearColor FlowNode_GetColor_Implementation() const override { return node_col; };
	virtual void FlowNode_GetConnectionPorts_Implementation(TArray<FOmegaGameplayAssetFlowPin>& Inputs, TArray<FOmegaGameplayAssetFlowPin>& Outputs) const override
	{
		pin_init_in()
	};
	virtual FSlateBrush FlowNode_GetPortrait_Implementation() const override { return OMEGA_Content::Load_Icon_AsBrush(GetOwningGameplayAsset(),"t_OMEGA_ico_64x_node_end",node_ico_size);}
};

UCLASS(Category="Util")
class OMEGAGAMEFRAMEWORK_API UFlowNode_UTIL_HUB : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("HUB"); };
	virtual FLinearColor FlowNode_GetColor_Implementation() const override { return node_col; };
	virtual void FlowNode_GetConnectionPorts_Implementation(TArray<FOmegaGameplayAssetFlowPin>& Inputs, TArray<FOmegaGameplayAssetFlowPin>& Outputs) const override
	{
		pin_init_out()
	};
	virtual FSlateBrush FlowNode_GetIcon_Implementation() const override { return OMEGA_Content::Load_Icon_AsBrush(GetOwningGameplayAsset(),"t_OMEGA_ico_64x_node_hub",node_ico_size);}
	virtual FString FlowNode_GetDescription_Implementation() const override { return HUB.ToString();};
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Node") FName HUB;
};

UCLASS(Category="Util")
class OMEGAGAMEFRAMEWORK_API UFlowNode_UTIL_ToHUB : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("To HUB"); };
	virtual FLinearColor FlowNode_GetColor_Implementation() const override { return node_col; };
	virtual void FlowNode_GetConnectionPorts_Implementation(TArray<FOmegaGameplayAssetFlowPin>& Inputs, TArray<FOmegaGameplayAssetFlowPin>& Outputs) const override
	{
		pin_init_in()
	};
	virtual FSlateBrush FlowNode_GetIcon_Implementation() const override { return OMEGA_Content::Load_Icon_AsBrush(GetOwningGameplayAsset(),"t_OMEGA_ico_64x_node_toHub",node_ico_size);}
	virtual FString FlowNode_GetDescription_Implementation() const override { return HUB.ToString();};
	UFUNCTION() TArray<FName> L_GetHubs() const;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Node",meta=(GetOptions="L_GetHubs")) FName HUB;
};