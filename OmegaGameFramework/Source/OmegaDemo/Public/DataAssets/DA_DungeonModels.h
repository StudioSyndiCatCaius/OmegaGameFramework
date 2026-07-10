// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_Dungeon.h"
#include "Misc/GeneralDataObject.h"
#include "DA_DungeonModels.generated.h"


// Cell types written into FOmegaDungeonCellData.type by UOmegaDungeonModel_Path.
UENUM(BlueprintType)
enum class EOmegaDngPathCellType : uint8
{
	None		=0,
	Path		=1, //a cell on the main path
	Start		=2, //first cell of the main path
	End			=3, //last cell of the main path
	LeafPath	=4, //a cell on a leaf (branch) path
	LeafEnd		=5, //last cell of a leaf path that does NOT reconnect to the main path
};

USTRUCT(BlueprintType)
struct FOmegaDngMdl_Path_Module
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") TSoftObjectPtr<UWorld> Module;
	//Normalized change of being selected
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") float Weight=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") int32 Min=0;
	//if 0, allow infinte amount
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") int32 Max=0;
};

USTRUCT(BlueprintType)
struct FOmegaDngMdl_Path_LeafData
{
	GENERATED_BODY()

	//chance of this path being selected as a leaf
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") float Weight=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") int32 Min=1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") int32 Max=3;
	//change of this leaf path connecting back to the main path instead of ending in a leaf
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Module") float ConnectToMainWeight=0.0;

};

// Cached socket layout of a module: one entry per horizontal direction (+X,+Y,-X,-Y index order),
// in the module's authoring space. Not reflected — internal to the Path model.
struct FOmegaDngMdl_SocketInfo
{
	bool bHasSocket=false;
	FGameplayTag Tag;
	FGameplayTagContainer Accepted;
};

struct FOmegaDngMdl_ModuleSockets
{
	FOmegaDngMdl_SocketInfo Dirs[4];

	int32 GetDirMask() const
	{
		int32 Mask = 0;
		for(int32 i = 0; i < 4; i++) { if(Dirs[i].bHasSocket) { Mask |= 1 << i; } }
		return Mask;
	}
};

// Generates a dungeon as a self-avoiding random-walk main path (Start -> End) on the dungeon grid,
// with optional leaf (branch) paths growing off it. One module level is spawned per cell. The layout
// tracks which neighboring cells are LOGICALLY connected (path order, capped by
// MaxModuleSocketConnections); after all modules stream in, every socket that doesn't face a connected
// neighbor gets a wall module — so adjacent-but-unconnected cells are walled off on both sides.
//
// Module authoring conventions (all modules are CellModuleSize sized, origin at cell center):
//  - Path/Start/End modules should be open on all 4 horizontal sides, with a Dungeon Socket actor at
//    each opening (on the cell edge, arrow pointing outward).
//  - Wall modules are spawned at an open socket's transform: author them to close an opening when
//    placed at the socket, with +X matching the socket's arrow.
//  - Door modules are spawned at connected sockets the same way (once per connection).
UCLASS()
class OMEGADEMO_API UOmegaDungeonModel_Path : public UOmegaDataAsset, public IDataInterface_DungeonModel
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") FVector CellModuleSize=FVector(1000,1000,1000);
	//Max socket connections per placed module. Structural connections (path order, leaf branches and
	//connect-backs) are exempt; the cap limits EXTRA connections between cells that merely touch, and
	//touching cells beyond it are walled off on both sides. Default 2 keeps a folded path (e.g. 4 cells
	//in a 2x2) as walled corridors instead of one wide open area. Clamped to at least 2 internally.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") int32 MaxModuleSocketConnections=2;

	//modules used for and main path tiles.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") TArray<FOmegaDngMdl_Path_Module> Modules_Path;

	//modules used for start tile
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") TArray<FOmegaDngMdl_Path_Module> Modules_Start;

	//modules used for an end tile
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") TArray<FOmegaDngMdl_Path_Module> Modules_End;
	//modules used for an end tile on a LEAF PATH. if there are NON in this, use one of the normal End tiles
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") TArray<FOmegaDngMdl_Path_Module> Modules_LeafEnd;
	
	//modules placed in the opening between two valid connected sockets (one per connection). Author them
	//like walls: centered on the opening, +X matching the socket arrow of the +X/+Y-facing socket.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") TArray<FOmegaDngMdl_Path_Module> Modules_Doors;
	
	//After all paths is drawn and all point tiles (like start/end) are placed, place walls at remaining Dungeon Sockets that don't connect to anything
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules") TArray<FOmegaDngMdl_Path_Module> Modules_Wall;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Path") int32 MainPathLength_Min=3;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Path") int32 MainPathLength_Max=5;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Path") int32 LeafPaths_Min=1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Path") int32 LeafPaths_Max=3;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Path") TArray<FOmegaDngMdl_Path_LeafData> LeafPaths;

	// --- IDataInterface_DungeonModel ------------------------------------------------------------------------------
	virtual void Dungeon_GenerateBegin_Implementation(AOmegaDungeon* Dungeon) override;
	virtual void Dungeon_GenerateLayout_Implementation(AOmegaDungeon* Dungeon) override;
	virtual void Dungeon_ProcessCell_Implementation(AOmegaDungeon* Dungeon, FIntVector Coord, FOmegaDungeonCellData Cell) override;
	virtual void Dungeon_ProcessOpenSocket_Implementation(AOmegaDungeon* Dungeon, AOmegaDungeon_Socket* Socket) override;
	virtual void Dungeon_GenerateEnd_Implementation(AOmegaDungeon* Dungeon) override;

