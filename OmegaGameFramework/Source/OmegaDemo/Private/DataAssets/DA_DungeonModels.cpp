// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_DungeonModels.h"

#include "Engine/Level.h"
#include "Engine/World.h"

namespace
{
	// 4 horizontal neighbor directions for the random walk.
	const FIntVector GPathDirs[4] = {
		FIntVector( 1, 0, 0),
		FIntVector( 0, 1, 0),
		FIntVector(-1, 0, 0),
		FIntVector( 0,-1, 0),
	};

	// Mirror of AOmegaDungeon_Socket::CanConnectTo on cached socket data: both sides must accept the
	// other's tag (empty Accepted = accepts anything; matching is hierarchical).
	bool SocketsCompatible(const FOmegaDngMdl_SocketInfo& A, const FOmegaDngMdl_SocketInfo& B)
	{
		const bool bAAccepts = A.Accepted.IsEmpty() || A.Accepted.HasTag(B.Tag);
		const bool bBAccepts = B.Accepted.IsEmpty() || B.Accepted.HasTag(A.Tag);
		return bAAccepts && bBAccepts;
	}

	// All 90° rotation steps of a module that put a socket on every required side AND are tag-compatible
	// with the given placed-neighbor constraints (4 entries or empty; null = unconstrained direction).
	// A module with no authored sockets has nothing to verify — every rotation is valid.
	TArray<int32> GetValidRotations(const FOmegaDngMdl_ModuleSockets& Data, int32 RequiredMask,
		const TArray<const FOmegaDngMdl_SocketInfo*>& Constraints)
	{
		if(Data.GetDirMask() == 0)
		{
			return TArray<int32>({0,1,2,3});
		}
		TArray<int32> Valid;
		for(int32 Step = 0; Step < 4; Step++)
		{
			bool bValid = true;
			for(int32 DirIndex = 0; DirIndex < 4 && bValid; DirIndex++)
			{
				// World direction DirIndex is served by authored direction (DirIndex - Step).
				const FOmegaDngMdl_SocketInfo& Info = Data.Dirs[(DirIndex - Step + 4) % 4];
				if((RequiredMask & (1 << DirIndex)) && !Info.bHasSocket)
				{
					bValid = false;
				}
				else if(Info.bHasSocket && Constraints.IsValidIndex(DirIndex) && Constraints[DirIndex]
					&& !SocketsCompatible(Info, *Constraints[DirIndex]))
				{
					bValid = false;
				}
			}
			if(bValid) { Valid.Add(Step); }
		}
		return Valid;
	}

	// Can some 90° rotation of SocketMask put a socket on every required side? (Mask 0 = module has no
	// authored sockets — nothing to verify, treat as fitting.)
	bool CanCoverRequiredDirs(int32 SocketMask, int32 RequiredMask)
	{
		if(SocketMask == 0 || RequiredMask == 0) { return true; }
		for(int32 Step = 0; Step < 4; Step++)
		{
			const int32 RotatedMask = ((SocketMask << Step) | (SocketMask >> (4 - Step))) & 0xF;
			if((RequiredMask & ~RotatedMask) == 0) { return true; }
		}
		return false;
	}

	FOmegaDungeonCellData MakeCell(EOmegaDngPathCellType Type)
	{
		FOmegaDungeonCellData Cell;
		Cell.type = static_cast<int32>(Type);
		return Cell;
	}

	// One random-walk step: returns a random in-bounds, unused neighbor of Current, or false if boxed in.
	bool GetRandomFreeNeighbor(AOmegaDungeon* Dungeon, const TSet<FIntVector>& Used, const FIntVector& Current, FIntVector& OutNext)
	{
		int32 Order[4] = {0,1,2,3};
		for(int32 i = 3; i > 0; i--)
		{
			const int32 j = Dungeon->GetRandomIntInRange(0, i);
			Swap(Order[i], Order[j]);
		}
		for(const int32 DirIndex : Order)
		{
			const FIntVector Next = Current + GPathDirs[DirIndex];
			if(Dungeon->IsCoordInBounds(Next) && !Used.Contains(Next))
			{
				OutNext = Next;
				return true;
			}
		}
		return false;
	}
}

