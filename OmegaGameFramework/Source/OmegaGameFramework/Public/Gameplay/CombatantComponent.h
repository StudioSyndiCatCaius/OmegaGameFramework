// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeModifierContainer.h"

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"

#include "Gameplay/CombatInputUtility.h"

#include "Components/ActorComponent.h"
#include "CombatantComponent.generated.h"

class APawn;
class ACharacter;
class APlayerController;

class UOmegaAttribute;
class UOmegaAttributeSet;
class AOmegaAbility;
class AOmegaGameplayEffect;
class UOmegaGameplaySubsystem;

class UInputComponent;
class UEnhancedInputComponent;
class UInputAction;

UENUM(Blueprintable, BlueprintType)
enum EFactionAffinity
{
	NeutralAffinity			UMETA(DisplayName = "Neutral"),
	FriendlyAffinity		UMETA(DisplayName = "Friendly"),
	HostileAffinity			UMETA(DisplayName = "Hostile"),
};

/// DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UObject*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantLevelChange, int32, NewLevel);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetAdded, UCombatantComponent*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetRemoved, UCombatantComponent*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddedAsTarget, UCombatantComponent*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemovedAsTarget, UCombatantComponent*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveTargetChanged, UCombatantComponent*, ActiveTarget, bool, Valid);


