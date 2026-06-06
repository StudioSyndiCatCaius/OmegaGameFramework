// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Event/OmegaLinearEvent.h"
#include "LinearEvent_Zone.generated.h"

class AOmegaZonePoint;
class UOmegaZoneData;
/**
 * 
 */
UCLASS()
class OMEGADEMO_API ULinearEvent_AwaitZone : public UOmegaLinearEvent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone") UOmegaZoneData* Zone;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone") bool bAwaitSpecificPoint;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone",meta=(EditCondition="bAwaitSpecificPoint")) TSoftObjectPtr<AOmegaZonePoint> _Point;

	UFUNCTION()
	void L_OnSpawn(APlayerController* Player, AOmegaZonePoint* Point);
	virtual void Native_Begin(const FString& Flag = "") override;
	virtual void OnEventEnd_Implementation(const FString& Flag) override;
};
