// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CombatantFunctions.h"
#include "Kismet/GameplayStatics.h"
#include "OmegaGameplaySubsystem.h"
#include "OmegaSettings.h"
#include "GameFramework/Pawn.h"
#include "OmegaUtilityFunctions.h"
#include "Attributes/OmegaAttributeSet.h"
#include "Gameplay/DataInterface_OmegaEffect.h"

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
			OutTargets.Add(Instigator->GetActiveTarget());
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
		const FTransform EmptyLoc;
		Instigator->CreateEffect(Effect.EffectClass, Effect.Power, Combatant, Effect.AddedTags, LocalContext);
	}
}

void UCombatantFunctions::ApplyEffectFromAsset(UCombatantComponent* Combatant, UCombatantComponent* Instigator,
	UObject* Asset)
{
	if(!Asset)
	{
		UE_LOG(LogTemp, Display, TEXT("Invalid Asset"));
		return;
	}
	if(Asset->GetClass()->ImplementsInterface(UDataInterface_OmegaEffect::StaticClass()))
	{
		UE_LOG(LogTemp, Display, TEXT("Applied Effects from asset"));
		for(const FOmegaEffectContainer TempEffect : IDataInterface_OmegaEffect::Execute_GetOmegaEffects(Asset))
		{
			ApplyEffectFromContainer(Combatant, Instigator, TempEffect, Asset);
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Does not implement interface"));
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

TArray<FOmegaAttributeModifier> UCombatantFunctions::FlatAttributesToModifierValues(
	TMap<UOmegaAttribute*, float> FlatAttributes,bool AsMultiplier)
{
	TArray<FOmegaAttributeModifier> out;
	TArray<UOmegaAttribute*> local_attributes;
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
	if(Combatant && Combatant->GetActiveTarget())
	{
		return Combatant->GetActiveTarget()->GetOwner()->GetDistanceTo(Combatant->GetOwner());
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
/*
void UCombatantFunctions::IsAttributeAtValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,  float Value,
	EComparisonMethod Method, TEnumAsByte<EOmegaBranch>& Outcome)
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
	float Percentage, EComparisonMethod Method, TEnumAsByte<EOmegaBranch>& Outcome)
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
                                               TEnumAsByte<EOmegaBranch>& Outcome)
{
	if(Combatant && Combatant->CombatantHasTag(Tag))
	{
		Outcome = EOmegaBranch::Yes;
	}
	else
	{
		Outcome = EOmegaBranch::No;
	}
}

void UCombatantFunctions::DoesCombatantHaveEffectWithTag(UCombatantComponent* Combatant, FGameplayTagContainer Tags,
	TEnumAsByte<EOmegaBranch>& Outcome)
{
	if(Combatant && Combatant->HasEffectWithTags(Tags))
	{
		Outcome = EOmegaBranch::Yes;
	}
	else
	{
		Outcome = EOmegaBranch::No;
	}
}
