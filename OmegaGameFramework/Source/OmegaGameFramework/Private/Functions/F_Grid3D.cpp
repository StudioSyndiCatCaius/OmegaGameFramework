// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Grid3D.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Functions/F_Math.h"
#include "Functions/F_Utility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

UOmegaGrid3D_Map::UOmegaGrid3D_Map()
{
	GridSize=FIntVector(20,20,1);
	TileOffset=FVector(100,100,100);
}

void UOmegaGrid3D_Map::BeginPlay()
{
	GenerateTiles();
	if(GetHostGridmap()==this)
	{
		GetWorld()->GetSubsystem<UOmegaSubsystem_Grid3D>()->Register_TileMap(this,true);
	}
	Super::BeginPlay();
	// Addons have already injected their tiles into their host map, so remove them from the
	// world - they should not be found as gridmaps of their own.
	if(GetHostGridmap()!=this)
	{
		if(AOmegaGridmap3D* gridmap_actor=Cast<AOmegaGridmap3D>(GetOwner()))
		{
			gridmap_actor->Destroy();
		}
		else
		{
			DestroyComponent();
		}
	}
}

UOmegaGrid3D_Map* UOmegaGrid3D_Map::GetHostGridmap()
{
	if(!bIsAddon)
	{
		return this;
	}
	if(REF_HostGridmap)
	{
		return REF_HostGridmap;
	}
	if(AddonLinkedGridmap && AddonLinkedGridmap->GridmapComponent && AddonLinkedGridmap->GridmapComponent!=this)
	{
		REF_HostGridmap=AddonLinkedGridmap->GridmapComponent;
	}
	else
	{
		// No host set - link to the first found gridmap actor that is not itself an addon
		TArray<AActor*> found_gridmaps;
		UGameplayStatics::GetAllActorsOfClass(this,AOmegaGridmap3D::StaticClass(),found_gridmaps);
		for(AActor* _actor : found_gridmaps)
		{
			AOmegaGridmap3D* _gridmap=Cast<AOmegaGridmap3D>(_actor);
			if(_gridmap && _gridmap->GridmapComponent && _gridmap->GridmapComponent!=this && !_gridmap->GridmapComponent->bIsAddon)
			{
				REF_HostGridmap=_gridmap->GridmapComponent;
				break;
			}
		}
	}
	if(REF_HostGridmap)
	{
		return REF_HostGridmap;
	}
	// No host could be found - act as a standalone map
	return this;
}

void UOmegaGrid3D_Map::OnComponentCreated()
{
	Super::OnComponentCreated();
	// Draw debug boxes when the component is created

}

void UOmegaGrid3D_Map::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UKismetSystemLibrary::FlushPersistentDebugLines(this);
	Super::EndPlay(EndPlayReason);
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
	REF_Tiles.Empty();
}

void UOmegaGrid3D_Map::GenerateTiles()
{
	UOmegaGrid3D_Map* host=GetHostGridmap();
	if(host!=this)
	{
		// Addon: append this map's coordinates (converted to host space) to the host's list,
		// then let the host (re)generate so it owns the resulting tiles.
		for (int ix = 0; ix < GridSize.X; ++ix)
		{
			for (int iy = 0; iy < GridSize.Y; ++iy)
			{
				for (int iz = 0; iz < GridSize.Z; ++iz)
				{
					host->REF_AddonCoordinates.AddUnique(host->GetCoordinateFromVector(GetVectorFromCoordinate(FIntVector(ix,iy,iz))));
				}
			}
		}
		host->GenerateTiles();
		return;
	}

	DestroyTiles();
	TSubclassOf<AOmegaGrid3D_Tile> in_tile_class=AOmegaGrid3D_Tile::StaticClass();
	if(TileClass)
	{
		in_tile_class=TileClass;
	}
	TArray<FIntVector> spawn_coords;
	for (int ix = 0; ix < GridSize.X; ++ix)
	{
		for (int iy = 0; iy < GridSize.Y; ++iy)
		{
			for (int iz = 0; iz < GridSize.Z; ++iz)
			{
				spawn_coords.AddUnique(FIntVector(ix,iy,iz));
			}
		}
	}
	for(const FIntVector& addon_coord : REF_AddonCoordinates)
	{
		spawn_coords.AddUnique(addon_coord);
	}
	for (const FIntVector& new_coord : spawn_coords)
	{
		AOmegaGrid3D_Tile* new_tile = GetWorld()->SpawnActorDeferred<AOmegaGrid3D_Tile>(in_tile_class,FTransform());
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

AOmegaGridmap3D::AOmegaGridmap3D()
{
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));
	GridmapComponent=CreateDefaultSubobject<UOmegaGrid3D_Map>(TEXT("Gridmap"));
	GridmapComponent->SetupAttachment(GetRootComponent());

	PreviewMesh=CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("PreviewMesh"));
	PreviewMesh->SetupAttachment(GetRootComponent());
	PreviewMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PreviewMesh->SetHiddenInGame(true);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> default_preview_mesh(TEXT("/OmegaGameFramework/Meshes/util/sm_UTIL_GridmapPreview_100x.sm_UTIL_GridmapPreview_100x"));
	if(default_preview_mesh.Succeeded())
	{
		PreviewMesh->SetStaticMesh(default_preview_mesh.Object);
	}
}


