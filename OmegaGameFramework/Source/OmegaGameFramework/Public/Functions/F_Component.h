// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "F_Component.generated.h"

class UTextRenderComponent;
class UOmegaCondition_Actor;
class UOmegaActorSelector;

// =====================================================================================================================
// Actor Modifiers
// =====================================================================================================================

/** Abstract scriptable object that can be applied to an Actor to modify its state.
 *  Subclass in Blueprint or C++ to implement custom per-actor setup logic. */
UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UActorModifierScript : public UObject
{
	GENERATED_BODY()

public:
	/** Called when this modifier is applied to an Actor. Return true if the modification succeeded. */
	UFUNCTION(BlueprintNativeEvent,Category="Script")
	bool OnAppliedToActor(AActor* Actor) const;

};

/** A collection of ActorModifierScripts that can be applied to an Actor as a batch. */
USTRUCT(Blueprintable,BlueprintType)
struct FActorModifiers
{
	GENERATED_BODY()

public:
	/** The list of modifier scripts to run on the target Actor. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UActorModifierScript*> Script;

	/** Iterates all scripts and calls OnAppliedToActor for each valid entry. */
	void ApplyMods(AActor* Actor)
	{
		if(Actor)
		{
			for(auto* s : Script)
			{
				if(s) { s->OnAppliedToActor(Actor);}
			}
		}
	}
};


/** Bundles an actor selector, optional conditions, and a list of modifier scripts into a single unit.
 *  Used with RunActorModifierContainer to select & conditionally modify actors in the world. */
USTRUCT(Blueprintable,BlueprintType)
struct FActorModiferContainer
{
	GENERATED_BODY()

public:
	/** Selects which actor(s) to target. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	UOmegaActorSelector* ActorSelector=nullptr;
	/** All conditions must pass for the modifiers to be applied. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UOmegaCondition_Actor*> Conditions;
	/** Modifier scripts applied to the selected actor if conditions pass. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UActorModifierScript*> Modifiers;
};



// =====================================================================================================================
// Component Modifiers
// =====================================================================================================================

/** Abstract scriptable object that can be applied to any ActorComponent to modify its state.
 *  Implement OnAppliedToComponent in Blueprint to define custom component setup logic. */
UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript : public UObject
{
	GENERATED_BODY()

public:
	/** Called when this modifier is applied to a component. Return true if the modification succeeded. */
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	bool OnAppliedToComponent(UActorComponent* Component) const;

};

/** A collection of ComponentModScripts applied to a generic ActorComponent. */
USTRUCT(Blueprintable,BlueprintType)
struct FComponentMods
{
	GENERATED_BODY()

public:
	/** The list of modifier scripts to run on the target component. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UComponentModScript*> Script;
};


// --------------------------------------------------------------------
// Skeletal Mesh
// --------------------------------------------------------------------

/** Abstract modifier script targeting a SkeletalMeshComponent specifically (e.g. setting mesh, animations, physics). */
UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript_SkeletalMesh : public UObject
{
	GENERATED_BODY()

public:
	/** Called when this modifier is applied to a SkeletalMeshComponent. Return true if the modification succeeded. */
	UFUNCTION(BlueprintNativeEvent,Category="Script")
	bool OnAppliedToComponent(USkeletalMeshComponent* Component) const;

};

/** A collection of SkeletalMesh-specific modifier scripts. */
USTRUCT(Blueprintable,BlueprintType)
struct FComponentMod_SkeletalMesh
{
	GENERATED_BODY()

public:
	/** The list of skeletal mesh modifier scripts to apply. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UComponentModScript_SkeletalMesh*> Scripts;
};

// --------------------------------------------------------------------
// Static Mesh
// --------------------------------------------------------------------

/** Abstract modifier script targeting a StaticMeshComponent specifically (e.g. setting mesh, materials). */
UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript_StaticMesh : public UObject
{
	GENERATED_BODY()

public:
	/** Called when this modifier is applied to a StaticMeshComponent. Return true if the modification succeeded. */
	UFUNCTION(BlueprintNativeEvent,Category="Script")
	bool OnAppliedToComponent(UStaticMeshComponent* Component) const;

};

/** A collection of StaticMesh-specific modifier scripts. */
USTRUCT(Blueprintable,BlueprintType)
struct FComponentMod_StaticMesh
{
	GENERATED_BODY()

public:
	/** The list of static mesh modifier scripts to apply. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UComponentModScript_StaticMesh*> Scripts;
};

// --------------------------------------------------------------------
// Instanced Static Mesh
// --------------------------------------------------------------------

/** Abstract modifier script targeting an InstancedStaticMeshComponent (e.g. configuring per-instance data). */
UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript_InstancedStaticMesh : public UObject
{
	GENERATED_BODY()

public:
	/** Called when this modifier is applied to an InstancedStaticMeshComponent. Return true if the modification succeeded. */
	UFUNCTION(BlueprintNativeEvent,Category="Script")
	bool OnAppliedToComponent(UInstancedStaticMeshComponent* Component) const;

};

/** A collection of InstancedStaticMesh-specific modifier scripts. */
USTRUCT(Blueprintable,BlueprintType)
struct FComponentMod_InstancedStaticMesh
{
	GENERATED_BODY()

public:
	/** The list of instanced static mesh modifier scripts to apply. */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UComponentModScript_InstancedStaticMesh*> Scripts;
};



// =====================================================================================================================
// Function Lib
// =====================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComponentModifierFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Applies all modifier scripts in the FActorModifiers struct to the given Actor. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_Actor(FActorModifiers mods, AActor* Actor);

	/** Evaluates the FActorModiferContainer: selects an actor, checks conditions, and applies modifiers if they pass. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier",meta=(WorldContext="WorldContextObject"))
	static void RunActorModifierContainer(UObject* WorldContextObject, FActorModiferContainer container);

	/** Applies all modifier scripts in the FComponentMods struct to the given generic ActorComponent. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_Component(FComponentMods mod, UActorComponent* Component);

	/** Applies all SkeletalMesh modifier scripts to the given SkeletalMeshComponent. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_SkeletalMesh(FComponentMod_SkeletalMesh mod, USkeletalMeshComponent* Component);

	/** Applies all StaticMesh modifier scripts to the given StaticMeshComponent. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_StaticMesh(FComponentMod_StaticMesh mod, UStaticMeshComponent* Component);

	/** Applies all InstancedStaticMesh modifier scripts to the given InstancedStaticMeshComponent. */
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_InstancedStaticMesh(FComponentMod_InstancedStaticMesh mod, UInstancedStaticMeshComponent* Component);

	/** Internal utility to configure a TextRenderComponent's type settings. */
	static void SetTextComponentType_Util(UTextRenderComponent* Component);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void SnapLocalToCenterOfBounds(USceneComponent* Component);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ScaleAbsoluteByBounds(USceneComponent* Component, float Size=100.0f);
};