void UOmegaDungeonModel_Path::Dungeon_GenerateBegin_Implementation(AOmegaDungeon* Dungeon)
{
	ModuleUseCounts.Reset();
	ModuleSocketDataCache.Reset();
	CellConnectionMasks.Reset();
	PlacedCellSockets.Reset();
}

void UOmegaDungeonModel_Path::AddCellConnection(const FIntVector& CellA, const FIntVector& CellB)
{
	const FIntVector Delta = CellB - CellA;
	for(int32 DirIndex = 0; DirIndex < 4; DirIndex++)
	{
		if(GPathDirs[DirIndex] == Delta)
		{
			CellConnectionMasks.FindOrAdd(CellA) |= 1 << DirIndex;
			CellConnectionMasks.FindOrAdd(CellB) |= 1 << ((DirIndex + 2) % 4); // opposite direction
			return;
		}
	}
}

int32 UOmegaDungeonModel_Path::GetConnectionCount(const FIntVector& Cell) const
{
	return FMath::CountBits(CellConnectionMasks.FindRef(Cell));
}

const TArray<FOmegaDngMdl_Path_Module>& UOmegaDungeonModel_Path::GetModuleList(EOmegaDngPathCellType Type) const
{
	switch(Type)
	{
		case EOmegaDngPathCellType::Start:
			if(Modules_Start.Num() > 0) { return Modules_Start; }
			break;
		case EOmegaDngPathCellType::End:
			if(Modules_End.Num() > 0) { return Modules_End; }
			break;
		case EOmegaDngPathCellType::LeafEnd:
			if(Modules_LeafEnd.Num() > 0) { return Modules_LeafEnd; }
			if(Modules_End.Num() > 0) { return Modules_End; }
			break;
		default:
			break;
	}
	return Modules_Path;
}

bool UOmegaDungeonModel_Path::CanListCoverMask(const TArray<FOmegaDngMdl_Path_Module>& List, int32 RequiredMask)
{
	for(const FOmegaDngMdl_Path_Module& TempModule : List)
	{
		if(!TempModule.Module.IsNull() && CanCoverRequiredDirs(GetModuleSocketData(TempModule.Module).GetDirMask(), RequiredMask))
		{
			return true;
		}
	}
	return false;
}

