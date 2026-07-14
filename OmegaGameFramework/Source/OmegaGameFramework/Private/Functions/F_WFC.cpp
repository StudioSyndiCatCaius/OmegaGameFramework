// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_WFC.h"
#include "Math/RandomStream.h"

// =====================================================================================================
// UOmegaWFCScript — default (no-op) implementations
// =====================================================================================================

void UOmegaWFCScript::OnGenerationBegin_Implementation(AOmegaWfcSpawner* /*Spawner*/) {}
void UOmegaWFCScript::OnCellCollapsed_Implementation(AOmegaWfcSpawner* /*Spawner*/, FIntVector /*Coordinate*/, int32 /*TileIndex*/) {}
void UOmegaWFCScript::OnContradiction_Implementation(AOmegaWfcSpawner* /*Spawner*/, int32 /*Attempt*/) {}
void UOmegaWFCScript::OnGenerationComplete_Implementation(AOmegaWfcSpawner* /*Spawner*/) {}
void UOmegaWFCScript::OnMapSpawned_Implementation(AOmegaWfcSpawner* /*Spawner*/) {}


// =====================================================================================================
// UOmegaWFCDefinition — default implementations
// =====================================================================================================

TArray<UOmegaWFCScript*> UOmegaWFCDefinition::L_GetScripts() const
{
	TArray<UOmegaWFCScript*> Result;
	for (auto* Preset : Scripts_Preset)
	{
		if (Preset) { Result.Append(Preset->Scripts); }
	}
	Result.Append(Scripts_Inline);
	return Result;
}

int32 UOmegaWFCDefinition::GetTileCount_Implementation() { return 0; }

TArray<FOmegaWfcTileSlotData> UOmegaWFCDefinition::GetTileSlots_Implementation(int32 /*TileIndex*/)
{
	return TArray<FOmegaWfcTileSlotData>();
}

float UOmegaWFCDefinition::GetTileWeight_Implementation(int32 /*TileIndex*/) { return 1.f; }

USceneComponent* UOmegaWFCDefinition::OnTileSpawn_Implementation(AOmegaWfcSpawner* /*Spawner*/, FIntVector /*Coordinate*/, int32 /*TileIndex*/)
{
	return nullptr;
}

void UOmegaWFCDefinition::OnTileDestroy_Implementation(AOmegaWfcSpawner* /*Spawner*/, USceneComponent* Tile)
{
	if (Tile) { Tile->DestroyComponent(); }
}


// =====================================================================================================
// AOmegaWfcSpawner
// =====================================================================================================

AOmegaWfcSpawner::AOmegaWfcSpawner()
{
	Root = CreateDefaultSubobject<UBillboardComponent>(TEXT("Root"));
	SetRootComponent(Root);
}

void AOmegaWfcSpawner::ForceTileAtCoordinate(FIntVector Coordinate, int32 TileIndex)
{
	PendingForced.Add({ Coordinate, TileIndex });
}

void AOmegaWfcSpawner::DestroyMap()
{
	for (USceneComponent* Tile : GeneratedTiles)
	{
		if (Tile && Definition) { Definition->OnTileDestroy(this, Tile); }
		else if (Tile)          { Tile->DestroyComponent(); }
	}
	GeneratedTiles.Empty();
}

void AOmegaWfcSpawner::RandomizeSeed()  { Seed = FMath::RandRange(0, INT_MAX); }
void AOmegaWfcSpawner::RandomizeMap()   { RandomizeSeed(); GenerateMap(); }

