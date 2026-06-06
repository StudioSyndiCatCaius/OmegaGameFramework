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
	if (ActorIdentity)
	{
		ActorIdentity->PauseCategory=FGameplayTag::RequestGameplayTag("PAUSE.Gameplay");
	}
	
}


void AOmegaMinimalCharacter::N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset)
{
}

void AOmegaMinimalCharacter::RebuildAppearance()
{
	cached_appearance=AppearanceOverride.LoadSynchronous();
	if(UOAsset_Appearance* ap=IDataInterface_AppearanceSource::Execute_GetAppearanceAsset(this))
	{
		ap->Apply(this);
	}
}

void AOmegaMinimalCharacter::L_Log(FString logString)
{
	if (false)
		{
		OGF_Log::LogInfo("Ω CHARACTER : "+GetName()+": -- "+logString);
		};
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
	if (Preset.GetObject())
	{
		IDataInterface_Character::Execute_Character_Construct(Preset.GetObject(),this);
	}
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
	if (Preset.GetObject())
	{
		IDataInterface_Character::Execute_Character_BeginPlay(Preset.GetObject(),this);
	}
}



void AOmegaMinimalCharacter::RandomizeSeed()
{
	Seed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
	RebuildAppearance();
}

void AOmegaMinimalCharacter::SetCharacterPreset(TScriptInterface<IDataInterface_Character> _preset)
{
	Preset=_preset;
	if (ActorIdentity)
	{
		if (UPrimaryDataAsset* da=Cast<UPrimaryDataAsset>(Preset.GetObject()))
		{
			UPrimaryDataAsset* old_asset=ActorIdentity->GetIdentitySourceAsset();
			ActorIdentity->SetIdentitySourceAsset(da);
			N_OnCharAssetChange(old_asset,ActorIdentity->GetIdentitySourceAsset());
		}
	}
	if (Preset.GetObject())
	{
		IDataInterface_Character::Execute_Character_Init(Preset.GetObject(),this);
	};
}

void AOmegaMinimalCharacter::SetCharacterAppearance(UOAsset_Appearance* Appearance)
{
	if (Appearance)
	{
		AppearanceOverride=TSoftObjectPtr<UOAsset_Appearance>(Appearance);
		cached_appearance=Appearance;
		RebuildAppearance();
	}
	else
	{
		AppearanceOverride=nullptr;
		cached_appearance=nullptr;
	}
}


UOAsset_Appearance* AOmegaMinimalCharacter::GetAppearanceAsset_Implementation()
{
	if(UOAsset_Appearance* ap=cached_appearance)
	{
		L_Log("got appearance from CACHE: "+cached_appearance->GetName());
		return ap;
	}
	if(ActorIdentity->IdentitySource && ActorIdentity->IdentitySource->GetClass()->ImplementsInterface(UDataInterface_AppearanceSource::StaticClass()))
	{
		if(UOAsset_Appearance* appr=Execute_GetAppearanceAsset(ActorIdentity->IdentitySource))
		{
			L_Log("got appearance from IDENTITY: "+appr->GetName());
			return appr;	
		}
	}
	L_Log("no appearance found: ");
	return nullptr;
}

void AOmegaMinimalCharacter::GetAppearanceLibraries_Implementation(UOmegaAssetLibrary_Animation*& Anim,
	UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate)
{
	
	if (Library_Animation) { Anim=Library_Animation; }
	if (Library_Sound) { Sound=Library_Sound; }
	if (Library_Slate) { Slate=Library_Slate; }
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

void AOmegaMinimalCharacter::GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags)
{
	if (ActorIdentity)
	{
		IDataInterface_General::Execute_GetObjectGameplayTags(ActorIdentity, OutCategoryTag, OutGameplayTags);
	}
}

void AOmegaMinimalCharacter::GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed,
	FOmegaClassNamedLists& named_lists)
{
	bitflags=Flags;
	named_lists=NamedLists;
	seed=Seed;
}

void AOmegaMinimalCharacter::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name,
                                                               FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	if (ActorIdentity)
	{
		IDataInterface_General::Execute_GetGeneralDataText(ActorIdentity, Tag, Name, Description, iconBrush, Color, Label, MetaConfig);
	}
	MetaConfig.bitflags=Flags;
	MetaConfig.named_lists=NamedLists;
	MetaConfig.seed=Seed;
}

