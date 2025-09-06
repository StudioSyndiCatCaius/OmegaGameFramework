// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaSubsystem_BGM.generated.h"

USTRUCT()
struct FOmegaBGMData
{
	GENERATED_BODY()

	UPROPERTY()float SavedPlaybackPosition=0.0f;
	UPROPERTY()UAudioComponent* SlotComponent=nullptr;

};

USTRUCT()
struct FOmegaBGMData_Incoming
{
	GENERATED_BODY()

	UPROPERTY() FGameplayTag Slot;
	UPROPERTY() USoundWave* Sound=nullptr;
	UPROPERTY() FTimerHandle PlayBGMHandle;
	UPROPERTY() bool ResumePos = false;
	UPROPERTY() bool DoesForcePlaybackPos = false;
	UPROPERTY() float ForcePlaybackPos=0.0f;
	UPROPERTY() float FadeTime=0.0f;
	UPROPERTY() float LoopBegin=0.0f;
	UPROPERTY() float LoopEnd=0.0f;
};

UCLASS(DisplayName="Omega Subsystem: BGM")
class OMEGAGAMEFRAMEWORK_API UOmegaBGMSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool bIsBgmLocked;
protected:

	UFUNCTION()
	void Local_OnPlayerbackPercent(const USoundWave* Wave, const float PlaybackPercent);
	UPROPERTY()
	float LocalSavedPosition;
	
	UFUNCTION()
	void Local_FinishPlayBGM();

	UPROPERTY()
	FOmegaBGMData_Incoming IncomingData;

	UPROPERTY()
	bool Local_HasIncomingBGM;
	
	UPROPERTY()
	float BgmVolume = 0.5;
	
public:

	UPROPERTY()
	FGameplayTag PlayingSlot;
	UPROPERTY()
	UOmegaBGM* PlayingBGM;

	UFUNCTION(BlueprintPure, Category="Omega|BGM")
	UOmegaBGM* GetPlayingBGM();
	
	UFUNCTION()
	float GetFadeDuration();

	UFUNCTION()
	float GetBGMVolume();
	
	UFUNCTION(BlueprintCallable, Category="Omega|BGM", meta=(AdvancedDisplay="ResumeLastPosition, FadeDuration, FadePrevious"))
	void PlayBGM(UOmegaBGM* BGM, FGameplayTag Slot, bool ResumeLastPosition, bool FadePrevious, float FadeDuration=0.5);

	UFUNCTION(BlueprintCallable, Category="Omega|BGM")
	void StopBGM(bool Fade, float& StoppedPosition, float FadeDuration=0.5);

	UFUNCTION(BlueprintCallable, Category="Omega|BGM")
	void PauseBGM(bool bPaused);

	UFUNCTION(BlueprintCallable, Category="Omega|BGM")
	void SetBGMLocked(bool bLocked) {bIsBgmLocked=bLocked;}

	
	UFUNCTION(BlueprintPure, Category="Omega|BGM")
	bool IsSlotPlayingBGM(FGameplayTag Slot);

	UFUNCTION(BlueprintCallable, Category="Omega|BGM")
	void SetBGMVolume(float Volume = 1.0);
	
	
	UFUNCTION()
	UAudioComponent* GetComponentBySlot(FGameplayTag Slot);
	UFUNCTION()
	float GetSavedPlaybackPosition(FGameplayTag Slot);
	
	UPROPERTY()
	TMap<FGameplayTag, FOmegaBGMData> SlotData;
	
	
};


//################################################################################################
// BGM Asset
//################################################################################################

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBgmSoundData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BGM") USoundWave* SoundWave=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BGM") float Loop_BeginTime=0.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BGM") float Loop_EndTime=0.0f;
};

UCLASS(EditInlineNew,Blueprintable,BlueprintType,Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaBGMScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Bgm Script")
	FOmegaBgmSoundData GetBgmSoundData(UOmegaBGMSubsystem* Subsystem, UOmegaBGM* BGM, const FString& style) const;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBGM : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText BgmName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", meta=(MultiLine), DisplayName="Description")
	FText BgmDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
	USoundWave* Sound;

	//The point in the Sound Wav where the bgm will begin when the loop ends
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
	float LoopBeginTime;
	//The point in the Sound Wav where the bgm where it will restart the loop
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
	float LoopEndTime=-1;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="General")
	UOmegaBGMScript* BgmScript;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};