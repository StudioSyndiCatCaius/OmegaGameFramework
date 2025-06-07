// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaCharacter.h"

#include "Components/AudioComponent.h"
#include "Functions/OmegaFunctions_Combatant.h"
#include "OmegaMutable_Functions.h"
#include "OmegaSettings_Gameplay.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"


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

// Sets default values
AOmegaCharacter::AOmegaCharacter()
{
	//Super AOmegaCharacter();
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ActorIdentity = CreateDefaultSubobject<UActorIdentityComponent>(TEXT("Actor Identity"));
	Combatant = CreateDefaultSubobject<UCombatantComponent>(TEXT("Combatant"));
	//DataItem = CreateDefaultSubobject<UDataItemComponent>(TEXT("DataItem"));
	//if(DataItem){ DataItem->FlagOnApplied="SetCharacter"; }
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


void AOmegaCharacter::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	if(b_IdentityHasGeneralInterface())
	{
		Execute_GetGeneralDataText(ActorIdentity->GetIdentitySourceAsset(),"",this,Name,Description);
	}
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