void AOmegaGridmap3D::OnConstruction(const FTransform& Transform)
{
	if(GridmapComponent && PreviewMesh)
	{
		const TCHAR* preview_mat_path=GridmapComponent->bIsAddon
			? TEXT("/OmegaGameFramework/DEMO/Grid3D/Materials/M_Grid3D_Tile__previewAddon.M_Grid3D_Tile__previewAddon")
			: TEXT("/OmegaGameFramework/DEMO/Grid3D/Materials/M_Grid3D_Tile__preview.M_Grid3D_Tile__preview");
		if(UMaterialInterface* preview_mat=LoadObject<UMaterialInterface>(nullptr,preview_mat_path))
		{
			PreviewMesh->SetMaterial(0,preview_mat);
		}

		// Remake preview instances to align with the tile locations. Preview mesh is authored at 100 units,
		// so instances are scaled to match the tile offset.
		PreviewMesh->ClearInstances();
		const FVector instance_scale=GridmapComponent->TileOffset/100.f;
		for (int32 ix = 0; ix < GridmapComponent->GridSize.X; ++ix)
		{
			for (int32 iy = 0; iy < GridmapComponent->GridSize.Y; ++iy)
			{
				for (int32 iz = 0; iz < GridmapComponent->GridSize.Z; ++iz)
				{
					FTransform inst_transform=FTransform();
					inst_transform.SetLocation(GridmapComponent->GetVectorFromCoordinate(FIntVector(ix,iy,iz)));
					inst_transform.SetRotation(GetActorRotation().Quaternion());
					inst_transform.SetScale3D(instance_scale);
					PreviewMesh->AddInstance(inst_transform,true);
				}
			}
		}
	}
	Super::OnConstruction(Transform);
}

UOmegaGrid3D_Occupant::UOmegaGrid3D_Occupant()
{
	PrimaryComponentTick.bCanEverTick=true;
	PrimaryComponentTick.bStartWithTickEnabled=true;
}

void UOmegaGrid3D_Occupant::BeginPlay()
{
	Super::BeginPlay();
	if(AutoSnapToTile)
	{
		// Deferred a tick so all gridmaps (including addon injections & regenerations) have
		// finished generating their tiles before snapping.
		GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this,[this]()
		{
			SnapToNearestTile();
		}));
	}
}

void UOmegaGrid3D_Occupant::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* owner=GetOwner();
	if(!owner) { return; }
	if(bMoving)
	{
		motion_alpha+=DeltaTime;
		// A bump travels half the distance per leg, so each leg runs at half the duration
		const float leg_duration=FMath::Max(bBumping ? MoveDuration*0.5f : MoveDuration, KINDA_SMALL_NUMBER);
		const float t=FMath::Clamp(motion_alpha/leg_duration,0.f,1.f);
		owner->SetActorLocation(FMath::Lerp(move_from,move_target,t));
		if(t>=1.f)
		{
			if(bBumping && !bBumpReturning)
			{
				// Reached the halfway point of an invalid move - notify, then head back to the origin
				bBumpReturning=true;
				move_from=move_target;
				move_target=move_origin;
				motion_alpha=0;
				OnOccupantMovementBump.Broadcast(this);
			}
			else
			{
				bMoving=false;
				bBumping=false;
				bBumpReturning=false;
				cooldown_remaining=MotionCooldownDuration;
				if(REF_MoveTargetTile)
				{
					SetTile(REF_MoveTargetTile,true,true);
					REF_MoveTargetTile=nullptr;
				}
				OnOccupantMotionEnd.Broadcast(this,false);
			}
		}
	}
	else if(bRotating)
	{
		motion_alpha+=DeltaTime;
		const float t=FMath::Clamp(motion_alpha/FMath::Max(RotateDuration,KINDA_SMALL_NUMBER),0.f,1.f);
		owner->SetActorRotation(UKismetMathLibrary::RLerp(rotate_origin,rotate_target,t,true));
		if(t>=1.f)
		{
			owner->SetActorRotation(rotate_target);
			bRotating=false;
			cooldown_remaining=MotionCooldownDuration;
			OnOccupantMotionEnd.Broadcast(this,true);
		}
	}
	else if(cooldown_remaining>0.f)
	{
		cooldown_remaining=FMath::Max(cooldown_remaining-DeltaTime,0.f);
	}
}

