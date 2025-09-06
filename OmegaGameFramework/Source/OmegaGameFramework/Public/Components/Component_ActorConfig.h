// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Component_ActorConfig.generated.h"

// =======================================================================================================================
// COMPONENT
// =======================================================================================================================


UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfigScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="ActorConfig")
	void OnActorConfigured(AActor* Actor) const;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	TArray<FGameplayTag> AutoregisterToGroups;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UOmegaActorConfigScript*> Scripts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UActorModifierScript*> BeginPlay_Modifiers;
};

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorConfigComponent : public UActorComponent
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere,Category="Config")
	UOmegaActorConfig* DefaultConfig;

	UFUNCTION(BlueprintCallable,Category="Config")
	void SetConfig(UOmegaActorConfig* Config);
};
