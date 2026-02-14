// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Character.h"

#include "LuaConst.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Gameplay.h"
#include "OmegaSettings_Global.h"
#include "Components/CapsuleComponent.h"
#include "Components/Component_DebugText.h"
#include "Components/StateTreeComponent.h"
#include "DataAssets/DA_ActorModifierCollection.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"


void AOmegaBaseCharacter::N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset)
{
}

void AOmegaBaseCharacter::RebuildAppearance()
{
	if(UOAsset_Appearance* ap=IDataInterface_AppearanceSource::Execute_GetAppearanceAsset(this))
	{
		ap->Apply(this);
	}
}

TSubclassOf<UAnimInstance> AOmegaBaseCharacter::GetContext_AnimClass()
{
	return GetMutableDefault<UOmegaSettings>()->DefaultCharacter_AnimClass.LoadSynchronous();
}


void AOmegaBaseCharacter::OnConstruction(const FTransform& Transform)
{
	if(Config && ActorConfig)
	{
		ActorConfig->SetConfig(Config);
	}
	Super::OnConstruction(Transform);
	FVector bound_origin;
	FVector bound_ext;
	float	bound_rad;
	UKismetSystemLibrary::GetComponentBounds(GetMesh(),bound_origin,bound_ext,bound_rad);
	// if(BoundsComponent) { BoundsComponent->SetBoxExtent(bound_ext); }
	RebuildAppearance();
	
	OGF_CFG()->OverrideActorLabel(this);
}

void AOmegaBaseCharacter::BeginPlay()
{
	if (TSubclassOf<UAnimInstance> _inAnim=GetContext_AnimClass())
	{
		if(GetMesh()->GetAnimationMode()==EAnimationMode::AnimationBlueprint && !GetMesh()->GetAnimClass())
		{
			GetMesh()->SetAnimInstanceClass(_inAnim);
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
	DebugText=CreateOptionalDefaultSubobject<UComponent_DebugText>("DebugText");
	DebugText->SetupAttachment(RootComponent);

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
	if(Seed<0)
	{
		//RandomizeSeed();
	}
	

}

void AOmegaBaseCharacter::RandomizeSeed()
{
	Seed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
	RebuildAppearance();
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


