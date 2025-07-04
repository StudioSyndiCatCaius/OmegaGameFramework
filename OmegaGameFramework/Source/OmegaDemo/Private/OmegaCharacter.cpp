// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaCharacter.h"

#include "Components/AudioComponent.h"
#include "Functions/OmegaFunctions_Combatant.h"
#include "OmegaMutable_Functions.h"
#include "OmegaSettings_Gameplay.h"
#include "Camera/CameraComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Component_CombatantExtension.h"
#include "Components/StateTreeComponent.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Kismet/KismetMathLibrary.h"


void AOmegaCharacter::OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UActorIdentityComponent* Component)
{
	if(IdentityAsset)
	{
		//if(IdentityAsset->GetClass()->IsChildOf(UOmegaDataItem::StaticClass())) { DataItem->SetDataItem(Cast<UOmegaDataItem>(IdentityAsset)); }
		Combatant->SetSourceDataAsset(IdentityAsset);
		UCombatantFunctions::SetCombatantFromSource(Combatant,IdentityAsset);
		UDataAssetCollectionFunctions::SetInventory_FromSource(Inventory,IdentityAsset);
		Equipment->SetEquipment_FromSource(IdentityAsset);
		UOmegaSkinFunctions::SetSkinFromAsset(SkinComponent,IdentityAsset);
		if(IdentityAsset && IdentityAsset->GetClass()->ImplementsInterface(UDataInterface_MutableSource::StaticClass()))
		{
			if(UCustomizableObjectInstance* inst = IDataInterface_MutableSource::Execute_GetCustomizableObjectInstance(IdentityAsset))
			{
				//if(USkeletalMesh* _mesh = inst->GetComponentMeshSkeletalMesh(MutableComponentName))
				//{
				//	GetMesh()->SetSkeletalMeshAsset(_mesh);
				//}
				//if(CustomSkelMesh) { CustomSkelMesh->SetCustomizableObjectInstance(inst); }
			}
		}
	}
}

bool AOmegaCharacter::b_IdentityHasGeneralInterface()
{
	if(UPrimaryDataAsset* _da=ActorIdentity->GetIdentitySourceAsset())
	{
		if(_da && _da->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
		{
			return true;
		}
	}
	return false;
}

void AOmegaCharacter::L_Camera_Update()
{
	if(UseCameraPull)
	{
		if(CameraBoom)
		{
			FRotator _rot =UKismetMathLibrary::FindLookAtRotation(CameraPull,CameraBoom->GetRelativeLocation());
			CameraBoom->SetRelativeRotation(_rot);
			float _dis=UKismetMathLibrary::Vector_Distance(CameraBoom->GetRelativeLocation(),CameraPull);
			CameraBoom->TargetArmLength=_dis;
		}
	}
}

// Sets default values
AOmegaCharacter::AOmegaCharacter()
{
	//Super AOmegaCharacter();
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ActorIdentity = CreateDefaultSubobject<UActorIdentityComponent>(TEXT("Actor Identity"));
	Combatant = CreateDefaultSubobject<UCombatantComponent>(TEXT("Combatant"));

	Equipment = CreateDefaultSubobject<UEquipmentComponent>(TEXT("Equipment"));
	Inventory = CreateDefaultSubobject<UDataAssetCollectionComponent>(TEXT("Inventory"));
	Leveling = CreateDefaultSubobject<ULevelingComponent>(TEXT("Leveling"));
	ActorState = CreateDefaultSubobject<UActorStateComponent>(TEXT("ActorState"));
	SaveVisibility = CreateDefaultSubobject<UOmegaSaveStateComponent>(TEXT("SaveVisibility"));
	SubscriptComponent = CreateDefaultSubobject<USubscriptComponent>(TEXT("Subscript"));
	SkinComponent = CreateDefaultSubobject<USkinComponent>(TEXT("Skin"));
	GameplayPause = CreateDefaultSubobject<UGameplayPauseComponent>(TEXT("GameplayPause"));
	ZoneEntity = CreateDefaultSubobject<UZoneEntityComponent>(TEXT("ZoneEntity"));
	LookAim = CreateDefaultSubobject<UAimTargetComponent>(TEXT("Aim Target"));
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	MainCamera->SetupAttachment(CameraBoom);
	
	Text_Name = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Name"));
	Text_Name->SetupAttachment(RootComponent);
	Text_Name->SetMaterial(0,LoadObject<UMaterial>(this,TEXT("/OmegaGameFramework/Materials/m_OutlineText.m_OutlineText")));
	Text_Name->HorizontalAlignment=EHTA_Center;
	Text_Name->WorldSize=80;
	Text_Name->VerticalAlignment=EVRTA_TextBottom;
	Text_Name->bHiddenInGame=true;
	
	Icon_Faction = CreateDefaultSubobject<UBillboardComponent>(TEXT("Icon Faction"));
	Icon_Faction->SetupAttachment(RootComponent);
	
	SkinTarget=CreateOptionalDefaultSubobject<UChildActorComponent>(TEXT("SkinTarget"));
	SkinTarget->SetupAttachment(GetMesh());

	AudioComponent=CreateOptionalDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(GetMesh());
	
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));

	ActorIdentity->OnActorIdentityChanged.AddDynamic(this, &AOmegaCharacter::OnActorIdentityChanged);

	if(GetMesh())
	{
		FVector bounds_loc=GetMesh()->GetLocalBounds().BoxExtent;
		Text_Name->SetRelativeLocation(bounds_loc+FVector(0,0,140));
		Icon_Faction->SetRelativeLocation(bounds_loc+FVector(0,0,110));
	}

	GetCapsuleComponent()->ShapeColor=FColor::Cyan;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MatRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male.SK_MannequinDemo_Male"));
	GetMesh()->SetSkeletalMeshAsset(MatRef.Object);

	//static ConstructorHelpers::FClassFinder<UAnimInstance> AnmRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Animations/ABP_OmegaDemo_Mannequin.ABP_OmegaDemo_Mannequin_c"));
	//GetMesh()->SetAnimInstanceClass(AnmRef.Class);
}

