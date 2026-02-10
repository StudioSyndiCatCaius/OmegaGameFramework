// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_ActorState.generated.h"

class UOmegaSaveSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeginWithState, FGameplayTag, State);


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:

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
