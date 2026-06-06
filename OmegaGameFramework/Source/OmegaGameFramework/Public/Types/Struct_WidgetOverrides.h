
#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Struct_WidgetOverrides.generated.h"

class UOmegaSlateStyle_Text;
class UOmegaTextBlock;
class UOmegaBorder;
class UOmegaSlateStyle_Border;

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaWidgetOverride_Bindings
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, bool> params_bool;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, int32> params_int;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, float> params_float;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, UOmegaBorder*> styles_border;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, UOmegaTextBlock*> styles_Text;
};	


