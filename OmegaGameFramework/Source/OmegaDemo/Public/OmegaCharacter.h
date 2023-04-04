// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataItemComponent.h"
#include "Attributes/LevelingComponent.h"
#include "Data/DataAssetCollectionComponent.h"
#include "GameFramework/Character.h"
#include "Gameplay/CombatantComponent.h"
#include "Gameplay/Components/ActorStateComponent.h"
#include "Gameplay/Components/EquipmentComponent.h"
#include "OmegaCharacter.generated.h"

UCLASS()
class OMEGADEMO_API AOmegaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOmegaCharacter();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OmegaCharacter")
	UDataItemComponent* DataItem;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OmegaCharacter")
	UCombatantComponent* Combatant;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OmegaCharacter")
	UEquipmentComponent* Equipment;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OmegaCharacter")
	UDataAssetCollectionComponent* Inventory;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OmegaCharacter")
	ULevelingComponent* Leveling;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OmegaCharacter")
	UActorStateComponent* ActorState;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Local_AddCombatantSource(UObject* Source);

	UFUNCTION()
	void Local_LevelUpdate(int32 NewLevel);
	
	UFUNCTION()
	void Local_UpdateDataItem(UOmegaDataItem* NewItem)
	{
		Combatant->CombatantDataAsset = NewItem;
		Combatant->Update();
	}
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};



