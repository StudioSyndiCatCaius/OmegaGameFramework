// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_AssetLib.h"
#include "Functions/F_Component.h"
#include "GameFramework/Character.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Appearance.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Appearance : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	virtual FLinearColor GetThumbnailBack_Tint_Implementation() override { return FLinearColor(FColor::Magenta); };
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	TSoftClassPtr<AActor> ActorClass;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(ForceInlineRow),Category="Appearance")
	FComponentMod_SkeletalMesh Mesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_Animation* Library_Anim=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_Sound* Library_Voice=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_SlateBrush* Library_Slate=nullptr;

	UFUNCTION(BlueprintCallable,Category="Appearance")
	void Apply(ACharacter* c) const;
};

UINTERFACE(MinimalAPI) class UDataInterface_AppearanceSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_AppearanceSource
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Appearance")
	UOAsset_Appearance* GetAppearanceAsset();

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAppearanceFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Appearance",DisplayName="👹Appearance - Get Asset") static UOAsset_Appearance* GetAppearanceAsset(UObject* Source);
	/**
	 * Will attempt Get the appearance libraries from the object.
	 * Check order:
	 *		1. First checks if the object has any valid libraries DIRECTLY.
	 *		2. if one library is missing, it will check if the object has a valid Appearance asset and if it has siad library
	 *		3. of not, that library returns null
	 */
	UFUNCTION(BlueprintPure,Category="Omega|Appearance",DisplayName="👹Appearance - Get Libraries") static void GetAppearanceLibraries(UObject* Source,UOmegaAssetLibrary_Animation*& Anim, UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate);

};