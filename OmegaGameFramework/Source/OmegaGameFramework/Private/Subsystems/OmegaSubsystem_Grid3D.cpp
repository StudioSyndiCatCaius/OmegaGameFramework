// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_Grid3D.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

UOmegaGrid3D_Map::UOmegaGrid3D_Map()
{
	GridSize=FIntVector(20,20,1);
	TileOffset=FVector(100,100,100);
}

void UOmegaGrid3D_Map::BeginPlay()
{
	GenerateTiles();
	GetWorld()->GetSubsystem<UOmegaSubsystem_Grid3D>()->Register_TileMap(this,true);
	Super::BeginPlay();
}

void UOmegaGrid3D_Map::OnComponentCreated()
{
	Super::OnComponentCreated();
	// Draw debug boxes when the component is created
	DrawDebugGrid();
}

void UOmegaGrid3D_Map::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UKismetSystemLibrary::FlushPersistentDebugLines(this);
	Super::EndPlay(EndPlayReason);
}

void UOmegaGrid3D_Map::DrawDebugGrid() const
{
	if (const AActor* Owner = GetOwner())
    {
		UKismetSystemLibrary::FlushPersistentDebugLines(this);

        // Draw the actual debug boxes persistently
        for (int32 X = 0; X < GridSize.X; ++X)
        {
            for (int32 Y = 0; Y < GridSize.Y; ++Y)
            {
                for (int32 Z = 0; Z < GridSize.Z; ++Z)
                {
                    FVector BoxLocation = Owner->GetActorLocation()+GetRelativeLocation() + (TileOffset*UKismetMathLibrary::Conv_IntVectorToVector(FIntVector(X,Y,Z)));

                    // Draw the final persistent debug box after flushing
                    DrawDebugBox(
                        GetWorld(),
                        BoxLocation,
                        TileOffset/2,
                        FQuat::Identity,
                        PreviewBoxColor,
                        true,      // Persistent boxes
                        -1.f,      // Infinite lifetime
                        0,
                        PreviewBoxThickness
                    );
                }
            }
        }
    }
}

void UOmegaGrid3D_Map::DestroyTiles()
{
	for(auto* tempTile : REF_Tiles)
	{
		if(tempTile)
		{
			tempTile->K2_DestroyActor();
		}
	}
}

void UOmegaGrid3D_Map::GenerateTiles()
{
	DestroyTiles();
	if(!TileClass)
	{
		return;
	}
	for (int ix = 0; ix < GridSize.X; ++ix)
	{
		for (int iy = 0; iy < GridSize.Y; ++iy)
		{
			for (int iz = 0; iz < GridSize.Z; ++iz)
			{
				FIntVector new_coord = FIntVector(ix,iy,iz);
				AOmegaGrid3D_Tile* new_tile = GetWorld()->SpawnActorDeferred<AOmegaGrid3D_Tile>(TileClass,FTransform());
				new_tile->AttachToActor(GetOwner(),FAttachmentTransformRules(EAttachmentRule::SnapToTarget,false));
				new_tile->Owning_Gridmap=this;
				new_tile->grid_coordinate=new_coord;
				FTransform newTransform=FTransform();
				newTransform.SetLocation(GetVectorFromCoordinate(new_coord));
				newTransform.SetRotation(GetOwner()->GetActorRotation().Quaternion());
				newTransform.SetScale3D(FVector(1,1,1));
				new_tile->FinishSpawning(newTransform);
				new_tile->AttachToActor(GetOwner(),FAttachmentTransformRules(EAttachmentRule::KeepWorld,false));
				REF_Tiles.AddUnique(new_tile);
			}
		}
	}
}

TArray<AOmegaGrid3D_Tile*> UOmegaGrid3D_Map::GetTiles()
{
	return REF_Tiles;
}

FIntVector UOmegaGrid3D_Map::GetCoordinateFromVector(FVector Vector)
{
	FVector local_vector=(Vector-GetOwner()->GetActorLocation())/TileOffset;
	return UKismetMathLibrary::FTruncVector(local_vector);
}

