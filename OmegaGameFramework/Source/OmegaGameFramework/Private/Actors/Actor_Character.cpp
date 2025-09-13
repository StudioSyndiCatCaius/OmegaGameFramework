// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Character.h"

#include "OmegaSettings_Gameplay.h"
#include "Components/CapsuleComponent.h"
#include "Components/StateTreeComponent.h"
#include "DataAssets/DA_ActorModifierCollection.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void AOmegaBaseCharacter::N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset)
{
}

void AOmegaBaseCharacter::OnConstruction(const FTransform& Transform)
{
	if(Config && ActorConfig)
	{
		ActorConfig->SetConfig(Config);
	}
	else if(UOmegaSettings_Gameplay* set = UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		ActorConfig->SetConfig(set->DefaultActorConfig_Character);
		if(UOAsset_ActorModifierCollection* col=set->ActorMods_Character)
		{
			col->ApplyAllModifiers(this);
		}
	}
	Super::OnConstruction(Transform);
	FVector bound_origin;
	FVector bound_ext;
	float	bound_rad;
	UKismetSystemLibrary::GetComponentBounds(GetMesh(),bound_origin,bound_ext,bound_rad);
	// if(BoundsComponent) { BoundsComponent->SetBoxExtent(bound_ext); }
	if(UOAsset_Appearance* ap=IDataInterface_AppearanceSource::Execute_GetAppearanceAsset(this))
	{
		ap->Apply(this);
	}
}

void AOmegaBaseCharacter::BeginPlay()
{
	if(UOmegaSettings_Gameplay* set=UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		if(set->DefaultCharacter_AnimClass && GetMesh()->GetAnimationMode()==EAnimationMode::AnimationBlueprint && !GetMesh()->GetAnimClass())
		{
			GetMesh()->SetAnimInstanceClass(set->DefaultCharacter_AnimClass.LoadSynchronous());
		}
	}
	Super::BeginPlay();
}

AOmegaBaseCharacter::AOmegaBaseCharacter()
{
	// BoundsComponent=CreateOptionalDefaultSubobject<UBoxComponent>("Bounds");
	// BoundsComponent->SetupAttachment(RootComponent);
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	
	ActorConfig=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");
	StateTree=CreateDefaultSubobject<UStateTreeComponent>(TEXT("State Tree"));

	if(GetMesh() && GetCapsuleComponent())
	{
		GetMesh()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	}
	if(GetCharacterMovement())
	{
		bUseControllerRotationYaw=false;
		GetCharacterMovement()->bOrientRotationToMovement=true;
		GetCharacterMovement()->RotationRate=FRotator(0,500,0);
	}
}

void AOmegaBaseCharacter::SetCharacterAsset(UPrimaryDataAsset* Asset)
{
	UPrimaryDataAsset* old_asset=nullptr;
	if(CharacterAsset) { old_asset=CharacterAsset; }
	if(Asset)
	{
		CharacterAsset=Asset;
	}
	else
	{
		CharacterAsset=nullptr;
	}
	N_OnCharAssetChange(old_asset,CharacterAsset);
}

void AOmegaBaseCharacter::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if(CharacterAsset)
	{
		Label=UDataInterface_General::GetObjectLabel(CharacterAsset);
	}
}

UOAsset_Appearance* AOmegaBaseCharacter::GetAppearanceAsset_Implementation()
{
	if(AppearanceOverride.IsValid())
	{
		return AppearanceOverride.LoadSynchronous();
	}
	if(CharacterAsset && CharacterAsset->GetClass()->ImplementsInterface(UDataInterface_AppearanceSource::StaticClass()))
	{
		if(UOAsset_Appearance* appr=Execute_GetAppearanceAsset(CharacterAsset))
		{
			return appr;	
		}
	}
	return nullptr;
}

void AOmegaBaseCharacter::GetAppearanceLibraries_Implementation(UOmegaAssetLibrary_Animation*& Anim,
	UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate)
{
	Anim=Library_Animation;
	
}


