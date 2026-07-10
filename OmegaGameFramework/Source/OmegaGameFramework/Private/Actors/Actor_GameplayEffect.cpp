// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_GameplayEffect.h"
#include "Components/TextBlock.h"
#include "DataAssets/DA_Attribute.h"
#include "Functions/F_Common.h"
#include "TimerManager.h"
#include "Components/Component_Combatant.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetTextLibrary.h"


// Sets default values
AOmegaGameplayEffect::AOmegaGameplayEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOmegaGameplayEffect::BeginPlay()
{
	Super::BeginPlay();

	//Construct DamageFormula Object
	//LocalFormula = NewObject<UDamageFormula>(this, DamageFormula, FName("LocalFormula"));

	//Select What Lifetime to use.
	switch (EffectLifetime)
	{
	case EEffectLifetime::EffectLifetime_Instant:
		GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AOmegaGameplayEffect::LifetimeEnd, 0.1f, false);
		break;

	case EEffectLifetime::EffectLifetime_Timer:
		GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AOmegaGameplayEffect::LifetimeEnd, Lifetime, false);
		break;
	case EEffectLifetime::EffectLifetime_OnTrigger:
		//Do code
		break;
	case EEffectLifetime::EffectLifetime_OnDestroy:
		//Do code
		break;
	default: break;
	}

	//CorrectContext
	if(!EffectContext)
	{
		EffectContext = nullptr;
	}

	Local_RemoveEffects(RemoveEffectsOnApplied);
	
	if(TargetedCombatant)
	{
		TargetedCombatant->OnDamaged.AddDynamic(this, &AOmegaGameplayEffect::OnAttributeDamaged);
	}
	
	
}

void AOmegaGameplayEffect::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if(EndPlayReason == EEndPlayReason::Destroyed)
	{
		
	}
}



//Trigger the Effect
void AOmegaGameplayEffect::LifetimeEnd()
{
	TriggerEffect();
	K2_DestroyActor();
}



//####################################//####################################//####################################
//-----Generals
//####################################//####################################//####################################
void AOmegaGameplayEffect::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(EffectContext, Tag, Name, Description, iconBrush, Color, Label, MetaConfig);
	}
}


// Called every frame
void AOmegaGameplayEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

//Trigger the effects and destory this Effect Actor.
void AOmegaGameplayEffect::TriggerEffect()
{
	//Remove Effects
	//Local_RemoveEffects(RemoveEffectsOnTrigger);
	
	UE_LOG(LogTemp, Display, TEXT("Applied Effect"));
	
	if(EffectLifetime == EEffectLifetime::EffectLifetime_OnTrigger)
	{
		K2_DestroyActor();
	}
	
}

bool AOmegaGameplayEffect::EffectCanApply_Implementation(UCombatantComponent* EffectInstigator,
	UCombatantComponent* EffectTarget, UObject* Context, FOmegaCommonMeta Meta,FOmegaCommonMeta& OutMeta)
{
	OutMeta=Meta;
	return true;
}


UOmegaDamageType* AOmegaGameplayEffect::GetDamageType_Implementation(UObject* Context)
{
	return nullptr;
}


void AOmegaGameplayEffect::Local_RemoveEffects(FGameplayTagContainer Effects)
{
	if(TargetedCombatant)
	{
		for(auto* TempEffect: TargetedCombatant->GetEffectsWithTags(Effects))
		{
			if(TempEffect != this)
			{
				TempEffect->Destroy();
			}
		};
	}
}

//Tags
void AOmegaGameplayEffect::GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags)
{
	OutCategoryTag = EffectCategory;
	OutGameplayTags = EffectTags;
}

bool AOmegaGameplayEffect::L_ContextUsesInterface() const
{
	if (EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
	{
		return true;
	}
	return false;
}

float AOmegaGameplayEffect::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
                                                        UCombatantComponent* instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	if (L_ContextUsesInterface())
	{
		return IDataInterface_Combatant::Execute_ModifyDamage(EffectContext,Attribute, Target, instigator, BaseDamage, DamageType,
																	 Context);		
	}
	return IDataInterface_Combatant::ModifyDamage_Implementation(Attribute, Target, instigator, BaseDamage, DamageType,
	                                                             Context);
}

TArray<FOmegaAttributeModifier> AOmegaGameplayEffect::GetModifierValues_Implementation(
	UCombatantComponent* CombatantComponent)
{
	if (L_ContextUsesInterface())
	{
		return IDataInterface_Combatant::Execute_GetModifierValues(EffectContext,CombatantComponent);
	}
	return IDataInterface_Combatant::GetModifierValues_Implementation(CombatantComponent);
}

UPrimaryDataAsset* AOmegaGameplayEffect::GetDamageType_Weight_Implementation(UCombatantComponent* Combatant,
	UOmegaDamageType* DamageType, float& weight, int32& priority)
{
	if (L_ContextUsesInterface())
	{
		return IDataInterface_Combatant::Execute_GetDamageType_Weight(EffectContext,Combatant, DamageType, weight, priority);
	}
	return IDataInterface_Combatant::GetDamageType_Weight_Implementation(Combatant, DamageType, weight, priority);
}