void UOmegaDungeonModel_Path::Dungeon_GenerateLayout_Implementation(AOmegaDungeon* Dungeon)
{
	const int32 TargetLength = FMath::Max(2, Dungeon->GetRandomIntInRange(MainPathLength_Min, MainPathLength_Max));

	// --- Main path: self-avoiding random walk, retried if it dead-ends too early --------------------------------
	TArray<FIntVector> MainPath;
	TSet<FIntVector> Used;
	const int32 MaxAttempts = 20;
	for(int32 Attempt = 0; Attempt < MaxAttempts; Attempt++)
	{
		MainPath.Reset();
		Used.Reset();

		FIntVector Current = FIntVector(Dungeon->Size.X / 2, Dungeon->Size.Y / 2, 0);
		MainPath.Add(Current);
		Used.Add(Current);

		while(MainPath.Num() < TargetLength)
		{
			FIntVector Next;
			if(!GetRandomFreeNeighbor(Dungeon, Used, Current, Next)) { break; }
			Current = Next;
			MainPath.Add(Current);
			Used.Add(Current);
		}

		if(MainPath.Num() >= FMath::Max(2, FMath::Min(MainPathLength_Min, TargetLength))) { break; }
	}

	if(MainPath.Num() < 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("[DungeonModel_Path] Could not fit a main path inside dungeon Size %s"), *Dungeon->Size.ToString());
		return;
	}

	// The walk starts at the grid center (for room to grow), but cells are written shifted so the
	// Start cell is coord (0,0,0) — placing it at the dungeon actor's world origin.
	const FIntVector Shift = FIntVector::ZeroValue - MainPath[0];

	for(int32 i = 0; i < MainPath.Num(); i++)
	{
		EOmegaDngPathCellType Type = EOmegaDngPathCellType::Path;
		if(i == 0) { Type = EOmegaDngPathCellType::Start; }
		else if(i == MainPath.Num() - 1) { Type = EOmegaDngPathCellType::End; }
		Dungeon->SetCell(MainPath[i] + Shift, MakeCell(Type));
	}
	for(int32 i = 0; i < MainPath.Num() - 1; i++)
	{
		AddCellConnection(MainPath[i] + Shift, MainPath[i + 1] + Shift);
	}

	// Middle path cells inherently need 2 connections (in + out), so the cap can't go below that.
	const int32 MaxConnections = FMath::Max(2, MaxModuleSocketConnections);

	// --- Leaf paths ----------------------------------------------------------------------------------------------
	if(LeafPaths.Num() > 0)
	{
		const int32 LeafCount = FMath::Max(0, Dungeon->GetRandomIntInRange(LeafPaths_Min, LeafPaths_Max));
		for(int32 LeafIndex = 0; LeafIndex < LeafCount; LeafIndex++)
		{
			TArray<float> LeafWeights;
			for(const FOmegaDngMdl_Path_LeafData& TempLeaf : LeafPaths) { LeafWeights.Add(TempLeaf.Weight); }
			const int32 PickedLeaf = Dungeon->GetRandomWeightedIndex(LeafWeights);
			if(PickedLeaf == INDEX_NONE) { break; }
			const FOmegaDngMdl_Path_LeafData& LeafData = LeafPaths[PickedLeaf];

			const int32 LeafLength = FMath::Max(1, Dungeon->GetRandomIntInRange(LeafData.Min, LeafData.Max));

			// Find a main-path cell to branch from. Leaf connections are structural (exempt from
			// MaxModuleSocketConnections), but the origin's module list must contain a module whose
			// sockets can cover its connections PLUS the new branch — otherwise e.g. a leaf could sprout
			// from a 1-socket End module's solid wall and be unreachable.
			FIntVector OriginCell = FIntVector::ZeroValue;
			FIntVector FirstCell = FIntVector::ZeroValue;
			bool bFoundOrigin = false;
			for(int32 Attempt = 0; Attempt < 10 && !bFoundOrigin; Attempt++)
			{
				const int32 OriginIndex = Dungeon->GetRandomIntInRange(0, MainPath.Num() - 1);
				const FIntVector Origin = MainPath[OriginIndex];

				EOmegaDngPathCellType OriginType = EOmegaDngPathCellType::Path;
				if(OriginIndex == 0) { OriginType = EOmegaDngPathCellType::Start; }
				else if(OriginIndex == MainPath.Num() - 1) { OriginType = EOmegaDngPathCellType::End; }

				int32 Order[4] = {0,1,2,3};
				for(int32 i = 3; i > 0; i--)
				{
					const int32 j = Dungeon->GetRandomIntInRange(0, i);
					Swap(Order[i], Order[j]);
				}
				for(const int32 DirIndex : Order)
				{
					const FIntVector Next = Origin + GPathDirs[DirIndex];
					if(!Dungeon->IsCoordInBounds(Next) || Used.Contains(Next)) { continue; }
					const int32 NewOriginMask = CellConnectionMasks.FindRef(Origin + Shift) | (1 << DirIndex);
					if(!CanListCoverMask(GetModuleList(OriginType), NewOriginMask)) { continue; }
					OriginCell = Origin;
					FirstCell = Next;
					bFoundOrigin = true;
					break;
				}
			}
			if(!bFoundOrigin) { continue; }

			TArray<FIntVector> LeafCells;
			LeafCells.Add(FirstCell);
			Used.Add(FirstCell);
			FIntVector Current = FirstCell;
			for(int32 Step = 1; Step < LeafLength; Step++)
			{
				FIntVector Next;
				if(!GetRandomFreeNeighbor(Dungeon, Used, Current, Next)) { break; }
				Current = Next;
				LeafCells.Add(Current);
				Used.Add(Current);
			}

			FIntVector PrevCell = OriginCell;
			for(const FIntVector& LeafCell : LeafCells)
			{
				Dungeon->SetCell(LeafCell + Shift, MakeCell(EOmegaDngPathCellType::LeafPath));
				AddCellConnection(PrevCell + Shift, LeafCell + Shift);
				PrevCell = LeafCell;
			}

			// The leaf either reconnects to the main path or ends in a LeafEnd cell. As a leaf connection,
			// the connect-back is exempt from MaxModuleSocketConnections — but both cells' module lists
			// must be able to realize the extra connection, or the doorway would be sealed by geometry.
			bool bConnectsBack = false;
			if(Dungeon->GetRandomFloat() < LeafData.ConnectToMainWeight)
			{
				const FIntVector LastCell = LeafCells.Last();
				const FIntVector BeforeLast = LeafCells.Num() > 1 ? LeafCells[LeafCells.Num() - 2] : OriginCell;
				for(int32 DirIndex = 0; DirIndex < 4; DirIndex++)
				{
					const FIntVector Neighbor = LastCell + GPathDirs[DirIndex];
					if(Neighbor == BeforeLast || !MainPath.Contains(Neighbor)) { continue; }

					const int32 NeighborIndex = MainPath.IndexOfByKey(Neighbor);
					EOmegaDngPathCellType NeighborType = EOmegaDngPathCellType::Path;
					if(NeighborIndex == 0) { NeighborType = EOmegaDngPathCellType::Start; }
					else if(NeighborIndex == MainPath.Num() - 1) { NeighborType = EOmegaDngPathCellType::End; }

					const int32 NewLastMask = CellConnectionMasks.FindRef(LastCell + Shift) | (1 << DirIndex);
					const int32 NewNeighborMask = CellConnectionMasks.FindRef(Neighbor + Shift) | (1 << ((DirIndex + 2) % 4));
					if(!CanListCoverMask(Modules_Path, NewLastMask)) { continue; } // connected-back leaf cells use path modules
					if(!CanListCoverMask(GetModuleList(NeighborType), NewNeighborMask)) { continue; }

					AddCellConnection(LastCell + Shift, Neighbor + Shift);
					bConnectsBack = true;
					break;
				}
			}
			if(!bConnectsBack)
			{
				Dungeon->SetCell(LeafCells.Last() + Shift, MakeCell(EOmegaDngPathCellType::LeafEnd));
			}
		}
	}

	// --- Adjacency connections -----------------------------------------------------------------------------------
	// Cells that touch without being linked by path order also connect — but only while both cells are
	// under MaxModuleSocketConnections. This is what the cap limits (structural path/leaf connections
	// above are exempt): with the default of 2, a path folding into a 2x2 block stays a corridor with
	// walls instead of merging into one wide open area.
	TArray<FIntVector> AllCells = Dungeon->GetCellCoords();
	AllCells.Sort([](const FIntVector& A, const FIntVector& B)
	{
		if(A.X != B.X) { return A.X < B.X; }
		if(A.Y != B.Y) { return A.Y < B.Y; }
		return A.Z < B.Z;
	});
	for(const FIntVector& CellCoord : AllCells)
	{
		for(int32 DirIndex = 0; DirIndex < 2; DirIndex++) // +X and +Y only; the -X/-Y pair is visited from the neighbor
		{
			const FIntVector Neighbor = CellCoord + GPathDirs[DirIndex];
			if(!Dungeon->HasCell(Neighbor)) { continue; }
			if(CellConnectionMasks.FindRef(CellCoord) & (1 << DirIndex)) { continue; } // already connected
			if(GetConnectionCount(CellCoord) >= MaxConnections || GetConnectionCount(Neighbor) >= MaxConnections) { continue; }

			// Only connect if both cells' module lists can realize the extra opening.
			FOmegaDungeonCellData CellA, CellB;
			if(!Dungeon->GetCell(CellCoord, CellA) || !Dungeon->GetCell(Neighbor, CellB)) { continue; }
			const int32 NewMaskA = CellConnectionMasks.FindRef(CellCoord) | (1 << DirIndex);
			const int32 NewMaskB = CellConnectionMasks.FindRef(Neighbor) | (1 << ((DirIndex + 2) % 4));
			if(!CanListCoverMask(GetModuleList(static_cast<EOmegaDngPathCellType>(CellA.type)), NewMaskA)) { continue; }
			if(!CanListCoverMask(GetModuleList(static_cast<EOmegaDngPathCellType>(CellB.type)), NewMaskB)) { continue; }

			AddCellConnection(CellCoord, Neighbor);
		}
	}
}

