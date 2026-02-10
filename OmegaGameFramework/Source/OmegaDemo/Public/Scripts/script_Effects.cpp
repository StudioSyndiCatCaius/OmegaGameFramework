// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "script_Effects.h"

#include "Actors/Actor_GameplayEffect.h"
#include "Components/Component_Combatant.h"
#include "Kismet/KismetMathLibrary.h"

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
		Instigator->CreateEffect(Class,Power,Target,Tags,Context);
	}
	return true;
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

void UEffectScript_DamageFlat::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
	FText& Name, FText& Description)
{
	Super::GetGeneralDataText_Implementation(Label, Context, Name, Description);
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

void UEffectScriptBASE_DamagePercent::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
	FText& Name, FText& Description)
{
	Super::GetGeneralDataText_Implementation(Label, Context, Name, Description);
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

void UEffectScriptBASE_DamagePercent::GetEffectParameters_Implementation(UOmegaAttribute*& _DamagedAttribute,
                                                                         UOmegaDamageType*& _DamageType, float& _Variance, float& _MinDamage, float& _MaxDamage,
                                                                         UOmegaAttribute*& _Instigator_Attribute, float& Instigator_Power, UOmegaAttribute*& _Target_Attribute,
                                                                         float& _Target_Power)
{
	
}
