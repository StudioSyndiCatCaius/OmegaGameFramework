// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spawnable.h"

#include "Misc/OmegaFlowAssetBase.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "OmegaSettings.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/Component_GameplayActor.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Engine.h"
#include "Types/Struct_SpawnableTypeConfig.h"
#include "Materials/Material.h"


TSubclassOf<AActor> AOmegaActorSpawnable::GetSpawnableClass()
{
	bool val=false;
	return GetSpawnableTypeConfig(val).Class.LoadSynchronous();
}

FOmegaSpawnableTypeConfig AOmegaActorSpawnable::GetSpawnableTypeConfig(bool& valid)
{
	FOmegaSpawnableTypeConfig typeConifg;
	
	FLuaValue devConfigData=OGF_Subsystems::oEngine()->Spawnable_GetData(Config.SpawnableID);
	
	if (!devConfigData.IsNil())
	{
		typeConifg.SetFromLua(devConfigData);
		valid=true;
	}
	else if (OGF_CFG()->SpawnableDefinitions.Contains(Config.SpawnableID))
	{
		typeConifg=OGF_CFG()->SpawnableDefinitions[Config.SpawnableID];
		valid=true;
	}
	return typeConifg;
}

bool AOmegaActorSpawnable::L_ClassUsesInterface()
{
	if (GetSpawnableClass() && GetSpawnableClass()->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		return true;
	}
	return false;
}

TArray<FName> AOmegaActorSpawnable::L_getSpawnables() const
{
	TArray<FName> out;
	OGF_CFG()->SpawnableDefinitions.GetKeys(out);
	//out.Append(OGF_Subsystems::oEngine()->keys_spawnables);
	
	return out;
}

AOmegaActorSpawnable::AOmegaActorSpawnable()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComp=RootComponent;
	
	DisplayRoot=CreateOptionalDefaultSubobject<UBoxComponent>("DisplayRoot");
	DisplayRoot->SetupAttachment(RootComponent);
	
	ArrowComponent=CreateOptionalDefaultSubobject<UArrowComponent>("Arrow");
	ArrowComponent->SetupAttachment(DisplayRoot);
	BillboardComponent=CreateOptionalDefaultSubobject<UBillboardComponent>("Billboard");
	BillboardComponent->SetupAttachment(DisplayRoot);
	TextRenderComponent=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
	TextRenderComponent->SetupAttachment(DisplayRoot);
	TextRenderComponent->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	TextRenderComponent->SetMaterial(0,OGF_UASSET_MAT_TEXT_CAMFACE());
}

void AOmegaActorSpawnable::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (id<=0)
	{
		id=FMath::RandRange(1,9999999);
	}
	BillboardComponent->SetSprite(nullptr);
	TextRenderComponent->SetText(FText::FromString("-"));
	TextRenderComponent->SetWorldRotation(FRotator(0,0,0));
	DisplayRoot->ShapeColor=FColor(100,100,100);
	DisplayRoot->SetLineThickness(2);
	DisplayRoot->SetRelativeLocation(FVector());
	DisplayRoot->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DisplayRoot->SetCollisionResponseToAllChannels(ECR_Ignore);
	FColor _color;
	FText _disName;
	FVector _rootOffset;
	UTexture2D* _icon=nullptr;
	FVector _boxExt;
	float _iconScale;
	float _boxThick;
		
	Config.Bitflags.override_config=false;
	Config.Lists.override_keys=false;
	Config.Lists.override_keyList.Empty();
	Config.Relatives.override_keys=false;
	Config.Relatives.override_keyList.Empty();
	
	bool typeConfig_valid=false;
	FOmegaSpawnableTypeConfig typeConifg;
	
	TSubclassOf<AActor> _resolvedClass = GetSpawnableClass();
	UPrimaryDataAsset* _effectiveIdentity = Config.Identity;

	bool b_validSpawnable=false;
	if (_resolvedClass && _resolvedClass->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(_resolvedClass))
		{
			b_validSpawnable=true;
			IActorInterface_Spawnable::Execute_GetSpawnablePreviewConfig(_tempDef,_icon,_rootOffset,_disName,_color,_iconScale,_boxExt,_boxThick);
			OGF_CFG()->OverrideActorLabel(this,IActorInterface_Spawnable::Execute_GetSpawnable_ActorLabel(_tempDef));
		}
	}
	else
	{
		typeConifg=GetSpawnableTypeConfig(typeConfig_valid);
	}
	
	if (typeConfig_valid)
	{
		Config.Bitflags.override_config=true;
		Config.Lists.override_keys=true;
		Config.Relatives.override_keys=true;
		Config.Bitflags.override_configData=typeConifg.Bitmask_Config;
		Config.Lists.override_keyList=typeConifg.NamedLists;
		Config.Relatives.override_keyList=typeConifg.ActorRelatives;
		b_validSpawnable=true;
		
		_color=typeConifg.Color.ToFColor(true);
		_disName=FText::FromName(Config.SpawnableID);
		_rootOffset=typeConifg.RangeOffset;
		if (UTexture2D* icoRef=typeConifg.Icon.LoadSynchronous())
		{
			_icon=icoRef;
		}
		_boxExt=typeConifg.RangeSize;
		_iconScale=typeConifg.IconSize;
		_boxThick=typeConifg.LineThickness;
		
#if WITH_EDITOR
		if (GetActorLabel().Contains("OmegaActorSpawnable"))
		{
			UpdateWorldLabel();
		}
#endif
		
	}
	
	if (b_validSpawnable)
	{
		if (DisplayRoot)
		{
			if (_icon)
			{
				BillboardComponent->SetSprite(_icon);
			}
			BillboardComponent->SetWorldScale3D(FVector(_iconScale));
			DisplayRoot->ShapeColor=_color;
			ArrowComponent->SetArrowColor(_color);
			DisplayRoot->SetRelativeLocation(_rootOffset);
			DisplayRoot->SetLineThickness(1);
			DisplayRoot->SetBoxExtent(_boxExt);
			DisplayRoot->SetLineThickness(_boxThick);
			if (_effectiveIdentity)
			{
				FString _st=_disName.ToString()+": \n"+_effectiveIdentity->GetName();
				TextRenderComponent->SetText(FText::FromString(_st));
			}
			else
			{
				TextRenderComponent->SetText(_disName);
			}
			TextRenderComponent->SetHiddenInGame(true);
			TextRenderComponent->SetTextRenderColor(_color);
			TextRenderComponent->SetWorldLocation(GetActorLocation()+FVector(0,0,_boxExt.Z+_rootOffset.Z+10));
		}
	}
	
}

