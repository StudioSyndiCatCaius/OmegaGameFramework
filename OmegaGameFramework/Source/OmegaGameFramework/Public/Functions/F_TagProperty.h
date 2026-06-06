// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_TagProperty.generated.h"

UINTERFACE(MinimalAPI)
class UDataInterface_TagProperty : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IDataInterface_TagProperty
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|TagProperties", DisplayName="Tag Param - (1) Get Map")
	TMap<FGameplayTag, FString> GetTagPropertyMap();
	
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|TagProperties", DisplayName="Tag Param - (2) Get Property")
	FString GetTagProperty(FGameplayTag Property, bool& ValidProperty);
	
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|TagProperties", DisplayName="Tag Param - (1) Get Object Map")
	TMap<FGameplayTag, UObject*>  GetTagPropertyMap_Object(FGameplayTag Property);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|TagProperties", DisplayName="Tag Param - (2) Get Object Property")
	UObject* GetTagProperty_Object(FGameplayTag Property);
};


UCLASS()
class UOmegaFunctions_TagProperty : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	static bool ObjectUsesInterface(UObject* Object); 
public:
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties",DisplayName="Tag Param (string)")
	static FString Get_String(UObject* Object, UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName, const FString& Fallback="");
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties", DisplayName="Tag Param (bool)")
	static bool Get_Bool(UObject* Object,UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName, bool Fallback = false);
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties", DisplayName="Tag Param (float)")
	static float Get_Float(UObject* Object,UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName,float Fallback=0.0f);
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties", DisplayName="Tag Param (int32)")
	static int32 Get_Int32(UObject* Object,UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName,int32 Fallback=0);
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties", DisplayName="Tag Param (vector)")
	static FVector Get_Vector(UObject* Object,UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName, FVector Fallback);
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties", DisplayName="Tag Param (rotator)")
	static FRotator Get_Rotator(UObject* Object,UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName, FRotator Fallback);
	
	UFUNCTION(BlueprintPure, Category="Omega|TagProperties",DisplayName="Tag Param (Object)",meta=(DeterminesOutputType="Class"))
	static UObject* Get_Object(UObject* Object,UPARAM(meta=(Categories="PARAM")) FGameplayTag PropertyName, TSubclassOf<UObject> Class,  UObject* Fallback = nullptr);
};


