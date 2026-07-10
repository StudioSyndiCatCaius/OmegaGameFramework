// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_GameplayCue.h"
#include "GameFramework/Actor.h"
#include "Subsystems/Subsystem_World.h"
#include "Actor_InteractTransit.generated.h"

class UBillboardComponent;
class UArrowComponent;
class UBoxComponent;
class UCapsuleComponent;
class UTextRenderComponent;

// An interactable actor that transitions the player to a different level and optional spawn tag when activated.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AInteractTransit : public AActor, public IActorInterface_Interactable, public IDataInterface_General
{
	GENERATED_BODY()

	UPROPERTY() UTextRenderComponent* comp_text;

	UFUNCTION() FText L_GetName();

public:
	// Sets default values for this actor's properties
	AInteractTransit();

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override {};
	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;

	// The level to load when the player interacts with this transit point.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Transit") TSoftObjectPtr<UWorld> TransitLevel;
	// Gameplay tag used to find the matching spawn point in the destination level.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Transit") FGameplayTag SpawnTag;
	// Local offset from this actor where the player spawns in the destination level (editable as a widget in the viewport).
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Transit",AdvancedDisplay,meta=(MakeEditWidget)) FVector SpawnLocation=FVector(250,0,0);

	// Box collision component that defines the interaction trigger area.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* Range;
	UPROPERTY() UCapsuleComponent* Capsule;
	UPROPERTY() UArrowComponent* SpawnArrow;
	UPROPERTY() UArrowComponent* UpwardArrow;
	UPROPERTY() UBillboardComponent* UpwardIcon;
	UPROPERTY() UChildActorComponent* SpawnPoint;

};
