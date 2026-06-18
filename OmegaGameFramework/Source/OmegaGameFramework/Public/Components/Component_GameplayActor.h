// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaComponent.h"
#include "Components/ActorComponent.h"
#include "Condition/Condition_Actor.h"
#include "Functions/F_Component.h"
#include "Functions/F_GlobalScripting.h"
#include "Functions/F_TagEvent.h"
#include "Interfaces/I_Interaction.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_RandomRange.h"
#include "Engine/HitResult.h"
#include "Component_GameplayActor.generated.h"

class UOmegaActorConfig;
class UOmegaFlowAssetBase;
class UOmegaZoneData;
// =======================================================================================================================
// Config Script
// =======================================================================================================================

// Abstract script object run during actor configuration. Override OnActorConfigured in Blueprint to apply custom setup logic.
UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfigScript : public UObject
{
	GENERATED_BODY()

public:

	// Called when an actor is configured with this script. Use it to apply any setup (tags, components, properties).
	UFUNCTION(BlueprintImplementableEvent,Category="ActorConfig")
	void OnActorConfigured(AActor* Actor) const;

};


// A data asset that bundles configuration options for gameplay actors: group registration, scripts, spawn delay, and interaction conditions.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

	// Gameplay groups this actor is automatically registered to at BeginPlay.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	TArray<FGameplayTag> AutoregisterToGroups;

	// Inline configuration scripts applied to the actor when this config is set.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UOmegaActorConfigScript*> Scripts;

	// Random delay range (seconds) applied before the actor runs its BeginPlay modifier scripts.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	FOmegaRandomRangeFloat BeginPlayMod_Delay;


	// Modifier scripts applied to the actor at BeginPlay (after the optional delay).
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UActorModifierScript*> BeginPlay_Modifiers;

	// Conditions the target actor must pass to allow interaction.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FOmegaConditions_Actor CanInteract_Target;
	// Conditions the instigating actor must pass to allow interaction.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FOmegaConditions_Actor CanInteract_Instigator;
};

// =======================================================================================================================
// Subscripts
// =======================================================================================================================

// Abstract inline script executed on a UGameplayActorComponent in response to actor events (overlap, hit, tick, tags).
UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API USubscript : public UObject
{
	GENERATED_BODY()

public:

	// Called when the owning actor begins overlapping another actor.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void ActorBeginOverlap(UGameplayActorComponent* OwningComponent, AActor* OverlappedActor) const;
	// Called when the owning actor stops overlapping another actor.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void ActorEndOverlap(UGameplayActorComponent* OwningComponent, AActor* OverlappedActor) const;
	// Called when the owning actor is hit by a physics impulse.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void ActorHit(UGameplayActorComponent* OwningComponent, AActor* SelfActor, AActor* OtherActor, FVector Vector, const FHitResult& hit) const;

	// When true, this subscript's Tick event is called every frame.
	UPROPERTY(EditDefaultsOnly,Category="Subscript")
	bool bCanTick;

	// Called when the owning component's BeginPlay fires.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnBeginPlay(UGameplayActorComponent* OwningComponent) const;

	// Called when the owning component's EndPlay fires.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnEndPlay(UGameplayActorComponent* OwningComponent) const;

	// Called every frame if bCanTick is true.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void Tick(float Delta,UGameplayActorComponent* OwningComponent) const;

	// Called when a gameplay tag event is fired on the owning component.
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnTagEvent(UGameplayActorComponent* OwningComponent, FGameplayTag Event) const;
};

// A data asset that bundles a list of subscripts for reuse across multiple actors.
UCLASS()
class OMEGAGAMEFRAMEWORK_API USubscriptCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	// The subscripts contained in this collection.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Default")
	TArray<USubscript*> Subscripts;

};

// Container that holds both preset (data asset) and inline subscript lists for a gameplay actor component.
USTRUCT(BlueprintType)
struct FOmegaSubscripts
{
	GENERATED_BODY()
	// Subscript collections loaded from data assets.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="📜Subscripts",DisplayName="📜Subscripts (Preset)") TArray<USubscriptCollection*> Preset;
	// Subscripts defined inline directly on this component.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="📜Subscripts",DisplayName="📜Subscripts (Inline)") TArray<USubscript*> Inline;

	TArray<USubscript*> GetSubscripts() const;
	// 0=beginPlay | 1=EndPlay | 2=BeginOverlap | 3=EndOverlay | 4=TagEvent
	void EventCall(uint8 event, UGameplayActorComponent* component, AActor* other_actor=nullptr,FGameplayTag tag=FGameplayTag(),FHitResult hit=FHitResult());
};


// =======================================================================================================================
// COMPONENT
// =======================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorIdentityChanged, UPrimaryDataAsset*, IdentityAsset, UGameplayActorComponent*, Component);