void AOmegaActorSpawnable::BeginPlay()
{
	Super::BeginPlay();
	if (TSubclassOf<AActor> refClass=GetSpawnableClass())
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(refClass))
		{
			bool bAutospawn = false;
			if (L_ClassUsesInterface())
			{
				IActorInterface_Spawnable::Execute_GetSpawnableSpawnConfig(_tempDef,bAutospawn);	
				if (bAutospawn)
				{
					Spawnable_Spawn(true);
				}
			}
			else
			{
				Spawnable_Spawn(true);
			}
			
		}
	}
}

void AOmegaActorSpawnable::UpdateWorldLabel()
{
	if (Config.Identity)
	{
#if WITH_EDITOR
		SetActorLabel(Config.SpawnableID.ToString()+"_"+Config.Identity.GetName());
#endif
		
	}
	else
	{
#if WITH_EDITOR
		SetActorLabel(Config.SpawnableID.ToString()+"_"+FString::FromInt(UKismetMathLibrary::RandomIntegerInRange(0,99999)));
#endif
		
	}
}

bool AOmegaActorSpawnable::Spawnable_IsAlive() const
{
	if (REF_linkedActor && !REF_linkedActor->IsActorBeingDestroyed())
	{
		return true;
	}
	return false;
}

void AOmegaActorSpawnable::Spawnable_Spawn(bool bForceRespawn)
{
	if (TSubclassOf<AActor> refClass= GetSpawnableClass())
	{
		if (Spawnable_IsAlive())
		{
			if (!bForceRespawn)
			{
				return;
			}
			Spawnable_Destroy();
		}
	
		AActor* _tempActor=GetWorld()->SpawnActorDeferred<AActor>(refClass,FTransform(),this,nullptr,ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
		if (UActorComponent* com=_tempActor->GetComponentByClass(UGameplayActorComponent::StaticClass()))
		{
			UGameplayActorComponent* c=Cast<UGameplayActorComponent>(com);
			if (Config.Identity)
			{
				c->SetIdentitySourceAsset(Config.Identity);
			}
			if (Config.Flow.IsValid())
			{
				c->DefaultFlow=Config.Flow;	
			}
			if (Config.Zone)
			{
				c->Zone=Config.Zone;	
			}
		}
		
		_tempActor->FinishSpawning(GetActorTransform());
		REF_linkedActor=_tempActor;
		
#if WITH_EDITOR
		REF_linkedActor->SetActorLabel(GetActorLabel()+"_SPAWNED");
#endif
		
		if (L_ClassUsesInterface())
		{
			IActorInterface_Spawnable::Execute_OnSpawnableSpawn(_tempActor,this,Flag);
		}
	}
}

void AOmegaActorSpawnable::Spawnable_Destroy()
{
	if (Spawnable_IsAlive())
	{
		REF_linkedActor->K2_DestroyActor();
		REF_linkedActor=nullptr;
	}
}
