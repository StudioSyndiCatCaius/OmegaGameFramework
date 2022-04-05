// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaAttribute.h"

float UOmegaAttribute::GetAttributeValue(int32 Level, int32 AttributeRank, FGameplayTag ValueCategory)
{

	float FinalValue = MaxValue;

	//Adjust along rank curve
	if (RankValueCurves.IsValidIndex(AttributeRank))
	{
		float LevelFloat = float(Level);
		//Get Appropriate curve by rank
		FRuntimeFloatCurve TempCurve = RankValueCurves[AttributeRank];
		//Get Attribute Value by Level
		FinalValue = TempCurve.GetRichCurve()->Eval(LevelFloat);
	}
	//Adjust Value if possible
	if (ValueCategory.IsValid()&& ValueCategoryAdjustments.Contains(ValueCategory))
	{
		FinalValue = FinalValue * ValueCategoryAdjustments[ValueCategory];
	}

	return FinalValue;
}

//Tags

FGameplayTag UOmegaAttribute::GetObjectGameplayCategory_Implementation()
{
	return AttributeCategory;
}

FGameplayTagContainer UOmegaAttribute::GetObjectGameplayTags_Implementation()
{
	return AttributeTags;
}

//General
void UOmegaAttribute::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description)
{
	Name = AttributeName;
}

void UOmegaAttribute::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	IDataInterface_General::GetGeneralDataImages_Implementation(Label, Context, AttributeIcon, Material, Brush);
}

void UOmegaAttribute::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color = AttributeColor;
}

void UOmegaAttribute::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = AttributeLabel;
}
