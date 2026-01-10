// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_PlaySound.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Components/AudioComponent.h"


void UAsyncAction_PlaySound::Local_Finish()
{
	Finished.Broadcast();
	SetReadyToDestroy();
}

void UAsyncAction_PlaySound::Activate()
{
	if(Local_IsSound2D)
	{
		Local_AudioComp = UGameplayStatics::SpawnSound2D(LocalWorldContext, Local_Sound, Local_volume, Local_pitch, Local_start);
	}
	else
	{
		Local_AudioComp = UGameplayStatics::SpawnSoundAtLocation(LocalWorldContext, Local_Sound, Local_Loc, Local_Rot, Local_volume, Local_pitch, Local_start, Local_atten);
	}
	if(Local_AudioComp)
	{
		Local_AudioComp->OnAudioFinished.AddDynamic(this, &UAsyncAction_PlaySound::Local_Finish);
		Local_AudioComp->Play(Local_start);
	}
	else
	{
		Failed.Broadcast();
	}
}

UAsyncAction_PlaySound* UAsyncAction_PlaySound::PlaySoundAsync(UObject* WorldContextObject, USoundBase* Sound,
	bool bIs2D, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime,
	USoundAttenuation* Attenuation)
{
	UAsyncAction_PlaySound* NewNode = NewObject<UAsyncAction_PlaySound>();
	NewNode->Local_atten = Attenuation;
	NewNode->Local_pitch = PitchMultiplier;
	NewNode->Local_start = StartTime;
	NewNode->Local_volume = VolumeMultiplier;
	if(Sound)
	{
		NewNode->Local_Sound = Sound;
	}
	NewNode->Local_IsSound2D = bIs2D;
	NewNode->Local_Loc = Location;
	NewNode->Local_Rot = Rotation;
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}


