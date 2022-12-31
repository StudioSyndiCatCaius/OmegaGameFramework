// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OmegaInstanceActor.generated.h"

class UInstanceActorComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaInstanceActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaInstanceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category="InstanceActor")
	void OnInstanceCreated(UObject* Context, const FString& Flag);
	
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor", VisibleInstanceOnly)
	UObject* ContextObject = nullptr;
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor")
	UInstanceActorComponent* OwningComponent;
};
