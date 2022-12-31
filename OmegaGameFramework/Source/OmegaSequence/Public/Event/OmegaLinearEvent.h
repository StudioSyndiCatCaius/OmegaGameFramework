// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.generated.h"

class UWorld;
class UOmegaLinearEventSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventEnded, const FString&, Flag);

UCLASS(BlueprintType, Blueprintable, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGASEQUENCE_API UOmegaLinearEvent : public UObject
{
	GENERATED_BODY()
public:
	UOmegaLinearEvent(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;

	UPROPERTY()
	UWorld* WorldPrivate = nullptr;
	UPROPERTY()
	UGameInstance* GameInstanceRef = nullptr;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	
	UPROPERTY()
	FOnEventEnded EventEnded;

	UPROPERTY(EditInstanceOnly, Category="LinearEvent", AdvancedDisplay)
	FName EventID;
	
	///FUNCTIONS
	///
	UFUNCTION()
	virtual void Native_Begin();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventBegin();
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventEnd(const FString& Flag);
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	void Finish(const FString& Flag);

	UFUNCTION(BlueprintNativeEvent, Category="LinearEvent")
	FString GetLogString() const;
	
};
