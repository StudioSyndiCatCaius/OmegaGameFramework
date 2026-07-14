// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Common.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Misc/OmegaUtils_Volume.h"
#include "Actor_GameplayEffect.generated.h"

class AOmegaGameplayEffect;
class CombatantComponent;
class UOmegaDamageType;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEffectTriggered, AOmegaGameplayEffect*, Effect, float, DamageValue);

UENUM()
enum class EEffectLifetime : uint8
{
	// Effect is instantly triggered and destruct
	EffectLifetime_Instant        UMETA(DisplayName = "Instant"),
	//Effect will trigger and destruct after a certain amount of timer has passed.
	EffectLifetime_Timer        UMETA(DisplayName = "Timer"),
	// Effect remains until Trigger
	EffectLifetime_OnTrigger        UMETA(DisplayName = "OnTrigger"),
	// Effect remains until "Destroy Actor" is called.
	EffectLifetime_OnDestroy       UMETA(DisplayName = "OnDestroy"),

};

UCLASS(hideCategories = (Input, HLOD, WorldPartition, Physics, Collision, Volume, Replication, Rendering))
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayEffect : public AActor, public IDataInterface_General, public IDataInterface_Combatant
{
	GENERATED_BODY()
	
	FTimerHandle LifetimeTimer;
	
public:
	AOmegaGameplayEffect();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnEffectTriggered OnEffectTriggered;


	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
	void OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* InstigatorCombatant, UOmegaDamageType* DamageType, FHitResult Hit);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "Effect Triggered", Category = "Ω|Gameplay|Effects")
	void EffectApplied(float DamageValue);

	UFUNCTION(BlueprintCallable, Category = "Ω|Gameplay|Effects")
	void TriggerEffect();

	UFUNCTION(BlueprintNativeEvent, Category = "Ω|Gameplay|Effects")
	bool EffectCanApply(UCombatantComponent* EffectInstigator,UCombatantComponent* EffectTarget, UObject* Context, FOmegaCommonMeta Meta
		,FOmegaCommonMeta& OutMeta);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
	void EffectBeginPlay(UObject* Context, FOmegaCommonMeta Meta);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
	void Refresh();

	UFUNCTION(BlueprintNativeEvent, Category = "Ω|Gameplay|Effects")
	UOmegaDamageType* GetDamageType(UObject* Context);
	
	UPROPERTY(BlueprintReadOnly, Category = "General")
	UCombatantComponent* CombatantInstigator;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	UCombatantComponent* TargetedCombatant;
	
	UPROPERTY(BlueprintReadOnly, Category = "General", VisibleInstanceOnly)
	UObject* EffectContext;
	
	//-----Life-----//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime")
		EEffectLifetime EffectLifetime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime")
		float Lifetime = 1.0;
	
	UFUNCTION()
	void LifetimeEnd();
	
	//####################################//####################################//####################################
	//-----Generals
	//####################################//####################################//####################################
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	//####################################//####################################//####################################
	//-----Tags-----//
	//####################################//####################################//####################################
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags",meta=(Categories="EFFECT"))
	FGameplayTag EffectCategory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags",meta=(Categories="EFFECT"))
	FGameplayTagContainer EffectTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags",meta=(Categories="EFFECT"))
	FGameplayTagContainer RemoveEffectsOnApplied;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags",meta=(Categories="EFFECT"))
	FGameplayTagContainer BlockEffects;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags",meta=(Categories="EFFECT"))
	//FGameplayTagContainer RemoveEffectsOnTrigger;

	void Local_RemoveEffects(FGameplayTagContainer Effects);
	
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override;
	
	bool L_ContextUsesInterface() const;
	
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual UPrimaryDataAsset* GetDamageType_Weight_Implementation(UCombatantComponent* Combatant, UOmegaDamageType* DamageType, float& weight, int32& priority) override;
};



