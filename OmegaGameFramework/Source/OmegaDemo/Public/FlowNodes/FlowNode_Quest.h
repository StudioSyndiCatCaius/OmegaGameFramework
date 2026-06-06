// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaCode.h"
#include "OmegaDemo_Const.h"
#include "Actors/OmegaGameplaySystem.h"

#include "Nodes/FlowNode.h"

#include "FlowNode_Quest.generated.h"

// ==============================================================================================================
// -
// ==============================================================================================================

UCLASS(DisplayName="📜Quest - Start",Category="Gameplay")
class OMEGADEMO_API UFlowNode_QuestStart : public UFlowNode
{
	GENERATED_BODY()

	UFUNCTION() void L_QuestEnd(AOmegaQuestInstance* comp, UOmegaQuest* q);
	
public:
	UFlowNode_QuestStart();

	virtual void ExecuteInput(const FName& PinName) override;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Quest"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_FLOW; return true;};
#endif
	UPROPERTY() AOmegaQuestInstance* QuestInstance=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flow")
	TSoftObjectPtr<UOmegaQuest> Quest;

};

UCLASS(DisplayName="📜Quest - State?",Category="Gameplay")
class OMEGADEMO_API UFlowNode_QuestState : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_QuestState();

	virtual void ExecuteInput(const FName& PinName) override;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Quest"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_FLOW; return true;};
#endif

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flow")
	TSoftObjectPtr<UOmegaQuest> Quest;

};
