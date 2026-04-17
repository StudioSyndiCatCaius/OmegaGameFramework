// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Zone.h"

#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "OmegaSettings.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Component_UtilMesh.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/TextRenderComponent.h"
#include "Functions/F_Common.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"


UZoneEntityComponent::UZoneEntityComponent()
{
	LegendAsset=LoadObject<UZoneLegendAsset>(nullptr, TEXT("/OmegaGameFramework/DEMO/Zone/Legend/Legend_SpawnPoint.Legend_SpawnPoint"));
}

void UZoneEntityComponent::BeginPlay()
{
	Super::BeginPlay();
	UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(this)->ZoneEntity_Register(this,true);
	TSubclassOf<AZoneEntityDisplayActor> inClass;
	if(DisplayActorClass)
	{
		inClass=DisplayActorClass;
	}
	else if (LegendAsset && LegendAsset->DefaultDisplayActor)
	{
		inClass=LegendAsset->DefaultDisplayActor;
	}
	if(TSubclassOf<AZoneEntityDisplayActor> tempClass = GetMutableDefault<UOmegaSettings>()->DefaultZoneEntityDisplayActor.LoadSynchronous())
	{
		inClass=tempClass;
	}
	if(inClass)
	{
		FTransform in_pos;
		Ref_DisplayActor= GetWorld()->SpawnActorDeferred<AZoneEntityDisplayActor>(inClass,in_pos,GetOwner());
		if (Ref_DisplayActor)
		{
			Ref_DisplayActor->owning_component=this;
			Ref_DisplayActor->FinishSpawning(in_pos);
			if (Ref_DisplayActor)
			{
				Ref_DisplayActor->AttachToActor(GetOwner(),FAttachmentTransformRules(EAttachmentRule::SnapToTarget,false));
			}
		}
		
		
	}
}

void UZoneEntityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(AOmegaWorldManager* m= UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(this))
	{
		m->ZoneEntity_Register(this,false);
	}
	if(Ref_DisplayActor)
	{
		Ref_DisplayActor->K2_DestroyActor();
	}
	Super::EndPlay(EndPlayReason);
}

AActor* UZoneEntityComponent::GetDisplayActor() const
{
	if(UseParentAsDisplayActor)
	{
		return GetOwner();
	}
	if(Ref_DisplayActor)
    {
    	return Ref_DisplayActor;
    }
    return nullptr;
}

FVector2D UZoneEntityComponent::GetPosition2D()
{
	return UKismetMathLibrary::Conv_VectorToVector2D(GetOwner()->GetActorLocation());
	
}

float UZoneEntityComponent::GetRotation2D()
{

	return GetOwner()->GetActorRotation().Yaw;
}

void UZoneEntityComponent::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	Name=DisplayName;
	Description=DisplayDescription;
}

void UZoneEntityComponent::GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture,
	class UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(LegendAsset)
	{
		Brush=LegendAsset->Icon;
	}
}


FGameplayTag UZoneEntityComponent::GetObjectGameplayCategory_Implementation()
{
	if(LegendAsset)
	{
		return LegendAsset->CategoryTag;
	}
	return FGameplayTag();
}

FGameplayTagContainer UZoneEntityComponent::GetObjectGameplayTags_Implementation()
{
	FGameplayTagContainer outTags=ExtraTags;
	if(LegendAsset)
	{
		outTags.AppendTags(LegendAsset->GameplayTags);
	}
	return outTags;
}

AZoneEntityViewCamera::AZoneEntityViewCamera()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	SpringArm=CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength=400;
	CameraComponent=CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArm);
	SceneCaptureComponent=CreateOptionalDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene Capture"));
	SceneCaptureComponent->SetupAttachment(CameraComponent);
	SceneCaptureComponent->PrimitiveRenderMode=ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
}

void AZoneEntityViewCamera::L_RefreshView()
{
	SceneCaptureComponent->ShowOnlyActors.Empty();
	for(UZoneEntityComponent* temp_entity : UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(this)->ZoneEntity_GetRegistered())
	{
		if(temp_entity &&
			IsLegendVisible(temp_entity->LegendAsset))
		{
			if(AActor* ac=temp_entity->GetDisplayActor())
			{
				if(L_ActorIsValidViewable(temp_entity->GetOwner()))
				{
					SceneCaptureComponent->ShowOnlyActors.Add(ac);
				}
			}
		}
	}
}

