// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "Components/BillboardComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshSocket.h"
#include "F_WFC.generated.h"

class AOmegaWfcSpawner;
class UOmegaWFCScript;

// =====================================================================================================
// Structs
// =====================================================================================================

// Per-face connection ID. Two adjacent tiles can be placed next to each other
// when the touching faces share the same SlotID.
USTRUCT(BlueprintType)
struct FOmegaWfcTileSlotData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 SlotID = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") FTransform Transform;
};

// One tile entry for the static-mesh definition.
// Face slot IDs are read from sockets named "WfcSlot:<id>" on the mesh (e.g. "WfcSlot:2_1").
// The socket's position relative to the mesh bounds determines which face it belongs to.
// The suffix after the first '_' is ignored, allowing multiple sockets with the same ID.
// Faces with no WfcSlot socket default to ID 0.
USTRUCT(BlueprintType)
struct FOmegaWfcStaticMeshTile
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") TSoftObjectPtr<UStaticMesh> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") float Weight = 1.f;
};

USTRUCT(BlueprintType)
struct FOmegaWfcSpawnerTileData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 ChosenTile = 1;
};


// =====================================================================================================
// Scripts
// =====================================================================================================

// Base class for WFC generation scripts. Override events in Blueprint or C++ to influence generation.
// Place instances on AOmegaWfcSpawner or collect them via UOmegaWFCScriptPreset on the definition.
UCLASS(Blueprintable, BlueprintType, Abstract, CollapseCategories, DefaultToInstanced, EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaWFCScript : public UObject
{
	GENERATED_BODY()
public:
	// Called once the wave is initialised. Call Spawner->ForceTileAtCoordinate() here to pre-collapse cells.
	UFUNCTION(BlueprintNativeEvent, Category="WFC|Script")
	void OnGenerationBegin(AOmegaWfcSpawner* Spawner);

	// Called each time a cell is collapsed by the WFC algorithm (not for forced collapses).
	UFUNCTION(BlueprintNativeEvent, Category="WFC|Script")
	void OnCellCollapsed(AOmegaWfcSpawner* Spawner, FIntVector Coordinate, int32 TileIndex);

	// Called when a contradiction is found before the algorithm retries with the next seed.
	UFUNCTION(BlueprintNativeEvent, Category="WFC|Script")
	void OnContradiction(AOmegaWfcSpawner* Spawner, int32 Attempt);

	// Called after the wave is fully collapsed, before any visual tiles are spawned.
	UFUNCTION(BlueprintNativeEvent, Category="WFC|Script")
	void OnGenerationComplete(AOmegaWfcSpawner* Spawner);

	// Called after all visual tile components have been spawned.
	UFUNCTION(BlueprintNativeEvent, Category="WFC|Script")
	void OnMapSpawned(AOmegaWfcSpawner* Spawner);
};


// A reusable data asset that bundles a set of WFC scripts for sharing across definitions.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaWFCScriptPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="WFC")
	TArray<UOmegaWFCScript*> Scripts;
};


// =====================================================================================================
// Definition — abstract base class
// =====================================================================================================

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaWFCDefinition : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	// Scripts that always run for this definition. Referenced presets are merged with inline scripts.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC")
	TArray<UOmegaWFCScriptPreset*> Scripts_Preset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="WFC")
	TArray<UOmegaWFCScript*> Scripts_Inline;

	// Returns the combined script list (preset scripts first, then inline).
	TArray<UOmegaWFCScript*> L_GetScripts() const;

	// World-space extents of one grid cell
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC")
	FVector TileSize = FVector(100.f, 100.f, 100.f);

	// Total number of distinct tile types in this definition
	UFUNCTION(BlueprintNativeEvent, Category="WFC")
	int32 GetTileCount();

	// Face slots for TileIndex — 6 entries in order: +X, -X, +Y, -Y, +Z, -Z
	UFUNCTION(BlueprintNativeEvent, Category="WFC")
	TArray<FOmegaWfcTileSlotData> GetTileSlots(int32 TileIndex);

	// Relative spawn weight (higher = more common)
	UFUNCTION(BlueprintNativeEvent, Category="WFC")
	float GetTileWeight(int32 TileIndex);

	// Create and return the visual component for this tile at Coordinate (relative to Spawner)
	UFUNCTION(BlueprintNativeEvent, Category="WFC")
	USceneComponent* OnTileSpawn(AOmegaWfcSpawner* Spawner, FIntVector Coordinate, int32 TileIndex);

	// Destroy a previously spawned tile component
	UFUNCTION(BlueprintNativeEvent, Category="WFC")
	void OnTileDestroy(AOmegaWfcSpawner* Spawner, USceneComponent* Tile);
};


