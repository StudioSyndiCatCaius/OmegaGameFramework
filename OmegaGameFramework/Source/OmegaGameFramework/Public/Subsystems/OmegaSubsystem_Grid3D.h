// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subsystems/WorldSubsystem.h"
#include "Engine/DataAsset.h"
#include "OmegaSubsystem_Grid3D.generated.h"

// ===============================================================================================================================
// Tilemap Component
// ===============================================================================================================================

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
	UFUNCTION(BlueprintCallable,Category="Grid3D")
	TArray<AOmegaGrid3D_Tile*> GetTiles();
	
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
	UFUNCTION(BlueprintPure,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTileFromVector(FVector Vector);
	UFUNCTION(BlueprintPure,Category="Grid3D")
	AOmegaGrid3D_Tile* GetTileFromCoordinate(FIntVector Coordinate);

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