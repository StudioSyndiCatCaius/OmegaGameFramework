// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ActorStateComponent.generated.h"

class UOmegaSaveSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeginWithState, FGameplayTag, State);


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//UActorStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="State")
	FGameplayTag DefaultState;

	UPROPERTY(BlueprintAssignable)
	FOnBeginWithState OnBeginWithState;
	
	UFUNCTION(BlueprintCallable, Category="Actor State")
	void SetActorState(FGameplayTag State);

	UFUNCTION(BlueprintCallable, Category="Actor State")
	FGameplayTag GetActorState() const;

	UPROPERTY()
	UOmegaSaveSubsystem* SubsysRef;
};
