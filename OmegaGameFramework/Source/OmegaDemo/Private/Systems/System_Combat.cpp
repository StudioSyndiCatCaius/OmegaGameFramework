// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/System_Combat.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "Components/Component_CombatEncounter.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_TurnBasedManager.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"

// ----------------------------------------------------------------------
// Combat Instance
// ----------------------------------------------------------------------

void ASystemBASE_CombatInstance::N_BattleStart()
{
}

void ASystemBASE_CombatInstance::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	if(GetSequence_PreSetup())
	{
		ULevelSequencePlayer::CreateLevelSequencePlayer(this,GetSequence_PreSetup(),FMovieSceneSequencePlaybackSettings(),seqPlayer_preStart);
		seqPlayer_preStart->GetSequencePlayer()->OnFinished.AddDynamic(this,&ASystemBASE_CombatInstance::L_SeqFinished_PreStart);
	}
	else
	{
		L_SeqFinished_PreStart();
	}
	
	Super::SystemActivated_Implementation(Context, Flag);
}

void ASystemBASE_CombatInstance::L_SeqFinished_PreStart()
{
	Encounter_Component->StartEncounter_FromSource(ContextObject);
	if(GetSequence_PostSetup())
	{
		ULevelSequencePlayer::CreateLevelSequencePlayer(this,GetSequence_PostSetup(),FMovieSceneSequencePlaybackSettings(),seqPlayer_postStart);
		seqPlayer_postStart->GetSequencePlayer()->OnFinished.AddDynamic(this,&ASystemBASE_CombatInstance::L_SeqFinished_PostStart);
	}
	else
	{
		L_SeqFinished_PostStart();
	}
}

void ASystemBASE_CombatInstance::L_SeqFinished_PostStart()
{
	N_BattleStart();
}

ASystemBASE_CombatInstance::ASystemBASE_CombatInstance()
{
	Encounter_Component=CreateOptionalDefaultSubobject<UOmegaCombatEncounter_Component>("Encounter");
	Scores_Component=CreateOptionalDefaultSubobject<UDataAssetCollectionComponent>("Scores");
	XP_Component=CreateOptionalDefaultSubobject<ULevelingComponent>("XP");
}

// ----------------------------------------------------------------------
// Combat TurnBased
// ----------------------------------------------------------------------

ASystemBASE_Combat_TurnBased::ASystemBASE_Combat_TurnBased()
{
	TurnManager_Component=CreateOptionalDefaultSubobject<UTurnBasedManagerComponent>("TurnManager");

	TurnManager_Component->OnTurnFail.AddDynamic(this,&ASystemBASE_Combat_TurnBased::N_TurnFail);
}

void ASystemBASE_Combat_TurnBased::N_BattleStart()
{
	FString fail_reason;
	TurnManager_Component->NextTurn(true,"",FGameplayTagContainer(),fail_reason);
}

void ASystemBASE_Combat_TurnBased::N_TurnFail(FString Reason)
{
	if(TurnFailSystems.Contains(Reason))
	{
		if(UOmegaGameplaySubsystem* sys=GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>())
		{
			l_sysTurnFail=sys->ActivateGameplaySystem(TurnFailSystems[Reason],this);
			l_sysTurnFail->OnSystemShutdown.AddDynamic(this,&ASystemBASE_Combat_TurnBased::L_SystemFailEnd);
		}
	}
}

void ASystemBASE_Combat_TurnBased::L_SystemFailEnd(UObject* Context, FString Flag)
{
	Shutdown(Context,Flag);
}