void AOmegaCharacter::OnConstruction(const FTransform& Transform)
{
	L_Camera_Update();
	if(CharacterAsset)
	{
		SetCharacterAsset(CharacterAsset);
	}
	if(SkinComponent)
	{
		SkinComponent->SetupLinkedComponents(GetMesh(),SkinTarget);
		SkinComponent->Assemble();
	}

	if(Combatant && Combatant->FactionDataAsset)
	{
		Icon_Faction->SetVisibility(false);
		if(UTexture2D* texture =Cast<UTexture2D>(Combatant->FactionDataAsset->FactionIcon.GetResourceObject()))
		{
			Text_Name->SetTextRenderColor(Combatant->FactionDataAsset->FactionColor.ToFColorSRGB());
			Icon_Faction->SetVisibility(true);
			Icon_Faction->SetSprite(texture);
		}
	}
	Text_Name->SetText(L_GetDisplayName());
	
	Super::OnConstruction(Transform);
}

void AOmegaCharacter::SetCharacterAsset(UPrimaryDataAsset* Asset)
{
	if(Asset)
	{
		CharacterAsset=Asset;
	}
	else
	{
		CharacterAsset=nullptr;
	}
	ActorIdentity->SetIdentitySourceAsset(CharacterAsset);
	OnActorIdentityChanged(CharacterAsset,ActorIdentity);
}

FVector AOmegaCharacter::GetAimTargetLocation_Implementation(const UAimTargetComponent* Component) const
{
	return GetMesh()->GetSocketLocation(LookAimSocketName);
}



// Called when the game starts or when spawned
void AOmegaCharacter::BeginPlay()
{
	Super::BeginPlay();
	Leveling->OnLevelUp.AddDynamic(this, &AOmegaCharacter::Local_LevelUpdate);
	Leveling->OnLevelDown.AddDynamic(this, &AOmegaCharacter::Local_LevelUpdate);
	//DataItem->OnDataItemChanged.AddDynamic(this, &AOmegaCharacter::Local_UpdateDataItem);
	if(DefaultEmote)
	{
		UOmegaAnimationFunctions::PlayEmoteAnimation(this,DefaultEmote);
	}
	if(Autobind_NamedGlobalEvents)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &AOmegaCharacter::OnGlobalEvent_Named);
	}
	if(Autobind_TaggedGlobalEvents)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.AddDynamic(this, &AOmegaCharacter::OnGlobalEvent_Tagged);
	}
	_ActivateSubscriptCol(SubscriptCollections);
	if(UOmegaSettings_Gameplay* set = UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		_ActivateSubscriptCol(set->SubscriptCollections_Character);
	}
}