void AOmegaWfcSpawner::GenerateMap()
{
	DestroyMap();
	if (!Definition) { return; }

	const int32 TileCount = Definition->GetTileCount();
	if (TileCount <= 0) { return; }
	const int32 TotalCells = Size.X * Size.Y * Size.Z;
	if (TotalCells <= 0) { return; }

	// Collect scripts from definition + spawner
	TArray<UOmegaWFCScript*> AllScripts = Definition->L_GetScripts();
	AllScripts.Append(Scripts);

	// Face directions: index 0=+X 1=-X 2=+Y 3=-Y 4=+Z 5=-Z
	static const FIntVector Dirs[6]   = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
	static const int32      OppDir[6] = {       1,       0,       3,       2,       5,       4 };

	// Precompute compatibility: Compat[tileA][dir] = set of tile IDs that can sit in direction dir from A
	TArray<TArray<TSet<int32>>> Compat;
	Compat.SetNum(TileCount);
	for (int32 a = 0; a < TileCount; a++)
	{
		Compat[a].SetNum(6);
		TArray<FOmegaWfcTileSlotData> SlotsA = Definition->GetTileSlots(a);
		for (int32 dir = 0; dir < 6; dir++)
		{
			const int32 SlotA = SlotsA.IsValidIndex(dir) ? SlotsA[dir].SlotID : 0;
			for (int32 b = 0; b < TileCount; b++)
			{
				TArray<FOmegaWfcTileSlotData> SlotsB = Definition->GetTileSlots(b);
				const int32 SlotB = SlotsB.IsValidIndex(OppDir[dir]) ? SlotsB[OppDir[dir]].SlotID : 0;
				if (SlotA == SlotB) { Compat[a][dir].Add(b); }
			}
		}
	}

	// Coordinate utilities
	auto CoordToIdx = [&](const FIntVector& c) -> int32
	{
		return c.X + c.Y * Size.X + c.Z * Size.X * Size.Y;
	};
	auto IdxToCoord = [&](int32 idx) -> FIntVector
	{
		return FIntVector(idx % Size.X, (idx / Size.X) % Size.Y, idx / (Size.X * Size.Y));
	};
	auto InBounds = [&](const FIntVector& c) -> bool
	{
		return c.X >= 0 && c.X < Size.X && c.Y >= 0 && c.Y < Size.Y && c.Z >= 0 && c.Z < Size.Z;
	};

	// Tile weights
	TArray<float> Weights;
	Weights.SetNum(TileCount);
	for (int32 i = 0; i < TileCount; i++) { Weights[i] = FMath::Max(0.001f, Definition->GetTileWeight(i)); }

	// Wave state: Wave[cell * TileCount + tile] = still possible?
	TArray<uint8> Wave;
	TArray<int32> OptionCount;

	// BFS propagation helper — returns false if a contradiction is found
	auto Propagate = [&](int32 StartIdx, bool& bContradiction)
	{
		TArray<int32> Queue    = { StartIdx };
		TSet<int32>   InQueue  = { StartIdx };
		int32 Head = 0;

		while (Head < Queue.Num())
		{
			const int32 CurIdx    = Queue[Head++];
			const FIntVector CurCoord = IdxToCoord(CurIdx);

			for (int32 dir = 0; dir < 6; dir++)
			{
				const FIntVector NbrCoord = CurCoord + Dirs[dir];
				if (!InBounds(NbrCoord)) { continue; }
				const int32 NbrIdx = CoordToIdx(NbrCoord);
				if (OptionCount[NbrIdx] == 0) { bContradiction = true; return; }

				bool bChanged = false;
				for (int32 t = 0; t < TileCount; t++)
				{
					if (!Wave[NbrIdx * TileCount + t]) { continue; }
					bool bOk = false;
					for (int32 ca = 0; ca < TileCount && !bOk; ca++)
					{
						if (Wave[CurIdx * TileCount + ca] && Compat[ca][dir].Contains(t)) { bOk = true; }
					}
					if (!bOk)
					{
						Wave[NbrIdx * TileCount + t] = 0;
						OptionCount[NbrIdx]--;
						bChanged = true;
					}
				}
				if (OptionCount[NbrIdx] == 0) { bContradiction = true; return; }
				if (bChanged && !InQueue.Contains(NbrIdx)) { Queue.Add(NbrIdx); InQueue.Add(NbrIdx); }
			}
		}
	};

	// Forced-collapse helper used for script-requested collapses
	auto ForceCollapse = [&](const FIntVector& Coord, int32 TileIdx, bool& bContradiction)
	{
		if (!InBounds(Coord)) { return; }
		const int32 CellIdx = CoordToIdx(Coord);
		if (TileIdx < 0 || TileIdx >= TileCount) { return; }
		for (int32 t = 0; t < TileCount; t++) { Wave[CellIdx * TileCount + t] = (t == TileIdx) ? 1 : 0; }
		OptionCount[CellIdx] = 1;
		Propagate(CellIdx, bContradiction);
	};

	// Collect forced collapses from all scripts (once, before any retry)
	PendingForced.Empty();
	// Initialise a scratch wave so scripts can call ForceTileAtCoordinate safely
	Wave.Init(1, TotalCells * TileCount);
	OptionCount.Init(TileCount, TotalCells);
	for (auto* Script : AllScripts) { if (Script) { Script->OnGenerationBegin(this); } }

	// WFC main loop
	FRandomStream Rand(Seed);
	bool bSuccess = false;

	for (int32 Attempt = 0; Attempt < 10 && !bSuccess; Attempt++)
	{
		Wave.Init(1, TotalCells * TileCount);
		OptionCount.Init(TileCount, TotalCells);

		bool bContradiction = false;

		// Apply script-forced collapses first
		for (const TPair<FIntVector, int32>& Forced : PendingForced)
		{
			if (bContradiction) { break; }
			ForceCollapse(Forced.Key, Forced.Value, bContradiction);
		}

		// WFC collapse loop
		while (!bContradiction)
		{
			// Find the uncollapsed cell with the fewest options (min entropy)
			int32 MinOptions = INT_MAX;
			int32 ChosenCell = -1;
			for (int32 i = 0; i < TotalCells; i++)
			{
				const int32 n = OptionCount[i];
				if (n == 0) { bContradiction = true; break; }
				if (n > 1 && n < MinOptions) { MinOptions = n; ChosenCell = i; }
			}
			if (bContradiction) { break; }
			if (ChosenCell == -1) { bSuccess = true; break; }

			// Weighted-random collapse
			float TotalW = 0.f;
			for (int32 t = 0; t < TileCount; t++) { if (Wave[ChosenCell * TileCount + t]) { TotalW += Weights[t]; } }
			float Pick = Rand.FRandRange(0.f, TotalW);
			float Acc  = 0.f;
			int32 Chosen = 0;
			for (int32 t = 0; t < TileCount; t++)
			{
				if (!Wave[ChosenCell * TileCount + t]) { continue; }
				Acc += Weights[t];
				if (Acc >= Pick) { Chosen = t; break; }
			}
			for (int32 t = 0; t < TileCount; t++) { Wave[ChosenCell * TileCount + t] = (t == Chosen) ? 1 : 0; }
			OptionCount[ChosenCell] = 1;

			// Notify scripts
			const FIntVector ChosenCoord = IdxToCoord(ChosenCell);
			for (auto* Script : AllScripts) { if (Script) { Script->OnCellCollapsed(this, ChosenCoord, Chosen); } }

			Propagate(ChosenCell, bContradiction);
		}

		if (bContradiction)
		{
			for (auto* Script : AllScripts) { if (Script) { Script->OnContradiction(this, Attempt); } }
			Rand = FRandomStream(Seed + Attempt + 1);
		}
	}

	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("OmegaWFC: Could not collapse grid after 10 attempts — check that tile slot IDs allow a valid configuration."));
		PendingForced.Empty();
		return;
	}

	for (auto* Script : AllScripts) { if (Script) { Script->OnGenerationComplete(this); } }

	// Spawn visuals
	GeneratedTiles.SetNum(TotalCells);
	for (int32 i = 0; i < TotalCells; i++)
	{
		int32 TileIdx = -1;
		for (int32 t = 0; t < TileCount; t++) { if (Wave[i * TileCount + t]) { TileIdx = t; break; } }
		if (TileIdx < 0) { continue; }
		GeneratedTiles[i] = Definition->OnTileSpawn(this, IdxToCoord(i), TileIdx);
	}

	for (auto* Script : AllScripts) { if (Script) { Script->OnMapSpawned(this); } }

	PendingForced.Empty();
}


