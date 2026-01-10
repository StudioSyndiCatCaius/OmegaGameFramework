// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_AssetThumbnail.generated.h"

// ===================================================================================================================
// Skill Source
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_AssetThumbnail : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_AssetThumbnail
{
	GENERATED_BODY()
	public:

	UFUNCTION(BlueprintNativeEvent,Category="Editor|Thumbnail") UTexture2D* GetThumbnailBack_Texture();
	UFUNCTION(BlueprintNativeEvent,Category="Editor|Thumbnail") FLinearColor GetThumbnailBack_Tint();
	UFUNCTION(BlueprintNativeEvent,Category="Editor|Thumbnail") FSlateBrush GetThumbnail_Brush();
	UFUNCTION(BlueprintNativeEvent,Category="Editor|Thumbnail") FText GetThumbnail_Text();
};