FVector UOmegaGrid3D_Map::GetVectorFromCoordinate(FIntVector Coordinate)
{
	return (UKismetMathLibrary::Conv_IntVectorToVector(Coordinate)*TileOffset)+GetOwner()->GetActorLocation();
}

AOmegaGrid3D_Tile* UOmegaGrid3D_Map::GetTileFromVector(FVector Vector)
{
	if(AOmegaGrid3D_Tile* out_tile = GetTileFromCoordinate(GetCoordinateFromVector(Vector)))
	{
		return out_tile;
	}
	return nullptr;
}

AOmegaGrid3D_Tile* UOmegaGrid3D_Map::GetTileFromCoordinate(FIntVector Coordinate)
{
	for(auto* tempTile: GetTiles())
	{
		if(tempTile && tempTile->GetTileCoordinate()==Coordinate)
		{
			return tempTile;
		}
	}
	return nullptr;
}



void AOmegaGridmap3D::OnConstruction(const FTransform& Transform)
{
	if(GridmapComponent)
	{
		GridmapComponent->DrawDebugGrid();
	}
	Super::OnConstruction(Transform);
}

void UOmegaGrid3D_Occupant::BeginPlay()
{
	Super::BeginPlay();
	if(AutoSnapToTile)
	{
		SnapToNearestTile();
	}
}


void UOmegaGrid3D_Occupant::SnapToNearestTile()
{

	TArray<TEnumAsByte<EObjectTypeQuery>>	query_types;
	TArray<AActor*> ignored_actors;
	ignored_actors.Add(GetOwner());
	query_types.Add(EObjectTypeQuery::ObjectTypeQuery1);
	query_types.Add(EObjectTypeQuery::ObjectTypeQuery2);
	query_types.Add(EObjectTypeQuery::ObjectTypeQuery3);
	TArray<AActor*> found_actors;
	UKismetSystemLibrary::SphereOverlapActors(this,GetOwner()->GetActorLocation(),AutoSnapDistance,query_types,AOmegaGrid3D_Tile::StaticClass(),ignored_actors,found_actors);
	
	float DumpFloat;
	if(AActor* out_actor = UGameplayStatics::FindNearestActor(GetOwner()->GetActorLocation(),found_actors,DumpFloat))
	{
		SetTile(Cast<AOmegaGrid3D_Tile>(out_actor),true,true);
	}
}

void UOmegaGrid3D_Occupant::SetTile(AOmegaGrid3D_Tile* Tile, bool bClearPrevious, bool bSnap)
{
	if(Tile)
	{
		Tile->SetOccupantOnTile(this,true,bClearPrevious,bSnap);
	}
}

AOmegaGrid3D_Tile* UOmegaGrid3D_Occupant::GetTile()
{
	for (auto* TempMap : GetWorld()->GetSubsystem<UOmegaSubsystem_Grid3D>()->REF_Tilemaps)
	{
		if (TempMap)
		{
			for(auto* TempTile : TempMap->GetTiles())
			{
				if(TempTile && TempTile->Occupants.Contains(this))
				{
					return TempTile;
				}
			}
		}
	}
	return nullptr;
}

void UOmegaGrid3D_Selector::SetSelectedTile(AOmegaGrid3D_Tile* Tile)
{
	if(REF_SelectedTile && Tile && REF_SelectedTile==Tile)
	{
		return;
	}
	if(REF_SelectedTile)
	{
		OnGrid3DTileSelected.Broadcast(REF_SelectedTile,false);
		REF_SelectedTile=nullptr;
	}
	if(Tile)
	{
		REF_SelectedTile=Tile;
		OnGrid3DTileSelected.Broadcast(Tile,true);
	}
}

AOmegaGrid3D_Tile* UOmegaGrid3D_Selector::GetSelectedTile()
{
	if(REF_SelectedTile) { return  REF_SelectedTile; } return nullptr;
}

