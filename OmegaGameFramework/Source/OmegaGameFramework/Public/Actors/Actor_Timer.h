// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_TagEvent.h"
#include "GameFramework/Actor.h"
#include "Actor_Timer.generated.h"

class UBillboardComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaTimerActor : public AActor, public IActorTagEventInterface
{
	GENERATED_BODY()

public:
	AOmegaTimerActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/** Editor billboard to make the actor visible in the viewport. */
	UPROPERTY() UBillboardComponent* SpriteComponent;

	/** Returns true if the timer is currently counting down. */
	UFUNCTION(BlueprintPure, Category="Timer")
	bool IsTimerPlaying() const;

	/** Starts (or restarts) the timer. Returns true if successfully started. */
	UFUNCTION(BlueprintCallable, Category="Timer")
	bool PlayTimer();

	/** Stops the timer early, firing the end events. Returns true if the timer was playing. */
	UFUNCTION(BlueprintCallable, Category="Timer")
	bool StopTimer();

	/** How long the timer runs in seconds. */
	UPROPERTY(EditAnywhere, Category="Timer")
	float Duration = 2.0f;

	/** Time remaining on the current countdown. Read-only at runtime; set to 0 when not playing. */
	UPROPERTY(VisibleAnywhere, Category="Timer")
	float TimeRemaining = 0.0f;

	/** If true, the timer starts automatically on BeginPlay. */
	UPROPERTY(EditAnywhere, Category="Timer")
	bool bAutoPlay = false;

	/** If true, the timer restarts automatically each time it completes. */
	UPROPERTY(EditAnywhere, Category="Timer")
	bool bLoop = false;

	/** Tag event fired on this actor when the timer starts. */
	UPROPERTY(EditAnywhere, Category="Timer")
	FGameplayTag Event_Begin = FGameplayTag::RequestGameplayTag("Event.Misc.Start");

	/** Tag event fired on this actor when the timer ends. */
	UPROPERTY(EditAnywhere, Category="Timer")
	FGameplayTag Event_End = FGameplayTag::RequestGameplayTag("Event.Misc.Stop");

	/** Tag events fired on other actors when the timer starts. */
	UPROPERTY(EditAnywhere, Category="Timer", meta=(ShowInnerPropertiesOnly))
	FOmegaActorTagEventContainer EventsOn_Begin;

	/** Tag events fired on other actors when the timer ends. */
	UPROPERTY(EditAnywhere, Category="Timer", meta=(ShowInnerPropertiesOnly))
	FOmegaActorTagEventContainer EventsOn_End;
	
	//sound is played 2d
	UPROPERTY(EditAnywhere, Category="Timer|Sound") bool bPlaySound=true;
	
	UPROPERTY(EditAnywhere, Category="Timer|Sound") USoundBase* Sound_Default;
	//Sound to play on loop if at or under a certain percent
	UPROPERTY(EditAnywhere, Category="Timer|Sound") TMap<USoundBase*,float> Sound_AtPercent;
	
protected:
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;

private:
	/** Fires end events and optionally loops. Called when TimeRemaining hits 0. */
	void Local_OnTimerEnd();

	/** Updates the looping audio each tick based on the current timer percent. */
	void Local_TickSound();

	/** Looping audio component used for all timer sounds. */
	UPROPERTY() UAudioComponent* AudioComponent = nullptr;

	/** Tracks which Sound_AtPercent sound is currently playing, to avoid restarting it every tick. */
	UPROPERTY() USoundBase* Local_ActivePercentSound = nullptr;

	/** Replays the current sound when it finishes, as long as the timer is still running. */
	UFUNCTION() void Local_OnAudioFinished();
};


// /OmegaGameFramework/Textures/icons/pixel/OmegaIcon_I_Clock.OmegaIcon_I_Clock
