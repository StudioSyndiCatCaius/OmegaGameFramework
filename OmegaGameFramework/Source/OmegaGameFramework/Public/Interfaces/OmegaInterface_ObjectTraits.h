// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OmegaInterface_ObjectTraits.generated.h"


UCLASS(Blueprintable,BlueprintType,Abstract,Const,EditInlineNew,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaObjectTrait : public UObject
{
	GENERATED_BODY()

public:
	
};

UINTERFACE(MinimalAPI) class UDataInterface_Traits : public UInterface
{
	GENERATED_BODY()
public:
	static TArray<UOmegaObjectTrait*> GetObjectTraits(UObject* Object);
};


class OMEGAGAMEFRAMEWORK_API IDataInterface_Traits
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Traits")
	TArray<UOmegaObjectTrait*> GetTraits();
};

inline TArray<UOmegaObjectTrait*> UDataInterface_Traits::GetObjectTraits(UObject* Object)
{
	if(Object && Object->GetClass()->ImplementsInterface(StaticClass()))
	{
		return IDataInterface_Traits::Execute_GetTraits(Object);
	}
	TArray<UOmegaObjectTrait*> nil;
	return nil;
}