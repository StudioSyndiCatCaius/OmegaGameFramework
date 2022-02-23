// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OmegaWorldSettings.h"
#include "GameplayTagContainer.h"

#include "OmegaZoneManager.generated.h"

UCLASS()
class OMEGAWORLD_API AOmegaZoneManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaZoneManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, Category ="Zones")
	TMap<FGameplayTag, FOmegaZoneData> Zones;

	
};
