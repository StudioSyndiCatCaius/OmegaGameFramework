// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/Component_Combatant.h"
#include "Components/TextRenderComponent.h"
#include "Curves/CurveFloat.h"
#include "Functions/OmegaFunctions_Actor.h"

#include "GameFramework/Actor.h"
#include "Actor_FloatingCombatant.generated.h"


UCLASS()
class OMEGADEMO_API AFloatingCombatant : public AActor, public IDataInterface_FlowAsset
{
	GENERATED_BODY()

public:

	virtual void OnConstruction(const FTransform& Transform) override;

	AFloatingCombatant();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="FloatingCombatant")
	UBoxComponent* RangeBox;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="FloatingCombatant")
	UTextRenderComponent* NameText;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="FloatingCombatant")
	UFlowAsset* DialogueFlow=nullptr;
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override { return DialogueFlow;};
	
	UPROPERTY(EditAnywhere,AdvancedDisplay,Category="FloatingCombatant")
	UOmegaActorConfig* Config;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UCombatantComponent* Combatant;
	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorConfigComponent* ActorConfig;
};
