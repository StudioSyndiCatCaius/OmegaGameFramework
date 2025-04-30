// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_Clock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClockUpdate, UOmegaClockComponent*, Component, FTimespan, Time);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClockStateChange, UOmegaClockComponent*, Component, bool, Playing);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaClockComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() FTimerHandle l_timeHandle;
	UPROPERTY() FTimespan Time;
	UPROPERTY() bool l_IsInit;
	UFUNCTION() void local_UpdateTime();
	void L_InitClock();
	virtual void BeginPlay() override;	
public:
	UPROPERTY(BlueprintAssignable) FOnClockUpdate OnClockUpdate;
	UPROPERTY(BlueprintAssignable) FOnClockStateChange OnClockStateChange;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Clock")
	bool bAutostart;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Clock")
	float UpdateRate=0.01;

	UFUNCTION(BlueprintPure,Category="Clock")
	FTimespan GetTime() const { return Time;};
	UFUNCTION(BlueprintCallable,Category="Clock")
	void SetClockPlaying(bool bPlaying);
	UFUNCTION(BlueprintPure,Category="Clock")
	bool IsClockPlaying() const;
};
