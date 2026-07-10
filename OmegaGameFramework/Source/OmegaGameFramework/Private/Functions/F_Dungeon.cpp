// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Dungeon.h"

#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Engine/Brush.h"
#include "Engine/Level.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/World.h"
#include "GameFramework/Info.h"

// ===================================================================================================================
// Actor - Dungeon
// ===================================================================================================================

AOmegaDungeon::AOmegaDungeon()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void AOmegaDungeon::BeginPlay()
{
	Super::BeginPlay();
	if(bGenerateOnBeginPlay && Model.GetObject())
	{
		GenerateDungeon();
	}
}

void AOmegaDungeon::SetModel(TScriptInterface<IDataInterface_DungeonModel> InModel, bool bRegenerate)
{
	Model = InModel;
	if(bRegenerate)
	{
		GenerateDungeon();
	}
}

void AOmegaDungeon::RandomizeSeed()
{
	Seed = FMath::Rand();
}

void AOmegaDungeon::GenerateDungeon()
{
	DestroyDungeon();

	RandomStream.Initialize(Seed);
	OnDungeonGeneration_Begin.Broadcast(this);

	if(UObject* ModelObject = Model.GetObject())
	{
		IDataInterface_DungeonModel::Execute_Dungeon_GenerateBegin(ModelObject, this);
		IDataInterface_DungeonModel::Execute_Dungeon_GenerateLayout(ModelObject, this);

		// Iterate a copy of the coords so models can safely add/remove cells while processing.
		TArray<FIntVector> Coords = GetCellCoords();
		for(const FIntVector& Coord : Coords)
		{
			if(const FOmegaDungeonCellData* Cell = CellData.Find(Coord))
			{
				IDataInterface_DungeonModel::Execute_Dungeon_ProcessCell(ModelObject, this, Coord, *Cell);
			}
		}
	}

	// Module levels stream in asynchronously; the rest of generation (open sockets, GenerateEnd, Finish)
	// runs in FinalizeGeneration once they are all loaded.
	bFinalizePending = true;
	if(PendingLevels.Num() == 0)
	{
		FinalizeGeneration();
	}
}

void AOmegaDungeon::FinalizeGeneration()
{
	if(!bFinalizePending) { return; }
	bFinalizePending = false;

	if(UObject* ModelObject = Model.GetObject())
	{
		// NOTE: processing an open socket may spawn more module levels (e.g. walls). Those stream in after
		// this pass and still get their markers processed, but do not trigger another socket pass.
		for(AOmegaDungeon_Socket* TempSocket : GetOpenSockets(SocketConnectDistance))
		{
			IDataInterface_DungeonModel::Execute_Dungeon_ProcessOpenSocket(ModelObject, this, TempSocket);
		}
		IDataInterface_DungeonModel::Execute_Dungeon_GenerateEnd(ModelObject, this);
	}

	OnDungeonGeneration_Finish.Broadcast(this);
}

void AOmegaDungeon::DestroyDungeon()
{
	OnDungeonDestroy_Begin.Broadcast(this);

	for(AActor* TempActor : GeneratedActors)
	{
		if(IsValid(TempActor)) { TempActor->Destroy(); }
	}
	GeneratedActors.Empty();

	for(UActorComponent* TempComp : GeneratedComponents)
	{
		if(IsValid(TempComp)) { TempComp->DestroyComponent(); }
	}
	GeneratedComponents.Empty();

	for(ULevelStreamingDynamic* TempLevel : GeneratedLevels)
	{
		if(IsValid(TempLevel))
		{
			TempLevel->OnLevelShown.RemoveAll(this);
			TempLevel->SetShouldBeVisible(false);
			TempLevel->SetShouldBeLoaded(false);
			TempLevel->SetIsRequestingUnloadAndRemoval(true);
		}
	}
	GeneratedLevels.Empty();
	PendingLevels.Empty();
	bFinalizePending = false;
	ModuleSpawnCounter = 0;

	CellData.Empty();
	MarkerSpawnCounts.Empty();

#if WITH_EDITOR
	// In the editor, finish the unload NOW. Unloaded module packages linger until the next garbage
	// collection, and while alive their linkers hold an OS file handle on the source .umap files —
	// which makes saving those module maps fail with a sharing violation (Error Code 32).
	if(GIsEditor && GetWorld() && !GetWorld()->IsGameWorld())
	{
		GetWorld()->FlushLevelStreaming(EFlushLevelStreamingType::Full);
		CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
	}
#endif

	OnDungeonDestroy_End.Broadcast(this);
}

// --- Cells --------------------------------------------------------------------------------------------------------

void AOmegaDungeon::SetCell(FIntVector Coord, FOmegaDungeonCellData Cell)
{
	CellData.Add(Coord, Cell);
}

