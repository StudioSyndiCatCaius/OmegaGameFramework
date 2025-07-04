// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Interactable.h"

#include "OmegaSettings_Gameplay.h"
#include "Components/Component_ActorConfig.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Components/TextRenderComponent.h"
#include "DataAssets/DA_ActorModifierCollection.h"
#include "Kismet/KismetMathLibrary.h"

void AOmegaInteractable::OnConstruction(const FTransform& Transform)
{
	if(RangeBox)
	{
		Range+=GetActorScale()-1;
		FVector _def=50*Range;
		RangeBox->SetBoxExtent(_def);
		SetActorScale3D(FVector::One());
	}
	if(NameText)
	{
		NameText->SetText(UDataInterface_General::GetObjectName(this));
	}
	if(SpringArm)
	{
		FRotator _rot =UKismetMathLibrary::FindLookAtRotation(CameraDirection,SpringArm->GetRelativeLocation());
		SpringArm->SetRelativeRotation(_rot);
		float _dis=UKismetMathLibrary::Vector_Distance(SpringArm->GetRelativeLocation(),CameraDirection);
		SpringArm->TargetArmLength=_dis;
	}

	//Apply Gameplay Settings
	if(UOmegaSettings_Gameplay* set=UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		if(UOmegaActorConfig* _cfg=set->DefaultActorConfig_Interactable)
		{
			if(ActorConfig && !ActorConfig->DefaultConfig)
			{
				ActorConfig->DefaultConfig=_cfg;
			}
		}
		if(UOAsset_ActorModifierCollection* col=set->ActorMods_Interactable)
		{
			col->ApplyAllModifiers(this);
		}
	}
	
	Super::OnConstruction(Transform);
}

AOmegaInteractable::AOmegaInteractable()
{
	RangeBox=CreateDefaultSubobject<UBoxComponent>("Range");
	RootComponent=RangeBox;
	RangeBox->SetBoxExtent(FVector(50,50,50));
	RangeBox->SetLineThickness(3);
	RangeBox->ShapeColor=FColor(0,100,255);
	ActorID=CreateOptionalDefaultSubobject<UActorIdentityComponent>("ActorID");
	ActorConfig=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");
	NameText=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
	NameText->bHiddenInGame=true;
	NameText->HorizontalAlignment=EHTA_Center;
	NameText->SetupAttachment(RangeBox);
	SpringArm=CreateOptionalDefaultSubobject<USpringArmComponent>("SpringArm");
	if(SpringArm)
	{
		SpringArm->SetupAttachment(RangeBox);
		Camera=CreateOptionalDefaultSubobject<UCameraComponent>("Camera");
		Camera->FieldOfView=50;
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SOFT_CamMesh(TEXT("/OmegaGameFramework/Meshes/util/sm_UTIL_CameraMini.sm_UTIL_CameraMini"));
#if WITH_EDITOR
		Camera->SetCameraMesh(SOFT_CamMesh.Object);
#endif
		Camera->SetupAttachment(SpringArm);
		SpringArm->TargetArmLength=300;
	}
}

TArray<UOmegaObjectTrait*> AOmegaInteractable::GetTraits_Implementation()
{
	TArray<UOmegaObjectTrait*> out;
	if(UPrimaryDataAsset* _asset = ActorID->GetIdentitySourceAsset())
    {
		TArray<UOmegaObjectTrait*> _in = UDataInterface_Traits::GetObjectTraits(_asset);
		out.Append(_in);
    }
	return out;
}

void AOmegaInteractable::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                           FText& Description)
{
	if(UPrimaryDataAsset* _asset = ActorID->GetIdentitySourceAsset())
	{
		Name=UDataInterface_General::GetObjectName(_asset);
		Description=UDataInterface_General::GetObjectDesc(_asset);
	}
	else
	{
		Name=DisplayName;
	}
	IDataInterface_General::GetGeneralDataText_Implementation(Label, Context, Name, Description);
}
