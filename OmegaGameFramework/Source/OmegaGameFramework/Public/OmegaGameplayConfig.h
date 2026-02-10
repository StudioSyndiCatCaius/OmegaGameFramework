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
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TMap<FName,FOmegaInputConfig> InputActionConfigs;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> ClassPaths;
	
	UFUNCTION(BlueprintPure,Category="Omega|Paths")
	TArray<FString> GetPathsFromAssetName(const FString& AssetName, TSubclassOf<UObject> Class) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAssetHandlerConfig : public UOmegaGameplayConfig
{
	GENERATED_BODY()
public:
};