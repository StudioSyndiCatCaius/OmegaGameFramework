// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Subsystems/Subsystem_World.h"
#include "F_Message.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Message : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message - Send",meta=(WorldContext="WorldContextObject"))
	static UOmegaGameplayMessage* Send(UObject* WorldContextObject, UObject* Instigator,FText Text,UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag,FOmegaGameplayMessageMeta meta);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message - Finish (Category)",meta=(WorldContext="WorldContextObject"))
	static bool Finish(UObject* WorldContextObject,UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message - Get Current",meta=(WorldContext="WorldContextObject"))
	static UOmegaGameplayMessage* GetCurrent(UObject* WorldContextObject,UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag);
};
