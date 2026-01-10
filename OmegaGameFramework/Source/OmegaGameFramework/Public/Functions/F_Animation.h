// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "F_Animation.generated.h"

class UAnimMontage;
class ULevelSequence;

UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaAnimationEmoteScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Emote")
	UAnimMontage* GetEmoteMontage(ACharacter* Character) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAnimationEmote : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Animation")
	UOmegaAnimationEmoteScript* Script;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAnimationFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Animation",meta=(ExpandBoolAsExecs="Result"))
	static UAnimInstance* TryGetAnimInstanceFromObject(UObject* Object, TSubclassOf<UAnimInstance> AnimClass, bool& Result);

	UFUNCTION(BlueprintCallable,Category="Omega|Animation")
	static void PlayMontage_ByTag(USkeletalMeshComponent* Mesh, FGameplayTag MontageTag);

	UFUNCTION(BlueprintCallable,Category="Omega|Animation",meta=(AdvancedDisplay="blend_settings"))
	static void StopMontage_ByTag(USkeletalMeshComponent* Mesh, FGameplayTag MontageTag,FMontageBlendSettings blend_settings);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Animation")
	static void PlayEmoteAnimation(ACharacter* Character, UOmegaAnimationEmote* Emote);
		
	UFUNCTION(BlueprintCallable,Category="Omega|Animation")
	static void StopEmoteAnimation(ACharacter* Character, UOmegaAnimationEmote* Emote);

	UFUNCTION(BlueprintCallable,Category="Omega|Animation",DisplayName="Stop All Montages On Character")
	static void StopAllMontages_Character(ACharacter* character,float blendOutTime);
};
