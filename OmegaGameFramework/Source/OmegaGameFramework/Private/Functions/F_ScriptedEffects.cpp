// Copyright Studio Syndicat 2023. All Rights Reserved.


#include "Functions/F_ScriptedEffects.h"

#include "Actors/Actor_GameplayCue.h"
#include "Components/Component_Combatant.h"
#include "Kismet/GameplayStatics.h"


bool UOmegaScriptedEffect::OnEffectApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	return false;
}

TArray<TSubclassOf<AOmegaGameplayCue>> UOmegaScriptedEffect::GetCuesToPlay_Implementation()
{
	TArray<TSubclassOf<AOmegaGameplayCue>> OutVal;
	return OutVal;
}

bool UOmegaScriptedEffect::CanApplyEffect_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	return true;
}

TArray<UOmegaScriptedEffect*> FOmegaCustomScriptedEffects::GetAllEffects() const
{
	TArray<UOmegaScriptedEffect*> out=CustomEffects;
	for(auto* a : EffectAssets)
	{
		if(a)
		{
			out.Append(a->ScriptedEffects);
		}
	}
	return out;
}

FText FOmegaCustomScriptedEffects::GetEffectsDescription(const FString& delimiter) const
{
	FText out;
	for(auto* a : GetAllEffects())
	{
		if(a)
		{
			FString str=out.ToString()+delimiter+UDataInterface_General::GetObjectDesc(a,FGameplayTag()).ToString();
			out=FText::FromString(str);
		}
	}
	return out;
}

FText UOmegaScriptedEffectFunctions::GetEffects_Description(FOmegaCustomScriptedEffects effects,
	const FString& delimiter)
{
	FText out;
	for(auto* a :effects.GetAllEffects())
	{
		if(a)
		{
			FString str=out.ToString()+delimiter+UDataInterface_General::GetObjectDesc(a,FGameplayTag()).ToString();
			out=FText::FromString(str);
		}
	}
	return out;
}

void UOmegaScriptedEffectFunctions::ApplyScriptedEffects_List(TArray<UOmegaScriptedEffect*> Effects,
                                                                 UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	for(auto* TempEffect : Effects)
	{
		if(TempEffect && TempEffect->CanApplyEffect(Target,Instigator))
		{
			TempEffect->OnEffectApplied(Target, Instigator);

			//Spawn Cues
			for(const TSubclassOf<AOmegaGameplayCue>& TempCue : TempEffect->GetCuesToPlay())
			{
				UOmegaGameplayCueFunctions::PlayGameplayCue(Target,TempCue,FTransform(), FHitResult(),Target->GetOwner()->GetRootComponent());
			}
		}
	}
}

void UOmegaScriptedEffectFunctions::ApplyScriptedEffects_Asset(UOmegaScriptedEffectAsset* EffectAsset,
                                                                   UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	if(EffectAsset)
	{
		ApplyScriptedEffects_List(EffectAsset->ScriptedEffects,Target,Instigator);
		
		//Spawn Cues
		for(const TSubclassOf<AOmegaGameplayCue>& TempCue : EffectAsset->GameplayCues)
		{
			UOmegaGameplayCueFunctions::PlayGameplayCue(Target,TempCue,FTransform(),FHitResult(),Target->GetOwner()->GetRootComponent());
		}
	}
}

void UOmegaScriptedEffectFunctions::ApplyScriptedEffects_Source(
	TScriptInterface<IDataInterface_ScriptedEffects> EffectAsset, FGameplayTag Tag, UCombatantComponent* Target,
	UCombatantComponent* Instigator)
{
	if(EffectAsset.GetObject() && Target && Instigator)
	{
		FOmegaCustomScriptedEffects ef=IDataInterface_ScriptedEffects::Execute_GetScriptedEffects(EffectAsset.GetObject(),Tag);
		ApplyCustomScriptedEffectToCombatant(ef,Target,Instigator);
		IDataInterface_ScriptedEffects::Execute_OnEffectsApplied(EffectAsset.GetObject(),Target,Instigator,Tag);
	}
}



void UOmegaScriptedEffectFunctions::ApplyCustomScriptedEffectToCombatant(FOmegaCustomScriptedEffects Effects,
                                                                         UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	FOmegaCustomScriptedEffects IncomingEffects = Effects;

	for(auto* TempAsset : IncomingEffects.EffectAssets)
	{
		ApplyScriptedEffects_Asset(TempAsset,Target,Instigator);
	}

	ApplyScriptedEffects_List(IncomingEffects.CustomEffects,Target,Instigator);
}

