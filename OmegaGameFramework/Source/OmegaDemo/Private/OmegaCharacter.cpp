// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaCharacter.h"

#include "LuaConst.h"
#include "LuaSubsystem.h"
#include "Components/AudioComponent.h"
#include "Functions/F_Combatant.h"
#include "OmegaSettings.h"
#include "OmegaGameplayConfig.h"
#include "Actors/Actor_Zone.h"
#include "Camera/CameraComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Component_CombatantExtension.h"
#include "Components/Component_DataWidget.h"
#include "Components/Component_UtilMesh.h"
#include "Components/StateTreeComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Kismet/KismetMathLibrary.h"
#include "DataAssets/DA_Faction.h"
#include "Functions/F_Common.h"

class ULuaWorldSubsystem;

void AOmegaCharacter::OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UGameplayActorComponent* Component)
{
	if(IdentityAsset)
	{
		Combatant->SetSourceDataAsset(IdentityAsset);
		//UOmegaSkinFunctions::SetSkinFromAsset(SkinComponent,IdentityAsset);
	}
}

bool AOmegaCharacter::b_IdentityHasGeneralInterface() const
{
	if(ActorIdentity)
	{
		if(UPrimaryDataAsset* _da=ActorIdentity->GetIdentitySourceAsset())
		{
			if(_da && _da->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
			{
				return true;
			}
		}
	}
	return false;
}

void AOmegaCharacter::L_Camera_Update() const
{
	if(UseCameraPull)
	{
		if(CameraBoom)
		{
			FRotator _rot =UKismetMathLibrary::FindLookAtRotation(CameraPull,CameraBoom->GetRelativeLocation());
			CameraBoom->SetRelativeLocation(CameraOffset);
			CameraBoom->SetRelativeRotation(_rot);
			float _dis=UKismetMathLibrary::Vector_Distance(CameraBoom->GetRelativeLocation(),CameraPull);
			CameraBoom->TargetArmLength=_dis;
		}
	}
}

void AOmegaCharacter::N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset)
{
	ActorIdentity->SetIdentitySourceAsset(new_asset);
	OnActorIdentityChanged(new_asset,ActorIdentity);
}

void AOmegaCharacter::GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed,
	FOmegaClassNamedLists& named_lists)
{
	bitflags=Flags;
	named_lists=NamedLists;
	seed=Seed;
}

// Sets default values
AOmegaCharacter::AOmegaCharacter()
{
	//Super AOmegaCharacter();
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Combatant = CreateDefaultSubobject<UCombatantComponent>(TEXT("Combatant"));
	
	Saveable = CreateDefaultSubobject<UOmegaSaveableComponent>(TEXT("Saveable"));
	SaveVisibility = CreateDefaultSubobject<UOmegaSaveStateComponent>(TEXT("SaveVisibility"));
	ActorIdentity->PauseCategory=FGameplayTag::RequestGameplayTag(TEXT("Character.Type.Field"));
	ZoneEntity = CreateDefaultSubobject<UZoneEntityComponent>(TEXT("ZoneEntity"));
	LookAim = CreateDefaultSubobject<UAimTargetComponent>(TEXT("Aim Target"));
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bDoCollisionTest=false;
	//CameraBoom->bAutoActivate=false;
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	MainCamera->FieldOfView=55;
	MainCamera->SetupAttachment(CameraBoom);
	
	
	DataWidget = CreateDefaultSubobject<UDataWidgetComponent>(TEXT("GUI"));
	DataWidget->SetupAttachment(RootComponent);
	DataWidget->SetWidgetSpace(EWidgetSpace::Screen);
	
	ChildSlot=CreateOptionalDefaultSubobject<UChildActorComponent>(TEXT("Child Slot"));
	ChildSlot->SetupAttachment(GetMesh());

	AudioComponent=CreateOptionalDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(GetMesh());
	
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));

	ActorIdentity->OnActorIdentityChanged.AddDynamic(this, &AOmegaCharacter::OnActorIdentityChanged);

	// -- EDITOR ONLY --
	
	Text_Name = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Name"));
	Text_Name->SetupAttachment(RootComponent);
	if (UMaterial* _mat=LoadObject<UMaterial>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/m_UTIL_TextOutline.m_UTIL_TextOutline")))
	{
		Text_Name->SetMaterial(0,_mat);
	}
	Text_Name->HorizontalAlignment=EHTA_Center;
	Text_Name->WorldSize=40;
	Text_Name->VerticalAlignment=EVRTA_TextBottom;
	Text_Name->bHiddenInGame=true;
	Text_Name->bIsEditorOnly=true;

	Icon_Faction = CreateDefaultSubobject<UBillboardComponent>(TEXT("Icon Faction"));
	Icon_Faction->SetupAttachment(RootComponent);
	Icon_Faction->bIsEditorOnly=true;
	
	if(GetMesh())
	{
		FVector bounds_loc=GetMesh()->GetLocalBounds().BoxExtent;
		Text_Name->SetRelativeLocation(bounds_loc+FVector(0,0,140));
		if (Icon_Faction)
		{
			Icon_Faction->SetRelativeLocation(bounds_loc+FVector(0,0,110));
		}
	}

	GetCapsuleComponent()->ShapeColor=FColor::Cyan;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MatRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male.SK_MannequinDemo_Male"));
	GetMesh()->SetSkeletalMeshAsset(MatRef.Object);

}

