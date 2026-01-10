// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Widget/DataWidget.h"
#include "Actor_WorldMapPoint.generated.h"


class UActorConfigComponent;
class UOmegaZoneData;
class USphereComponent;
class UDataWidgetComponent;
class UBillboardComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWorldMapPointDelegate, AOmegaWorldMapPoint*, point);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWorldMapPointDelegatePlayer, AOmegaWorldMapPoint*, point, APlayerController*, Player);

UCLASS(DisplayName="Ω World Map Point")
class OMEGAGAMEFRAMEWORK_API AOmegaWorldMapPoint : public AActor
{
	GENERATED_BODY()

public:
	AOmegaWorldMapPoint();
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginCursorOver() override;
	virtual void NotifyActorEndCursorOver() override;

	UPROPERTY(BlueprintAssignable) FWorldMapPointDelegatePlayer OnPointSelected;
	
	UFUNCTION() void OnDW_Selected(UDataWidget* DataWidget);

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") USphereComponent* Range;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UDataWidgetComponent* DataWidgetComponent;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorConfigComponent* Config;

	UPROPERTY() UBillboardComponent* cmp_icon;

	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Flags") bool WidgetVisible=false;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Flags") bool TransitOnWidgetSelected=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Map Point") UOmegaZoneData* Zone;
};
