// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_ActorConfig.h"
#include "DataAssets/DA_Appearance.h"
#include "GameFramework/Character.h"
#include "Interfaces/OmegaInterface_Json.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Actor_Character.generated.h"

class UStateTreeComponent;
class UBoxComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCharacterConfig : public UOmegaActorConfig
{
	GENERATED_BODY()

public:
	
};



UCLASS(HideCategories=("Skeletal Mesh, Physics"))
class OMEGAGAMEFRAMEWORK_API AOmegaBaseCharacter : public ACharacter, public IDataInterface_Json, public IDataInterface_Traits,
																	public IDataInterface_AppearanceSource, public IDataInterface_AssetLibraries
{
	GENERATED_BODY()

	virtual void N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset);

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	AOmegaBaseCharacter();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorConfigComponent* ActorConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UStateTreeComponent* StateTree;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Character")
	UPrimaryDataAsset* CharacterAsset;

	UFUNCTION(BlueprintCallable, Category="Character")
	void SetCharacterAsset(UPrimaryDataAsset* Asset);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character")
	TSoftObjectPtr<UOAsset_Appearance> AppearanceOverride;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character",AdvancedDisplay)
	UOmegaAssetLibrary_Animation* Library_Animation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character",AdvancedDisplay)
	UOmegaAssetLibrary_Sound* Library_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character",AdvancedDisplay)
	UOmegaAssetLibrary_SlateBrush* Library_Slate;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,AdvancedDisplay, Category="Character")
	UOmegaCharacterConfig* Config;
	
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
	virtual void GetAppearanceLibraries_Implementation(UOmegaAssetLibrary_Animation*& Anim, UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate) override;
};
