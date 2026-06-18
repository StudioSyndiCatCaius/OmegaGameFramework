// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Enums.h"
#include "JsonObjectWrapper.h"
#include "Math/Vector2D.h"
#include "Engine/EngineTypes.h"
#include "Engine/AssetUserData.h"
#include "LuaValue.h"
#include "Misc/GeneralDataObject.h"
#include "F_Common.generated.h"

class UOmegaCalendarComponent;
class UOAsset_Calendar;
class AOmegaGameMode;
class UAssetSquadComponent;
class UOmegaDataAsset;
class UAssetSquad_Identity;
class AOmegaInstancedEntity;
class UCombatantComponent;
class AOmegaWorldManager;
class UOmegaStyleSettings;
class UOmegaSettings;
class UEquipmentSlot;
class APlayerController;
class UEnhancedInputLocalPlayerSubsystem;
class UOmegaSubsystem_Player;
class UOmegaInputMode;
class ALevelInstance;
class UCurveFloat;
class UOmegaAssetSettings;

/** Simple two-state enum used to branch execution based on a flag being active or inactive. */
UENUM(Blueprintable)
enum EOmegaFlagResult
{
	Flag_Active		UMETA(DisplayName = "Activate"),
	Flag_Inactive	UMETA(DisplayName = "Inactive"),
};


/** Controls which sources are consulted when searching for assets. */
USTRUCT(BlueprintType)
struct FOmegaAssetSearchConfig
{
	GENERATED_BODY()
public:
	/** Include assets loaded from external/streaming sources. */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bLoadExternal=false;
	/** Return assets in their sorted order. */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bSortedAssets=true;
	/** Include assets registered in the quick-access list. */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bQuickAccess=true;
	/** Include assets referenced via per-class gameplay config. */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bClassGameplayConfig=true;
	/** Allow the game core override list to contribute assets. */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bGameCoreOverride=true;
	/** Log the search process to the output log for debugging. */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bLogProcess=false;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameFrameworkBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/** Internal helper that formats a Text string using values from the given object. */
	static FText L_TextFormatObject(UObject* obj, FText t);

public:

	/** Returns the global OmegaSettings object (project-wide Omega configuration). */
	UFUNCTION(BlueprintPure, Category="Omega|Settings", meta=(Keywords="has"),DisplayName="Ω Get Settings - Omega")
	static UOmegaSettings* GetSettings_Omega();
	/** Returns the global OmegaStyleSettings object (UI/visual style configuration). */
	UFUNCTION(BlueprintPure, Category="Omega|Settings", meta=(Keywords="has"),DisplayName="Ω Get Settings - Style")
	static UOmegaStyleSettings* GetSettings_Style();
	/** Returns the global OmegaAssetSettings object (asset registry / search configuration). */
	UFUNCTION(BlueprintPure, Category="Omega|Settings", meta=(Keywords="has"),DisplayName="Ω Get Settings - Asset")
	static UOmegaAssetSettings* GetSettings_Asset();

	// -----------------------------------------------------------------------------------------------------------------
	// World Manager
	// -----------------------------------------------------------------------------------------------------------------


	/** Returns the OmegaWorldManager actor for the current world (holds global state such as entity instances). */
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject",CompactNodeTitle="🌎World Manager"))
	static AOmegaWorldManager* GetOmegaWorldManager(UObject* WorldContextObject);

