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
	ULevelSequence* GetContextAVSequences(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	USoundBase* GetContextAVSounds(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	UNiagaraSystem* GetContextAVNiagara(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	UAnimMontage* GetContextAVMontages(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="AV")
	UAnimSequence* GetContextAVAnimations(FGameplayTag ID);
};


UCLASS()
class UOmegaContextAVFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category="AV")
	static ULevelSequence* TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID, ULevelSequence* Fallback=nullptr);
	UFUNCTION(BlueprintPure, Category="AV")
	static USoundBase* TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID, USoundBase* Fallback=nullptr);
	UFUNCTION(BlueprintPure, Category="AV")
	static UNiagaraSystem* TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID, UNiagaraSystem* Fallback=nullptr);
	UFUNCTION(BlueprintPure, Category="AV")
	static UAnimMontage* TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID, UAnimMontage* Fallback=nullptr);
	UFUNCTION(BlueprintPure, Category="AV")
	static UAnimSequence* TryGetObjectContext_AnimSequence(UObject* Object, FGameplayTag ID, UAnimSequence* Fallback=nullptr);

	
};