// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Grid3D.h"
#include "Engine/World.h"
#include "Functions/F_Utility.h"
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

TArray<AOmegaGrid3D_Tile*> UOmegaGrid3D_Map::GetTilesFromCoordinates(TArray<FIntVector> Coordinates)
{
	TArray<AOmegaGrid3D_Tile*> out;
	for(auto* tile : GetTiles())
	{
		if(tile && Coordinates.Contains(tile->GetTileCoordinate()))
		{
			out.Add(tile);
		}
	}
	return out;
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



AOmegaGrid3D_Tile* UOmegaGrid3D_Map::GetTile_OfOccupant_Comp(UOmegaGrid3D_Occupant* Occupant)
{
	if(Occupant)
	{
		for (auto* _tile : GetTiles())
		{
			for(auto* _occ : _tile->Occupants)
			{
				if(_occ)
				{
					if(_occ==Occupant)
					{
						return _tile;
					}
				}
			}
		}
	}
	return nullptr;
}

AOmegaGrid3D_Tile* UOmegaGrid3D_Map::GetTile_OfOccupant_Actor(AActor* Occupant)
{
	if(Occupant)
	{
		for (auto* _tile : GetTiles())
		{
			for(auto* _occ : _tile->Occupants)
			{
				if(_occ)
				{
					if(_occ->GetOwner()==Occupant)
					{
						return _tile;
					}
				}
			}
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

// =====================================================================================================
// Mover
// =====================================================================================================

UOmegaGrid3D_Mover::UOmegaGrid3D_Mover()
{
	PrimaryComponentTick.bCanEverTick=true;
	PrimaryComponentTick.bStartWithTickEnabled=true;
}

void UOmegaGrid3D_Mover::BeginPlay()
{
	Super::BeginPlay();
}

void UOmegaGrid3D_Mover::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	if(move_state!=0)
	{
		move_alpha+=DeltaTime;
		float normalized_alpha=UKismetMathLibrary::FClamp(move_alpha/MoveTime,0,1);
		if(move_state==1)
		{
			if(UKismetMathLibrary::Vector_Distance(GetOwner()->GetActorLocation(),target_loc)<=0.01)
			{
				move_state=0;
				GetOwner()->SetActorLocation(target_loc);
				OnGrid3DMover_StateChange_Move.Broadcast(this,false);
			}
			else
			{
				GetOwner()->SetActorLocation(UKismetMathLibrary::VLerp(origin_loc,target_loc,normalized_alpha));
				//OnGrid3DMover_MoveUpdate.Broadcast(this,DeltaTime);
			}
		}
		if(move_state==2)
		{
			if(UKismetMathLibrary::EqualEqual_RotatorRotator(GetOwner()->GetActorRotation(),target_rot,0.01))
			{
				move_state=0;
				GetOwner()->SetActorRotation(target_rot);
				OnGrid3DMover_StateChange_Rotate.Broadcast(this,false);
			}
			else
			{
				GetOwner()->SetActorRotation(UKismetMathLibrary::RLerp(origin_rot,target_rot,normalized_alpha,true));
				//OnGrid3DMover_MoveUpdate.Broadcast(this,DeltaTime);
			}
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UOmegaGrid3D_Mover::SetLinkedOccupant(UOmegaGrid3D_Occupant* Occupant)
{
	REF_occupant=nullptr;
	if(Occupant)
	{
		REF_occupant=Occupant;
	}
}

bool UOmegaGrid3D_Mover::IsMoving() const
{
	if(move_state==0) { return false;} return true;
}


void UOmegaGrid3D_Mover::AddInput_Movement(int32 X, int32 Y, int32 Z,
	FRotator DirectionOverride)
{
	
	if(!IsMoving())
	{
		move_alpha=0.0;
		origin_loc=GetOwner()->GetActorLocation();
		target_loc=UOmegaMathFunctions::Offset_Vector(GetOwner()->GetActorLocation(),DirectionOverride,(FVector(X,Y,Z)*MoveDistance));
		TArray<AActor*> _ignoredActors;
		_ignoredActors.Add(GetOwner());
		FHitResult _hit=FHitResult();
		if(bShouldTraceToBlockMovement && UKismetSystemLibrary::LineTraceSingle(this,origin_loc,target_loc,BlockMovement_TraceChanel,true,_ignoredActors,EDrawDebugTrace::None,_hit,true))
		{
			return;
		}
		else
		{
			OnGrid3DMover_StateChange_Move.Broadcast(this,true);
			move_state=1;
		}
		
	}
}

void UOmegaGrid3D_Mover::AddInput_Rotation(int32 X, int32 Y, int32 Z)
{
	if(!IsMoving())
	{
		move_alpha=0.0;
		origin_rot=GetOwner()->GetActorRotation();
		target_rot=UKismetMathLibrary::ComposeRotators(FRotator(Y*InputRange,Z*InputRange,X*InputRange),GetOwner()->GetActorRotation());
		OnGrid3DMover_StateChange_Rotate.Broadcast(this,true);
		move_state=2;
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

AActor* AOmegaGrid3D_Tile::GetFirstOccupantActorOfClass(TSubclassOf<AActor> Class,
	bool& Result)
{
	for(auto* oc : GetOccupants())
	{
		if(oc && (!Class || oc->GetOwner()->GetClass()->IsChildOf(Class)))
		{
			Result=true;
			return oc->GetOwner();
		}
	}
	Result=false;
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

TArray<FIntVector> UOmegaGrid3DFunctions::GetAdjacentCoordinates(FIntVector in)
{
	TArray<FIntVector> out;
	TArray<FIntVector> _checks;
	
	int32 _inputs[2] = {1,-1};

	for (int32 t_x : _inputs)
	{
		for (int32 t_y : _inputs)
		{
			for (int32 t_z : _inputs)
			{
				_checks.AddUnique(FIntVector(t_x,t_y,t_z));
			}
		}
	}

	for (FIntVector vec_to_check : _checks)
	{
		out.AddUnique(vec_to_check+in);
	}

	return out;
}

TArray<FIntVector> UOmegaGrid3DFunctions::GetCoordinatesInDistance(FIntVector in, int32 distance)
{
	TArray<FIntVector> out;
	
	int32 remaining_distance=distance;
	TArray<FIntVector> evaluated;
	
	evaluated.Add(in);

	for(FIntVector current_coord : evaluated)
	{
		TArray<FIntVector> Added;
		Added=GetAdjacentCoordinates(current_coord);
	}
	
	return out;
}

FOmegaGrid3DPathfindResult UOmegaGrid3DFunctions::Pathfind3D_AllPossiblePaths(const FIntVector& StartPoint, int32 MaxDistance,
	UObject* Modifier,FOmegaGrid3DPathfindMeta metadata, bool x,bool y,bool z)
{
	FOmegaGrid3DPathfindResult out;
	TArray<FOmegaGrid3DPath> AllPaths;
    
    // Define possible movement directions (only adjacent, no diagonals)
    // Up, Down, North, South, East, West
	TArray<FIntVector> Directions;

	if(x)
	{
		Directions.Add(FIntVector(1, 0, 0) );
		Directions.Add(FIntVector(-1, 0, 0) );
	}
	if(y)
	{
		Directions.Add(FIntVector(0, 1, 0) );
		Directions.Add(FIntVector(0, -1, 0) );
	}
	if(z)
	{
		Directions.Add(FIntVector(0, 0, 1) );
		Directions.Add(FIntVector(0, 0, -1) );
	}
    
    // Helper function for recursive path finding
    struct FPathFinder
    {
        TSet<FIntVector> Visited;
        TArray<FOmegaGrid3DPath>& OutPaths;
        const TArray<FIntVector>& Dirs;
        int32 MaxDist;
        
        FPathFinder(TArray<FOmegaGrid3DPath>& InPaths, const TArray<FIntVector>& InDirs, int32 InMaxDist)
            : OutPaths(InPaths), Dirs(InDirs), MaxDist(InMaxDist) {}
        
        void FindPaths(const FIntVector& CurrentPos, FOmegaGrid3DPath CurrentPath, int32 StepsRemaining,UObject* Modifier,FOmegaGrid3DPathfindMeta metadata)
        {
            // Add current position to the path
            CurrentPath.PathPoints.Add(CurrentPos);
            
            // If we've reached the maximum distance, add this path to our results
            if (StepsRemaining <= 0)
            {
                OutPaths.Add(CurrentPath);
                return;
            }
            
            // Mark current position as visited for this path
            Visited.Add(CurrentPos);
            
            // Try each direction
            for (const FIntVector& Dir : Dirs)
            {
                FIntVector NextPos = CurrentPos + Dir;

            	//skip if blocked by modifier
				if(Modifier && Modifier->GetClass()->ImplementsInterface(UDataInterface_Pathfind3D::StaticClass()))
				{
					if(!IDataInterface_Pathfind3D::Execute_CanAddCoordinate(Modifier,metadata,NextPos,StepsRemaining))
					{
						continue;
					}
				}
            	
                // Skip if we've already visited this position in the current path
                if (Visited.Contains(NextPos))
                {
                    continue;
                }
                
                // Create a new path branching from here
                FOmegaGrid3DPath NewPath = CurrentPath;
                
                // Recursively find paths from the new position
                TSet<FIntVector> VisitedCopy = Visited;
                FindPaths(NextPos, NewPath, StepsRemaining - 1,Modifier,metadata);
                Visited = VisitedCopy;
            }
            
            // We're done exploring from this position, remove it from visited
            Visited.Remove(CurrentPos);
        }
    };

	int32 in_distance=MaxDistance;
	//skip if blocked by modifier
	if(Modifier && Modifier->GetClass()->ImplementsInterface(UDataInterface_Pathfind3D::StaticClass()))
	{
		in_distance=IDataInterface_Pathfind3D::Execute_ModifyDistance(Modifier,metadata,in_distance);
	}
	
    // Start the recursive path finding
    FOmegaGrid3DPath InitialPath;
    FPathFinder PathFinder(AllPaths, Directions, in_distance);
    PathFinder.FindPaths(StartPoint, InitialPath, in_distance,Modifier,metadata);

	out.paths=AllPaths;
    return out;
}

TArray<FIntVector> UOmegaGrid3DFunctions::GetCoordinatesFromPathfindResult(FOmegaGrid3DPathfindResult in)
{
	TArray<FIntVector> out;
	for(FOmegaGrid3DPath path : in.paths)
	{
		for(FIntVector vec : path.PathPoints)
		{
			out.Add(vec);
		}
	}
	return out;
}

AOmegaGrid3D_Tile* UOmegaGrid3DFunctions::GetGrid3DTileInfo(UObject* Object, TSubclassOf<AOmegaGrid3D_Tile> TileClass,
	UOmegaGrid3D_Occupant*& Occupant, bool& result)
{
	AOmegaGrid3D_Tile* tile_out = nullptr;
	if(Object)
	{
		if(AActor* _actor=Cast<AActor>(Object))
		{
			if(AOmegaGrid3D_Tile* _tile = Cast<AOmegaGrid3D_Tile>(_actor))
			{
				tile_out=_tile;
			}
			if(UOmegaGrid3D_Occupant* _occ=Cast<UOmegaGrid3D_Occupant>(_actor->GetComponentByClass(UOmegaGrid3D_Occupant::StaticClass())))
			{
				tile_out=_occ->GetTile();
			}	
		}
		if(UOmegaGrid3D_Occupant* _occ=Cast<UOmegaGrid3D_Occupant>(Object))
		{
			tile_out=_occ->GetTile();
		}	
	}
	if(tile_out && (!TileClass || tile_out->GetClass()->IsChildOf(TileClass)))
	{
		Occupant=tile_out->GetFirstOccupant();
		result=true;
		return tile_out;
	}
	result=false;
	Occupant=nullptr;
	return nullptr;
}

TArray<AOmegaGrid3D_Tile*> UOmegaGrid3DFunctions::GetTilesFromPath(UOmegaGrid3D_Map* Tilemap, FOmegaGrid3DPath Path)
{
	TArray<AOmegaGrid3D_Tile*> out;
	if(Tilemap)
	{
		for(FIntVector p : Path.PathPoints)
		{
			if(AOmegaGrid3D_Tile* _tile = Tilemap->GetTileFromCoordinate(p))
			{
				out.Add(_tile);
			}
		}
	}
	return out;
}

TArray<AOmegaGrid3D_Tile*> UOmegaGrid3DFunctions::GetTilesFromPathfind(UOmegaGrid3D_Map* Tilemap,
	FOmegaGrid3DPathfindResult Path, bool bOnlyLast)
{
	TArray<AOmegaGrid3D_Tile*> out;
	if(Tilemap)
	{
		for(FOmegaGrid3DPath p : Path.paths)
		{
			TArray<AOmegaGrid3D_Tile*> _tempTiles=GetTilesFromPath(Tilemap,p);
			if(bOnlyLast)
			{
				if(_tempTiles.IsValidIndex(0)) { out.Add(_tempTiles[0]);}
			}
			else
			{
				out.Append(_tempTiles);
			}
		}
	}
	return out;
}


FOmegaGrid3DPath UOmegaGrid3DFunctions::GetShortestPath_ToCoordinate(FOmegaGrid3DPathfindResult pathfind,
                                                                     FIntVector coord, bool& result)
{
	bool is_init=false;
	FOmegaGrid3DPath out=FOmegaGrid3DPath();
	
	for(FOmegaGrid3DPath p : pathfind.paths)
	{
		if(p.PathPoints.Last()==coord)
		{
			result=true;
			if(!is_init || p.PathPoints.Num()<out.PathPoints.Num())
			{
				is_init=true;
				out=p;
			}
		}
	}
	if(result)
	{
		return out;
	}
	result=false;
	return  FOmegaGrid3DPath();
}

FOmegaGrid3DPath UOmegaGrid3DFunctions::GetShortestPath_ToTile(FOmegaGrid3DPathfindResult pathfind,
	AOmegaGrid3D_Tile* tile, bool& result)
{
	if(tile)
	{
		return GetShortestPath_ToCoordinate(pathfind,tile->GetTileCoordinate(),result);
	}
	result=false;
	return  FOmegaGrid3DPath();
}

int32 UOmegaGrid3D_PathfindScript::ModifyDistance_Implementation(int32 distance, FOmegaGrid3DPathfindMeta metadata) const
{
	return distance;
}

bool UOmegaGrid3D_PathfindScript::CanAddCoordinate_Implementation(FOmegaGrid3DPathfindMeta metadata, FIntVector coord, int32 MovesRemaining) const
{
	return true;
}

int32 UOmegaGrid3D_PathfindAction::ModifyDistance_Implementation(FOmegaGrid3DPathfindMeta metadata, int32 in) const
{
	int32 out=in;
	for(auto* s : Scripts)
	{
		if(s)
		{
			out=s->ModifyDistance(in,metadata);
		}
	}
	return out;
}

bool UOmegaGrid3D_PathfindAction::CanAddCoordinate_Implementation(FOmegaGrid3DPathfindMeta metadata, FIntVector coordinate, int32 MovesRemaining) const
{
	for(auto* s : Scripts)
	{
		if(s)
		{
			if(!s->CanAddCoordinate(metadata,coordinate,MovesRemaining))
			{
				return false;
			}
		}
	}
	return true;
}