// Core gameplay component that gives an actor an identity data asset, gameplay tags, save visibility, subscript logic, zone, and flow support.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UGameplayActorComponent : public UOmegaComponent, public IDataInterface_General, public IActorTagEventInterface, public IActorInterface_Interactable
{
	GENERATED_BODY()

	void L_Init();
	bool Local_IsSourceAssetValid() const;
	bool L_SourceUsesGeneralInterface() const;
	TArray<UActorIdentityScript*> Local_GetScripts() const;

	UPROPERTY() FTimerHandle timer_modDelay;
	UFUNCTION() void L_TimerEnd();
	virtual UOmegaActorConfig* L_GetConfig();
	virtual void OnRegister() override;

public:
	UGameplayActorComponent();
	void Local_RunConstruct();

	UPROPERTY(BlueprintReadOnly,Category="Gameplay")
	FLuaValue temp_table;

	// Optional config asset applied to the actor at BeginPlay. Overrides the identity asset's config if set.
	UPROPERTY(EditAnywhere,Category="🎮Gameplay",AdvancedDisplay) UOmegaActorConfig* DefaultConfig;
	// Applies a new config asset to this actor, running its scripts and registering it to groups.
	UFUNCTION(BlueprintCallable,Category="🎮Gameplay") void SetConfig(UOmegaActorConfig* Config);

	// Overrides the display name returned by the general data interface (used in UI, logs, etc.).
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="🎮Gameplay") FText OverrideName;
	// The primary data asset that defines this actor's identity (name, icon, stats, etc.).
	UPROPERTY(EditAnywhere,Category="🎮Gameplay",DisplayName="Identity") UPrimaryDataAsset* IdentitySource;
	// Bitflag set forwarded to identity scripts for conditional setup logic.
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="🎮Gameplay",DisplayName="Identity Flags") FOmegaBitflagsBase IdentityFlags;
	// Default flow asset launched when this actor is interacted with.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎮Gameplay") TSoftObjectPtr<UOmegaFlowAssetBase> DefaultFlow;
	// Zone this actor belongs to; used for zone-based queries and logic.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎮Gameplay") TObjectPtr<UOmegaZoneData> Zone;
	// Stable GUID used to identify this actor across sessions (save/load references).
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎮Gameplay") FGuid Guid;

	// Category tag that classifies this actor in tag-based queries.
	UPROPERTY(EditAnywhere,Category="🎮Gameplay|Tags") FGameplayTag CategoryTag;
	// Gameplay tags on this actor used for filtering, conditions, and events.
	UPROPERTY(EditAnywhere,Category="🎮Gameplay|Tags") FGameplayTagContainer GameplayTags;
	// When set, tag events matching this category will pause and unpause the actor's tick.
	UPROPERTY(EditAnywhere, Category="🎮Gameplay|Tags") FGameplayTag PauseCategory;

	void L_UpdateVisibility();
	bool IsVisible() const;

	// When true, visibility conditions are checked against the global save state.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="👁️Visibility")
	bool bGlobalSave;

	// This actor is visible only when the active save's tags match this query.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="👁️Visibility", DisplayName="Visible (On Save Query)")
	FGameplayTagQuery VisibleOnSaveQuery;

	// This actor is hidden when the active save's tags match this query.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="👁️Visibility", DisplayName="Hidden (On Save Query)")
	FGameplayTagQuery HiddenOnSaveQuery;



	// Subscripts executed in response to this actor's events (overlap, hit, tag events, etc.).
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎮Gameplay", meta=(ShowOnlyInnerProperties)) FOmegaSubscripts Subscripts;

	// Fires when the identity source asset changes at runtime.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnActorIdentityChanged OnActorIdentityChanged;

	// Sets a new identity data asset, running its init scripts and firing OnActorIdentityChanged.
	UFUNCTION(BlueprintCallable,Category="Actor")
	void SetIdentitySourceAsset(UPrimaryDataAsset* SourceAsset);
	// Returns the current identity data asset, or null if none is set.
	UFUNCTION(BlueprintPure,Category="Actor")
	UPrimaryDataAsset*  GetIdentitySourceAsset() const
	{
		if(IdentitySource) {return IdentitySource;} return nullptr;
	};

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override { OutCategoryTag = CategoryTag; OutGameplayTags = GameplayTags; };
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;

	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	UFUNCTION()
	void L_SaveTagsUpdate(FGameplayTagContainer EditedTags, bool bAdded, bool bGlobal);
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION() void OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION() void OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION() void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	// -------------------------------------------------------------------------------------

	// Sets a named boolean value in the subscript temp table.
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Bool") void SetBool(FString param, bool Value);
	// Sets a named integer value in the subscript temp table.
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Int") void SetInt(FString param, int32 Value);
	// Sets a named float value in the subscript temp table.
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Float") void SetFloat(FString param, float Value);
	// Sets a named vector value in the subscript temp table.
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Vector") void SetVector(FString param, FVector Value);

	// Gets a named boolean value from the subscript temp table.
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Bool") bool GetBool(FString param);
	// Gets a named integer value from the subscript temp table.
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Int") int32 GetInt(FString param);
	// Gets a named float value from the subscript temp table.
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Float") float GetFloat(FString param);
	// Gets a named vector value from the subscript temp table.
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Vector") FVector GetVector(FString param);

};

