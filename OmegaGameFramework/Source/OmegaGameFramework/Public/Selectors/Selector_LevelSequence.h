// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "Misc/GeneralDataObject.h"
#include "Selector_LevelSequence.generated.h"


USTRUCT(BlueprintType)
struct FOmegaSelect_LevelSequence
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Selector")
	UOmegaSelector_LevelSequence* Selector=nullptr;
	
};


UCLASS(Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_LevelSequence : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Selector")
	ULevelSequence* GetLevelSequence(UObject* Context) const;
};