// =====================================================================================================
// UOmegaWFCDef_StaticMesh
// =====================================================================================================

int32 UOmegaWFCDef_StaticMesh::GetTileCount_Implementation()
{
	return Tiles.Num();
}

TArray<FOmegaWfcTileSlotData> UOmegaWFCDef_StaticMesh::GetTileSlots_Implementation(int32 TileIndex)
{
	// 6 slots in order: +X, -X, +Y, -Y, +Z, -Z (matching Dirs[] in GenerateMap)
	TArray<FOmegaWfcTileSlotData> Out;
	Out.SetNum(6);

	if (!Tiles.IsValidIndex(TileIndex)) { return Out; }
	UStaticMesh* Mesh = Tiles[TileIndex].Mesh.LoadSynchronous();
	if (!Mesh) { return Out; }

	const FBoxSphereBounds Bounds    = Mesh->GetBounds();
	const FVector          HalfExtent = Bounds.BoxExtent + FVector(KINDA_SMALL_NUMBER);

	static const FString Prefix = TEXT("WfcSlot:");

	for (UStaticMeshSocket* Socket : Mesh->Sockets)
	{
		if (!Socket) { continue; }
		const FString Name = Socket->SocketName.ToString();
		if (!Name.StartsWith(Prefix)) { continue; }

		// Suffix after the first '_' is ignored — allows multiple sockets with the same slot ID.
		FString AfterPrefix = Name.RightChop(Prefix.Len());
		FString IdStr, Ignored;
		if (!AfterPrefix.Split(TEXT("_"), &IdStr, &Ignored)) { IdStr = AfterPrefix; }
		const int32 SlotId = FCString::Atoi(*IdStr);

		// Determine face by the dominant axis of the socket position relative to mesh bounds centre
		const FVector Local      = Socket->RelativeLocation - Bounds.Origin;
		const FVector Normalized = Local / HalfExtent;
		const float   AbsX = FMath::Abs(Normalized.X);
		const float   AbsY = FMath::Abs(Normalized.Y);
		const float   AbsZ = FMath::Abs(Normalized.Z);

		int32 FaceIdx = -1;
		if      (AbsX >= AbsY && AbsX >= AbsZ) { FaceIdx = Normalized.X > 0.f ? 0 : 1; }
		else if (AbsY >= AbsX && AbsY >= AbsZ) { FaceIdx = Normalized.Y > 0.f ? 2 : 3; }
		else                                    { FaceIdx = Normalized.Z > 0.f ? 4 : 5; }

		if (FaceIdx >= 0) { Out[FaceIdx].SlotID = SlotId; }
	}

	return Out;
}

