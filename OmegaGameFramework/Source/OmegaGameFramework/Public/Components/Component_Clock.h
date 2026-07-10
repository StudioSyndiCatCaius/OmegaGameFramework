// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_Clock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClockUpdate, UOmegaClockComponent*, Component, FTimespan, Time);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClockStateChange, UOmegaClockComponent*, Component, bool, Playing);

// Tracks elapsed time as a Timespan and broadcasts tick events at a configurable rate. Can be started and stopped at runtime.
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
	// Fires each time the clock ticks, supplying the current elapsed time.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnClockUpdate OnClockUpdate;
	// Fires when the clock is started or stopped.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnClockStateChange OnClockStateChange;

	// When true, the clock starts running automatically at BeginPlay.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Clock")
	bool bAutostart;
	// Interval in seconds between each clock tick and delegate broadcast.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Clock")
	float UpdateRate=0.01;

	// Returns the total time elapsed on this clock.
	UFUNCTION(BlueprintPure,Category="Clock")
	FTimespan GetTime() const { return Time;};
	// Starts the clock when true, stops it when false.
	UFUNCTION(BlueprintCallable,Category="Clock")
	void SetClockPlaying(bool bPlaying);
	// Returns true if the clock is currently ticking.
	UFUNCTION(BlueprintPure,Category="Clock")
	bool IsClockPlaying() const;
};
