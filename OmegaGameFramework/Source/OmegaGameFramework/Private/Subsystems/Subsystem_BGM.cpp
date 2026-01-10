// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_BGM.h"
#include "Subsystems/Subsystem_GamePreferences.h"
#include "OmegaSettings.h"
#include "Components/AudioComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Functions/F_Common.h"
#include "Subsystems/Subsystem_Save.h"

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

		FOmegaBgmSoundData new_dat;
		new_dat.SoundWave=BGM->Sound;
		new_dat.Loop_BeginTime=BGM->LoopBeginTime;
		new_dat.Loop_EndTime=BGM->LoopEndTime;

		//override from script
		if(BGM->BgmScript && GetWorld() && GetWorld()->GetGameInstance())
		{
			if(GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>())
			{
				FOmegaBgmSoundData override_dat= BGM->BgmScript->GetBgmSoundData(this, BGM, "");
				if(override_dat.SoundWave)
				{
					new_dat=override_dat;
				}
			}
		}
		
		//Setup Incoming Slot Data
		IncomingData.Slot = Slot;
		IncomingData.Sound = new_dat.SoundWave;
		IncomingData.ResumePos = ResumeLastPosition;
		IncomingData.FadeTime = FadeDuration;
		IncomingData.LoopEnd = new_dat.Loop_EndTime;
		IncomingData.LoopBegin = new_dat.Loop_BeginTime;

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

	if(UAudioComponent* aud=GetComponentBySlot(PlayingSlot))
	{
		if(Fade)
		{
			aud->FadeOut(FadeDuration,0);
		}
		else
		{
			aud->Stop();
		}
	}
	
}

void UOmegaBGMSubsystem::PauseBGM(bool bPaused)
{
	if(UAudioComponent* aud=GetComponentBySlot(PlayingSlot))
	{
		aud->SetPaused(bPaused);
	}
}

bool UOmegaBGMSubsystem::IsSlotPlayingBGM(FGameplayTag Slot)
{
	if(UAudioComponent* aud=GetComponentBySlot(Slot))
	{
		return PlayingSlot == Slot && aud->IsPlaying();
	}
	return false;
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
	if(UAudioComponent* aud=GetComponentBySlot(PlayingSlot))
	{
		if(Wave == aud->GetSound())
		{
			LocalSavedPosition = Wave->Duration*PlaybackPercent;
		}
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
	if(UAudioComponent* _aud=GetComponentBySlot(PlayingSlot))
	{
		//Set sound
		if(_aud->GetSound() && _aud->GetSound()->GetClass()->IsChildOf(UMetaSoundSource::StaticClass()))
		{
			_aud->SetWaveParameter(TEXT("Wav"),IncomingData.Sound);
			_aud->SetFloatParameter(TEXT("Loop_Start"),IncomingData.LoopBegin);
			_aud->SetFloatParameter(TEXT("Loop_End"),IncomingData.LoopEnd);
		}
		else
		{
			_aud->SetSound(IncomingData.Sound);
		}

		if (IncomingData.ResumePos)
		{
			_aud->FadeIn(GetFadeDuration(), GetBGMVolume(), Local_StartPos);
		}
		else
		{
			_aud->Play(0);
		}
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

void UOmegaBGM::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = this->GetName();
}

FGameplayTagContainer UOmegaBGM::GetObjectGameplayTags_Implementation()
{
	return GameplayTags;
}