	// -----------------------------------------------------------------------------------------------------------------
	// Game Mode
	// -----------------------------------------------------------------------------------------------------------------
	/** Returns the OmegaGameMode for the current world. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject",CompactNodeTitle="🎮Game Mode"))
	static AOmegaGameMode* GetOmegaGameMode(UObject* WorldContextObject);
	
	/** Returns the global CombatantComponent registered on the Game Mode. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Combatant")
	static UCombatantComponent* GetGlobalCombatant(UObject* WorldContextObject);
	/** Returns the instanced entity actor in the world that matches the given identity object ID. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Entity Instance")
	static AOmegaInstancedEntity* GetGlobalEntityInstance(UObject* WorldContextObject,UObject* ID);
	/** Returns the asset occupying the given equipment slot on the world entity identified by ID. Result is false if the slot is empty. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject",ExpandBoolAsExecs="Result"),DisplayName="🎮Game Mode - Get Entity Equipment Slot")
    static UPrimaryDataAsset* GetGlobalEntityEquipmentSlot(UObject* WorldContextObject,UObject* ID, UEquipmentSlot* Slot,bool& Result);

	/** Returns the global squad component and its currently active squad identity. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Squad")
	static void GetGlobalSquad_CurrentIdentity(UObject* WorldContextObject, UAssetSquadComponent*& Component, UAssetSquad_Identity*& CurrentSquad);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Calendar")
	static void GetGlobalCalendar(UObject* WorldContextObject, UOmegaCalendarComponent*& Component, UOAsset_Calendar*& Asset);

	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Calendar Data Seed")
	static FRandomStream GetGlobalCalendarDateSeed(UObject* WorldContextObject);

	/** Returns all instanced entity actors whose identity matches any of the given IDs. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Entity Instance (from Identities)")
	static TArray<AOmegaInstancedEntity*> GetGlobalEntityInstances_FromIDs(UObject* WorldContextObject,TArray<UPrimaryDataAsset*> IDs);
	
	/** Returns all instanced entity actors whose identity is part of the given squad. */
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Get Entity Instance (from Squad)")
	static TArray<AOmegaInstancedEntity*> GetGlobalEntityInstances_FromSquad(UObject* WorldContextObject,UAssetSquad_Identity* Squad);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Split Squad Entity Instance (at index)")
	static void SplitGlobalCurrentSquadEntityInst_AtIndex(UObject* WorldContextObject,
		TArray<AOmegaInstancedEntity*>& Before,TArray<AOmegaInstancedEntity*>& After, int32 index);

	UFUNCTION(BlueprintPure, Category="Omega|GameMode",meta=(WorldContext="WorldContextObject"),DisplayName="🎮Game Mode - Split Squad Entity Instance (at Constant)")
	static void SplitGlobalCurrentSquadEntityInst_AtConst(UObject* WorldContextObject,
		TArray<AOmegaInstancedEntity*>& Before,TArray<AOmegaInstancedEntity*>& After, 
		UPARAM(meta=(GetOptions="UOmegaFunctions_Constants::opts_int")) FName Constant="PartySize");

	//###############################################################################
	// Gameplay tags
	//###############################################################################


	/** Advanced tag container check. bAll: require all tags; bExact: use exact tag matching. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Ω Has Gameplay Tags (Adv.)")
	static bool HasTags_Advance(FGameplayTagContainer Tags, FGameplayTagContainer Has, bool bAll, bool bExact);

	/** Returns the full gameplay tag container registered on Object via the Omega interface. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Get Gameplay Tags")
	static FGameplayTagContainer GetObjectGameplayTags(UObject* Object);

	/** Returns the single category gameplay tag for Object (the tag that classifies what type of object it is). */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Get Gameplay Category")
	static FGameplayTag GetObjectGameplayCategory(UObject* Object);

	/** Returns true if Object's category tag matches CategoryTag. bExact: use exact tag comparison. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags",DisplayName="Ω Is Object of Gameplay Category")
	static bool IsObjectOfGameplayCategory(UObject* Object, FGameplayTag CategoryTag, bool bExact);

	/** Returns true if Object has the given gameplay tag. bExact: use exact tag matching. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Gameplay Tags - Has Tag")
	static bool DoesObjectHaveGameplayTag(UObject* Object, FGameplayTag GameplayTag, bool bExact);
	/** Returns true if Object has all (or any) of the given gameplay tags. bValidIfEmpty: return true when the tag container is empty. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Gameplay Tags - Has Tags")
	static bool DoesObjectHaveGameplayTags(UObject* Object, const FGameplayTagContainer& GameplayTags, bool bExact, bool bValidIfEmpty=true);

	/** Evaluates a FGameplayTagQuery against Object's tags. bEmptyReturnsTrue: pass when the query is empty. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags",DisplayName="Object - Gameplay Tags - Query")
	static bool QueryObjectGameplayTags(UObject* Object, FGameplayTagQuery Query, bool bEmptyReturnsTrue=true);

	/** Returns only the tags from TagsIn that are children of TypeTag. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer FilterTagsByType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);

	/** Returns the first tag in TagsIn that is a child of TypeTag. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTag GetFirstTagOfType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);

	/** Converts a dot-delimited string (e.g. "Category.SubTag") into a FGameplayTag. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTag MakeGameplayTagFromString(const FString& String);

	/** Converts an array of dot-delimited strings into a FGameplayTagContainer. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer MakeGameplayTagContainerFromStrings(TArray<FString> Strings);

	/** Returns the last segment of a gameplay tag's dot-delimited name (e.g. "Category.Sub.Leaf" → "Leaf"). */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FString GetLastGameplayTagString(const FGameplayTag& GameplayTag);

