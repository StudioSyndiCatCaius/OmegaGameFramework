// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaComponent.h"

#include "Interfaces/I_Common.h"
#include "Interfaces/I_Skill.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "Interfaces/I_Combatant.h"
#include "DataAssets/DA_Attribute.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"
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
class UOmegaSubsystem_World;
class ACombatantTargetIndicator;
class UOmegaFaction;
class UOmegaDamageType;
class UCombatantGambitAsset;

class UInputComponent;
class UEnhancedInputComponent;
class UInputAction;

/// DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UCombatantComponent*, Instigator, UOmegaDamageType*, DamageType, FHitResult, Hit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatantDataAssetChanged, UCombatantComponent*, Combatant, UPrimaryDataAsset*, NewAsset,UPrimaryDataAsset*, OldAsset);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFactionChanged, UCombatantComponent*, component, UOmegaFaction*, NewFaction, UOmegaFaction*, OldFaction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTargetAdded, UCombatantComponent*, component, UCombatantComponent*, Target, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAddedAsTarget, UCombatantComponent*, component, UCombatantComponent*, Instigator, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveTargetChanged, UCombatantComponent*, ActiveTarget, bool, Valid);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatantNotify, UCombatantComponent*, Combatant, FName, Notify, const FString&, Flag);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatant_InventoryEdit, UCombatantComponent*, Combatant, UPrimaryDataAsset*, Item, int32, AmountChanged);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatant_EquipChange, UCombatantComponent*, Combatant, UEquipmentSlot*, Slot, UPrimaryDataAsset*, Item);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCombatant_XpChange, UCombatantComponent*, Combatant, UOmegaLevelingAsset*, Type, float, old_xp,float, new_xp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCombatant_LevelChange, UCombatantComponent*, Combatant, UOmegaLevelingAsset*, Type, int32, old_level,int32, new_level);


#define  UFUNC_EQUIP_C(Name) UFUNCTION(BlueprintCallable, Category="Equipment", DisplayName="Equipment - ")
#define  UFUNC_EQUIP_P(Name) UFUNCTION(BlueprintPure, Category="Equipment", DisplayName="Equipment - ")


#define PrintError(ErrorText) \
	(GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, ErrorText))

UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), CollapseCategories="Sockets,Component Tick,Component Replication,Activation,Cooking" )
class OMEGAGAMEFRAMEWORK_API UCombatantComponent : public UOmegaComponent, public IDataInterface_SkillSource,
																			public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier,
																			public IDataInterface_General
{
	GENERATED_BODY()

	float L_ModifyDamage(UOmegaAttribute* Attribute,UCombatantComponent* Instigator,float BaseDamage,UOmegaDamageType* DamageType,UObject* Context);
	void L_CacheAttributeMods();
	float L_GetAllModsOfAttribute(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute);

	UFUNCTION() TArray<UObject*> L_GetSources_Skill();
	
	TArray<FOmegaAttributeModifier> CachedAttributeModValues;
	
	UPROPERTY() UEnhancedInputComponent* OwnerInputComp;
	UPROPERTY() APawn* ref_OwnerPawn;
	UPROPERTY() TArray<AOmegaAbility*> abilities_granted;
	UPROPERTY() TArray<UCombatantComponent*> target_list;
	UPROPERTY() UCombatantComponent* target_active;
	
public:	
	
	// type: 0=attribute | 1=skill | 2=damage
	TArray<UObject*> L_AppendModifiers(TArray<UObject*> current, TArray<UObject*> to_append,uint8 type, FOmegaCombatantModifierToggles toggles);
	// type: 0=attribute | 1=skill | 2=damage
	TArray<UObject*> L_GetModifierOfType(uint8 type);
	
	UCombatantComponent();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetColor_Implementation(FGameplayTag Tag, FLinearColor& Color) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override; 
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return CombatantTags; };
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- Delegates -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	
	UPROPERTY(BlueprintAssignable) FOnDamaged OnDamaged;
	UPROPERTY(BlueprintAssignable) FOnFactionChanged OnFactionChanged;
	UPROPERTY(BlueprintAssignable) FOnCombatantDataAssetChanged OnDataAssetChanged;
	UPROPERTY(BlueprintAssignable) FOnTargetAdded OnTargetAdded;
	UPROPERTY(BlueprintAssignable) FOnAddedAsTarget OnAddedAsTarget;
	UPROPERTY(BlueprintAssignable) FOnActiveTargetChanged OnActiveTargetChanged;
	UPROPERTY(BlueprintAssignable) FOnCombatantNotify OnCombatantNotify;
	
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- UPROPERTY -- 
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	
	// ------------------------------------------------------------------------------------------
	// Entity
	// ------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere,Category="Combatant",meta=(EditCondition="!use_entity_id")) FOmegaEntity entity_data;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Combatant") bool use_entity_id;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") FOmegaEntityID entity_id;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") FOmegaCombatantModifierToggles ModiferToggle_Equipment;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") FOmegaCombatantModifierToggles ModiferToggle_Inventory;
	
	FOmegaEntity* L_GetEntityData();
	FOmegaEntity_AssetData* L_GetEntity_AssetData(UPrimaryDataAsset* asset);
	TArray<UPrimaryDataAsset*> L_GetEntity_AssetsSaved();
	
	// ------------------------------------------------------------------------------------------
	// Sources
	// ------------------------------------------------------------------------------------------
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
	
	UPROPERTY(EditAnywhere, Category = "Combatant",DisplayName="🤜Abilities Granted")
	TArray<TSubclassOf<AOmegaAbility>>GrantedAbilities;
	
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
	
	// ------------------------------------------------------------------------------------------
	// ATTRIBUTES
	// ------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void InitializeAttributes();
	
	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (AdvancedDisplay = "Instigator, Context, DamageType, Hit"))
	float ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UCombatantComponent* Instigator, UObject* Context, UOmegaDamageType* DamageType, FHitResult Hit);
	
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Value")
		void GetAttributeValue(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Base Value")
		float GetAttributeBaseValue(UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Percentage")
		float GetAttributePercentage(class UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Map Values")
		TMap<UOmegaAttribute*, float> GetCurrentAttributeValues(bool bCurrent=true);
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Attribute Level")
		int32 GetAttributeLevel(UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Adjust Value by Modifiers")
		float AdjustAttributeValueByModifiers(UOmegaAttribute* Attribute, TArray<FOmegaAttributeModifier> Modifiers);
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Compared Value")
		float GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") void ChangeAttributeSet(UOmegaAttributeSet* NewSet,bool Reinitialize);

	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetOverrideMaxAttribute(UOmegaAttribute* Attribute, float Value);
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetOverrideMaxAttributes(TMap<UOmegaAttribute*, float> Values);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCurrentAttributeValue(UOmegaAttribute* Attribute, float Value);
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCombatantLevel(int32 NewLevel, bool ReinitializeStats);
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetAttributeValueCategory(FGameplayTag CategoryTag, bool bReinitialize);
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") TArray<FOmegaAttributeModifier> GetAllModifierValues();
	
	UFUNCTION(BlueprintCallable, Category = "Attributes") const TArray<UObject*> GetAttributeModifiers();
	
	// ------------------------------------------------------------------------------------------
	// FACTION
	// ------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable,Category="Faction") void SetFaction_Asset(UOmegaFaction* Faction);
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Name")) FText GetFactionName();
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Color")) FLinearColor GetFactionColor();
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Tag")) FGameplayTag GetFactionTag();
	UFUNCTION(BlueprintPure, Category="Faction") TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> GetFactionAffinities();
	
	UFUNCTION(BlueprintPure, Category="Faction") EFactionAffinity GetAffinityToCombatant(UCombatantComponent* CheckedCombatant);
	UFUNCTION(BlueprintPure, Category="Faction") TArray<UCombatantComponent*> FilterCombatantsByAffinity(TArray<UCombatantComponent*> Combatants, EFactionAffinity Affinity, bool bExclude);
	
	// ------------------------------------------------------------------------------------------
	// SKILLS
	// ------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category="Skills",DisplayName="Skills - Get All") TArray<UPrimaryDataAsset*> GetAllSkills();
	UFUNCTION(BlueprintCallable, Category="Skills",DisplayName="Skills - Add") void AddSkill(UPrimaryDataAsset* Skill, bool Added);
	UFUNCTION(BlueprintCallable, Category="Skills",DisplayName="Skills - Add (List)") void AddSkills(TArray<UPrimaryDataAsset*> skill_list, bool Added);

	// ------------------------------------------------------------------------------------------
	// TAGS
	// ------------------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "Combatant|Tags") void SetCombatantTagsActive(FGameplayTagContainer GameplayTags,bool TagsActive);
	UFUNCTION(BlueprintCallable, Category = "Combatant|Tags",DisplayName="Entity - Set Tags Active") void SetTagsActive(FGameplayTagContainer GameplayTags,bool TagsActive);
	
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags") FGameplayTagContainer GetCombatantTags();
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags") bool CombatantHasTag(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags,", meta=(AdvancedDisplay = "Exact")) 	bool CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact=true) const;
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags", meta=(AdvancedDisplay = "Exact")) bool CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact=true) const;
	
	// ------------------------------------------------------------------------------------------
	// ABILITIES
	// ------------------------------------------------------------------------------------------
	
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
	
	// ------------------------------------------------------------------------------------------
	// EFFECTS
	// ------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintPure, Category="Effects", meta=(DeterminesOutputType="EffectClass"))
	AOmegaGameplayEffect* GetEffectOfContext(UObject* Context, TSubclassOf<AOmegaGameplayEffect> EffectClass);

	UFUNCTION(BlueprintCallable, Category = "Effects", meta=(AdvancedDisplay="AddedTags, Location"))
	class AOmegaGameplayEffect* CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass,UCombatantComponent* Instigator=nullptr, UObject* Context=nullptr, FOmegaCommonMeta meta=FOmegaCommonMeta());
	
	UFUNCTION(BlueprintCallable, Category = "Effects") void RemoveEffectsWithTags(FGameplayTagContainer EffectTags);
	
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetAllEffects();
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetEffectsWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetEffectsOfCategory(FGameplayTag CategoryTag);
	UFUNCTION(BlueprintPure, Category = "Effects") bool HasEffectWithTags(FGameplayTagContainer Tags);
	UFUNCTION(BlueprintPure, Category = "Effects") AOmegaGameplayEffect* GetActiveEffectOfClass(TSubclassOf<AOmegaGameplayEffect> EffectClass, bool& bIsValid);

	// ------------------------------------------------------------------------------------------
	// TARGETING
	// ------------------------------------------------------------------------------------------
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
	
	// ------------------------------------------------------------------------------------------
	// Gambit
	// ------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunDefaultGambit();
	
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunGambit(UCombatantGambitAsset* Gambit, bool bReplaceDefaultGambit=false);

	UFUNCTION(BlueprintPure, Category="Gambit")
	bool GetActionDataFromGambit(UCombatantGambitAsset* Gambit, TSubclassOf<AOmegaAbility>& Ability, UObject*& Context);
	
	// ------------------------------------------------------------------------------------------
	// EQUIPMENT
	// ------------------------------------------------------------------------------------------
	UPROPERTY(BlueprintAssignable) FOnCombatant_EquipChange OnSlot_Equip;
	UPROPERTY(BlueprintAssignable) FOnCombatant_EquipChange OnSlot_Unequip;
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Equipment",DisplayName="Equipment - Set in Slot") 
	void Equipment_SetInSlot(UPrimaryDataAsset* Item,UEquipmentSlot* Slot);
	UFUNCTION(BlueprintCallable, Category="Combatant|Equipment",DisplayName="Equipment - Set ALL") 
    void Equipment_SetAll(TMap<UEquipmentSlot*, UPrimaryDataAsset*> equipment);
	UFUNCTION(BlueprintCallable, Category="Combatant|Equipment",DisplayName="Equipment - Clear Slot") 
	void Equipment_ClearSlot(UEquipmentSlot* Slot);
	
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Get (In Slot)") 
	UPrimaryDataAsset* Equipment_GetInSlot(UEquipmentSlot* Slot, bool& result);
	
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Get (All)")  
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> Equipment_Get();
	
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Get (EquipList)")  
	TArray<UPrimaryDataAsset*> Equipment_GetEquipList();
	
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Can Set in Slot?") 
	bool Equipment_CanSetInSlot(UPrimaryDataAsset* Item,UEquipmentSlot* Slot);
	
	// ------------------------------------------------------------------------------------------
	// INVENTORY
	// ------------------------------------------------------------------------------------------
	UPROPERTY(BlueprintAssignable) FOnCombatant_InventoryEdit OnInventoryEdit;
	
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Give Item")
	bool Inventory_Add(UPrimaryDataAsset* Item, int32 amount);
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Give Item (List)")
	void Inventory_AddList(TMap<UPrimaryDataAsset*, int32> Assets,bool bInvertAmount=false);
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Transfer Item")
	void Inventory_Transfer(UCombatantComponent* To, UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll);
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Transfer ALL")
	void Inventory_TransferAll(UCombatantComponent* To);
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Set")
	void Inventory_Set(TMap<UPrimaryDataAsset*,int32> map,bool bClearFirst=true);
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Clear")
	void Inventory_Clear();
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get")
	TMap<UPrimaryDataAsset*,int32> Inventory_Get(int32 Minimum=1);
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get Amount")
	int32 Inventory_GetAmount(UPrimaryDataAsset* Item);
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get (All as Array)")
	TArray<UPrimaryDataAsset*> Inventory_GetItemsAsArray();
	
	//Checks if the collection has enough of each given type of asset;
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Has Minimum?")
	bool Inventory_HasMinimum(TMap<UPrimaryDataAsset*, int32> Assets);
	
	// ------------------------------------------------------------------------------------------
	// LEVELING
	// ------------------------------------------------------------------------------------------
	UPROPERTY(BlueprintAssignable) FOnCombatant_XpChange OnXpChanged;
	UPROPERTY(BlueprintAssignable) FOnCombatant_LevelChange OnLevelChanged;
	
	UFUNCTION(BlueprintCallable, Category="Combatant|XP",DisplayName="XP - Set") void XP_Set(UOmegaLevelingAsset* Type, float amount, bool bAdded=true);
	
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="XP - Get All") TMap<UOmegaLevelingAsset*,float> XP_GetAll();
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="XP - Get") float XP_Get(UOmegaLevelingAsset* Type);
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="XP - Get Values") void XP_GetValues(UOmegaLevelingAsset* Type, float& LevelMin,float& LevelMax,float& Percent);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|XP",DisplayName="Level - Set") void XP_SetLevel(UOmegaLevelingAsset* Type, int32 NewLevel);
	
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="Level - Get") int32 XP_GetLevel(UOmegaLevelingAsset* Type);
	
	// ------------------------------------------------------------------------------------------
	// Asset Tags
	// ------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category="Combatant|AssetLink",DisplayName="Asset Link - Remove All Tags")
	void AssetLink_RemoveAllTags(UPrimaryDataAsset* Asset);
	
	UFUNCTION(BlueprintCallable, Category="Combatant|AssetLink",DisplayName="Asset Link - Set Tags Active")
	void AssetLink_SetTagsActive(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bTagsActive);
	
	UFUNCTION(BlueprintPure, Category="Combatant|AssetLink",DisplayName="Asset Link - Set Tags Active")
	FGameplayTagContainer AssetLink_GetActiveTags(UPrimaryDataAsset* Asset);
	
	// ------------------------------------------------------------------------------------------
	// PARAM
	// ------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category="Entity|Param",DisplayName="Param (Bool) - Set") void EntityParam_Bool_Set(FName Param, bool Value);
	UFUNCTION(BlueprintPure, Category="Entity|Param",DisplayName="Param (Bool) - Get") bool EntityParam_Bool_Get(FName Param);
	
	UFUNCTION(BlueprintCallable, Category="Entity|Param",DisplayName="Param (Int32) - Set") void EntityParam_Int_Set(FName Param, int32 Value, bool bAdded);
	UFUNCTION(BlueprintPure, Category="Entity|Param",DisplayName="Param (Int32) - Get") int32 EntityParam_Int_Get(FName Param);
};