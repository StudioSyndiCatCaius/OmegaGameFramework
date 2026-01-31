// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_CombatEncounter.h"

#include "LevelSequence.h"
#include "OmegaSettings.h"
#include "Components/Component_Combatant.h"
#include "OmegaGameplayConfig.h"
#include "Functions/F_Common.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_BGM.h"

UWorld* UOmegaCombatEncounterScript::GetWorld() const { return WorldPrivate; }
UGameInstance* UOmegaCombatEncounterScript::GetGameInstance() const { return WorldPrivate->GetGameInstance(); }
UOmegaCombatEncounterScript::UOmegaCombatEncounterScript(const FObjectInitializer& ObjectInitializer) { if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); } }

UOmegaCombatEncounter_Component* UOmegaCombatEncounterScript::GetOwningComponent() const
{
	if(UOmegaCombatEncounter_Component* out_comp = Cast<UOmegaCombatEncounter_Component>(GetOuter()))
	{
		return out_comp;
	}
	return nullptr;
}

FTransform AOmegaCombatEncounter_Stage::GetTransformForBattler_Implementation(FGameplayTag FactionTag, int32 index)
{
	for (UActorComponent* TempComp : K2_GetComponentsByClass(USceneComponent::StaticClass()))
	{
		if(USceneComponent* scenComp=Cast<USceneComponent>(TempComp))
		{
			if(scenComp && scenComp->ComponentHasTag("BattlerPoint") && scenComp->ComponentHasTag(FName(*UOmegaGameFrameworkBPLibrary::GetLastGameplayTagString(FactionTag))))
			{
				return scenComp->GetComponentTransform();
			}
		}
	}
	return FTransform();
}



void UOmegaCombatEncounter_Component::BeginPlay()
{
	REF_Stage=nullptr;
	REF_Instance=nullptr;
	if(EncounterManagerScript)
	{
		EncounterManagerScript->WorldPrivate=GetWorld();
	}
	TArray<AActor*> tempActors;
	UGameplayStatics::GetAllActorsOfClass(this,AOmegaCombatEncounter_Stage::StaticClass(),tempActors);
	for(auto* tempactor : tempActors) { REF_StageList.Add(Cast<AOmegaCombatEncounter_Stage>(tempactor)); } 
	Super::BeginPlay();
}

void UOmegaCombatEncounter_Component::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Type::Destroyed || EndPlayReason==EEndPlayReason::Type::RemovedFromWorld)
	{
		EndEncounter();
	}
	Super::EndPlay(EndPlayReason);
}

UOmegaCombatEncounter_Component::UOmegaCombatEncounter_Component()
{
}

TArray<AOmegaCombatEncounter_Stage*> UOmegaCombatEncounter_Component::GetAllStages()
{
	return REF_StageList;
}

AOmegaCombatEncounter_Stage* UOmegaCombatEncounter_Component::GetStageFromID(FGameplayTag ID)
{
	for(auto* tempStage : GetAllStages())
	{
		if(tempStage && tempStage->StageID==ID)
		{
			return tempStage;
		}
	}
	return nullptr;
}

ULevelSequence* UOmegaCombatEncounter_Component::GetEncounter_SequenceIntro() const
{
	if(REF_Instance && REF_Instance->OverrideSequence_Intro)
	{
		return REF_Instance->OverrideSequence_Intro;
	}
	if(encounter_source && encounter_source->GetClass()->ImplementsInterface(UDataInterface_CombatEncounter::StaticClass()))
	{
		if(ULevelSequence* _U=IDataInterface_CombatEncounter::Execute_GetCombatEncounter_IntroSequence(encounter_source))
		{
			return _U;
		}
	}
	return Default_SequenceIntro;
}

UOmegaBGM* UOmegaCombatEncounter_Component::GetEncounter_BGM() const
{
	
	if(REF_Instance && REF_Instance->OverrideBGM)
	{
		return REF_Instance->OverrideBGM;
	}
	if(encounter_source && encounter_source->GetClass()->ImplementsInterface(UDataInterface_CombatEncounter::StaticClass()))
	{
		if(UOmegaBGM* _bgm=IDataInterface_CombatEncounter::Execute_GetCombatEncounter_BGM(encounter_source))
		{
			return _bgm;
		}
	}
	return Default_BGM;
}

