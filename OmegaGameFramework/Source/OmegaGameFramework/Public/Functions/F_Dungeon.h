// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/RandomStream.h"
#include "UObject/Interface.h"
#include "F_Dungeon.generated.h"

class UArrowComponent;
class UBillboardComponent;
class ULevelStreamingDynamic;
class UOmegaDungeon_MarkerPreset;
class AOmegaDungeon;
class AOmegaDungeon_Socket;
class AOmegaDungeon_Marker;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOmegaDungeonDelegate,AOmegaDungeon*,Dungeon);

USTRUCT(BlueprintType)
struct FOmegaDungeonCellData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Dungeon") int32 type=0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Dungeon") FGameplayTagContainer Tags;

};

// ===================================================================================================================
// Interface
// ===================================================================================================================
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Dungeon Model",BlueprintType) class UDataInterface_DungeonModel : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_DungeonModel
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category="Dungeon") void Dungeon_GenerateBegin(AOmegaDungeon* Dungeon);
	// Called after ALL spawned module levels have finished streaming in and all open sockets are processed.
	UFUNCTION(BlueprintNativeEvent, Category="Dungeon") void Dungeon_GenerateEnd(AOmegaDungeon* Dungeon);

	// Fill the Dungeon's CellData map (via Dungeon->SetCell) with the layout of the dungeon.
	// Use the Dungeon's Random* functions so results are deterministic per-seed.
	UFUNCTION(BlueprintNativeEvent, Category="Dungeon") void Dungeon_GenerateLayout(AOmegaDungeon* Dungeon);
	// Called once for every cell created during Dungeon_GenerateLayout. Spawn the cell's content here
	// (level modules, meshes, etc.) via Dungeon->SpawnLevelModule / Dungeon->SpawnDungeonActor.
	UFUNCTION(BlueprintNativeEvent, Category="Dungeon") void Dungeon_ProcessCell(AOmegaDungeon* Dungeon, FIntVector Coord, FOmegaDungeonCellData Cell);
	// Called after all module levels have streamed in, once for every socket that did NOT connect to a
	// socket of another module. Spawn wall/cap modules here at the socket's transform.
	UFUNCTION(BlueprintNativeEvent, Category="Dungeon") void Dungeon_ProcessOpenSocket(AOmegaDungeon* Dungeon, AOmegaDungeon_Socket* Socket);

};

