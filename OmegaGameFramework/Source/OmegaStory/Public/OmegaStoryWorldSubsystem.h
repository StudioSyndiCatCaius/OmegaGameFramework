// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaStoryWorldSubsystem.generated.h"

class UOmegaSpeakerComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpeakerRegistered, UOmegaSpeakerComponent*, Speaker);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpeakerUnegistered, UOmegaSpeakerComponent*, Speaker);


UCLASS()
class OMEGASTORY_API UOmegaStoryWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	/////////////////
	/// Speakers ////
	////////////////

	UFUNCTION()
	void RegisterSpeaker(UOmegaSpeakerComponent* Speaker);

	UFUNCTION()
	void UnregisterSpeaker(UOmegaSpeakerComponent* Speaker);

	UPROPERTY()
	TArray<UOmegaSpeakerComponent*> RegisteredSpeakers;
	
	UFUNCTION(BlueprintPure, Category="Omega|StorySubsystem")
	TArray<UOmegaSpeakerComponent*> GetAllSpeakers();
	
	UFUNCTION(BlueprintPure, Category="Omega|StorySubsystem")
	UOmegaSpeakerComponent* GetSpeakerFromID(FGameplayTag ID);
};
