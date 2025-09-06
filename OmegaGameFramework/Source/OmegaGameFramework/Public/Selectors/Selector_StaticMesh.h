// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "Selector_StaticMesh.generated.h"

USTRUCT(BlueprintType)
struct FOmegaSelect_StaticMesh
{
	GENERATED_BODY()


};


UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_StaticMesh : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Selector")
	UStaticMesh* GetStaticMesh() const;
	UFUNCTION(BlueprintImplementableEvent,Category="Selector")
	TArray<UMaterialInterface*> GetOverrideMaterials() const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSelectorFunctions_StaticMesh : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	

};