// ===================================================================================================================
// Actor - Dungeon
// ===================================================================================================================
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDungeon : public AActor
{
	GENERATED_BODY()

public:

	AOmegaDungeon();

	UPROPERTY(Transient) TArray<UActorComponent*> GeneratedComponents; // mainly used for things like Static and Instance Static Mesh componets
	UPROPERTY(Transient) TArray<AActor*> GeneratedActors;
	UPROPERTY(Transient) TArray<ULevelStreamingDynamic*> GeneratedLevels; // spawned level instance modules
	UPROPERTY(Transient) TMap<FIntVector,FOmegaDungeonCellData> CellData;

	UPROPERTY(EditAnywhere,Category="Dungeon") TScriptInterface<IDataInterface_DungeonModel> Model;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Dungeon") FIntVector Size=FIntVector(10,10,1);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Dungeon") int32 Seed=0;
	UPROPERTY(EditAnywhere,Category="Dungeon") bool bGenerateOnBeginPlay=true;
	//Max distance between two sockets of different modules for them to count as connected (open-socket pass).
	UPROPERTY(EditAnywhere,Category="Dungeon") float SocketConnectDistance=50.f;

	UFUNCTION(BlueprintCallable,Category="Dungeon") void SetModel(TScriptInterface<IDataInterface_DungeonModel> InModel,bool bRegenerate=false);
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Dungeon") void RandomizeSeed();
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Dungeon") void GenerateDungeon();
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Dungeon") void DestroyDungeon();

	// --- Cells --------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="Dungeon|Cells") void SetCell(FIntVector Coord, FOmegaDungeonCellData Cell);
	UFUNCTION(BlueprintCallable,Category="Dungeon|Cells") bool RemoveCell(FIntVector Coord);
	UFUNCTION(BlueprintPure,Category="Dungeon|Cells") bool GetCell(FIntVector Coord, FOmegaDungeonCellData& OutCell) const;
	UFUNCTION(BlueprintPure,Category="Dungeon|Cells") bool HasCell(FIntVector Coord) const;
	UFUNCTION(BlueprintPure,Category="Dungeon|Cells") TArray<FIntVector> GetCellCoords() const;
	// Is this coord inside the Dungeon's Size bounds? (0..Size-1 on each axis)
	UFUNCTION(BlueprintPure,Category="Dungeon|Cells") bool IsCoordInBounds(FIntVector Coord) const;
	// World-space transform for a cell coord, given the size (in units) of one cell module.
	UFUNCTION(BlueprintPure,Category="Dungeon|Cells") FTransform GetCellTransform(FIntVector Coord, FVector CellSize) const;

	// --- Sockets ------------------------------------------------------------------------------------------------
	// All sockets in currently-loaded generated module levels. Only valid once modules have streamed in.
	UFUNCTION(BlueprintPure,Category="Dungeon|Sockets") TArray<AOmegaDungeon_Socket*> GetAllSockets() const;
	// Sockets with no compatible socket from ANOTHER module within ConnectDistance (i.e. unconnected openings).
	UFUNCTION(BlueprintPure,Category="Dungeon|Sockets") TArray<AOmegaDungeon_Socket*> GetOpenSockets(float ConnectDistance=50.f) const;

	// --- Seeded Random ------------------------------------------------------------------------------------------
	// All randomness during generation should come from these so a given Seed always produces the same dungeon.
	UFUNCTION(BlueprintCallable,Category="Dungeon|Random") float GetRandomFloat();
	UFUNCTION(BlueprintCallable,Category="Dungeon|Random") int32 GetRandomIntInRange(int32 Min, int32 Max);
	// Returns a random index into Weights, where higher weights are proportionally more likely. -1 if empty/all zero.
	UFUNCTION(BlueprintCallable,Category="Dungeon|Random") int32 GetRandomWeightedIndex(const TArray<float>& Weights);

	// --- Spawning -----------------------------------------------------------------------------------------------
	// Spawns a level (module) at the given transform. Cleaned up by DestroyDungeon.
	// Game worlds (PIE/runtime): streams the level in asynchronously and returns the streaming level.
	// Editor worlds: duplicates the module's actors directly into the world and returns null — streaming
	// levels can't be cleanly unloaded from editor worlds and would keep the module's .umap file locked.
	UFUNCTION(BlueprintCallable,Category="Dungeon|Spawning") ULevelStreamingDynamic* SpawnLevelModule(TSoftObjectPtr<UWorld> Module, FTransform Transform);
	// Spawns an actor registered to this dungeon. Cleaned up by DestroyDungeon.
	UFUNCTION(BlueprintCallable,Category="Dungeon|Spawning") AActor* SpawnDungeonActor(TSubclassOf<AActor> Class, FTransform Transform);
	UFUNCTION(BlueprintCallable,Category="Dungeon|Spawning") void RegisterGeneratedActor(AActor* Actor);
	UFUNCTION(BlueprintCallable,Category="Dungeon|Spawning") void RegisterGeneratedComponent(UActorComponent* Component);

	UPROPERTY(BlueprintAssignable,Category="Dungeon") FOmegaDungeonDelegate OnDungeonGeneration_Begin;
	UPROPERTY(BlueprintAssignable,Category="Dungeon") FOmegaDungeonDelegate OnDungeonGeneration_Finish;
	UPROPERTY(BlueprintAssignable,Category="Dungeon") FOmegaDungeonDelegate OnDungeonDestroy_Begin;
	UPROPERTY(BlueprintAssignable,Category="Dungeon") FOmegaDungeonDelegate OnDungeonDestroy_End;

	FRandomStream RandomStream;

protected:

	virtual void BeginPlay() override;

	// Levels that haven't finished streaming in yet (module levels stream in asynchronously).
	TSet<TWeakObjectPtr<ULevelStreamingDynamic>> PendingLevels;
	// Total spawned per marker preset this generation, for Min/MaxSpawnable.
	UPROPERTY(Transient) TMap<UOmegaDungeon_MarkerPreset*,int32> MarkerSpawnCounts;
	// True between the initial generation pass and the deferred finalize (open sockets + GenerateEnd).
	bool bFinalizePending=false;
	// Incremented per spawned module; stamped onto duplicated sockets so socket matching can tell
	// modules apart in editor worlds (where all duplicated actors share one ULevel).
	int32 ModuleSpawnCounter=0;

	UFUNCTION() void HandleModuleLevelShown();
	void ProcessMarker(AOmegaDungeon_Marker* Marker);
	void ProcessMarkersInLevel(ULevel* Level);
	// Runs once all module levels are loaded: open-socket pass, Dungeon_GenerateEnd, Finish dispatcher.
	void FinalizeGeneration();

