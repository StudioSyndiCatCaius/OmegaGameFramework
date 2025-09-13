// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_Combatant.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "OmegaSettings.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Components/Component_Combatant.h"
#include "Condition/Condition_Combatant.h"
#include "Functions/OmegaFunctions_Animation.h"
#include "Functions/OmegaFunctions_AVContext.h"
#include "GameFramework/Pawn.h"
#include "Functions/OmegaFunctions_Utility.h"
#include "GameFramework/Character.h"
#include "Misc/Attribute.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"
#include "Types/Struct_Combatant.h"


TArray<UCombatantComponent*> UCombatantFunctions::FilterCombatantsByTags(
	TArray<UCombatantComponent*> Combatants, FGameplayTagContainer Tags, bool bExact, bool bExclude)
{
	TArray<UCombatantComponent*> OutCombatants;
	for(UCombatantComponent* TempCombatant : Combatants)
	{
		bool bDoesMatch = false;
		bDoesMatch = TempCombatant->CombatantHasAnyTag(Tags, bExact);
		if(bDoesMatch != bExclude)
		{
			OutCombatants.Add(TempCombatant);
		}
	}
	return OutCombatants;
}

TArray<UCombatantComponent*> UCombatantFunctions::FilterCombatantsByFaction(
	TArray<UCombatantComponent*> Combatants, FGameplayTag Faction, bool bExclude)
{
	TArray<UCombatantComponent*> OutCombatants;

	for(UCombatantComponent* TempCombatant : Combatants)
	{
		//Check if correct faction to include/exclude
		if((TempCombatant->GetFactionTag() == Faction) != bExclude)
		{
			OutCombatants.Add(TempCombatant);
		}
	}
	
	return OutCombatants;
}

AOmegaGameplayEffect* UCombatantFunctions::SelectFirstEffectWithContext(TArray<AOmegaGameplayEffect*> Effects,
	UObject* Context, bool& Result)
{
	for(auto* e : Effects)
	{
		if(e && e->EffectContext==Context)
		{
			Result=true;
			return e;
		}
	}
	Result=false;
	return nullptr;
}

void UCombatantFunctions::RemoveGameplayEffects_WithContext(UCombatantComponent* Combatant, UObject* Context)
{
	if(Combatant && Context)
	{
		for(auto* e : Combatant->GetAllEffects())
		{
			if(e && e->EffectContext==Context)
			{
				e->K2_DestroyActor();
			}
		}
	}
}

void UCombatantFunctions::RemoveGameplayEffects_OfClass(UCombatantComponent* Combatant,
	TSubclassOf<AOmegaGameplayEffect> EffectClass, bool bIncludeChildTypes)
{
	if(Combatant && EffectClass)
	{
		for(auto* e : Combatant->GetAllEffects())
		{
			if(e && (e->GetClass()==EffectClass || (bIncludeChildTypes && e->GetClass()->IsChildOf(EffectClass))))
			{
				e->K2_DestroyActor();
			}
		}
	}
}



bool UCombatantFunctions::CheckCombatantConditions(UCombatantComponent* Combatant,
	FOmegaConditions_Combatant Conditions)
{
	if(Combatant)
	{
		return Conditions.CheckConditions(Combatant);
	}
	return true;
}

UCombatantComponent* UCombatantFunctions::GetCombatantWithHighestAttributeValue(TArray<UCombatantComponent*> Combatants,
                                                                                UOmegaAttribute* Attribute, bool bUseCurrentValue)
{
	float LastHighestValue = -1.0;
	UCombatantComponent* OutCombatant = nullptr;
	for(auto* TempCombatant : Combatants)
	{
		if(TempCombatant)
		{
			float CurrentVal;
			float MaxVal;
			TempCombatant->GetAttributeValue(Attribute, CurrentVal, MaxVal);

			if(bUseCurrentValue && CurrentVal > LastHighestValue)
			{
				OutCombatant = TempCombatant;
				LastHighestValue = CurrentVal;
			}
			else if(!bUseCurrentValue && MaxVal > LastHighestValue)
			{
				OutCombatant = TempCombatant;
                LastHighestValue = MaxVal;
			}
		}
	}
	return OutCombatant;
}

TArray<UCombatantComponent*> UCombatantFunctions::GetCombatantFromTargetSelection(UCombatantComponent* Instigator,
	EOmegaCombatTarget Selection)
{
	TArray<UCombatantComponent*> OutTargets;
	if(Instigator)
	{
		switch (Selection) {
		case Target_Self:
			OutTargets.Add(Instigator);
			break;
		case Target_ActiveTarget:
			OutTargets.Add(Instigator->Native_GetActiveTarget());
			break;
		case Target_AllTargets:
			OutTargets=Instigator->GetRegisteredTargetList();
			break;
		default: ;
		}
	}
	return OutTargets;
}