bool AZoneEntityViewCamera::L_ActorIsValidViewable(AActor* a) const
{
	if(a)
	{
		if(ViewFilterActors.IsEmpty()) { return true;}
		for(auto* _a : ViewFilterActors)
		{
			if(_a && (a->IsOverlappingActor(_a) || a==_a))
			{
				return true;
			}
		}
	}
	return false;
}

void AZoneEntityViewCamera::BeginPlay()
{
	Super::BeginPlay();
	L_RefreshView();
}

bool AZoneEntityViewCamera::IsLegendVisible(UZoneLegendAsset* Legend) const
{
	if(LegendVisibility.Contains(Legend))
	{
		return LegendVisibility[Legend];
	}
	return true;
}

void AZoneEntityViewCamera::SetLegendVisible(UZoneLegendAsset* Legend, bool bVisible)
{
	if(Legend)
	{
		LegendVisibility.Add(Legend,bVisible);
		L_RefreshView();
	}
}

void AZoneEntityViewCamera::SetViewFilterActorValid(AActor* Actor, bool ValidFilter)
{
	if(Actor)
	{
		if(ValidFilter && !ViewFilterActors.Contains(Actor))
		{
			ViewFilterActors.Add(Actor);
		}
		if(!ValidFilter && ViewFilterActors.Contains(Actor))
		{
			ViewFilterActors.Remove(Actor);
		}
		L_RefreshView();
	}
}

void AZoneEntityViewCamera::ClearAllViewFilterActors()
{
	ViewFilterActors.Empty();
	L_RefreshView();
}



// =============================================================================================================
// Zone Actors
// =============================================================================================================

AOmegaZoneTransit::AOmegaZoneTransit()
{
	//Setup Root Billboard
	UBillboardComponent* RootRef = CreateDefaultSubobject<UBillboardComponent>("RootBillboard");
	RootComponent=RootRef;
	Box_Transit = CreateOptionalDefaultSubobject<UBoxComponent>("Transit Box");
	Box_Notify = CreateOptionalDefaultSubobject<UBoxComponent>("Notify Box");
	Spawn_Point_Ref= CreateOptionalDefaultSubobject<USceneComponent>("SpawnPointReference");
	Spawn_Point_Ref->SetupAttachment(RootRef);
	
	if(Box_Transit)
	{
		Box_Transit->SetupAttachment(RootRef);
		Box_Transit->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Box_Transit->OnComponentBeginOverlap.AddDynamic(this, &AOmegaZoneTransit::OnBoxTransitOverlapBegin);
	}
	if(Box_Notify)
	{
		Box_Notify->SetupAttachment(RootRef);
		Box_Notify->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Box_Notify->OnComponentBeginOverlap.AddDynamic(this, &AOmegaZoneTransit::OnBoxNotifyOverlapBegin);
		Box_Notify->OnComponentEndOverlap.AddDynamic(this, &AOmegaZoneTransit::OnBoxNotifyOverlapEnd);
	}
	UpdateBoxes();


	// Create TextComponent
	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComponent"));
	if(TextComponent)
	{
		TextComponent->SetMaterial(0,LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/m_UTIL_TextOutline.m_UTIL_TextOutline")));
		TextComponent->SetupAttachment(RootRef);
		TextComponent->SetHorizontalAlignment(EHTA_Center);
		TextComponent->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
		TextComponent->SetHiddenInGame(true);
	}
	
	DirectionalArrow=CreateOptionalDefaultSubobject<UArrowComponent>("TransitDirection");
	if(DirectionalArrow)
	{
		DirectionalArrow->SetupAttachment(Capsule);
	
		DirectionalArrow->SetComponentTickEnabled(false);
	}
	DisplayEmitter=CreateOptionalDefaultSubobject<UNiagaraComponent>("Display");
	DisplayEmitter->SetupAttachment(RootComponent);

	UtilMesh=CreateOptionalDefaultSubobject<UUtilMeshComponent>("UtilMesh");
	UtilMesh->SetupAttachment(RootComponent);
#if WITH_EDITOR
	UtilMesh->SetStaticMesh(LoadObject<UStaticMesh>(this,TEXT("/OmegaGameFramework/Meshes/util/SM_UTIL_TransitPointer.SM_UTIL_TransitPointer")));
	
#endif
	UtilMesh->SetRelativeLocation(FVector(0,0,100));
	UtilMesh->SetRelativeScale3D(FVector(0.6,0.6,0.6));
	
	Capsule=CreateOptionalDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetupAttachment(RootComponent);

#if WITH_EDITOR
	bIsSpatiallyLoaded=false;
#endif
}

void AOmegaZoneTransit::BeginPlay()
{
	Box_Transit->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Box_Notify->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Spawn_Point_Ref->SetRelativeLocation(SpawnPointLocation);
	SubsysRef = GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	//GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->ZonePoints.AddUnique(this);

	if(bUseLinkedSpawnPoint)
	{
		TSubclassOf<AOmegaZonePoint> point_class=AOmegaZonePoint::StaticClass();
		if(ZoneSpawnPointClass)
		{
			point_class=ZoneSpawnPointClass;
		}
		
		
		linked_point = GetWorld()->SpawnActorDeferred<AOmegaZonePoint>(point_class,GetActorTransform(),this);
		if(linked_point)
		{
			linked_point->SetActorLocation(Spawn_Point_Ref->GetComponentLocation());
			linked_point->FromLevel=TransitLevel;
			linked_point->ZonePointID=LevelTransitID;
			linked_point->ZoneToLoad=SpawnZoneToLoad;
			linked_point->FinishSpawning(linked_point->GetActorTransform());
		}
	}
	
}

void AOmegaZoneTransit::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}


