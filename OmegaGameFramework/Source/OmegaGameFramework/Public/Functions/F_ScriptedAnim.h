// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Interfaces/I_Common.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "F_ScriptedAnim.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScriptedAnimDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScriptedAnimDelegate_Notify,FName,notify);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScriptedAnimDelegate_Script,UOmegaScriptedAnimation*,Script);


UCLASS(EditInlineNew, Blueprintable, BlueprintType, CollapseCategories, Abstract,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedAnimation : public UObject
{
	GENERATED_BODY()

	UPROPERTY() AActor* REF_Instigator=nullptr;
	
public:
	
	void Native_Begin(AActor* instigator=nullptr);
	
	UPROPERTY(BlueprintAssignable) FOnScriptedAnimDelegate_Script OnAnimBegin;
	UPROPERTY(BlueprintAssignable) FOnScriptedAnimDelegate_Script OnAnimEnd;
	UPROPERTY(BlueprintAssignable) FOnScriptedAnimDelegate_Notify OnAnimNotify;
	
	UFUNCTION(BlueprintPure, Category="Omega|ScriptedAnim") AActor* GetAnimationInstigator() const;
	UFUNCTION(BlueprintCallable,Category="Omega|ScriptedAnim") void Notify(FName notify);
	UFUNCTION(BlueprintCallable,Category="Omega|ScriptedAnim") void FinishAnimation();
	
	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect") void OnBegin();
	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect") void OnEnd();
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedAnimation_Preset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Effect",DisplayName="Anim (Inline)")
	TArray<UOmegaScriptedAnimation*> Animations;
};

USTRUCT(BlueprintType)
struct FOmegaScriptedAnimationData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect",DisplayName="Anim (Presets)")
	TArray<UOmegaScriptedAnimation_Preset*> anim_preset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Effect",DisplayName="Anim (Inline)")
	TArray<UOmegaScriptedAnimation*> anim_inline;
	
	TArray<UOmegaScriptedAnimation*> GetAllAnimations() const;
};


UINTERFACE() class UDataInterface_ScriptedAnimation : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ScriptedAnimation
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Animation") FOmegaScriptedAnimationData GetScriptedAnimation(FName name);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_ScriptedAnimation : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UAsyncAction_ScriptedAnimation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	int32 anim_index=-1;
	
	UPROPERTY(BlueprintAssignable) FOnScriptedAnimDelegate Finished;
	UPROPERTY(BlueprintAssignable) FOnScriptedAnimDelegate_Notify OnNotify;

	UPROPERTY() AActor* local_Instigator=nullptr;
	UPROPERTY() FOmegaScriptedAnimationData local_animData;
	UPROPERTY() UOmegaScriptedAnimation* current_anim=nullptr;
	
	UFUNCTION() void L_Notify(FName Notify);
	UFUNCTION() void Next_Anim(UOmegaScriptedAnimation* anim);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|AsyncGameplayTasks", meta = (WorldContext = "WorldContextObject",
		AdvancedDisplay=""),DisplayName="Ω🔷 Play Scripted Animation") 
	static UAsyncAction_ScriptedAnimation* PlayScriptedAnimation(UObject* WorldContextObject, AActor* Instigator, FOmegaScriptedAnimationData AnimationData);

	
};
