
#pragma once

#include "CoreMinimal.h"
#include "Struct_CustomNamedList.generated.h"


USTRUCT(BlueprintType)
struct FOmegaCustomNamedList
{
	GENERATED_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	FName ListID;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	FName Option;
};

USTRUCT(BlueprintType)
struct FOmegaClassNamedLists
{
	GENERATED_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	TMap<FName, FOmegaCustomNamedList> CustomNamedList;
    

};