// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OmegaInterface_Seed.generated.h"


// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_Seed : public UInterface
{
	GENERATED_BODY()

public:

	static int32 getSeed(UObject* obj,FName name);
};



class OMEGAGAMEFRAMEWORK_API IDataInterface_Seed
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="IntState")
	int32 GetSeed(FName Name);
};

inline int32 UDataInterface_Seed::getSeed(UObject* obj,FName name)
{
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_Seed::StaticClass()))
	{
		return IDataInterface_Seed::Execute_GetSeed(obj,name);
	}
	return 0;
}