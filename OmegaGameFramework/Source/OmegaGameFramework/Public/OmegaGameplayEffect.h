// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "GameplayTagContainer.h"
#include "VolumeUtils.h"
#include "DamageFormula.h"
#include "Gameplay/CombatantComponent.h"
#include "Gameplay/Combatant/OmegaEffectPopup.h"
#include "OmegaGameplayEffect.generated.h"

class AOmegaGameplayEffect;


USTRUCT(BlueprintType)
struct FOmegaEffectContainer
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	TSubclassOf<AOmegaGameplayEffect> EffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	float Power = 1.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	FGameplayTagContainer AddedTags;
};

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

UENUM()
enum class EOmegaEffectType : uint8
{
	OET_Damage        UMETA(DisplayName = "Damage"),
	OET_Heal        UMETA(DisplayName = "Heal"),
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayEffect : public AActor, public IGameplayTagsInterface
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	AOmegaGameplayEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TArray<FName> ActorsTagsGranted;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "Effect Triggered", Category = "Ω|Gameplay|Effects")
		void EffectApplied(float DamageValue);

	UFUNCTION(BlueprintCallable, Category = "Ω|Gameplay|Effects")
		void TriggerEffect();

	UPROPERTY(BlueprintAssignable)
	FOnEffectTriggered OnEffectTriggered;

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
		FHitResult GetImpactHitResult();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
	void EffectBeginPlay(UObject* Context);

	UFUNCTION(BlueprintNativeEvent, Category = "Ω|Gameplay|Effects")
	UOmegaDamageType* GetDamageType(UObject* Context);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
	void LifetimeUpdated(float TimeElapsed, float TimeRemaining);

	UPROPERTY(BlueprintReadOnly, Category = "General")
	UCombatantComponent* CombatantInstigator;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	UCombatantComponent* TargetedCombatant;

	UPROPERTY(BlueprintReadOnly, Category = "General", VisibleInstanceOnly)
	UObject* EffectContext;
	
	//-----VOLUME-----//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Volume")
		bool bUseVolume = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Volume")
	EVolumeShape VolumeShape;

	//-----Life-----//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime")
		EEffectLifetime EffectLifetime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime")
		float Lifetime = 1.0;
	
	
	UFUNCTION()
	void LifetimeEnd();

	//-----Damage-----//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")
	UOmegaAttribute* EffectedAttribute;
	
	UPROPERTY(EditAnywhere, Category="Damage")
	EOmegaEffectType AttrbuteEffectType;

	//DEPRICATED. TO BE RE<MOVED IN FUTURE
	UPROPERTY()
	TSubclassOf<UDamageFormula> DamageFormula = UDamageFormula::StaticClass();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, instanced, Category = "Damage", DisplayName="Damage Formula")
	class UDamageFormula* LocalFormula;
	
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Damage")
		float Power;

	UFUNCTION(BlueprintPure, Category = "Ω|Gameplay|Effects")
	float CalculateDamageValue();

	
	//####################################//####################################//####################################
	//-----Tags-----//
	//####################################//####################################//####################################
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTag EffectCategory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer EffectTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer RemoveEffectsOnApplied;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer RemoveEffectsOnTrigger;

	void Local_RemoveEffects(FGameplayTagContainer Effects)
	{
		if(TargetedCombatant)
		{
			for(auto* TempEffect: TargetedCombatant->GetEffectsWithTags(Effects))
			{
				if(TempEffect != this)
				{
					TempEffect->Destroy();
				}
			};
		}
	}
	
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTag GetObjectGameplayCategory();
	virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();

	//###############################################################################################################
	// POPUP
	//###############################################################################################################
	UPROPERTY(EditDefaultsOnly, Category="Popup")
	bool bShowPopupOnTrigger;
	UPROPERTY(EditDefaultsOnly, Category="Popup")
	TSubclassOf<UOmegaEffectPopup> PopupClass;
	UPROPERTY(EditDefaultsOnly, Category="Popup")
	bool UseCustomPopupText;
	
	
	UFUNCTION(BlueprintImplementableEvent, Category="Popup")
	FText GetTriggeredPopupText();
	UFUNCTION(BlueprintNativeEvent, Category="Popup")
	FSlateColor GetTriggeredPopupColor();

	
	//Misc
	FTimerHandle LifetimeTimer;

	float PastLifetime;
	float RemainingLifetime;

	TSubclassOf<UOmegaEffectPopup> Local_GetPopupClass()
	{
		if(PopupClass)
		{
			return PopupClass;
		}
		else
		{
			return UOmegaEffectPopup::StaticClass();
		}
	}
};
