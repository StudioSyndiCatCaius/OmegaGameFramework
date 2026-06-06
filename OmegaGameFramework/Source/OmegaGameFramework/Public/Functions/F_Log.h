// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "F_Log.generated.h"



UCLASS()
class UOmegaFunctions_Log : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|Log",DisplayName="📟Print - WARNING")
	static void Warning(FText Text=INVTEXT("Maybe I goofed?"), float Duration=2.0);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Log",DisplayName="📟Print - ERROR")
	static void Error(FText Text=INVTEXT("I goofed..."), float Duration=2.0);
	
};
