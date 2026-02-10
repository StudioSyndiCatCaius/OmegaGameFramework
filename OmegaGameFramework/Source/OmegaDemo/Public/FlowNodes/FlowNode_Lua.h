// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaCode.h"
#include "OmegaDemo_Const.h"
#include "Actors/OmegaGameplaySystem.h"

#include "Nodes/FlowNode.h"

#include "FlowNode_Lua.generated.h"

class ULuaState;
class UOmegaEncounter_Asset;
class UOmegaQuestComponent;

UCLASS(DisplayName="🌑Lua - Call")
class OMEGADEMO_API UFlowNode_LuaCall : public UFlowNode
{
	GENERATED_BODY()
	
public:

	UFlowNode_LuaCall();

	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY() FString Code;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Lua")
	TSubclassOf<ULuaState> State;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Lua",meta=(MultiLine))
	FOmegaLuaCode Script;
	
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Lua")
	virtual void FixCodeString();
	
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Lua"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(0,0,1,1); return true;};
	virtual FString GetNodeDescription() const override { return  Script.LuaCode; };
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostLoad() override;
#endif
	
};

UCLASS(DisplayName="🌑Lua - IF")
class OMEGADEMO_API UFlowNode_LuaIf : public UFlowNode
{
	GENERATED_BODY()

public:

	UFlowNode_LuaIf();

	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Lua")
	TSubclassOf<ULuaState> State;
	UPROPERTY()
	FString Code="return ";
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Lua",meta=(MultiLine))
	FOmegaLuaCode Condition;
	
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Lua"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(1,0,0,1); return true;};
	virtual FString GetNodeDescription() const override { return  Condition.LuaCode; };
	virtual void PostLoad() override;
#endif
	
};
