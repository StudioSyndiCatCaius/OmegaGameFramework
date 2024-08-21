// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_CombatEncounter.h"

#include "Functions/OmegaFunctions_Common.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"


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
	TArray<AActor*> tempActors;
	UGameplayStatics::GetAllActorsOfClass(this,AOmegaCombatEncounter_Stage::StaticClass(),tempActors);
	for(auto* tempactor : tempActors) { REF_StageList.Add(Cast<AOmegaCombatEncounter_Stage>(tempactor)); } 
	Super::BeginPlay();
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

AOmegaCombatEncounter_Instance* UOmegaCombatEncounter_Component::StartEncounter(
	TSubclassOf<AOmegaCombatEncounter_Instance> EncounterClass,AOmegaCombatEncounter_Stage* Stage)
{
	if(!REF_Instance && EncounterClass && Stage)
	{
		REF_Stage=Stage;
		REF_Instance = GetWorld()->SpawnActorDeferred<AOmegaCombatEncounter_Instance>(EncounterClass,FTransform());
		REF_Instance->FinishSpawning(Stage->GetActorTransform());
		return  REF_Instance;
	}
	return nullptr;
}

AOmegaCombatEncounter_Instance* UOmegaCombatEncounter_Component::StartEncounter_FromSource(UObject* Source)
{
	if(Source && Source->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
	{
		return StartEncounter(
			IDataInterface_CombatEncounter::Execute_GetCombatEncounter_InstanceClass(Source),
			GetStageFromID(IDataInterface_CombatEncounter::Execute_GetCombatEncounter_StageID(Source)));
	}
	return nullptr;
}

bool UOmegaCombatEncounter_Component::EndEncounter()
{
	if(REF_Instance)
	{
		REF_Instance->K2_DestroyActor();
		return true;
	}
	return false;
}

ACharacter* UOmegaCombatEncounter_Component::SpawnBattler(UPrimaryDataAsset* DataAsset, UOmegaFaction* Faction,
                                                          FTransform Transform)
{
	if(REF_Instance)
	{
		if(BattlerCharacterClass)
		{
			ACharacter* new_char= GetWorld()->SpawnActorDeferred<ACharacter>(BattlerCharacterClass,Transform,REF_Instance);
			if(UCombatantComponent* comb_ref = new_char->FindComponentByClass<UCombatantComponent>())
			{
				new_char->FinishSpawning(Transform);
				REF_BattlerCombatants.Add(comb_ref);
				if(DataAsset) { comb_ref->CombatantDataAsset=DataAsset; }
				if(Faction) { comb_ref->FactionDataAsset=Faction; }
				return new_char;
			}
			GetWorld()->DestroyActor(new_char);
		}
	}
	return nullptr;
}