// Implement on data assets that act as actor identity sources to define lifecycle scripts and hooks for actors using them.
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Actor Identity Source") class UDataInterface_ActorIdentitySource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()

public:

	// Returns the list of identity scripts applied to actors using this identity source.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Actor",DisplayName="Actor ID - Get Scripts")
	TArray<UActorIdentityScript*> GetIdentityScripts();

	// Called when this identity is applied to an actor. Return false to cancel default initialization.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Identity Init")
	bool OnIdentityInit(AActor* Actor, UGameplayActorComponent* Component);

	// Called when this identity is removed from an actor.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Identity Uninit")
	bool OnIdentityUninit(AActor* Actor, UGameplayActorComponent* Component);

	// Called during the actor's OnConstruction when this identity is set.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Construct")
	bool OnActorConstruction(AActor* Actor, UGameplayActorComponent* Component);

	// Called at the actor's BeginPlay when this identity is set.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Begin Play")
	bool OnActorBeginPlay(AActor* Actor, UGameplayActorComponent* Component);

	// Called on the actor's tick each frame while this identity is set.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Tick")
	bool OnActorTick(AActor* Actor, UGameplayActorComponent* Component, float DeltaTime);

	// Called when a gameplay tag event fires on the actor while this identity is set.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Tag Event")
	bool OnActorTagEvent(AActor* Actor, UGameplayActorComponent* Component, FGameplayTag Event);

	// Called when the actor is interacted with while this identity is set.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Interact")
	bool OnActorInteract(AActor* Actor, UGameplayActorComponent* Component, AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Meta);

	// Return true to block interaction while this identity is set.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - Interact Blocked?")
	bool IsInteractBlocked(AActor* Actor, UGameplayActorComponent* Component, AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Meta);
};

// =======================================================================================================================
// IDENTITY ASSET
// =======================================================================================================================


// A data asset that composes identity scripts from pre-setup, local, and post-setup lists, enabling layered actor configuration.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UActorIdentityPreset : public UOmegaDataAsset, public IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()

public:

	virtual TArray<UActorIdentityScript*> GetIdentityScripts_Implementation() override;

	// Scripts applied before the local scripts (run first).
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|ActorIdentity")
	TArray<UActorIdentityPreset*> PreSetup_Scripts;
	// Scripts defined directly on this preset.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Omega|ActorIdentity")
	TArray<UActorIdentityScript*> Local_Scripts;
	// Scripts applied after the local scripts (run last).
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|ActorIdentity")
	TArray<UActorIdentityPreset*> PostSetup_Scripts;
};

// =======================================================================================================================
// IDENTITY SCRIPT
// =======================================================================================================================


// An inline script applied to an actor at construction, BeginPlay, or each tick via its identity source.
UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UActorIdentityScript : public UObject
{
	GENERATED_BODY()

public:

	// Called during the actor's OnConstruction when this script runs.
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorConstruction(AActor* Actor, UGameplayActorComponent* Component) const;

	// Called at the actor's BeginPlay when this script runs.
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorBeginPlay(AActor* Actor, UGameplayActorComponent* Component) const;

	// Called each tick if the identity source enables ticking for this script.
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorTick(AActor* Actor, UGameplayActorComponent* Component, float DeltaTime) const;
};



// =======================================================================================================================
// FUNCTIONS
// =======================================================================================================================

// Blueprint function library for querying the world for actors by their identity data asset.
UCLASS()
class UOmegaActorIdentityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Returns all actors in the world that have the given identity asset set on their UGameplayActorComponent.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(WorldContext="WorldContextObject",DeterminesOutputType="FilterClass"))
	static TArray<AActor*> GetAllActorsWithIdentity(UObject* WorldContextObject, UPrimaryDataAsset* Asset, TSubclassOf<AActor> FilterClass);

	// Returns the first actor found with the given identity asset, or null if none exists.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject",ExpandBoolAsExecs = "Outcome",DeterminesOutputType="FilterClass"),DisplayName="Ω🔴 Get First Actor /w Identity")
	static AActor* GetFirstActorWithIdentity(UObject* WorldContextObject,UPrimaryDataAsset* Asset, TSubclassOf<AActor> FilterClass,  bool& Outcome);

	// Returns the identity data asset set on Actor's UGameplayActorComponent, or null if none.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(ExpandBoolAsExecs = "result",DeterminesOutputType="Class"))
	static UPrimaryDataAsset* GetActorIdentityAsset(AActor* Actor, bool& result,TSubclassOf<UPrimaryDataAsset> Class=nullptr);

};

// Convenience alias for UGameplayActorComponent with no added behavior.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UActorIdentityComponent : public UGameplayActorComponent
{

	GENERATED_BODY()
public:
};
