// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_AVContext.h"
#include "Functions/F_Localization.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "DA_AssetLib.generated.h"


class UAimOffsetBlendSpace;

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaAssetLibrary_Animation : public UOmegaDataAsset, public IDataInterface_ContextAV
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	UOmegaAssetLibrary_Animation* Fallback=nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Animations")
	TMap<FName,UAnimSequence*> Anims_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Animations")
	TMap<FName,FOmegaList_AnimSequences> Anims_NamedLists;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Montages")
	TMap<FName,UAnimMontage*> Montages_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Montages")
	TMap<FName,FOmegaList_Montages> Montages_NamedList;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="LevelSequence")
	TMap<FName,ULevelSequence*> LevelSequences_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="LevelSequence")
	TMap<FName,FOmegaList_LevelSequences> LevelSequences_NamedList;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BlendSpace")
	TMap<FName,UBlendSpace*> BlendSpace_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BlendSpace")
	TMap<FName,UAimOffsetBlendSpace*> AimBlendSpace_Named;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, UAnimSequence*> AnimSequences;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, UAnimMontage*> Montages;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, ULevelSequence*> LevelSequences;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	UBlendSpace* Default_BlendSpace=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, UBlendSpace*> BlendSpaces;
	
	// --------------------------------------------------------------------------------
	// Get asset (Single)
	// --------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	UAnimSequence* GetAnimation_Named(FName Name,bool RandomFromList, bool& Result,UAnimSequence* fall_back=nullptr);
	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	UAnimMontage* GetMontage_Named(FName Name,bool RandomFromList,bool& Result,UAnimMontage* fall_back=nullptr);
	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	ULevelSequence* GetLevelSequence_Named(FName Name,bool RandomFromList,bool& Result,ULevelSequence* fall_back=nullptr);

	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	UBlendSpace* GetBlendSpace_Named(FName Name,bool& Result,UBlendSpace* fall_back=nullptr);
	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	UAimOffsetBlendSpace* GetAimOffset_Named(FName Name,bool& Result,UAimOffsetBlendSpace* fall_back=nullptr);
	
	// --------------------------------------------------------------------------------
	// Get asset (Single)
	// --------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure,Category="AssetLibrary")
	TArray<UAnimSequence*> GetAnimation_NamedList(FName Name) const;
	UFUNCTION(BlueprintPure,Category="AssetLibrary")
	TArray<UAnimMontage*> GetMontage_NamedList(FName Name) const;
	UFUNCTION(BlueprintPure,Category="AssetLibrary")
	TArray<ULevelSequence*> GetLevelSequence_NamedList(FName Name) const;
	
	
	virtual UAnimSequence* GetContextAVAnimations_Implementation(FGameplayTag ID) override
	{
		if(AnimSequences.Contains(ID)) { return AnimSequences[ID];} return nullptr;
	}
	virtual UAnimMontage* GetContextAVMontages_Implementation(FGameplayTag ID) override
	{
		if(Montages.Contains(ID)) { return Montages[ID];} return nullptr;
	}
	virtual ULevelSequence* GetContextAVSequences_Implementation(FGameplayTag ID) override
	{
		if(LevelSequences.Contains(ID)) { return LevelSequences[ID];} return nullptr;
	}
};



UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaAssetLibrary_Sound : public UOmegaDataAsset, public IDataInterface_ContextAV, public IDataInterface_VoiceSource
{
	GENERATED_BODY()
public:
	//the voice id used to get a voice clip from the "Locale" paths. If blank, will use the source object's label.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	FString VoiceID;
	virtual FString VoiceSource_GetID_Implementation() override { return VoiceID; };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	UOmegaAssetLibrary_Sound* Fallback=nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	USoundBase* Default_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FName, USoundBase*> Sounds_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, USoundBase*> Sounds_Tagged;

	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	USoundBase* GetSound_Named(FName Name,bool& Result,USoundBase* fall_back=nullptr);
	
	virtual USoundBase* GetContextAVSounds_Implementation(FGameplayTag ID) override
	{
		if(Sounds_Tagged.Contains(ID)) { return Sounds_Tagged[ID];} return Default_Sound;
	}
};




UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaAssetLibrary_SlateBrush : public UOmegaDataAsset, public IDataInterface_ContextSlate
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	UOmegaAssetLibrary_SlateBrush* Fallback=nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	bool FallbackToIcon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	FSlateBrush Default_Brush;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FName, FSlateBrush> Brushes_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Assets")
	TMap<FGameplayTag, FSlateBrush> Brushes_Tagged;

	UFUNCTION(BlueprintCallable,Category="AssetLibrary",meta=(ExpandBoolAsExecs="Result"))
	FSlateBrush GetBrush_Named(FName Name,bool& Result,FSlateBrush fall_back=FSlateBrush());
	
	virtual FSlateBrush GetContextAV_SlateBrush_Implementation(FGameplayTag ID) override
	{
		if(Brushes_Tagged.Contains(ID))
		{
			return Brushes_Tagged[ID];
		}
		if(Default_Brush.GetResourceObject())
		{
			return Default_Brush;
		}
		if(FallbackToIcon) { return Icon;}
		return FSlateBrush();
	}
};


UINTERFACE(MinimalAPI) class UDataInterface_AssetLibraries : public UInterface
{
	GENERATED_BODY()
public:
	static bool Uses(UObject* object);
	static UOmegaAssetLibrary_Animation* getAnim(UObject* Object);
	static UOmegaAssetLibrary_SlateBrush* getSlate(UObject* Object);
	static UOmegaAssetLibrary_Sound* getSound(UObject* Object);
};
class OMEGAGAMEFRAMEWORK_API IDataInterface_AssetLibraries
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|AppearanceLibraries")
	void GetAppearanceLibraries(UOmegaAssetLibrary_Animation*& Anim,UOmegaAssetLibrary_Sound*& Sound,UOmegaAssetLibrary_SlateBrush*& Slate);

};


