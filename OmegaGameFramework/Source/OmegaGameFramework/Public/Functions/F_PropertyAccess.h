// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_PropertyAccess.generated.h"


UCLASS()
class UOmegaFunctions_PropertyAccess : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Omega|Property Access",DisplayName="Get UProperty (string)")
	static FString Get_String(UObject* Object, const FString& Property, const FString& Fallback="");
	UFUNCTION(BlueprintPure, Category="Omega|Property Access",DisplayName="Get UProperty (bool)")
	static bool Get_bool(UObject* Object, const FString& Property, bool Fallback=false);
	UFUNCTION(BlueprintPure, Category="Omega|Property Access",DisplayName="Get UProperty (double)")
	static double Get_Double(UObject* Object, const FString& Property, double Fallback=0.0);
	UFUNCTION(BlueprintPure, Category="Omega|Property Access",DisplayName="Get UProperty (int)")
	static int64 Get_Int64(UObject* Object, const FString& Property, int64 Fallback=0);
	
	UFUNCTION(BlueprintPure, Category="Omega|Property Access",DisplayName="Get UProperty (Object)",meta=(DeterminesOutputType="Class"))
	static UObject* Get_Object(UObject* Object,const FString& Property, TSubclassOf<UObject> Class,  UObject* Fallback = nullptr);
};


