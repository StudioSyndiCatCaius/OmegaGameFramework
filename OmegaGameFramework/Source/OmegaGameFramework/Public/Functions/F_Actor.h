// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "F_Component.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Condition/Condition_Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"

#include "F_Actor.generated.h"

class UOmegaActorConfig;

// =====================================================================================================================
// ACTOR
// =====================================================================================================================

class UArrowComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Returns true if the object implements the Omega common interface. */
	static bool UsesInterface(UObject* obj);

	/** Sets the editor-facing label of the Actor (the name shown in the Outliner). No-op and returns false in non-editor builds.
	 *  RandIdRange: if another actor already has the same label, appends _N (random 1–9999) to avoid collisions.
	 *  bOnlyIfDefaultName: skips the rename if the actor's current label is not the auto-generated default (ClassName or ClassName_N). */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",DisplayName="Actor - Set Editor Label",meta=(AdvancedDisplay="RandIdRange,bOnlyIfDefaultName"))
	static bool Label_Set(AActor* Actor, const FString& Label, bool RandIdRange=false, bool bOnlyIfDefaultName=false);

	/** Returns the editor-facing label of the Actor (the name shown in the Outliner). Returns an empty string in non-editor builds. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor",DisplayName="Actor - Get Editor Label")
	static FString Label_Get(AActor* Actor);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static bool TeleportActorToReferencePoint(AActor* Actor, AActor* Point, bool bLocation=true,bool bRotation=true,
		bool bScale=false,bool bKeepVelocity=false);
	
	/** Performs a line trace and snaps the Actor to the first surface hit between Trace_Start and Trace_End. */
	UFUNCTION(BlueprintCallable,Category="Actor Condition")
	static void SnapActorToSurface(AActor* Actor, FVector Trace_Start,FVector Trace_End, TEnumAsByte<EObjectTypeQuery> CollisionType);

	/** Evaluates a set of actor conditions against the given Actor. Returns true if all conditions pass. */
	UFUNCTION(BlueprintCallable,Category="Actor Condition")
	static bool CheckActorCondition(AActor* Actor, FOmegaConditions_Actor Conditions);

	/** Checks whether the Actor is a player-controlled pawn. Outputs the Pawn and PlayerController if true. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(ExpandBoolAsExecs="Result"))
	static bool IsActorPlayer(AActor* Actor, APawn*& Pawn, APlayerController*& Controller, bool& Result);

	/** Applies an OmegaActorConfig data asset to the Actor, setting its properties accordingly. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static void ApplyActorConfigAsset(AActor* Actor, UOmegaActorConfig* Config);

	/** Reconfigures a ChildActorComponent with a new class, identity asset, and owner. Returns the new child actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static AActor* ConfigureChildActor(UChildActorComponent* ChildActor, TSubclassOf<AActor> NewClass, UPrimaryDataAsset* NewIdentity, AActor* NewOwner);

	/** Attaches a SceneComponent to the root (or named socket) of an Actor using the specified attachment rules. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(AdvancedDisplay="LocationRule,RotationRule,ScaleRule,bWeldSimulateBodies"))
	static void AttachComponentToActor(USceneComponent* Component, AActor* Actor, FName Socket="",
		EAttachmentRule LocationRule=EAttachmentRule::SnapToTarget,
		EAttachmentRule RotationRule=EAttachmentRule::SnapToTarget,
		EAttachmentRule ScaleRule=EAttachmentRule::SnapToTarget,
		bool bWeldSimulateBodies=true);

	/** From the given Actors list, returns the one whose screen position is closest to ScreenPoint. Also outputs the distance. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static AActor* GetActorNearestToScreenPoint(const TArray<AActor*>& Actors,const FVector2D& ScreenPoint, APlayerController* PlayerController,float& OutDistance);

	/** Pauses or unpauses actors belonging to the given PauseGroup gameplay tag. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(WorldContext="WorldContext"),DisplayName="Actors - Set Paused")
	static void SetPaused(UObject* WorldContext, UPARAM(meta=(Categories="PAUSE")) FGameplayTag PauseGroup, bool bPaused);

	// =====================================================================================================================
    // Filters
    // =====================================================================================================================

	/** Returns actors from the list whose distance to the given vector is within (or outside, if inverted) the threshold. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static TArray<AActor*> FilterActors_ByDistanceToVector(TArray<AActor*> actors, FVector vector, float distance, bool invert);

	/** Returns actors from the list that are (or are not, if inverted) visible on screen within the edge tolerance. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(AdvancedDisplay="player"))
	static TArray<AActor*> FilterActors_OnScreen(TArray<AActor*> actors, float ScreenEdgeTolerance, bool invert, APlayerController* player);

	/** Returns actors from the list that are currently overlapping OverlapTarget and match the given class. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(DeterminesOutputType="Class"))
	static TArray<AActor*> FilterActors_OverlappingActor(AActor* OverlapTarget, TArray<AActor*> actors,TSubclassOf<AActor> Class);


	// =====================================================================================================================
	// Tags
	// =====================================================================================================================

	/** Parses a tag of the form "Key=Value" from the Actor or Component's tags and returns the value string. Valid is false if the tag is not found. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor",DisplayName="Actor/Component - Get Tag as Param")
	static FString GetTagAsParam(UObject* Target, FName TagKey, bool& Valid,FName Delimiter="=");


	// =====================================================================================================================
	// BoundParam
	// =====================================================================================================================

	/** Gets a named string parameter bound to the Actor. Returns Fallback if the key is not set. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (String)")
	static FString GetActorBoundParam_String(AActor* Actor, FName Key, const FString& Fallback);
	/** Gets a named float parameter bound to the Actor. Returns Fallback if the key is not set. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (Float)")
	static float GetActorBoundParam_Float(AActor* Actor, FName Key, float Fallback);
	/** Gets a named int32 parameter bound to the Actor. Returns Fallback if the key is not set. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (Int32)")
	static int32 GetActorBoundParam_Int32(AActor* Actor, FName Key, int32 Fallback);
	/** Gets a named bool parameter bound to the Actor. Returns Fallback if the key is not set. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (Bool)")
	static bool GetActorBoundParam_Bool(AActor* Actor, FName Key, bool Fallback);

	/** Sets a named string parameter on the Actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (String)")
	static void SetActorBoundParam_String(AActor* Actor, FName Key, const FString& Value);
	/** Sets a named float parameter on the Actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (Float)")
	static void SetActorBoundParam_Float(AActor* Actor, FName Key, float Value);
	/** Sets a named int32 parameter on the Actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (Int32)")
	static void SetActorBoundParam_Int32(AActor* Actor, FName Key, int32 Value);
	/** Sets a named bool parameter on the Actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (Bool)")
	static void SetActorBoundParam_Bool(AActor* Actor, FName Key, bool Value);

	// =====================================================================================================================
	// Groups
	// =====================================================================================================================

	/** Adds or removes a single Actor from the given actor group tag. Returns true if the operation succeeded. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP"),DisplayName="Actor Group - Add Actor")
	static bool Group_Add(AActor* Actor, FGameplayTag Group, bool bInGroup);
	/** Adds or removes multiple Actors from the given actor group tag at once. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP"),DisplayName="Actor Group - Add Actors")
	static void Group_AddList(TArray<AActor*> Actors, FGameplayTag Group, bool bInGroup);

	/** Returns true if the Actor belongs to the given actor group tag. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP"),DisplayName="Actor Group - Has Actor?")
	static bool Group_HasActor(AActor* Actor,FGameplayTag Group);

	/** Returns all actors currently registered in the given actor group tag. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP",WorldContext="WorldContext"),DisplayName="Actor Group - Get All In Group")
	static TArray<AActor*> Group_GetActors(UObject* WorldContext, FGameplayTag Group);

	// =====================================================================================================================
	// Tag Target
	// =====================================================================================================================

	/** Retrieves the actor stored under a named tag target slot on the given Actor. Result is false if none is assigned. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(ExpandBoolAsExecs="Result",GameplayTagFilter = "TARGET"),DisplayName="Tag Target - Get")
	static AActor* GetActorTagTarget(AActor* Actor, FGameplayTag Tag, bool& Result);

	/** Stores a target actor reference in a named tag target slot on the given Actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(GameplayTagFilter = "TARGET"),DisplayName="Tag Target - Set")
	static void SetActorTagTarget(AActor* Actor, FGameplayTag Tag, AActor* Target);

	// =====================================================================================================================
	// Interact
	// =====================================================================================================================

	/** Checks whether an Actor can be interacted with by Instigator using the given interaction tag.
	 *  bRequireInterface: Actor must implement the interaction interface. bExcludeInstigator: Actor cannot be its own instigator. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Interaction",meta=(ExpandBoolAsExecs="Result",GameplayTagFilter = "INTERACTION",AdvancedDisplay="bRequireInterface,bExcludeInstigator"),DisplayName="Actor - Is Interactable?")
	static bool CheckIsActorInteractable(AActor* Actor, AActor* Instigator, FGameplayTag Tag, FOmegaCommonMeta meta, bool& Result, bool bRequireInterface=true,bool bExcludeInstigator=true);

	/** Triggers an interaction on the Actor from Instigator. bForce bypasses interactability checks. Returns true on success. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Interaction",DisplayName="Actor - Perform Interaction",meta=(GameplayTagFilter = "INTERACTION"))
	static bool PerformInteraction(AActor* Actor, AActor* Instigator, FGameplayTag Tag, FOmegaCommonMeta meta, bool bForce=false);

	// =====================================================================================================================
	// Relative Actors
	// =====================================================================================================================

	/** Returns the actor stored in the named "relative" slot on the given Actor (e.g. a linked NPC or spawn point). */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Relative")
	static AActor* GetRelative(AActor* Actor, FName Relative);

	/** Returns the named relative actor for each actor in the list. bIncludeEmpty keeps entries that have no relative assigned. */
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Relative (Actor List)")
	static TArray<AActor*> GetRelativeList(TArray<AActor*> Actors, FName Relative, bool bIncludeEmpty);

	// =====================================================================================================================
	// Combatant
	// =====================================================================================================================

	/** Returns the faction gameplay tag assigned to the Actor via its combatant component. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|Combatant",DisplayName="Actor - Get Faction")
	static FGameplayTag GetFaction_Tag(AActor* Actor);

	/** Returns how the Actor's faction regards the given FactionTag (e.g. Friendly, Neutral, Hostile). */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Faction Affinity")
	static EFactionAffinity GetFaction_Affinity(AActor* Actor, FGameplayTag FactionTag);

	/** Returns how the Actor's faction regards the Target's faction. */
	UFUNCTION(BlueprintPure,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Faction Affinity To Target")
	static EFactionAffinity GetFaction_AffinityToTarget(AActor* Actor, AActor* Target);

	// =====================================================================================================================
	// metadata
	// =====================================================================================================================

	/** Internal helper – retrieves the OmegaWorldManager for the given Actor's world. */
	UFUNCTION()
	static AOmegaWorldManager* GetWorldManager(AActor* Actor);

	/** Gets a named bool metadata value from the Actor's world manager entry. Returns Fallback if not set. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Bool")
	static bool GetMeta_Bool(AActor* Actor, FName Param, bool Fallback = false);

	/** Gets a named int32 metadata value from the Actor's world manager entry. Returns Fallback if not set. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Int")
	static int32 GetMeta_Int(AActor* Actor, FName Param, int32 Fallback = 0);

	/** Gets a named float metadata value from the Actor's world manager entry. Returns Fallback if not set. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Float")
	static float GetMeta_Float(AActor* Actor, FName Param, float Fallback = 0.0f);

	/** Gets a named string metadata value from the Actor's world manager entry. Returns Fallback if not set. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get String")
	static FString GetMeta_String(AActor* Actor, FName Param, const FString& Fallback = "");

	/** Gets a named PrimaryDataAsset metadata value from the Actor's world manager entry. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get DataAsset")
	static UPrimaryDataAsset* GetMeta_DataAsset(AActor* Actor, FName Param);

	/** Gets a named Actor metadata reference from the Actor's world manager entry. */
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Actor")
	static AActor* GetMeta_Actor(AActor* Actor, FName Param);


};

