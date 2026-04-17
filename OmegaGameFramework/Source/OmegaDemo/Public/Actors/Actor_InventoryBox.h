// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Actors/Actor_Prop.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Components/Component_GameplayActor.h"
#include "Components/StateTreeComponent.h"
#include "Functions/F_Component.h"
#include "GameFramework/SpringArmComponent.h"
#include "Subsystems/Subsystem_World.h"
#include "Types/Struct_CustomNamedList.h"
#include "Actor_InventoryBox.generated.h"

class UCombatantComponent;
class UDataAssetCollectionComponent;
class UActorConfigComponent;
class UTextRenderComponent;
class UUtilMeshComponent;
class UOmegaCondition_Interact;

UCLASS(DisplayName="Ω Inventory Box")
class OMEGADEMO_API AOmegaInventoryBox : public AOmegaGameplayActor, public IActorInterface_Interactable
{
	GENERATED_BODY()
	
	UFUNCTION() void L_AssetChange(UPrimaryDataAsset* Asset, int32 Amount, bool IsFull);

public:
	virtual void BeginPlay() override;
	AOmegaInventoryBox();

	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override { return !CanInteract; };
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InventoryBox") bool bSaveInventory=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InventoryBox") bool CanInteract=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InventoryBox") TMap<UPrimaryDataAsset*,int32> Items;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InventoryBox") int32 Bulk_Amount;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="InventoryBox") TArray<UPrimaryDataAsset*> Bulk_Items;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UCombatantComponent* Combatant;
	UPROPERTY() UTextRenderComponent* NameText;
	UPROPERTY() UUtilMeshComponent* UtilMesh;

};

