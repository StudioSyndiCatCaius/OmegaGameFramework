// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Sound/SoundBase.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimMontage.h"
#include "LevelSequence.h"
#include "OmegaFunctions_AVContext.generated.h"

class USkeletalMeshComponent;

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
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	TMap<FGameplayTag, UAnimMontage*> GetContextAVMontages();
};


UCLASS()
class UOmegaContextAVFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category="AV")
	static ULevelSequence* TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID);
	UFUNCTION(BlueprintPure, Category="AV")
	static USoundBase* TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID);
	UFUNCTION(BlueprintPure, Category="AV")
	static UNiagaraSystem* TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID);
	UFUNCTION(BlueprintPure, Category="AV")
	static UAnimMontage* TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID);

	
};