// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subsystems/WorldSubsystem.h"
#include "Engine/DataAsset.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaSubsystem_Grid3D.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaGrid3DPath
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FIntVector> PathPoints;

	UPROPERTY()
	int32 distance;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaGrid3DPathfindResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FOmegaGrid3DPath> paths;

};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaGrid3DPathfindMeta
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AOmegaGrid3D_Tile* Tile=nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* ContextActor=nullptr;
};


// ===============================================================================================================================
// Tilemap Component
// ===============================================================================================================================

class UOmegaGrid3D_Occupant;

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_Map : public USceneComponent
{
	GENERATED_BODY()
	
	UOmegaGrid3D_Map();

	UPROPERTY() TArray<AOmegaGrid3D_Tile*> REF_Tiles;

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentCreated() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	// Draws the grid of debug boxes
	void DrawDebugGrid() const;
	
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid3d|Preview")
	FColor PreviewBoxColor = FColor::Cyan;  // Color of the debug box
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid3d|Preview")
	float PreviewBoxThickness = 1.0; 
	
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

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gridmap3D")
	UOmegaGrid3D_Map* GridmapComponent;
};

inline AOmegaGridmap3D::AOmegaGridmap3D()
{
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));
	GridmapComponent=CreateDefaultSubobject<UOmegaGrid3D_Map>(TEXT("Gridmap"));
	GridmapComponent->SetupAttachment(GetRootComponent());
}

// =====================================================================================================
// Tile Occupant Component
// =====================================================================================================

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_Occupant : public UActorComponent
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant")
	FVector TileOffset;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant")
	bool AutoSnapToTile;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grid3d Occupant")
	float AutoSnapDistance=200;
	UFUNCTION(BlueprintCallable,Category="Gird3D Occupant")
	void SnapToNearestTile();
	
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	void SetTile(AOmegaGrid3D_Tile* Tile, bool bClearPrevious=true, bool bSnap=true);
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTile();
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

	UPROPERTY(BlueprintAssignable)
	FOnGrid3DTileSelected OnGrid3DTileSelected;
	UPROPERTY(BlueprintAssignable)
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
// Mover
// =====================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrid3DMover_StateChange_Move, UOmegaGrid3D_Mover*, Component, bool, Moving);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrid3DMover_StateChange_Rotate, UOmegaGrid3D_Mover*, Component, bool, Moving);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrid3DMover_MoveUpdate, UOmegaGrid3D_Mover*, Component,float, DeltaTime);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_Mover : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() float InputRange=90.0f;
	UPROPERTY() UOmegaGrid3D_Occupant* REF_occupant;

	UPROPERTY() int32 move_state=0;
	UPROPERTY() float move_alpha;
	
	UPROPERTY() FVector target_loc;
	UPROPERTY() FRotator target_rot;
	UPROPERTY() FVector origin_loc;
	UPROPERTY() FRotator origin_rot;
	
public:
	UOmegaGrid3D_Mover();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable) FOnGrid3DMover_StateChange_Move OnGrid3DMover_StateChange_Move;
	UPROPERTY(BlueprintAssignable) FOnGrid3DMover_StateChange_Rotate OnGrid3DMover_StateChange_Rotate;
	UPROPERTY(BlueprintAssignable) FOnGrid3DMover_MoveUpdate OnGrid3DMover_MoveUpdate;
	
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D|Mover")
	void SetLinkedOccupant(UOmegaGrid3D_Occupant* Occupant);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D|Mover")
	bool IsMoving() const;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mover")
	float MoveTime=0.5f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mover")
	float MoveDistance=100;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mover")
	bool bShouldTraceToBlockMovement;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mover")
	TEnumAsByte<ETraceTypeQuery> BlockMovement_TraceChanel;
	
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D|Mover",meta=(AdvancedDisplay="bOverrideDirection,DirectionOverride"))
	void AddInput_Movement(int32 X, int32 Y, int32 Z, FRotator DirectionOverride);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D|Mover")
	void AddInput_Rotation(int32 X, int32 Y, int32 Z);
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

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaGrid3D_Tile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY() FIntVector grid_coordinate;
	UPROPERTY() UOmegaGrid3D_Map* Owning_Gridmap;
	
	UPROPERTY(EditAnywhere,Category="Grid3D Tile")
	UOmegaGrid3DTileType* TileType;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	void SetTileType(UOmegaGrid3DTileType* Type);
	
	UFUNCTION(BlueprintPure,Category="Grid3D Tile")
	UOmegaGrid3DTileType* GetTileType() const;

	//Occupant
	UPROPERTY(VisibleAnywhere,Category="Grid3D Tile")
	TArray<UOmegaGrid3D_Occupant*> Occupants;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile",meta=(AdvancedDisplay="bSnap"))
	void SetOccupantOnTile(UOmegaGrid3D_Occupant* Occupant, bool bIsOnTile, bool bClearPrevious, bool bSnap=true);
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	TArray<UOmegaGrid3D_Occupant*> GetOccupants() const;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile")
	UOmegaGrid3D_Occupant* GetFirstOccupant() const;
	
	UFUNCTION(BlueprintCallable,Category="Grid3D Tile",meta=(DeterminesOutputType="Class",ExpandEnumAsExecs="Result"))
    AActor* GetFirstOccupantActorOfClass(TSubclassOf<AActor> Class, TEnumAsByte<EOmegaFunctionResult>& Result);
	
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

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3DFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(AdvancedDisplay="x,y,z"))
	TArray<FIntVector> GetAdjacentCoordinates(FIntVector in);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(AdvancedDisplay="x,y,z"))
	TArray<FIntVector> GetCoordinatesInDistance(FIntVector in, int32 distance);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D",meta=(AdvancedDisplay="metadata, Modifier, x,y,z"))
	static FOmegaGrid3DPathfindResult Pathfind3D_AllPossiblePaths(
		const FIntVector& StartPoint,
		int32 MaxDistance,
		UObject* Modifier,
		FOmegaGrid3DPathfindMeta metadata,
		bool x=true,bool y=true,bool z=false);

	UFUNCTION(BlueprintCallable,Category="Omega|Grid3D")
	static TArray<FIntVector> GetCoordinatesFromPathfindResult(FOmegaGrid3DPathfindResult in);

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
	bool CanAddCoordinate(FOmegaGrid3DPathfindMeta metadata, FIntVector coordinate) const;
};



UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_PathfindScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="Pathfind")
	int32 ModifyDistance(int32 distance, FOmegaGrid3DPathfindMeta metadata) const;
	UFUNCTION(BlueprintNativeEvent,Category="Pathfind")
	bool CanAddCoordinate(FOmegaGrid3DPathfindMeta metadata,FIntVector coord) const;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGrid3D_PathfindAction : public UOmegaDataAsset, public IDataInterface_Pathfind3D
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Pathfind")
	TArray<UOmegaGrid3D_PathfindScript*> Scripts;

	virtual int32 ModifyDistance_Implementation(FOmegaGrid3DPathfindMeta metadata, int32 in) const override;
	virtual bool CanAddCoordinate_Implementation(FOmegaGrid3DPathfindMeta metadata, FIntVector coordinate) const override;

};
