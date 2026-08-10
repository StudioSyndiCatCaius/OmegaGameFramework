// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Components/AudioComponent.h"
#include "AsyncAction_TransitToPoint.generated.h"

class AOmegaZonePoint;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAsyncAsyncTransitToPointDelegate);

UCLASS()
class OMEGAFLOW_API UAsyncAction_TransitToPoint : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnAsyncAsyncTransitToPointDelegate Finished;
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnAsyncAsyncTransitToPointDelegate Failed;

	virtual void Activate() override;

	UFUNCTION(BlueprintInternalUseOnly, Category="Omega|AsyncGameplayTasks", meta = (WorldContext = "WorldContextObject",
		AdvancedDisplay="Player"),DisplayName="Ω🔷 Transit to Point")
	static UAsyncAction_TransitToPoint* AsyncTransitToPoint(UObject* WorldContextObject, AOmegaZonePoint* Point, APlayerController* Player=nullptr);

private:

	UPROPERTY() UObject* WorldContextObject = nullptr;
	UPROPERTY() AOmegaZonePoint* Point = nullptr;
	UPROPERTY() APlayerController* Player = nullptr;

	UFUNCTION()
	void OnPlayerSpawnedAtPoint(APlayerController* SpawnedPlayer, AOmegaZonePoint* SpawnedPoint);
};