bool UOmegaGrid3D_Occupant::Input_Move(FIntVector Direction, bool RotationRelative)
{
	if(bMoving || bRotating || cooldown_remaining>0.f || Direction==FIntVector::ZeroValue)
	{
		return false;
	}
	AOmegaGrid3D_Tile* current_tile=GetTile();
	if(!current_tile || !current_tile->GetOwningGridmap())
	{
		return false;
	}
	FIntVector dir=Direction;
	if(RotationRelative)
	{
		const FVector rotated=GetOwner()->GetActorRotation().RotateVector(FVector(Direction.X,Direction.Y,Direction.Z));
		dir=FIntVector(FMath::RoundToInt(rotated.X),FMath::RoundToInt(rotated.Y),FMath::RoundToInt(rotated.Z));
	}
	UOmegaGrid3D_Map* map=current_tile->GetOwningGridmap();
	const FIntVector target_coord=current_tile->GetTileCoordinate()+dir;
	AOmegaGrid3D_Tile* target_tile=map->GetTileFromCoordinate(target_coord);
	const bool valid_move=target_tile && (!Query_CanMoveToTile.IsBound() || Query_CanMoveToTile.Execute(this,target_tile));

	move_origin=GetOwner()->GetActorLocation();
	move_from=move_origin;
	motion_alpha=0;
	const FVector target_loc=map->GetVectorFromCoordinate(target_coord)+TileOffset;
	if(valid_move)
	{
		move_target=target_loc;
		REF_MoveTargetTile=target_tile;
		bBumping=false;
		bBumpReturning=false;
		bMoving=true;
		OnOccupantMotionBegin.Broadcast(this,false);
		return true;
	}
	if(BumpOnInvalidMove)
	{
		move_target=(move_origin+target_loc)/2;
		REF_MoveTargetTile=nullptr;
		bBumping=true;
		bBumpReturning=false;
		bMoving=true;
		OnOccupantMotionBegin.Broadcast(this,false);
	}
	return false;
}

bool UOmegaGrid3D_Occupant::Input_Rotate(FIntVector Amount, bool RotationRelative)
{
	if(bMoving || bRotating || cooldown_remaining>0.f || Amount==FIntVector::ZeroValue)
	{
		return false;
	}
	// Amount is in 90 degree grid steps: X=Roll, Y=Pitch, Z=Yaw
	const FRotator rot_amount=FRotator(Amount.Y*90.f,Amount.Z*90.f,Amount.X*90.f);
	rotate_origin=GetOwner()->GetActorRotation();
	if(RotationRelative)
	{
		rotate_target=UKismetMathLibrary::ComposeRotators(rot_amount,rotate_origin);
	}
	else
	{
		rotate_target=rot_amount;
	}
	motion_alpha=0;
	bRotating=true;
	OnOccupantMotionBegin.Broadcast(this,true);
	return true;
}

bool UOmegaGrid3D_Occupant::IsMovingOrRotating(bool& Moving, bool& Rotating)
{
	Moving=bMoving;
	Rotating=bRotating;
	return bMoving || bRotating;
}