#if WITH_EDITOR
	// Editor-world module spawn: duplicates the module level's actors into this world.
	void SpawnLevelModule_Editor(UWorld* ModuleWorld, const FTransform& Transform, int32 ModuleID);
#endif
};

// ===================================================================================================================
// Actor - Socket
// ===================================================================================================================

// a dungeon socket is marked as a point where one dungeon tile can connect to another.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDungeon_Socket : public AActor
{
	GENERATED_BODY()

public:

	AOmegaDungeon_Socket();

	UPROPERTY() UBillboardComponent* ReferenceBillboard; //use some default editor icon
	UPROPERTY() UArrowComponent* ReferenceArrow;

	//chance of being used to connect to a new tile
	UPROPERTY(EditAnywhere,Category="Dungeon") float Weight=1.0;
	UPROPERTY(EditAnywhere,Category="Dungeon") FGameplayTag SocketTag;
	UPROPERTY(EditAnywhere,Category="Dungeon") FGameplayTagContainer AcceptedSockets; //if empty, any socket can connect
	//Chance of connected to a X/Y cell tile.
	UPROPERTY(EditAnywhere,Category="Dungeon") float Weight_Left=1.0;
	//Chance of connected to a X/Y cell tile.
	UPROPERTY(EditAnywhere,Category="Dungeon") float Weight_Forward=1.0;
	//Chance of connected to a Z cell tile.
	UPROPERTY(EditAnywhere,Category="Dungeon") float Weight_Up=0.0;

	// Set during generation: which spawned module instance this socket belongs to. -1 = use the owning
	// ULevel to tell modules apart (streamed module levels each have their own ULevel).
	UPROPERTY(Transient) int32 GeneratedModuleID=-1;

	// Can this socket connect to the given socket? Both sides must accept the other's SocketTag
	// (an empty AcceptedSockets accepts anything; matching is hierarchical).
	UFUNCTION(BlueprintPure,Category="Dungeon") bool CanConnectTo(const AOmegaDungeon_Socket* Other) const;
	// Do these sockets belong to the same spawned module instance?
	UFUNCTION(BlueprintPure,Category="Dungeon") bool IsFromSameModule(const AOmegaDungeon_Socket* Other) const;
};

// ===================================================================================================================
// Actor - Marker
// ===================================================================================================================


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDungeon_MarkerPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,Category="Actor") TSubclassOf<AActor> SpawnClass;
	UPROPERTY(EditAnywhere,Category="Actor") FTransform SpawnOffset;
	UPROPERTY(EditAnywhere,Category="Actor") float SpawnChance=0.5;
	UPROPERTY(EditAnywhere,Category="Actor") int32 MinSpawnable=1;
	UPROPERTY(EditAnywhere,Category="Actor") int32 MaxSpawnable=3;

	UPROPERTY(EditAnywhere,Category="Preview") TObjectPtr<UTexture2D> BillboardIcon;
	UPROPERTY(EditAnywhere,Category="Preview") FLinearColor ArrowColor=FLinearColor::White;
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDungeon_Marker : public AActor
{
	GENERATED_BODY()

public:

	AOmegaDungeon_Marker();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY() UBillboardComponent* ReferenceBillboard;
	UPROPERTY() UArrowComponent* ReferenceArrow;

	UPROPERTY(EditAnywhere,Category="Dungeon") TObjectPtr<UOmegaDungeon_MarkerPreset> Preset;
	UPROPERTY(EditAnywhere,Category="Dungeon") float SpawnChance=1.0;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Dungeon : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Weighted random pick using an explicit stream (C++/BP utility; -1 if empty or all weights <= 0).
	UFUNCTION(BlueprintCallable,Category="Omega|Dungeon")
	static int32 GetWeightedRandomIndex(const TArray<float>& Weights, const FRandomStream& Stream);

	// All markers currently placed in a spawned module level.
	UFUNCTION(BlueprintCallable,Category="Omega|Dungeon")
	static TArray<AOmegaDungeon_Marker*> GetMarkersInLevel(ULevelStreamingDynamic* Level);
};
