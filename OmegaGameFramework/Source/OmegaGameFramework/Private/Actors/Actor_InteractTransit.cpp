// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_InteractTransit.h"

#include "UObject/ConstructorHelpers.h"
#include "Actors/Actor_Zone.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TextRenderComponent.h"
#include "DataAssets/DA_Zone.h"
#include "Functions/F_Common.h"
#include "Functions/F_Component.h"
#include "Subsystems/Subsystem_World.h"


FText AInteractTransit::L_GetName()
{
	return UDataInterface_General::GetObjectName(UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(this)->Zone_GetLevelData(TransitLevel),FGameplayTag());
}

AInteractTransit::AInteractTransit()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Range=CreateOptionalDefaultSubobject<UBoxComponent>("Range");
	Range->SetupAttachment(RootComponent);
	Range->SetBoxExtent(FVector::One()*100);
	Range->SetLineThickness(5);
	Range->ShapeColor=FColor::Yellow;
	SpawnPoint=CreateOptionalDefaultSubobject<UChildActorComponent>("SpawnPoint");
	SpawnPoint->SetupAttachment(RootComponent);
	Capsule=CreateOptionalDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->ShapeColor=FColor::Yellow;
	Capsule->SetupAttachment(SpawnPoint);
	SpawnArrow=CreateOptionalDefaultSubobject<UArrowComponent>("SpawnArrow");
	SpawnArrow->ArrowColor=FColor::Yellow;
	SpawnArrow->SetupAttachment(SpawnPoint);
	comp_text=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
	comp_text->SetupAttachment(RootComponent);
	comp_text->SetRelativeLocation(FVector(0,0,50));
	UOmegaComponentModifierFunctions::SetTextComponentType_Util(comp_text);

	UpwardArrow=CreateOptionalDefaultSubobject<UArrowComponent>("UpwardArrow");
	UpwardArrow->SetupAttachment(RootComponent);
	UpwardArrow->ArrowColor=FColor::Cyan;
	UpwardArrow->bIsEditorOnly=true;
	UpwardArrow->ArrowSize=6;
	UpwardArrow->ArrowLength=500;
	UpwardArrow->SetRelativeRotation(FRotator(90,0,0));

	UpwardIcon=CreateOptionalDefaultSubobject<UBillboardComponent>("UpwardIcon");
	UpwardIcon->SetupAttachment(RootComponent);
	UpwardIcon->SetRelativeLocation(FVector(0,0,3000));
	UpwardIcon->SetRelativeScale3D(FVector(6,6,6));
	static ConstructorHelpers::FObjectFinder<UTexture2D> UpwardIconFinder(TEXT("/OmegaGameFramework/Textures/Kenny/icons/board/exploding.exploding"));
	if (UpwardIconFinder.Succeeded()) UpwardIcon->SetSprite(UpwardIconFinder.Object);
	
#if WITH_EDITOR
	bIsSpatiallyLoaded=false;
#endif
}

void AInteractTransit::OnConstruction(const FTransform& Transform)
{
	if(SpawnPoint)
	{
		SpawnPoint->SetRelativeLocation(SpawnLocation);
	}
	if(comp_text)
	{
		comp_text->SetText(L_GetName());
	}
	Super::OnConstruction(Transform);
}

void AInteractTransit::BeginPlay()
{
	if(SpawnPoint)
	{
		SpawnPoint->SetChildActorClass(AOmegaZonePoint::StaticClass());
		if(AOmegaZonePoint* p=Cast<AOmegaZonePoint>(SpawnPoint->GetChildActor()))
		{
			p->FromLevel=TransitLevel;
			p->ZonePointID=SpawnTag;
		}
	}
	Super::BeginPlay();
}

void AInteractTransit::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name,
                                                         FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	Name=L_GetName();
	Label=GetName();
}

bool AInteractTransit::IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	return IActorInterface_Interactable::IsInteractionBlocked_Implementation(InteractInstigator, Tag, Context);
}

void AInteractTransit::OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if(APawn* p=Cast<APawn>(InteractInstigator))
	{
		if(p->IsPlayerControlled())
		{
			UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(this)->Zone_TransitToLevel(TransitLevel,SpawnTag);
		}
	}
}
