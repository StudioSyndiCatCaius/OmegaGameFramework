// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "Misc/GeneralDataObject.h"
#include "F_Grid3D.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaGrid3DPath
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Grid3D")
	TArray<FIntVector> PathPoints;

	UPROPERTY() int32 distance=0;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaGrid3DPathfindResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Grid3D")
	TArray<FOmegaGrid3DPath> paths;

};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaGrid3DPathfindMeta
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Grid3D")
	AOmegaGrid3D_Tile* Tile=nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Grid3D")
	AActor* ContextActor=nullptr;
};


UINTERFACE(DisplayName="♎Actor🔵 - ♟️Grid3D Pathfind") class UDataInterface_Grid3DPathfind : public UInterface
{
	GENERATED_BODY()
public:
};

class OMEGAGAMEFRAMEWORK_API IDataInterface_Grid3DPathfind
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|♟️Grid3D Pathfind",DisplayName="♟️Grid3D Pathfind - Valid?")
	bool Grid3D_ValidPathfind(AOmegaGrid3D_Tile* Tile);
	
};


// ===============================================================================================================================
// Tilemap Component
// ===============================================================================================================================

class UOmegaGrid3D_Occupant;
class UInstancedStaticMeshComponent;

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_Map : public USceneComponent
{
	GENERATED_BODY()
	
	UOmegaGrid3D_Map();

	UPROPERTY() TArray<AOmegaGrid3D_Tile*> REF_Tiles;
	// Coordinates appended by (now destroyed) addon gridmaps. Included whenever tiles are (re)generated.
	UPROPERTY() TArray<FIntVector> REF_AddonCoordinates;
	UPROPERTY() UOmegaGrid3D_Map* REF_HostGridmap;

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentCreated() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:


	UFUNCTION(BlueprintCallable,Category="Grid3D")
	void DestroyTiles();
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	void GenerateTiles();
	
	UPROPERTY(EditAnywhere,Category="Grid3D")
	UOmegaGrid3DTileType* DefaultTileType;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3D")
	FIntVector GridSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3D")
	FVector TileOffset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3D")
	TSubclassOf<AOmegaGrid3D_Tile> TileClass;
	
	/*
	 * if true, this will not be its own gridmap, but rather, will be an addon to another Gridmap.
	 */
	UPROPERTY(EditAnywhere,Category="Grid3D")
	bool bIsAddon;
	//Gridmap this will act as an addon to. if NONE set but bIsAddon is true, then jist find and like to the first found Gridmap actor.
	UPROPERTY(EditAnywhere,Category="Grid3D")
	AOmegaGridmap3D* AddonLinkedGridmap;

	// The gridmap this map contributes its tiles to: itself normally, or the linked host map if this is an addon.
	UFUNCTION(BlueprintPure,Category="Grid3D")
	UOmegaGrid3D_Map* GetHostGridmap();

	// Get Coordinate & Vector
	UFUNCTION(BlueprintPure,Category="Grid3D")
	FIntVector GetCoordinateFromVector(FVector Vector);
	UFUNCTION(BlueprintPure,Category="Grid3D")
	FVector GetVectorFromCoordinate(FIntVector Coordinate);
	
	// Get Tile
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	TArray<AOmegaGrid3D_Tile*> GetTiles();
	
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	TArray<AOmegaGrid3D_Tile*> GetTilesFromCoordinates(TArray<FIntVector> Coordinates);
	UFUNCTION(BlueprintPure,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTileFromVector(FVector Vector);
	UFUNCTION(BlueprintPure,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTileFromCoordinate(FIntVector Coordinate);
	
	UFUNCTION(BlueprintCallable,Category="Grid3D",DisplayName="Get Tile w/ Occupant (Component)")
	AOmegaGrid3D_Tile* GetTile_OfOccupant_Comp(UOmegaGrid3D_Occupant* Occupant);
	UFUNCTION(BlueprintCallable,Category="Grid3D",DisplayName="Get Tile w/ Occupant (Actor)")
	AOmegaGrid3D_Tile* GetTile_OfOccupant_Actor(AActor* Occupant);

};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGridmap3D : public AActor
{
	GENERATED_BODY()

	AOmegaGridmap3D();
	virtual void OnConstruction(const FTransform& Transform) override;
public:

	//mesh used to display preview points for where the tiles will spawn
	UPROPERTY() UInstancedStaticMeshComponent* PreviewMesh;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Gridmap3D")
	UOmegaGrid3D_Map* GridmapComponent;
};

// =====================================================================================================
// Tile Occupant Component
// =====================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGrid3DOccupantDelegate, UOmegaGrid3D_Occupant*, Occupant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrid3DOccupantMotionDelegate, UOmegaGrid3D_Occupant*, Occupant, bool, Rotation);

DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FOnGrid3DOccupantTileQuery, UOmegaGrid3D_Occupant*, Occupant,AOmegaGrid3D_Tile*, Tile);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_Occupant : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() AOmegaGrid3D_Tile* REF_MoveTargetTile=nullptr;
	FVector move_origin;
	FVector move_from;
	FVector move_target;
	FRotator rotate_origin;
	FRotator rotate_target;
	float motion_alpha=0;
	float cooldown_remaining=0;
	bool bBumping=false;
	bool bBumpReturning=false;

public:
	UOmegaGrid3D_Occupant();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant")
	FVector TileOffset;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant")
	bool AutoSnapToTile;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant")
	float AutoSnapDistance=200;
	UFUNCTION(BlueprintCallable,Category="Gird3D Occupant")
	bool SnapToNearestTile();
	
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	void SetTile(AOmegaGrid3D_Tile* Tile, bool bClearPrevious=true, bool bSnap=true);
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTile();
	
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTileAtOffset(FIntVector Offset, bool RotationRelative);
	
	//Movement -------------
	
	bool bMoving=false;
	bool bRotating=false;
	
	UPROPERTY(BlueprintAssignable) FOnGrid3DOccupantMotionDelegate OnOccupantMotionBegin;
	UPROPERTY(BlueprintAssignable) FOnGrid3DOccupantMotionDelegate OnOccupantMotionEnd;
	UPROPERTY(BlueprintAssignable) FOnGrid3DOccupantDelegate OnOccupantMovementBump;
	UPROPERTY(BlueprintReadWrite,Category="Grid3d Occupant|Mover") FOnGrid3DOccupantTileQuery Query_CanMoveToTile;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant|Mover")
	float MoveDuration=0.2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant|Mover")
	float RotateDuration=0.2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant|Mover")
	float MotionCooldownDuration=0.3f;
	
	/*
	 * If true, when tring to move to a tile queried as FALSE for valid move, move halfway, then return to original point.
	 * That halfway point broadcasts `OnOccupantMovementBump`
	*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant|Mover")
	bool BumpOnInvalidMove;
	
	
	UFUNCTION(BlueprintCallable,Category="Grid3d Occupant|Mover")
	bool Input_Move(FIntVector Direction, bool RotationRelative);
	
	UFUNCTION(BlueprintCallable,Category="Grid3d Occupant|Mover")
	bool Input_Rotate(FIntVector Amount, bool RotationRelative);
	
	UFUNCTION(BlueprintCallable,Category="Grid3d Occupant|Mover")
	bool IsMovingOrRotating(bool& Moving,bool& Rotating);
	
};

// =====================================================================================================
// Tile Selector
// =====================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrid3DTileSelected, AOmegaGrid3D_Tile*, Tile, bool, bIsSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrid3DTileRegistered, AOmegaGrid3D_Tile*, Tile, bool, bIsRegistered);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_Selector : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() TArray<AOmegaGrid3D_Tile*> REF_RegisteredTiles;
	UPROPERTY() AOmegaGrid3D_Tile* REF_SelectedTile;
public:

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnGrid3DTileSelected OnGrid3DTileSelected;
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnGrid3DTileRegistered OnGrid3DTileRegistered;

	UFUNCTION(BlueprintCallable,Category="Grid3D Selector")
	void SetSelectedTile(AOmegaGrid3D_Tile* Tile);
	UFUNCTION(BlueprintPure,Category="Grid3D Selector")
	AOmegaGrid3D_Tile* GetSelectedTile();
	UFUNCTION(BlueprintCallable,Category="Grid3D Selector")
	void SetTileRegistered(AOmegaGrid3D_Tile* Tile, bool bTileRegistered);

	UFUNCTION(BlueprintPure,Category="Grid3D Selector")
	TArray<AOmegaGrid3D_Tile*> GetRegisteredTiles();
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Selector")
	void RegisterTiles(TArray<AOmegaGrid3D_Tile*> Tiles, bool bClearFirst=true);
	UFUNCTION(BlueprintCallable,Category="Grid3D Selector")
	void ClearRegisteredTiles();
};



// =====================================================================================================
// Tile Type
// =====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3DTileType : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
};

// =====================================================================================================
// Tile Actor
// =====================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGrid3DTileTagEdit, AOmegaGrid3D_Tile*, Tile, FGameplayTag, Tag, bool, bActive);

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGrid3D_Tile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY() FIntVector grid_coordinate;
	UPROPERTY() UOmegaGrid3D_Map* Owning_Gridmap;
	
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnGrid3DTileTagEdit OnTileTagChanged;
	
	UPROPERTY(EditAnywhere,Category="Grid3D Tile")
	UOmegaGrid3DTileType* TileType;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	void SetTileType(UOmegaGrid3DTileType* Type);
	
	UFUNCTION(BlueprintPure,Category="Grid3D Tile")
	UOmegaGrid3DTileType* GetTileType() const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Grid3D Tile")
	TMap<FGameplayTag,USceneComponent*> LinkTileTagVisibilityComponents();

private:
	
	USceneComponent* L_GetTagVisComp(FGameplayTag Tag);
	
public:
	
	//Occupant
	UPROPERTY(VisibleAnywhere,Category="Grid3D Tile")
	TArray<UOmegaGrid3D_Occupant*> Occupants;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Grid3D Tile",meta=(Categories="GRID3D.Tile"))
	FGameplayTagContainer TileTags;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile",DisplayName="Tile - Set Tag Active",meta=(Categories="GRID3D.Tile"))
	void Tag_SetActive(FGameplayTagContainer Tile_Tags, bool bActive);
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile",meta=(AdvancedDisplay="bSnap"))
	void SetOccupantOnTile(UOmegaGrid3D_Occupant* Occupant, bool bIsOnTile, bool bClearPrevious, bool bSnap=true);
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	TArray<UOmegaGrid3D_Occupant*> GetOccupants() const;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	UOmegaGrid3D_Occupant* GetFirstOccupant() const;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile",meta=(DeterminesOutputType="Class",ExpandEnumAsExecs="Result"))
    AActor* GetFirstOccupantActorOfClass(TSubclassOf<AActor> Class, bool& Result);
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	bool HasOccupant(UOmegaGrid3D_Occupant* Occupant) const;
	
	UFUNCTION(BlueprintPure,Category="Grid3d Tile")
	UOmegaGrid3D_Map* GetOwningGridmap();
	
	UFUNCTION(BlueprintPure,Category="Grid3d Tile")
	FIntVector GetTileCoordinate();
};


// =====================================================================================================
// Grid3D Subsystem
// =====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_Grid3D : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY() TArray<UOmegaGrid3D_Map*> REF_Tilemaps;
	
	UFUNCTION() void Register_TileMap(UOmegaGrid3D_Map* Tilemap, bool bRegistered);
};


// =====================================================================================================
// Functions
// =====================================================================================================

USTRUCT(BlueprintType)
struct FOmegaGrid3DPathfindQueryResult
{
	GENERATED_BODY()
	
	// if true, stops the pathfinding after this coord (bot doesn't necessarily exclude this coord itself)
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3D Pathfind") bool BlockTrace=false;
	// if true, excludes this tile from the path (but doesn't necessarily block the trace)
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3D Pathfind") bool BlockAdd=false;
};

DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(FOmegaGrid3DPathfindQueryResult, FGrid3DPathfindQuery, FIntVector, Coord,FOmegaGrid3DPathfindMeta,Meta);


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3DFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(AdvancedDisplay="x,y,z"))
	TArray<FIntVector> GetAdjacentCoordinates(FIntVector in);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(AdvancedDisplay="x,y,z"))
	TArray<FIntVector> GetCoordinatesInDistance(FIntVector in, int32 distance);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(AdvancedDisplay="metadata, x,y,z"))
	static FOmegaGrid3DPathfindResult Pathfind3D_AllPossiblePaths(
		const FIntVector& StartPoint,
		int32 MaxDistance,
		FGrid3DPathfindQuery Query,
		FOmegaGrid3DPathfindMeta metadata,
		bool x=true,bool y=true,bool z=false);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D")
	static TArray<FIntVector> GetCoordinatesFromPathfindResult(FOmegaGrid3DPathfindResult in, bool bOnlyLastPoints=false);

	//Will attempt to get the tile info and possible occupant, from an actor if need be
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(DeterminesOutputType="TileClass",ExpandBoolAsExecs="result"))
	static AOmegaGrid3D_Tile* GetGrid3DTileInfo(UObject* Object, TSubclassOf<AOmegaGrid3D_Tile> TileClass, UOmegaGrid3D_Occupant*& Occupant, bool& result);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D")
	static TArray<AOmegaGrid3D_Tile*> GetTilesFromPath(UOmegaGrid3D_Map* Tilemap, FOmegaGrid3DPath Path);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D")
	static TArray<AOmegaGrid3D_Tile*> GetTilesFromPathfind(UOmegaGrid3D_Map* Tilemap, FOmegaGrid3DPathfindResult Path, bool bOnlyLast);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(ExpandBoolAsExecs="result"))
	static FOmegaGrid3DPath GetShortestPath_ToCoordinate(FOmegaGrid3DPathfindResult pathfind,FIntVector coord, bool& result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(ExpandBoolAsExecs="result"))
	static FOmegaGrid3DPath GetShortestPath_ToTile(FOmegaGrid3DPathfindResult pathfind,AOmegaGrid3D_Tile* tile, bool& result);
};

// ===============================================================================================================================
// pATHFIND
// ===============================================================================================================================

UINTERFACE(MinimalAPI)
class UDataInterface_Pathfind3D : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Pathfind3D
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Pathfind")
	int32 ModifyDistance(FOmegaGrid3DPathfindMeta metadata, int32 in) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Pathfind")
	bool CanAddCoordinate(FOmegaGrid3DPathfindMeta metadata, FIntVector coordinate, int32 MovesRemaining) const;
};



UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_PathfindScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="Pathfind")
	int32 ModifyDistance(int32 distance, FOmegaGrid3DPathfindMeta metadata) const;
	UFUNCTION(BlueprintNativeEvent,Category="Pathfind")
	bool CanAddCoordinate(FOmegaGrid3DPathfindMeta metadata,FIntVector coord, int32 MovesRemaining) const;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_PathfindAction : public UOmegaDataAsset, public IDataInterface_Pathfind3D
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Pathfind")
	TArray<UOmegaGrid3D_PathfindScript*> Scripts;

	virtual int32 ModifyDistance_Implementation(FOmegaGrid3DPathfindMeta metadata, int32 in) const override;
	virtual bool CanAddCoordinate_Implementation(FOmegaGrid3DPathfindMeta metadata, FIntVector coordinate, int32 MovesRemaining) const override;

};
