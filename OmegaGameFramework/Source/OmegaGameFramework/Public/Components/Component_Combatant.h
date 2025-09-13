// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Interfaces/OmegaInterface_Common.h"
#include "Interfaces/OmegaInterface_Skill.h"
#include "Engine/DataAsset.h"
#include "JsonObjectWrapper.h"
#include "OmegaGameplayComponent.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Misc/OmegaAttribute.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Component_Combatant.generated.h"

class APawn;
class ACharacter;
class APlayerController;
class UOmegaAttribute;
class UOmegaDamageType;
class UOmegaAttribute;
class UOmegaAttributeSet;
class AOmegaAbility;
class AOmegaGameplayEffect;
class UOmegaGameplaySubsystem;
class ACombatantTargetIndicator;
class UOmegaFaction;
class UOmegaDamageType;
class UOmegaDamageTypeReaction;
class UOmegaDamageTypeReactionAsset;
class UCombatantGambitAsset;

class UInputComponent;
class UEnhancedInputComponent;
class UInputAction;

/// DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UCombatantComponent*, Instigator, UOmegaDamageType*, DamageType, FHitResult, Hit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantLevelChange, int32, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatantDataAssetChanged, UCombatantComponent*, Combatant, UPrimaryDataAsset*, NewAsset,UPrimaryDataAsset*, OldAsset);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFactionChanged, UCombatantComponent*, component, UOmegaFaction*, NewFaction, UOmegaFaction*, OldFaction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTargetAdded, UCombatantComponent*, component, UCombatantComponent*, Target, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAddedAsTarget, UCombatantComponent*, component, UCombatantComponent*, Instigator, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveTargetChanged, UCombatantComponent*, ActiveTarget, bool, Valid);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatantNotify, UCombatantComponent*, Combatant, FName, Notify, const FString&, Flag);


#define PrintError(ErrorText) \
	(GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, ErrorText))

UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), CollapseCategories="Sockets,Component Tick,Component Replication,Activation,Cooking" )
class OMEGAGAMEFRAMEWORK_API UCombatantComponent : public UOmegaGameplayComponent, public IDataInterface_General, public IDataInterface_SkillSource,
																			public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier
{
	GENERATED_BODY()

	float L_ModifyDamage(UOmegaAttribute* Attribute,UObject* Instigator,float BaseDamage,UOmegaDamageType* DamageType,UObject* Context);
	
	UPROPERTY() UEnhancedInputComponent* OwnerInputComp;
	UPROPERTY() APawn* OwnerPawn;
	UPROPERTY() TArray<AOmegaAbility*> ActiveAbilities;
	
public:	
	UCombatantComponent();
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override; 
	
	// ------------------------------------------------------------------------------------------------------------------------
	// General
	// ------------------------------------------------------------------------------------------------------------------------

		//		--- PROPERTY ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combatant", meta = (DisplayName = "Name"))
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combatant", meta = (DisplayName = "Description", MultiLine))
	FText CombatantDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combatant", meta = (DisplayName = "Icon"))
	FSlateBrush CombatantIcon;
	UPROPERTY(BlueprintReadWrite, Category="Combatant", DisplayName="Metadata")
	FJsonObjectWrapper JsonMetadata;
	
		//		--- FUNCTION ---
	UPROPERTY(VisibleInstanceOnly,Category="Modifiers")
	TArray<UObject*> SOURCES_Master;
	UFUNCTION(BlueprintCallable, Category="DataSource", DisplayName="Set MASTER Source Active")
	void SetMasterDataSourceActive(UObject* Source, bool bActive);

	UPROPERTY(EditAnywhere, Category = "Flags")
	bool bUseSkillsAsMasterSource=true;
	
	// ------------------------------------------------------------------------------------------------------------------------
	// Attributes
	// ------------------------------------------------------------------------------------------------------------------------

		//		--- DELEGATES ---
	UPROPERTY(BlueprintAssignable) FOnDamaged OnDamaged;
	UPROPERTY(BlueprintAssignable) FOnCombatantLevelChange OnLevelChanged;

		//		--- PROPERTY ---
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	int32 Level = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	UOmegaAttributeSet* AttributeSet;
	
	UPROPERTY(EditInstanceOnly,Category="Attributes")
	TMap<UOmegaAttribute*, float> CurrentAttributeValues;
	
	//Forcibly Override whatever the max attributes values found in the "AttributeSet" 
	UPROPERTY(EditAnywhere, Category = "Attributes")
	TMap<UOmegaAttribute*, float>  OverrideMaxAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", AdvancedDisplay)
	bool bCanDamageAttributes = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes", AdvancedDisplay)
	TMap<class UOmegaAttribute*, int32> AttributeLevels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", AdvancedDisplay)
	FGameplayTag AttributeValueCategory;
	
	UFUNCTION(BlueprintCallable,Category="Attributes")
	void ChangeAttributeSet(UOmegaAttributeSet* NewSet,bool Reinitialize);
	
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetOverrideMaxAttribute(UOmegaAttribute* Attribute, float Value);
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetOverrideMaxAttributes(TMap<UOmegaAttribute*, float> Value);
	UFUNCTION(BlueprintCallable, Category="Attributes", DisplayName="Set Override Max Attributes (Int)")
	void SetOverrideMaxAttributes_Int(TMap<UOmegaAttribute*, int32> Value);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (AdvancedDisplay = "Instigator, Context, DamageType, Hit"))
	float ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UCombatantComponent* Instigator, UObject* Context, UOmegaDamageType* DamageType, FHitResult Hit);
	
	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetAttributeValue(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);

	UFUNCTION(BlueprintCallable, Category = "Attributes", DisplayName="GetAttributeValue (Impure)")
	void GetAttributeValue_Impure(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);
	
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

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void InitializeAttributes();
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetAttributeValueCategory(FGameplayTag CategoryTag, bool bReinitialize);

	UFUNCTION(BlueprintPure, Category="Attributes")
	int32 GetAttributeLevel(UOmegaAttribute* Attribute);

	// ------------------------------------------------------------------------------------------------------------------------
	// Attribute Modifiers
	// ------------------------------------------------------------------------------------------------------------------------
	
private:
	void Local_CacheAttributeMods();
	
	float GatherAttributeModifiers(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute);
	TArray<FOmegaAttributeModifier> CachedAttributeModValues;
public:
			//		--- PROPERTY ---
	UPROPERTY(VisibleInstanceOnly,Category="Modifiers")
	TArray<UObject*> SOURCES_AttributeMods;
	
	//Only reruns attribute modifier call when attribute modifiers source list changes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attributes")
	bool bCacheAttributeModifierValues=true;

		//		--- FUNCTION ---
	
	UFUNCTION(BlueprintPure, Category="Attributes")
	float AdjustAttributeValueByModifiers(UOmegaAttribute* Attribute, TArray<FOmegaAttributeModifier> Modifiers);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	TArray<FOmegaAttributeModifier> GetAllModifierValues();
	
	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers", meta = (AdvancedDisplay = "Category, Tags"))
	UAttributeModifierContainer* CreateAttributeModifier(UOmegaAttribute* Attribute, float Increment, float Multiplier, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="DataSource")
	void SetAttributeModifierActive(UObject* Modifier, bool bActive);

	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	void RemoveAttributeModifersWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category= "Attributes|Modifiers")
	float GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers);

	UFUNCTION(BlueprintCallable, Category= "Attributes|Modifiers")
	const TArray<UObject*> GetAttributeModifiers();
	
	// ------------------------------------------------------------------------------------------------------------------------
	// Effects
	// ------------------------------------------------------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	TMap<UOmegaDamageType*,UOmegaDamageTypeReactionAsset*> DamageTypeReactions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	TSubclassOf<AOmegaGameplayEffect> ReactionEffectClass;
	
protected:

	UPROPERTY()
	TArray<UOmegaDamageTypeReaction*> LocalDamageReactions;
