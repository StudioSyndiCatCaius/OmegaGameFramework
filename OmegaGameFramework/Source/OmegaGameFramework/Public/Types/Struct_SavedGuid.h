
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Struct_SavedGuid.generated.h"

class UPrimaryDataAsset;

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSavedGuidData
{
	GENERATED_BODY()
	
	TMap<FGuid,int32> guid_params;
	TMap<FGuid,FGuid> guid_links;
	
};
