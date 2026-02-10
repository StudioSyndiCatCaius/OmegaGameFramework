// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Interfaces/I_Common.h"
#include "Interfaces/I_Skill.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "Interfaces/I_Combatant.h"
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
class OMEGAGAMEFRAMEWORK_API UCombatantComponent : public UActorComponent, public IDataInterface_SkillSource, public IGameplayTagsInterface,
																			public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier,
																			public IDataInterface_General
{
	GENERATED_BODY()

	float L_ModifyDamage(UOmegaAttribute* Attribute,UCombatantComponent* Instigator,float BaseDamage,UOmegaDamageType* DamageType,UObject* Context);
	void L_CacheAttributeMods();
	float L_GetAllModsOfAttribute(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute);

	UFUNCTION() TArray<UObject*> L_GetSources_Skill();
	UFUNCTION() FGameplayTagContainer GetBlockedEffectTags();
	
	TArray<FOmegaAttributeModifier> CachedAttributeModValues;
	
	UPROPERTY() UEnhancedInputComponent* OwnerInputComp;
	UPROPERTY() APawn* ref_OwnerPawn;
	UPROPERTY() TArray<AOmegaAbility*> abilities_granted;
	UPROPERTY() TArray<UOmegaDamageTypeReaction*> LocalDamageReactions;
	UPROPERTY() TArray<UCombatantComponent*> target_list;
	UPROPERTY() UCombatantComponent* target_active;

public:	
	UCombatantComponent();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override; 
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return CombatantTags; };
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- Delegates -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	
	UPROPERTY(BlueprintAssignable) FOnDamaged OnDamaged;
	UPROPERTY(BlueprintAssignable) FOnCombatantLevelChange OnLevelChanged;
	UPROPERTY(BlueprintAssignable) FOnFactionChanged OnFactionChanged;
	UPROPERTY(BlueprintAssignable) FOnCombatantDataAssetChanged OnDataAssetChanged;
	UPROPERTY(BlueprintAssignable) FOnTargetAdded OnTargetAdded;
	UPROPERTY(BlueprintAssignable) FOnAddedAsTarget OnAddedAsTarget;
	UPROPERTY(BlueprintAssignable) FOnActiveTargetChanged OnActiveTargetChanged;
	UPROPERTY(BlueprintAssignable) FOnCombatantNotify OnCombatantNotify;
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- UPROPERTY -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	
	UPROPERTY(VisibleInstanceOnly,Category="Modifiers") TArray<UObject*> SOURCES_Master;
	UPROPERTY(VisibleInstanceOnly,Category="Modifiers") TArray<UObject*> SOURCES_AttributeMods;
	UPROPERTY(VisibleInstanceOnly,Category="Modifiers") TArray<UObject*> SOURCES_Skills;
	UPROPERTY(VisibleInstanceOnly,Category="Modifiers") TArray<UObject*> SOURCES_DamageMods;

	/// ------ FLAGS ----------
	
	UPROPERTY(EditAnywhere, Category = "Flags")
	bool bUseSkillsAsMasterSource=true;
	
	//Only reruns attribute modifier call when attribute modifiers source list changes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Flags")
	bool bCacheAttributeModifierValues=false;

	/// ------ COMBATANT ----------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category = "Combatant")
	UPrimaryDataAsset* CombatantDataAsset=nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Combatant")	
	FGameplayTagContainer CombatantTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combatant",DisplayName="Faction")
	UOmegaFaction* FactionDataAsset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combatant")
	UCombatantGambitAsset* DefaultGambit;
	
	UPROPERTY(EditAnywhere, Category = "Combatant")
	TArray<TSubclassOf<AOmegaAbility>>GrantedAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combatant")
	TMap<UOmegaDamageType*,UOmegaDamageTypeReactionAsset*> DamageTypeReactions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combatant")
	TArray<UPrimaryDataAsset*> Skills;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combatant")
	TSubclassOf<AOmegaGameplayEffect> ReactionEffectClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combatant")
	FGameplayTagContainer BlockEffectWithTags;

	/// ------ Attributes ----------
	/// 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", AdvancedDisplay)
	bool bCanDamageAttributes = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	UOmegaAttributeSet* AttributeSet;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	int32 Level = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", AdvancedDisplay)
	FGameplayTag AttributeValueCategory;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Attributes")
	TMap<UOmegaAttribute*, float> CurrentAttributeValues;
	
	//Forcibly Override whatever the max attributes values found in the "AttributeSet" 
	UPROPERTY(EditAnywhere, Category = "Attributes")
	TMap<UOmegaAttribute*, float>  OverrideMaxAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes", AdvancedDisplay)
	TMap<UOmegaAttribute*, int32> AttributeLevels;
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- UFUNCTION -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//

	/// ------ COMBATANT ----------

	//Refreshes all visible combatnat related values, primarily in widgets.
	UFUNCTION(BlueprintCallable, Category = "Combatant", DisplayName="Refresh") void Update();

	//Tries to get the owning actor as a Pawn.
	UFUNCTION(BlueprintPure, Category="Combatant") APawn* GetOwnerPawn() const;
	UFUNCTION(BlueprintPure, Category="Combatant") APlayerController* GetOwnerPlayerController() const;
	
	UFUNCTION(BlueprintCallable,Category="Combatant")
	void SetSourceDataAsset(UPrimaryDataAsset* DataAsset);
	UFUNCTION(BlueprintPure,Category="Combatant")
	UPrimaryDataAsset* GetSourceDataAsset() const;
	
	/// ------ DataSources ----------
	
	UFUNCTION(BlueprintCallable, Category = "DataSource", DisplayName="Set Source Active (MASTER)")
	void SetMasterDataSourceActive(UObject* Source, bool bActive);
	UFUNCTION(BlueprintCallable, Category = "DataSource", DisplayName="Set Source Active (Attribute Modifier)")
	void SetAttributeModifierActive(UObject* Modifier, bool bActive);
	UFUNCTION(BlueprintCallable, Category="DataSource", DisplayName="Set Source Active (Skills)")
	bool SetSkillSourceActive(UObject* SkillSource, bool bActive);
	UFUNCTION(BlueprintCallable, Category="DataSource", DisplayName="Set Source Active (Damage Modifiers)")
	bool SetDamageModifierActive(UObject* Modifier, bool bActive);
	
	/// ------ Attributes ----------
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void InitializeAttributes();
	
	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (AdvancedDisplay = "Instigator, Context, DamageType, Hit"))
	float ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UCombatantComponent* Instigator, UObject* Context, UOmegaDamageType* DamageType, FHitResult Hit);
	
	UFUNCTION(BlueprintPure, Category = "Attributes") void GetAttributeValue(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);
	UFUNCTION(BlueprintPure, Category = "Attributes") float GetAttributeBaseValue(UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure, Category = "Attributes") float GetAttributePercentage(class UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure, Category = "Attributes") TMap<UOmegaAttribute*, float> GetCurrentAttributeValues();
	UFUNCTION(BlueprintPure, Category = "Attributes") int32 GetAttributeLevel(UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure, Category = "Attributes") float AdjustAttributeValueByModifiers(UOmegaAttribute* Attribute, TArray<FOmegaAttributeModifier> Modifiers);
	UFUNCTION(BlueprintPure, Category = "Attributes") float GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") void ChangeAttributeSet(UOmegaAttributeSet* NewSet,bool Reinitialize);

	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetOverrideMaxAttribute(UOmegaAttribute* Attribute, float Value);
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetOverrideMaxAttributes(TMap<UOmegaAttribute*, float> Values);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCurrentAttributeValue(UOmegaAttribute* Attribute, float Value);
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCombatantLevel(int32 NewLevel, bool ReinitializeStats);
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetAttributeValueCategory(FGameplayTag CategoryTag, bool bReinitialize);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") TArray<FOmegaAttributeModifier> GetAllModifierValues();
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") const TArray<UObject*> GetAttributeModifiers();
	/// ------ FACTION ----------
	
	UFUNCTION(BlueprintCallable,Category="Faction") void SetFaction_Asset(UOmegaFaction* Faction);
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Name")) FText GetFactionName();
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Color")) FLinearColor GetFactionColor();
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Tag")) FGameplayTag GetFactionTag();
	UFUNCTION(BlueprintPure, Category="Faction") TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> GetFactionAffinities();
	
	UFUNCTION(BlueprintPure, Category="Faction") EFactionAffinity GetAffinityToCombatant(UCombatantComponent* CheckedCombatant);
	UFUNCTION(BlueprintPure, Category="Faction") TArray<UCombatantComponent*> FilterCombatantsByAffinity(TArray<UCombatantComponent*> Combatants, EFactionAffinity Affinity, bool bExclude);
	
	/// ------ SKILLS ----------
	
	UFUNCTION(BlueprintCallable, Category="Skills") TArray<UPrimaryDataAsset*> GetAllSkills();
	UFUNCTION(BlueprintCallable, Category="Skills") void AddSkill(UPrimaryDataAsset* Skill, bool Added);
	UFUNCTION(BlueprintCallable, Category="Skills") void AddSkills(TArray<UPrimaryDataAsset*> skill_list, bool Added);

	/// ------ TAGS ----------

	UFUNCTION(BlueprintPure, Category = "Tags") FGameplayTagContainer GetCombatantTags();
	UFUNCTION(BlueprintPure, Category = "Tags") bool CombatantHasTag(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure, Category = "Tags,", meta=(AdvancedDisplay = "Exact")) 	bool CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact=true) const;
	UFUNCTION(BlueprintPure, Category = "Tags", meta=(AdvancedDisplay = "Exact")) bool CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact=true) const;
	
	/// ------ Abilities ----------
	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool SetAbilityGranted(TSubclassOf<AOmegaAbility> AbilityClass, bool Granted);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetAbilitiesGranted(TArray<TSubclassOf<AOmegaAbility>> AbilityClass, bool Granted);

	UFUNCTION(BlueprintPure, Category = "Ability", meta=(DeterminesOutputType="AbilityClass"))
	AOmegaAbility* GetAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool& bSuccess);
	
	UFUNCTION(BlueprintCallable, Category = "Ability", meta = (AdvancedDisplay = "Context", DisplayName="Activate Ability"))
	AOmegaAbility* ExecuteAbility(class TSubclassOf<AOmegaAbility> AbilityClass, class UObject* Context, bool& bSuccess);

	UFUNCTION(BlueprintCallable, Category = "Ability") bool StopAbility(class TSubclassOf<AOmegaAbility> AbilityClass, bool Cancel);
	UFUNCTION(BlueprintCallable, Category = "Ability") void CancelAbilitiesWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintCallable, Category = "Ability") void CancelAllAbilities();
	
	UFUNCTION(BlueprintPure, Category = "Ability") bool IsAbilityActive(class TSubclassOf<AOmegaAbility> AbilityClass);
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetActiveAbilities();
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetActiveAbilitiesWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetGrantedAbilities();
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetGrantedAbilitiesWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintPure, Category = "Ability") bool IsAbilityTagBlocked(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintPure, Category="DamageModifiers") TArray<UObject*> GetDamageModifiers();
	
	/// ------ Effects ----------
	
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
	
	UFUNCTION(BlueprintCallable, Category = "Effects") void RemoveEffectsWithTags(FGameplayTagContainer EffectTags);
	
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetAllEffects();
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetEffectsWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetEffectsOfCategory(FGameplayTag CategoryTag);
	UFUNCTION(BlueprintPure, Category = "Effects") bool HasEffectWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintPure, Category = "Effects") AOmegaGameplayEffect* GetActiveEffectOfClass(TSubclassOf<AOmegaGameplayEffect> EffectClass, bool& bIsValid);

	/// ------ Targeting ----------

	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Register",meta=(Keywords="Add, List"))
	void SetTargetRegistered(UCombatantComponent* Combatant, bool IsRegistered);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting",meta=(Keywords="Add, List"))
	void SetTargetsRegistered(TArray<UCombatantComponent*> Combatants, bool IsRegistered, bool ClearListFirst);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") void ClearTargetList();
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") void SetActiveTarget(UCombatantComponent* Combatant);
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting",meta=(ExpandBoolAsExecs="IsValid")) UCombatantComponent* TryGetActiveTarget(bool&  IsValid);
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") UCombatantComponent* CycleActiveTarget(int32 Amount);
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") void ClearActiveTarget();
	
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting") TArray<UCombatantComponent*> GetRegisteredTargetList();
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting") UCombatantComponent* GetActiveTarget() const;
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting") int32 GetActiveTargetIndex();

	/// ------ Notify ----------
	
	//Fires an agonist notify across the combatant that can be recieved in abilities and the parent actor.
	UFUNCTION(BlueprintCallable, Category="Notify", meta=(AdvancedDisplay="Flag")) void CombatantNotify(FName Notify, const FString& Flag);

	/// ------ Gambit ----------
	
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunDefaultGambit();
	
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunGambit(UCombatantGambitAsset* Gambit, bool bReplaceDefaultGambit=false);

	UFUNCTION(BlueprintPure, Category="Gambit")
	bool GetActionDataFromGambit(UCombatantGambitAsset* Gambit, TSubclassOf<AOmegaAbility>& Ability, UObject*& Context);
};