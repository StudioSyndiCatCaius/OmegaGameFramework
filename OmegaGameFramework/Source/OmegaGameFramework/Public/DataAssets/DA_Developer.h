// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Interfaces/I_Common.h"
#include "DA_Developer.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Developer : public UPrimaryDataAsset, public IDataInterface_General
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Developer")
	FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Developer")
	FLinearColor DevColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Developer")
	FGameplayTagContainer Tags;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override
	{
		Name=DisplayName;
	};
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override
	{
		Label=GetName();
	};
	virtual void GetGeneralAssetColor_Implementation(FGameplayTag Tag,FLinearColor& Color) override
	{
		Color=DevColor;
	};
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override
	{
		return Tags;
	};
};
