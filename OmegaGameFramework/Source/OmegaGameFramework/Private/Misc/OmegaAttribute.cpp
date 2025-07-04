// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaAttribute.h"

#include "Kismet/KismetTextLibrary.h"

FString UOmegaAttribute::GetDesc()
{
	if(!AttributeDescription.ToString().IsEmpty())
	{
		return AttributeDescription.ToString();
	}
	return Super::GetDesc();
}

float UOmegaAttribute::GetAttributeValue(int32 Level, int32 AttributeRank, FGameplayTag ValueCategory)
{
	float FinalValue = MaxValue;
	if(Script)
	{
		FinalValue =Script->GetAttributeValue(Level,ValueCategory);
	}
	else if (RankValueCurves.IsValidIndex(AttributeRank))
	{
		float LevelFloat = float(Level);
		//Get Appropriate curve by rank
		FRuntimeFloatCurve TempCurve = RankValueCurves[AttributeRank];
		//Get Attribute Value by Level
		FinalValue = TempCurve.GetRichCurve()->Eval(LevelFloat);
	}

	//Adjust along rank curve
	
	//Adjust Value if possible
	if (ValueCategory.IsValid() && ValueCategoryAdjustments.Contains(ValueCategory))
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

FText UOmegaAttribute::GetAttributeValueDisplayText(float value)
{
	if(Script)
	{
		return Script->GetDisplayText(value);
	}
	return UKismetTextLibrary::Conv_FloatToText(value,RoundingMode,
		bAlwaysSign,
		bUseGrouping,
		MinIntegralDigits,
		MaxIntegralDigits,
		MinFractionalDigits,
		MaxFractionalDigits);
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
	IDataInterface_General::GetGeneralDataImages_Implementation(Label, Context, AttributeIcon, Material, AttributeSlateIcon);
}

void UOmegaAttribute::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color = AttributeColor;
}

void UOmegaAttribute::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = AttributeLabel;
}


TArray<UOmegaAttribute*> UOmegaAttributeSet::GetAllAttributes()
{
	TArray<UOmegaAttribute*> out=Attributes;
	for (auto* TempSet : InheritedSets)
	{
		if(TempSet)
		{
			out.Append(TempSet->Attributes);
		}
	}
	return out;
}

TArray<UOmegaAttribute*> UOmegaAttributeSet::GetMetricAttributes()
{
	return Local_GetAtt(false);
}

TArray<UOmegaAttribute*> UOmegaAttributeSet::GetStaticAttributes()
{
	return Local_GetAtt(true);
}

TArray<UOmegaAttribute*> UOmegaAttributeSet::Local_GetAtt(bool bStatic)
{
	TArray<UOmegaAttribute*> OutAtts;
	for(auto* TempAtt: GetAllAttributes())
	{
		if(TempAtt && (TempAtt->bIsValueStatic == bStatic))
		{
			OutAtts.Add(TempAtt);
		}
	}
	return OutAtts;
}


TArray<FOmegaAttributeModifier> UAttributeModifierContainer::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	FOmegaAttributeModifier LocalMod;
	LocalMod.Attribute = Attribute;
	LocalMod.Incrementer = IncValue;
	LocalMod.Multiplier = MultiValue;
	
	TArray<FOmegaAttributeModifier> ModifierList;
	ModifierList.Add(LocalMod);
	
	return ModifierList;
}

FGameplayTagContainer UAttributeModifierContainer::GetObjectGameplayTags_Implementation()
{
	return Tags;
}
