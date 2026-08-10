// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Nodes/FlowNode.h"
#include "Styling/SlateBrush.h"
#include "Types/Struct_Material.h"
#include "FlowNode_Message.generated.h"


class UOAsset_TransformPreset;
class UOmegaMessageStageComponent;

UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_MsgStage : public UFlowNode
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure,Category="Message Stage")
	UOmegaMessageStageComponent* GetMsgStageComponent() const;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message Stage") FGameplayTag StageID;
};




UCLASS(DisplayName="💬Message - 🗣️Speaker Edit")
class OMEGADEMO_API UFlowNode_Msg_SpeakerEdit : public UFlowNode_MsgStage
{
	GENERATED_BODY()

public:
	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") bool bRemoveAllSpeakers;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") TArray<UPrimaryDataAsset*> SpeakersRemoved;

	//speakers to add to the stage, at the given (optional) position
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") TMap<UPrimaryDataAsset*,UOAsset_TransformPreset*> SpeakersAdded;
	//portrait images to set on these speakers' actors (creates the actor if it doesn't exist yet)
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") TMap<UPrimaryDataAsset*,UMaterialInstance*> SpeakerPortraits;
};



UCLASS(DisplayName="💬Message - 🖼️Image Edit")
class OMEGADEMO_API UFlowNode_Msg_ImgEdit : public UFlowNode_MsgStage
{
	GENERATED_BODY()

	FTimerHandle timer_handle;
	UFUNCTION() void L_Finished();

public:
	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif

	//message actor (matched by its SlotTag) that the image is applied to
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") FGameplayTag ImageSlotTag;
	//instead of setting an image, fades the slot actor out. delays continue until the fade finishes
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") bool bRemoveImage=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit",meta=(EditCondition="!bRemoveImage")) FSlateBrush Image;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit",meta=(EditCondition="!bRemoveImage")) FOmegaDynamicMaterialParams ImageParams;
	//transit to the new image over this time, as well as delays continue until finished
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit",meta=(EditCondition="!bRemoveImage")) float ChangeTime=0.4f;
};
