
#pragma once

#include "CoreMinimal.h"
#include "Struct_CustomNamedList.generated.h"


USTRUCT(BlueprintType)
struct FOmegaCustomNamedList
{
	GENERATED_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ListID;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Option;
};

USTRUCT(BlueprintType)
struct FOmegaClassNamedLists
{
	GENERATED_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, FOmegaCustomNamedList> CustomNamedList;
    

};