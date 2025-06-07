// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "DA_Developer.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Developer : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Developer")
	FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Developer")
	FLinearColor DevColor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Developer")
	FGameplayTagContainer Tags;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override
	{
		Name=DisplayName;
	};
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override
	{
		Label=GetName();
	};
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override
	{
		Color=DevColor;
	};
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override
	{
		return Tags;
	};
};
