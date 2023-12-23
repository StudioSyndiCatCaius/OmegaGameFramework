// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaGameplaySubsystem.h"
#include "GameplayTagContainer.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectWrapper.h"
#include "Engine/AssetUserData.h"
#include "OmegaGeneralEnums.h"
#include "AssetRegistry/AssetData.h"
#include "Components/ScrollBox.h"
#include "OmegaGameFrameworkBPLibrary.generated.h"

class APlayerController;
class UEnhancedInputLocalPlayerSubsystem;
class UOmegaPlayerSubsystem;
class UOmegaInputMode;


UENUM(Blueprintable)
enum EOmegaFlagResult
{
	Flag_Active	UMETA(DisplayName = "Activate"),
	Flag_Inactive	UMETA(DisplayName = "Inactive"),
};


UCLASS()
class UOmegaGameFrameworkBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//###############################################################################
	// Gameplay tags
	//###############################################################################

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"))
	static FGameplayTagContainer GetObjectGameplayTags(UObject* Object);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static bool IsObjectOfGameplayCategory(UObject* Object, FGameplayTag CategoryTag, bool bExact);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags", meta=(Keywords="has"))
	static bool DoesObjectHaveGameplayTag(UObject* Object, FGameplayTag GameplayTag, bool bExact);
	
	//Exact: Exact tag? | Exclude: if true, will exclude matching objects instead of including them.
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class,bIncludeOnEmptyTag", DeterminesOutputType="Class"))
	static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag CategoryTag,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag);

	//Exact: Exact tag? | Exclude: if true, will exclude matching objects instead of including them.
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class,bIncludeOnEmptyTag", DeterminesOutputType="Class"))
	static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer GameplayTags,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer FilterTagsByType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTag GetFirstTagOfType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);
	
	UFUNCTION(BlueprintPure, Category="Omega|Assets", meta=(DeterminesOutputType="Class", AdvancedDisplay="bExclude"))
	static TArray<UObject*> FilterObjectsByClass(TArray<UObject*> Objects, TSubclassOf<UObject> Class, bool bExclude);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTag MakeGameplayTagFromString(const FString& String);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer MakeGameplayTagContainerFromStrings(TArray<FString> Strings);
	
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FString GetLastGameplayTagString(const FGameplayTag& GameplayTag);
	//###############################################################################
	// System
	//###############################################################################
	
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static void SetGameplaySystemActive(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass, bool bActive, const FString Flag, UObject* Context);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static void SetGameplaySystemsActive(const UObject* WorldContextObject, TArray<TSubclassOf<AOmegaGameplaySystem>> SystemClasses, bool bActive, const FString Flag, UObject* Context);

	//###############################################################################
	// Object
	//###############################################################################
	UFUNCTION(BlueprintPure, Category="Omega|Object")
	static UObject* SelectObjectByName(TArray<UObject*> Objects, const FString& Name);

	UFUNCTION(BlueprintPure, Category="Omega|Object")
	static const TArray<FString> GetDisplayNamesFromObjects(TArray<UObject*> Objects);
	
	//###############################################################################
	// Player
	//###############################################################################
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay|Player")
	static AActor* GetPlayerMouseOverActor(APlayerController* Player, ETraceTypeQuery TraceChannel, float TraceSphereRadius);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay|Player", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Player"))
	static void SetPlayerCustomInputMode(const UObject* WorldContextObject, APlayerController* Player,  UOmegaInputMode* InputMode);

	UFUNCTION(BlueprintPure, Category="Omega|Gameplay|Player")
	static float  GetPlayerCameraFadeAmount(APlayerController* Player);
	
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay|Player")
	static FLinearColor  GetPlayerCameraFadeColor(APlayerController* Player);
	
	//###############################################################################
	// Actor Binding
	//###############################################################################
	
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject"))
	static void SetGlobalActorBinding(const UObject* WorldContextObject, FName Binding, AActor* Actor);
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject"))
	static void ClearGlobalActorBinding(const UObject* WorldContextObject, FName Binding);
	UFUNCTION(BlueprintPure, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject"))
	static AActor* GetGlobalActorBinding(const UObject* WorldContextObject, FName Binding);

	//###############################################################################
	// Quick Get
	//###############################################################################

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintPure, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="SystemClass", CompactNodeTitle="Gameplay System"))
	static AOmegaGameplaySystem* GetActiveGameplaySystem(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass);
	
	//Get an Active Gameplay Module by Class
	UFUNCTION(BlueprintPure, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="ModuleClass", CompactNodeTitle="Gameplay Module"))
	static UOmegaGameplayModule* GetGameplayModule(const UObject* WorldContextObject, TSubclassOf<UOmegaGameplayModule> ModuleClass);

	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta=(WorldContext = "WorldContextObject", AdvancedDisplay="Context"))
	static void FireGlobalEvent(const UObject* WorldContextObject, FName Event, UObject* Context);

	//###############################################################################
	// Flag
	//###############################################################################

	//Reutrns "Inactive" until game flag is Active, then sets the flag back to "Inactive"
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager", DisplayName="Switch on Flag Active", meta=(WorldContext = "WorldContextObject", ExpandEnumAsExecs = "Outcome"))
	static void OnFlagActiveReset(const UObject* WorldContextObject, const FString& Flag, bool bDeactivateFlagOnActive, TEnumAsByte<EOmegaFlagResult>& Outcome);

	//###############################################################################
	// Actor
	//###############################################################################
	
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetActorTagActive(AActor* Actor, FName Tag, bool bIsActive);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Tags")
	static void SetComponentTagActive(UActorComponent* Component, FName Tag, bool bIsActive);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors")
	static TArray<AActor*> GetActorsFromComponents(TArray<UActorComponent*> Components);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="ComponentClass"))
	static TArray<UActorComponent*> GetComponentsFromActors(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static AActor* GetClosestActorToPoint(TArray<AActor*> Actors, FVector Point);

	// True = (ActorHiddenInGame=false, Collision=Enabled, TimeDilation=1 | False = (ActorHiddenInGame=true, Collision=Disabled, TimeDilation=0)
	UFUNCTION(BlueprintCallable, Category="Omega|Actors")
	static void SetActorActive(AActor* Actor, bool bIsActive);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(AdvancedDisplay="ExcludedActors"))
	static TArray<AActor*> FilterActorsWithComponents(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass, TArray<AActor*> ExcludedActors);

	//Will attempt to get a component, casting the object as component, and actor, or a sibling component.
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandEnumAsExecs = "Outcome"))
	static UActorComponent* TryGetComponentFromObject(UObject* Object, TSubclassOf<UActorComponent> Class, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(DeterminesOutputType="Class", ExpandEnumAsExecs = "Outcome"))
	static UActorComponent* TryGetFirstComponentWithTag(UObject* Object, TSubclassOf<UActorComponent> Class, FName Tag, TEnumAsByte<EOmegaFunctionResult>& Outcome);

	UFUNCTION(BlueprintPure, Category="Omega|Actors", meta=(DeterminesOutputType="Class", AdvancedDisplay="ExcludedActors"))
	static TArray<AActor*> FilterActorsWithTag(TArray<AActor*> Actors, FName Tag, bool bExclude,TSubclassOf<AActor> Class);

	UFUNCTION(BlueprintPure, Category="Omega|Actors", meta=(DeterminesOutputType="Class", AdvancedDisplay="ExcludedActors"))
	static TArray<UActorComponent*> FilterComponentsWithTag(TArray<UActorComponent*> Components, FName Tag, bool bExclude,TSubclassOf<UActorComponent> Class);
	
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

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta=(WorldContext = "WorldContextObject", ExpandEnumAsExecs = "Outcome"))
	static void SwitchOnSaveTagQuery(const UObject* WorldContextObject, FGameplayTagQuery TagQuery, bool bGlobal, TEnumAsByte<EOmegaFunctionResult>& Outcome);

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
	UFUNCTION(BlueprintPure, Category="Omega|General")
	static FText GetObjectDisplayName(UObject* Object);
	UFUNCTION(BlueprintPure, Category="Omega|General")
	static FText GetObjectDisplayDescription(UObject* Object);
	UFUNCTION(BlueprintPure, Category="Omega|General")
	static FString GetObjectLabel(UObject* Object);
	
	//###############################################################################
    // MetaData
    //###############################################################################
	//UFUNCTION(BlueprintPure, Category="Omega|MetaData", meta=(DeterminesOutputType="Class"))
	//UOmegaAssetMetadata* GetMetadataFromObject(UObject* Object, TSubclassOf<UOmegaAssetMetadata> Class);

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
class UOmegaWidgetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	
};

UCLASS(BlueprintType,Blueprintable)
class UOmegaAssetMetadata : public UAssetUserData
{
	GENERATED_BODY()

public:
};