// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OmegaFunctions_ComponentMod.generated.h"

// =====================================================================================================================
// ACtor Modifiers
// =====================================================================================================================

UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UActorModifierScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	bool OnAppliedToActor(AActor* Actor) const;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FActorModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UActorModifierScript*> Script;
};


// =====================================================================================================================
// Component Modifiers
// =====================================================================================================================

UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	bool OnAppliedToComponent(UActorComponent* Component) const;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FComponentMods
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	TArray<UComponentModScript*> Script;
};


// --------------------------------------------------------------------
// Skeletal Mesh
// --------------------------------------------------------------------


UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript_SkeletalMesh : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	bool OnAppliedToComponent(USkeletalMeshComponent* Component) const;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FComponentMod_SkeletalMesh
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	UComponentModScript_SkeletalMesh* Script;
};

// --------------------------------------------------------------------
// Static Mesh
// --------------------------------------------------------------------


UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript_StaticMesh : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	bool OnAppliedToComponent(UStaticMeshComponent* Component) const;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FComponentMod_StaticMesh
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	UComponentModScript_StaticMesh* Script;
};

// --------------------------------------------------------------------
// Static Mesh
// --------------------------------------------------------------------


UCLASS(BlueprintType,Blueprintable,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UComponentModScript_InstancedStaticMesh : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Script")
	bool OnAppliedToComponent(UInstancedStaticMeshComponent* Component) const;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FComponentMod_InstancedStaticMesh
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Script")
	UComponentModScript_InstancedStaticMesh* Script;
};



// =====================================================================================================================
// Function Lib
// =====================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComponentModifierFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_Actor(FActorModifiers mods, AActor* Actor);

	
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_Component(FComponentMods mod, UActorComponent* Component);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_SkeletalMesh(FComponentMod_SkeletalMesh mod, USkeletalMeshComponent* Component);	
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_StaticMesh(FComponentMod_StaticMesh mod, UStaticMeshComponent* Component);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Component|Modifier")
	static void ApplyModifierTo_InstancedStaticMesh(FComponentMod_InstancedStaticMesh mod, UInstancedStaticMeshComponent* Component);
};
