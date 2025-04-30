// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "OmegaInterface_AssetThumbnail.generated.h"

class UOmegaAttribute;
class UCombatantComponent;
class UCombatantFilter;
class AOmegaGameplayEffect;

// ===================================================================================================================
// Skill Source
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_AssetThumbnail : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_AssetThumbnail
{
	GENERATED_BODY()
	public:

	UFUNCTION(BlueprintNativeEvent,Category="Editor|Thumbnail") FSlateBrush GetThumbnail_Brush();
	UFUNCTION(BlueprintNativeEvent,Category="Editor|Thumbnail") FText GetThumbnail_Text();
};

