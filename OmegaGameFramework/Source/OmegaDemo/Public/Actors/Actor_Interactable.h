// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Components/Component_ActorIdentity.h"
#include "GameFramework/SpringArmComponent.h"
#include "Actor_Interactable.generated.h"

class UActorConfigComponent;
class UTextRenderComponent;

UCLASS()
class OMEGADEMO_API AOmegaInteractable : public AActor, public IDataInterface_FlowAsset, public IDataInterface_General, public IDataInterface_Traits
{
	GENERATED_BODY()

public:

	virtual void OnConstruction(const FTransform& Transform) override;

	AOmegaInteractable();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Interactable")
	TArray<UOmegaObjectTrait*> Traits;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override;
//	virtual void SetTraits_Implementation(TArray<UOmegaObjectTrait*> NewTraits) override { Traits=NewTraits; };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable",DisplayName="Name")
	FText DisplayName;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	UFlowAsset* DialogueFlow=nullptr;
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override { return DialogueFlow;};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="Interactable")
	FVector Range=FVector(1,1,1);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,meta=(MakeEditWidget),Category="Interactable")
	FVector CameraDirection=FVector(100,0,0);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTextRenderComponent* NameText;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorIdentityComponent* ActorID;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorConfigComponent* ActorConfig;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
};
