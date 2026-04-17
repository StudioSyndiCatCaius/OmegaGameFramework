// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "I_Interaction.generated.h"

class AActor;

UINTERFACE()  class UActorInterface_Interactable : public UInterface
{
	GENERATED_BODY()
public:
};

class OMEGAGAMEFRAMEWORK_API IActorInterface_Interactable
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Interaction")
	void OnInteraction(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Interaction")
	bool IsInteractionBlocked(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Interaction")
	int32 GetInteraction_BitFlags();
};