public:
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- FACTION -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	UPROPERTY(BlueprintAssignable) FOnFactionChanged OnFactionChanged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	UOmegaFaction* FactionDataAsset;
	
	UFUNCTION(BlueprintCallable,Category="Faction")
	void SetFaction_Asset(UOmegaFaction* Faction);
	
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Name"))
	FText GetFactionName();
	
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Color"))
	FLinearColor GetFactionColor();
	
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Tag"))
	FGameplayTag GetFactionTag();
	
	UFUNCTION(BlueprintPure, Category="Faction")
	TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> GetFactionAffinities();
	
	UFUNCTION(BlueprintPure, Category="Faction")
	EFactionAffinity GetAffinityToCombatant(UCombatantComponent* CheckedCombatant);

	UFUNCTION(BlueprintPure, Category="Faction")
	TArray<UCombatantComponent*> FilterCombatantsByAffinity(TArray<UCombatantComponent*> Combatants, EFactionAffinity Affinity, bool bExclude);
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- SKILLS -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//

	UPROPERTY(VisibleInstanceOnly,DisplayName="Skill Sources",Category="Modifiers")
	TArray<UObject*> SOURCES_Skills;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
	TArray<UPrimaryDataAsset*> Skills;

	
	UFUNCTION(BlueprintCallable, Category="Skills")
	TArray<UPrimaryDataAsset*> GetAllSkills();
	
	UFUNCTION(BlueprintCallable, Category="Skills")
	void AddSkill(UPrimaryDataAsset* Skill, bool Added);
	UFUNCTION(BlueprintCallable, Category="Skills")
	void AddSkills(TArray<UPrimaryDataAsset*> skill_list, bool Added);


	UFUNCTION(BlueprintCallable, Category="DataSource")
	bool SetSkillSourceActive(UObject* SkillSource, bool bActive);


	UFUNCTION()
	TArray<UObject*> Local_GetSkillSources();
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- Gameplay Tags -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
		
	UPROPERTY(EditAnywhere, Category = "Combatant")
	FGameplayTag CategoryTags;

	UPROPERTY(EditAnywhere, Category = "Combatant")	
	FGameplayTagContainer CombatantTags;
	
	UFUNCTION(BlueprintCallable, Category = "Tags")
	void AddTagsToCombatant(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category = "Tags")
	void RemoveTagsFromCombatant(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Tags")
	FGameplayTagContainer GetCombatantTags();

	UFUNCTION(BlueprintPure, Category = "Tags")
	bool CombatantHasTag(FGameplayTag Tag);

	UFUNCTION(BlueprintPure, Category = "Tags,", meta=(AdvancedDisplay = "Exact"))
	bool CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact=true);

	UFUNCTION(BlueprintPure, Category = "Tags", meta=(AdvancedDisplay = "Exact"))
	bool CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact=true);

	//////////////////////////////////////////////////////////////////////////////////////////
	//////////______________________________FUNCTIONS______________________________//////////
	////////////////////////////////////////////////////////////////////////////////////////

	// ------------------------------------------------------------------------------------------------------------------------
	// - MISC - 
	// ------------------------------------------------------------------------------------------------------------------------

	//Refreshes all visible combatnat related values, primarily in widgets.
	UFUNCTION(BlueprintCallable, Category = "Combatant", DisplayName="Refresh") void Update();

	//Tries to get the owning actor as a Pawn.
	UFUNCTION(BlueprintPure, Category="Combatant") APawn* GetOwnerPawn();

	//Tries to get the owning actor as a Character.
	UFUNCTION(BlueprintPure, Category="Combatant") ACharacter* GetOwnerCharacter();

	//Tries to get the owning actor OR the owning actor's controller.
	UFUNCTION(BlueprintPure, Category="Combatant") AController* GetOwnerController();

	//Tries to get the owning actor OR the owning actor's controller as a player controller.
	UFUNCTION(BlueprintPure, Category="Combatant") APlayerController* GetOwnerPlayerController();
	

	bool CombatantDataAssetIsValidData() const
	{
		return CombatantDataAsset && CombatantDataAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass());
	}
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category = "General")
	UPrimaryDataAsset* CombatantDataAsset=nullptr;
	UFUNCTION(BlueprintCallable,Category="Combatant")
	void SetSourceDataAsset(UPrimaryDataAsset* DataAsset)
	{
		if(DataAsset)
		{
			UPrimaryDataAsset* oldAsset=DataAsset;
			CombatantDataAsset=DataAsset;
			OnDataAssetChanged.Broadcast(this,DataAsset,oldAsset);
		}
	}
	UFUNCTION(BlueprintPure,Category="Combatant")
	UPrimaryDataAsset* GetSourceDataAsset() const { if(CombatantDataAsset) {return CombatantDataAsset;} return nullptr;}
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- ABILITIES -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	void SetAbilityActive(bool bActive, AOmegaAbility* Ability);
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<AOmegaAbility>>GrantedAbilities;

	UPROPERTY()
	TArray<AOmegaAbility*>AbilityList;

	///////Ability Possession
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool GrantAbility(TSubclassOf<AOmegaAbility> AbilityClass);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool UngrantAbility(TSubclassOf<AOmegaAbility> AbilityClass);

	UFUNCTION(BlueprintPure, Category = "Ability", meta=(DeterminesOutputType="AbilityClass"))
	AOmegaAbility* GetAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool& bSuccess);

	///////Ability Activation
	
	UFUNCTION(BlueprintCallable, Category = "Ability", meta = (AdvancedDisplay = "Context", DisplayName="Activate Ability"))
	AOmegaAbility* ExecuteAbility(class TSubclassOf<AOmegaAbility> AbilityClass, class UObject* Context, bool& bSuccess);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool StopAbility(class TSubclassOf<AOmegaAbility> AbilityClass, bool Cancel);

	UFUNCTION(BlueprintPure, Category = "Ability")
	bool IsAbilityActive(class TSubclassOf<AOmegaAbility> AbilityClass, class AOmegaAbility*& Ability);

	UFUNCTION(BlueprintPure, Category = "Ability")
	TArray<AOmegaAbility*> GetActiveAbilities();

	UFUNCTION(BlueprintPure, Category = "Ability")
	TArray<AOmegaAbility*> GetActiveAbilitiesWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Ability")
	TArray<AOmegaAbility*> GetGrantedAbilities();

	UFUNCTION(BlueprintPure, Category = "Ability")
	TArray<AOmegaAbility*> GetGrantedAbilitiesWithTags(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void CancelAbilitiesWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void CancelAllAbilities();

	UFUNCTION(BlueprintPure, Category = "Ability")
	bool IsAbilityTagBlocked(FGameplayTagContainer Tags);
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- Damage Modifiers -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//

	UPROPERTY(VisibleInstanceOnly,Category="Modifiers")
	TArray<UObject*> SOURCES_DamageMods;

	UFUNCTION(BlueprintCallable, Category="DataSource")
	bool SetDamageModifierActive(UObject* Modifier, bool bActive);

	UFUNCTION(BlueprintPure, Category="DamageModifiers")
	TArray<UObject*> GetDamageModifiers();
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- EFFECTS -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	FGameplayTagContainer BlockEffectWithTags;

	UFUNCTION()
	FGameplayTagContainer GetBlockedEffectTags();

	UFUNCTION(BlueprintPure, Category="Effects", meta=(DeterminesOutputType="EffectClass"))
	AOmegaGameplayEffect* GetEffectOfContext(UObject* Context, TSubclassOf<AOmegaGameplayEffect> EffectClass);

	//This value will be added to an effects default success rate. If blank, the default rate will be used.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects", DisplayName="Offset Effect Success")
	TMap<TSubclassOf<AOmegaGameplayEffect>,float> EffectSuccessRate;

	UFUNCTION(BlueprintPure, Category="Effects", meta=(DeprecatedFunction))
	float GetEffectSuccessRate(TSubclassOf<AOmegaGameplayEffect> EffectClass);
	
	UFUNCTION(BlueprintCallable, Category="Effects", meta=(DeprecatedFunction))
	void SetEffectSuccessRate(TSubclassOf<AOmegaGameplayEffect> EffectClass, float OffsetRate=0);
	
	UFUNCTION(BlueprintCallable, Category = "Effects", meta=(AdvancedDisplay="AddedTags, Location"))
	class AOmegaGameplayEffect* CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, float Power, UCombatantComponent* Target, FGameplayTagContainer AddedTags, UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void TriggerEffectsWithTags(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void TriggerEffectsOfCategory(FGameplayTag CategoryTag);

	UFUNCTION(BlueprintPure, Category = "Effects")
	bool HasEffectWithTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "Effects")
	TArray<AOmegaGameplayEffect*> GetAllEffects();
	
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
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- TARGETING -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//

private:
	UPROPERTY() TArray<UCombatantComponent*> TargetList;
	UPROPERTY() UCombatantComponent* ActiveTarget;
	UPROPERTY() int32 ActiveTargetIndex;

public:

	UCombatantComponent* Native_GetActiveTarget() const
	{
		if(ActiveTarget) {return ActiveTarget;} return nullptr;
	}
	
		//		-- DELEGATES --
	UPROPERTY(BlueprintAssignable) FOnCombatantDataAssetChanged OnDataAssetChanged;
	UPROPERTY(BlueprintAssignable) FOnTargetAdded OnTargetAdded;
	UPROPERTY(BlueprintAssignable) FOnAddedAsTarget OnAddedAsTarget;
	UPROPERTY(BlueprintAssignable) FOnActiveTargetChanged OnActiveTargetChanged;

	// - TARGET LIST ----------------------------

	UFUNCTION(BlueprintCallable
		, Category="Combatant|Targeting|Register",meta=(Keywords="Add, List"))
	void SetTargetRegistered(UCombatantComponent* Combatant, bool IsRegistered);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Register",meta=(Keywords="Add, List"))
	void SetTargetsRegistered(TArray<UCombatantComponent*> Combatants, bool IsRegistered, bool ClearListFirst);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Register")
	void ClearTargetList();

	UFUNCTION(BlueprintPure, Category="Combatant|Targeting|Register")
	TArray<UCombatantComponent*> GetRegisteredTargetList();

		// - ACTIVE TARGET ----------------------------
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Active")
	void SetActiveTarget(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintPure, Category="Combatant|Targeting|Active")
	UCombatantComponent* GetActiveTarget() const;

	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Active",meta=(ExpandBoolAsExecs="IsValid"))
	UCombatantComponent* TryGetActiveTarget(bool&  IsValid);
	
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting|Active")
	int32 GetActiveTargetIndex();

	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Active")
	UCombatantComponent* CycleActiveTarget(int32 Amount);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Active")
	void ClearActiveTarget();
	
	
	////////////////////////////////////
	////////// -- NOTIFIES -- //////////
	///////////////////////////////////

	//Fires an agonist notify across the combatant that can be recieved in abilities and the parent actor.
	UFUNCTION(BlueprintCallable, Category="Notify", meta=(AdvancedDisplay="Flag"))
	void CombatantNotify(FName Notify, const FString& Flag);

	UPROPERTY(BlueprintAssignable) FOnCombatantNotify OnCombatantNotify;

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;

	//##################################################################################################################
	// Gambits
	//##################################################################################################################
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	UCombatantGambitAsset* DefaultGambit;
	
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunDefaultGambit();
	
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunGambit(UCombatantGambitAsset* Gambit, bool bReplaceDefaultGambit=false);

	UFUNCTION(BlueprintPure, Category="Gambit")
	bool GetActionDataFromGambit(UCombatantGambitAsset* Gambit, TSubclassOf<AOmegaAbility>& Ability, UObject*& Context);
	
	
};