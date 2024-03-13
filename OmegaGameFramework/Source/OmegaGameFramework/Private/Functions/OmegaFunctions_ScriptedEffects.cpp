// Copyright Studio Syndicat 2023. All Rights Reserved.


#include "Functions/OmegaFunctions_ScriptedEffects.h"

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

void UOmegaScriptedEffectFunctions::ApplyEffectScriptToCombatant(TArray<UOmegaScriptedEffect*> Effects,
	UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	for(auto* TempEffect : Effects)
	{
		if(TempEffect && TempEffect->CanApplyEffect(Target,Instigator))
		{
			TempEffect->OnEffectApplied(Target, Instigator);

			//Spawn Cues
			for(const TSubclassOf<AOmegaGameplayCue> TempCue : TempEffect->GetCuesToPlay())
			{
				UOmegaGameplayCueFunctions::PlayGameplayCue(Target,TempCue,FTransform(), FHitResult(),Target->GetOwner());
			}
		}
	}
}

void UOmegaScriptedEffectFunctions::ApplyScriptedEffectToCombatant(UOmegaScriptedEffectAsset* EffectAsset,
                                                                   UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	if(EffectAsset)
	{
		ApplyEffectScriptToCombatant(EffectAsset->ScriptedEffects,Target,Instigator);
		
		//Spawn Cues
		for(const TSubclassOf<AOmegaGameplayCue> TempCue : EffectAsset->GameplayCues)
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
		ApplyScriptedEffectToCombatant(TempAsset,Target,Instigator);
	}

	ApplyEffectScriptToCombatant(IncomingEffects.CustomEffects,Target,Instigator);
}
