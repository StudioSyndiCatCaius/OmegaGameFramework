// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_BGM.h"
#include "Subsystems/OmegaSubsystem_GamePreferences.h"

#include "OmegaSettings.h"
#include "Components/AudioComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

UOmegaBGM* UOmegaBGMSubsystem::GetPlayingBGM()
{
	if(PlayingBGM && IsSlotPlayingBGM(PlayingSlot))
	{
		return PlayingBGM;
	}
	return nullptr;
}

float UOmegaBGMSubsystem::GetFadeDuration()
{
	return GetMutableDefault<UOmegaSettings>()->BGM_FadeDuration;
}

float UOmegaBGMSubsystem::GetBGMVolume()
{
	/*
	if(GetMutableDefault<UOmegaSettings>()->BGM_VolumePreference.IsValid())
	{
		UGamePreferenceFloat* LocalPref = LoadObject<UGamePreferenceFloat>(NULL, *GetMutableDefault<UOmegaSettings>()->BGM_VolumePreference.ToString());

		return GetWorld()->GetGameInstance()->GetSubsystem<UGamePreferenceSubsystem>()->GetGamePreferenceFloat(LocalPref);
	}
	*/
	return BgmVolume;
	
}

void UOmegaBGMSubsystem::PlayBGM(UOmegaBGM* BGM, FGameplayTag Slot, bool ResumeLastPosition, bool FadePrevious, float FadeDuration)
{
	if(bIsBgmLocked)
	{
		return;
	}
	if(BGM)
	{
		FOmegaBGMData_Incoming NewLocalIncomingData;
		IncomingData = NewLocalIncomingData;
		
		//Setup Incoming Slot Data
		IncomingData.Slot = Slot;
		IncomingData.Sound = BGM->Sound;
		IncomingData.ResumePos = ResumeLastPosition;
		IncomingData.FadeTime = FadeDuration;
		IncomingData.LoopEnd = BGM->LoopEndTime;
		IncomingData.LoopBegin = BGM->LoopBeginTime;

		float Local_StopPos;
		
		if(BGM != PlayingBGM || !IsSlotPlayingBGM(Slot))
		{
			//BEGIN PLAY BGM
			PlayingBGM = BGM;
			if(FadePrevious  && !Local_HasIncomingBGM && IsSlotPlayingBGM(PlayingSlot))	//If set to fade, not already fading, and is playing
				{
				//Lock this function until play is complete
				Local_HasIncomingBGM = true;
			
				StopBGM(true,Local_StopPos, FadeDuration);
				GetWorld()->GetTimerManager().SetTimer(IncomingData.PlayBGMHandle, this, &UOmegaBGMSubsystem::Local_FinishPlayBGM, GetFadeDuration(), false);
				}
			else
			{
				StopBGM(false,Local_StopPos);
				Local_FinishPlayBGM();
			}
		}
		else if (Slot != PlayingSlot)
		{
			StopBGM(false,Local_StopPos);
			
			//Set Data to resume from changed slot
			IncomingData.DoesForcePlaybackPos = true;
			IncomingData.ForcePlaybackPos = Local_StopPos;
			
			Local_FinishPlayBGM();
		}
	}
}

void UOmegaBGMSubsystem::StopBGM(bool Fade, float& StoppedPosition, float FadeDuration)
{
	if(bIsBgmLocked)
	{
		return;
	}
	FOmegaBGMData TempSlotData = SlotData.FindOrAdd(PlayingSlot);
	TempSlotData.SavedPlaybackPosition = LocalSavedPosition;
	StoppedPosition = LocalSavedPosition;
	SlotData.Add(PlayingSlot, TempSlotData);
	
	if(Fade)
	{
		GetComponentBySlot(PlayingSlot)->FadeOut(FadeDuration,0);
	}
	else
	{
		GetComponentBySlot(PlayingSlot)->Stop();
	}
	
}

void UOmegaBGMSubsystem::PauseBGM(bool bPaused)
{
	GetComponentBySlot(PlayingSlot)->SetPaused(bPaused);
}

bool UOmegaBGMSubsystem::IsSlotPlayingBGM(FGameplayTag Slot)
{
	return PlayingSlot == Slot && GetComponentBySlot(Slot)->IsPlaying();
}

