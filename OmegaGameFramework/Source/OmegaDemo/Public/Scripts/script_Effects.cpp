// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "script_Effects.h"

#include "Actors/Actor_GameplayEffect.h"
#include "Components/Component_Combatant.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/HitResult.h"

FHitResult l_CalcHit(UCombatantComponent* Target,UCombatantComponent* Instigator)
{
	if(Target && Instigator)
	{
		FHitResult hit;

		return hit;
	}
	return FHitResult();
}

float l_scaleVal(UCombatantComponent* comb,UOmegaAttribute* att, float scale)
{
	if(comb && att)
	{
		float v_c;
		float v_m;
		comb->GetAttributeValue(att,v_c,v_m);

		return scale*v_m;
	}
	return 0.0;
}

bool UEffectScript_FlipTargets::OnEffectApplied_Implementation(UCombatantComponent* Target,
                                                               UCombatantComponent* Instigator)
{
	if(Target && Instigator)
	{
		for(auto* e : Effects)
		{
			if(e)
			{
				e->OnEffectApplied(Instigator,Target);
			}
		}
	}
	return true;
}

bool UEffectScript_EffectActorAdd::OnEffectApplied_Implementation(UCombatantComponent* Target,
	UCombatantComponent* Instigator)
{
	if(Instigator && Target && Class)
	{
		Target->CreateEffect(Class,Instigator,Context);
	}
	return true;
}

float UEffectScript_EffectActorAdd::GetEffectUtilityScore_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	if(!Target || !Instigator) return 0.0f;
	EFactionAffinity Affinity = Instigator->GetAffinityToCombatant(Target);
	float Score = Power;
	if(Utility_Target != EFactionAffinity::NeutralAffinity && Affinity != EFactionAffinity::NeutralAffinity && Utility_Target != Affinity)
		Score *= -1.0f;
	return Score;
}

bool UEffectScript_EffectActorRemove::OnEffectApplied_Implementation(UCombatantComponent* Target,
	UCombatantComponent* Instigator)
{
	if(Instigator && Target)
	{
		for(TSubclassOf<AOmegaGameplayEffect> c : Classes_Removed)
		{
			if(c)
			{
				bool val;
				if(AOmegaGameplayEffect* ef=Target->GetActiveEffectOfClass(c,val))
				{
					ef->K2_DestroyActor();
				}
			}
		}
		Target->RemoveEffectsWithTags(Tags_Removed);
	}
	return true;
}

float UEffectScript_EffectActorRemove::GetEffectUtilityScore_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	if(!Target || !Instigator) return 0.0f;
	EFactionAffinity Affinity = Instigator->GetAffinityToCombatant(Target);
	float Score = (float)(Classes_Removed.Num() + Tags_Removed.Num());
	if(Utility_Target != EFactionAffinity::NeutralAffinity && Affinity != EFactionAffinity::NeutralAffinity && Utility_Target != Affinity)
		Score *= -1.0f;
	return Score;
}

bool UEffectScript_DamageFlat::OnEffectApplied_Implementation(UCombatantComponent* Target,
                                                              UCombatantComponent* Instigator)
{
	if(Target && DamagedAttribute)
	{
		float in_amount=Amount;
		if(bIsPercentage)
		{
			float v_c;
			float v_m;
			Target->GetAttributeValue(DamagedAttribute,v_c,v_m);
			in_amount=Amount*v_m;
		}
		Target->ApplyAttributeDamage(DamagedAttribute,in_amount,Instigator,nullptr,DamageType,l_CalcHit(Target,Instigator));
	}
	return true;
}

float UEffectScript_DamageFlat::GetEffectUtilityScore_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	float Score = Amount;
	if(bIsPercentage && Target && DamagedAttribute)
	{
		float v_c, v_m;
		Target->GetAttributeValue(DamagedAttribute, v_c, v_m);
		Score = Amount * v_m;
	}
	if(Target && Instigator && Instigator->GetAffinityToCombatant(Target) == EFactionAffinity::FriendlyAffinity)
		Score *= -1.0f;
	return Score;
}

void UEffectScript_DamageFlat::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
}