void UCombatantFunctions::ApplyEffectFromContainer(UCombatantComponent* Combatant, UCombatantComponent* Instigator, FOmegaEffectContainer Effect, UObject* Context)
{
	if(Combatant && Effect.EffectClass)
	{
		UObject* LocalContext;
		if(Context)
		{
			LocalContext = Context;
		}
		else
		{
			LocalContext = Instigator;
		}
		Instigator->CreateEffect(Effect.EffectClass, Effect.Power, Combatant, Effect.AddedTags, LocalContext);
	}
}


UCombatantComponent* UCombatantFunctions::GetPlayerCombatant(const UObject* WorldContextObject, int32 Index)
{
	if(APawn* TempPawn = UGameplayStatics::GetPlayerPawn(WorldContextObject, Index))
	{
		if(TempPawn->GetComponentByClass(UCombatantComponent::StaticClass()))
		{
			return Cast<UCombatantComponent>(TempPawn->GetComponentByClass(UCombatantComponent::StaticClass()));
		}
	}
	return nullptr;
}

void UCombatantFunctions::NotifyCombatantFaction(const UObject* WorldContextObject, FGameplayTag Faction, FName Notify)
{
	TArray<UCombatantComponent*> LocalList = WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetAllCombatants();

	for(auto* TempComb : LocalList)
	{
		if(TempComb->GetFactionTag() == Faction)
		{
			TempComb->CombatantNotify(Notify,"");
		}
	}
}

void UCombatantFunctions::NotifyCombatant_FactionOfTag(const UObject* WorldContextObject, FGameplayTag Tag,
	FName Notify)
{
	TArray<UCombatantComponent*> LocalList = WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetAllCombatants();

	for(auto* TempComb : LocalList)
	{
		if(TempComb->GetCombatantTags().HasTagExact(Tag))
		{
			TempComb->CombatantNotify(Notify,"");
		}
	}
}


UOmegaAttribute* UCombatantFunctions::GetAttributeByUniqueID(const FString& ID)
{
	TMap<FString, FSoftObjectPath> LocalAID = GetMutableDefault<UOmegaSettings>()->AttributeIDs;
	FSoftObjectPath LocalAttributePath = LocalAID.FindOrAdd(ID);
	if(LocalAttributePath.IsValid())
	{
		return LoadObject<UOmegaAttribute>(NULL, *LocalAttributePath.ToString());
	}
	return nullptr;
}

TArray<FOmegaAttributeModifier> UCombatantFunctions::MakeAttributeMods_FromFlatValues(
	TMap<UOmegaAttribute*, float> FlatAttributes,bool AsMultiplier)
{
	TArray<FOmegaAttributeModifier> out;
	TArray<UOmegaAttribute*> local_attributes;
	FlatAttributes.GetKeys(local_attributes);
	for(auto* a: local_attributes)
	{
		FOmegaAttributeModifier new_mod;
		new_mod.Attribute=a;
		float local_val = FlatAttributes[a];
		if(AsMultiplier)
		{
			new_mod.Multiplier=local_val;
		}
		else
		{
			new_mod.Incrementer=local_val;
		}
		out.Add(new_mod);
	}
	return out;
}

TArray<FOmegaAttributeModifier> UCombatantFunctions::MakeAttributeMods_FromFlatIntValues(
	TMap<UOmegaAttribute*, int32> FlatAttributes, bool AsMultiplier)
{
	TMap<UOmegaAttribute*, float> in;
	for(auto& p : FlatAttributes)
	{
		in.Add(p.Key,p.Value);
	}
	return MakeAttributeMods_FromFlatValues(in,AsMultiplier);
}

void UCombatantFunctions::CompareSingleAttributeModifiers(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
                                                          UObject* ComparedSource, UObject* UncomparedSource, float& NewValue, float& OldValue)
{
	if(Combatant && Attribute)
	{
		TArray<FOmegaAttributeModifier> outMods=IDataInterface_AttributeModifier::Execute_GetModifierValues(Combatant,Combatant);
		if(UncomparedSource && UncomparedSource->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			TArray<FOmegaAttributeModifier> mods_newOut;
			TArray<FOmegaAttributeModifier> mods_UnComp=IDataInterface_AttributeModifier::Execute_GetModifierValues(UncomparedSource,Combatant);
			for (FOmegaAttributeModifier temp_CombatantMod : outMods)
			{
				for (FOmegaAttributeModifier temp_UncomparedMod : mods_UnComp)
				{
					if(!(temp_UncomparedMod.Attribute==temp_CombatantMod.Attribute
						&& temp_UncomparedMod.Incrementer==temp_CombatantMod.Incrementer
						&& temp_UncomparedMod.Multiplier==temp_CombatantMod.Multiplier))
					{
						mods_newOut.Add(temp_CombatantMod);
					}
				}
			}
			outMods=mods_newOut;
		}
		if(ComparedSource && ComparedSource->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			outMods.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(ComparedSource,Combatant));
		}
		
		float curval;
		Combatant->GetAttributeValue(Attribute,curval,OldValue);
		NewValue=Combatant->AdjustAttributeValueByModifiers(Attribute,outMods);
	}
}

