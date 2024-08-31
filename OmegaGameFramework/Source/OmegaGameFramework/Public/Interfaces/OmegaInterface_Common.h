// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "OmegaInterface_Common.generated.h"

// ===================================================================================================================
// General Info
// ===================================================================================================================

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_General : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IDataInterface_General
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Texts"))
	void GetGeneralDataText (const FString& Label, const class UObject* Context, FText& Name, FText& Description);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Images"))
	void GetGeneralDataImages (const FString& Label, const class UObject* Context,class UTexture2D*& Texture,class UMaterialInterface*& Material,FSlateBrush& Brush);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(CompactNodeTitle="Color"))
	void GetGeneralAssetColor(FLinearColor& Color);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(CompactNodeTitle="General Label"))
	void GetGeneralAssetLabel(FString& Label);

};

// ===================================================================================================================
// Tags Interface
// ===================================================================================================================
UINTERFACE(MinimalAPI)
class UGameplayTagsInterface : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IGameplayTagsInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTag GetObjectGameplayCategory();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();

};