// =====================================================================================================
// Spawner Actor
// =====================================================================================================

UCLASS(DisplayName="Omega WFC Spawner")
class OMEGAGAMEFRAMEWORK_API AOmegaWfcSpawner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category="Components") UBillboardComponent* Root;
	UPROPERTY() TArray<USceneComponent*> GeneratedTiles;

	// Pending forced collapses collected from scripts during OnGenerationBegin
	TArray<TPair<FIntVector, int32>> PendingForced;

public:
	AOmegaWfcSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC")
	UOmegaWFCDefinition* Definition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC")
	int32 Seed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC")
	FIntVector Size = FIntVector(10, 10, 1);

	// Additional scripts layered on top of whatever the Definition provides
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="WFC")
	TArray<UOmegaWFCScript*> Scripts;

	UFUNCTION(BlueprintCallable, CallInEditor, Category="WFC") void GenerateMap();
	UFUNCTION(BlueprintCallable, CallInEditor, Category="WFC") void DestroyMap();
	UFUNCTION(BlueprintCallable, CallInEditor, Category="WFC") void RandomizeSeed();
	UFUNCTION(BlueprintCallable, CallInEditor, Category="WFC") void RandomizeMap();

	// Call from a script's OnGenerationBegin to force a specific tile at a grid coordinate.
	// Has no effect if called outside of the generation phase.
	UFUNCTION(BlueprintCallable, Category="WFC")
	void ForceTileAtCoordinate(FIntVector Coordinate, int32 TileIndex);
};


// =====================================================================================================
// Function Library
// =====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_WFC : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};


// ############################################################################################################
// Definitions
// ############################################################################################################

// Static mesh tile definition. Each tile entry has a mesh and a weight.
// Face connectivity is derived from sockets named "WfcSlot:<id>[_suffix]" on each mesh.
UCLASS(DisplayName="WFC: Static Mesh Tiles")
class OMEGAGAMEFRAMEWORK_API UOmegaWFCDef_StaticMesh : public UOmegaWFCDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC")
	TArray<FOmegaWfcStaticMeshTile> Tiles;

	virtual int32 GetTileCount_Implementation() override;
	virtual TArray<FOmegaWfcTileSlotData> GetTileSlots_Implementation(int32 TileIndex) override;
	virtual float GetTileWeight_Implementation(int32 TileIndex) override;
	virtual USceneComponent* OnTileSpawn_Implementation(AOmegaWfcSpawner* Spawner, FIntVector Coordinate, int32 TileIndex) override;
	virtual void OnTileDestroy_Implementation(AOmegaWfcSpawner* Spawner, USceneComponent* Tile) override;
};


// ############################################################################################################
// Scripts
// ############################################################################################################

// Forces an L-shaped main path through the dungeon before WFC runs.
// The path starts near a random grid edge, walks inward, then turns perpendicular.
UCLASS(DisplayName="WFC Script: Main Path")
class OMEGAGAMEFRAMEWORK_API UWFCScript_MainPath : public UOmegaWFCScript
{
	GENERATED_BODY()
public:
	// How far from an edge the path start/end can be (0 = on the edge)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 MinStartDistanceFromEdge = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 MaxStartDistanceFromEdge = 2;

	// Total number of cells in the forced path
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 MinPathLength = 6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 MaxPathLength = 10;

	// Tile index to use for the main corridor cells
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 PathTile_Main = 0;
	// Tile index for the path entrance (-1 = use PathTile_Main)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 PathTile_Start = -1;
	// Tile index for the path exit (-1 = use PathTile_Main)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WFC") int32 PathTile_End = -1;

	virtual void OnGenerationBegin_Implementation(AOmegaWfcSpawner* Spawner) override;
};
