// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaGameplaySubsystem.h"
#include "GameplayTagContainer.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "Kismet/GameplayStatics.h"
#include "Player/OmegaInputMode.h"
#include "OmegaGameFrameworkBPLibrary.generated.h"

class APlayerController;
class UEnhancedInputLocalPlayerSubsystem;
class UOmegaPlayerSubsystem;


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

	//###############################################################################
	// Gameplay tags
	//###############################################################################

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static bool IsObjectOfGameplayCategory(UObject* Object, FGameplayTag CategoryTag, bool bExact);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static bool DoesObjectHaveGameplayTag(UObject* Object, FGameplayTag GameplayTag, bool bExact);
	
	//Exact: Exact tag? | Exclude: if true, will exclude matching objects instead of including them.
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class", DeterminesOutputType="Class"))
	static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag CategoryTag,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class);

	//Exact: Exact tag? | Exclude: if true, will exclude matching objects instead of including them.
	UFUNCTION(BlueprintPure, Category = "Omega|Assets", meta=(AdvancedDisplay="bExact, bExclude, bInvertCheck, Class", DeterminesOutputType="Class"))
	static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer GameplayTags,
		bool bExact, bool bExclude, TSubclassOf<UObject> Class);

	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags")
	static FGameplayTagContainer FilterTagsByType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn);
	
	UFUNCTION(BlueprintPure, Category="Omega|Assets", meta=(DeterminesOutputType="Class", AdvancedDisplay="bExclude"))
	static TArray<UObject*> FilterObjectsByClass(TArray<UObject*> Objects, TSubclassOf<UObject> Class, bool bExclude);

	//###############################################################################
	// System
	//###############################################################################
	
	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static void SetGameplaySystemActive(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem> SystemClass, bool bActive, const FString Flag, UObject* Context);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static void SetGameplaySystemsActive(const UObject* WorldContextObject, TArray<TSubclassOf<AOmegaGameplaySystem>> SystemClasses, bool bActive, const FString Flag, UObject* Context);
	
	UFUNCTION(BlueprintPure, Category="Ω|Assets", meta=(DeterminesOutputType="Class", AdvancedDisplay="bExclude"))
	static UObject* SelectObjectByName(TArray<UObject*> Objects, const FString& Name);

	//###############################################################################
	// Player
	//###############################################################################
	UFUNCTION(BlueprintPure, Category="Omega|Gameplay|Player")
	static AActor* GetPlayerMouseOverActor(APlayerController* Player, ETraceTypeQuery TraceChannel, float TraceSphereRadius);

	UFUNCTION(BlueprintCallable, Category="Omega|Gameplay|Player", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Player"))
	static void SetPlayerCustomInputMode(const UObject* WorldContextObject, APlayerController* Player,  UOmegaInputMode* InputMode);

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
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager", meta=(WorldContext = "WorldContextObject", ExpandEnumAsExecs = "Outcome"))
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

	UFUNCTION(BlueprintPure, Category="Omega|Actors")
	static AActor* GetClosestActorToPoint(TArray<AActor*> Actors, FVector Point);

	// True = (ActorHiddenInGame=false, Collision=Enabled, TimeDilation=1 | False = (ActorHiddenInGame=true, Collision=Disabled, TimeDilation=0)
	UFUNCTION(BlueprintCallable, Category="Omega|Actors")
	static void SetActorActive(AActor* Actor, bool bIsActive);
	
};