bool AOmegaDungeon::RemoveCell(FIntVector Coord)
{
	return CellData.Remove(Coord) > 0;
}

bool AOmegaDungeon::GetCell(FIntVector Coord, FOmegaDungeonCellData& OutCell) const
{
	if(const FOmegaDungeonCellData* Found = CellData.Find(Coord))
	{
		OutCell = *Found;
		return true;
	}
	return false;
}

bool AOmegaDungeon::HasCell(FIntVector Coord) const
{
	return CellData.Contains(Coord);
}

TArray<FIntVector> AOmegaDungeon::GetCellCoords() const
{
	TArray<FIntVector> Coords;
	CellData.GetKeys(Coords);
	return Coords;
}

bool AOmegaDungeon::IsCoordInBounds(FIntVector Coord) const
{
	return Coord.X >= 0 && Coord.X < Size.X
		&& Coord.Y >= 0 && Coord.Y < Size.Y
		&& Coord.Z >= 0 && Coord.Z < Size.Z;
}

FTransform AOmegaDungeon::GetCellTransform(FIntVector Coord, FVector CellSize) const
{
	const FVector LocalLocation = FVector(Coord.X * CellSize.X, Coord.Y * CellSize.Y, Coord.Z * CellSize.Z);
	return FTransform(LocalLocation) * GetActorTransform();
}

// --- Sockets --------------------------------------------------------------------------------------------------------

TArray<AOmegaDungeon_Socket*> AOmegaDungeon::GetAllSockets() const
{
	TArray<AOmegaDungeon_Socket*> Sockets;
	for(ULevelStreamingDynamic* TempLevel : GeneratedLevels)
	{
		// Only visible levels: transforms aren't applied until the level is added to the world.
		if(!IsValid(TempLevel) || !TempLevel->IsLevelVisible() || !TempLevel->GetLoadedLevel()) { continue; }
		for(AActor* TempActor : TempLevel->GetLoadedLevel()->Actors)
		{
			if(AOmegaDungeon_Socket* Socket = Cast<AOmegaDungeon_Socket>(TempActor))
			{
				Sockets.Add(Socket);
			}
		}
	}
	// Editor-world modules are duplicated as plain actors rather than streamed levels.
	for(AActor* TempActor : GeneratedActors)
	{
		if(AOmegaDungeon_Socket* Socket = Cast<AOmegaDungeon_Socket>(TempActor))
		{
			Sockets.Add(Socket);
		}
	}
	return Sockets;
}

TArray<AOmegaDungeon_Socket*> AOmegaDungeon::GetOpenSockets(float ConnectDistance) const
{
	const TArray<AOmegaDungeon_Socket*> AllSockets = GetAllSockets();
	const float DistSquared = ConnectDistance * ConnectDistance;

	TArray<AOmegaDungeon_Socket*> OpenSockets;
	for(AOmegaDungeon_Socket* Socket : AllSockets)
	{
		bool bConnected = false;
		for(AOmegaDungeon_Socket* Other : AllSockets)
		{
			// A connection requires a compatible socket from a DIFFERENT module at (roughly) the same spot.
			if(Other == Socket || Socket->IsFromSameModule(Other)) { continue; }
			if(FVector::DistSquared(Socket->GetActorLocation(), Other->GetActorLocation()) <= DistSquared
				&& Socket->CanConnectTo(Other))
			{
				bConnected = true;
				break;
			}
		}
		if(!bConnected)
		{
			OpenSockets.Add(Socket);
		}
	}
	return OpenSockets;
}

// --- Seeded Random --------------------------------------------------------------------------------------------------

float AOmegaDungeon::GetRandomFloat()
{
	return RandomStream.FRand();
}

int32 AOmegaDungeon::GetRandomIntInRange(int32 Min, int32 Max)
{
	return RandomStream.RandRange(Min, Max);
}

int32 AOmegaDungeon::GetRandomWeightedIndex(const TArray<float>& Weights)
{
	return UOmegaFunctions_Dungeon::GetWeightedRandomIndex(Weights, RandomStream);
}

// --- Spawning -------------------------------------------------------------------------------------------------------

