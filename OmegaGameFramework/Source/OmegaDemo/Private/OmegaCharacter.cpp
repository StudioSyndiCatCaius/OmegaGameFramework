// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaCharacter.h"

#include "Components/AudioComponent.h"
#include "Functions/OmegaFunctions_Combatant.h"
#include "OmegaMutable_Functions.h"
#include "OmegaSettings_Gameplay.h"
#include "GameFramework/CharacterMovementComponent.h"


void AOmegaCharacter::OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UActorIdentityComponent* Component)
{
	if(IdentityAsset)
	{
		if(IdentityAsset->GetClass()->IsChildOf(UOmegaDataItem::StaticClass()))
		{
			DataItem->SetDataItem(Cast<UOmegaDataItem>(IdentityAsset));
		}
		Combatant->SetSourceDataAsset(IdentityAsset);
		UCombatantFunctions::SetCombatantFromSource(Combatant,IdentityAsset);
		UDataAssetCollectionFunctions::SetInventory_FromSource(Inventory,IdentityAsset);
		Equipment->SetEquipment_FromSource(IdentityAsset);
		UOmegaSkinFunctions::SetSkinFromAsset(SkinComponent,IdentityAsset);
		if(IdentityAsset && IdentityAsset->GetClass()->ImplementsInterface(UDataInterface_MutableSource::StaticClass()))
		{
			if(UCustomizableObjectInstance* inst = IDataInterface_MutableSource::Execute_GetCustomizableObjectInstance(IdentityAsset))
			{
				if(USkeletalMesh* _mesh = inst->GetComponentMeshSkeletalMesh(MutableComponentName))
				{
					GetMesh()->SetSkeletalMeshAsset(_mesh);
				}
				//if(CustomSkelMesh) { CustomSkelMesh->SetCustomizableObjectInstance(inst); }
			}
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
	DataItem = CreateDefaultSubobject<UDataItemComponent>(TEXT("DataItem"));
	if(DataItem)
	{
		DataItem->FlagOnApplied="SetCharacter";
	}
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

	//CustomSkelMesh=CreateOptionalDefaultSubobject<UCustomizableSkeletalComponent>(TEXT("CustomSkelMesh"));
	//CustomSkelMesh->SetupAttachment(GetMesh());
	//CustomSkelMesh->ComponentIndex=-1;
	//CustomSkelMesh->SetComponentName(FName("Body"));
	
	SkinTarget=CreateOptionalDefaultSubobject<UChildActorComponent>(TEXT("SkinTarget"));
	SkinTarget->SetupAttachment(GetMesh());

	AudioComponent=CreateOptionalDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(GetMesh());
	
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));

	ActorIdentity->OnActorIdentityChanged.AddDynamic(this, &AOmegaCharacter::OnActorIdentityChanged);
}

void AOmegaCharacter::OnConstruction(const FTransform& Transform)
{
	if(CharacterAsset)
	{
		SetCharacterAsset(CharacterAsset);
	}
	if(SkinComponent)
	{
		SkinComponent->SetupLinkedComponents(GetMesh(),SkinTarget);
		SkinComponent->Assemble();
	}
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
	DataItem->OnDataItemChanged.AddDynamic(this, &AOmegaCharacter::Local_UpdateDataItem);
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
		Combatant->SetSkillSourceActive(DataItem, true);
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

void AOmegaCharacter::Local_LevelUpdate(int32 NewLevel)
{
	Combatant->Level = Leveling->GetCurrentLevel();
}

void AOmegaCharacter::Local_UpdateDataItem(UOmegaDataItem* NewItem)
{
	Combatant->CombatantDataAsset = NewItem;
	Combatant->Update();
}


AOmegaEncounterCharacter::AOmegaEncounterCharacter()
{
	StageID=FGameplayTag::RequestGameplayTag(FName("Combat.Stage.Default"));
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
