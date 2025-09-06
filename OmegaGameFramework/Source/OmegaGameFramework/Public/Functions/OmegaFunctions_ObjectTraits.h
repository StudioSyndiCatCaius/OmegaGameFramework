// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_ObjectTraits.generated.h"



UCLASS()
class UOmegaObjectTraitsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Traits",meta=(ExpandBoolAsExecs="result", DeterminesOutputType="Class"),DisplayName="Traits - Try Get (Of Class)")
	static UOmegaObjectTrait* TryGetObjectTrait(UObject* Object, TSubclassOf<UOmegaObjectTrait> Class,FName TraitName,bool FallbackToDefault,bool& result);

	UFUNCTION(BlueprintCallable,Category="Omega|Traits",DisplayName="Traits - Get All")
	static TArray<UOmegaObjectTrait*> GetObjectTraits(UObject* Object);
};

