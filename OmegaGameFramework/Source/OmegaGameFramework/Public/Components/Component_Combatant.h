// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaComponent.h"

#include "Interfaces/I_Common.h"
#include "Interfaces/I_Skill.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Components/ActorComponent.h"
#include "Interfaces/I_Combatant.h"
#include "DataAssets/DA_Attribute.h"
#include "Functions/F_PropertyBag.h"
#include "Functions/F_TagEvent.h"
#include "Interfaces/I_StandardInput.h"
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
class UOmegaGambit_Asset;

class UInputComponent;
class UEnhancedInputComponent;
class UInputAction;

/// DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatantDelegate, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UCombatantComponent*, Instigator, UOmegaDamageType*, DamageType, FHitResult, Hit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatantDataAssetChanged, UCombatantComponent*, Combatant, UPrimaryDataAsset*, NewAsset,UPrimaryDataAsset*, OldAsset);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFactionChanged, UCombatantComponent*, component, UOmegaFaction*, NewFaction, UOmegaFaction*, OldFaction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTargetAdded, UCombatantComponent*, component, UCombatantComponent*, Target, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAddedAsTarget, UCombatantComponent*, component, UCombatantComponent*, Instigator, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveTargetChanged, UCombatantComponent*, ActiveTarget, bool, Valid);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatantNotify, UCombatantComponent*, Combatant, FName, Notify, const FString&, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCombatantSkillEdit, UCombatantComponent*, Combatant, UPrimaryDataAsset*, Skill, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatant_InventoryEdit, UCombatantComponent*, Combatant, UPrimaryDataAsset*, Item, int32, AmountChanged);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatant_EquipChange, UCombatantComponent*, Combatant, UEquipmentSlot*, Slot, UPrimaryDataAsset*, Item);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCombatant_XpChange, UCombatantComponent*, Combatant, UOmegaLevelingAsset*, Type, float, old_xp,float, new_xp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCombatant_LevelChange, UCombatantComponent*, Combatant, UOmegaLevelingAsset*, Type, int32, old_level,int32, new_level);


#define  UFUNC_EQUIP_C(Name) UFUNCTION(BlueprintCallable, Category="Equipment", DisplayName="Equipment - ")
#define  UFUNC_EQUIP_P(Name) UFUNCTION(BlueprintPure, Category="Equipment", DisplayName="Equipment - ")



#define PrintError(ErrorText) \
	(GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, ErrorText))

