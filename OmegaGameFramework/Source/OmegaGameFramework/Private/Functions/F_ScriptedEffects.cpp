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
			FString str=out.ToString()+delimiter+UDataInterface_General::GetObjectDesc(a).ToString();
			out=FText::FromString(str);
		}
	}
	return out;
}

void UOmegaScriptedEffectAsset::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
                                                                  FText& Name, FText& Description)
{
	Name = EffectName;
	Description = EffectDescription;
}

void UOmegaScriptedEffectAsset::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = EffectIcon;
}

FText UOmegaScriptedEffectFunctions::GetEffects_Description(FOmegaCustomScriptedEffects effects,
	const FString& delimiter)
{
	FText out;
	for(auto* a :effects.GetAllEffects())
	{
		if(a)
		{
			FString str=out.ToString()+delimiter+UDataInterface_General::GetObjectDesc(a).ToString();
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
				UOmegaGameplayCueFunctions::PlayGameplayCue(Target,TempCue,FTransform(), FHitResult(),Target->GetOwner());
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
			UOmegaGameplayCueFunctions::PlayGameplayCue(Target,TempCue,FTransform(),FHitResult(),Target->GetOwner());
		}
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

void UOmegaScriptedEffectFunctions::ApplyScriptedEffects_Source(UObject* EffectAsset, UCombatantComponent* Target,
	UCombatantComponent* Instigator, FGameplayTag Tag)
{
	if(EffectAsset && EffectAsset->GetClass()->ImplementsInterface(UOmegaScriptedEffectsInterface::StaticClass()))
	{
		FOmegaCustomScriptedEffects ef;
		ApplyCustomScriptedEffectToCombatant(ef,Target,Instigator);
		IOmegaScriptedEffectsInterface::Execute_OnEffectsApplied(EffectAsset,Target,Instigator,Tag);
	}
}