void AOmegaZoneTransit::OnConstruction(const FTransform& Transform)
{
	UpdateBoxes();

	FString Text;
	if (bTransitToLevel)
	{
		TextComponent->SetTextRenderColor(FColor::Purple);
		DirectionalArrow->ArrowColor=FColor::Purple;
		Capsule->ShapeColor=FColor::Purple;
		Box_Transit->ShapeColor=FColor::Purple;
		Box_Notify->ShapeColor=FColor::Blue;
#if WITH_EDITOR
		UtilMesh->SetMaterial(0,LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/instances/MI_UTIL_throbber_P.MI_UTIL_throbber_P")));
#endif
		
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
		TextComponent->SetTextRenderColor(FColor::Yellow);
		DirectionalArrow->ArrowColor=FColor::Yellow;
		Capsule->ShapeColor=FColor::Yellow;
		Box_Transit->ShapeColor=FColor::Yellow;
		Box_Notify->ShapeColor=FColor::Orange;
	
#if WITH_EDITOR
		UtilMesh->SetMaterial(0,LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/instances/MI_UTIL_throbber_Y.MI_UTIL_throbber_P")));
#endif
		FString TempTransitName;
		if(TransitPoint)
		{
			TempTransitName = TransitPoint->GetName();
		}
		// Set the text for TextComponent
		Text = FString::Printf(TEXT("Transit Zone: %s"), *TempTransitName);
	}
	if(DisplayEmitter)
	{
		if(UNiagaraSystem* sys=GetMutableDefault<UOmegaSettings>()->DefaultZoneTransitParticle.LoadSynchronous())
		{
			DisplayEmitter->SetAsset(sys);
		}
	}


	Capsule->SetRelativeLocation(SpawnPointLocation);
	TextComponent->SetText(FText::FromString(Text));
	Super::OnConstruction(Transform);
}

void AOmegaZoneTransit::OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context)
{

	IActorInterface_Interactable::OnInteraction_Implementation(InteractInstigator, Tag, Context);
}

bool AOmegaZoneTransit::IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	return true;
}

// BEGIN TRANSITION
void AOmegaZoneTransit::OnBoxTransitOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APawn* PlayerPawn = Cast<APawn>(OtherActor))
	{
		if(APlayerController* _player=Cast<APlayerController>(PlayerPawn->GetController()))
		{
			if(!CanPlayerTransit(PlayerPawn))
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to start transition: cannot transition this player pawn"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Begin Zone Transit"));
				if (_player)
				{
					if (OtherActor == PlayerPawn)
					{
						TriggerTransit(_player);
					}
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to start transition: invalid player"));
		}
	}
}

