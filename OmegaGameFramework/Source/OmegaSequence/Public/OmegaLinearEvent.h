// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.generated.h"

class UWorld;
class UOmegaLinearEventSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventEnded);


UCLASS(BlueprintType, Blueprintable, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGASEQUENCE_API UOmegaLinearEvent : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY(Transient)
	UWorld* WorldPrivate = nullptr;
	
public:
	UOmegaLinearEvent(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UPROPERTY()
	UGameInstance* GameInstanceRef = nullptr;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	
	UPROPERTY()
	FOnEventEnded EventEnded;
	
	///FUNCTIONS

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventBegin();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventEnd();
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	void Finish();

	
	
};
