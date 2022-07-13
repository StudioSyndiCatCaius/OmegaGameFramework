// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaLinearEvent.h"
#include "OmegaLinearEventSubsystem.generated.h"

class UOmegaLinearEventInstance;

USTRUCT(BlueprintType)
struct FLinearEventSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="LinearEvents", instanced, EditAnywhere)
	TArray<class UOmegaLinearEvent*> Events;

};

UCLASS()
class OMEGASEQUENCE_API UOmegaLinearEventSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;


public:
	UPROPERTY()
	UGameInstance* GameInstanceReference;
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	UOmegaLinearEventInstance* PlayLinearEvent(FLinearEventSequence Sequence);
	
	UPROPERTY()
	TArray<UOmegaLinearEventInstance*> TempEvents;
};