ULevelStreamingDynamic* AOmegaDungeon::SpawnLevelModule(TSoftObjectPtr<UWorld> Module, FTransform Transform)
{
	if(Module.IsNull() || !GetWorld()) { return nullptr; }

	const int32 ModuleID = ModuleSpawnCounter++;

#if WITH_EDITOR
	// Editor (non-PIE) worlds don't support the full streaming-level lifecycle: "unloaded" module
	// packages linger and keep an OS file handle on the source .umap, blocking saves of the module maps.
	// So in-editor the module's actors are duplicated directly into the world instead of streamed.
	if(GIsEditor && !GetWorld()->IsGameWorld())
	{
		if(UWorld* ModuleWorld = Module.LoadSynchronous())
		{
			SpawnLevelModule_Editor(ModuleWorld, Transform, ModuleID);
		}
		return nullptr;
	}
#endif

	bool bSuccess = false;
	// bLoadAsTempPackage: instance under a unique /Temp package name so the source module map is never
	// registered as loaded — otherwise editing/saving a module asset fails while (or after) a dungeon
	// generated from it exists in the editor session.
	ULevelStreamingDynamic* NewLevel = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(
		this, Module, Transform.GetLocation(), Transform.Rotator(), bSuccess,
		FString(), nullptr, /*bLoadAsTempPackage*/ true);

	if(bSuccess && NewLevel)
	{
		GeneratedLevels.Add(NewLevel);
		PendingLevels.Add(NewLevel);
		NewLevel->OnLevelShown.AddUniqueDynamic(this, &AOmegaDungeon::HandleModuleLevelShown);
		return NewLevel;
	}
	return nullptr;
}

#if WITH_EDITOR
void AOmegaDungeon::SpawnLevelModule_Editor(UWorld* ModuleWorld, const FTransform& Transform, int32 ModuleID)
{
	if(!ModuleWorld || !ModuleWorld->PersistentLevel) { return; }

	for(AActor* SourceActor : ModuleWorld->PersistentLevel->Actors)
	{
		// Skip level plumbing: world settings/info actors, brushes, the level blueprint, editor-only actors.
		if(!IsValid(SourceActor) || SourceActor->IsEditorOnly()
			|| SourceActor->IsA<AInfo>() || SourceActor->IsA<ABrush>() || SourceActor->IsA<ALevelScriptActor>())
		{
			continue;
		}

		FActorSpawnParameters SpawnParams;
		SpawnParams.Template = SourceActor;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Owner = this;
		SpawnParams.ObjectFlags |= RF_Transient;

		AActor* NewActor = GetWorld()->SpawnActor<AActor>(SourceActor->GetClass(), SpawnParams);
		if(!NewActor) { continue; }

		NewActor->SetActorTransform(SourceActor->GetActorTransform() * Transform);
		RegisterGeneratedActor(NewActor);

		if(AOmegaDungeon_Socket* Socket = Cast<AOmegaDungeon_Socket>(NewActor))
		{
			Socket->GeneratedModuleID = ModuleID;
		}
		else if(AOmegaDungeon_Marker* Marker = Cast<AOmegaDungeon_Marker>(NewActor))
		{
			ProcessMarker(Marker);
		}
	}
}
#endif

AActor* AOmegaDungeon::SpawnDungeonActor(TSubclassOf<AActor> Class, FTransform Transform)
{
	if(!Class || !GetWorld()) { return nullptr; }

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;
	// Generated content should never be saved into the map (matters when generating in-editor).
	SpawnParams.ObjectFlags |= RF_Transient;

	if(AActor* NewActor = GetWorld()->SpawnActor<AActor>(Class, Transform, SpawnParams))
	{
		RegisterGeneratedActor(NewActor);
		return NewActor;
	}
	return nullptr;
}

void AOmegaDungeon::RegisterGeneratedActor(AActor* Actor)
{
	if(Actor) { GeneratedActors.AddUnique(Actor); }
}

void AOmegaDungeon::RegisterGeneratedComponent(UActorComponent* Component)
{
	if(Component) { GeneratedComponents.AddUnique(Component); }
}

// --- Markers --------------------------------------------------------------------------------------------------------

void AOmegaDungeon::HandleModuleLevelShown()
{
	// OnLevelShown carries no payload, so sweep all pending levels for any that finished streaming in.
	TArray<TWeakObjectPtr<ULevelStreamingDynamic>> Pending = PendingLevels.Array();
	for(const TWeakObjectPtr<ULevelStreamingDynamic>& WeakLevel : Pending)
	{
		ULevelStreamingDynamic* Level = WeakLevel.Get();
		if(!Level)
		{
			PendingLevels.Remove(WeakLevel);
			continue;
		}
		// A level counts as ready only once VISIBLE (added to the world), not merely loaded — the level's
		// transform is applied on add, so actors of loaded-but-not-shown levels are still at their
		// authoring-time positions and would break socket matching and marker spawn locations.
		if(Level->IsLevelVisible() && Level->GetLoadedLevel())
		{
			PendingLevels.Remove(WeakLevel);
			ProcessMarkersInLevel(Level->GetLoadedLevel());
		}
	}

	if(bFinalizePending && PendingLevels.Num() == 0)
	{
		FinalizeGeneration();
	}
}

