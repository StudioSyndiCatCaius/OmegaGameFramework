// Fill out your copyright notice in the Description page of Project Settings.


// Sets default values

#include "Gameplay/AdvancedVolume/AdvancedVolume.h"

#include "Components/BillboardComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"

AAdvancedVolume::AAdvancedVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	const FAttachmentTransformRules DefaultRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
	SetActorHiddenInGame(false);
	
	USceneComponent* RootRef = CreateDefaultSubobject<USceneComponent>("VolumeRoot");

	CollisionType = ECollisionChannel::ECC_WorldDynamic;
	
	// Volume
	Volume = CreateOptionalDefaultSubobject<UStaticMeshComponent>("Volume");
	if(Volume)
	{
		Volume->SetupAttachment(RootRef);
		Volume->SetHiddenInGame(true);
	}
	
	// Text
	TextDisplay = CreateOptionalDefaultSubobject<UTextRenderComponent>("TextDisplay");
	if (TextDisplay)
	{
		TextDisplay->SetupAttachment(RootRef);
		static ConstructorHelpers::FObjectFinder<UMaterialInterface> TextMatRef(TEXT("/Engine/EngineMaterials/UnlitText.UnlitText"));
		TextDisplay->SetTextMaterial(TextMatRef.Object);
	}
	
	// Icon
	IconDisplay = CreateOptionalDefaultSubobject<UBillboardComponent>("IconDisplay");
	if (IconDisplay)
	{
		IconDisplay->SetupAttachment(RootRef);
	}
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShapeRef_Sphere(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	ShapeMeshRef_sphere = ShapeRef_Sphere.Object;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShapeRef_Box(TEXT("/Engine/BasicShapes/Cube.Cube"));
	ShapeMeshRef_box = ShapeRef_Box.Object;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatRef(TEXT("/OmegaGameFramework/Materials/m_trans.m_trans"));
	VolumeMaterial_ref = MatRef.Object;
}

// Called when the game starts or when spawned
void AAdvancedVolume::BeginPlay()
{
	Super::BeginPlay();
	Volume->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

// Called every frame
void AAdvancedVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAdvancedVolume::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	//------------------------------------Shape--------------------------------------//
	switch (Shape)
	{
	case EVolumeShape::OmegaVolume_Sphere: 
		Volume->SetStaticMesh(ShapeMeshRef_sphere);
		break;
	case EVolumeShape::OmegaVolume_Box:
		Volume->SetStaticMesh(ShapeMeshRef_box);
		break;
	default: ;
	}

	//Volume->SetCollisionObjectType(CollisionType);
	
	if(Volume)
	{
		Volume->SetGenerateOverlapEvents(true);
		UMaterialInstanceDynamic* LocalMatInst = Volume->CreateDynamicMaterialInstance(0, VolumeMaterial_ref);
		LocalMatInst->SetVectorParameterValue("Color", Color);
		LocalMatInst->SetScalarParameterValue("Opacity", 0.35);
	}
	
	
	//------------------------------------ICON--------------------------------------//
	if(GetVolumeIcon())
	{
		IconDisplay->SetSprite(GetVolumeIcon());
		IconDisplay->SetWorldLocation(GetActorLocation()+FVector(0,0,50));
		IconDisplay->SetWorldScale3D(FVector(1,1,1));
	}
	
	//------------------------------------Name--------------------------------------//
	if(TextDisplay)
	{
		TextDisplay->SetText(GetVolumeText());
		TextDisplay->SetWorldScale3D(FVector(1,1,1));
		TextDisplay->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextTop);
		TextDisplay->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	}
	
}
