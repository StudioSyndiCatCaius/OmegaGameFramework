// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Component_SkeletalGhost.generated.h"

UCLASS(Blueprintable,BlueprintType,Abstract,EditInlineNew,Const,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API USkeletalGhostScript : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Skeletal Ghost")
	void OnMeshLinked(USkeletalMeshComponent* DriverMesh,	USkeletalMeshComponent* GhostMesh) const;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API USkeletalGhostComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<USkeletalMeshComponent*,USkeletalMeshComponent*> LinkedGhostMeshes;

public:
	// Sets default values for this component's properties
	//USkeletalGhostComponent();

	UPROPERTY(EditAnywhere,Instanced, BlueprintReadWrite,Category="Skeletal Ghost")
	TArray<USkeletalGhostScript*> Scripts;
	
	UFUNCTION(BlueprintCallable,Category="Skeletal Ghost")
	void LinkSkeletalMeshComponents(USkeletalMeshComponent* DriverMesh,	USkeletalMeshComponent* GhostMesh);

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};