private:

	// Per-generation usage counts, so Min/Max on modules can be honored. Reset in Dungeon_GenerateBegin.
	TMap<const FOmegaDngMdl_Path_Module*,int32> ModuleUseCounts;
	// Cached per-module socket layout (per-direction presence + tags). Reset in Dungeon_GenerateBegin.
	TMap<FSoftObjectPath,FOmegaDngMdl_ModuleSockets> ModuleSocketDataCache;
	// Logical connections per cell (bitmask of the 4 directions), built during layout. Adjacency without
	// a connection here gets walled on both sides. Reset in Dungeon_GenerateBegin.
	TMap<FIntVector,int32> CellConnectionMasks;
	// Rotated (world-space direction) socket layout of each already-placed cell, so later cells can
	// match socket tags against their placed neighbors. Reset in Dungeon_GenerateBegin.
	TMap<FIntVector,FOmegaDngMdl_ModuleSockets> PlacedCellSockets;

	const FOmegaDngMdl_ModuleSockets& GetModuleSocketData(const TSoftObjectPtr<UWorld>& Module);
	// Registers a two-way connection between two adjacent cells.
	void AddCellConnection(const FIntVector& CellA, const FIntVector& CellB);
	int32 GetConnectionCount(const FIntVector& Cell) const;
	// The module list used for a cell type, including the fallback chain (LeafEnd -> End -> Path).
	const TArray<FOmegaDngMdl_Path_Module>& GetModuleList(EOmegaDngPathCellType Type) const;
	// Does ANY module in the list have sockets covering RequiredMask at some rotation? Used during layout
	// so connections are only created where the module inventory can actually realize them.
	bool CanListCoverMask(const TArray<FOmegaDngMdl_Path_Module>& List, int32 RequiredMask);

	// Weighted pick honoring Min (under-min modules are picked first) and Max (0 = unlimited).
	// RequiredDirMask: sides of the cell that must have a socket (in some 90° rotation) — modules that
	// can't cover them are ineligible, so e.g. corner modules never land on straight-through cells.
	// NeighborConstraints (4 entries or empty): facing sockets of already-placed neighbors; a module is
	// only eligible if some rotation is also tag-compatible with all of them.
	// Null if List is empty.
	const FOmegaDngMdl_Path_Module* PickModule(const TArray<FOmegaDngMdl_Path_Module>& List, AOmegaDungeon* Dungeon, int32 RequiredDirMask=0,
		const TArray<const FOmegaDngMdl_SocketInfo*>& NeighborConstraints={});
	void SpawnCellModule(const TArray<FOmegaDngMdl_Path_Module>& List, AOmegaDungeon* Dungeon, const FTransform& Transform);
};