void UOmegaGrid3D_Selector::SetTileRegistered(AOmegaGrid3D_Tile* Tile, bool bTileRegistered)
{
	if(Tile)
	{
		if(bTileRegistered && !REF_RegisteredTiles.Contains(Tile))
		{
			REF_RegisteredTiles.AddUnique(Tile);
			OnGrid3DTileRegistered.Broadcast(Tile,true);
		}
		else if(REF_RegisteredTiles.Contains(Tile))
		{
			REF_RegisteredTiles.Remove(Tile);
			OnGrid3DTileRegistered.Broadcast(Tile,false);
		}
	}
}

TArray<AOmegaGrid3D_Tile*> UOmegaGrid3D_Selector::GetRegisteredTiles()
{
	return REF_RegisteredTiles;
}

void UOmegaGrid3D_Selector::RegisterTiles(TArray<AOmegaGrid3D_Tile*> Tiles, bool bClearFirst)
{
	if(bClearFirst)
	{
		ClearRegisteredTiles();
	}
	for(auto* TempTile : Tiles)
	{
		if(TempTile)
		{
			SetTileRegistered(TempTile,true);
		}
	}
}

void UOmegaGrid3D_Selector::ClearRegisteredTiles()
{
	for(auto* TempTile : REF_RegisteredTiles)
	{
		if(TempTile)
		{
			SetTileRegistered(TempTile,false);
		}
	}
}


void AOmegaGrid3D_Tile::SetTileType(UOmegaGrid3DTileType* Type)
{
	if(Type)
	{
		TileType=Type;
	}
}

UOmegaGrid3DTileType* AOmegaGrid3D_Tile::GetTileType() const
{
	if(TileType) {return TileType; } return nullptr;
}


void AOmegaGrid3D_Tile::SetOccupantOnTile(UOmegaGrid3D_Occupant* Occupant, bool bIsOnTile, bool bClearPrevious,
	bool bSnap)
{
	if(Occupant)
	{
		if(bIsOnTile && !HasOccupant(Occupant))
		{
			if(bClearPrevious && Occupant->GetTile())
			{
				Occupant->GetTile()->SetOccupantOnTile(Occupant,false,false,false);
			}
			Occupants.AddUnique(Occupant);
			if(bSnap)
			{
				Occupant->GetOwner()->SetActorLocation(GetActorLocation()+Occupant->TileOffset);
			}
		}
		if(!bIsOnTile && HasOccupant(Occupant))
		{
			Occupants.Remove(Occupant);
		}
	}
}

TArray<UOmegaGrid3D_Occupant*> AOmegaGrid3D_Tile::GetOccupants() const
{
	return Occupants;
}

UOmegaGrid3D_Occupant* AOmegaGrid3D_Tile::GetFirstOccupant() const
{
	for(auto* TempOccupant : GetOccupants())
	{
		if(TempOccupant)
		{
			return  TempOccupant;
		}
	}
	return nullptr;
}

bool AOmegaGrid3D_Tile::HasOccupant(UOmegaGrid3D_Occupant* Occupant) const
{
	
	if(Occupants.IsEmpty()) { return false; }
	for(auto* TempOcc :Occupants)
	{
		if(TempOcc && TempOcc==Occupant)
		{
			return true;
		}	
	}
	return false;
}

UOmegaGrid3D_Map* AOmegaGrid3D_Tile::GetOwningGridmap()
{
	if(Owning_Gridmap)
	{
		return Owning_Gridmap;
	}
	return nullptr;
}

FIntVector AOmegaGrid3D_Tile::GetTileCoordinate()
{
	return  grid_coordinate;
}

void UOmegaSubsystem_Grid3D::Register_TileMap(UOmegaGrid3D_Map* Tilemap, bool bRegistered)
{
	if(Tilemap)
	{
		if(bRegistered && !REF_Tilemaps.Contains(Tilemap))
		{
			REF_Tilemaps.AddUnique(Tilemap);
		}
		else if(REF_Tilemaps.Contains(Tilemap))
		{
			REF_Tilemaps.Remove(Tilemap);
		}
	}
}
