// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaActors.h"
#include "Nodes/FlowNode.h"
#include "OmegaSavedLevelSequence.generated.h"

class ALevelSequenceActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSavedLevelSequenceDelegateState,AOmegaSavedLevelSequence*, Actor, bool, NewState);

UCLASS()
class OMEGADEMO_API AOmegaSavedLevelSequence : public AOmegaActorBASE
{
	GENERATED_BODY()
	
	UPROPERTY() ALevelSequenceActor* LevelSequenceActor;

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	AOmegaSavedLevelSequence();
	virtual void Tick(float DeltaTime) override;
	
	FOmegaEntity* L_GetEntity() const;
	
	bool b_isPlaying;
	
	UPROPERTY(BlueprintAssignable) FSavedLevelSequenceDelegateState OnStateChange;
	UPROPERTY(BlueprintAssignable) FSavedLevelSequenceDelegateState OnPlayingStateChange;
	
	UFUNCTION(BlueprintCallable, Category = "Saved Level Sequence") void SetSavedState(bool bState);
	
	UFUNCTION(BlueprintPure,Category="Saved Level Sequence") bool GetSavedState() const;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Level Sequence") ULevelSequence* LevelSequence;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Level Sequence") FGuid GUID;
};


UCLASS(DisplayName="Play Saved Level Sequence",Category="Debug")
class OMEGADEMO_API UFlowNode_PlaySavedLevelSequence : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_PlaySavedLevelSequence();

	UFUNCTION()
	void L_OnPlayFinish(AOmegaSavedLevelSequence* Actor, bool bNewState);
	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Cyan); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Debug") TSoftObjectPtr<AOmegaSavedLevelSequence> LevelSequenceActor;
	UPROPERTY(EditAnywhere,Category="Debug") bool bTargetState;
	
};
