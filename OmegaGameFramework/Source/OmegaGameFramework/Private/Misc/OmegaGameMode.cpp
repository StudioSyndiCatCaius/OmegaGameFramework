// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Actors/Actor_DynamicCamera.h"
#include "Actors/Actor_Player.h"
#include "Components/Component_Combatant.h"
#include "DataAssets/DA_Calendar.h"
#include "Functions/F_Entity.h"
#include "Functions/F_Widget.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_World.h"

void AOmegaGameMode::Native_DragSelectEnd(const TArray<AActor*>& actors)
{
	
	OnDragSelectedEnded.Broadcast(actors);
	OnDragSelectEnd(actors); 
}

void AOmegaGameMode::Local_LoadSystemShutdown(UObject* Context, FString Flag)
{
	
	UOmegaSubsystem_World* SystemRef = GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	
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

	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	AssetSquad=CreateOptionalDefaultSubobject<UAssetSquadComponent>("AssetSquad");
	EntityInstances=CreateOptionalDefaultSubobject<UInstanceActorComponent>("Entity Instances");
	Calendar=CreateOptionalDefaultSubobject<UOmegaCalendarComponent>("Calendar");
	

	FName GlobalNameId = "_GLOBAL_";
	

	if(Combatant)
	{
		Combatant->use_entity_id=true;
		Combatant->entity_id=UOmegaFunctions_Entity::Conv_Name_2_EntityID(GlobalNameId);
	}

	if(AssetSquad)
	{
		AssetSquad->bBindToSave=true;
		AssetSquad->SaveBinding=GlobalNameId;
	}

	if(EntityInstances)
	{
		EntityInstances->Instance_NamePrefex="E__";
		EntityInstances->InstancedActorClass=AOmegaInstancedEntity::StaticClass();
	}
	
	if(Calendar)
	{
		Calendar->bBindToSave=true;
		Calendar->SaveBinding=GlobalNameId;
		static ConstructorHelpers::FObjectFinder<UOAsset_Calendar> CalendarAssetFinder(TEXT("/OmegaGameFramework/DataAssets/Calendar/Calendar/Calendar_Earth.Calendar_Earth"));
		if (CalendarAssetFinder.Succeeded()) Calendar->CalendarAsset = CalendarAssetFinder.Object;
	}
}


void AOmegaGameMode::Local_ActivatePersistentSystems()
{
	UOmegaSubsystem_World* SystemRef = GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : PersistentGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "PersistentSystem");
	}
}

void AOmegaGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	//Fire OnLevelOpened Delegate
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaSubsystem_GameInstance>()->OnNewLevel.Broadcast(UGameplayStatics::GetCurrentLevelName(this), this);
	UOmegaSubsystem_World* SystemRef = GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : AutoGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "GameMode_PreLoad");
	}

	if(LoadGameplaySystem)
	{
		if(AOmegaGameplaySystem* TempLoadSys = SystemRef->ActivateGameplaySystem(LoadGameplaySystem, this, "GameMode_Load"))
		{
			TempLoadSys->OnSystemShutdown.AddDynamic(this, &AOmegaGameMode::Local_LoadSystemShutdown);
		}
		else
		{
			Local_LoadSystemShutdown(this, "NONE");
		}
	}
	else
	{
		Local_LoadSystemShutdown(this, "NONE");
	}

	GetWorld()->GetTimerManager().SetTimer(PersistentSystemsTimerHandle, this, &AOmegaGameMode::Local_ActivatePersistentSystems, PersistentSystemActivationFrequency, true);

	
}

void AOmegaGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	if(AOmegaPlayer* p=Cast<AOmegaPlayer>(NewPlayer))
	{
		//p->Systems_Auto.Append(PlayerSystems_Auto);
		//p->SetSystemsActive(PlayerSystems_Auto,this,"Auto",true);
		//p->Systems_Persistent.Append(PlayerSystems_Auto);
	}
	
	if (ULocalPlayer* _lp=NewPlayer->GetLocalPlayer())
	{
		if (bAutoActivateDynamicCamera)
		{
			if (UOmegaSubsystem_Player* _subsys=_lp->GetSubsystem<UOmegaSubsystem_Player>())
			{
				_subsys->DynaCam_SetActive(bAutoActivateDynamicCamera);
				if (DefaultDynamicCamera)
				{
					AOmegaDynamicCamera* _NewCam=GetWorld()->SpawnActorDeferred<AOmegaDynamicCamera>(DefaultDynamicCamera,NewPlayer->GetLevelTransform());
					_NewCam->restricted_players.AddUnique(NewPlayer);
					_NewCam->FinishSpawning(NewPlayer->GetLevelTransform());
				}
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
	ss_world=OGF_Subsystems::oWorld(this);
	
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
	if(ss_world)
	{
		for (auto* sys : ss_world->GetActiveGameplaySystems())
		{
			if(sys) { sys->OnHUDDraw(this); }
		}
	}
	
}

