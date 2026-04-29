// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Misc/OmegaGameplayModule.h"
#include "NiagaraSystem.h"
#include "Types/Struct_InputConfig.h"
#include "Types/Struct_SortedClassPath.h"
#include "OmegaGameplayConfig.generated.h"

class UOmegaPhysicsSurfaceType;
class UOmegaFaction;
class UMenu;
class UOAsset_Appearance;
class UOAsset_ActorModifierCollection;
class UEquipmentSlot;
class UOmegaAttribute;
class UOmegaAttributeSet;
class AZoneEntityDisplayActor;
class UOmegaCharacterConfig;
class UOmegaActorConfig;
class USubscriptCollection;
class AOmegaActorProcessor;
class UOmegaTextFormater_Collection;
class AOmegaActor_ChoiceBASE;
class UOmegaGameplayModule;
class AOmegaGameplaySystem;
class UOmegaFileImportScript;


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UOmegaGameplayConfig();
	
	TArray<UOmegaGameplayModule*> GetModules();
	FOmegaSortedClassPathData GetAssetDataFromClass(TSubclassOf<UObject> Class) const;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules")
	TArray<UOmegaGameplayModuleSet*> ModuleSets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Modules")
	TArray<UOmegaGameplayModule*> ScriptedModules;
	
	//Keys that will constantly on tick try to me updated with theri axis value
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Input")
	TArray<FKey> PersistentAxisKeys;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(ForceInlineRow,Categories="INPUT"), Category="Input")
	TMap<FGameplayTag,FOmegaInputConfig> InputActionConfigs;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Physics")
	TMap<UPhysicalMaterial*, UOmegaPhysicsSurfaceType*> PhysicsSurfaceTypes;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> ClassPaths;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Assets")
	TArray<UOmegaFileImportScript*> FileImportScripts;
	
	UFUNCTION(BlueprintPure,Category="Omega|Paths")
	TArray<FString> GetPathsFromAssetName(const FString& AssetName, TSubclassOf<UObject> Class) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAssetHandlerConfig : public UOmegaGameplayConfig
{
	GENERATED_BODY()
public:
};