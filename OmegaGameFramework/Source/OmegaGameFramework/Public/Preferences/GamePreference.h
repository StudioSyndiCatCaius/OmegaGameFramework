// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "Engine/DataAsset.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "GameplayTagContainer.h"
#include "GamePreference.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreference : public UDataAsset, public IGameplayTagsInterface, public IDataInterface_General
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
	FText PrefernceName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
	FString PreferenceLabel;

	//Is this preference saved globally save file?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
	bool bGlobal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
	FGameplayTag PreferenceCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer PreferenceTags;

//Interface

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
		FGameplayTag GetObjectGameplayCategory();
		virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
		FGameplayTagContainer GetObjectGameplayTags();
		virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();
		
		
	//DataInterface

	//Texts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralDataText(const FString& Label, const class UObject* Context,	FText& Name, FText& Description);
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description) override;

	//AssetLabel
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralAssetLabel(FString& Label);
	virtual void GetGeneralAssetLabel_Implementation(FString& Label);
};
