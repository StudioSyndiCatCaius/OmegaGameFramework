// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_FloatingCombatant.h"

#include "OmegaSettings_Gameplay.h"
#include "Functions/F_Common.h"

void AFloatingCombatant::OnConstruction(const FTransform& Transform)
{
	if(Combatant)
	{
		NameText->SetText(UDataInterface_General::GetObjectName(Combatant));
	}

	FVector forcedscale=FVector(1,1,1);
	if(NameText) { NameText->SetWorldScale3D(forcedscale); }
	
	Super::OnConstruction(Transform);
}

AFloatingCombatant::AFloatingCombatant()
{
	RangeBox=CreateDefaultSubobject<UBoxComponent>("Range");
	RangeBox->SetBoxExtent(FVector(100,100,100));
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	//ActorConfig=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");
	NameText=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
	NameText->HorizontalAlignment=EHTA_Center;
	NameText->SetupAttachment(RangeBox);
}