	//###############################################################################
	// System
	//###############################################################################

	/** Returns true if the gameplay system tagged with Tag is currently active in the world. */
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject"),DisplayName="🧩Gameplay Systems - Is Tag Active?")
	static bool IsSystemTagActive(const UObject* WorldContextObject,UPARAM(meta=(Categories="SYSTEM")) FGameplayTag Tag);

	/** Activates or deactivates a gameplay system of the given class. Flag and Context are optional metadata. */
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context"),DisplayName="🧩Gameplay Systems - Set Active")
	static void SetGameplaySystemActive(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass, bool bActive, const FString Flag, UObject* Context);

	/** Activates or deactivates multiple gameplay systems at once. Flag and Context are optional metadata. */
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context"),DisplayName="🧩Gameplay Systems - Set Active (List)")
	static void SetGameplaySystemsActive(const UObject* WorldContextObject, TArray<TSubclassOf<AOmegaGameplaySystem>> SystemClasses, bool bActive, const FString Flag, UObject* Context);

	//###############################################################################
	// Object
	//###############################################################################

	/** Returns the class default object (CDO) for the given class, cast to the appropriate type. */
	UFUNCTION(BlueprintCallable, Category="Omega|Object",meta=(DeterminesOutputType="Class"),DisplayName="Object - Get Class Default")
	static UObject* GetClassDefaultObject(TSubclassOf<UObject> object);

	/** Returns the CDO for each class in the array. */
	UFUNCTION(BlueprintCallable, Category="Omega|Object",meta=(DeterminesOutputType="Class"),DisplayName="Objects - Get Class Defaults")
	static TArray<UObject*> GetClassDefaultObjects(TArray<TSubclassOf<UObject>> object);

	/** Resolves an array of soft object pointers to hard references, filtering by Class. */
	UFUNCTION(BlueprintCallable, Category="Omega|Object",meta=(DeterminesOutputType="Class"),DisplayName="Objects - Resolve Soft Array")
	static TArray<UObject*> ResolveSoftArray_Object(TArray<TSoftObjectPtr<UObject>> List, TSubclassOf<UObject> Class);
	/** Resolves an array of soft class pointers to hard UClass references. */
	UFUNCTION(BlueprintCallable, Category="Omega|Object",meta=(DeterminesOutputType="Class"))
	static TArray<TSubclassOf<UObject>> ResolveSoftArray_Class(TArray<TSoftClassPtr<UObject>> List);

	/** Filters an object array to only (or exclude, if bExclude) objects that are instances of Class. */
	UFUNCTION(BlueprintPure, Category="Omega|Assets", meta=(DeterminesOutputType="Class", AdvancedDisplay="bExclude"),DisplayName="Object - Filter (by Class)")
	static TArray<UObject*> FilterObjectsByClass(TArray<UObject*> Objects, TSubclassOf<UObject> Class, bool bExclude);

