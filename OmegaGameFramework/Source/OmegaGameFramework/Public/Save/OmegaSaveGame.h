// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Save/OmegaSaveBase.h"
#include "GameplayTagContainer.h"
#include "Engine/GameInstance.h"
#include "UObject/SoftObjectPath.h"


#include "OmegaSaveGame.generated.h"

class UWorld;
class UGameInstance;
class UOmegaZoneData;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveGame : public UOmegaSaveBase
{
	GENERATED_BODY()

public:

	// UPROPERTY(BlueprintReadOnly, Category="Playtime")
	// FTimecode SavedPlaytime;
	
	UPROPERTY()
	FString ActiveLevelName;

	UPROPERTY()
	FTransform SavedPlayerTransform;

	UPROPERTY()
	UOmegaZoneData* ActiveZone;

	UPROPERTY(BlueprintReadOnly, Category="Save")
	FDateTime SaveDate;

	UFUNCTION(BlueprintImplementableEvent, Category="Save")
	void OnGameStarted(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Save")
	FText GetDisplayName();

		UPROPERTY(BlueprintReadWrite, Category="Tags")
		TMap<TSoftObjectPtr<AActor>, FGameplayTag> ActorStates;
	
		UPROPERTY(BlueprintReadWrite, Category="Tags")
		TMap<TSoftObjectPtr<AActor>, FGameplayTagContainer> ActorTags;

	UPROPERTY(BlueprintReadOnly, Category="Save")
	UTexture2D* SaveScreenshot;

};

