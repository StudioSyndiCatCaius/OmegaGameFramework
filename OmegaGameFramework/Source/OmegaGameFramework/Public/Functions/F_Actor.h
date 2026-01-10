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
	UFUNCTION(BlueprintCallable,Category="Actor Condition")
	static void SnapActorToSurface(AActor* Actor, FVector Trace_Start,FVector Trace_End, TEnumAsByte<EObjectTypeQuery> CollisionType);

	UFUNCTION(BlueprintCallable,Category="Actor Condition")
	static bool CheckActorCondition(AActor* Actor, FOmegaConditions_Actor Conditions);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(ExpandBoolAsExecs="Result"))
	static bool CheckIsActorInteractable(AActor* Actor, AActor* Instigator, FGameplayTag Tag, FOmegaCommonMeta meta, bool& Result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor",meta=(ExpandBoolAsExecs="Result"))
	static bool IsActorPlayer(AActor* Actor, APawn*& Pawn, APlayerController*& Controller, bool& Result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static void ApplyActorConfigAsset(AActor* Actor, UOmegaActorConfig* Config);

	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static AActor* ConfigureChildActor(UChildActorComponent* ChildActor, TSubclassOf<AActor> NewClass, UPrimaryDataAsset* NewIdentity, AActor* NewOwner);
	
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