bool UEffectScriptBASE_DamagePercent::OnEffectApplied_Implementation(UCombatantComponent* Target,
                                                                     UCombatantComponent* Instigator)
{
	if(Target)
	{
		UOmegaAttribute* DamagedAttribute;
		UOmegaDamageType* DamageType;
		float Variance=0.05;
		float MinDamage=0.0;
		float MaxDamage=99999.0;
		UOmegaAttribute* Instigator_Attribute;
		float Instigator_Power=1.0;
		UOmegaAttribute* Target_Attribute;
		float Target_Power=0.5;

		GetEffectParameters(DamagedAttribute,DamageType,Variance,MinDamage,MaxDamage,Instigator_Attribute,Instigator_Power,Target_Attribute,Target_Power);

		if(DamagedAttribute)
		{
			float val_inst=l_scaleVal(Target,Instigator_Attribute,Instigator_Power);
			float val_targ=l_scaleVal(Target,Target_Attribute,Target_Power);

			float dmg=UKismetMathLibrary::FClamp(val_inst-val_targ,MinDamage,MaxDamage);
			dmg=UKismetMathLibrary::RandomFloatInRange(Variance*-1,Variance)*dmg+dmg;
		
			Target->ApplyAttributeDamage(DamagedAttribute,dmg,Instigator,nullptr,DamageType,l_CalcHit(Target,Instigator));
		}
	}
	return true;
}


float UEffectScriptBASE_DamagePercent::GetEffectUtilityScore_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator)
{
	if(!Target) return 0.0f;
	UOmegaAttribute* DamagedAttribute = nullptr;
	UOmegaDamageType* DamageType = nullptr;
	float Variance = 0.05f, MinDamage = 0.0f, MaxDamage = 99999.0f, Instigator_Power = 1.0f, Target_Power = 0.5f;
	UOmegaAttribute* Instigator_Attribute = nullptr;
	UOmegaAttribute* Target_Attribute = nullptr;
	GetEffectParameters(DamagedAttribute, DamageType, Variance, MinDamage, MaxDamage, Instigator_Attribute, Instigator_Power, Target_Attribute, Target_Power);
	float Score = UKismetMathLibrary::FClamp(l_scaleVal(Target, Instigator_Attribute, Instigator_Power) - l_scaleVal(Target, Target_Attribute, Target_Power), MinDamage, MaxDamage);
	if(Instigator && Instigator->GetAffinityToCombatant(Target) == EFactionAffinity::FriendlyAffinity)
		Score *= -1.0f;
	return Score;
}

void UEffectScript_DamagePercent::GetEffectParameters_Implementation(UOmegaAttribute*& _DamagedAttribute,
	UOmegaDamageType*& _DamageType, float& _Variance, float& _MinDamage, float& _MaxDamage,
	UOmegaAttribute*& _Instigator_Attribute, float& _Instigator_Power, UOmegaAttribute*& _Target_Attribute,
	float& _Target_Power)
{
	_DamagedAttribute=DamagedAttribute;
	_DamageType=DamageType;
	_Variance=Variance;
	_MinDamage=MinDamage;
	_MaxDamage=MaxDamage;
	_Instigator_Attribute=Instigator_Attribute;
	_Instigator_Power=Instigator_Power;
	_Target_Attribute=Target_Attribute;
	_Target_Power=Target_Power;
}

bool UEffectScript_Inv_Edit::OnEffectApplied_Implementation(UCombatantComponent* Target,
	UCombatantComponent* Instigator)
{
	if (Instigator && bTransferFromInstigator)
	{
		Instigator->Inventory_AddList(ItemsGiven,true);
	}
	if (Target)
	{
		Target->Inventory_AddList(ItemsGiven,false);	
	}
	return true;
}

bool UEffectScript_Equip_Edit::OnEffectApplied_Implementation(UCombatantComponent* Target,
	UCombatantComponent* Instigator)
{
	if (Target)
	{
		for (auto* s : SlotsCleared)
		{
			if (s)
			{
				Target->Equipment_ClearSlot(s);
			}
		}
		
		TArray<UEquipmentSlot*> _slot;
		EquipmentAdded.GetKeys(_slot);
		for (auto* s : _slot)
		{
			if (s)
			{
				Target->Equipment_SetInSlot(EquipmentAdded.FindOrAdd(s),s);
			}
		}
	}
	
	return true;
}

void UEffectScriptBASE_DamagePercent::GetEffectParameters_Implementation(UOmegaAttribute*& _DamagedAttribute,
                                                                         UOmegaDamageType*& _DamageType, float& _Variance, float& _MinDamage, float& _MaxDamage,
                                                                         UOmegaAttribute*& _Instigator_Attribute, float& Instigator_Power, UOmegaAttribute*& _Target_Attribute,
                                                                         float& _Target_Power)
{
	
}
