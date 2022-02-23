// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Attributes/OmegaLevelingAsset.h"

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