void UOmegaBGMSubsystem::SetBGMVolume(float Volume)
{
	TArray<FGameplayTag> TempSlots;
	SlotData.GetKeys(TempSlots);
	for(FGameplayTag TempComp : TempSlots)
	{
		SlotData.Find(TempComp)->SlotComponent->SetVolumeMultiplier(Volume);
	}
	BgmVolume = Volume;
}

void UOmegaBGMSubsystem::Local_OnPlayerbackPercent(const USoundWave* Wave, const float PlaybackPercent)
{
	if(Wave == GetComponentBySlot(PlayingSlot)->GetSound())
	{
		LocalSavedPosition = Wave->Duration*PlaybackPercent;
	}
}

void UOmegaBGMSubsystem::Local_FinishPlayBGM()
{
	Local_HasIncomingBGM = false;
	PlayingSlot = IncomingData.Slot;
	//Set Starting playback position
	
	float Local_StartPos = 0;
	if(IncomingData.DoesForcePlaybackPos)		//Set from forced position (When changing slots)
	{
		Local_StartPos = IncomingData.ForcePlaybackPos;
	}
	if (IncomingData.ResumePos)
	{
		Local_StartPos = SlotData.FindOrAdd(PlayingSlot).SavedPlaybackPosition;	//Set from Resumed position
	}

	//Set sound
	if(GetComponentBySlot(PlayingSlot)->GetSound() && GetComponentBySlot(PlayingSlot)->GetSound()->GetClass()->IsChildOf(UMetaSoundSource::StaticClass()))
	{
		GetComponentBySlot(PlayingSlot)->SetWaveParameter(TEXT("Wav"),IncomingData.Sound);
		GetComponentBySlot(PlayingSlot)->SetFloatParameter(TEXT("Loop_Start"),IncomingData.LoopBegin);
		GetComponentBySlot(PlayingSlot)->SetFloatParameter(TEXT("Loop_End"),IncomingData.LoopEnd);
	}
	else
	{
		GetComponentBySlot(PlayingSlot)->SetSound(IncomingData.Sound);
	}

	if (IncomingData.ResumePos)
	{
		GetComponentBySlot(PlayingSlot)->FadeIn(GetFadeDuration(), GetBGMVolume(), Local_StartPos);
	}
	else
	{
		GetComponentBySlot(PlayingSlot)->Play(0);
	}
	
}

UAudioComponent* UOmegaBGMSubsystem::GetComponentBySlot(FGameplayTag Slot)
{
	if(SlotData.Contains(Slot) && SlotData.Find(Slot)->SlotComponent)
	{
		return SlotData.Find(Slot)->SlotComponent;
	}

	//Setup BGM Component. First check if game mode is valid
	if (AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this))
	{
		const FTransform DumTransform;

		//Try Setup Component
		if(UAudioComponent* LocalComp = Cast<UAudioComponent>(GameMode->AddComponentByClass(UAudioComponent::StaticClass(),false,DumTransform, false)))
		{
			LocalComp->VolumeMultiplier = GetBGMVolume();
			LocalComp->OnAudioPlaybackPercent.AddDynamic(this, &UOmegaBGMSubsystem::Local_OnPlayerbackPercent);
			
			FOmegaBGMData LocalNewData;
			LocalNewData.SlotComponent = LocalComp;
			SlotData.Add(Slot, LocalNewData);

			if(UMetaSoundSource* MetaSoundSource = GetMutableDefault<UOmegaSettings>()->GetMetaSoundSourceFromPath())
			{
				LocalComp->SetSound(MetaSoundSource);
			}

			return LocalComp;
		}
		
		return nullptr;
	}
	return nullptr;
}

float UOmegaBGMSubsystem::GetSavedPlaybackPosition(FGameplayTag Slot)
{
	return  SlotData.Find(Slot)->SavedPlaybackPosition;
}

//################################################################################################
// BGM Asset
//################################################################################################

void UOmegaBGM::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name = BgmName;
	Description = BgmDescription;
}

FGameplayTagContainer UOmegaBGM::GetObjectGameplayTags_Implementation()
{
	return GameplayTags;
}
