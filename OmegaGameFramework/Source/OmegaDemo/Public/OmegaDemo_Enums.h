// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDemo_Enums.generated.h"


UENUM(Blueprintable)
enum EOmegaDemo_AgeGroup : uint8
{
	Age_Infant		UMETA(DisplayName = "Infant"),
	Age_Child		UMETA(DisplayName = "Child"),
	Age_Youth		UMETA(DisplayName = "Youth"),
	Age_Adult		UMETA(DisplayName = "Adult"),
	Age_Elderly		UMETA(DisplayName = "Elderly"),
};

