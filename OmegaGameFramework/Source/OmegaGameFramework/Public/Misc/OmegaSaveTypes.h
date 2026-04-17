// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaSaveTypes.generated.h"

class UOmegaSaveCondition;
class UOmegaSaveConditionCollection;

// ====================================================================================================
// Save Conditions Struct - lightweight header to avoid pulling in the full Save Subsystem
// ====================================================================================================

USTRUCT(BlueprintType)
struct FOmegaSaveConditions
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="OmegaSaveConditions")
	TEnumAsByte<EBoolType> CheckType=BoolType_And;

	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", instanced, EditAnywhere)
	TArray<class UOmegaSaveCondition*> Conditions;

	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", EditAnywhere)
	TArray<class UOmegaSaveConditionCollection*> ConditionCollections;
};
