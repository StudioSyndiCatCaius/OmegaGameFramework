// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/comp_LevelEditor.h"


// Sets default values for this component's properties
UOmegaForgeComponent_LevelEditor::UOmegaForgeComponent_LevelEditor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOmegaForgeComponent_LevelEditor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOmegaForgeComponent_LevelEditor::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UOmegaForgeComponent_LevelEditor::CustomLevel_Load(FOmegaForge_LevelData LevelData)
{
}

void UOmegaForgeComponent_LevelEditor::CustomLevel_Save(FOmegaForge_LevelData LevelData)
{
}

void UOmegaForgeComponent_LevelEditor::CustomLevel_Unload(FOmegaForge_LevelData LevelData)
{
}