void AOmegaCharacter::OnConstruction(const FTransform& Transform)
{
	L_Camera_Update();
	ActorIdentity->Local_RunConstruct();
	
	//corrective flow set. remove long term
	if (DialogueFlow.IsValid() && !ActorIdentity->DefaultFlow)
	{
		ActorIdentity->DefaultFlow=DialogueFlow;
		DialogueFlow=nullptr;
	}
	
	if(Combatant && Combatant->FactionDataAsset)
	{
		FSlateBrush _br=Combatant->FactionDataAsset->FactionIcon;
		if (Icon_Faction)
		{
			Icon_Faction->SetVisibility(false);
			if(UTexture2D* texture =Cast<UTexture2D>(_br.GetResourceObject()))
			{
				Icon_Faction->SetVisibility(true);
				Icon_Faction->SetSprite(texture);
			}
		}
	}
	if(Text_Name)
	{
		if(Combatant)
		{
			Text_Name->SetTextRenderColor(Combatant->GetFactionColor().ToFColorSRGB());	
		}
		Text_Name->SetText(UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(this,FGameplayTag()));	
	}
	
	Super::OnConstruction(Transform);
}


UFlowAsset* AOmegaCharacter::GetFlowAsset_Implementation(FGameplayTag Tag)
{
	if (UFlowAsset* _fl=Cast<UFlowAsset>(ActorIdentity->DefaultFlow.LoadSynchronous()))
	{
		return _fl;
	}
	return nullptr;
}

FVector AOmegaCharacter::GetAimTargetLocation_Implementation(const UAimTargetComponent* Component) const
{
	return GetMesh()->GetSocketLocation(LookAimSocketName);
}



// Called when the game starts or when spawned
void AOmegaCharacter::BeginPlay()
{
	Super::BeginPlay();
	//if(Leveling)
	//{
	//	Leveling->OnLevelUp.AddDynamic(this, &AOmegaCharacter::Local_LevelUpdate);
	//	Leveling->OnLevelDown.AddDynamic(this, &AOmegaCharacter::Local_LevelUpdate);
	//}
	//DataItem->OnDataItemChanged.AddDynamic(this, &AOmegaCharacter::Local_UpdateDataItem);
	if(DefaultEmote)
	{
		UOmegaAnimationFunctions::PlayEmoteAnimation(this,DefaultEmote);
	}

}



void AOmegaCharacter::Local_AddCombatantSource(UObject* Source)
{
	if(Source)
	{
		Combatant->SetAttributeModifierActive(Source,true);
		Combatant->SetSkillSourceActive(Source, true);
	}
}

// Called every frame
void AOmegaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AOmegaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



void AOmegaCharacter::Camera_Front()
{
	CameraPull=FVector(200,0,0)+CameraOffset;
	UseCameraPull=true;
	L_Camera_Update();
}




