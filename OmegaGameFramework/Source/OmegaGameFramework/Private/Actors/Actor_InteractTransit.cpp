// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_InteractTransit.h"

#include "Components/BillboardComponent.h"
#include "Components/TextRenderComponent.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Subsystems/OmegaSubsystem_Zone.h"


FText AInteractTransit::L_GetName() const
{
	return UDataInterface_General::GetObjectName(GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->GetLevelData(TransitLevel));
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
	if(UTexture2D* textr=LoadObject<UTexture2D>(this,TEXT("/OmegaGameFramework/Textures/Kenny/icons/board/exploding.exploding")))
	{
		UpwardIcon->SetSprite(textr);	
	}
	
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

void AInteractTransit::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                         FText& Description)
{
	Name=L_GetName();
	IDataInterface_General::GetGeneralDataText_Implementation(Label, Context, Name, Description);
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
			GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->TransitPlayerToLevel(TransitLevel,SpawnTag);
		}
	}
}