#define PrintError(ErrorText) \
	(GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, ErrorText))

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OMEGAGAMEFRAMEWORK_API UCombatantComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatantComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//////////////////////////////////////////////////////////////////////////////////////////
	//////////______________________________PROPERTIES______________________________//////////
	//////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////
	////////// -- General -- //////////
	///////////////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "General")
	class UPrimaryDataAsset* CombatantDataAsset;

	UPROPERTY(EditAnywhere, Category = "General", meta = (DisplayName = "Name"))
	FText DisplayName;

	UPROPERTY()
	class UEnhancedInputComponent* OwnerInputComp;

	UPROPERTY()
		class APawn* OwnerPawn;

	////////////////////////////////////
	////////// -- Abilities -- //////////
	///////////////////////////////////

	UPROPERTY()
	TArray<class AOmegaAbility*> ActiveAbilities;

	void SetAbilityActive(bool bActive, AOmegaAbility* Ability);
	
	////////////////////////////////////
	////////// -- Attributes -- //////////
	///////////////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	class UOmegaAttributeSet* AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	TMap<class UOmegaAttribute*, int32> AttributeLevels;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	FGameplayTag AttributeValueCategory;

	UFUNCTION(BlueprintPure, Category="Modifiers")
	int32 GetAttributeLevel(UOmegaAttribute* Attribute);

	UPROPERTY()
	TMap<class UOmegaAttribute*, float> CurrentAttributeValues;

	float GatherAttributeModifiers(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute);

	////////////////////////////////////
	////////// -- Faction -- //////////
	///////////////////////////////////

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Faction")
	class UPrimaryDataAsset* FactionDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	FGameplayTag FactionTag;

	UFUNCTION(BlueprintPure, Category="Faction")
	FGameplayTag GetFactionTag();

	UPROPERTY(EditAnywhere, Category = "Faction")
	TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> FactionAffinities;

	UFUNCTION(BlueprintPure, Category="Faction")
	EFactionAffinity GetAffinityToCombatant(UCombatantComponent* CheckedCombatant);

	UFUNCTION(BlueprintPure, Category="Faction")
	TArray<UCombatantComponent*> FilterCombatantsByAffinity(TArray<UCombatantComponent*> Combatants, EFactionAffinity Affinity, bool bExclude);
	
	////////////////////////////////////
	////////// -- Skills -- //////////
	///////////////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<UPrimaryDataAsset*> Skills;

	UFUNCTION(BlueprintCallable, Category="Skills")
	void AddSkill(UPrimaryDataAsset* Skill);

	UFUNCTION(BlueprintCallable, Category="Skills")
	void RemoveSkill(UPrimaryDataAsset* Skill);
	
	////////////////////////////////////
	////////// -- Tags -- //////////
	///////////////////////////////////
		
	UPROPERTY(EditAnywhere, Category = "GameplayTags")
	FGameplayTag CategoryTags;

	UPROPERTY(EditAnywhere, Category = "GameplayTags")	
	FGameplayTagContainer CombatantTags;
	
	UFUNCTION(BlueprintCallable, Category = "Combatant|Tags")
    void AddTagsToCombatant(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category = "Combatant|Tags")
	void RemoveTagsFromCombatant(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Combatant|Tags")
	FGameplayTagContainer GetCombatantTags();

	UFUNCTION(BlueprintPure, Category = "Combatant|Tags")
	bool CombatantHasTag(FGameplayTag Tag);

	UFUNCTION(BlueprintPure, Category = "Combatant|Tags,", meta=(AdvancedDisplay = "Exact"))
	bool CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact=true);

	UFUNCTION(BlueprintPure, Category = "Combatant|Tags", meta=(AdvancedDisplay = "Exact"))
	bool CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact=true);

	//////////////////////////////////////////////////////////////////////////////////////////
	//////////______________________________FUNCTIONS______________________________//////////
	////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////
	////////// -- General -- ////////
	///////////////////////////////////
	
	UFUNCTION(BlueprintCallable, Category = "Combatant")
	void Update();

	//Tries to get the owning actor as a Pawn.
	UFUNCTION(BlueprintPure, Category="Combatant")
	APawn* GetOwnerPawn();

	//Tries to get the owning actor as a Character.
	UFUNCTION(BlueprintPure, Category="Combatant")
	ACharacter* GetOwnerCharacter();

	//Tries to get the owning actor OR the owning actor's controller.
	UFUNCTION(BlueprintPure, Category="Combatant")
	AController* GetOwnerController();

	//Tries to get the owning actor OR the owning actor's controller as a player controller.
	UFUNCTION(BlueprintPure, Category="Combatant")
	APlayerController* GetOwnerPlayerController();

	////////////////////////////////////
	////////// -- Ability -- ////////
	///////////////////////////////////

	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<AOmegaAbility>>GrantedAbilities;

	UPROPERTY()
	TArray<AOmegaAbility*>AbilityList;

				///////Ability Possession
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	bool GrantAbility(TSubclassOf<AOmegaAbility> AbilityClass);

	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	bool UngrantAbility(TSubclassOf<AOmegaAbility> AbilityClass);

	UFUNCTION(BlueprintPure, Category = "Ω|Ability", meta=(DeterminesOutputType="AbilityClass"))
	AOmegaAbility* GetAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool& bSuccess);

				///////Ability Activation
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability", meta = (AdvancedDisplay = "Context", DisplayName="Activate Ability"))
	AOmegaAbility* ExecuteAbility(class TSubclassOf<AOmegaAbility> AbilityClass, class UObject* Context, bool& bSuccess);

	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	bool StopAbility(class TSubclassOf<AOmegaAbility> AbilityClass, bool Cancel);

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
	bool IsAbilityActive(class TSubclassOf<AOmegaAbility> AbilityClass, class AOmegaAbility*& Ability);

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
	TArray<AOmegaAbility*> GetActiveAbilities();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
	TArray<AOmegaAbility*> GetActiveAbilitiesWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
		TArray<AOmegaAbility*> GetGrantedAbilities();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
	TArray<AOmegaAbility*> GetGrantedAbilitiesWithTags(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CancelAbilitiesWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
	bool IsAbilityTagBlocked(FGameplayTagContainer Tags);

	////////////////////////////////////
	////////// -- Attributes -- ////////
	//////////////////////////////////

	//Initializes the Combatants from an asset implementing "DataInterface_Combatant"
	UFUNCTION(BlueprintCallable, Category="Combatant")
	void InitializeFromAsset(UObject* Asset);

	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (AdvancedDisplay = "Instigator"))
	float ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UObject* Instigator, UObject* Context);
	
	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetAttributeValue(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	float GetAttributeBaseValue(UOmegaAttribute* Attribute);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	float GetAttributePercentage(class UOmegaAttribute* Attribute);
	
	UFUNCTION(BlueprintPure, Category = "Attributes")
	TMap<UOmegaAttribute*, float> GetCurrentAttributeValues();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetCombatantLevel(int32 NewLevel, bool ReinitializeStats);

	void InitializeAttributes();

	/////////
	/// Damage Mods
	/// //////

	UPROPERTY()
	TArray<UObject*> DamageModifiers;

	UFUNCTION(BlueprintCallable, Category="Combatant|DamageModifiers")
	bool SetDamageModifierActive(UObject* Modifier, bool bActive);

	UFUNCTION(BlueprintPure, Category="Combatant|DamageModifiers")
	TArray<UObject*> GetDamageModifiers();
	
	///Attribute Modifiers
	UPROPERTY()
	TArray<UObject*> AttributeModifiers;
	
	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers", meta = (AdvancedDisplay = "Category, Tags"))
	UAttributeModifierContainer* CreateAttributeModifier(UOmegaAttribute* Attribute, float Increment, float Multiplier, FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	bool AddAttrbuteModifier(UObject* Modifier);
	
	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	bool RemoveAttributeModifier(UObject* Modifier);

	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	void RemoveAttributeModifersWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category= "Attributes|Modifiers")
	float GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers);

	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	const TArray<UObject*> GetAttributeModifiers();

	
	////////////////////////////////////
	////////// -- Effects -- ////////
	///////////////////////////////////

	UPROPERTY()
	TArray<class AOmegaGameplayEffect*> ActiveEffects;

	UFUNCTION(BlueprintCallable, Category = "Effects", meta=(AdvancedDisplay="AddedTags, Location"))
	class AOmegaGameplayEffect* CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, float Power, FTransform Location, UCombatantComponent* Target, FGameplayTagContainer AddedTags, UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void TriggerEffectsWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category = "Effects")
	void TriggerEffectsOfCategory(FGameplayTag CategoryTag);

	UFUNCTION(BlueprintPure, Category = "Effects")
	TArray<AOmegaGameplayEffect*> GetEffectsWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Effects")
	TArray<AOmegaGameplayEffect*> GetEffectsOfCategory(FGameplayTag CategoryTag);

	UFUNCTION(BlueprintPure, Category = "Effects")
	AOmegaGameplayEffect* GetActiveEffectOfClass(TSubclassOf<AOmegaGameplayEffect> EffectClass, bool& bIsValid);
	
	UFUNCTION()
	TArray<AOmegaGameplayEffect*> GetValidActiveEffects();
	
	UFUNCTION(BlueprintCallable, Category = "Effects")
    void RemoveEffectsOfCategory(FGameplayTag CategoryTag);
    
    UFUNCTION(BlueprintCallable, Category = "Effects")
	void RemoveEffectsWithTags(FGameplayTagContainer EffectTags);
	
	////////////////////////////////////
	////////// -- Targeting -- //////////
	///////////////////////////////////

	UPROPERTY(BlueprintReadOnly, Category="Target")
	TArray<UCombatantComponent*> TargetList;

	UPROPERTY(BlueprintReadOnly, Category="Target")
	UCombatantComponent* ActiveTarget;
	
	UPROPERTY(BlueprintReadOnly, Category="Target")
	int32 ActiveTargetIndex;

	UFUNCTION(BlueprintCallable, Category="Target")
	void AddTargetToList(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintCallable, Category="Target")
	void AddTargetsToList(TArray<UCombatantComponent*> Combatants, bool bClearListFirst);
	
	UFUNCTION(BlueprintCallable, Category="Target")
	void RemoveTargetFromList(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintCallable, Category="Target")
	void ClearTargetList();

	UFUNCTION(BlueprintCallable, Category="Target")
	void SetActiveTarget(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintCallable, Category="Target")
	void ClearActiveTarget();
	
	//Delegates
	UPROPERTY(BlueprintAssignable)
	FOnTargetAdded OnTargetAdded;
	UPROPERTY(BlueprintAssignable)
	FOnTargetAdded OnTargetRemoved;
	
	UPROPERTY(BlueprintAssignable)
	FOnAddedAsTarget OnAddedAsTarget;
	UPROPERTY(BlueprintAssignable)
	FOnRemovedAsTarget OnRemovedAsTarget;
	
	UPROPERTY(BlueprintAssignable)
	FOnActiveTargetChanged OnActiveTargetChanged;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//////////______________________________DELEGATES______________________________//////////
	////////////////////////////////////////////////////////////////////////////////////////

	UPROPERTY(BlueprintAssignable)
	FOnDamaged OnDamaged;

	UPROPERTY(BlueprintAssignable)
	FOnCombatantLevelChange OnLevelChanged;
};