UOAsset_Appearance* AOmegaCharacter::GetAppearanceAsset_Implementation()
{
	if(ActorIdentity && ActorIdentity->GetIdentitySourceAsset() &&
		ActorIdentity->GetIdentitySourceAsset()->GetClass()->ImplementsInterface(UDataInterface_AppearanceSource::StaticClass()))
	{
		return IDataInterface_AppearanceSource::Execute_GetAppearanceAsset(ActorIdentity->GetIdentitySourceAsset());
	}
	return Super::GetAppearanceAsset_Implementation();
}

// ========================================================================================================
// Encounter Character
// ========================================================================================================


AOmegaEncounterCharacter::AOmegaEncounterCharacter()
{

	if (USkeletalMesh* mesh=GetMutableDefault<UOmegaSettings>()->CharacterMesh_Encounter.LoadSynchronous())
	{
		GetMesh()->SetSkeletalMesh(mesh);
	}
	
	SaveVisibility = CreateDefaultSubobject<UOmegaSaveStateComponent>(TEXT("SaveVisibility"));
	ZoneEntity = CreateDefaultSubobject<UZoneEntityComponent>(TEXT("ZoneEntity"));
	LookAim = CreateDefaultSubobject<UAimTargetComponent>(TEXT("Aim Target"));
	
	OverlapRange=CreateOptionalDefaultSubobject<UBoxComponent>("Box");
	OverlapRange->SetupAttachment(RootComponent);
	OverlapRange->ShapeColor=FColor::Red;
	UtilMesh=CreateOptionalDefaultSubobject<UUtilMeshComponent>("UtilMesh");
	UtilMesh->SetupAttachment(RootComponent);
#if WITH_EDITOR
	UtilMesh->SetStaticMesh(LoadObject<UStaticMesh>(this,TEXT("/OmegaGameFramework/Meshes/util/SM_UTIL_Battle.SM_UTIL_Battle")));
	UtilMesh->SetMaterial(0,LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/instances/MI_UTIL_BoundRotate_R.MI_UTIL_BoundRotate_R")));
#endif
	
	//UtilMesh->SetRelativeScale3D(FVector(0.6,0.6,0.6));
	
	//StageID=FGameplayTag::RequestGameplayTag(FName("Combat.Stage.Default"));
	GetCapsuleComponent()->ShapeColor=FColor::Red;
}

void AOmegaEncounterCharacter::OnConstruction(const FTransform& Transform)
{
	//BoundsComponent->SetOverlayColor(FColor::Red);
	Super::OnConstruction(Transform);
	if(GetMesh())
	{
		if(UtilMesh)
		{
			UtilMesh->SetBoundsZ(GetMesh(),30);
		}
		if(OverlapRange)
		{
			OverlapRange->SetBoxExtent(GetMesh()->Bounds.BoxExtent+FVector(15,15,5));
		}
	}
}

UOmegaEncounter_Asset* AOmegaEncounterCharacter::GetEncounterAsset() const
{
	if(UOmegaSubsystem_World*  sub=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
	{
		if(UOmegaZoneData* zoneDat=sub->GetWorldManager()->Zone_GetFirstLoaded())
		{
			if(zoneDat->Default_Encounter) { return zoneDat->Default_Encounter;}
		}
	}
	if(Encounter) { return Encounter; }
	return nullptr;
}

AOmegaReferenceCharacter::AOmegaReferenceCharacter()
{
	CustomTimeDilation=0;
	SetActorEnableCollision(false);
	//bIsSpatiallyLoaded=false;
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));

	if (USkeletalMesh* mesh=GetMutableDefault<UOmegaSettings>()->CharacterMesh_Reference.LoadSynchronous())
	{
		GetMesh()->SetSkeletalMesh(mesh);
	}
}

void AOmegaReferenceCharacter::BeginPlay()
{
	SetActorHiddenInGame(true);
	Super::BeginPlay();
}

AOmegaCinematicCharacter::AOmegaCinematicCharacter()
{
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	if (USkeletalMesh* mesh=GetMutableDefault<UOmegaSettings>()->CharacterMesh_Cinematic.LoadSynchronous())
	{
		GetMesh()->SetSkeletalMesh(mesh);
	}
}
