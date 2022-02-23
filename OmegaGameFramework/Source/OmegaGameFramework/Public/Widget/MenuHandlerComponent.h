// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Menu.h"
#include "Components/ActorComponent.h"
#include "MenuHandlerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UMenuHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMenuHandlerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category="Menu")
	TSubclassOf<UMenu> MenuClass;

	UPROPERTY(BlueprintReadOnly, Category="Menu")
	UMenu* MenuObject;
	
	UFUNCTION(BlueprintCallable, Category="Menu")
	bool OpenMenu(FGameplayTagContainer Tags);

	
};
