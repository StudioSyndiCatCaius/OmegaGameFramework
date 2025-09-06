// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "OmegaFaction.generated.h"

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

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;

private:
	
};

