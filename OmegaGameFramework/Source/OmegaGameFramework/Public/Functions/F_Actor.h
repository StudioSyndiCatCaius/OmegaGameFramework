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
	static bool UsesInterface(UObject* obj);
	
	UFUNCTION(BlueprintCallable,Category="Actor Condition")
	static void SnapActorToSurface(AActor* Actor, FVector Trace_Start,FVector Trace_End, TEnumAsByte<EObjectTypeQuery> CollisionType);

	UFUNCTION(BlueprintCallable,Category="Actor Condition")
	static bool CheckActorCondition(AActor* Actor, FOmegaConditions_Actor Conditions);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(ExpandBoolAsExecs="Result"))
	static bool IsActorPlayer(AActor* Actor, APawn*& Pawn, APlayerController*& Controller, bool& Result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static void ApplyActorConfigAsset(AActor* Actor, UOmegaActorConfig* Config);

	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static AActor* ConfigureChildActor(UChildActorComponent* ChildActor, TSubclassOf<AActor> NewClass, UPrimaryDataAsset* NewIdentity, AActor* NewOwner);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(AdvancedDisplay="LocationRule,RotationRule,ScaleRule,bWeldSimulateBodies"))
	static void AttachComponentToActor(USceneComponent* Component, AActor* Actor, FName Socket="",
		EAttachmentRule LocationRule=EAttachmentRule::SnapToTarget,
		EAttachmentRule RotationRule=EAttachmentRule::SnapToTarget,
		EAttachmentRule ScaleRule=EAttachmentRule::SnapToTarget,
		bool bWeldSimulateBodies=true);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static AActor* GetActorNearestToScreenPoint(const TArray<AActor*>& Actors,const FVector2D& ScreenPoint, APlayerController* PlayerController,float& OutDistance);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(WorldContext="WorldContext"),DisplayName="Actors - Set Paused")
	static void SetPaused(UObject* WorldContext, UPARAM(meta=(Categories="PAUSE")) FGameplayTag PauseGroup, bool bPaused);
	
	// =====================================================================================================================
    // Filters
    // =====================================================================================================================
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static TArray<AActor*> FilterActors_ByDistanceToVector(TArray<AActor*> actors, FVector vector, float distance, bool invert);

	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(AdvancedDisplay="player"))
	static TArray<AActor*> FilterActors_OnScreen(TArray<AActor*> actors, float ScreenEdgeTolerance, bool invert, APlayerController* player);

	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(DeterminesOutputType="Class"))
	static TArray<AActor*> FilterActors_OverlappingActor(AActor* OverlapTarget, TArray<AActor*> actors,TSubclassOf<AActor> Class);
	

	// =====================================================================================================================
	// Tags
	// =====================================================================================================================
	//Extracts a tag from an Actor or ActorComponent as a param;
	UFUNCTION(BlueprintPure,Category="Omega|Actor",DisplayName="Actor/Component - Get Tag as Param")
	static FString GetTagAsParam(UObject* Target, FName TagKey, bool& Valid,FName Delimiter="=");

	
	// =====================================================================================================================
	// BoundParam
	// =====================================================================================================================
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (String)")
	static FString GetActorBoundParam_String(AActor* Actor, FName Key, const FString& Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (Float)")
	static float GetActorBoundParam_Float(AActor* Actor, FName Key, float Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (Int32)")
	static int32 GetActorBoundParam_Int32(AActor* Actor, FName Key, int32 Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam",DisplayName="Actor - Get Bounrd Param (Bool)")
	static bool GetActorBoundParam_Bool(AActor* Actor, FName Key, bool Fallback);


	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (String)")
	static void SetActorBoundParam_String(AActor* Actor, FName Key, const FString& Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (Float)")
	static void SetActorBoundParam_Float(AActor* Actor, FName Key, float Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (Int32)")
	static void SetActorBoundParam_Int32(AActor* Actor, FName Key, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam",DisplayName="Actor - Set Bounrd Param (Bool)")
	static void SetActorBoundParam_Bool(AActor* Actor, FName Key, bool Value);
	
	// =====================================================================================================================
	// Groups
	// =====================================================================================================================
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP"),DisplayName="Actor Group - Add Actor")
	static bool Group_Add(AActor* Actor, FGameplayTag Group, bool bInGroup);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP"),DisplayName="Actor Group - Add Actors")
	static void Group_AddList(TArray<AActor*> Actors, FGameplayTag Group, bool bInGroup);
	
	UFUNCTION(BlueprintPure,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP"),DisplayName="Actor Group - Has Actor?")
	static bool Group_HasActor(AActor* Actor,FGameplayTag Group);
	
	UFUNCTION(BlueprintPure,Category="Omega|Actor",meta=(GameplayTagFilter = "ACTOR_GROUP",WorldContext="WorldContext"),DisplayName="Actor Group - Get All In Group")
	static TArray<AActor*> Group_GetActors(UObject* WorldContext, FGameplayTag Group);
	
	// =====================================================================================================================
	// Tag Target
	// =====================================================================================================================
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(ExpandBoolAsExecs="Result",GameplayTagFilter = "TARGET"),DisplayName="Tag Target - Get")
	static AActor* GetActorTagTarget(AActor* Actor, FGameplayTag Tag, bool& Result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(GameplayTagFilter = "TARGET"),DisplayName="Tag Target - Set")
	static void SetActorTagTarget(AActor* Actor, FGameplayTag Tag, AActor* Target);

	// =====================================================================================================================
	// Interact
	// =====================================================================================================================
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Interaction",meta=(ExpandBoolAsExecs="Result",GameplayTagFilter = "INTERACTION",AdvancedDisplay="bRequireInterface,bExcludeInstigator"),DisplayName="Actor - Is Interactable?")
	static bool CheckIsActorInteractable(AActor* Actor, AActor* Instigator, FGameplayTag Tag, FOmegaCommonMeta meta, bool& Result, bool bRequireInterface=true,bool bExcludeInstigator=true);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Interaction",DisplayName="Actor - Perform Interaction",meta=(GameplayTagFilter = "INTERACTION"))
	static bool PerformInteraction(AActor* Actor, AActor* Instigator, FGameplayTag Tag, FOmegaCommonMeta meta, bool bForce=false);
	
	// =====================================================================================================================
	// Relative Actors
	// =====================================================================================================================
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Relative")
	static AActor* GetRelative(AActor* Actor, FName Relative);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Relative (Actor List)")
	static TArray<AActor*> GetRelativeList(TArray<AActor*> Actors, FName Relative, bool bIncludeEmpty);
	
	// =====================================================================================================================
	// Combatant
	// =====================================================================================================================
	UFUNCTION(BlueprintPure,Category="Omega|Actor|Combatant",DisplayName="Actor - Get Faction")
	static FGameplayTag GetFaction_Tag(AActor* Actor);
	
	UFUNCTION(BlueprintPure,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Faction Affinity")
	static EFactionAffinity GetFaction_Affinity(AActor* Actor, FGameplayTag FactionTag);
	
	UFUNCTION(BlueprintPure,Category="Omega|Actor|Relatives",DisplayName="Actor - Get Faction Affinity To Target")
	static EFactionAffinity GetFaction_AffinityToTarget(AActor* Actor, AActor* Target);

	// =====================================================================================================================
	// metadata
	// =====================================================================================================================
	UFUNCTION()
	static AOmegaWorldManager* GetWorldManager(AActor* Actor);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Bool")
	static bool GetMeta_Bool(AActor* Actor, FName Param, bool Fallback = false);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Int")
	static int32 GetMeta_Int(AActor* Actor, FName Param, int32 Fallback = 0);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get Float")
	static float GetMeta_Float(AActor* Actor, FName Param, float Fallback = 0.0f);
	
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get String")
	static FString GetMeta_String(AActor* Actor, FName Param, const FString& Fallback = "");
	
	UFUNCTION(BlueprintPure, Category="Omega|Actor|Meta", DisplayName="Actor Meta - Get DataAsset")
	static UPrimaryDataAsset* GetMeta_DataAsset(AActor* Actor, FName Param);
	
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

	UFUNCTION(BlueprintCallable,Category="Omega|Pawn")
	static void MovePawn2D_Grounded(APawn* Pawn, FVector2D Axis,bool bForce, FVector Forward, FVector Right);

	UFUNCTION(BlueprintCallable,Category="Omega|Pawn")
	static void RotateControl2D(APawn* Pawn, FVector2D Axis, FOmega_CameraConfig config);
	
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
	static void InterpComponentRotation_FromVector(USceneComponent* component, FVector Vector, float InterpSpeed, bool bWorldSpace);

	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void LerpSceneComponentTransform(USceneComponent* component, FTransform A, FTransform B, float lerp, bool bWorld);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void LerpSceneComponentBetweenComponents(USceneComponent* component, USceneComponent* A, USceneComponent* B, float lerp, bool bWorld);

	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void PointArrowComponentToTarget(UArrowComponent* Component, FVector Target);

};
