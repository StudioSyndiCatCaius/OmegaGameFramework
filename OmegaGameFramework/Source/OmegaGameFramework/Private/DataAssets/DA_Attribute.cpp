// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_Attribute.h"
#include "Interfaces/I_Combatant.h"
#include "Curves/CurveFloat.h"
#include "Kismet/KismetTextLibrary.h"


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

float UOmegaAttribute::LocalFloor(float Number, int32 Decimals)
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

FText UOmegaAttribute::GetAttributeValueDisplayText(float value)
{
	if(Script)
	{
		return Script->GetDisplayText(value);
	}
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 7
	return UKismetTextLibrary::Conv_FloatToText(value,RoundingMode,bAlwaysSign,bUseGrouping,MinIntegralDigits,MaxIntegralDigits,MinFractionalDigits,MaxFractionalDigits);
#else
	return UKismetTextLibrary::Conv_DoubleToText(value,RoundingMode,bAlwaysSign,bUseGrouping,MinIntegralDigits,MaxIntegralDigits,MinFractionalDigits,MaxFractionalDigits);
#endif
	
}

TArray<UOmegaAttribute*> UOmegaAttributeSet::GetAllAttributes()
{
	TArray<UOmegaAttribute*> out;
	Attributes.GetKeys(out);
	for (auto* TempSet : InheritedSets)
	{
		if(TempSet)
		{
			out.Append(TempSet->GetAllAttributes());
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

float UOmegaAttributeSet::GetAttributeValue(UOmegaAttribute* Attribute, int32 level, int32 attLevel,FGameplayTag ValueCat)
{
	float out=0.0f;
	bool b_noScale=false;
	if (Attribute)
	{
		out=Attribute->GetAttributeValue(level, attLevel, ValueCat);
		
		if (Attributes.Contains(Attribute))
		{
			FOmegaAttributeSetOverride f= Attributes.FindOrAdd(Attribute);
			if (f.OverrideProgressionCurve)
			{
				out=f.OverrideProgressionCurve->GetFloatValue(level)*f.ValueScale;
				b_noScale=f.bIgnoreMasterAttributeLevelScaler;
			}
		}
		
		if (!b_noScale && MasterAttributeLevelScaler)
		{
			out=MasterAttributeLevelScaler->GetFloatValue(level)*out;
		}
	}
	return out;
}

float UOmegaAttributeSet::GetAttributeMax(UOmegaAttribute* Attribute)
{
	if (GetAllAttributes().Contains(Attribute))
	{
		TMap<UOmegaAttribute*, FOmegaAttributeSetOverride> temp=GetAttributeConfigs();
		FOmegaAttributeSetOverride f= temp.FindOrAdd(Attribute);
		if (f.bOverrideMax)
		{
			return f.MaxOverride;
		}
	}
	return 0;
}

TMap<UOmegaAttribute*, FOmegaAttributeSetOverride> UOmegaAttributeSet::GetAttributeConfigs()
{
	TMap<UOmegaAttribute*, FOmegaAttributeSetOverride> out;
	for (auto* TempSet : InheritedSets)
	{
		if (TempSet)
		{
			out.Append(TempSet->GetAttributeConfigs());
		}
	}
	out.Append(Attributes);
	
	return out;
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


TArray<FOmegaAttributeModifier> UDataInterface_Combatant::GetObjectModifiers(UCombatantComponent* Combatant, UObject* object)
{
	if (object && object->GetClass()->ImplementsInterface(StaticClass()))
	{
		return IDataInterface_Combatant::Execute_GetModifierValues(object, Combatant);
	}
	return {};
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

