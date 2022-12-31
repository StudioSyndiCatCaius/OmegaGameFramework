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

	FinalValue = LocalFloor(FinalValue, MaxDecimals);
	
	return FinalValue;
}

//Tags

int32 UOmegaAttribute::LocalFloor(float Number, int32 Decimals)
{
	if (Number == 0)
	{
		return Number;
	}
	Decimals = FMath::Min(18, Decimals);
	if (Decimals > 0)
	{
		int64 Multiplier = 1;
		for (int32 i = 1; i <= Decimals; i++)
		{
			Multiplier *= 10;
		}
		double MultiplierFloat = static_cast<double>(Multiplier);
		return FMath::FloorToFloat(Number * MultiplierFloat) / MultiplierFloat;
	}
	if (Decimals < 0)
	{
		int64 Divider = 1;
		for (int32 i = -1; i >= Decimals; i--)
		{
			Divider *= 10;
		}
		double DividerFloat = static_cast<double>(Divider);
		return FMath::FloorToFloat(Number / DividerFloat) * DividerFloat;
	}
	return FMath::FloorToFloat(Number);
}

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
	Description = AttributeDescription;
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
