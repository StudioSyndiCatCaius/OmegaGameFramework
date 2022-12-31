// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OmegaUtils_General.generated.h"

UENUM(BlueprintType)
enum class EAddRemove : uint8
{
	Add				UMETA(DisplayName = "Add"),
	Remove          UMETA(DisplayName = "Remove"),
};

UENUM(BlueprintType)
enum class EOmegaGender : uint8
{
	NONE            UMETA(DisplayName = "N/A"),
	Male            UMETA(DisplayName = "Male"),
	Female            UMETA(DisplayName = "Female"),
};