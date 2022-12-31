// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Styling/SlateBrush.h"
#include "DataInterface_General.h"
#include "GameplayTagContainer.h"
#include "Curves/CurveFloat.h"
#include "Gameplay/GameplayTagsInterface.h"

#include "OmegaAttribute.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAttribute : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Ω|Attributes")
	float GetAttributeValue(int32 Level, int32 AttributeRank, FGameplayTag ValueCategory);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Name", Category = "General")
	FText AttributeName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Description", Category = "General")
	FText AttributeDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Label", Category = "General")
	FString AttributeLabel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Icon", Category = "General")
	UTexture2D* AttributeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Color", Category = "General")
	FLinearColor AttributeColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "General")
	FLinearColor DamageColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float StartValuePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	float MaxValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	bool bIsValueStatic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	TArray<FRuntimeFloatCurve> RankValueCurves;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	TMap<FGameplayTag, float> ValueCategoryAdjustments;

	int32 LocalFloor(float Number, int32 Decimals);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value", AdvancedDisplay)
	int32 MaxDecimals = 2;
	
	//Tags
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTag AttributeCategory;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer AttributeTags;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTag GetObjectGameplayCategory();
	virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();

///Widget
	UPROPERTY(EditAnywhere, Category="Widget")
	TEnumAsByte<ERoundingMode> RoundingMode = ERoundingMode::HalfToEven;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bAlwaysSign;
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bUseGrouping = true;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinIntegralDigits = 1;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxIntegralDigits = 324;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinFractionalDigits;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxFractionalDigits = 0;
	
//DataInterface

	//Texts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralDataText(const FString& Label, const class UObject* Context,	FText& Name, FText& Description);
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description);

	//Images
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush);


	//Color
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralAssetColor(FLinearColor& Color);
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color);

	//AssetLabel
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralAssetLabel(FString& Label);
	virtual void GetGeneralAssetLabel_Implementation(FString& Label);
};
