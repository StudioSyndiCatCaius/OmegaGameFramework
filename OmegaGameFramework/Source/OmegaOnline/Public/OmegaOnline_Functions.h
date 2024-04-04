// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "UObject/Object.h"
#include "FindSessionsCallbackProxy.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaOnline_Functions.generated.h"

UCLASS(BlueprintType)
class OMEGAONLINE_API UOmegaSessionDataObject : public UObject, public IDataInterface_General
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly,Category="Session")
	FBlueprintSessionResult ResultData;
};

UCLASS()
class OMEGAONLINE_API UOmegaOnlineFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Online",meta=(WorldContext="WorldContextObject"))
	static UOmegaSessionDataObject* CreateSessionObject(UObject* WorldContextObject, FBlueprintSessionResult Result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Online",meta=(WorldContext="WorldContextObject"))
	static TArray<UOmegaSessionDataObject*> CreateSessionObjects(UObject* WorldContextObject, TArray<FBlueprintSessionResult> Results);
};



