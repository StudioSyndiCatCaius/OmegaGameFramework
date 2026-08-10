
#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Struct_ByteContainer.generated.h"



USTRUCT(BlueprintType)
struct FOmegaByteBuffer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ByteContainer") TArray<uint8> Bytes;
};