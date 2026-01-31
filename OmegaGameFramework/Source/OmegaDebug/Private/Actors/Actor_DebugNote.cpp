// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_DebugNote.h"

#include "OmegaSettings.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/TextRenderComponent.h"
#include "Functions/F_Actor.h"
#include "Misc/OmegaUtils_Macros.h"

void AOmegaDebugNote::OnConstruction(const FTransform& Transform)
{
	UOmegaComponentFunctions::PointArrowComponentToTarget(Arrow,ArrowPoint);
	Arrow->SetArrowColor(Color);
	Text->SetText(Note);
	OGF_CFG()->OverrideActorLabel(this);
	Super::OnConstruction(Transform);
}

AOmegaDebugNote::AOmegaDebugNote()
{
	SetActorHiddenInGame(true);
	RootComponent=CreateDefaultSubobject<UBillboardComponent>("ROOT");
	Cast<UBillboardComponent>(RootComponent)->SetSprite(LoadObject<UTexture2D>(this, TEXT("/Engine/EditorResources/S_Note.S_Note")));
	Arrow=CreateOptionalDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetupAttachment(RootComponent);
	Arrow->ArrowSize=2;
	Text=CreateOptionalDefaultSubobject<UTextRenderComponent>("TEXT");
	Text->SetMaterial(0,OGF_UASSET_MAT_TEXT_OUTLINE());
	Text->SetupAttachment(RootComponent);
	Text->HorizontalAlignment=EHTA_Center;
	Text->SetRelativeLocation(FVector(0,0,50.0));
	Text->WorldSize=80;
	Text->VerticalAlignment=EVRTA_TextBottom;
}
