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

class UOmegaAttribute;
class UOmegaAttributeSet;
class AOmegaAbility;
class AOmegaGameplayEffect;

class UInputComponent;
class UEnhancedInputComponent;
class UInputAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UObject*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantLevelChange, int32, NewLevel);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetAdded, UCombatantComponent*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetRemoved, UCombatantComponent*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveTargetChanged, UCombatantComponent*, ActiveTarget, bool, Valid);


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
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

	UPROPERTY()
	TMap<class UOmegaAttribute*, float> CurrentAttributeValues;

	float GatherAttributeModifiers(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute);

	////////////////////////////////////
	////////// -- Faction -- //////////
	///////////////////////////////////

	UPROPERTY(EditAnywhere, Category = "Faction")
	class UPrimaryDataAsset* FactionDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	FGameplayTag FactionTag;
	
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

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
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

	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CancelAbilitiesWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Ω|Ability")
	bool IsAbilityTagBlocked(FGameplayTagContainer Tags);

	////////////////////////////////////
	////////// -- Attributes -- ////////
	///////////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (AdvancedDisplay = "Instigator"))
	float ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UObject* Instigator, UObject* DamageModifier);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetAttributeValue(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	float GetAttributePercentage(class UOmegaAttribute* Attribute);
	
	UFUNCTION(BlueprintPure, Category = "Attributes")
	TMap<UOmegaAttribute*, float> GetCurrentAttributeValues();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetCombatantLevel(int32 NewLevel, bool ReinitializeStats);

	void InitializeAttributes();
	
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

	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	const TArray<UObject*> GetAttributeModifiers();

	
	////////////////////////////////////
	////////// -- Effects -- ////////
	///////////////////////////////////

	UPROPERTY()
	TArray<class AOmegaGameplayEffect*> ActiveEffects;

	UFUNCTION(BlueprintCallable, Category = "Effects", meta=(AdvancedDisplay="AddedTags, Target"))
	class AOmegaGameplayEffect* CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, float Power, FTransform Location, class AActor* Target, FGameplayTagContainer AddedTags);
	
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void TriggerEffectsWithTags(FGameplayTagContainer Tags);
	
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
	FOnActiveTargetChanged OnActiveTargetChanged;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//////////______________________________DELEGATES______________________________//////////
	////////////////////////////////////////////////////////////////////////////////////////

	UPROPERTY(BlueprintAssignable)
	FOnDamaged OnDamaged;

	UPROPERTY(BlueprintAssignable)
	FOnCombatantLevelChange OnLevelChanged;
};


