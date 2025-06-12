// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Lootable.h"

#include "Components/Component_Inventory.h"

void AOmegaActor_Lootable::OnConstruction(const FTransform& Transform)
{
	
}
/*
void AOmegaActor_Lootable::OnInteraction_Implementation(AActor* Instigator, FGameplayTag Tag, UObject* Context)
{
	if(Instigator==GetWorld()->GetFirstPlayerController())
	{
		
	}
	IActorInterface_Interactable::OnInteraction_Implementation(Instigator, Tag, Context);
}
*/
AOmegaActor_Lootable::AOmegaActor_Lootable()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Mesh=CreateOptionalDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	
	Inventory=CreateOptionalDefaultSubobject<UDataAssetCollectionComponent>("Inventory");

}