void AOmegaCharacter::Local_AddCombatantSource(UObject* Source)
{
	if(Source)
	{
		Combatant->AddAttrbuteModifier(Source);
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

TArray<UOmegaObjectTrait*> AOmegaCharacter::GetTraits_Implementation()
{
	TArray<UOmegaObjectTrait*> out;
	if(UPrimaryDataAsset* _asset = ActorIdentity->GetIdentitySourceAsset())
	{
		out.Append(UDataInterface_Traits::GetObjectTraits(_asset));
	}
	return out;
}


void AOmegaCharacter::Local_LevelUpdate(ULevelingComponent* comp,int32 NewLevel)
{
	Combatant->Level = Leveling->GetCurrentLevel();
}

void AOmegaCharacter::Local_UpdateDataItem(UOmegaDataItem* NewItem)
{
//	Combatant->CombatantDataAsset = NewItem;
	Combatant->Update();
}


FText AOmegaCharacter::L_GetDisplayName()
{
	FText text_out;
	FText desc_out;
	if(!OverrideName.IsEmpty())
	{
		return OverrideName;
	}
	if(b_IdentityHasGeneralInterface())
    {
    	Execute_GetGeneralDataText(ActorIdentity->GetIdentitySourceAsset(),"",this,text_out,desc_out);
    }
	return text_out;
}

FText AOmegaCharacter::L_GetDisplayDescript()
{
	FText text_out;
	FText desc_out;
	if(b_IdentityHasGeneralInterface())
	{
		Execute_GetGeneralDataText(ActorIdentity->GetIdentitySourceAsset(),"",this,text_out,desc_out);
	}
	return desc_out;
}

void AOmegaCharacter::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                        FText& Description)
{
	Name=L_GetDisplayName();
	Description=L_GetDisplayDescript();
	IDataInterface_General::GetGeneralDataText_Implementation(Label, Context, Name, Description);
}

void AOmegaCharacter::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(b_IdentityHasGeneralInterface())
	{
		Execute_GetGeneralDataImages(ActorIdentity->GetIdentitySourceAsset(),"",this,Texture,Material,Brush);
	}
	IDataInterface_General::GetGeneralDataImages_Implementation(Label, Context, Texture, Material, Brush);
}

void AOmegaCharacter::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if(b_IdentityHasGeneralInterface())
	{
		Execute_GetGeneralAssetLabel(ActorIdentity->GetIdentitySourceAsset(),Label);
	}
	IDataInterface_General::GetGeneralAssetLabel_Implementation(Label);
}

// ========================================================================================================
// Encounter Character
// ========================================================================================================


AOmegaEncounterCharacter::AOmegaEncounterCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MatRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_BlackRed.SK_MannequinDemo_Male_BlackRed"));
	GetMesh()->SetSkeletalMeshAsset(MatRef.Object);
	//static ConstructorHelpers::FClassFinder<UAnimInstance> AnmRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Animations/ABP_OmegaDemo_Mannequin.ABP_OmegaDemo_Mannequin_c"));
	//GetMesh()->SetAnimInstanceClass(AnmRef.Class);
	
	ActorIdentity = CreateDefaultSubobject<UActorIdentityComponent>(TEXT("Actor Identity"));
	ActorState = CreateDefaultSubobject<UActorStateComponent>(TEXT("ActorState"));
	SaveVisibility = CreateDefaultSubobject<UOmegaSaveStateComponent>(TEXT("SaveVisibility"));
	SubscriptComponent = CreateDefaultSubobject<USubscriptComponent>(TEXT("Subscript"));
	SkinComponent = CreateDefaultSubobject<USkinComponent>(TEXT("Skin"));
	GameplayPause = CreateDefaultSubobject<UGameplayPauseComponent>(TEXT("GameplayPause"));
	ZoneEntity = CreateDefaultSubobject<UZoneEntityComponent>(TEXT("ZoneEntity"));
	LookAim = CreateDefaultSubobject<UAimTargetComponent>(TEXT("Aim Target"));
	
	StageID=FGameplayTag::RequestGameplayTag(FName("Combat.Stage.Default"));
	GetCapsuleComponent()->ShapeColor=FColor::Red;
}

void AOmegaEncounterCharacter::OnConstruction(const FTransform& Transform)
{
	//BoundsComponent->SetOverlayColor(FColor::Red);
	Super::OnConstruction(Transform);
}

AOmegaReferenceCharacter::AOmegaReferenceCharacter()
{
	CustomTimeDilation=0;
	SetActorEnableCollision(false);
	//bIsSpatiallyLoaded=false;
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MatRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Female_blue.SK_MannequinDemo_Female_blue"));
	GetMesh()->SetSkeletalMeshAsset(MatRef.Object);
}

void AOmegaReferenceCharacter::BeginPlay()
{
	SetActorHiddenInGame(true);
	Super::BeginPlay();
}

AOmegaCinematicCharacter::AOmegaCinematicCharacter()
{
	ActorIdentityComponent=CreateOptionalDefaultSubobject<UActorIdentityComponent>("ActorID");

	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MatRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_green.SK_MannequinDemo_Male_green"));
	GetMesh()->SetSkeletalMeshAsset(MatRef.Object);
	//static ConstructorHelpers::FClassFinder<UAnimInstance> AnmRef(TEXT("/OmegaGameFramework/DEMO/Mannequin/Animations/ABP_OmegaDemo_Mannequin.ABP_OmegaDemo_Mannequin_c"));
	//GetMesh()->SetAnimInstanceClass(AnmRef.Class);
}
