// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Blueprint/UserWidget.h"
#include "Misc/OmegaDamageType.h"
#include "Misc/OmegaUtils_Volume.h"
#include "OmegaGameplayEffect.generated.h"

class AOmegaGameplayEffect;
class CombatantComponent;

// ==============================================================================
// Formula
// ==============================================================================

UCLASS(BlueprintType, Blueprintable, editinlinenew)
class OMEGAGAMEFRAMEWORK_API UDamageFormula : public UObject
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintNativeEvent, Category="Damage")
	void GetDamageAmount(UCombatantComponent* Instigator, UCombatantComponent* Target, float& DamageOut);
	
};

// ==============================================================================
// Popup Widget
// ==============================================================================

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaEffectPopup : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY()
	AOmegaGameplayEffect* OwningEffect;

	UPROPERTY()
	FSlateColor Incoming_Color;
	UPROPERTY()
	FText Incoming_Text;
	
	UFUNCTION(BlueprintImplementableEvent)
	UTextBlock* GetDamageText();

	UFUNCTION(BlueprintNativeEvent)
	float GetPopupLifetime();

	//############################################################################################
	//  Location
	//############################################################################################
	UPROPERTY()
	FVector2D InitPosition;
	UPROPERTY()
	FVector2D CurrentPosition;
	
	UFUNCTION(BlueprintImplementableEvent)
	FVector2D GetTargetViewportPosition();
	
	UPROPERTY()
	FTimerHandle LifetimeTimer;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage Popup")
	TEnumAsByte<ERoundingMode> DamageDisplayRounding;
};

// ==============================================================================
// Effect
// ==============================================================================

UENUM()
enum class ECombatantEffectTargets : uint8
{
	// Effect is instantly triggered and destruct
	EffectTargets_Self				UMETA(DisplayName = "Self"),
	//Effect will trigger and destruct after a certain amount of timer has passed.
	EffectTargets_ActiveTarget      UMETA(DisplayName = "Active Target"),
	// Effect remains until Trigger
	EffectTargets_AllTargets		UMETA(DisplayName = "Registered Targets"),

};

UENUM()
enum class EOmegaEffectReplacement : uint8
{
	// You can pply as many of this kind of effects to the combatant
	Effect_Addition				UMETA(DisplayName = "Addition"),
	// If another effect of this type is attempted to be applied, it will replace this effect
	Effect_Replace      UMETA(DisplayName = "Replace"),
	// If another effect of this type is attempted to be applied, it will be ignored.
	Effect_Singleton		UMETA(DisplayName = "Singleton"),

};

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

UCLASS(hideCategories = (Input, HLOD, WorldPartition, Physics, Collision, Volume, Replication, Rendering, Actor, ActorTick))
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayEffect : public AActor, public IGameplayTagsInterface, public IDataInterface_General
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

	//This is the default chance this effect has of being successfully applied. 1 = Always successful
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	float DefaultSuccessRate = 1.0;
	
	//These tags will be granted to the owning combatant's actor and removed when the effect is
	UPROPERTY(EditDefaultsOnly, Category="Effect")
	TArray<FName> ActorsTagsGranted;
	
	//Should only one of this effect be allowed at a time?
	EOmegaEffectReplacement SingletonStatus;
	
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
	
	//Applys Additional Attribute Damage with the same parameters as the formula damage.
	UFUNCTION(BlueprintCallable, Category="Effect")
	void ApplyAdditionalDamage(UOmegaAttribute* Attribute, float Amount);

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
	//-----Generals
	//####################################//####################################//####################################
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;\
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
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

	void Local_RemoveEffects(FGameplayTagContainer Effects);
	
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