// The core RPG/combat component. Manages attributes, abilities, effects, skills, inventory, equipment, faction, targeting, leveling, and AI gambit selection.
UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), CollapseCategories )
class OMEGAGAMEFRAMEWORK_API UCombatantComponent : public UOmegaComponent, public IDataInterface_Combatant, public IActorTagEventInterface,
																			public IDataInterface_General, public IDataInterface_InputAction
{
	GENERATED_BODY()

	float L_ModifyDamage(UOmegaAttribute* Attribute,UCombatantComponent* Instigator,float BaseDamage,UOmegaDamageType* DamageType,UObject* Context);
	void L_CacheAttributeMods();
	float L_GetAllModsOfAttribute(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute);

	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;

	TArray<FOmegaAttributeModifier> CachedAttributeModValues;

	UPROPERTY() UEnhancedInputComponent* OwnerInputComp;
	UPROPERTY() APawn* ref_OwnerPawn;
	UPROPERTY() TArray<AOmegaAbility*> abilities_granted;
	UPROPERTY() TArray<UCombatantComponent*> target_list;
	UPROPERTY() UCombatantComponent* target_active;

public:

	TArray<UObject*> GetAllModifiers();

	UCombatantComponent();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override { OutGameplayTags = CombatantTags; };
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;

	virtual void OnInputAction_Begin_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis) override;
	virtual void OnInputAction_Update_Implementation(APlayerController* Player, FGameplayTag Action, float DeltaTime, FVector axis) override;
	virtual	void OnInputAction_End_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis) override;
	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- Delegates --
	//----------------------------------------------------------------------------------------------------------------------------------------------//

	// Fires when this combatant takes attribute damage.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnDamaged OnDamaged;
	// Fires when this combatant's faction changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnFactionChanged OnFactionChanged;
	// Fires when the source data asset assigned to this combatant changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatantDataAssetChanged OnDataAssetChanged;
	// Fires when a combatant is added to or removed from this combatant's target list.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnTargetAdded OnTargetAdded;
	// Fires when this combatant is added to or removed from another combatant's target list.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnAddedAsTarget OnAddedAsTarget;
	// Fires when the active target changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnActiveTargetChanged OnActiveTargetChanged;
	// Fires when CombatantNotify is called on this combatant.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatantNotify OnCombatantNotify;

	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- UPROPERTY --
	//----------------------------------------------------------------------------------------------------------------------------------------------//

	/// ------ COMBATANT ----------
	// Optional data asset that seeds this combatant's name, icon, and stats.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category = "💪Combatant")
	UPrimaryDataAsset* CombatantDataAsset=nullptr;

	// Gameplay tags that describe this combatant's current state (e.g. "Status.Poisoned").
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "💪Combatant")
	FGameplayTagContainer CombatantTags;

	// The faction this combatant belongs to, used for affinity/targeting logic.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "💪Combatant",DisplayName="Faction")
	UOmegaFaction* FactionDataAsset;

	// General-purpose property bag for storing arbitrary combatant data in Blueprint.
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "💪Combatant",AdvancedDisplay)
	FOmegaPropertyBagWrapper PropertyBag;

	// Ability classes automatically granted to this combatant at BeginPlay.
	UPROPERTY(EditAnywhere, Category = "💪Combatant",DisplayName="🤜Abilities Granted")
	TArray<TSubclassOf<AOmegaAbility>>GrantedAbilities;

	/// ------ FLAGS ----------

	// When true, the combatant's active skills list is also treated as a master modifier source.
	UPROPERTY(EditAnywhere, Category = "💪Combatant - Flags")
	bool bUseSkillsAsMasterSource=true;

	// Only reruns attribute modifier call when attribute modifiers source list changes.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="💪Combatant - Flags")
	bool bCacheAttributeModifierValues=false;

	/// ------ Attributes ----------

	// When false, ApplyAttributeDamage calls are ignored and no damage is applied.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="💪Combatant - Attributes", AdvancedDisplay)
	bool bCanDamageAttributes = true;

	// The set of attributes (HP, MP, etc.) this combatant uses.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "💪Combatant - Attributes")
	UOmegaAttributeSet* AttributeSet;

	// The combatant's current level, used to scale attribute base values from the attribute set.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "💪Combatant - Attributes")
	int32 Level = 1;

	// Tag category that selects which value row to read from the attribute set at this level.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "💪Combatant - Attributes", AdvancedDisplay)
	FGameplayTag AttributeValueCategory;

	// Forcibly Override whatever the max attributes values found in the "AttributeSet"
	UPROPERTY(EditAnywhere, Category = "💪Combatant - Attributes")
	TMap<UOmegaAttribute*, float>  OverrideMaxAttributes;

	// Per-attribute level overrides; lets individual attributes scale at a different level than the combatant level.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "💪Combatant - Attributes", AdvancedDisplay)
	TMap<UOmegaAttribute*, int32> AttributeLevels;


	// ------------------------------------------------------------------------------------------
	// Entity
	// ------------------------------------------------------------------------------------------
	// Forces the combatant's entity data to the provided value, bypassing normal assignment flow.
	UFUNCTION(BlueprintCallable,Category="💪Combatant") void ForceSetEntityData(FOmegaEntity data);
	// Returns the active entity data for this combatant (from inline data or the entity ID lookup).
	UFUNCTION(BlueprintPure,Category="💪Combatant") FOmegaEntity GetEntityData();
	
	UFUNCTION(BlueprintCallable,Category="💪Combatant") bool SetEntityOverrideSource(UCombatantComponent* ComponentSource);
	
	UPROPERTY(VisibleAnywhere,Category="💪Combatant - Data",meta=(EditCondition="!use_entity_id")) UCombatantComponent* EntityOverrideSource;
	
	// Inline entity data used when use_entity_id is false.
	UPROPERTY(EditAnywhere,Category="💪Combatant - Data",meta=(EditCondition="!use_entity_id")) FOmegaEntity entity_data;
	// When true, entity data is loaded from the save system via entity_id instead of using inline data.
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="💪Combatant - Data") bool use_entity_id;
	// The entity ID used to look up saved entity data when use_entity_id is true.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="💪Combatant - Data",meta=(EditCondition="use_entity_id")) FOmegaEntityID entity_id;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="💪Combatant - Modifiers")
	bool bUseEquipmentAsModifiers=true;


	FOmegaEntity* L_GetEntityData();
	FOmegaEntity_AssetData* L_GetEntity_AssetData(UPrimaryDataAsset* asset);
	TArray<UPrimaryDataAsset*> L_GetEntity_AssetsSaved();

	// ------------------------------------------------------------------------------------------
	// Sources
	// ------------------------------------------------------------------------------------------
	// All active master modifier sources (drives which attribute, skill, and damage sources are considered).
	UPROPERTY(VisibleInstanceOnly,Category="💪Combatant - Modifiers") TArray<UObject*> SOURCES_Master;
	
	// ------------------------------------------------------------------------------------------
	// Ability Skel Mesh
	// ------------------------------------------------------------------------------------------
	// When set, abilities will use this skeletal mesh component instead of auto-detecting one from the owner.
	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	USkeletalMeshComponent* Override_AbilitySkelMesh;

	// Overrides the SkeletalMeshComponent that Abilities will try to use. (Input can be left blank to remove override.)
	UFUNCTION(BlueprintCallable, Category="Abilities")
	void SetOverrideAbilitySkelMesh(USkeletalMeshComponent* mesh);

	//----------------------------------------------------------------------------------------------------------------------------------------------//
	// -- UFUNCTION --
	//----------------------------------------------------------------------------------------------------------------------------------------------//

	/// ------ COMBATANT ----------

	// should only be used MOMENTARILY for things like preventing a looped Update() call, then index should be removed
	TArray<int32> blockUpdateCall;

	// Refreshes all visible combatnat related values, primarily in widgets.
	UFUNCTION(BlueprintCallable, Category = "Combatant", DisplayName="Refresh") void Update();
	// Generic Update delgate fired on Attribute Modificaton, effect change, or modifer source change
	UPROPERTY(BlueprintAssignable, Category="Omega") FCombatantDelegate OnUpdated;

	// Returns the owning actor cast to APawn, or null if the owner is not a pawn.
	UFUNCTION(BlueprintPure, Category="Combatant") APawn* GetOwnerPawn() const;
	// Returns the player controller possessing the owning pawn, or null if none.
	UFUNCTION(BlueprintPure, Category="Combatant") APlayerController* GetOwnerPlayerController() const;

	// Sets the primary data asset that identifies this combatant (name, icon, etc.).
	UFUNCTION(BlueprintCallable,Category="Combatant")
	void SetSourceDataAsset(UPrimaryDataAsset* DataAsset);
	// Returns the primary data asset currently assigned to this combatant.
	UFUNCTION(BlueprintPure,Category="Combatant")
	UPrimaryDataAsset* GetSourceDataAsset() const;

	/// ------ DataSources ----------

	// Adds or removes Source from the master modifier pool, which drives all other source types.
	UFUNCTION(BlueprintCallable, Category = "DataSource", DisplayName="Set Source Active (MASTER)")
	void SetMasterDataSourceActive(UObject* Source, bool bActive);

	// ------------------------------------------------------------------------------------------
	// ATTRIBUTES
	// ------------------------------------------------------------------------------------------

	// Reads the attribute set and level to populate initial current attribute values.
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void InitializeAttributes();

	// Applies BaseDamage to Attribute, applying modifiers and clamping to valid range. Returns the final damage dealt.
	UFUNCTION(BlueprintCallable, Category = "Attributes", meta = (AdvancedDisplay = "Instigator, Context, DamageType, Hit"))
	float ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UCombatantComponent* Instigator, UObject* Context, UOmegaDamageType* DamageType, FHitResult Hit);

	// Returns the current and maximum values of Attribute on this combatant.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Value")
		void GetAttributeValue(class UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue);
	// Returns the raw base (unmodified) value of Attribute at the current level.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Base Value")
		float GetAttributeBaseValue(UOmegaAttribute* Attribute);
	// Returns the current value of Attribute as a 0–1 fraction of its maximum.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Percentage")
		float GetAttributePercentage(class UOmegaAttribute* Attribute);
	// Returns a map of all attributes to their current (or maximum, if bCurrent=false) values.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Map Values")
		TMap<UOmegaAttribute*, float> GetCurrentAttributeValues(bool bCurrent=true);
	// Returns the effective level used when computing Attribute's value from the attribute set curve.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Attribute Level")
		int32 GetAttributeLevel(UOmegaAttribute* Attribute);
	// Applies the supplied modifier list to a base value and returns the adjusted result.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Adjust Value by Modifiers")
		float AdjustAttributeValueByModifiers(UOmegaAttribute* Attribute, TArray<FOmegaAttributeModifier> Modifiers);
	// Returns what Attribute's value would be if the supplied modifier objects were applied.
	UFUNCTION(BlueprintPure, Category = "Attributes",DisplayName="Attribute - Get Compared Value")
		float GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers);

	// Replaces the active attribute set. Pass Reinitialize=true to recalculate all current values immediately.
	UFUNCTION(BlueprintCallable, Category = "Attributes") void ChangeAttributeSet(UOmegaAttributeSet* NewSet,bool Reinitialize);

	// Overrides the maximum value of a single attribute, ignoring the attribute set's value.
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetOverrideMaxAttribute(UOmegaAttribute* Attribute, float Value);
	// Replaces all override-max values at once.
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetOverrideMaxAttributes(TMap<UOmegaAttribute*, float> Values);

	// Directly sets the current (bar) value of Attribute, clamped to [0, max].
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCurrentAttributeValue(UOmegaAttribute* Attribute, float Value);
	// Directly sets current values for all provided attributes.
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values);

	// Sets the combatant's level and optionally re-initializes all attribute values.
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetCombatantLevel(int32 NewLevel, bool ReinitializeStats);
	// Sets the value category tag (selects an attribute set row) and optionally re-initializes.
	UFUNCTION(BlueprintCallable, Category = "Attributes") void SetAttributeValueCategory(FGameplayTag CategoryTag, bool bReinitialize);

	// Returns the combined attribute modifier list from all active modifier sources.
	UFUNCTION(BlueprintCallable, Category = "Attributes") TArray<FOmegaAttributeModifier> GetAllModifierValues();

	// Returns all currently active attribute modifier source objects.
	UFUNCTION(BlueprintCallable, Category = "Attributes") const TArray<UObject*> GetAttributeModifiers();

	// Use for situations such as when comparing equipment stats
	UFUNCTION(BlueprintCallable, Category = "DataSource",DisplayName="Attribute Modifiers - Compare Objects (All Attributes)")
	TArray<FOmegaAttributeModifier> CompareObjectAttributeModifiers(UObject* Compared, UObject* Uncompared);

	// Returns the old and new values of a single attribute when swapping from Uncompared to Compared as an active modifier.
	UFUNCTION(BlueprintCallable, Category = "DataSource",DisplayName="Attribute Modifiers - Compare Objects (One Attribute)")
	void CompareObjectAttributeModifiers_Single(UOmegaAttribute* Attribute, UObject* Compared, UObject* Uncompared,
		float& oldValue,float& newValue);

	// ------------------------------------------------------------------------------------------
	// DAMAGE TYPE
	// ------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure, Category = "DamageTypes")
	UPrimaryDataAsset* GetDamageTypeWeight(UOmegaDamageType* DamageType, float& Total,float& Average);
	
	// ------------------------------------------------------------------------------------------
	// FACTION
	// ------------------------------------------------------------------------------------------

	// Sets the faction data asset, updating affinity relationships.
	UFUNCTION(BlueprintCallable,Category="Faction") void SetFaction_Asset(UOmegaFaction* Faction);
	// Returns the display name of this combatant's faction.
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Name")) FText GetFactionName();
	// Returns the color associated with this combatant's faction.
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Color")) FLinearColor GetFactionColor();
	// Returns the gameplay tag that identifies this combatant's faction.
	UFUNCTION(BlueprintPure, Category="Faction", meta=(CompactNodeTitle="Faction Tag")) FGameplayTag GetFactionTag();
	// Returns the map of faction tags to affinity values defined on this combatant's faction.
	UFUNCTION(BlueprintPure, Category="Faction") TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> GetFactionAffinities();

	// Returns the affinity (Friendly/Neutral/Hostile) this combatant has toward CheckedCombatant.
	UFUNCTION(BlueprintPure, Category="Faction") EFactionAffinity GetAffinityToCombatant(UCombatantComponent* CheckedCombatant);
	// Filters the list to combatants that have (or don't have, if bExclude) the given affinity toward this combatant.
	UFUNCTION(BlueprintPure, Category="Faction") TArray<UCombatantComponent*> FilterCombatantsByAffinity(TArray<UCombatantComponent*> Combatants, EFactionAffinity Affinity, bool bExclude);

	// ------------------------------------------------------------------------------------------
	// SKILLS
	// ------------------------------------------------------------------------------------------
	UPROPERTY(BlueprintAssignable, Category="Omega") FCombatantSkillEdit OnSkillsEdited;
	
	TArray<UPrimaryDataAsset*> GetSkills_FromSourceList(TArray<UObject*> SourceList);
	// Returns true if Skill is in this combatant's active skill list.
	UFUNCTION(BlueprintPure, Category="Skills",DisplayName="Skills - Owned?") bool HasSkill(UPrimaryDataAsset* Skill);
	// Returns all skills currently available to this combatant from all skill sources.
	UFUNCTION(BlueprintCallable, Category="Skills",DisplayName="Skills - Get All") TArray<UPrimaryDataAsset*> GetAllSkills();
	// Adds or removes Skill from the combatant's inline skill list.
	UFUNCTION(BlueprintCallable, Category="Skills",DisplayName="Skills - Add") void AddSkill(UPrimaryDataAsset* Skill, bool Added);
	// Adds or removes a list of skills from the combatant's inline skill list.
	UFUNCTION(BlueprintCallable, Category="Skills",DisplayName="Skills - Add (List)") void AddSkills(TArray<UPrimaryDataAsset*> skill_list, bool Added);
	
	// ------------------------------------------------------------------------------------------
	// TAGS
	// ------------------------------------------------------------------------------------------

	// Adds or removes GameplayTags from the combatant's tag container.
	UFUNCTION(BlueprintCallable, Category = "Combatant|Tags") void SetCombatantTagsActive(FGameplayTagContainer GameplayTags,bool TagsActive);
	// Adds or removes tags from the combatant's entity data tag container (saved to entity).
	UFUNCTION(BlueprintCallable, Category = "Combatant|Tags",DisplayName="Entity - Set Tags Active") void SetTagsActive(FGameplayTagContainer GameplayTags,bool TagsActive);
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags",DisplayName="Entity - Get Tags Active") FGameplayTagContainer GetTagsActive();

	// Returns the full gameplay tag container on this combatant.
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags") FGameplayTagContainer GetCombatantTags();
	// Returns true if this combatant has the exact tag.
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags") bool CombatantHasTag(FGameplayTag Tag) const;
	// Returns true if this combatant has any tag in the container (Exact controls parent-tag matching).
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags,", meta=(AdvancedDisplay = "Exact")) 	bool CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact=true) const;
	// Returns true if this combatant has all tags in the container (Exact controls parent-tag matching).
	UFUNCTION(BlueprintPure, Category = "Combatant|Tags", meta=(AdvancedDisplay = "Exact")) bool CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact=true) const;

	// ------------------------------------------------------------------------------------------
	// ABILITIES
	// ------------------------------------------------------------------------------------------

	// Grants or revokes the specified ability class on this combatant. Returns true on success.
	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool SetAbilityGranted(TSubclassOf<AOmegaAbility> AbilityClass, bool Granted);

	// Grants or revokes a list of ability classes in one call.
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetAbilitiesGranted(TArray<TSubclassOf<AOmegaAbility>> AbilityClass, bool Granted);

	// When true, no abilities can be executed on this combatant.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability") bool bAbilitiesDisabled;

	// Sets whether all abilities are blocked from activating on this combatant.
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetAbilitiesDisabled(bool bDisabled);

	// Returns the active instance of AbilityClass if it is currently granted, along with a success bool.
	UFUNCTION(BlueprintPure, Category = "Ability", meta=(DeterminesOutputType="AbilityClass"))
	AOmegaAbility* GetAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool& bSuccess);

	// Executes (activates) the ability of AbilityClass with an optional context object. Returns the ability instance.
	UFUNCTION(BlueprintCallable, Category = "Ability", meta = (AdvancedDisplay = "Context", DisplayName="Activate Ability"))
	AOmegaAbility* ExecuteAbility(class TSubclassOf<AOmegaAbility> AbilityClass, class UObject* Context, FOmegaCombatantEventMeta meta, bool& bSuccess);

	// Stops the ability of AbilityClass. Pass Cancel=true to treat it as a cancel instead of a normal end.
	UFUNCTION(BlueprintCallable, Category = "Ability") bool StopAbility(class TSubclassOf<AOmegaAbility> AbilityClass, bool Cancel);
	// Cancels all active abilities whose tags match the given container.
	UFUNCTION(BlueprintCallable, Category = "Ability") void CancelAbilitiesWithTags(FGameplayTagContainer Tags);
	// Cancels all currently active abilities on this combatant.
	UFUNCTION(BlueprintCallable, Category = "Ability") void CancelAllAbilities();

	// Returns true if an ability of AbilityClass is currently active.
	UFUNCTION(BlueprintPure, Category = "Ability") bool IsAbilityActive(class TSubclassOf<AOmegaAbility> AbilityClass);
	// Returns all currently active ability instances.
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetActiveAbilities();
	// Returns active abilities whose gameplay tags match any tag in the container.
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetActiveAbilitiesWithTags(FGameplayTagContainer Tags);
	// Returns all granted (available) ability instances regardless of active state.
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetGrantedAbilities();
	// Returns granted abilities whose gameplay tags match any tag in the container.
	UFUNCTION(BlueprintPure, Category = "Ability") TArray<AOmegaAbility*> GetGrantedAbilitiesWithTags(FGameplayTagContainer Tags);
	// Returns true if any granted ability is currently blocking the given tag container.
	UFUNCTION(BlueprintPure, Category = "Ability") bool IsAbilityTagBlocked(FGameplayTagContainer Tags);

	// Returns all active damage modifier source objects.
	UFUNCTION(BlueprintPure, Category="DamageModifiers") TArray<UObject*> GetDamageModifiers();

	// ------------------------------------------------------------------------------------------
	// EFFECTS
	// ------------------------------------------------------------------------------------------

	// When true, new gameplay effects cannot be applied to this combatant.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "💪Combatant - Effects") bool bEffectsDisabled;

	// Sets whether all incoming gameplay effects are blocked on this combatant.
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void SetEffectsDisabled(bool bDisabled);

	UFUNCTION()
	bool CanApplyEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, UCombatantComponent* Instigator, UObject* Context, FOmegaCommonMeta
	                    _meta, FOmegaCommonMeta& MetaOut);

	// Returns the active effect instance that was created with the given Context object, cast to EffectClass.
	UFUNCTION(BlueprintPure, Category="Effects", meta=(DeterminesOutputType="EffectClass"))
	AOmegaGameplayEffect* GetEffectOfContext(UObject* Context, TSubclassOf<AOmegaGameplayEffect> EffectClass);

	// Creates and applies an effect of EffectClass to this combatant, optionally from an Instigator with a Context.
	UFUNCTION(BlueprintCallable, Category = "Effects", meta=(AdvancedDisplay="AddedTags, Location"))
	class AOmegaGameplayEffect* CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass,UCombatantComponent* Instigator=nullptr, UObject* Context=nullptr, FOmegaCommonMeta meta=FOmegaCommonMeta());

	// Removes all active effects from this combatant.
	UFUNCTION(BlueprintCallable, Category = "Effects") void RemoveAllEffects();
	// Removes all active effects whose tags match any tag in EffectTags.
	UFUNCTION(BlueprintCallable, Category = "Effects") void RemoveEffectsWithTags(FGameplayTagContainer EffectTags);

	// Returns every currently active effect instance on this combatant.
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetAllEffects();
	// Returns active effects whose gameplay tags include any tag in Tags.
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetEffectsWithTags(FGameplayTagContainer Tags);
	// Returns active effects whose category tag matches CategoryTag.
	UFUNCTION(BlueprintPure, Category = "Effects") TArray<AOmegaGameplayEffect*> GetEffectsOfCategory(FGameplayTag CategoryTag);
	// Returns true if any active effect has at least one tag from Tags.
	UFUNCTION(BlueprintPure, Category = "Effects") bool HasEffectWithTags(FGameplayTagContainer Tags);
	// Returns the single active effect of the exact class EffectClass, along with a validity bool.
	UFUNCTION(BlueprintPure, Category = "Effects") AOmegaGameplayEffect* GetActiveEffectOfClass(TSubclassOf<AOmegaGameplayEffect> EffectClass, bool& bIsValid);

	// ------------------------------------------------------------------------------------------
	// TARGETING
	// ------------------------------------------------------------------------------------------
	// Adds or removes Combatant from this combatant's target registration list.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting|Register",meta=(Keywords="Add, List"))
	void SetTargetRegistered(UCombatantComponent* Combatant, bool IsRegistered);

	// Adds or removes a list of combatants from the target registration list, optionally clearing it first.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting",meta=(Keywords="Add, List"))
	void SetTargetsRegistered(TArray<UCombatantComponent*> Combatants, bool IsRegistered, bool ClearListFirst);

	// Removes all combatants from the target list.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") void ClearTargetList();
	// Sets Combatant as the single active/focused target.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") void SetActiveTarget(UCombatantComponent* Combatant);
	// Returns the active target and a validity bool. Exec pin branches on IsValid.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting",meta=(ExpandBoolAsExecs="IsValid")) UCombatantComponent* TryGetActiveTarget(bool&  IsValid);
	// Shifts the active target by Amount positions in the registered target list and returns the new target.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") UCombatantComponent* CycleActiveTarget(int32 Amount);
	// Clears the active target without modifying the target list.
	UFUNCTION(BlueprintCallable, Category="Combatant|Targeting") void ClearActiveTarget();

	// Returns the full list of registered targets.
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting") TArray<UCombatantComponent*> GetRegisteredTargetList();
	// Returns the current active target, or null if none is set.
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting") UCombatantComponent* GetActiveTarget() const;
	// Returns the index of the active target within the registered target list.
	UFUNCTION(BlueprintPure, Category="Combatant|Targeting") int32 GetActiveTargetIndex();

	/// ------ Notify ----------

	// Fires an agonist notify across the combatant that can be recieved in abilities and the parent actor.
	UFUNCTION(BlueprintCallable, Category="Notify", meta=(AdvancedDisplay="Flag")) void CombatantNotify(FName Notify, const FString& Flag);
	
	UFUNCTION(BlueprintCallable, Category="Notify")
	void FireCombatantEvent(UPARAM(meta=(Categories="EVENT.Combat")) FGameplayTag Event, FOmegaCombatantEventMeta meta);

	
	// ------------------------------------------------------------------------------------------
	// Gambit / AI
	// ------------------------------------------------------------------------------------------
	// The gambit (AI decision tree) run by default when bAutorunAbilitySelector is true.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="💪Combatant - AI ")
	UOmegaGambit_Asset* DefaultGambit;

	// When true, the combatant automatically evaluates its gambit and runs abilities each AbilitySelectorFrequency seconds.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="💪Combatant - AI ")
	bool bAutorunAbilitySelector;
	// How often (in seconds) the gambit ability selector is evaluated when bAutorunAbilitySelector is true.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="💪Combatant - AI ")
	float AbilitySelectorFrequency=0.2;
	// When true, the currently running selector ability is cancelled when a new selector choice is made.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="💪Combatant - AI ")
	bool bCancelAbilityOnSelectorChange=true;

	UPROPERTY() bool bSelectorAbilityActive;
	UPROPERTY() TSubclassOf<AOmegaAbility> SelectorActiveAbilityClass;
	UPROPERTY() float SelectorAccumulator = 0.f;

	// Evaluates all abilities in the gambit by utility score and returns the best choice with its context.
	UFUNCTION(BlueprintCallable, Category="Gambit")
	TSubclassOf<AOmegaAbility> SelectAbilityByUtility(UObject*& AbilityContext, FOmegaCombatantEventMeta meta, bool ShuffleFirst);

	// Runs DefaultGambit and executes the selected ability. Returns true if an ability was activated.
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunDefaultGambit();

	// Runs the given gambit, optionally replacing the default gambit. Returns true if an ability was activated.
	UFUNCTION(BlueprintCallable, Category="Gambit")
	bool RunGambit(UOmegaGambit_Asset* Gambit, bool bReplaceDefaultGambit=false);

	// Evaluates the gambit without executing anything and returns the chosen ability class and context.
	UFUNCTION(BlueprintPure, Category="Gambit")
	bool GetActionDataFromGambit(UOmegaGambit_Asset* Gambit, TSubclassOf<AOmegaAbility>& Ability, UObject*& Context);

	// ------------------------------------------------------------------------------------------
	// EQUIPMENT
	// ------------------------------------------------------------------------------------------
	// Fires when an item is placed into an equipment slot.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatant_EquipChange OnSlot_Equip;
	// Fires when an item is removed from an equipment slot.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatant_EquipChange OnSlot_Unequip;

	// Places Item into the specified equipment slot, replacing any existing item.
	UFUNCTION(BlueprintCallable, Category="Combatant|Equipment",DisplayName="Equipment - Set in Slot")
	void Equipment_SetInSlot(UPrimaryDataAsset* Item,UEquipmentSlot* Slot);
	// Sets the entire equipment map at once.
	UFUNCTION(BlueprintCallable, Category="Combatant|Equipment",DisplayName="Equipment - Set ALL")
    void Equipment_SetAll(TMap<UEquipmentSlot*, UPrimaryDataAsset*> equipment);
	// Removes any item from the specified equipment slot.
	UFUNCTION(BlueprintCallable, Category="Combatant|Equipment",DisplayName="Equipment - Clear Slot")
	void Equipment_ClearSlot(UEquipmentSlot* Slot);

	// Returns the item in the specified slot and whether the slot is filled.
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Get (In Slot)")
	UPrimaryDataAsset* Equipment_GetInSlot(UEquipmentSlot* Slot, bool& result);

	// Returns the full map of all equipment slots to their current items.
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Get (All)")
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> Equipment_Get();

	// Returns all equipped items as a flat array (slots with no item are excluded).
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Get (EquipList)")
	TArray<UPrimaryDataAsset*> Equipment_GetEquipList();

	// Returns true if Item can be placed in Slot (passes slot filter and any slot conditions).
	UFUNCTION(BlueprintPure, Category="Combatant|Equipment",DisplayName="Equipment - Can Set in Slot?")
	bool Equipment_CanSetInSlot(UPrimaryDataAsset* Item,UEquipmentSlot* Slot);

	// ------------------------------------------------------------------------------------------
	// INVENTORY
	// ------------------------------------------------------------------------------------------
	// Fires whenever an item quantity changes in this combatant's inventory.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatant_InventoryEdit OnInventoryEdit;

	// Adds or removes the given amount of Item from the inventory. Returns true if the operation succeeded.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Give Item")
	bool Inventory_Add(UPrimaryDataAsset* Item, int32 amount);
	// Adds or removes multiple items at once; set bInvertAmount to remove instead of add.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Give Item (List)")
	void Inventory_AddList(TMap<UPrimaryDataAsset*, int32> Assets,bool bInvertAmount=false);
	// Transfers Amount of Asset from this inventory to the To combatant. Pass bTransferAll to move the entire stack.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Transfer Item")
	void Inventory_Transfer(UCombatantComponent* To, UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll);
	// Transfers every item in this inventory to the To combatant.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Transfer ALL")
	void Inventory_TransferAll(UCombatantComponent* To);
	// Replaces the inventory with the provided map; pass bClearFirst to wipe existing contents first.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Set")
	void Inventory_Set(TMap<UPrimaryDataAsset*,int32> map,bool bClearFirst=true);
	// Removes all items from the inventory.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Clear")
	void Inventory_Clear();
	// Returns the inventory as a map of item to quantity; items below Minimum are excluded.
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get")
	TMap<UPrimaryDataAsset*,int32> Inventory_Get(int32 Minimum=1);
	// Returns the quantity of Item currently held in the inventory.
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get Amount")
	int32 Inventory_GetAmount(UPrimaryDataAsset* Item);
	// Returns all held items as a flat array (one entry per unique item, regardless of quantity).
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get (All as Array)")
	TArray<UPrimaryDataAsset*> Inventory_GetItemsAsArray();

	// Checks if the collection has enough of each given type of asset;
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Has Minimum?")
	bool Inventory_HasMinimum(TMap<UPrimaryDataAsset*, int32> Assets);

	// Per-item quantity cap overrides; items not listed use the cap defined in their data asset.
	UPROPERTY(EditAnywhere,Category="💪Combatant - Data",AdvancedDisplay)
	TMap<UPrimaryDataAsset*,int32> InventoryMaxOverrides;

	// Sets (or adds to) the max-quantity override for a single item.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Override Max (One)")
	void Inventory_OverrideMax(UPrimaryDataAsset* Item, int32 Max, bool bAdd=false);
	// Replaces all max-quantity overrides at once.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Override Max (List)")
	void Inventory_OverrideMaxList(TMap<UPrimaryDataAsset*,int32> max);
	// Removes the max-quantity override for a single item, restoring the asset-defined cap.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Clear Override Max (One)")
	void Inventory_OverrideMaxClear(UPrimaryDataAsset* Asset);
	// Removes all max-quantity overrides, restoring asset-defined caps for all items.
	UFUNCTION(BlueprintCallable, Category="Combatant|Inventory",DisplayName="Inventory - Clear Override Max (All)")
	void Inventory_OverrideMaxClearAll();
	// Returns the effective max quantity for Item, considering overrides and asset-defined limits.
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get Item Max")
	int32 Inventory_GetMax(UPrimaryDataAsset* Item);
	// Returns how full the Item's stack is as a 0–1 fraction relative to its effective max.
	UFUNCTION(BlueprintPure, Category="Combatant|Inventory",DisplayName="Inventory - Get Percent to Max")
	float Inventory_GetPercent(UPrimaryDataAsset* Item);

	// ------------------------------------------------------------------------------------------
	// LEVELING
	// ------------------------------------------------------------------------------------------
	// Fires when XP for any leveling type changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatant_XpChange OnXpChanged;
	// Fires when the level for any leveling type changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCombatant_LevelChange OnLevelChanged;

	// Sets (or adds to) the XP for the given leveling type.
	UFUNCTION(BlueprintCallable, Category="Combatant|XP",DisplayName="XP - Set") void XP_Set(UOmegaLevelingAsset* Type, float amount, bool bAdded=true);
	// Sets (or adds to) XP for multiple leveling types at once.
	UFUNCTION(BlueprintCallable, Category="Combatant|XP",DisplayName="XP - Set All") void XP_SetAll(TMap<UOmegaLevelingAsset*, float> XP, bool bAdded=true);

	// Returns the full XP map for all leveling types.
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="XP - Get All") TMap<UOmegaLevelingAsset*,float> XP_GetAll();
	// Returns the current XP value for the given leveling type.
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="XP - Get") float XP_Get(UOmegaLevelingAsset* Type);
	// Returns the min/max XP bounds for the current level and the progress fraction toward the next level.
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="XP - Get Values") void XP_GetValues(UOmegaLevelingAsset* Type, float& LevelMin,float& LevelMax,float& Percent);

	// Directly sets the level for the given leveling type, adjusting XP to the level's minimum threshold.
	UFUNCTION(BlueprintCallable, Category="Combatant|XP",DisplayName="Level - Set") void XP_SetLevel(UOmegaLevelingAsset* Type, int32 NewLevel);

	// Returns the current level derived from XP for the given leveling type.
	UFUNCTION(BlueprintPure, Category="Combatant|XP",DisplayName="Level - Get") int32 XP_GetLevel(UOmegaLevelingAsset* Type);

	// ------------------------------------------------------------------------------------------
	// Asset Tags
	// ------------------------------------------------------------------------------------------
	// Removes all custom tags associated with the given asset in this combatant's entity data.
	UFUNCTION(BlueprintCallable, Category="Combatant|AssetLink",DisplayName="Asset Link - Remove All Tags")
	void AssetLink_RemoveAllTags(UPrimaryDataAsset* Asset);

	// Adds or removes tags linked to a specific asset in this combatant's entity data.
	UFUNCTION(BlueprintCallable, Category="Combatant|AssetLink",DisplayName="Asset Link - Set Tags Active")
	void AssetLink_SetTagsActive(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bTagsActive);

	// Returns the tags currently associated with the given asset in this combatant's entity data.
	UFUNCTION(BlueprintPure, Category="Combatant|AssetLink",DisplayName="Asset Link - Set Tags Active")
	FGameplayTagContainer AssetLink_GetActiveTags(UPrimaryDataAsset* Asset);

	// ------------------------------------------------------------------------------------------
	// Dynamic Vars
	// ------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintPure, Category="Combatant|DynamicVar",DisplayName="Get Dynamic Param - Float")
	void GetDynamic_ScalarValue(UPARAM(meta=(Categories="Combat.Dynamic")) FGameplayTag Tag,UObject* Context, 
		float& Top,float& Total,float& Average);
	
	UFUNCTION(BlueprintPure, Category="Combatant|DynamicVar",DisplayName="Get Dynamic Param - Data Asset")
	UPrimaryDataAsset* GetDynamic_AssetValue(UPARAM(meta=(Categories="Combat.Dynamic"))FGameplayTag Tag,UObject* Context);
	
	UFUNCTION(BlueprintPure, Category="Combatant|DynamicVar",DisplayName="Get Dynamic Param - Tags")
	FGameplayTagContainer GetDynamic_TagsValue(UPARAM(meta=(Categories="Combat.Dynamic"))FGameplayTag Tag,UObject* Context);
	// ------------------------------------------------------------------------------------------
	// PARAM
	// ------------------------------------------------------------------------------------------
	// Stores a named boolean parameter on this combatant's entity data.
	UFUNCTION(BlueprintCallable, Category="Entity|Param",DisplayName="Param (Bool) - Set") void EntityParam_Bool_Set(FName Param, bool Value);
	// Gets a named boolean parameter from this combatant's entity data.
	UFUNCTION(BlueprintPure, Category="Entity|Param",DisplayName="Param (Bool) - Get") bool EntityParam_Bool_Get(FName Param);

	// Stores a named integer parameter on this combatant's entity data. Pass bAdded=true to add to the existing value.
	UFUNCTION(BlueprintCallable, Category="Entity|Param",DisplayName="Param (Int32) - Set") void EntityParam_Int_Set(FName Param, int32 Value, bool bAdded);
	// Gets a named integer parameter from this combatant's entity data.
	UFUNCTION(BlueprintPure, Category="Entity|Param",DisplayName="Param (Int32) - Get") int32 EntityParam_Int_Get(FName Param);
};

// --------------------------------------------------------------------------------------------------------------------
// LISTEN
// --------------------------------------------------------------------------------------------------------------------
