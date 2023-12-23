// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Components/AudioComponent.h"
#include "AsyncAction_PlaySound.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAsyncSoundFinished);


UCLASS()
class OMEGAFLOW_API UAsyncAction_PlaySound : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnAsyncSoundFinished Finished;

	UPROPERTY()
	const UObject* LocalWorldContext;
	UPROPERTY()
	UAudioComponent* Local_AudioComp;
	UPROPERTY()
	USoundBase* Local_Sound;
	UPROPERTY()
	bool Local_IsSound2D;
	UPROPERTY()
	float Local_volume;
	UPROPERTY()
	float Local_pitch;
	UPROPERTY()
	float Local_start;
	UPROPERTY()
	FVector Local_Loc;
	UPROPERTY()
	FRotator Local_Rot;
	UPROPERTY()
	USoundAttenuation* Local_atten;
	
	UFUNCTION()
	void Local_Finish();
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Rotation, VolumeMultiplier, PitchMultiplier, StarTime, Attenuation")) 
	static UAsyncAction_PlaySound* PlaySoundAsync(UObject* WorldContextObject, USoundBase* Sound, bool bIs2D, FVector Location, FRotator Rotation, float VolumeMultiplier =1, float PitchMultiplier=1, float StartTime=0, USoundAttenuation* Attenuation=nullptr);

	
};
