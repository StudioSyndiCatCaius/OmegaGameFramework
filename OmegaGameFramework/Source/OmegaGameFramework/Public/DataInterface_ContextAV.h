// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameplayEffect.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataInterface_ContextAV.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_ContextAV : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextAV
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	TMap<FGameplayTag, ULevelSequence*> GetContextAVSequences();
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	TMap<FGameplayTag, USoundBase*> GetContextAVSounds();
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	TMap<FGameplayTag, UNiagaraSystem*> GetContextAVNiagara();
	
};


UCLASS()
class UOmegaContextAVFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category="AV")
	static ULevelSequence* TryGetObjectContext_Seqeunce(UObject* Object, FGameplayTag ID);
	UFUNCTION(BlueprintPure, Category="AV")
	static USoundBase* TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID);
	UFUNCTION(BlueprintPure, Category="AV")
	static UNiagaraSystem* TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID);
};
