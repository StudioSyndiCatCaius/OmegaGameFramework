// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Components/Component_ActorConfig.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"

#include "OmegaFunctions_Actor.generated.h"

// =====================================================================================================================
// ACTOR
// =====================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

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
	static void LerpSceneComponentTransform(USceneComponent* component, FTransform A, FTransform B, float lerp, bool bWorld);


	UFUNCTION(BlueprintCallable,Category="Omega|Component")
	static void LerpSceneComponentBetweenComponents(USceneComponent* component, USceneComponent* A, USceneComponent* B, float lerp, bool bWorld);
};
