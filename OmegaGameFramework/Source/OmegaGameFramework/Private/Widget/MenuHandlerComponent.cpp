// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/MenuHandlerComponent.h"

#include "Player/OmegaPlayerSubsystem.h"


// Sets default values for this component's properties
UMenuHandlerComponent::UMenuHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMenuHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMenuHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UMenuHandlerComponent::OpenMenu(FGameplayTagContainer Tags)
{
	if(CastChecked<APlayerController>(GetOwner()->GetInstigatorController()) && IsValid(MenuClass))
	{
		APlayerController* TempController = Cast<APlayerController>(GetOwner()->GetInstigatorController());
		MenuObject = TempController->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->OpenMenu(MenuClass, GetOwner(), Tags, TEXT("MenuHandler"));
		return true;	
	}
	return false;
}

