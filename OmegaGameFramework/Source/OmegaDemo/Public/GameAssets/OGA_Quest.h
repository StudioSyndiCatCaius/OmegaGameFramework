// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameAsset.h"
#include "OGA_Quest.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADEMO_API UOmegaGA_Quest : public UOmegaGameAsset
{
	GENERATED_BODY()
public:
	virtual TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> FlowGraph_GetAvailableNodes_Implementation() const override;
	virtual void GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const override;
};

UCLASS(Abstract)
class OMEGADEMO_API UOGA_Node_QuestTask : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	UOGA_Node_QuestTask();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") FName EventToAwait;
};


UCLASS(Category="Quest")
class OMEGADEMO_API UOGA_Node_Quest_AwaitGEvent : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Await (Global Event)"); };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") FName EventToAwait;
};

UCLASS(Category="Quest")
class OMEGADEMO_API UOGA_Node_Quest_Dialogue : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Dialogue"); };
	
};

UCLASS(Category="Quest")
class OMEGADEMO_API UOGA_Node_Quest_Battle : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Battle"); };
	
};


UCLASS(Category="Quest")
class OMEGADEMO_API UOGA_Node_Quest_LevelTransit : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Level Transit"); };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") TSoftObjectPtr<UWorld> Level;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") FGameplayTag SpawnTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") bool bTransitIfNotCurrent;
};