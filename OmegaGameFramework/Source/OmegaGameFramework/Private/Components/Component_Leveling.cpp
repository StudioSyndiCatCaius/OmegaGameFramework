// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Leveling.h"
#include "GameFramework/Actor.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/ProgressBar.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetTextLibrary.h"

int32 UOmegaLevelingAsset::GetLevelFromXP(float XP)
{
	float MinXP;
	float MaxXP;

	for (int i = 0; i <= MaxRank; i++)
	{
		GetXPFromLevel(i, MinXP, MaxXP);
		//if xp greater than max level
		if(i>=MaxRank)
		{
			return MaxRank;
		}
		//If XP is in this level range
		else if (XP >= MinXP && XP < MaxXP)
		{
			return i;
		}

	}
	return 0;
}

void UOmegaLevelingAsset::GetXPFromLevel(int32 Level, float& MinLevelXP, float& MaxLevelXP)
{
	const float LevelFloat = static_cast<float>(Level);
	MinLevelXP = ValueCurve.GetRichCurve()->Eval(LevelFloat);
	MaxLevelXP = ValueCurve.GetRichCurve()->Eval(LevelFloat+1.0);
}

FText UOmegaLevelingAsset::GetTextFromValue(float Value) const
{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 7
	return UKismetTextLibrary::Conv_FloatToText(Value,RoundingMode,false,true,MinIntegralDigits);
#else
	return UKismetTextLibrary::Conv_DoubleToText(Value,RoundingMode,false,true,MinIntegralDigits);
#endif
	
}

#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 7
#else
#endif
