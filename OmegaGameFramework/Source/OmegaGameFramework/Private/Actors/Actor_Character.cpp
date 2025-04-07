// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Character.h"

#include "OmegaSettings_Gameplay.h"
#include "Kismet/KismetSystemLibrary.h"

void AOmegaBaseCharacter::OnConstruction(const FTransform& Transform)
{
	if(Config && ActorConfig)
	{
		ActorConfig->SetConfig(Config);
	}
	else if(UOmegaSettings_Gameplay* set = UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		ActorConfig->SetConfig(set->DefaultActorConfig_Character);
	}
	Super::OnConstruction(Transform);
	FVector bound_origin;
	FVector bound_ext;
	float	bound_rad;
	UKismetSystemLibrary::GetComponentBounds(GetMesh(),bound_origin,bound_ext,bound_rad);
	// if(BoundsComponent) { BoundsComponent->SetBoxExtent(bound_ext); }
}

AOmegaBaseCharacter::AOmegaBaseCharacter()
{
	// BoundsComponent=CreateOptionalDefaultSubobject<UBoxComponent>("Bounds");
	// BoundsComponent->SetupAttachment(RootComponent);
	ActorConfig=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");
}
