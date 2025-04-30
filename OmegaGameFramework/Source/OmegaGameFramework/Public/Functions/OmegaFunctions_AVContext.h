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
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaFunctions_AVContext.generated.h"

class USkeletalMeshComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI) class UDataInterface_ContextAV : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextAV
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Level Sequence>")
	ULevelSequence* GetContextAVSequences(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Sound>")
	USoundBase* GetContextAVSounds(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Niagara>")
	UNiagaraSystem* GetContextAVNiagara(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Montage>")
	UAnimMontage* GetContextAVMontages(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Animation>")
	UAnimSequence* GetContextAVAnimations(FGameplayTag ID);
};



UINTERFACE(MinimalAPI) class UDataInterface_ContextActor : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextActor
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Actor Class>")
	TSubclassOf<AActor> GetContextAV_ActorClass(FGameplayTag ID);
};

UINTERFACE(MinimalAPI) class UDataInterface_ContextMesh : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextMesh
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Static Mesh>")
	UStaticMesh* GetContextAV_StaticMesh(FGameplayTag ID);
	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Skeletal Mesh>")
	USkeletalMesh* GetContextAV_SkeletalMesh(FGameplayTag ID);
};

UINTERFACE(MinimalAPI) class UDataInterface_ContextAnimation : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextAnimation
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category="Omega|AV", DisplayName="Ω Get Context AV <Animation Class>")
	TSubclassOf<UAnimInstance> GetContextAV_AnimClass(FGameplayTag ID);
};


UINTERFACE(MinimalAPI) class UDataInterface_ContextSlate : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextSlate
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega|Slate", DisplayName="Ω Get Context AV <Slate Brush>")
	FSlateBrush GetContextAV_SlateBrush(FGameplayTag ID);

};


UINTERFACE(MinimalAPI) class UDataInterface_ContextString : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ContextString
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega|String", DisplayName="Ω Get Context AV <Text>")
	FText GetContextAV_Text(FGameplayTag ID);

};

UCLASS()
class UOmegaContextAVFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Context|Animation",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <LevelSequence>")
	static ULevelSequence* TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID, ULevelSequence* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);
	UFUNCTION(BlueprintCallable, Category="Context|Animation",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Montage>")
	static UAnimMontage* TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID, UAnimMontage* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);
	UFUNCTION(BlueprintCallable, Category="Context|Animation",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Anim Sequence>")
	static UAnimSequence* TryGetObjectContext_AnimSequence(UObject* Object, FGameplayTag ID, UAnimSequence* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintCallable, Category="Context|Sound",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Sound>")
	static USoundBase* TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID, USoundBase* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintCallable, Category="Context|Particle",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Niagara>")
	static UNiagaraSystem* TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID, UNiagaraSystem* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintCallable, Category="Context|Actor",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Actor Class>")
	static TSubclassOf<AActor> TryGetObjectContext_ActorClass(UObject* Object, FGameplayTag ID, TSubclassOf<AActor> Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintCallable, Category="Context|Mesh",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Static Mesh>")
	static UStaticMesh* TryGetObjectContext_StaticMesh(UObject* Object, FGameplayTag ID, UStaticMesh* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintCallable, Category="Context|Mesh",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Skeletal Mesh>")
	static USkeletalMesh* TryGetObjectContext_SkelMesh(UObject* Object, FGameplayTag ID, USkeletalMesh* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Context|Mesh",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Anim Class>")
	static TSubclassOf<UAnimInstance> TryGetObjectContext_AnimClass(UObject* Object, FGameplayTag ID, TSubclassOf<UAnimInstance> Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Context|Slate",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <SlateBrush>")
	static FSlateBrush TryGetObjectContext_SlateBrush(UObject* Object, FGameplayTag ID, FSlateBrush Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	// =============================================================================
	// Text
	// =============================================================================
	UFUNCTION(BlueprintCallable, Category="Context|String",meta=(ExpandEnumAsExecs="Outcome"),DisplayName="Try Get Object Context <Text>")
	static FText TryGetObjectContext_Text(UObject* Object, FGameplayTag ID, FText Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome);

};

UCLASS()
class UOmegaContextAVSettersFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:


};