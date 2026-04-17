// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Interfaces/I_Common.h"
#include "DA_Faction.generated.h"

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaFaction : public UPrimaryDataAsset, public IDataInterface_General
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FText FactionName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FSlateBrush FactionIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FLinearColor FactionColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tag")
	FGameplayTag FactionTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tag")
	TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> FactionAffinities;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override
	{
		Name=FactionName;
	};
	virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override
	{
		Brush=FactionIcon;
	};
	virtual void GetGeneralAssetColor_Implementation(FGameplayTag Tag, FLinearColor& Color) override
	{
		Color=FactionColor;
	};
	
private:
	
};

