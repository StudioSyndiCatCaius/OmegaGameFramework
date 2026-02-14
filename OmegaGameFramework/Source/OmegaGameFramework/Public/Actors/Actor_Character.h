// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_ActorConfig.h"
#include "DataAssets/DA_Appearance.h"
#include "GameFramework/Character.h"
#include "Interfaces/I_Json.h"
#include "Interfaces/I_BitFlag.h"
#include "Interfaces/I_NamedLists.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Interfaces/I_Seed.h"
#include "Types/Struct_CustomNamedList.h"
#include "Actor_Character.generated.h"

class UComponent_DebugText;
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
																	public IDataInterface_AppearanceSource, public IDataInterface_AssetLibraries,
																public IDataInterface_General, public IDataInterface_Seed, public IDataInterface_BitFlag,
																	public IDataInterface_NamedLists
{
	GENERATED_BODY()
	
	virtual void N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset);
	void RebuildAppearance();
public:
	virtual TSubclassOf<UAnimInstance> GetContext_AnimClass();
	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	AOmegaBaseCharacter();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorConfigComponent* ActorConfig;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UStateTreeComponent* StateTree;
	UPROPERTY() UComponent_DebugText* DebugText;
	

	
	UFUNCTION(BlueprintCallable,CallInEditor,Category="OmegaCharacter")
	void RandomizeSeed();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter") FOmegaClassNamedLists NamedLists;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter")
	int32 Seed=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="OmegaCharacter")
	FOmegaBitflagsBase Flags;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter")
	UPrimaryDataAsset* CharacterAsset;

	UFUNCTION(BlueprintCallable, Category="OmegaCharacter")
	void SetCharacterAsset(UPrimaryDataAsset* Asset);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter")
	TSoftObjectPtr<UOAsset_Appearance> AppearanceOverride;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",AdvancedDisplay)
	UOmegaAssetLibrary_Animation* Library_Animation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",AdvancedDisplay)
	UOmegaAssetLibrary_Sound* Library_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",AdvancedDisplay)
	UOmegaAssetLibrary_SlateBrush* Library_Slate;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,AdvancedDisplay, Category="OmegaCharacter")
	UOmegaCharacterConfig* Config;

	virtual FOmegaBitflagsBase Bitflags_Get_Implementation() override { return Flags; };
	virtual FOmegaClassNamedLists GetClassNamedLists_Implementation() override { return NamedLists; };
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
	virtual void GetAppearanceLibraries_Implementation(UOmegaAssetLibrary_Animation*& Anim, UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate) override;
	virtual int32 GetSeed_Implementation(FName Name) override { return Seed;};
};