//----------------------------------------
// Transit Notify
//----------------------------------------
void AOmegaZoneTransit::OnBoxNotifyOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->OnZoneTransitInRange.Broadcast(this,true);
}

void AOmegaZoneTransit::OnBoxNotifyOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->OnZoneTransitInRange.Broadcast(this,false);
}


void AOmegaZoneTransit::TriggerTransit(APlayerController* Player)
{
	if(bTransitToLevel)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempt Level Transit: %s"), *TransitLevel.GetAssetName());
		SubsysRef->GetWorldManager()->Zone_TransitToLevel(TransitLevel,LevelTransitID);
	}
	else
	{
		AOmegaZonePoint* incoming_point=TransitPoint;
		if(TransitPoint_Linked && TransitPoint_Linked->GetLinkedSpawnPoint())
		{
			incoming_point= TransitPoint_Linked->GetLinkedSpawnPoint();
		}
		if(incoming_point)
		{
			const FString TransitAppendName = incoming_point->GetName();
			UE_LOG(LogTemp, Warning, TEXT("Attempt Spawn Transit: %s"), *TransitAppendName);
			SubsysRef->GetWorldManager()->Zone_Transit(incoming_point,Player);
		}
				
	}
}

bool AOmegaZoneTransit::CanPlayerTransit(APawn* PlayerPawn) const
{
	return true;
}

AOmegaZonePoint* AOmegaZoneTransit::GetLinkedSpawnPoint()
{
	if(linked_point)
	{
		return linked_point;
	}
	return nullptr;
}

void AOmegaZoneTransit::AutosetTransits()
{
	if(TransitPoint_Linked)
	{
		TransitPoint_Linked->TransitPoint_Linked=this;
	}
}

void AOmegaZoneTransit::UpdateBoxes()
{
	Box_Transit->InitBoxExtent(FVector(50,Box_X,Box_Y));
	Box_Notify->InitBoxExtent(FVector(200,Box_X,Box_Y));
}

//################################################################################################################
//ZONE POINT
//################################################################################################################

void AOmegaZonePoint::BeginPlay()
{
	const FVector TempVec = GetActorLocation()+FVector(0,0,1);
	SetActorLocation(TempVec);
	//GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->L_ZonePointEvent(this,0,true);
	Super::BeginPlay();
}

void AOmegaZonePoint::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->L_ZonePointEvent(this,0,false);
	Super::EndPlay(EndPlayReason);
}

AOmegaZonePoint::AOmegaZonePoint()
{
	UCapsuleComponent* CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	CapsuleComponent->ShapeColor=FColor::Yellow;
	CapsuleComponent->SetLineThickness(3);
	DirectionalArrow= CreateOptionalDefaultSubobject<UArrowComponent>("DirectionArrow");
	DirectionalArrow->ArrowColor=FColor::Yellow;
	ZoneEntityComponent= CreateOptionalDefaultSubobject<UZoneEntityComponent>("ZoneEntity");
	if(DirectionalArrow) { DirectionalArrow->SetupAttachment(CapsuleComponent); }
	if(CapsuleComponent)
	{
		CapsuleComponent->InitCapsuleSize(45,90);
	}
#if WITH_EDITOR
	bIsSpatiallyLoaded=false;
#endif
	
}

void AOmegaZonePoint::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	Name = PointName;
}




AZoneEntity_Mesh::AZoneEntity_Mesh()
{
	ZoneEntity=CreateOptionalDefaultSubobject<UZoneEntityComponent>("ZoneEntity");
	ZoneEntity->UseParentAsDisplayActor=true;
	AActor::SetActorHiddenInGame(true);
	if(GetStaticMeshComponent())
	{
		//GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetStaticMeshComponent()->CastShadow=false;
	}
}

void AZoneEntity_Mesh::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
	GetStaticMeshComponent()->bVisibleInSceneCaptureOnly=true;
}
