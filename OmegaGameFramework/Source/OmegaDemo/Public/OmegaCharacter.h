// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataItemComponent.h"
#include "FlowAsset.h"
#include "Components/Component_ActorIdentity.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_ActorState.h"
#include "Components/Component_AimTargeter.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Skin.h"
#include "Components/Component_Subscript.h"
#include "Functions/OmegaFunctions_Animation.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "GameFramework/Character.h"
#include "MuCO/CustomizableSkeletalComponent.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Subsystems/OmegaSubsystem_Zone.h"
#include "OmegaCharacter.generated.h"

UCLASS(HideCategories=("Physics","Collision","Rendering"))
class OMEGADEMO_API AOmegaCharacter : public ACharacter, public IGameplayTagsInterface, public IActorInterface_AimTarget
{
	GENERATED_BODY()

	UFUNCTION()
	void OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UActorIdentityComponent* Component);
	
public:
	// Sets default values for this character's properties 
	AOmegaCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UActorIdentityComponent* ActorIdentity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UDataItemComponent* DataItem;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UCombatantComponent* Combatant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UEquipmentComponent* Equipment;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UDataAssetCollectionComponent* Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) ULevelingComponent* Leveling;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UActorStateComponent* ActorState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) USubscriptComponent* SubscriptComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) USkinComponent* SkinComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UChildActorComponent* SkinTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UGameplayPauseComponent* GameplayPause;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UAimTargetComponent* LookAim;
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OmegaCharacter",AdvancedDisplay) UCustomizableSkeletalComponent* CustomSkeletalMesh;
	
protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Local_AddCombatantSource(UObject* Source);
	UFUNCTION() void Local_LevelUpdate(int32 NewLevel);
	UFUNCTION() void Local_UpdateDataItem(UOmegaDataItem* NewItem);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter")
	UPrimaryDataAsset* CharacterAsset;

	UFUNCTION(BlueprintCallable, Category="OmegaCharacter")
	void SetCharacterAsset(UPrimaryDataAsset* Asset);

	UPROPERTY(EditAnywhere,Category="OmegaCharacter")
	UOmegaAnimationEmote* DefaultEmote;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter")
	UFlowAsset* DialogueFlow;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Animation")
	FName LookAimSocketName=TEXT("LookPoint");
	
	UPROPERTY(EditAnywhere,Category="OmegaCharacter")
	FGameplayTagContainer CharacterTags;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return CharacterTags; };

	UPROPERTY(EditDefaultsOnly,Category="OmegaCharacter",AdvancedDisplay)
	bool Autobind_NamedGlobalEvents;
	UPROPERTY(EditDefaultsOnly,Category="OmegaCharacter",AdvancedDisplay)
	bool Autobind_TaggedGlobalEvents;
	
	UFUNCTION(BlueprintImplementableEvent,Category="OmegaCharacter")
	void OnGlobalEvent_Named(FName Event, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent,Category="OmegaCharacter")
	void OnGlobalEvent_Tagged(FGameplayTag Event, UObject* Context);

	virtual FVector GetAimTargetLocation_Implementation(const UAimTargetComponent* Component) const override;
};