AOmegaCombatEncounter_Instance* UOmegaCombatEncounter_Component::StartEncounter(
	TSubclassOf<AOmegaCombatEncounter_Instance> EncounterClass,AOmegaCombatEncounter_Stage* Stage)
{
	if(!REF_Instance && EncounterClass && Stage)
	{
		REF_Stage=Stage;
		REF_Instance = GetWorld()->SpawnActorDeferred<AOmegaCombatEncounter_Instance>(EncounterClass,FTransform());
		REF_Instance->FinishSpawning(Stage->GetActorTransform());
		if(EncounterManagerScript)
		{
			EncounterManagerScript->OnEncounterStarted(REF_Instance,REF_Stage);
		}
		
		return  REF_Instance;
	}
	return nullptr;
}

AOmegaCombatEncounter_Instance* UOmegaCombatEncounter_Component::StartEncounter_FromSource(UObject* Source)
{
	if(Source && Source->GetClass()->ImplementsInterface(UDataInterface_CombatEncounter::StaticClass()))
	{
		encounter_source=Source;
		AOmegaCombatEncounter_Instance* new_inst =StartEncounter(
			IDataInterface_CombatEncounter::Execute_GetCombatEncounter_InstanceClass(Source),
			GetStageFromID(IDataInterface_CombatEncounter::Execute_GetCombatEncounter_StageID(Source)));
		IDataInterface_CombatEncounter::Execute_OnEncounterBegin(Source,this);
		return new_inst;
	}
	return nullptr;
}

bool UOmegaCombatEncounter_Component::EndEncounter()
{
	if(REF_Instance)
	{
		for(auto* b : REF_BattlerCombatants)
		{
			if(b)
			{
				b->GetOwner()->K2_DestroyActor();
			}
		}
		REF_Instance->K2_DestroyActor();
		if(EncounterManagerScript)
		{
			EncounterManagerScript->OnEncounterEnded(REF_Instance,REF_Stage);
		}
		return true;
	}
	return false;
}

ACharacter* UOmegaCombatEncounter_Component::SpawnBattler(UPrimaryDataAsset* DataAsset, UOmegaFaction* Faction,
                                                          FTransform Transform, ESpawnActorCollisionHandlingMethod CollisionMethod)
{
	TSubclassOf<ACharacter> in_class=BattlerCharacterClass;
	if (TSubclassOf<ACharacter> _NewClass= GetMutableDefault<UOmegaSettings>()->Default_EncounterCharacter.LoadSynchronous())
	{
		in_class=_NewClass;
	}
	if(REF_Instance)
	{
		if(in_class)
		{
			ACharacter* new_char= GetWorld()->SpawnActorDeferred<ACharacter>(in_class,Transform,REF_Instance,nullptr,CollisionMethod);
			if(UCombatantComponent* comb_ref = new_char->FindComponentByClass<UCombatantComponent>())
			{
				for(TSubclassOf<AOmegaAbility> temp_ability : ExtraBattlerAbilities)
				{
					if(temp_ability)
					{
						comb_ref->SetAbilityGranted(temp_ability,true);
					}
				}
				new_char->FinishSpawning(Transform);
				REF_BattlerCombatants.Add(comb_ref);
				if(DataAsset) { comb_ref->SetSourceDataAsset(DataAsset); }
				if(Faction) { comb_ref->SetFaction_Asset(Faction); }
				if(EncounterManagerScript)
				{
					EncounterManagerScript->OnBattlerSpawned(new_char,comb_ref);
				}
				OnEncounterSpawned.Broadcast(new_char);
				if(new_char->GetClass()->ImplementsInterface(UActorInterface_EncounterBattler::StaticClass()))
				{
					IActorInterface_EncounterBattler::Execute_OnBattlerInit(new_char,this,DataAsset,Faction);
				}
				return new_char;
			}
			GetWorld()->DestroyActor(new_char);
		}
	}
	return nullptr;
}

AOmegaCombatEncounter_Stage* UOmegaCombatEncounter_Component::GetCurrent_Stage() const
{
	return REF_Stage;
}

AOmegaCombatEncounter_Instance* UOmegaCombatEncounter_Component::GetCurrent_Encounter() const
{
	return REF_Instance;
}

void UOmegaCombatEncounter_Component::SetXP(float xp)
{
	encounter_xp=xp;
}

void UOmegaCombatEncounter_Component::AddXP(float xp)
{
	SetXP(encounter_xp+xp);
}

float UOmegaCombatEncounter_Component::GetXP() const
{
	return encounter_xp;
}

bool UOmegaEncounter_Asset::OnEncounterBegin_Implementation(UOmegaCombatEncounter_Component* Component)
{
	if(Script)
	{
		Script->OnEncounterBegin(Component);
		return true;
	}
	return false;
}
