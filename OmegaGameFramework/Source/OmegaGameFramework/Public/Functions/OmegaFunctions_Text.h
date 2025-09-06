// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "OmegaFunctions_Text.generated.h"

UCLASS(Abstract)
class UOmegaTextFormater_Script : public UOmegaInstancableObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Text")
	FText FormatText(const FText& In, UObject* WorldContext, FGameplayTag Tag, FOmegaCommonMeta meta) const;
	
};


UCLASS(EditInlineNew,CollapseCategories)
class UOmegaTextFormater_Collection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Category="Text") FGameplayTagContainer Tags_Accepted;
	UPROPERTY(EditAnywhere,Category="Text") FGameplayTagContainer Tags_Rejected;
	UPROPERTY(EditAnywhere,Category="Text") TArray<UOmegaTextFormater_Collection*> Collections;
	UPROPERTY(EditAnywhere,Instanced,Category="Text") TArray<UOmegaTextFormater_Script*> Scripts;

	UFUNCTION(BlueprintCallable,Category="Text") FText ApplyTextFormat(FText in,UObject* WorldContext, FGameplayTag Tag, FOmegaCommonMeta meta);
};


UCLASS()
class UOmegaTextFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Text",meta=(WorldContext="WorldContextObject"))
	static FText ApplyGameplayTextFormating(UObject* WorldContextObject, FText In, FGameplayTag Tag, FOmegaCommonMeta meta);
	
};