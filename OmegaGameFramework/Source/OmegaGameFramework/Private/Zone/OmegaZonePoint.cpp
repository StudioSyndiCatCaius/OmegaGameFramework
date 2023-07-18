// Fill out your copyright notice in the Description page of Project Settings.


// Sets default values

#include "Zone/OmegaZonePoint.h"

#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Texture2D.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Zone/OmegaZoneSubsystem.h"

AOmegaZoneTransit::AOmegaZoneTransit()
{
	//Setup Root Billboard
	UBillboardComponent* RootRef = CreateDefaultSubobject<UBillboardComponent>("RootBillboard");
	
	UTexture2D* TextureBill = LoadObject<UTexture2D>(GetTransientPackage(), TEXT("/OmegaGameFramework/Textures/Kenny/icons/board/structure_house.structure_house"));
	RootRef->SetSprite(TextureBill);
	
	Box_Transit = CreateOptionalDefaultSubobject<UBoxComponent>("Transit Box");
	Box_Notify = CreateOptionalDefaultSubobject<UBoxComponent>("Notify Box");
	
	if(Box_Transit)
	{
		Box_Transit->SetupAttachment(RootRef);
		Box_Transit->ShapeColor = FColor(255, 0, 0);
		Box_Transit->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Box_Transit->OnComponentBeginOverlap.AddDynamic(this, &AOmegaZoneTransit::OnBoxTransitOverlapBegin);
	}
	if(Box_Notify)
	{
		Box_Notify->SetupAttachment(RootRef);
		Box_Notify->ShapeColor = FColor(0, 0, 255);
		Box_Notify->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Box_Notify->OnComponentBeginOverlap.AddDynamic(this, &AOmegaZoneTransit::OnBoxNotifyOverlapBegin);
		Box_Notify->OnComponentEndOverlap.AddDynamic(this, &AOmegaZoneTransit::OnBoxNotifyOverlapEnd);
	}
	UpdateBoxes();


	// Create TextComponent
	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComponent"));
	if(TextComponent)
	{
		TextComponent->SetupAttachment(RootRef);
		TextComponent->SetTextRenderColor(FColor::White);
		TextComponent->SetHorizontalAlignment(EHTA_Center);
		TextComponent->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
		TextComponent->SetHiddenInGame(true);
	}
}

void AOmegaZoneTransit::BeginPlay()
{
	Box_Transit->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Box_Notify->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	
	SubsysRef = GetWorld()->GetSubsystem<UOmegaZoneSubsystem>();
	//GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->ZonePoints.AddUnique(this);
	
}

void AOmegaZoneTransit::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}


void AOmegaZoneTransit::OnConstruction(const FTransform& Transform)
{
	UpdateBoxes();

	// Set the material for TextComponent
	
	
	FString Text;
	if (bTransitToLevel)
	{
		// Get the current level name
		FString CurrentLevelName;
		if(TransitLevel)
		{
			CurrentLevelName = TransitLevel.GetAssetName();
		}

		// Set the text for TextComponent
		Text = FString::Printf(TEXT("Transit Level: %s"), *CurrentLevelName);
	}
	else
	{
		FString TempTransitName;
		if(TransitPoint)
		{
			TempTransitName = TransitPoint->GetName();
		}
		// Set the text for TextComponent
		Text = FString::Printf(TEXT("Transit Zone: %s"), *TempTransitName);
		
	}
	
	TextComponent->SetText(FText::FromString(Text));
	Super::OnConstruction(Transform);
}

// BEGIN TRANSITION
void AOmegaZoneTransit::OnBoxTransitOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if(!PlayerPawn)
	{
		return;
	}
	APlayerController* MyPlayerController = Cast<APlayerController>(PlayerPawn->GetController());
	UE_LOG(LogTemp, Warning, TEXT("Begin Zone Transit"));
	if (MyPlayerController)
	{
		if (OtherActor == PlayerPawn)
		{
			if(bTransitToLevel)
			{
				UE_LOG(LogTemp, Warning, TEXT("Attempt Level Transit: %s"), *TransitLevel.GetAssetName());
				SubsysRef->TransitPlayerToLevel(TransitLevel,LevelTransitID);
			}
			else
			{
				FString TransitAppendName;
				if(TransitPoint)
				{
					TransitAppendName = TransitPoint->GetName();
				}
				UE_LOG(LogTemp, Warning, TEXT("Attempt Spawn Transit: %s"), *TransitAppendName);
				SubsysRef->TransitPlayerToPoint(TransitPoint,MyPlayerController);
			}
		}
	}
}

//----------------------------------------
// Transit Notify
//----------------------------------------
void AOmegaZoneTransit::OnBoxNotifyOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->OnZoneTransitInRange.Broadcast(this,true);
}

void AOmegaZoneTransit::OnBoxNotifyOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->OnZoneTransitInRange.Broadcast(this,false);
}


void AOmegaZoneTransit::UpdateBoxes()
{
	Box_Transit->InitBoxExtent(FVector(50,Box_Y,Box_X));
	Box_Notify->InitBoxExtent(FVector(200,Box_Y,Box_X));
}

//################################################################################################################
//ZONE POINT
//################################################################################################################

void AOmegaZonePoint::BeginPlay()
{
	const FVector TempVec = GetActorLocation()+FVector(0,0,1);
	SetActorLocation(TempVec);
	GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->ZonePoints.Add(this);
	Super::BeginPlay();
}

void AOmegaZonePoint::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->ZonePoints.Remove(this);
}

AOmegaZonePoint::AOmegaZonePoint()
{
	UCapsuleComponent* CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	if(CapsuleComponent)
	{
		CapsuleComponent->InitCapsuleSize(45,90);
	}
}

void AOmegaZonePoint::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name = PointName;
}

