// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Character.h"

#include "OmegaSettings_Gameplay.h"
#include "Components/StateTreeComponent.h"
#include "DataAssets/DA_ActorModifierCollection.h"
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
		if(UOAsset_ActorModifierCollection* col=set->ActorMods_Character)
		{
			col->ApplyAllModifiers(this);
		}
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
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	
	ActorConfig=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");
	StateTree=CreateDefaultSubobject<UStateTreeComponent>(TEXT("State Tree"));
}
