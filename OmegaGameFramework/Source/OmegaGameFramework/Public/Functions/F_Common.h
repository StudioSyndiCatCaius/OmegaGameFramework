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

UENUM(Blueprintable)
enum EOmegaFlagResult
{
	Flag_Active		UMETA(DisplayName = "Activate"),
	Flag_Inactive	UMETA(DisplayName = "Inactive"),
};


USTRUCT(BlueprintType)
struct FOmegaAssetSearchConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bLoadExternal=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bSortedAssets=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bQuickAccess=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bClassGameplayConfig=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bGameCoreOverride=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Asset Search") bool bLogProcess=false;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameFrameworkBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static FText L_TextFormatObject(UObject* obj, FText t);

public:
	
	UFUNCTION(BlueprintPure, Category="Omega|Settings", meta=(Keywords="has"),DisplayName="Ω Get Settings - Omega")
	static UOmegaSettings* GetSettings_Omega();
	UFUNCTION(BlueprintPure, Category="Omega|Settings", meta=(Keywords="has"),DisplayName="Ω Get Settings - Style")
	static UOmegaStyleSettings* GetSettings_Style();
	UFUNCTION(BlueprintPure, Category="Omega|Settings", meta=(Keywords="has"),DisplayName="Ω Get Settings - Asset")
	static UOmegaAssetSettings* GetSettings_Asset();
	
	//###############################################################################
	// WORLD GLOBALS
	//###############################################################################
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject"))
	static AOmegaWorldManager* GetOmegaWorldManager(UObject* WorldContextObject);
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject"),DisplayName="World Manager - Get Combatant")
	static UCombatantComponent* GetGlobalCombatant(UObject* WorldContextObject);
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject"),DisplayName="World Manager - Get Entity Instance")
	static AOmegaInstancedEntity* GetGlobalEntityInstance(UObject* WorldContextObject,UObject* ID);
	
	
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject"),DisplayName="World Manager - Get Squad")
	static void GetGlobalSquad_CurrentIdentity(UObject* WorldContextObject, UAssetSquadComponent*& Component, UAssetSquad_Identity*& CurrentSquad);
	
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject"),DisplayName="World Manager - Get Entity Instance (from Identities)")
	static TArray<AOmegaInstancedEntity*> GetGlobalEntityInstances_FromIDs(UObject* WorldContextObject,TArray<UPrimaryDataAsset*> IDs);
	UFUNCTION(BlueprintPure, Category="Omega|World",meta=(WorldContext="WorldContextObject"),DisplayName="World Manager - Get Entity Instance (from Squad)")
	static TArray<AOmegaInstancedEntity*> GetGlobalEntityInstances_FromSquad(UObject* WorldContextObject,UAssetSquad_Identity* Squad);
	
	//###############################################################################
	// Gameplay tags
	//###############################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|GameplayTags",DisplayName="Object - Fire Tag Event")
	static void Object_TagEvent(UObject* Object, UPARAM(meta=(Categories="EVENT")) FGameplayTag Event, FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags",DisplayName="Object - Check Tag Query")
	static bool Object_TagQuery(UObject* Object, UPARAM(meta=(Categories="QUERY")) FGameplayTag Event, FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Ω Has Gameplay Tags (Adv.)")
	static bool HasTags_Advance(FGameplayTagContainer Tags, FGameplayTagContainer Has, bool bAll, bool bExact);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Get Gameplay Tags")
	static FGameplayTagContainer GetObjectGameplayTags(UObject* Object);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Get Gameplay Category")
	static FGameplayTag GetObjectGameplayCategory(UObject* Object);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags",DisplayName="Ω Is Object of Gameplay Category")
	static bool IsObjectOfGameplayCategory(UObject* Object, FGameplayTag CategoryTag, bool bExact);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Gameplay Tags - Has Tag")
	static bool DoesObjectHaveGameplayTag(UObject* Object, FGameplayTag GameplayTag, bool bExact);
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"),DisplayName="Object - Gameplay Tags - Has Tags")
	static bool DoesObjectHaveGameplayTags(UObject* Object, const FGameplayTagContainer& GameplayTags, bool bExact, bool bValidIfEmpty=true);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags",DisplayName="Object - Gameplay Tags - Query")
	static bool QueryObjectGameplayTags(UObject* Object, FGameplayTagQuery Query, bool bEmptyReturnsTrue=true);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer FilterTagsByType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTag GetFirstTagOfType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTag MakeGameplayTagFromString(const FString& String);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer MakeGameplayTagContainerFromStrings(TArray<FString> Strings);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FString GetLastGameplayTagString(const FGameplayTag& GameplayTag);
	
	//###############################################################################
	// System
	//###############################################################################
	
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject")) 
	static bool IsSystemTagActive(const UObject* WorldContextObject,UPARAM(meta=(Categories="SYSTEM")) FGameplayTag Tag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static void SetGameplaySystemActive(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass, bool bActive, const FString Flag, UObject* Context);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static void SetGameplaySystemsActive(const UObject* WorldContextObject, TArray<TSubclassOf<AOmegaGameplaySystem>> SystemClasses, bool bActive, const FString Flag, UObject* Context);

	//###############################################################################
	// Object
	//###############################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Object",meta=(DeterminesOutputType="Class"),DisplayName="Objects - Resolve Soft Array")
	static TArray<UObject*> ResolveSoftArray_Object(TArray<TSoftObjectPtr<UObject>> List, TSubclassOf<UObject> Class);
	UFUNCTION(BlueprintCallable, Category="Omega|Object",meta=(DeterminesOutputType="Class"))
	static TArray<TSubclassOf<UObject>> ResolveSoftArray_Class(TArray<TSoftClassPtr<UObject>> List);
	
	UFUNCTION(BlueprintPure, Category="Omega|Assets", meta=(DeterminesOutputType="Class", AdvancedDisplay="bExclude"),DisplayName="Object - Filter (by Class)")
	static TArray<UObject*> FilterObjectsByClass(TArray<UObject*> Objects, TSubclassOf<UObject> Class, bool bExclude);
	
	//Exact: Exact tag? | Exclude: if true, will exclude matching objects instead of including them.
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class,bIncludeOnEmptyTag", 
		DeterminesOutputType="Class"),DisplayName="Object - Filter (by Category Tag)")
	static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag CategoryTag,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag);

	//Exact: Exact tag? | Exclude: if true, will exclude matching objects instead of including them.
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class,bIncludeOnEmptyTag", 
		DeterminesOutputType="Class"),DisplayName="Object - Filter (by Gameplay Tags)")
	static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer GameplayTags,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExclude, Class",
		DeterminesOutputType="Class"),DisplayName="Object - Filter (by Interface)")
	static TArray<UObject*> FilterObjectsWithInterface(TArray<UObject*> Objects, TSubclassOf<UInterface> Interface, bool bExclude, TSubclassOf<UObject> Class);
	
	UFUNCTION(BlueprintPure, Category="Omega|Object",DisplayName="Object - Select (by Name)")
	static UObject* SelectObjectByName(TArray<UObject*> Objects, const FString& Name);

	UFUNCTION(BlueprintPure, Category="Omega|Object",DisplayName="Objects - Get Display Names")
	static const TArray<FString> GetDisplayNamesFromObjects(TArray<UObject*> Objects);

	UFUNCTION(BlueprintPure,Category="Omega|Object") static FGuid GetObjectGUID(UObject* Object);
	UFUNCTION(BlueprintPure,Category="Omega|Object") static int32 GetObjectSeed(UObject* Object);
	
	//###############################################################################
	// Asset Getter
	//###############################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class"),DisplayName="Assets - Get All of Class")
	static TArray<UObject*> GetAllAssetsOfClass(TSubclassOf<UObject> Class, bool bIncludeSubclasses=false, FGameplayTag FilterCategory=FGameplayTag());
	
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome")
	,DisplayName="Ω🔴 Get Asset (Adjacent to Reference)")
	static UObject* GetAsset_AdjacentToReference(TSoftObjectPtr<UObject> Reference, const FString& Prefix,const FString& Suffix, const FString& Subdir,const FString& RemovedString,TSubclassOf<UObject> Class,bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Directory, Prefix, Sufix, config")
		,DisplayName="Ω🔴 Get Asset (from Path)")
	static UObject* GetAsset_FromPath(const FString& AssetPath, TSubclassOf<UObject> Class, bool& Outcome,const FString& Directory="", FOmegaAssetSearchConfig config=FOmegaAssetSearchConfig());

	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get Assets List (from Path)")
	static TArray<UObject*> GetAssets_FromPath(const FString& path, bool bRecursive, TSubclassOf<UObject> Class);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get Assets List (from Paths)")
	static TArray<UObject*> GetAssetList_FromPath(const TArray<FString> AssetPaths, TSubclassOf<UObject> Class);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Class (from Path)")
	static UClass* GetClass_FromPath(const FString& AssetPath, TSubclassOf<UObject> Class, bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Asset (from Lua Field)")
	static UObject* GetAsset_FromLuaField(FLuaValue Lua, const FString& Field, TSubclassOf<UObject> Class, bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Assets", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Class (from Lua Field)")
	static UClass* GetClass_FromLuaField(FLuaValue Lua, const FString& Field, TSubclassOf<UObject> Class, bool& Outcome);
	
	//###############################################################################
	// Player
	//###############################################################################
	UFUNCTION(BlueprintPure, Category="Omega|Player")
	static AActor* GetPlayerMouseOverActor(const APlayerController* Player, ETraceTypeQuery TraceChannel, float TraceSphereRadius);

	UFUNCTION(BlueprintCallable, Category="Omega|Player", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Player"))
	static void SetPlayerCustomInputMode(const UObject* WorldContextObject, APlayerController* Player,  UOmegaInputMode* InputMode);

	UFUNCTION(BlueprintPure, Category="Omega|Player")
	static float  GetPlayerCameraFadeAmount(const APlayerController* Player);
	
	UFUNCTION(BlueprintPure, Category="Omega|Player")
	static FLinearColor  GetPlayerCameraFadeColor(const APlayerController* Player);
	
	//###############################################################################
	// Actor Binding
	//###############################################################################
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - SET")
	static void SetGlobalActorBinding(const UObject* WorldContextObject, FName Binding, AActor* Actor);
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - CLEAR")
	static void ClearGlobalActorBinding(const UObject* WorldContextObject, FName Binding);
	UFUNCTION(BlueprintPure, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"),DisplayName="Actor - Global Binding - GET")
	static AActor* GetGlobalActorBinding(const UObject* WorldContextObject, FName Binding);

	
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject"))
	static void SetTaggedActorBinding(const UObject* WorldContextObject, FGameplayTag Binding, AActor* Actor);
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs="result",DeterminesOutputType="Class"))
	static AActor* CheckTaggedActorBinding(const UObject* WorldContextObject, FGameplayTag Binding, TSubclassOf<AActor> Class, bool& result);
	
	//###############################################################################
	// Quick Get
	//###############################################################################

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="SystemClass", ExpandBoolAsExecs="result"))
	static AOmegaGameplaySystem* GetActiveGameplaySystem(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass, bool& result);

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="Component",ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Get Gameplay System (w/ Component)")
	static UActorComponent* GetFirstActiveGameplaySystemWithComponent(const UObject* WorldContextObject, TSubclassOf<UActorComponent> Component, FName RequiredTag, AOmegaGameplaySystem*& system, bool& Outcome);
	
	//Get an Active Gameplay Module by Class
	UFUNCTION(BlueprintPure, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="ModuleClass"))
	static UOmegaGameplayModule* GetGameplayModule(const UObject* WorldContextObject, TSubclassOf<UOmegaGameplayModule> ModuleClass, bool bFallbackToDefault=false);

	//Get an Active Gameplay Module by Class
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="ModuleClass",ExpandBoolAsExecs="Outcome"))
	static UOmegaGameplayModule* TryGetGameplayModule(const UObject* WorldContextObject, TSubclassOf<UOmegaGameplayModule> ModuleClass, bool& Outcome, bool bFallbackToDefault=false);
	
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta=(WorldContext = "WorldContextObject", AdvancedDisplay="Context"),DisplayName="Fire Global Event (Named)")
	static void FireGlobalEvent(const UObject* WorldContextObject, FName Event, UObject* Context, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta=(WorldContext = "WorldContextObject", AdvancedDisplay="Context"),DisplayName="Fire Global Event (Tagged)")
	static void FireTaggedGlobalEvent(const UObject* WorldContextObject, FGameplayTag Event, UObject* Context, FOmegaCommonMeta meta);
	
	//###############################################################################
	// Actor
	//###############################################################################
	
	
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetActorTagActive(AActor* Actor, FName Tag, bool bIsActive);

	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetActorTagListActive(AActor* Actor, TArray<FName> Tags, bool bIsActive);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetComponentTagActive(UActorComponent* Component, FName Tag, bool bIsActive);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(DeterminesOutputType="Class"))
	static TArray<AActor*> GetActorsFromComponents(TArray<UActorComponent*> Components,TSubclassOf<UActorComponent> Class=nullptr);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(DeterminesOutputType="ActorClass"))
	static TArray<AActor*> GetActorsFromChildActorComponents(TArray<UChildActorComponent*> Components, TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="ComponentClass"))
	static TArray<UActorComponent*> GetComponentsFromActors(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static TArray<FVector2D> GetActorPositionVectors2D(TArray<AActor*> Actors, const APlayerController* Player, bool ViewportRelative);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static AActor* GetClosestActorToPoint(TArray<AActor*> Actors, FVector Point);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(DeterminesOutputType="FilterClass"))
	static AActor* GetClosestOverlappingActor(UPrimitiveComponent* OverlappedComponent,TSubclassOf<AActor> FilterClass);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static AActor* GetClosestActorToViewportPoint2D(TArray<AActor*> Actors, FVector2D Point, const APlayerController* Player, bool ViewportRelative);

	// True = (ActorHiddenInGame=false, Collision=Enabled, TimeDilation=1 | False = (ActorHiddenInGame=true, Collision=Disabled, TimeDilation=0)
	UFUNCTION(BlueprintCallable, Category="Omega|Actors")
	static void SetActorActive(AActor* Actor, bool bIsActive);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(AdvancedDisplay="ExcludedActors"))
	static TArray<AActor*> FilterActorsWithComponents(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Try Get Actor (From Object)")
	static AActor* TryGetActorFromObject(UObject* Object, TSubclassOf<AActor> Class, bool& Outcome);

	//Will attempt to get a component, casting the object as component, and actor, or a sibling component.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Try Get Component (From Object)")
	static UActorComponent* TryGetComponentFromObject(UObject* Object, TSubclassOf<UActorComponent> Class, bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Try Get Component (First with Tag)")
	static UActorComponent* TryGetFirstComponentWithTag(UObject* Object, TSubclassOf<UActorComponent> Class, FName Tag, bool& Outcome);

	UFUNCTION(BlueprintPure, Category="Omega|Actors", meta=(DeterminesOutputType="Class", AdvancedDisplay="ExcludedActors"))
	static TArray<AActor*> FilterActorsWithTag(TArray<AActor*> Actors, FName Tag, bool bExclude,TSubclassOf<AActor> Class);

	UFUNCTION(BlueprintPure, Category="Omega|Actors", meta=(DeterminesOutputType="Class", AdvancedDisplay="ExcludedActors"))
	static TArray<UActorComponent*> FilterComponentsWithTag(TArray<UActorComponent*> Components, FName Tag, bool bExclude,TSubclassOf<UActorComponent> Class);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject",DeterminesOutputType="Class"))
	static AActor* Quick_SpawnActor(UObject* WorldContextObject, TSubclassOf<AActor> Class, FTransform Transform, const TArray<FName> Tags);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject", AdvancedDisplay="Player"))
	static void SetActorInputEnabled(UObject* WorldContextObject, AActor* Actor, bool bEnabled, APlayerController* Player);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Try Get Child Actor As Class")
	static AActor* TryGetChildActorAsClass(UChildActorComponent* ChildActor, TSubclassOf<AActor> Class, bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class"),DisplayName="Ω Get Actors (from Hit Results)")
	static TArray<AActor*> GetActorsFromHitResults(TArray<FHitResult> Hits, TSubclassOf<AActor> Class);

	// -- ROTATE ACTOR

	//Rotates an Actor to aim at a Location
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actor - Rotate (To Look Location)")
	static void RotateActorToLookLocation(AActor* Actor, FVector Location, bool X=false, bool Y=false, bool Z=true);
	
	//Rotates an Actor to aim at an actor
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actor - Rotate (To Look Target)")
	static void RotateActorToLookTarget(AActor* Actor, AActor* LookTarget, bool X=false, bool Y=false, bool Z=true);

	//Rotates an Actor to aim at the average location of an actor list
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actor - Rotate (To Look Multi-Target Midpoint)")
	static void RotateActorToLookTargetsMidpoint(AActor* Actor, TArray<AActor*> LookTargets, bool X=false, bool Y=false, bool Z=true);
	
	//Gets the locations of every actor in the list
	UFUNCTION(BlueprintCallable, Category="Omega|Actor", meta=(AdvancedDisplay="X,Y,Z"),DisplayName="Actors - Get Location List from")
	static TArray<FVector> GetLocationArrayFromActorList(TArray<AActor*> Actors);
	
	
	//###############################################################################
	// InterpActor
	//###############################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|Actors|Interp")
	static void InterpActorLocation(AActor* Actor, FVector TargetLocation, float InterpSpeed);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors|Interp", meta=(AdvancedDisplay="X,Y,Z"))
	static void InterpActorRotation(AActor* Actor, FRotator TargetRotation, float InterpSpeed, bool X=true, bool Y=true, bool Z=true);
	
	//###############################################################################
	// Save
	//###############################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta=(WorldContext = "WorldContextObject"))
	static void SetTagsAddedToSaveGame(const UObject* WorldContextObject, FGameplayTagContainer Tags, bool Saved, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta=(WorldContext = "WorldContextObject", ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Check Save Tag Query")
	static void SwitchOnSaveTagQuery(const UObject* WorldContextObject, FGameplayTagQuery TagQuery, bool bGlobal, bool& Outcome);

	//###############################################################################
	// Json
	//###############################################################################
	
	UFUNCTION(BlueprintPure, Category = "Json")
	static void CombineJsonObjects(const TArray<FJsonObjectWrapper>& JsonObjects, FJsonObjectWrapper& CombinedObject);

	UFUNCTION(BlueprintPure, Category = "Json", meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"))
	static FJsonObjectWrapper CreateJsonField(const FString& FieldName, const int32& Value);

	//###############################################################################
	// Generals
	//###############################################################################
	static bool Object_UsesCommonInterface(UObject* Object);
	
	
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Name",meta=(AdvancedDisplay="FormatText"))
	static FText GetObjectDisplayName(UObject* Object,FGameplayTag Tag,bool FormatText=true);
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Description",meta=(AdvancedDisplay="FormatText"))
	static FText GetObjectDisplayDescription(UObject* Object,FGameplayTag Tag,bool FormatText=true);
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Label")
	static FString GetObjectLabel(UObject* Object);
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Icon")
	static FSlateBrush GetObjectIcon(UObject* Object,FGameplayTag Tag);
	UFUNCTION(BlueprintPure, Category="Omega|General",DisplayName="Object - Get Color")
	static FLinearColor GetObjectColor(UObject* Object,FGameplayTag Tag);

	UFUNCTION(BlueprintCallable,Category="Omega|General",DisplayName="Ω Get Labels (From Object List)")
	static TArray<FString> GetLabelsFromObjects(TArray<UObject*> Objects);
	UFUNCTION(BlueprintCallable,Category="Omega|General",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs = "Outcome"), DisplayName="Ω🔴 Select Object (From Label)") 
	static UObject* SelectObjectFromLabel(TArray<UObject*> ObjectsIn, const FString& Label, TSubclassOf<UObject> Class,bool& Outcome);
	UFUNCTION(BlueprintCallable,Category="Omega|General", DisplayName="Ω Filter Objects (By Labels)") 
	static TArray<UObject*> FilterObjectsFromLabels(TArray<UObject*> ObjectsIn, TArray<FString> Labels);


	//###############################################################################
	// Math
	//###############################################################################

	UFUNCTION(BlueprintCallable,Category="Omega|Math")
	static int32 GetClosestVector2dToPoint(TArray<FVector2D> Vectors, FVector2D point, FVector2D& out_point);
	
	//###############################################################################
	// Lua
	//###############################################################################
	UFUNCTION(BlueprintCallable,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", AdvancedDisplay="ParentTable, StateClass"))
	static FLuaValue GetLuaValueFromGameplayTag(UObject* WorldContextObject, FGameplayTag Tag, const FString& ParentTable, TSubclassOf<ULuaState> StateClass);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static UDataAsset* CreateDataAssetFromLua(UObject* WorldContextObject, TSubclassOf<UDataAsset> Class,FLuaValue Value);

	UFUNCTION(BlueprintPure,Category="Omega|Lua",meta=(WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static TMap<UOmegaAttribute*, float> LuaToOmegaAttributes(UObject* WorldContextObject, TSubclassOf<UDataAsset> Class, FLuaValue Value);

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

	//Gets a value from 0-1 based on the star rank. R.G. ☆☆☆☆☆ = 0.0, ★★★☆☆ = 0.6, ★★★★★ = 1
	UFUNCTION(BlueprintPure, Category="Omega|StarRank")
	static float GetFloatFromStarRank(EOmegaStarRank Rank);

	//Gets a value from 0-5 based on the star rank. R.G. ☆☆☆☆☆ = 0, ★★★☆☆ = 3, ★★★★★ = 5
	UFUNCTION(BlueprintPure, Category="Omega|StarRank")
	static int32 GetIntFromStarRank(EOmegaStarRank Rank);
	
};

UCLASS()
class UOmegaCurveFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Math|Curve")
	float GetCurveValueFromTime(FRuntimeFloatCurve curve,float time);
	
};

UCLASS(BlueprintType,Blueprintable)
class UOmegaAssetMetadata : public UAssetUserData
{
	GENERATED_BODY()

public:
};