bool UCombatantFunctions::CanCombatantUseSkill(UCombatantComponent* Combatant, UObject* SkillObject)
{
	if(Combatant && SkillObject)
	{
		if(SkillObject->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
		{
			if(!IDataInterface_Skill::Execute_CanUseSkill(SkillObject,Combatant))
			{
				return false;
			}
			TArray<UOmegaAttribute*> att_list;
			TMap<UOmegaAttribute*, float> att_vals = IDataInterface_Skill::Execute_GetSkillAttributeCosts(
				SkillObject, Combatant, nullptr);
			att_vals.GetKeys(att_list);
			for(auto* TempAtt : att_list)
			{
				if(TempAtt)
				{
					float val_cur; float val_max;
					Combatant->GetAttributeValue(TempAtt, val_cur,val_max);
					if(val_cur<att_vals[TempAtt])
					{
						return false; // return false if even 1 attribute is insufficient
					}
				}
			}
		}
		return true;
	}
	return false;
}

bool UCombatantFunctions::ConsumeSkillAttributes(UCombatantComponent* Combatant, UObject* SkillObject)
{
	if(!Combatant || !SkillObject) { return false; }
	
	if(CanCombatantUseSkill(Combatant,SkillObject))
	{
		if(SkillObject->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
		{
			TArray<UOmegaAttribute*> att_list;
			TMap<UOmegaAttribute*, float> att_vals = IDataInterface_Skill::Execute_GetSkillAttributeCosts(
				SkillObject, Combatant, nullptr);
			att_vals.GetKeys(att_list);
			
			for(auto* TempAtt : att_list)
			{
				if(TempAtt)
				{
					Combatant->ApplyAttributeDamage(TempAtt,att_vals[TempAtt],nullptr,nullptr,nullptr,FHitResult());
				}
			}
		}
		return true;
	}
	return false;
}

/*
TMap<UOmegaAttribute*, float> UCombatantFunctions::CompareAttributeModifiers(UCombatantComponent* Combatant,
	UObject* ComparedModifier, UObject* UncomparedModifer)
{
	TMap<UOmegaAttribute*, float> OutMap;
	
	if(Combatant)
	{
		TArray<FOmegaAttributeModifier> TempMods = Combatant->GetAllModifierValues();

		//Remove modifiers from Uncomapred Value
		if(UncomparedModifer && UncomparedModifer->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			for(const FOmegaAttributeModifier TempMod : IDataInterface_AttributeModifier::Execute_GetModifierValues(UncomparedModifer))
			{
				TempMods.Remove(TempMod);
			}
		}

		//Add compared values
		if(ComparedModifier && ComparedModifier->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			TempMods.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(ComparedModifier));
		}

		//Add attributes to map
		for(auto* TempAtt : Combatant->AttributeSet->Attributes)
		{
			OutMap.Add(TempAtt, Combatant->AdjustAttributeValueByModifiers(TempAtt, TempMods));
		}
	}
	return OutMap;
}


float UCombatantFunctions::CompareSingleAttributeModifiers(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
	UObject* ComparedModifier, UObject* UncomparedModifer)
{
	if(Attribute)
	{
		TMap<UOmegaAttribute*, float> OutMap=CompareAttributeModifiers(Combatant, ComparedModifier, UncomparedModifer);
		return OutMap.FindOrAdd(Attribute);
	}
	return 0;
}
*/

float UCombatantFunctions::GetCombatantDistantToActiveTarget(UCombatantComponent* Combatant)
{
	if(Combatant && Combatant->Native_GetActiveTarget())
	{
		return Combatant->Native_GetActiveTarget()->GetOwner()->GetDistanceTo(Combatant->GetOwner());
	}
	return 0;
}

bool UCombatantFunctions::IsCombatantActiveTargetInRange(UCombatantComponent* Combatant, float Range)
{
	if (Combatant && GetCombatantDistantToActiveTarget(Combatant)<=Range)
	{
		return true;
	}
	return false;
}

void UCombatantFunctions::IsCombatantOfFaction(UCombatantComponent* Combatant, UOmegaFaction* Faction,
	bool& Outcome)
{
	if(Combatant && Combatant->FactionDataAsset==Faction)
	{
		Outcome=true;
		return;
	}
	Outcome=false;
	return;
}

TArray<UCombatantComponent*> UCombatantFunctions::GetAllCombatantsWithDataAsset(UObject* WorldContextObject,
                                                                                UPrimaryDataAsset* Asset)
{
	TArray<UCombatantComponent*> out;
	if (WorldContextObject && Asset)
	{
		for (auto* c : WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetAllCombatants())
		{
			if(c && c->CombatantDataAsset==Asset)
			{
				out.Add(c);
			}
		}
	}
	return out;
}

TArray<UPrimaryDataAsset*> UCombatantFunctions::GetDataAssetsFromCombatants(TArray<UCombatantComponent*> Combatants)
{
	TArray<UPrimaryDataAsset*> out;
	for(auto* c : Combatants)
	{
		if(c && c->GetSourceDataAsset())
		{
			out.Add(c->GetSourceDataAsset());
		}
	}
	return out;
}

UCombatantComponent* UCombatantFunctions::GetFirstCombatantWithDataAsset(UObject* WorldContextObject,
                                                                         UPrimaryDataAsset* Asset, bool& Outcome)
{
	TArray<UCombatantComponent*> list=GetAllCombatantsWithDataAsset(WorldContextObject,Asset);
	if(list.IsValidIndex(0))
	{
		Outcome=true;
		return list[0];
	}
	Outcome=false;
	return nullptr;
}

TArray<UCombatantComponent*> UCombatantFunctions::GetAllCombatants_OfFaction(UObject* WorldContextObject,
	UOmegaFaction* Faction)
{
	TArray<UCombatantComponent*> out;
	if (WorldContextObject && Faction)
	{
		for (auto* c : WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetAllCombatants())
		{
			if(c && c->FactionDataAsset==Faction)
			{
				out.Add(c);
			}
		}
	}
	return out;
}

UCombatantComponent* UCombatantFunctions::SelectFirstCombatantWithDataAsset(TArray<UCombatantComponent*> Combatants,
                                                                            UPrimaryDataAsset* Asset, bool& Outcome)
{
	for (auto* c : Combatants)
	{
		if(c && c->CombatantDataAsset==Asset)
		{
			Outcome=true;
			return  c;
		}
	}
	Outcome=false;
	return nullptr;
}

UCombatantComponent* UCombatantFunctions::SelectFirstCombatant_WithTag(TArray<UCombatantComponent*> Combatants,
	FGameplayTag Tag, bool& Outcome)
{
	for (auto* c : Combatants)
	{
		if(c && c->CombatantHasTag(Tag))
		{
			Outcome=true;
			return  c;
		}
	}
	Outcome=false;
	return nullptr;
}



/*
void UCombatantFunctions::IsAttributeAtValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,  float Value,
	EComparisonMethod Method, bool& Outcome)
{
	if(Combatant)
	{
		float CurVal;
		float MaxVal;
		Combatant->GetAttributeValue(Attribute,CurVal,MaxVal);

		if(const bool OutVal = UOmegaUtilityFunctions::CompareFloatValues(CurVal,Value,Method))
		{
			Outcome = EOmegaBranch::Yes;
		}
		else
		{
			Outcome = EOmegaBranch::No;
		}
	}
}

void UCombatantFunctions::IsAttributeAtPercentage(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
	float Percentage, EComparisonMethod Method, bool& Outcome)
{
	if(Combatant)
	{
		if(const bool OutVal = UOmegaUtilityFunctions::CompareFloatValues(Combatant->GetAttributePercentage(Attribute),Percentage,Method))
		{
			Outcome = EOmegaBranch::Yes;
		}
		else
		{
			Outcome = EOmegaBranch::No;
		}
	}
}
*/
void UCombatantFunctions::DoesCombatantHaveTag(UCombatantComponent* Combatant, FGameplayTag Tag,
                                               bool& Outcome)
{
	if(Combatant && Combatant->CombatantHasTag(Tag))
	{
		Outcome=true;
	}
	else
	{
		Outcome=false;
	}
}

void UCombatantFunctions::DoesCombatantHaveEffectWithTag(UCombatantComponent* Combatant, FGameplayTagContainer Tags,
	bool& Outcome)
{
	if(Combatant && Combatant->HasEffectWithTags(Tags))
	{
		Outcome=true;
	}
	else
	{
		Outcome=false;
	}
}




