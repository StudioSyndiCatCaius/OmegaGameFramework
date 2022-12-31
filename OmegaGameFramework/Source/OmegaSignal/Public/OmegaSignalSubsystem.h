// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaSignalAsset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaSignalSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFireSignal, UOmegaSignalAsset*, Signal);

UCLASS()
class OMEGASIGNAL_API UOmegaSignalSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:

	UPROPERTY()
	TArray<UOmegaSignalAsset*> RegisteredSignals;

public:
	//Fires a Global Signal to all listening assets
	UFUNCTION(BlueprintCallable, Category="Omega|Signals", meta=(BlueprintInternalUseOnly="true"))
	void FireGlobalSignal(UOmegaSignalAsset* Signal);

	UPROPERTY()
	FOnFireSignal OnFireSignal;
};
