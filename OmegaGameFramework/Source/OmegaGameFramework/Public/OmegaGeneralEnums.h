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

