// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spawnable.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Engine.h"


TSubclassOf<AActor> AOmegaActorSpawnable::GetSpawnableClass()
{
	FLuaValue devConfigData=OGF_Subsystems::oEngine()->Spawnable_GetData(Config.NamedSpawnable);
	FLuaValue lua_uclass=devConfigData.GetField("UCLASS");
	if (TSubclassOf<AActor> class_ref=TSoftClassPtr<AActor>(lua_uclass.ToString()).LoadSynchronous())
	{
		return class_ref;
	}
	if (Config.SpawnableClass)
	{
		return Config.SpawnableClass;
	}
	return nullptr;
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
	OGF_GAME_CORE()->Spawnable_GetNamed().GetKeys(out);
	out.Append(OGF_Subsystems::oEngine()->keys_spawnables);
	
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
	
	FLuaValue devConfigData=OGF_Subsystems::oEngine()->Spawnable_GetData(Config.NamedSpawnable);
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
	
	bool b_validSpawnable=false;
	if (Config.SpawnableClass && Config.SpawnableClass->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(Config.SpawnableClass))
		{
			b_validSpawnable=true;
			IActorInterface_Spawnable::Execute_GetSpawnablePreviewConfig(_tempDef,_icon,_rootOffset,_disName,_color,_iconScale,_boxExt,_boxThick);
			OGF_CFG()->OverrideActorLabel(this,IActorInterface_Spawnable::Execute_GetSpawnable_ActorLabel(_tempDef));
		}
		
	}
	else if (!devConfigData.IsNil())
	{
		Config.Bitflags.override_config=true;
		Config.Lists.override_keys=true;
		Config.Relatives.override_keys=true;
		FOmegaBitmaskEditorData BitflagEditData;
		
		TArray<FLuaValue> keys_bitflags=ULuaBlueprintFunctionLibrary::LuaTableGetValues(devConfigData.GetField("bitflags"));
		for (FLuaValue key : keys_bitflags)
		{
			FOmegaBitmaskEditorEntry entry;
			entry.Title=FText::FromString(key.ToString());
			BitflagEditData.Bitflags.Add(entry);
		}
		TArray<FLuaValue> keys_bitenums=ULuaBlueprintFunctionLibrary::LuaTableGetValues(devConfigData.GetField("bitenums"));
		for (FLuaValue key : keys_bitenums)
		{
			FOmegaBitmaskEditorEnumData entry;
			entry.Title=FText::FromString(key.GetField("name").ToString());
			TArray<FLuaValue> opts=ULuaBlueprintFunctionLibrary::LuaTableGetValues(key.GetField("options"));
			for (FLuaValue opt : opts)
			{
				FOmegaBitmaskEditorEntry optData;
				optData.Title=FText::FromString(key.ToString());
				entry.Options.Add(optData);
			}
			BitflagEditData.BitEnums.Add(entry);
		}
		
		TArray<FLuaValue> keys_lists=ULuaBlueprintFunctionLibrary::LuaTableGetValues(devConfigData.GetField("lists"));
		for (FLuaValue key : keys_lists)
		{
			Config.Lists.override_keyList.Add(key.ToName());
		}
		
		TArray<FLuaValue> keys_relatives=ULuaBlueprintFunctionLibrary::LuaTableGetValues(devConfigData.GetField("relatives"));
		for (FLuaValue key : keys_relatives)
		{
			Config.Relatives.override_keyList.Add(key.ToName());
		}
		
		Config.Bitflags.override_configData=BitflagEditData;
		
		b_validSpawnable=true;
		
		_disName=FText::FromString(Config.NamedSpawnable.ToString());
		FVector _ColorVec=ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(devConfigData.GetField("Color"),FVector());
		_color=UKismetMathLibrary::Conv_VectorToLinearColor(_ColorVec).ToFColor(true);
		_color.A=255;
		_rootOffset=ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(devConfigData.GetField("BoundsOffset"),FVector());
		_boxExt=ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(devConfigData.GetField("BoundsSize"),FVector());
		_boxThick=devConfigData.GetField("BoundsThickness").ToFloat();
		bool iconFound;
		if (UTexture2D* _foundTxt=Cast<UTexture2D>(UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(devConfigData.GetField("Icon").ToString(),UTexture2D::StaticClass(),iconFound)))
		{
			_icon=_foundTxt;
		}
		_iconScale=devConfigData.GetField("IconSize").ToFloat();
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
			TextRenderComponent->SetText(_disName);
			TextRenderComponent->SetHiddenInGame(true);
			TextRenderComponent->SetTextRenderColor(_color);
			TextRenderComponent->SetWorldLocation(GetActorLocation()+FVector(0,0,(_boxExt.Z*2)+10));
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
			}
			
			if (bAutospawn)
			{
				Spawnable_Spawn(true);
			}
		}
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
	
		AActor* _tempActor=GetWorld()->SpawnActorDeferred<AActor>(refClass,FTransform());
		_tempActor->FinishSpawning(GetActorTransform());
		REF_linkedActor=_tempActor;
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
