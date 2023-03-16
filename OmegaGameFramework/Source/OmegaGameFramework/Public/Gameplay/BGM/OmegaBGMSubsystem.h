// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "GameplayTagContainer.h"

#include "Gameplay/GameplayTagsInterface.h"
#include "OmegaBGMSubsystem.generated.h"

USTRUCT()
struct FOmegaBGMData
{
	GENERATED_BODY()

	UPROPERTY()
	float SavedPlaybackPosition;

	UPROPERTY()
	UAudioComponent* SlotComponent;

};

USTRUCT()
struct FOmegaBGMData_Incoming
{
	GENERATED_BODY()

	UPROPERTY()
	FGameplayTag Slot;
	UPROPERTY()
	USoundBase* Sound;
	UPROPERTY()
	FTimerHandle PlayBGMHandle;
	UPROPERTY()
	bool ResumePos = false;
	UPROPERTY()
	bool DoesForcePlaybackPos = false;
	UPROPERTY()
	float ForcePlaybackPos;
	
};



UCLASS(DisplayName="Omega Subsystem: BGM")
class OMEGAGAMEFRAMEWORK_API UOmegaBGMSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


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
	
	UFUNCTION()
	float GetFadeDuration();

	UFUNCTION()
	float GetBGMVolume();
	
	UFUNCTION(BlueprintCallable, Category="Omega|BGM", meta=(AdvancedDisplay="ResumeLastPosition, FadePrevious"))
	void PlayBGM(UOmegaBGM* BGM, FGameplayTag Slot, bool ResumeLastPosition, bool FadePrevious);

	UFUNCTION(BlueprintCallable, Category="Omega|BGM")
	void StopBGM(bool Fade, float& StoppedPosition);

	UFUNCTION(BlueprintPure, Category="Omega|BGM")
	bool IsSlotPlayingBGM(FGameplayTag Slot);

	UFUNCTION(BlueprintCallable, Category="Omega|BGM")
	void SetBGMVolume(float Volume = 1.0);
	
	
	UFUNCTION()
	UAudioComponent* GetComponentBySlot(FGameplayTag Slot);
	UFUNCTION(BlueprintPure)
	float GetSavedPlaybackPosition(FGameplayTag Slot);
	
	UPROPERTY()
	TMap<FGameplayTag, FOmegaBGMData> SlotData;
	
	
};


//################################################################################################
// BGM Asset
//################################################################################################

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBGM : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BGM", DisplayName="Name")
	FText BgmName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BGM", meta=(MultiLine), DisplayName="Description")
	FText BgmDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BGM")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BGM")
	USoundBase* Sound;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};