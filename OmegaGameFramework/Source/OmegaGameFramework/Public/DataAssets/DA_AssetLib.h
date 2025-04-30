// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_AVContext.h"
#include "Misc/GeneralDataObject.h"
#include "DA_AssetLib.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaAssetLibrary_Animation : public UOmegaDataAsset, public IDataInterface_ContextAV
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	UAnimSequence* Default_AnimSequence=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, UAnimSequence*> AnimSequences;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	UAnimMontage* Default_Montage=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, UAnimMontage*> Montages;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	ULevelSequence* Default_LevelSequence=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, ULevelSequence*> LevelSequences;

	virtual UAnimSequence* GetContextAVAnimations_Implementation(FGameplayTag ID) override
	{
		if(AnimSequences.Contains(ID)) { return AnimSequences[ID];} return Default_AnimSequence;
	}
	virtual UAnimMontage* GetContextAVMontages_Implementation(FGameplayTag ID) override
	{
		if(Montages.Contains(ID)) { return Montages[ID];} return Default_Montage;
	}
	virtual ULevelSequence* GetContextAVSequences_Implementation(FGameplayTag ID) override
	{
		if(LevelSequences.Contains(ID)) { return LevelSequences[ID];} return Default_LevelSequence;
	}
};


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaAssetLibrary_Sound : public UOmegaDataAsset, public IDataInterface_ContextAV
{
	GENERATED_BODY()
public:
		
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	USoundBase* Default_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, USoundBase*> Sounds;
	
	virtual USoundBase* GetContextAVSounds_Implementation(FGameplayTag ID) override
	{
		if(Sounds.Contains(ID)) { return Sounds[ID];} return Default_Sound;
	}
};

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaAssetLibrary_SlateBrush : public UOmegaDataAsset, public IDataInterface_ContextSlate
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	bool FallbackToIcon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	FSlateBrush Default_Brush;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, FSlateBrush> Brushes;
	
	virtual FSlateBrush GetContextAV_SlateBrush_Implementation(FGameplayTag ID) override
	{
		if(Brushes.Contains(ID))
		{
			return Brushes[ID];
		}
		if(Default_Brush.GetResourceObject())
		{
			return Default_Brush;
		}
		if(FallbackToIcon) { return Icon;}
		return FSlateBrush();
	}
};
