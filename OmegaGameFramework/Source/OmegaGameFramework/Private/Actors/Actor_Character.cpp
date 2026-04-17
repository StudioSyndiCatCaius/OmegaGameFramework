// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Character.h"

#include "LuaConst.h"
#include "OmegaSettings.h"
#include "OmegaGameplayConfig.h"
#include "OmegaGameManager.h"
#include "Components/CapsuleComponent.h"
#include "Components/Component_DebugText.h"
#include "Components/StateTreeComponent.h"
#include "DataAssets/DA_ActorModifierCollection.h"
#include "Functions/F_Common.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"

AOmegaMinimalCharacter::AOmegaMinimalCharacter()
{
	// BoundsComponent=CreateOptionalDefaultSubobject<UBoxComponent>("Bounds");
	// BoundsComponent->SetupAttachment(RootComponent);
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	
	StateTree=CreateDefaultSubobject<UStateTreeComponent>(TEXT("State Tree"));
	DebugText=CreateOptionalDefaultSubobject<UComponent_DebugText>("DebugText");
	ActorIdentity=CreateDefaultSubobject<UActorIdentityComponent>("Actor Identity");
	DebugText->SetupAttachment(RootComponent);

	if(GetMesh() && GetCapsuleComponent())
	{
		GetMesh()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
		GetMesh()->ComponentTags.Add("ToolHolder");
	}
	if(UCharacterMovementComponent* _move=GetCharacterMovement())
	{
		bUseControllerRotationYaw=false;
		_move->bOrientRotationToMovement=true;
		_move->RotationRate=FRotator(0,500,0);
		
		_move->GravityScale=2.0f;
		_move->AirControl=1.0f;
		_move->JumpZVelocity=700;
		_move->MaxWalkSpeed=600;
		_move->MaxAcceleration=3000;
		_move->BrakingDecelerationWalking=2000;
	}
	if(Seed<0)
	{
		//RandomizeSeed();
	}
	
}


void AOmegaMinimalCharacter::N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset)
{
}

void AOmegaMinimalCharacter::RebuildAppearance()
{
	if(UOAsset_Appearance* ap=IDataInterface_AppearanceSource::Execute_GetAppearanceAsset(this))
	{
		ap->Apply(this);
	}
}

TSubclassOf<UAnimInstance> AOmegaMinimalCharacter::GetContext_AnimClass()
{
	return GetMutableDefault<UOmegaSettings>()->DefaultCharacter_AnimClass.LoadSynchronous();
}


void AOmegaMinimalCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	FVector bound_origin;
	FVector bound_ext;
	float	bound_rad;
	UKismetSystemLibrary::GetComponentBounds(GetMesh(),bound_origin,bound_ext,bound_rad);
	// if(BoundsComponent) { BoundsComponent->SetBoxExtent(bound_ext); }
	RebuildAppearance();
	
	OGF_CFG()->OverrideActorLabel(this);
}

void AOmegaMinimalCharacter::BeginPlay()
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



void AOmegaMinimalCharacter::RandomizeSeed()
{
	Seed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
	RebuildAppearance();
}

void AOmegaMinimalCharacter::SetCharacterAsset(UPrimaryDataAsset* Asset)
{
	UPrimaryDataAsset* old_asset=nullptr;
	ActorIdentity->SetIdentitySourceAsset(Asset);
	N_OnCharAssetChange(old_asset,ActorIdentity->GetIdentitySourceAsset());
}

void AOmegaMinimalCharacter::SetCharacterAppearance(UOAsset_Appearance* Appearance)
{
	if (Appearance)
	{
		AppearanceOverride=Appearance;
		Appearance->Apply(this);
	}
	else
	{
		AppearanceOverride=nullptr;	
	}
}

void AOmegaMinimalCharacter::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if(ActorIdentity)
	{
		Label=UDataInterface_General::GetObjectLabel(ActorIdentity);
	}
}

UOAsset_Appearance* AOmegaMinimalCharacter::GetAppearanceAsset_Implementation()
{
	if(UOAsset_Appearance* ap=AppearanceOverride.LoadSynchronous())
	{
		return ap;
	}
	if(ActorIdentity->IdentitySource && ActorIdentity->IdentitySource->GetClass()->ImplementsInterface(UDataInterface_AppearanceSource::StaticClass()))
	{
		if(UOAsset_Appearance* appr=Execute_GetAppearanceAsset(ActorIdentity->IdentitySource))
		{
			return appr;	
		}
	}
	return nullptr;
}

void AOmegaMinimalCharacter::GetAppearanceLibraries_Implementation(UOmegaAssetLibrary_Animation*& Anim,
	UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate)
{
	Anim=Library_Animation;
}

FString AOmegaMinimalCharacter::VoiceSource_GetID_Implementation()
{
	if (UPrimaryDataAsset* da=ActorIdentity->GetIdentitySourceAsset())
	{
		if (UDataInterface_VoiceSource::Uses(da))
		{
			FString _id=IDataInterface_VoiceSource::Execute_VoiceSource_GetID(da);
			if (!_id.IsEmpty()) { return _id; }
		}
	}
	//if no override id in sound library, get grom source object label 
	return UOmegaGameFrameworkBPLibrary::GetObjectLabel(ActorIdentity->GetIdentitySourceAsset());
}

void AOmegaMinimalCharacter::GetGeneralDataImages_Implementation(FGameplayTag Tag,
                                                                 UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Execute_GetGeneralDataImages(ActorIdentity,Tag,Texture,Material,Brush);
	IDataInterface_General::GetGeneralDataImages_Implementation(Tag, Texture, Material, Brush);
}

FGameplayTagContainer AOmegaMinimalCharacter::GetObjectGameplayTags_Implementation()
{
	if (ActorIdentity)
	{
		return Execute_GetObjectGameplayTags(ActorIdentity);
	}
	return FGameplayTagContainer();
}

FGameplayTag AOmegaMinimalCharacter::GetObjectGameplayCategory_Implementation()
{
	if (ActorIdentity)
	{
		return Execute_GetObjectGameplayCategory(ActorIdentity);
	}
	return FGameplayTag();
}

void AOmegaMinimalCharacter::GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed,
	FOmegaClassNamedLists& named_lists)
{
	bitflags=Flags;
	named_lists=NamedLists;
	seed=Seed;
}

void AOmegaMinimalCharacter::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name,
                                                               FText& Description)
{
	if (ActorIdentity)
	{
		Execute_GetGeneralDataText(ActorIdentity,Tag,Name,Description);
	}
}