float UOmegaWFCDef_StaticMesh::GetTileWeight_Implementation(int32 TileIndex)
{
	if (!Tiles.IsValidIndex(TileIndex)) { return 1.f; }
	return FMath::Max(0.001f, Tiles[TileIndex].Weight);
}

USceneComponent* UOmegaWFCDef_StaticMesh::OnTileSpawn_Implementation(AOmegaWfcSpawner* Spawner, FIntVector Coordinate, int32 TileIndex)
{
	if (!Spawner || !Tiles.IsValidIndex(TileIndex)) { return nullptr; }
	UStaticMesh* Mesh = Tiles[TileIndex].Mesh.LoadSynchronous();
	if (!Mesh) { return nullptr; }

	UStaticMeshComponent* Comp = NewObject<UStaticMeshComponent>(Spawner);
	Comp->SetStaticMesh(Mesh);
	Comp->AttachToComponent(Spawner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	Comp->SetRelativeLocation(FVector(Coordinate.X, Coordinate.Y, Coordinate.Z) * TileSize);
	Comp->RegisterComponent();
	return Comp;
}

void UOmegaWFCDef_StaticMesh::OnTileDestroy_Implementation(AOmegaWfcSpawner* /*Spawner*/, USceneComponent* Tile)
{
	if (Tile) { Tile->DestroyComponent(); }
}


// =====================================================================================================
// UWFCScript_MainPath
// =====================================================================================================

void UWFCScript_MainPath::OnGenerationBegin_Implementation(AOmegaWfcSpawner* Spawner)
{
	if (!Spawner) { return; }
	const FIntVector GS = Spawner->Size;

	// Use an offset seed so this stream doesn't mirror the main WFC collapse stream
	FRandomStream Rand(Spawner->Seed + 0xABCDEF);

	const int32 PathLen = Rand.RandRange(
		MinPathLength,
		FMath::Max(MinPathLength, MaxPathLength)
	);

	// Pick a random edge to start on: 0=MinX 1=MaxX 2=MinY 3=MaxY
	const int32 StartEdge    = Rand.RandRange(0, 3);
	const int32 DistFromEdge = Rand.RandRange(
		MinStartDistanceFromEdge,
		FMath::Max(MinStartDistanceFromEdge, MaxStartDistanceFromEdge)
	);

	FIntVector Start;
	FIntVector InwardDir;
	switch (StartEdge)
	{
		case 0:  Start = { DistFromEdge,             Rand.RandRange(0, GS.Y-1), 0 }; InwardDir = {  1, 0, 0 }; break;
		case 1:  Start = { GS.X-1-DistFromEdge,      Rand.RandRange(0, GS.Y-1), 0 }; InwardDir = { -1, 0, 0 }; break;
		case 2:  Start = { Rand.RandRange(0, GS.X-1), DistFromEdge,             0 }; InwardDir = {  0, 1, 0 }; break;
		default: Start = { Rand.RandRange(0, GS.X-1), GS.Y-1-DistFromEdge,      0 }; InwardDir = {  0,-1, 0 }; break;
	}

	// Perpendicular turn direction (random left or right relative to InwardDir)
	FIntVector PerpDir = Rand.RandBool()
		? FIntVector(-InwardDir.Y,  InwardDir.X, 0)
		: FIntVector( InwardDir.Y, -InwardDir.X, 0);

	// Split the path: first half inward, second half perpendicular
	const int32 LegA = PathLen / 2;
	const int32 LegB = PathLen - LegA;

	const int32 TileStart = PathTile_Start >= 0 ? PathTile_Start : PathTile_Main;
	const int32 TileEnd   = PathTile_End   >= 0 ? PathTile_End   : PathTile_Main;

	auto Clamp = [&](FIntVector c) -> FIntVector
	{
		return FIntVector(
			FMath::Clamp(c.X, 0, GS.X - 1),
			FMath::Clamp(c.Y, 0, GS.Y - 1),
			FMath::Clamp(c.Z, 0, FMath::Max(0, GS.Z - 1))
		);
	};

	FIntVector Cur = Clamp(Start);

	// Force start cell
	Spawner->ForceTileAtCoordinate(Cur, TileStart);

	// Walk inward leg
	for (int32 i = 1; i <= LegA; i++)
	{
		Cur = Clamp(Cur + InwardDir);
		Spawner->ForceTileAtCoordinate(Cur, PathTile_Main);
	}

	// Walk perpendicular leg (last cell gets TileEnd)
	for (int32 i = 1; i <= LegB; i++)
	{
		Cur = Clamp(Cur + PerpDir);
		Spawner->ForceTileAtCoordinate(Cur, i == LegB ? TileEnd : PathTile_Main);
	}
}
