// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventTriggerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UEventTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEventTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void Native_TriggerEvent(FName Event, UObject* Instigator);

	void Local_EventOnActor (AActor* Actor, FName Event, UObject* Instigator);
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Event")
	void TriggerLocalEvent(FName Event);

	UFUNCTION(BlueprintCallable, Category="Event")
	void TriggerGlobalEvent(FName Event);

	UPROPERTY(EditAnywhere, Category="Event")
	TArray<AActor*> LocalListeningActors;

	
};