void AOmegaDungeon::ProcessMarker(AOmegaDungeon_Marker* Marker)
{
	if(!Marker || !Marker->Preset || !Marker->Preset->SpawnClass) { return; }

	UOmegaDungeon_MarkerPreset* Preset = Marker->Preset;
	int32& Count = MarkerSpawnCounts.FindOrAdd(Preset);

	bool bSpawn;
	if(Preset->MaxSpawnable > 0 && Count >= Preset->MaxSpawnable)
	{
		bSpawn = false;
	}
	else if(Count < Preset->MinSpawnable)
	{
		bSpawn = true;
	}
	else
	{
		bSpawn = RandomStream.FRand() <= (Marker->SpawnChance * Preset->SpawnChance);
	}

	if(bSpawn)
	{
		const FTransform SpawnTransform = Preset->SpawnOffset * Marker->GetActorTransform();
		if(SpawnDungeonActor(Preset->SpawnClass, SpawnTransform))
		{
			Count++;
		}
	}
}

void AOmegaDungeon::ProcessMarkersInLevel(ULevel* Level)
{
	if(!Level) { return; }

	for(AActor* TempActor : Level->Actors)
	{
		ProcessMarker(Cast<AOmegaDungeon_Marker>(TempActor));
	}
}

// ===================================================================================================================
// Actor - Socket
// ===================================================================================================================

AOmegaDungeon_Socket::AOmegaDungeon_Socket()
{
	PrimaryActorTick.bCanEverTick = false;

	ReferenceBillboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	RootComponent = ReferenceBillboard;

	ReferenceArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ReferenceArrow->SetupAttachment(RootComponent);
}

bool AOmegaDungeon_Socket::CanConnectTo(const AOmegaDungeon_Socket* Other) const
{
	if(!Other) { return false; }
	// Both sides must accept the other's tag. An empty AcceptedSockets list accepts anything; matching is
	// hierarchical, so accepting "Socket.Door" also accepts "Socket.Door.Locked".
	const bool bThisAccepts = AcceptedSockets.IsEmpty() || AcceptedSockets.HasTag(Other->SocketTag);
	const bool bOtherAccepts = Other->AcceptedSockets.IsEmpty() || Other->AcceptedSockets.HasTag(SocketTag);
	return bThisAccepts && bOtherAccepts;
}

bool AOmegaDungeon_Socket::IsFromSameModule(const AOmegaDungeon_Socket* Other) const
{
	if(!Other) { return false; }
	if(GeneratedModuleID >= 0 || Other->GeneratedModuleID >= 0)
	{
		return GeneratedModuleID == Other->GeneratedModuleID;
	}
	// Streamed module levels each get their own ULevel.
	return GetLevel() == Other->GetLevel();
}

// ===================================================================================================================
// Actor - Marker
// ===================================================================================================================

AOmegaDungeon_Marker::AOmegaDungeon_Marker()
{
	PrimaryActorTick.bCanEverTick = false;

	ReferenceBillboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	RootComponent = ReferenceBillboard;

	ReferenceArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ReferenceArrow->SetupAttachment(RootComponent);
}

void AOmegaDungeon_Marker::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(Preset)
	{
		if(ReferenceBillboard && Preset->BillboardIcon)
		{
			ReferenceBillboard->SetSprite(Preset->BillboardIcon);
		}
		if(ReferenceArrow)
		{
			ReferenceArrow->SetArrowColor(Preset->ArrowColor);
		}
	}
}

// ===================================================================================================================
// Function Library
// ===================================================================================================================

int32 UOmegaFunctions_Dungeon::GetWeightedRandomIndex(const TArray<float>& Weights, const FRandomStream& Stream)
{
	float TotalWeight = 0.f;
	for(const float Weight : Weights)
	{
		TotalWeight += FMath::Max(Weight, 0.f);
	}
	if(TotalWeight <= 0.f) { return INDEX_NONE; }

	float Roll = Stream.FRand() * TotalWeight;
	for(int32 i = 0; i < Weights.Num(); i++)
	{
		const float Weight = FMath::Max(Weights[i], 0.f);
		if(Weight <= 0.f) { continue; }
		Roll -= Weight;
		if(Roll <= 0.f) { return i; }
	}
	return Weights.Num() - 1;
}

TArray<AOmegaDungeon_Marker*> UOmegaFunctions_Dungeon::GetMarkersInLevel(ULevelStreamingDynamic* Level)
{
	TArray<AOmegaDungeon_Marker*> Markers;
	if(Level && Level->GetLoadedLevel())
	{
		for(AActor* TempActor : Level->GetLoadedLevel()->Actors)
		{
			if(AOmegaDungeon_Marker* Marker = Cast<AOmegaDungeon_Marker>(TempActor))
			{
				Markers.Add(Marker);
			}
		}
	}
	return Markers;
}