// =====================================================================================================================
// PAWN
// =====================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaPawnFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** Applies 2D movement input to a grounded Pawn using the provided Forward and Right world vectors.
	 *  bForce adds movement even if the pawn's movement component would normally ignore it. */
	UFUNCTION(BlueprintCallable,Category="Omega|Pawn")
	static void MovePawn2D_Grounded(APawn* Pawn, FVector2D Axis,bool bForce, FVector Forward, FVector Right);

	/** Applies 2D rotational input to the Pawn's controller using the provided camera config (pitch/yaw limits, speeds). */
	UFUNCTION(BlueprintCallable,Category="Omega|Pawn")
	static void RotateControl2D(APawn* Pawn, FVector2D Axis, FOmega_CameraConfig config);

	/** Returns the Forward, Right, and Up control vectors for a Pawn, optionally locking each axis (X/Y/Z). */
	UFUNCTION(BlueprintPure,Category="Omega|Pawn")
	static void GetPawnControlVectors(APawn* Pawn, bool X, bool Y, bool Z, FVector& Forward, FVector& Right, FVector& Up);
};

// =====================================================================================================================
// Components
// =====================================================================================================================
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComponentFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void SetBoxRangeToComponentBounds(UBoxComponent* Box, USceneComponent* Reference,bool bSetBoxExtent=true,bool bSetPosition=true);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void ResetMeshComponentMaterials(UMeshComponent* Component);
	
	/** Smoothly interpolates a SceneComponent's rotation to face a world-space Vector at the given speed.
	 *  bWorldSpace: interpret Vector in world space rather than local space. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void InterpComponentRotation_FromVector(USceneComponent* component, FVector Vector, float InterpSpeed, bool bWorldSpace);

	/** Linearly interpolates the SceneComponent's transform between A and B by the lerp value (0–1).
	 *  bWorld: apply the result in world space. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void LerpSceneComponentTransform(USceneComponent* component, FTransform A, FTransform B, float lerp, bool bWorld);

	/** Linearly interpolates the SceneComponent's transform between the world transforms of components A and B. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void LerpSceneComponentBetweenComponents(USceneComponent* component, USceneComponent* A, USceneComponent* B, float lerp, bool bWorld);

	/** Points an ArrowComponent directly at the given world-space Target location. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void PointArrowComponentToTarget(UArrowComponent* Component, FVector Target);

};
