// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Functions/OmegaFunctions_Actor.h"
#include "Components/Component_ActorConfig.h"

#include "GameFramework/Character.h"
#include "Actor_Character.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCharacterConfig : public UOmegaActorConfig
{
	GENERATED_BODY()

public:
	
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;

	AOmegaBaseCharacter();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,AdvancedDisplay, Category="OmegaCharacter")
	UOmegaCharacterConfig* Config;

	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UBoxComponent* BoundsComponent;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorConfigComponent* ActorConfig;
};
