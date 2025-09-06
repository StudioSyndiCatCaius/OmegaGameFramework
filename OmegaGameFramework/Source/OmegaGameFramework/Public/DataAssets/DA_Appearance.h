// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_AssetLib.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
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
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Appearance")
	UComponentModScript_SkeletalMesh* Mesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_Animation* Library_Anim=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_Sound* Library_Voice=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_SlateBrush* Library_Slate=nullptr;

	UFUNCTION(BlueprintCallable,Category="Appearance")
	void Apply(ACharacter* c) const
	{
		if(c && Mesh)
		{
			Mesh->OnAppliedToComponent(c->GetMesh());
		}
	}
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

	UFUNCTION(BlueprintPure,Category="Omega|Appearance") static UOAsset_Appearance* GetAppearanceAsset(UObject* Source);
	UFUNCTION(BlueprintPure,Category="Omega|Appearance") static void GetAppearanceLibraries(UObject* Source,UOmegaAssetLibrary_Animation*& Anim, UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate);

};