bool UOmegaGrid3D_Occupant::SnapToNearestTile()
{
	AActor* owner=GetOwner();
	if(!owner)
	{
		UE_LOG(LogTemp,Warning,TEXT("[Grid3D] SnapToNearestTile failed: occupant has no owner actor."));
		return false;
	}
	UOmegaSubsystem_Grid3D* subsystem=GetWorld()->GetSubsystem<UOmegaSubsystem_Grid3D>();
	if(!subsystem || subsystem->REF_Tilemaps.IsEmpty())
	{
		UE_LOG(LogTemp,Warning,TEXT("[Grid3D] SnapToNearestTile failed on '%s': no gridmaps are registered. (Has tile generation run yet?)"),*owner->GetName());
		return false;
	}

	const FVector owner_loc=owner->GetActorLocation();
	AOmegaGrid3D_Tile* nearest_tile=nullptr;
	float nearest_dist=0.f;
	int32 tile_count=0;
	for(UOmegaGrid3D_Map* map : subsystem->REF_Tilemaps)
	{
		if(!map) { continue; }
		for(AOmegaGrid3D_Tile* tile : map->GetTiles())
		{
			if(!tile) { continue; }
			tile_count++;
			const float dist=FVector::Dist(owner_loc,tile->GetActorLocation());
			if(!nearest_tile || dist<nearest_dist)
			{
				nearest_tile=tile;
				nearest_dist=dist;
			}
		}
	}

	if(!nearest_tile)
	{
		UE_LOG(LogTemp,Warning,TEXT("[Grid3D] SnapToNearestTile failed on '%s': registered gridmaps contain no tiles. (Tile generation may not be complete.)"),*owner->GetName());
		return false;
	}
	if(nearest_dist>AutoSnapDistance)
	{
		UE_LOG(LogTemp,Warning,TEXT("[Grid3D] SnapToNearestTile failed on '%s': nearest of %d tiles ('%s') is %.1f away, beyond AutoSnapDistance %.1f."),
			*owner->GetName(),tile_count,*nearest_tile->GetName(),nearest_dist,AutoSnapDistance);
		return false;
	}
	SetTile(nearest_tile,true,true);
	return true;
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

AOmegaGrid3D_Tile* UOmegaGrid3D_Occupant::GetTileAtOffset(FIntVector Offset, bool RotationRelative)
{
	AOmegaGrid3D_Tile* current_tile=GetTile();
	if(!current_tile || !current_tile->GetOwningGridmap())
	{
		return nullptr;
	}
	FIntVector dir=Offset;
	if(RotationRelative && GetOwner())
	{
		const FVector rotated=GetOwner()->GetActorRotation().RotateVector(FVector(Offset.X,Offset.Y,Offset.Z));
		dir=FIntVector(FMath::RoundToInt(rotated.X),FMath::RoundToInt(rotated.Y),FMath::RoundToInt(rotated.Z));
	}
	return current_tile->GetOwningGridmap()->GetTileFromCoordinate(current_tile->GetTileCoordinate()+dir);
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
// Tile
// =====================================================================================================


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

TMap<FGameplayTag, USceneComponent*> AOmegaGrid3D_Tile::LinkTileTagVisibilityComponents_Implementation()
{
	return TMap<FGameplayTag, USceneComponent*>();
}



USceneComponent* AOmegaGrid3D_Tile::L_GetTagVisComp(FGameplayTag Tag)
{
	TMap<FGameplayTag, USceneComponent*> links=LinkTileTagVisibilityComponents();
	if(links.Contains(Tag))
	{
		return links[Tag];
	}
	return nullptr;
}


void AOmegaGrid3D_Tile::Tag_SetActive(FGameplayTagContainer Tile_Tags, bool bActive)
{
	for (FGameplayTag Tag : Tile_Tags)
	{
		if (Tag.IsValid())
		{
			if (!TileTags.HasTagExact(Tag) && bActive)
			{
				TileTags.AddTag(Tag);
				if (USceneComponent* c=L_GetTagVisComp(Tag))
				{
					c->SetHiddenInGame(false);
				}
				OnTileTagChanged.Broadcast(this,Tag,true);
			}
			else if (TileTags.HasTagExact(Tag) && !bActive)
			{
				TileTags.RemoveTag(Tag);
				if (USceneComponent* c=L_GetTagVisComp(Tag))
				{
					c->SetHiddenInGame(true);
				}
				OnTileTagChanged.Broadcast(this,Tag,true);
			}
		}
	}
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

FOmegaGrid3DPathfindResult UOmegaGrid3DFunctions::Pathfind3D_AllPossiblePaths(const FIntVector& StartPoint,
	int32 MaxDistance, FGrid3DPathfindQuery Query, FOmegaGrid3DPathfindMeta metadata, bool x, bool y, bool z)
{
	FOmegaGrid3DPathfindResult out;

	TArray<FIntVector> directions;
	if(x) { directions.Add(FIntVector(1,0,0)); directions.Add(FIntVector(-1,0,0)); }
	if(y) { directions.Add(FIntVector(0,1,0)); directions.Add(FIntVector(0,-1,0)); }
	if(z) { directions.Add(FIntVector(0,0,1)); directions.Add(FIntVector(0,0,-1)); }

	// Breadth-first flood from the start point. Each visited coordinate stores the shortest path
	// used to reach it. Per the query result: BlockTrace stops expansion beyond a coordinate,
	// BlockAdd keeps it out of the returned destinations (but traces may still pass through it).
	TMap<FIntVector,FOmegaGrid3DPath> visited;
	TSet<FIntVector> blocked_add;
	FOmegaGrid3DPath start_path;
	start_path.PathPoints.Add(StartPoint);
	start_path.distance=0;
	visited.Add(StartPoint,start_path);

	TArray<FIntVector> frontier;
	frontier.Add(StartPoint);

	while(!frontier.IsEmpty())
	{
		TArray<FIntVector> next_frontier;
		for(const FIntVector& current : frontier)
		{
			const FOmegaGrid3DPath current_path=visited[current];
			if(current_path.distance>=MaxDistance)
			{
				continue;
			}
			for(const FIntVector& dir : directions)
			{
				const FIntVector next=current+dir;
				if(visited.Contains(next))
				{
					continue;
				}
				FOmegaGrid3DPathfindQueryResult query_result;
				if(Query.IsBound())
				{
					query_result=Query.Execute(next,metadata);
				}
				if(query_result.BlockTrace && query_result.BlockAdd)
				{
					continue;
				}
				FOmegaGrid3DPath next_path=current_path;
				next_path.PathPoints.Add(next);
				next_path.distance=current_path.distance+1;
				visited.Add(next,next_path);
				if(query_result.BlockAdd)
				{
					blocked_add.Add(next);
				}
				if(!query_result.BlockTrace)
				{
					next_frontier.Add(next);
				}
			}
		}
		frontier=next_frontier;
	}

	for(const TPair<FIntVector,FOmegaGrid3DPath>& pair : visited)
	{
		if(pair.Key!=StartPoint && !blocked_add.Contains(pair.Key))
		{
			out.paths.Add(pair.Value);
		}
	}
	return out;
}

TArray<FIntVector> UOmegaGrid3DFunctions::GetCoordinatesFromPathfindResult(FOmegaGrid3DPathfindResult in, bool bOnlyLastPoints)
{
	TArray<FIntVector> out;
	for(FOmegaGrid3DPath path : in.paths)
	{
		if(bOnlyLastPoints)
		{
			if(!path.PathPoints.IsEmpty()) { out.AddUnique(path.PathPoints.Last()); }
		}
		else
		{
			for(FIntVector vec : path.PathPoints)
			{
				out.AddUnique(vec);
			}
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
			if(bOnlyLast)
			{
				// Resolve the tile of the path's final point specifically; if that coordinate
				// has no tile, the path has no valid end tile and is skipped entirely.
				if(!p.PathPoints.IsEmpty())
				{
					if(AOmegaGrid3D_Tile* _tile=Tilemap->GetTileFromCoordinate(p.PathPoints.Last()))
					{
						out.AddUnique(_tile);
					}
				}
			}
			else
			{
				out.Append(GetTilesFromPath(Tilemap,p));
			}
		}
	}
	return out;
}


FOmegaGrid3DPath UOmegaGrid3DFunctions::GetShortestPath_ToCoordinate(FOmegaGrid3DPathfindResult pathfind,
                                                                     FIntVector coord, bool& result)
{
	result=false;
	FOmegaGrid3DPath out=FOmegaGrid3DPath();

	for(const FOmegaGrid3DPath& p : pathfind.paths)
	{
		if(!p.PathPoints.IsEmpty() && p.PathPoints.Last()==coord)
		{
			if(!result || p.PathPoints.Num()<out.PathPoints.Num())
			{
				out=p;
			}
			result=true;
		}
	}
	if(result)
	{
		return out;
	}
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
