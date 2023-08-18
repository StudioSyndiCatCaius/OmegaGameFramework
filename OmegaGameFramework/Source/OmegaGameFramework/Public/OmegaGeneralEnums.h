// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGeneralEnums.generated.h"


UENUM(Blueprintable)
enum EOmegaFunctionResult
{
	Success		UMETA(DisplayName = "Success"),
	Fail		UMETA(DisplayName = "Fail"),
};

UENUM(Blueprintable)
enum EOmegaBranch
{
	Yes	UMETA(DisplayName = "Yes"),
	No	UMETA(DisplayName = "No"),
};

UENUM(Blueprintable)
enum EOmegaStarRank
{
	Star5	UMETA(DisplayName = "★★★★★"),
	Star4	UMETA(DisplayName = "★★★★☆"),
	Star3	UMETA(DisplayName = "★★★☆☆"),
	Star2	UMETA(DisplayName = "★★☆☆☆"),
	Star1	UMETA(DisplayName = "★☆☆☆☆"),
	Star0	UMETA(DisplayName = "☆☆☆☆☆"),
};

UENUM(Blueprintable)
enum EOmegaComparisonMethod
{
	Compare_Equal		UMETA(DisplayName = "="),
	Compare_Great		UMETA(DisplayName = ">"),
	Compare_Less		UMETA(DisplayName = "<"),
	Compare_GreatEqual	UMETA(DisplayName = ">="),
	Compare_LessEqual	UMETA(DisplayName = "<="),
};