	/** Filters objects by category tag. bExact: exact tag match. bExclude: invert the filter. bIncludeOnEmptyTag: always include if no tag is set. */
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class,bIncludeOnEmptyTag",
		DeterminesOutputType="Class"),DisplayName="Object - Filter (by Category Tag)")
	static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag CategoryTag,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag);

	/** Filters objects by a gameplay tag container. bExact: exact match. bExclude: invert. bIncludeOnEmptyTag: pass when no tags are set. */
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class,bIncludeOnEmptyTag",
		DeterminesOutputType="Class"),DisplayName="Object - Filter (by Gameplay Tags)")
	static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer GameplayTags,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag);

	/** Filters objects to only (or exclude, if bExclude) those that implement the given Interface. */
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExclude, Class",
		DeterminesOutputType="Class"),DisplayName="Object - Filter (by Interface)")
	static TArray<UObject*> FilterObjectsWithInterface(TArray<UObject*> Objects, TSubclassOf<UInterface> Interface, bool bExclude, TSubclassOf<UObject> Class);

	/** Returns the first object in the array whose display name matches Name. */
	UFUNCTION(BlueprintPure, Category="Omega|Object",DisplayName="Object - Select (by Name)")
	static UObject* SelectObjectByName(TArray<UObject*> Objects, const FString& Name);

	/** Returns an array of display name strings for each object in the list. */
	UFUNCTION(BlueprintPure, Category="Omega|Object",DisplayName="Objects - Get Display Names")
	static const TArray<FString> GetDisplayNamesFromObjects(TArray<UObject*> Objects);

	/** Returns the GUID associated with the given UObject (if it has one). */
	UFUNCTION(BlueprintPure,Category="Omega|Object") static FGuid GetObjectGUID(UObject* Object);
	/** Returns a deterministic integer seed derived from the object's GUID. Useful for procedural content. */
	UFUNCTION(BlueprintPure,Category="Omega|Object") static int32 GetObjectSeed(UObject* Object);

	UFUNCTION(BlueprintPure,Category="Omega|Object") static int32 GetObjectGenericLevel(UObject* Object);
	
	UFUNCTION(BlueprintPure,Category="Omega|Object")
	static TArray<UObject*> FilterObjects_ByGenericLevel(TArray<UObject*> In, int32 Level, TEnumAsByte<EOmegaComparisonMethod> Method);
	
	//###############################################################################
	// Asset Getter
	//###############################################################################

	/** Returns all loaded assets of the given Class (optionally including subclasses), filtered by category tag if provided. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class"),DisplayName="Assets - Get All of Class")
	static TArray<UObject*> GetAllAssetsOfClass(TSubclassOf<UObject> Class, bool bIncludeSubclasses=false, FGameplayTag FilterCategory=FGameplayTag());

	/** Finds an asset next to a Reference asset by applying Prefix/Suffix/Subdir string transforms to its path.
	 *  Outcome is false if no matching asset was found. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome")
	,DisplayName="Ω🔴 Get Asset (Adjacent to Reference)")
	static UObject* GetAsset_AdjacentToReference(TSoftObjectPtr<UObject> Reference, const FString& Prefix,const FString& Suffix, const FString& Subdir,const FString& RemovedString,TSubclassOf<UObject> Class,bool& Outcome);

	/** Loads and returns an asset at AssetPath, optionally searching within Directory using the given config.
	 *  Outcome is false if the asset could not be found or loaded. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Directory, Prefix, Sufix, config")
		,DisplayName="Ω🔴 Get Asset (from Path)")
	static UObject* GetAsset_FromPath(const FString& AssetPath, TSubclassOf<UObject> Class, bool& Outcome,const FString& Directory="", FOmegaAssetSearchConfig config=FOmegaAssetSearchConfig());

	/** Returns all assets of Class found at or below the given content path. bRecursive searches sub-folders. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get All Assets (from Path)")
	static TArray<UObject*> GetAssets_FromPath(const FString& path, bool bRecursive, TSubclassOf<UObject> Class);

	/** Returns all assets of Class found at each path in AssetPaths. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get Assets List (from Paths)")
	static TArray<UObject*> GetAssetList_FromPath(const TArray<FString> AssetPaths, TSubclassOf<UObject> Class);

	/** Loads and returns the UClass at AssetPath. Outcome is false if the class could not be resolved. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Class (from Path)")
	static UClass* GetClass_FromPath(const FString& AssetPath, TSubclassOf<UObject> Class, bool& Outcome);

	/** Reads a string field named Field from a Lua value and loads the asset at that path as Class. Outcome is false on failure. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Asset (from Lua Field)")
	static UObject* GetAsset_FromLuaField(FLuaValue Lua, const FString& Field, TSubclassOf<UObject> Class, bool& Outcome);

	/** Reads a string field named Field from a Lua value and loads the UClass at that path. Outcome is false on failure. */
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Class (from Lua Field)")
	static UClass* GetClass_FromLuaField(FLuaValue Lua, const FString& Field, TSubclassOf<UObject> Class, bool& Outcome);

	//###############################################################################
	// Player
	//###############################################################################

	/** Returns the first actor hit by a sphere trace from the player's mouse cursor. Returns null if nothing is hit. */
	UFUNCTION(BlueprintPure, Category="Omega|Player")
	static AActor* GetPlayerMouseOverActor(const APlayerController* Player, ETraceTypeQuery TraceChannel, float TraceSphereRadius);

	/** Applies a custom OmegaInputMode to the player (controls UI/game focus and cursor visibility). */
	UFUNCTION(BlueprintCallable, Category="Omega|Player", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Player"))
	static void SetPlayerCustomInputMode(const UObject* WorldContextObject, APlayerController* Player,  UOmegaInputMode* InputMode);

	/** Returns the current camera fade opacity for the player (0 = no fade, 1 = fully faded). */
	UFUNCTION(BlueprintPure, Category="Omega|Player")
	static float  GetPlayerCameraFadeAmount(const APlayerController* Player);

	/** Returns the color currently used for the player's camera fade effect. */
	UFUNCTION(BlueprintPure, Category="Omega|Player")
	static FLinearColor  GetPlayerCameraFadeColor(const APlayerController* Player);

	//###############################################################################
	// Actor Binding
	//###############################################################################

	/** Registers an Actor under a global named binding so it can be retrieved by name from anywhere. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - SET")
	static void SetGlobalActorBinding(const UObject* WorldContextObject, FName Binding, AActor* Actor);
	/** Removes the actor stored under the named global binding. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - CLEAR")
	static void ClearGlobalActorBinding(const UObject* WorldContextObject, FName Binding);
	/** Returns the actor currently registered under the named global binding. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - GET")
	static AActor* GetGlobalActorBinding(const UObject* WorldContextObject, FName Binding);


	/** Registers an Actor under a gameplay-tag-keyed binding (must be under the BINDING tag category). */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - SET")
	static void SetTaggedActorBinding(const UObject* WorldContextObject, UPARAM(meta=(Categories="BINDING")) FGameplayTag Binding, AActor* Actor);
	/** Returns the actor registered under a gameplay-tag binding. result is false if none is assigned. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs="result",DeterminesOutputType="Class"),DisplayName="Actor - Tag Binding - GET")
	static AActor* CheckTaggedActorBinding(const UObject* WorldContextObject, UPARAM(meta=(Categories="BINDING")) FGameplayTag Binding, TSubclassOf<AActor> Class, bool& result);

	//###############################################################################
	// Quick Get
	//###############################################################################

	/** Returns the currently active gameplay system of the given class. result is false if it is not active. */
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="SystemClass", ExpandBoolAsExecs="result"))
	static AOmegaGameplaySystem* GetActiveGameplaySystem(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass, bool& result);

	/** Finds the first active gameplay system that owns a component of the given class (optionally tagged with RequiredTag).
	 *  Returns the component and system. Outcome is false if none is found. */
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="Component",ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Gameplay System (w/ Component)")
	static UActorComponent* GetFirstActiveGameplaySystemWithComponent(const UObject* WorldContextObject, TSubclassOf<UActorComponent> Component, FName RequiredTag, AOmegaGameplaySystem*& system, bool& Outcome);

	/** Returns the gameplay module of the given class. bFallbackToDefault: return the CDO if no active instance exists. */
	UFUNCTION(BlueprintPure, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="ModuleClass"))
	static UOmegaGameplayModule* GetGameplayModule(const UObject* WorldContextObject, TSubclassOf<UOmegaGameplayModule> ModuleClass, bool bFallbackToDefault=false);

	/** Returns the gameplay module of the given class via an exec pin. Outcome is false if the module is not available. */
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="ModuleClass",ExpandBoolAsExecs="Outcome"))
	static UOmegaGameplayModule* TryGetGameplayModule(const UObject* WorldContextObject, TSubclassOf<UOmegaGameplayModule> ModuleClass, bool& Outcome, bool bFallbackToDefault=false);

	/** Fires a named global event, notifying all registered listeners in the world. Context is optional payload. */
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta=(WorldContext = "WorldContextObject", AdvancedDisplay="Context"),DisplayName="Fire Global Event (Named)")
	static void FireGlobalEvent(const UObject* WorldContextObject, FName Event, UObject* Context, FOmegaCommonMeta meta);
	/** Fires a tag-based global event, notifying all registered listeners. Context is optional payload. */
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta=(WorldContext = "WorldContextObject", AdvancedDisplay="Context"),DisplayName="Fire Global Event (Tagged)")
	static void FireTaggedGlobalEvent(const UObject* WorldContextObject, FGameplayTag Event, UObject* Context, FOmegaCommonMeta meta);

	//###############################################################################
	// Actor
	//###############################################################################

	/** Adds or removes a single actor tag by name. */
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetActorTagActive(AActor* Actor, FName Tag, bool bIsActive);

	/** Adds or removes multiple actor tags by name in one call. */
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetActorTagListActive(AActor* Actor, TArray<FName> Tags, bool bIsActive);

	/** Adds or removes a tag on an ActorComponent. */
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetComponentTagActive(UActorComponent* Component, FName Tag, bool bIsActive);

	/** Returns the owner actors of a list of components, filtered to the given component class. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(DeterminesOutputType="Class"))
	static TArray<AActor*> GetActorsFromComponents(TArray<UActorComponent*> Components,TSubclassOf<UActorComponent> Class=nullptr);

	/** Returns the child actors spawned by the given ChildActorComponents, filtered by ActorClass. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(DeterminesOutputType="ActorClass"))
	static TArray<AActor*> GetActorsFromChildActorComponents(TArray<UChildActorComponent*> Components, TSubclassOf<AActor> ActorClass);

	/** Returns all components of ComponentClass found on each actor in the list. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="ComponentClass"))
	static TArray<UActorComponent*> GetComponentsFromActors(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass);

	/** Returns the 2D viewport positions for each Actor in the list. ViewportRelative: normalized [0,1] range instead of pixels. */
	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static TArray<FVector2D> GetActorPositionVectors2D(TArray<AActor*> Actors, const APlayerController* Player, bool ViewportRelative);

	/** Returns the actor from the list whose world location is closest to Point. */
	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static AActor* GetClosestActorToPoint(TArray<AActor*> Actors, FVector Point);

	/** Returns the actor of FilterClass whose origin is closest to the centre of OverlappedComponent (from its overlap list). */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(DeterminesOutputType="FilterClass"))
	static AActor* GetClosestOverlappingActor(UPrimitiveComponent* OverlappedComponent,TSubclassOf<AActor> FilterClass);

	/** Returns the actor from the list whose 2D viewport position is closest to the given screen Point. */
	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static AActor* GetClosestActorToViewportPoint2D(TArray<AActor*> Actors, FVector2D Point, const APlayerController* Player, bool ViewportRelative);

	/** Sets an actor's active state in one call:
	 *  true  → visible, collision enabled, time dilation = 1.
	 *  false → hidden, collision disabled, time dilation = 0. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors")
	static void SetActorActive(AActor* Actor, bool bIsActive);

	/** Filters the actor list to only those that have at least one component of ComponentClass. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(AdvancedDisplay="ExcludedActors"))
	static TArray<AActor*> FilterActorsWithComponents(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass);

	/** Attempts to get an actor from an arbitrary Object (cast, owner lookup, etc.). Outcome is false on failure. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Try Get Actor (From Object)")
	static AActor* TryGetActorFromObject(UObject* Object, TSubclassOf<AActor> Class, bool& Outcome);

	/** Attempts to get a component from an Object — tries casting it as a component, checking its owner actor, or finding a sibling component. Outcome is false on failure. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Tag,bForceAdd"),DisplayName="Ω🔴 Try Get Component (From Object)")
	static UActorComponent* TryGetComponentFromObject(UObject* Object, TSubclassOf<UActorComponent> Class, bool& Outcome,FName Tag="", bool bForceAdd=false);
	
	/** Filters the actor list to those that have (or don't have, if bExclude) a tag matching Tag, cast to Class. */
	UFUNCTION(BlueprintPure, Category="Omega|Actors", meta=(DeterminesOutputType="Class", AdvancedDisplay="ExcludedActors"))
	static TArray<AActor*> FilterActorsWithTag(TArray<AActor*> Actors, FName Tag, bool bExclude,TSubclassOf<AActor> Class);

	/** Filters the component list to those that have (or don't have, if bExclude) the given tag. */
	UFUNCTION(BlueprintPure, Category="Omega|Actors", meta=(DeterminesOutputType="Class", AdvancedDisplay="ExcludedActors"))
	static TArray<UActorComponent*> FilterComponentsWithTag(TArray<UActorComponent*> Components, FName Tag, bool bExclude,TSubclassOf<UActorComponent> Class);

	/** Spawns an actor of Class at Transform, applies the given Tags, and returns it. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject",DeterminesOutputType="Class"))
	static AActor* Quick_SpawnActor(UObject* WorldContextObject, TSubclassOf<AActor> Class, FTransform Transform, const TArray<FName> Tags);

	/** Enables or disables input processing on an Actor for the given player controller. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject", AdvancedDisplay="Player"))
	static void SetActorInputEnabled(UObject* WorldContextObject, AActor* Actor, bool bEnabled, APlayerController* Player);

	/** Returns the child actor inside ChildActor if it is (or inherits from) Class. Outcome is false on failure. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Try Get Child Actor As Class")
	static AActor* TryGetChildActorAsClass(UChildActorComponent* ChildActor, TSubclassOf<AActor> Class, bool& Outcome);

	/** Extracts the hit actors from a list of FHitResults, filtered to Class. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class"),DisplayName="Ω Get Actors (from Hit Results)")
	static TArray<AActor*> GetActorsFromHitResults(TArray<FHitResult> Hits, TSubclassOf<AActor> Class);

	// -- ROTATE ACTOR

	/** Rotates Actor to face a world-space Location. X/Y/Z flags lock individual rotation axes. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actor - Rotate (To Look Location)")
	static void RotateActorToLookLocation(AActor* Actor, FVector Location, bool X=false, bool Y=false, bool Z=true);

	/** Rotates Actor to face LookTarget. X/Y/Z flags lock individual rotation axes. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actor - Rotate (To Look Target)")
	static void RotateActorToLookTarget(AActor* Actor, AActor* LookTarget, bool X=false, bool Y=false, bool Z=true);

	/** Rotates Actor to face the average/midpoint location of all actors in LookTargets. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actor - Rotate (To Look Multi-Target Midpoint)")
	static void RotateActorToLookTargetsMidpoint(AActor* Actor, TArray<AActor*> LookTargets, bool X=false, bool Y=false, bool Z=true);

	/** Returns an array of world locations, one per actor in the list. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actors - Get Location List from")
	static TArray<FVector> GetLocationArrayFromActorList(TArray<AActor*> Actors);


	//###############################################################################
	// InterpActor
	//###############################################################################

	/** Smoothly moves an Actor toward TargetLocation each tick at InterpSpeed. Call every tick. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors|Interp")
	static void InterpActorLocation(AActor* Actor, FVector TargetLocation, float InterpSpeed);

	/** Smoothly rotates an Actor toward TargetRotation each tick at InterpSpeed. X/Y/Z flags restrict which axes are affected. */
	UFUNCTION(BlueprintCallable, Category="Omega|Actors|Interp", meta=(AdvancedDisplay="X,Y,Z"))
	static void InterpActorRotation(AActor* Actor, FRotator TargetRotation, float InterpSpeed, bool X=true, bool Y=true, bool Z=true);

	//###############################################################################
	// Save
	//###############################################################################

	/** Adds or removes a set of gameplay tags from the active save game. bGlobal: use the global (cross-session) save slot. */
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta=(WorldContext = "WorldContextObject"))
	static void SetTagsAddedToSaveGame(const UObject* WorldContextObject, FGameplayTagContainer Tags, bool Saved, bool bGlobal);

	/** Branches on whether a gameplay tag query passes against the current save game's tags. bGlobal: use the global save slot. */
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta=(WorldContext = "WorldContextObject", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Check Save Tag Query")
	static void SwitchOnSaveTagQuery(const UObject* WorldContextObject, FGameplayTagQuery TagQuery, bool bGlobal, bool& Outcome);

	//###############################################################################
	// Json
	//###############################################################################

	/** Merges multiple JSON objects into a single combined object. Later entries overwrite duplicate keys. */
	UFUNCTION(BlueprintPure, Category = "Json")
	static void CombineJsonObjects(const TArray<FJsonObjectWrapper>& JsonObjects, FJsonObjectWrapper& CombinedObject);

	/** Creates a JSON object with a single integer field named FieldName. */
	UFUNCTION(BlueprintPure, Category = "Json", meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"))
	static FJsonObjectWrapper CreateJsonField(const FString& FieldName, const int32& Value);

	//###############################################################################
	// Generals
	//###############################################################################

	/** Internal check: returns true if Object implements the Omega common interface. */
	static bool Object_UsesCommonInterface(UObject* Object);


	/** Returns the display name text for Object. Tag selects the name variant; FormatText applies rich-text formatting. */
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Name",meta=(AdvancedDisplay="FormatText"))
	static FText GetObjectDisplayName(UObject* Object,FGameplayTag Tag,bool FormatText=true);
	/** Returns the display description text for Object. Tag selects the description variant; FormatText applies rich-text formatting. */
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Description",meta=(AdvancedDisplay="FormatText"))
	static FText GetObjectDisplayDescription(UObject* Object,FGameplayTag Tag,bool FormatText=true);
	/** Returns a short string label for Object (typically its internal name, used for lookups). */
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Label")
	static FString GetObjectLabel(UObject* Object);
	/** Returns the Slate brush icon for Object. Tag selects the icon variant. */
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Icon")
	static FSlateBrush GetObjectIcon(UObject* Object,FGameplayTag Tag);
	/** Returns the display color for Object. Tag selects the color variant. */
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Color")
	static FLinearColor GetObjectColor(UObject* Object,FGameplayTag Tag);

	/** Returns the string labels for all objects in the list. */
	UFUNCTION(BlueprintCallable,Category="Omega|General",DisplayName="Ω Get Labels (From Object List)")
	static TArray<FString> GetLabelsFromObjects(TArray<UObject*> Objects);
	/** Returns the first object in the list whose label matches Label, cast to Class. Outcome is false if none match. */
	UFUNCTION(BlueprintCallable,Category="Omega|General",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs = "Outcome"), DisplayName="Ω🔴 Select Object (From Label)")
	static UObject* SelectObjectFromLabel(TArray<UObject*> ObjectsIn, const FString& Label, TSubclassOf<UObject> Class,bool& Outcome);
	/** Returns only the objects from ObjectsIn whose label is present in the Labels array. */
	UFUNCTION(BlueprintCallable,Category="Omega|General", DisplayName="Ω Filter Objects (By Labels)")
	static TArray<UObject*> FilterObjectsFromLabels(TArray<UObject*> ObjectsIn, TArray<FString> Labels);


	//###############################################################################
	// Math
	//###############################################################################

	/** Returns the index of the FVector2D in Vectors that is closest to point. Also outputs the closest point. */
	UFUNCTION(BlueprintCallable,Category="Omega|Math")
	static int32 GetClosestVector2dToPoint(TArray<FVector2D> Vectors, FVector2D point, FVector2D& out_point);

	//###############################################################################
	// Lua
	//###############################################################################

	/** Reads a value from the Lua state's table identified by Tag (and optional ParentTable) and returns it. */
	UFUNCTION(BlueprintCallable,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", AdvancedDisplay="ParentTable, StateClass"))
	static FLuaValue GetLuaValueFromGameplayTag(UObject* WorldContextObject, FGameplayTag Tag, const FString& ParentTable, TSubclassOf<ULuaState> StateClass);

	/** Creates and populates a DataAsset of the given Class from a Lua value table. */
	UFUNCTION(BlueprintCallable,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static UDataAsset* CreateDataAssetFromLua(UObject* WorldContextObject, TSubclassOf<UDataAsset> Class,FLuaValue Value);

	/** Converts a Lua table of attribute name→float pairs into a TMap of OmegaAttribute pointers to float values. */
	UFUNCTION(BlueprintPure,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static TMap<UOmegaAttribute*, float> LuaToOmegaAttributes(UObject* WorldContextObject, TSubclassOf<UDataAsset> Class, FLuaValue Value);

	/** Converts a Lua table of attribute name→int pairs into a TMap of OmegaAttribute pointers to int32 values. */
	UFUNCTION(BlueprintPure,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", DeterminesOutputType="Class"), DisplayName="Lua To Omega Attributes (Int)")
	static TMap<UOmegaAttribute*, int32> LuaToOmegaAttributes_int(UObject* WorldContextObject, TSubclassOf<UDataAsset> Class, FLuaValue Value);


};




//--------------------------------------------------------------------------------------------------------------------
// Star Rank
//--------------------------------------------------------------------------------------------------------------------
UCLASS()
class UOmegaStarRankFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** Returns a 0–1 float representing the star rank (e.g. 0 stars = 0.0, 3/5 stars = 0.6, 5 stars = 1.0). */
	UFUNCTION(BlueprintPure, Category="Omega|StarRank")
	static float GetFloatFromStarRank(EOmegaStarRank Rank);

	/** Returns a 0–5 integer representing the star rank (e.g. 0 stars = 0, 3 stars = 3, 5 stars = 5). */
	UFUNCTION(BlueprintPure, Category="Omega|StarRank")
	static int32 GetIntFromStarRank(EOmegaStarRank Rank);

};

UCLASS()
class UOmegaCurveFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** Evaluates a runtime float curve at the given time and returns the resulting value. */
	UFUNCTION(BlueprintPure,Category="Omega|Math|Curve")
	float GetCurveValueFromTime(FRuntimeFloatCurve curve,float time);

};

/** Optional metadata object that can be attached to any asset via the AssetUserData system. */
UCLASS(BlueprintType,Blueprintable)
class UOmegaAssetMetadata : public UAssetUserData
{
	GENERATED_BODY()

public:
};
