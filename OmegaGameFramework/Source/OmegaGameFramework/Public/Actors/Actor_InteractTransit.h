// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_GameplayCue.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Actor_InteractTransit.generated.h"

class UBillboardComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AInteractTransit : public AActor, public IActorInterface_Interactable, public IDataInterface_General
{
	GENERATED_BODY()

	UPROPERTY() UTextRenderComponent* comp_text;

	UFUNCTION() FText L_GetName() const;

public:
	// Sets default values for this actor's properties
	AInteractTransit();
	
public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Transit") TSoftObjectPtr<UWorld> TransitLevel;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Transit") FGameplayTag SpawnTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Transit",AdvancedDisplay,meta=(MakeEditWidget)) FVector SpawnLocation=FVector(250,0,0);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* Range;
	UPROPERTY() UCapsuleComponent* Capsule;
	UPROPERTY() UArrowComponent* SpawnArrow;
	UPROPERTY() UArrowComponent* UpwardArrow;
	UPROPERTY() UBillboardComponent* UpwardIcon;
	UPROPERTY() UChildActorComponent* SpawnPoint;
	
};
