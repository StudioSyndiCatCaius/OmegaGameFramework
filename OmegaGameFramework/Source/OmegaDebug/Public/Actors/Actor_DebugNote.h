// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_DebugNote.generated.h"

class UOAsset_Developer;
class UArrowComponent;
class UTextRenderComponent;

UCLASS()
class OMEGADEBUG_API AOmegaDebugNote : public AActor
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	AOmegaDebugNote();

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Debug",meta=(EditCondition="!Developer"))
	UOAsset_Developer* Developer;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Debug")
	FText Note;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Debug")
	FLinearColor Color=FLinearColor::White;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,meta=(MakeEditWidget),Category="Debug")
	FVector ArrowPoint=FVector(0,0,-400);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UArrowComponent* Arrow;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTextRenderComponent* Text;


};

