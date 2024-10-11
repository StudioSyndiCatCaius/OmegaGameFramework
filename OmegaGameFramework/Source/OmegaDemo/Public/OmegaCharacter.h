// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataItemComponent.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Inventory.h"
#include "Components/CombatantComponent.h"
#include "Components/Component_ActorState.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Subscript.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "GameFramework/Character.h"
#include "OmegaCharacter.generated.h"

UCLASS(HideCategories=("Physics","Collision","Rendering"))
class OMEGADEMO_API AOmegaCharacter : public ACharacter, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOmegaCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UDataItemComponent* DataItem;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UCombatantComponent* Combatant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UEquipmentComponent* Equipment;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UDataAssetCollectionComponent* Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) ULevelingComponent* Leveling;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UActorStateComponent* ActorState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) USubscriptComponent* SubscriptComponent;
	
protected:
	virtual void OnConstruction(const FTransform& Transform) override;
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

	UPROPERTY(EditAnywhere,Category="OmegaCharacter")
	UOmegaDataItem* CharacterAsset;

	UPROPERTY(EditAnywhere,Category="OmegaCharacter")
	FGameplayTagContainer CharacterTags;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return CharacterTags; };
};



