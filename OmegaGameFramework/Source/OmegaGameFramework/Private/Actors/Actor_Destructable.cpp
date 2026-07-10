// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Destructable.h"

#include "UObject/ConstructorHelpers.h"
#include "NiagaraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/Component_Combatant.h"
#include "DataAssets/DA_Faction.h"
#include "Functions/F_Actor.h"
#include "Kismet/KismetSystemLibrary.h"

void AOmegaDestructible::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (Preset.GetObject())
	{
		SetPreset(Preset);
	}
}


void AOmegaDestructible::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (dying)
	{
		if (DeathDelayRemaining<=0.0)
		{
			dying=false;
			PrimaryActorTick.bCanEverTick=false;
			bool bDestroyOnDeath=false;
			if (Preset.GetObject())
			{
				IDataInterface_Destructible::Execute_Destructible_Death(Preset.GetObject(),this,bDestroyOnDeath);
			}
			UActorTagEventFunctions::FireActorTagEvents_Container(TagEvents_OnDeath);	
			if (bDestroyOnDeath)
			{
				K2_DestroyActor();
			}
		}
		else
		{
			DeathDelayRemaining-=DeltaSeconds;
		}
	}
}

void AOmegaDestructible::BeginPlay()
{
	Super::BeginPlay();
	if (Preset.GetObject())
	{
		_cachedConfig=IDataInterface_Destructible::Execute_Destructible_GetConfig(Preset.GetObject());
		IDataInterface_Destructible::Execute_Destructible_BeginPlay(Preset.GetObject(),this);
	}
	if (CombatantComponent)
	{
		CombatantComponent->OnDamaged.AddUniqueDynamic(this, &AOmegaDestructible::L_Damaged);
	}
}

void AOmegaDestructible::Destroyed()
{
	Super::Destroyed();
	if (Preset.GetObject())
	{
		IDataInterface_Destructible::Execute_Destructible_Destroyed(Preset.GetObject(),this);
	}
}

FOmegaDestructibleConfig AOmegaDestructible::GetConfig() const
{
	if (Preset.GetObject())
	{
		return IDataInterface_Destructible::Execute_Destructible_GetConfig(Preset.GetObject());
	}
	return FOmegaDestructibleConfig();
}


void AOmegaDestructible::L_Damaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage,
                                   class UCombatantComponent* _Instigator, UOmegaDamageType* DamageType, FHitResult Hit)
{
	if (_cachedConfig.bDeathOnHealth0 && !dead)
	{
		if (_cachedConfig.HealthAttribute)
		{
			float health_cur;
			float health_max;
			Combatant->GetAttributeValue(_cachedConfig.HealthAttribute,health_cur,health_max);
			
			if (health_cur <= 0.0)
			{
				dead=true;
				DeathDelayRemaining=_cachedConfig.DeathDelay;
				dying=true;
			}
		}
	}
}

AOmegaDestructible::AOmegaDestructible()
{
	PrimaryActorTick.bCanEverTick=true;
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	RangeBox=CreateOptionalDefaultSubobject<UBoxComponent>("Range");
	RangeBox->SetupAttachment(RootComponent);
	MeshComponent=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(RootComponent);
	NiagaraComponent=CreateOptionalDefaultSubobject<UNiagaraComponent>("Niagara");
	NiagaraComponent->SetupAttachment(RootComponent);
	
	CombatantComponent=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	static ConstructorHelpers::FObjectFinder<UOmegaFaction> NeutralFactionFinder(TEXT("/OmegaGameFramework/DEMO/Factions/Faction_Neutral.Faction_Neutral"));
	if (NeutralFactionFinder.Succeeded()) CombatantComponent->FactionDataAsset = NeutralFactionFinder.Object;
}

void AOmegaDestructible::SetPreset(TScriptInterface<IDataInterface_Destructible> preset)
{
	Preset=preset;
	FOmegaDestructibleConfig config=GetConfig();
	
	if (Preset.GetObject())
	{
		IDataInterface_Destructible::Execute_Destructible_Construct(Preset.GetObject(),this);
	}
	
	if (config.bSizeRangeToMeshBounds)
	{
		UOmegaComponentFunctions::SetBoxRangeToComponentBounds(RangeBox,MeshComponent);
	}
}
