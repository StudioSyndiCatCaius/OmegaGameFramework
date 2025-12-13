// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaFunctions_ComponentMod.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Condition/Condition_Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"

#include "OmegaFunctions_Actor.generated.h"

class UOmegaActorConfig;

USTRUCT(BlueprintType)
struct FOmegaActorModifierSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor") TArray<UOmegaCondition_Actor*> Conditions;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor") TArray<UActorModifierScript*> Modifiers;

	bool Apply(AActor* a) const
	{
		if(a)
		{
			FOmegaConditions_Actor n;
			n.Conditions=Conditions;
			if(n.CheckConditions(a))
			{
				FActorModifiers m;
				m.Script=Modifiers;
				m.ApplyMods(a);
				return true;
			}
		}
		return false;
	}
};



UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UActorWeighterScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	float GetWeight(AActor* Actor) const;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FActorWeighter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UActorWeighterScript*> Scripts;

	float GetWeight(AActor* Actor)
	{
		float out=0.0;
		if(Actor)
		{
			for(auto* a : Scripts)
			{
				if(a) { out=a->GetWeight(Actor)*out;}
			}
		}
		return out;
	}
};



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
	
	UFUNCTION(BlueprintCallable,Category="Omega|Actor")
	static float GetActorWeight(AActor* Actor, FActorWeighter Weighter,float fallback);
	
	// =====================================================================================================================
	// Tags
	// =====================================================================================================================
	//Extracts a tag from an Actor or ActorComponent as a param;
	UFUNCTION(BlueprintPure,Category="Omega|Actor")
	static FString GetTagAsParam(UObject* Target, FName TagKey, bool& Valid,FName Delimiter="=");

	
	// =====================================================================================================================
	// BoundParam
	// =====================================================================================================================
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam")
	static FString GetActorBoundParam_String(AActor* Actor, FName Key, const FString& Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam")
	static float GetActorBoundParam_Float(AActor* Actor, FName Key, float Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam")
	static int32 GetActorBoundParam_Int32(AActor* Actor, FName Key, int32 Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Actor|BoundParam")
	static bool GetActorBoundParam_Bool(AActor* Actor, FName Key, bool Fallback);


	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam")
	static void SetActorBoundParam_String(AActor* Actor, FName Key, const FString& Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam")
	static void SetActorBoundParam_Float(AActor* Actor, FName Key, float Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam")
	static void SetActorBoundParam_Int32(AActor* Actor, FName Key, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Actor|BoundParam")
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
