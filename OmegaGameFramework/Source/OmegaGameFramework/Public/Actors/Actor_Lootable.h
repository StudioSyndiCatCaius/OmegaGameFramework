// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Subsystems/OmegaSubsystem_Actors.h"
#include "Actor_Lootable.generated.h"

class UDataAssetCollectionComponent;
class USkeletalMeshComponent;
class UTextRenderComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaActor_Lootable : public AActor, public IActorInterface_Interactable
{
	GENERATED_BODY()

public:

	virtual void OnConstruction(const FTransform& Transform) override;
	//virtual void OnInteraction_Implementation(AActor* Instigator, FGameplayTag Tag, UObject* Context) override;
	
	AOmegaActor_Lootable();
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UDataAssetCollectionComponent* Inventory;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USkeletalMeshComponent* Mesh;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;


};
