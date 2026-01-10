// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaGameMode.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Actors/Actor_Player.h"
#include "Functions/F_Widget.h"
#include "Subsystems/Subsystem_DynamicCamera.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Gameplay.h"

void AOmegaGameMode::Native_DragSelectEnd(const TArray<AActor*>& actors)
{
	OnDragSelectedEnded.Broadcast(actors);
	OnDragSelectEnd(actors);
}

void AOmegaGameMode::Local_LoadSystemShutdown(UObject* Context, FString Flag)
{
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	
	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : PostLoadGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "GameMode_PostLoad");
	}
	OnLoadEventFinish.Broadcast();
	OnLoadEventFinished();
}

AOmegaGameMode::AOmegaGameMode()
{
	PlayerControllerClass=AOmegaPlayer::StaticClass();
	HUDClass=AOmegaHUD::StaticClass();
	DragSelectColor=FLinearColor(1,1,1,0.4);
}

void AOmegaGameMode::Local_ActivatePersistentSystems()
{
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : PersistentGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "PersistentSystem");
	}
}

void AOmegaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Fire OnLevelOpened Delegate
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnNewLevel.Broadcast(UGameplayStatics::GetCurrentLevelName(this), this);
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : AutoGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "GameMode_PreLoad");
	}

	if(LoadGameplaySystem)
	{
		AOmegaGameplaySystem* TempLoadSys = SystemRef->ActivateGameplaySystem(LoadGameplaySystem, this, "GameMode_Load");
		TempLoadSys->OnSystemShutdown.AddDynamic(this, &AOmegaGameMode::Local_LoadSystemShutdown);
	}
	else
	{
		Local_LoadSystemShutdown(this, "NONE");
	}

	// Bind a function to be called by the timer.
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("Local_ActivatePersistentSystems"));

	// Set the timer. Replace GetWorld()->GetTimerManager() with your context.
	GetWorld()->GetTimerManager().SetTimer(PersistentSystemsTimerHandle, TimerDel, PersistentSystemActivationFrequency, true);

	
}

void AOmegaGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if(AOmegaPlayer* p=Cast<AOmegaPlayer>(NewPlayer))
	{
		p->Systems_Auto.Append(PlayerSystems_Auto);
		p->SetSystemsActive(PlayerSystems_Auto,this,"Auto",true);
		p->Systems_Persistent.Append(PlayerSystems_Auto);
	}
	
	if (bAutoActivateDynamicCamera)
	{
		if (UOmegaDynamicCameraSubsystem* _subsys=NewPlayer->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>())
		{
			_subsys->SetDynamicCameraActive(bAutoActivateDynamicCamera);
			if (DefaultDynamicCamera)
			{
				AOmegaDynamicCamera* _NewCam=GetWorld()->SpawnActorDeferred<AOmegaDynamicCamera>(DefaultDynamicCamera,NewPlayer->GetLevelTransform());
				_NewCam->restricted_players.AddUnique(NewPlayer);
				_NewCam->FinishSpawning(NewPlayer->GetLevelTransform());
			}
		}
		
	}
	UOmegaWidgetFunctions::SetHUDLayersActive(this,HUDLayers_Persistent,true,this,"",NewPlayer);
	
}


bool AOmegaHUD::isDragInputDown() const
{
	if(ref_gameMode)
	{
		for(FKey key : ref_gameMode->DragSelectKeys)
		{
			if(GetWorld()->GetFirstPlayerController()->IsInputKeyDown(key))
			{
				return true;
			}
		}
	}
	return false;
}

void AOmegaHUD::BeginPlay()
{
	Super::BeginPlay();
	if(AOmegaGameMode* _gm=Cast<AOmegaGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		ref_gameMode=_gm;
	}
}

bool isActorChildOfList(TArray<TSubclassOf<AActor>> classes, AActor* a)
{
	if(a)
	{
		for (TSubclassOf<AActor> cls : classes)
		{
			if(cls && a->GetClass()->IsChildOf(cls))
			{
				return true;
			}
		}
	}
	return false;
}

void AOmegaHUD::DrawHUD()
{
	Super::DrawHUD();
	if(ref_gameMode && ref_gameMode->CanDragSelect)
	{
		if(isDragInputDown())
		{
			APlayerController* _player=GetWorld()->GetFirstPlayerController();
			if(!b_isDragSelecting)
			{
				b_isDragSelecting=true;
				_player->GetMousePosition(dragSelect_start.X,dragSelect_start.Y);
			}
			
			_player->GetMousePosition(dragSelect_end.X,dragSelect_end.Y);
			dragSelect_end=dragSelect_end-dragSelect_start;
			DrawRect(ref_gameMode->DragSelectColor,dragSelect_start.X,dragSelect_start.Y,dragSelect_end.X,dragSelect_end.Y);
		}
		else
		{
			if(b_isDragSelecting)
			{
				b_isDragSelecting=false;
				TArray<AActor*> actors_found;
				GetActorsInSelectionRectangle(AActor::StaticClass(),dragSelect_start,dragSelect_end,actors_found);
				TArray<AActor*> actors_out;
				for(auto* a : actors_found)
				{
					if(isActorChildOfList(ref_gameMode->DragSelectableActors, a))
					{
						actors_out.Add(a);
					}
				}
				ref_gameMode->Native_DragSelectEnd(actors_out);
			}
		}
	}
}

