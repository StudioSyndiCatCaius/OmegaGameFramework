// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_BGM.generated.h"


class UOmegaBGM;

UCLASS()
class UOmegaFunctions_BGM : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|BGM",meta=(WorldContext="WorldContextObject"),DisplayName="🎵BGM - Play")
    static void Play(UObject* WorldContextObject, UOmegaBGM* BGM,UPARAM(meta=(Categories="BGM")) FGameplayTag Slot, bool bFadePrevious);
	
	UFUNCTION(BlueprintCallable,Category="Omega|BGM",meta=(WorldContext="WorldContextObject"),DisplayName="🎵BGM - Set Pause")
	static void Pause(UObject* WorldContextObject, bool bPaused);

	UFUNCTION(BlueprintCallable,Category="Omega|BGM",meta=(WorldContext="WorldContextObject"),DisplayName="🎵BGM - Set Locked")
	static void Lock(UObject* WorldContextObject, bool bLocked);
	
	UFUNCTION(BlueprintCallable,Category="Omega|BGM",meta=(WorldContext="WorldContextObject"),DisplayName="🎵BGM - Stop")
	static void Stop(UObject* WorldContextObject, bool bFade, float FadeTime=0.5);
};