void UOmegaDungeonModel_Path::Dungeon_ProcessCell_Implementation(AOmegaDungeon* Dungeon, FIntVector Coord, FOmegaDungeonCellData Cell)
{
	const FTransform CellTransform = Dungeon->GetCellTransform(Coord, CellModuleSize);

	// Sides that must stay open: the layout logically connects this cell to a neighbor there.
	// (Adjacent cells WITHOUT a connection get walled off in the Dungeon_GenerateEnd pass.)
	const int32 RequiredMask = CellConnectionMasks.FindRef(Coord);

	// Tag constraints from already-placed neighbors on connected sides: whatever module goes here must
	// present a socket those neighbors' facing sockets mutually accept.
	TArray<const FOmegaDngMdl_SocketInfo*> Constraints;
	Constraints.Init(nullptr, 4);
	for(int32 DirIndex = 0; DirIndex < 4; DirIndex++)
	{
		if(!(RequiredMask & (1 << DirIndex))) { continue; }
		if(const FOmegaDngMdl_ModuleSockets* NeighborSockets = PlacedCellSockets.Find(Coord + GPathDirs[DirIndex]))
		{
			const FOmegaDngMdl_SocketInfo& Facing = NeighborSockets->Dirs[(DirIndex + 2) % 4];
			if(Facing.bHasSocket) { Constraints[DirIndex] = &Facing; }
		}
	}

	const TArray<FOmegaDngMdl_Path_Module>& ModuleList = GetModuleList(static_cast<EOmegaDngPathCellType>(Cell.type));
	const FOmegaDngMdl_Path_Module* Picked = PickModule(ModuleList, Dungeon, RequiredMask, Constraints);
	if(!Picked) { return; }

	const FOmegaDngMdl_ModuleSockets& SocketData = GetModuleSocketData(Picked->Module);

	// Random rotation among those covering the required sides with tag-compatible sockets. The looser
	// fallbacks only trigger when PickModule itself had to fall back (content gap, already warned).
	int32 ChosenStep = 0;
	TArray<int32> ValidSteps = GetValidRotations(SocketData, RequiredMask, Constraints);
	if(ValidSteps.Num() == 0)
	{
		ValidSteps = GetValidRotations(SocketData, RequiredMask, TArray<const FOmegaDngMdl_SocketInfo*>());
	}
	if(ValidSteps.Num() > 0)
	{
		ChosenStep = ValidSteps[Dungeon->GetRandomIntInRange(0, ValidSteps.Num() - 1)];
	}
	else
	{
		// No rotation covers every required side — use the best partial fit.
		const int32 SocketMask = SocketData.GetDirMask();
		int32 BestCover = -1;
		for(int32 Step = 0; Step < 4; Step++)
		{
			const int32 RotatedMask = ((SocketMask << Step) | (SocketMask >> (4 - Step))) & 0xF;
			const int32 Cover = FMath::CountBits(RotatedMask & RequiredMask);
			if(Cover > BestCover)
			{
				BestCover = Cover;
				ChosenStep = Step;
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("[DungeonModel_Path] Module '%s' has too few sockets for cell %s (needs %d open sides)"),
			*Picked->Module.ToString(), *Coord.ToString(), FMath::CountBits(RequiredMask));
	}

	// Record the rotated (world-direction) socket layout so later cells can tag-match against this one.
	FOmegaDngMdl_ModuleSockets PlacedSockets;
	for(int32 DirIndex = 0; DirIndex < 4; DirIndex++)
	{
		PlacedSockets.Dirs[(DirIndex + ChosenStep) % 4] = SocketData.Dirs[DirIndex];
	}
	PlacedCellSockets.Add(Coord, PlacedSockets);

	const FTransform ModuleTransform = FTransform(FRotator(0.f, ChosenStep * 90.f, 0.f)) * CellTransform;
	Dungeon->SpawnLevelModule(Picked->Module, ModuleTransform);
}

void UOmegaDungeonModel_Path::Dungeon_ProcessOpenSocket_Implementation(AOmegaDungeon* Dungeon, AOmegaDungeon_Socket* Socket)
{
	// Walls are handled in Dungeon_GenerateEnd instead: "open" only means no coincident socket, but this
	// model must ALSO wall coincident socket pairs whose cells aren't logically connected.
}

void UOmegaDungeonModel_Path::Dungeon_GenerateEnd_Implementation(AOmegaDungeon* Dungeon)
{
	// Socket pass: every socket that doesn't face a logically-connected neighbor gets a wall — sealing
	// dungeon-boundary openings AND both sides of adjacent-but-unconnected cell pairs. Sockets that DO
	// face a connected neighbor get a door module in the opening instead (spawned once per connection,
	// from the +X/+Y side of the coincident socket pair).
	if(Modules_Wall.Num() > 0 || Modules_Doors.Num() > 0)
	{
		const FTransform DungeonTransform = Dungeon->GetActorTransform();
		for(AOmegaDungeon_Socket* Socket : Dungeon->GetAllSockets())
		{
			if(!Socket) { continue; }

			// Map the socket back to its cell coord + facing direction (dungeon-local space).
			const FVector LocalLocation = DungeonTransform.InverseTransformPosition(Socket->GetActorLocation());
			const float LocalYaw = DungeonTransform.InverseTransformRotation(Socket->GetActorQuat()).Rotator().Yaw;
			const int32 DirIndex = FMath::RoundToInt(FRotator::ClampAxis(LocalYaw) / 90.f) % 4;
			const FVector DirVector(GPathDirs[DirIndex].X, GPathDirs[DirIndex].Y, GPathDirs[DirIndex].Z);
			// The socket sits on the cell edge; step half a cell inward to land on the cell center.
			const FVector CellCenter = LocalLocation - DirVector * CellModuleSize * 0.5f;
			const FIntVector Coord(
				FMath::RoundToInt(CellCenter.X / CellModuleSize.X),
				FMath::RoundToInt(CellCenter.Y / CellModuleSize.Y),
				FMath::RoundToInt(CellCenter.Z / CellModuleSize.Z));

			const bool bConnected = (CellConnectionMasks.FindRef(Coord) & (1 << DirIndex)) != 0;
			if(!bConnected)
			{
				SpawnCellModule(Modules_Wall, Dungeon, Socket->GetActorTransform());
			}
			else if(DirIndex < 2) // connection = two coincident sockets; only the +X/+Y one spawns the door
			{
				SpawnCellModule(Modules_Doors, Dungeon, Socket->GetActorTransform());
			}
		}
	}
	ModuleUseCounts.Reset();
}

const FOmegaDngMdl_ModuleSockets& UOmegaDungeonModel_Path::GetModuleSocketData(const TSoftObjectPtr<UWorld>& Module)
{
	const FSoftObjectPath Key = Module.ToSoftObjectPath();
	if(const FOmegaDngMdl_ModuleSockets* Cached = ModuleSocketDataCache.Find(Key)) { return *Cached; }

	// Loads the module as a plain asset to inspect its authored sockets. Socket yaw is quantized to the
	// nearest 90° and mapped to the GPathDirs index (+X=0, +Y=1, -X=2, -Y=3). One socket per face is
	// assumed; if a face has several, the last one found wins.
	FOmegaDngMdl_ModuleSockets Data;
	if(UWorld* ModuleWorld = Module.LoadSynchronous())
	{
		if(ModuleWorld->PersistentLevel)
		{
			for(AActor* TempActor : ModuleWorld->PersistentLevel->Actors)
			{
				if(const AOmegaDungeon_Socket* Socket = Cast<AOmegaDungeon_Socket>(TempActor))
				{
					const int32 DirIndex = FMath::RoundToInt(FRotator::ClampAxis(Socket->GetActorRotation().Yaw) / 90.f) % 4;
					FOmegaDngMdl_SocketInfo& Info = Data.Dirs[DirIndex];
					Info.bHasSocket = true;
					Info.Tag = Socket->SocketTag;
					Info.Accepted = Socket->AcceptedSockets;
				}
			}
		}
	}
	return ModuleSocketDataCache.Add(Key, Data);
}

const FOmegaDngMdl_Path_Module* UOmegaDungeonModel_Path::PickModule(const TArray<FOmegaDngMdl_Path_Module>& List, AOmegaDungeon* Dungeon, int32 RequiredDirMask,
	const TArray<const FOmegaDngMdl_SocketInfo*>& NeighborConstraints)
{
	TArray<const FOmegaDngMdl_Path_Module*> UnderMin;
	TArray<const FOmegaDngMdl_Path_Module*> Eligible;
	for(const FOmegaDngMdl_Path_Module& TempModule : List)
	{
		if(TempModule.Module.IsNull()) { continue; }
		const int32 Count = ModuleUseCounts.FindRef(&TempModule);
		if(TempModule.Max > 0 && Count >= TempModule.Max) { continue; }
		// Traversal guarantee: never pick a module whose sockets can't face every neighboring cell in a
		// rotation that is also tag-compatible with the sockets of already-placed neighbors.
		if(GetValidRotations(GetModuleSocketData(TempModule.Module), RequiredDirMask, NeighborConstraints).Num() == 0) { continue; }
		Eligible.Add(&TempModule);
		if(Count < TempModule.Min) { UnderMin.Add(&TempModule); }
	}

	// Modules that haven't hit their Min yet take priority, so Min counts get satisfied.
	const TArray<const FOmegaDngMdl_Path_Module*>& Pool = UnderMin.Num() > 0 ? UnderMin : Eligible;
	if(Pool.Num() == 0)
	{
		const bool bHadTagConstraints = NeighborConstraints.ContainsByPredicate(
			[](const FOmegaDngMdl_SocketInfo* Constraint) { return Constraint != nullptr; });
		if(bHadTagConstraints)
		{
			// Sockets exist but no module's tags match the placed neighbors — retry ignoring tags.
			UE_LOG(LogTemp, Warning, TEXT("[DungeonModel_Path] No module in list is tag-compatible with its placed neighbors (mask %d) — picking ignoring socket tags."), RequiredDirMask);
			return PickModule(List, Dungeon, RequiredDirMask);
		}
		if(RequiredDirMask != 0)
		{
			// No module in this list can cover the cell's open sides — a content gap. Fall back to an
			// unconstrained pick (path may be blocked there) rather than leaving a hole in the dungeon.
			UE_LOG(LogTemp, Warning, TEXT("[DungeonModel_Path] No module in list can cover required sides (mask %d) — picking unconstrained. Add a module with matching sockets."), RequiredDirMask);
			return PickModule(List, Dungeon, 0);
		}
		return nullptr;
	}

	TArray<float> Weights;
	for(const FOmegaDngMdl_Path_Module* TempModule : Pool) { Weights.Add(TempModule->Weight); }
	const int32 PickedIndex = Dungeon->GetRandomWeightedIndex(Weights);
	if(PickedIndex == INDEX_NONE) { return nullptr; }

	const FOmegaDngMdl_Path_Module* Picked = Pool[PickedIndex];
	ModuleUseCounts.FindOrAdd(Picked)++;
	return Picked;
}

void UOmegaDungeonModel_Path::SpawnCellModule(const TArray<FOmegaDngMdl_Path_Module>& List, AOmegaDungeon* Dungeon, const FTransform& Transform)
{
	if(const FOmegaDngMdl_Path_Module* Picked = PickModule(List, Dungeon))
	{
		Dungeon->SpawnLevelModule(Picked->Module, Transform);
	}
}
