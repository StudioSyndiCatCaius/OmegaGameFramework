// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Combatant.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/Subsystem_World.h"
#include "OmegaSettings.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Components/Component_Combatant.h"
#include "Condition/Condition_Combatant.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "Functions/F_Animation.h"
#include "Functions/F_CombatantSelector.h"
#include "GameFramework/Pawn.h"
#include "Functions/F_Utility.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Misc/Attribute.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Skill.h"
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




float UCombatantUtility_Script::CheckUtility_Implementation(UCombatantComponent* Combatant,
	const TArray<UCombatantComponent*>& Targets, FGameplayTag UtilityTag, FOmegaCommonMeta meta) const
{
	return 0.0;
}

float FCombatantUtility_Container::CheckUtility(UCombatantComponent* Combatant, TArray<UCombatantComponent*> Targets,
                                                FGameplayTag UtilityTag, FOmegaCommonMeta meta)
{
	return 0.0;
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
		Combatant->CreateEffect(Effect.EffectClass, Instigator, LocalContext,FOmegaCommonMeta());
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
	TArray<UCombatantComponent*> LocalList = WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetAllCombatants();

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
	TArray<UCombatantComponent*> LocalList = WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetAllCombatants();

	for(auto* TempComb : LocalList)
	{
		if(TempComb->GetCombatantTags().HasTagExact(Tag))
		{
			TempComb->CombatantNotify(Notify,"");
		}
	}
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

TArray<FOmegaAttributeModifier> UCombatantFunctions::AttributeMods_Scale(TArray<FOmegaAttributeModifier> In,
	float Scale, bool bIncrements, bool bMultipliers)
{
	TArray<FOmegaAttributeModifier> out;
	
	for (FOmegaAttributeModifier mod : In)
	{
		FOmegaAttributeModifier new_mod;
		new_mod.Attribute=mod.Attribute;
		if (bIncrements)
		{
			new_mod.Multiplier=mod.Multiplier*Scale;	
		}
		if (bMultipliers)
		{
			new_mod.Incrementer=mod.Incrementer*Scale;	
		}
		out.Add(new_mod);
	}
	
	return out;
}

TArray<FOmegaAttributeModifier> UCombatantFunctions::AttributeMods_Flatten(TArray<FOmegaAttributeModifier> In)
{
	TMap<UOmegaAttribute*, float> att_inc;
	TMap<UOmegaAttribute*, float> att_scal;
	TArray<UOmegaAttribute*> local_attributes;
	
	for (FOmegaAttributeModifier mod : In)
	{
		if (mod.Attribute)
		{
			att_inc.Add(mod.Attribute,att_inc.FindOrAdd(mod.Attribute)+mod.Incrementer);
			att_scal.Add(mod.Attribute,att_scal.FindOrAdd(mod.Attribute)+mod.Multiplier);
			
			if (!local_attributes.Contains(mod.Attribute))
			{
				local_attributes.Add(mod.Attribute);
			}
		}
	}
	
	TArray<FOmegaAttributeModifier> out;
	for (auto* at :local_attributes)
	{
		FOmegaAttributeModifier new_mod;
		new_mod.Attribute=at;
		new_mod.Incrementer=att_inc.FindOrAdd(at);
		new_mod.Multiplier=att_scal.FindOrAdd(at);
		out.Add(new_mod);
	}
	return out;
}

TArray<FOmegaAttributeModifier> UCombatantFunctions::AttributeMods_Combine(TArray<FOmegaAttributeModifier> A,
	TArray<FOmegaAttributeModifier> B, bool Flatten)
{
	TArray<FOmegaAttributeModifier> out=A;
	out.Append(B);
	if (Flatten)
	{
		out=AttributeMods_Flatten(out);
	}
	return out;
}

TArray<FOmegaAttributeModifier> UCombatantFunctions::AttributeMods_GetAllFromObject(UObject* Object)
{
	TArray<FOmegaAttributeModifier> out;
	
	if (Object && Object->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
	{
		out=IDataInterface_Combatant::Execute_GetModifierValues(Object,nullptr);
		out.Append(IDataInterface_Combatant::Execute_Combatant_GetScriptedModifiers(Object).GatherAttributeModifiers(nullptr));

		out=AttributeMods_Flatten(out);
	}
	
	return out;
}

void UCombatantFunctions::AttributeMods_GetSingleValue(TArray<FOmegaAttributeModifier> mods, UOmegaAttribute* Attribute,
                                                       float& Increment, float& Multiplier)
{
	TArray<FOmegaAttributeModifier> InMods=AttributeMods_Flatten(mods);
	for (FOmegaAttributeModifier m : InMods)
	{
		if (m.Attribute==Attribute)
		{
			Increment=m.Incrementer;
			Multiplier=m.Multiplier;
			return;
		}
	}
}

TArray<UOmegaAttribute*> UCombatantFunctions::AttributeMods_GetAttributeList(TArray<FOmegaAttributeModifier> mods)
{
	TArray<FOmegaAttributeModifier> InMods=AttributeMods_Flatten(mods);
	TArray<UOmegaAttribute*> out;
	for (FOmegaAttributeModifier m : InMods)
	{
		if (m.Attribute)
		{
			out.Add(m.Attribute);	
		}
	}
	return out;
}

void UCombatantFunctions::CompareSingleAttributeModifiers(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
                                                          UObject* ComparedSource, UObject* UncomparedSource, float& NewValue, float& OldValue)
{
	if(Combatant && Attribute)
	{
		TArray<FOmegaAttributeModifier> outMods=IDataInterface_Combatant::Execute_GetModifierValues(Combatant,Combatant);
		if(UncomparedSource && UncomparedSource->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
		{
			TArray<FOmegaAttributeModifier> mods_newOut;
			TArray<FOmegaAttributeModifier> mods_UnComp=IDataInterface_Combatant::Execute_GetModifierValues(UncomparedSource,Combatant);
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
		if(ComparedSource && ComparedSource->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
		{
			outMods.Append(IDataInterface_Combatant::Execute_GetModifierValues(ComparedSource,Combatant));
		}
		
		float curval;
		Combatant->GetAttributeValue(Attribute,curval,OldValue);
		NewValue=Combatant->AdjustAttributeValueByModifiers(Attribute,outMods);
	}
}

bool UCombatantFunctions::CanCombatantUseSkill(UCombatantComponent* Combatant, UObject* SkillObject, bool bCheckAttributeCost)
{
	if(Combatant && SkillObject)
	{
		if(SkillObject->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
		{
			if(!IDataInterface_Skill::Execute_CanUseSkill(SkillObject,Combatant))
			{
				return false;
			}
			
			FOmegaSkillConfig SkillConfig=IDataInterface_Skill::Execute_Skill_GetConfig(SkillObject,Combatant);
			
			if (!SkillConfig.UseRequiredSkills.IsEmpty())
			{
				TArray<UPrimaryDataAsset*> combSkills=Combatant->GetAllSkills();
				for (auto* s : SkillConfig.UseRequiredSkills)
				{
					if (!combSkills.Contains(s)) {return false;}
				}
			}
			
			if (bCheckAttributeCost)
			{
				TArray<UOmegaAttribute*> att_list;
				
				TMap<UOmegaAttribute*, float> att_vals = SkillConfig.AttributeUseCost;
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
		}
		return true;
	}
	return false;
}

void UCombatantFunctions::GetSkillUtilityScore(UCombatantComponent* Combatant, UPrimaryDataAsset* Skill,
	TArray<UCombatantComponent*> Targets, float& Score,float& ScoreAverage)
{
	if (!Skill || !Skill->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass())) return;
	if (!IDataInterface_Skill::Execute_CanUseSkill(Skill, Combatant)) return;
	
	float targetNum = 0;
	
	for (UCombatantComponent* Target : Targets)
	{
		if (Target)
		{
			float score=IDataInterface_Skill::Execute_Skill_CheckUtility(Skill, Combatant, Target);
			targetNum+=1;
			Score+=score;
		}
	}

	ScoreAverage=Score/targetNum;
}

void UCombatantFunctions::SelectSkillAndTargetsByUtility(UCombatantComponent* Instigator,
	TArray<UPrimaryDataAsset*> PossibleSkills, TArray<UCombatantComponent*> PossibleTargets,
	EOmegaSkillUtilityOrder Order, UPrimaryDataAsset*& FinalSkill, TArray<UCombatantComponent*>& FinalTargets,
	float RandomOffsetRange, bool RegisterFinalAsTargetList)
{
	// Primarily for AI: pick skill + targets via IDataInterface_Skill::Skill_CheckUtility,
	// then finalize the target set with the skill's TargetSelector.
	FinalSkill = nullptr;
	FinalTargets.Reset();
	if (!Instigator)
	{
		return;
	}

	const auto ApplyRandom = [RandomOffsetRange](float Score) -> float
	{
		if (RandomOffsetRange > 0.f)
		{
			Score += FMath::FRandRange(-RandomOffsetRange, RandomOffsetRange);
		}
		return Score;
	};

	const auto GetValidTargetsForSkill = [Instigator, &PossibleTargets](UPrimaryDataAsset* Skill) -> TArray<UCombatantComponent*>
	{
		TArray<UCombatantComponent*> ValidTargets = PossibleTargets;
		const FOmegaSkillConfig Config = IDataInterface_Skill::Execute_Skill_GetConfig(Skill, Instigator);
		if (Config.TargetFilter)
		{
			ValidTargets = Config.TargetFilter->FilterCombatants(Instigator, ValidTargets);
		}
		ValidTargets.RemoveAll([](const UCombatantComponent* Target) { return !IsValid(Target); });
		return ValidTargets;
	};

	const auto IsUsableSkill = [Instigator](UPrimaryDataAsset* Skill) -> bool
	{
		return Skill
			&& Skill->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass())
			&& CanCombatantUseSkill(Instigator, Skill, true);
	};

	// Per-target utility for a skill (Skill_CheckUtility interface).
	const auto ScoreTargetForSkill = [Instigator, &ApplyRandom](UPrimaryDataAsset* Skill, UCombatantComponent* Target) -> float
	{
		const float Base = IDataInterface_Skill::Execute_Skill_CheckUtility(Skill, Instigator, Target);
		return ApplyRandom(Base);
	};

	// Aggregate skill utility over a target list (average of one-target utilities).
	const auto ScoreSkillOnTargets = [Instigator, &ApplyRandom](UPrimaryDataAsset* Skill, const TArray<UCombatantComponent*>& Targets) -> float
	{
		float Sum = 0.f;
		float Average = 0.f;
		GetSkillUtilityScore(Instigator, Skill, Targets, Sum, Average);
		return ApplyRandom(Average);
	};

	// Rank targets best-first by Skill_CheckUtility for a given skill.
	const auto RankTargetsForSkill = [&ScoreTargetForSkill](UPrimaryDataAsset* Skill, const TArray<UCombatantComponent*>& Targets) -> TArray<UCombatantComponent*>
	{
		struct FScoredTarget
		{
			UCombatantComponent* Target = nullptr;
			float Score = 0.f;
		};

		TArray<FScoredTarget> Scored;
		Scored.Reserve(Targets.Num());
		for (UCombatantComponent* Target : Targets)
		{
			Scored.Add({ Target, ScoreTargetForSkill(Skill, Target) });
		}
		Scored.Sort([](const FScoredTarget& A, const FScoredTarget& B) { return A.Score > B.Score; });

		TArray<UCombatantComponent*> Ranked;
		Ranked.Reserve(Scored.Num());
		for (const FScoredTarget& Entry : Scored)
		{
			Ranked.Add(Entry.Target);
		}
		return Ranked;
	};

	// Run the skill's TargetSelector over ranked valid targets (best-first so Single picks top utility).
	const auto FinalizeTargetsWithSelector = [Instigator](UPrimaryDataAsset* Skill, const TArray<UCombatantComponent*>& RankedTargets) -> TArray<UCombatantComponent*>
	{
		if (RankedTargets.IsEmpty())
		{
			return {};
		}

		const FOmegaSkillConfig Config = IDataInterface_Skill::Execute_Skill_GetConfig(Skill, Instigator);
		if (Config.TargetSelector)
		{
			UCombatantSelector* Selector = NewObject<UCombatantSelector>(Instigator, Config.TargetSelector);
			Selector->Instigator = Instigator;
			Selector->InputTargets = RankedTargets;
			Selector->OnSelectorBegin();

			if (Selector->ActiveTargets.IsEmpty())
			{
				Selector->SetSelectorTargetActive(RankedTargets[0], true);
			}

			Selector->Refresh();
			TArray<UCombatantComponent*> Selected = Selector->OnFinalizeTargets(Selector->ActiveTargets);
			Selected.RemoveAll([](const UCombatantComponent* Target) { return !IsValid(Target); });
			return Selected;
		}

		// No selector: single best-ranked target.
		return { RankedTargets[0] };
	};

	// ---------------------------------------------------------------
	// Collect usable skills that still have at least one valid target
	// ---------------------------------------------------------------
	struct FSkillCandidate
	{
		UPrimaryDataAsset* Skill = nullptr;
		TArray<UCombatantComponent*> ValidTargets;
	};

	TArray<FSkillCandidate> Candidates;
	Candidates.Reserve(PossibleSkills.Num());
	for (UPrimaryDataAsset* Skill : PossibleSkills)
	{
		if (!IsUsableSkill(Skill))
		{
			continue;
		}
		TArray<UCombatantComponent*> ValidTargets = GetValidTargetsForSkill(Skill);
		if (ValidTargets.IsEmpty())
		{
			continue;
		}
		Candidates.Add({ Skill, MoveTemp(ValidTargets) });
	}

	if (Candidates.IsEmpty())
	{
		return;
	}

	// ===============================================================
	// Order: Skill then Target  (elect skill first, then target order)
	// ===============================================================
	if (Order == SkillUtilOrd_TargSkill)
	{
		UPrimaryDataAsset* BestSkill = nullptr;
		TArray<UCombatantComponent*> BestValidTargets;
		float BestScore = TNumericLimits<float>::Lowest();
		bool bFound = false;

		for (const FSkillCandidate& Candidate : Candidates)
		{
			const float Score = ScoreSkillOnTargets(Candidate.Skill, Candidate.ValidTargets);
			if (!bFound || Score > BestScore)
			{
				bFound = true;
				BestScore = Score;
				BestSkill = Candidate.Skill;
				BestValidTargets = Candidate.ValidTargets;
			}
		}

		if (!BestSkill)
		{
			return;
		}

		FinalSkill = BestSkill;
		const TArray<UCombatantComponent*> Ranked = RankTargetsForSkill(FinalSkill, BestValidTargets);
		FinalTargets = FinalizeTargetsWithSelector(FinalSkill, Ranked);
	}
	// ===============================================================
	// Order: Target then Skill  (rank targets first, then elect skill)
	// ===============================================================
	else // SkillUtilOrd_SkillTarg
	{
		// Score each possible target by the best utility any usable skill can achieve on it.
		struct FGlobalTargetScore
		{
			UCombatantComponent* Target = nullptr;
			float BestScore = TNumericLimits<float>::Lowest();
			UPrimaryDataAsset* BestSkillForTarget = nullptr;
		};

		TMap<UCombatantComponent*, FGlobalTargetScore> TargetScores;
		for (const FSkillCandidate& Candidate : Candidates)
		{
			for (UCombatantComponent* Target : Candidate.ValidTargets)
			{
				const float Score = ScoreTargetForSkill(Candidate.Skill, Target);
				FGlobalTargetScore& Entry = TargetScores.FindOrAdd(Target);
				if (!Entry.Target)
				{
					Entry.Target = Target;
					Entry.BestScore = Score;
					Entry.BestSkillForTarget = Candidate.Skill;
				}
				else if (Score > Entry.BestScore)
				{
					Entry.BestScore = Score;
					Entry.BestSkillForTarget = Candidate.Skill;
				}
			}
		}

		// Global target ranking (best utility-first) — drives later selector input order.
		TArray<FGlobalTargetScore> RankedGlobal;
		TargetScores.GenerateValueArray(RankedGlobal);
		RankedGlobal.Sort([](const FGlobalTargetScore& A, const FGlobalTargetScore& B)
		{
			return A.BestScore > B.BestScore;
		});

		if (RankedGlobal.IsEmpty())
		{
			return;
		}

		// Elect skill: prefer the skill that is strongest on the highest-ranked targets.
		// Score each skill by utility on its valid targets, weighted so earlier global ranks matter more.
		UPrimaryDataAsset* BestSkill = nullptr;
		TArray<UCombatantComponent*> BestValidTargets;
		float BestSkillScore = TNumericLimits<float>::Lowest();
		bool bFoundSkill = false;

		// Build a rank lookup for weight.
		TMap<UCombatantComponent*, int32> GlobalRank;
		for (int32 i = 0; i < RankedGlobal.Num(); ++i)
		{
			GlobalRank.Add(RankedGlobal[i].Target, i);
		}

		for (const FSkillCandidate& Candidate : Candidates)
		{
			float WeightedSum = 0.f;
			float WeightTotal = 0.f;
			for (UCombatantComponent* Target : Candidate.ValidTargets)
			{
				const int32* RankPtr = GlobalRank.Find(Target);
				const int32 Rank = RankPtr ? *RankPtr : RankedGlobal.Num();
				// Higher weight for better-ranked (lower index) global targets.
				const float Weight = 1.f / static_cast<float>(Rank + 1);
				const float Util = IDataInterface_Skill::Execute_Skill_CheckUtility(Candidate.Skill, Instigator, Target);
				WeightedSum += Util * Weight;
				WeightTotal += Weight;
			}

			float Score = (WeightTotal > 0.f) ? (WeightedSum / WeightTotal) : 0.f;
			Score = ApplyRandom(Score);

			if (!bFoundSkill || Score > BestSkillScore)
			{
				bFoundSkill = true;
				BestSkillScore = Score;
				BestSkill = Candidate.Skill;
				BestValidTargets = Candidate.ValidTargets;
			}
		}

		if (!BestSkill)
		{
			return;
		}
		FinalSkill = BestSkill;

		// Order this skill's valid targets using the global target ranking (target-first intent).
		TArray<UCombatantComponent*> RankedForSkill;
		RankedForSkill.Reserve(BestValidTargets.Num());
		for (const FGlobalTargetScore& Entry : RankedGlobal)
		{
			if (BestValidTargets.Contains(Entry.Target))
			{
				RankedForSkill.Add(Entry.Target);
			}
		}
		// Any valid targets missing from global map (shouldn't happen) go last, still utility-ranked.
		for (UCombatantComponent* Target : BestValidTargets)
		{
			RankedForSkill.AddUnique(Target);
		}

		FinalTargets = FinalizeTargetsWithSelector(FinalSkill, RankedForSkill);
	}

	if (RegisterFinalAsTargetList && FinalTargets.Num() > 0)
	{
		Instigator->SetTargetsRegistered(FinalTargets, true, true);
	}
}


TArray<UCombatantComponent*> UCombatantFunctions::FilterValidSkillTargets(TScriptInterface<IDataInterface_Skill> Skill,
                                                                          UCombatantComponent* Instigator, TArray<UCombatantComponent*> Targets)
{
	if (Skill.GetObject() && Targets.IsValidIndex(0))
	{
		FOmegaSkillConfig SkillConfig=IDataInterface_Skill::Execute_Skill_GetConfig(Skill.GetObject(),Targets[0]);
		if (SkillConfig.TargetFilter)
		{
			return SkillConfig.TargetFilter->FilterCombatants(Instigator,Targets);
		}
	}
	return TArray<UCombatantComponent*>();
}

bool UCombatantFunctions::IsValidSkillTarget(TScriptInterface<IDataInterface_Skill> Skill,UCombatantComponent* Instigator, UCombatantComponent* Target)
{
	if (Skill.GetObject() && Target)
	{
		FOmegaSkillConfig SkillConfig=IDataInterface_Skill::Execute_Skill_GetConfig(Skill.GetObject(),Target);
		if (SkillConfig.TargetFilter)
		{
			TArray Targets = { Target };
			return SkillConfig.TargetFilter->FilterCombatants(Instigator,Targets).Contains(Target);
		}
	}
	return false;
}

bool UCombatantFunctions::ConsumeSkillAttributes(UCombatantComponent* Combatant, UObject* SkillObject)
{
	if(!Combatant || !SkillObject) { return false; }
	
	if(CanCombatantUseSkill(Combatant,SkillObject, true))
	{
		if(SkillObject->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
		{
			TArray<UOmegaAttribute*> att_list;
			FOmegaSkillConfig SkillConfig=IDataInterface_Skill::Execute_Skill_GetConfig(SkillObject,Combatant);
			TMap<UOmegaAttribute*, float> att_vals = SkillConfig.AttributeUseCost;
			att_vals.GetKeys(att_list);
			
			for(auto* TempAtt : att_list)
			{
				if(TempAtt)
				{
					Combatant->ApplyAttributeDamage(TempAtt,att_vals[TempAtt],nullptr,nullptr,FOmegaAttributeDamageMeta());
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
		if(UncomparedModifer && UncomparedModifer->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
		{
			for(const FOmegaAttributeModifier TempMod : IDataInterface_Combatant::Execute_GetModifierValues(UncomparedModifer))
			{
				TempMods.Remove(TempMod);
			}
		}

		//Add compared values
		if(ComparedModifier && ComparedModifier->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()))
		{
			TempMods.Append(IDataInterface_Combatant::Execute_GetModifierValues(ComparedModifier));
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
		for (auto* c : WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetAllCombatants())
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
		for (auto* c : WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetAllCombatants())
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

float UCombatantFunctions::CheckAttributeValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
	float Value, EOmegaAttributeValueType ValueType, TEnumAsByte<EOmegaComparisonMethod> Method, bool& Outcome)
{
	float CurVal = 0.f;
	float MaxVal = 0.f;
	if(Combatant && Attribute)
	{
		Combatant->GetAttributeValue(Attribute, CurVal, MaxVal);
	}
	float SelectedVal;
	switch(ValueType)
	{
	case EOmegaAttributeValueType::AttValue_Max:     SelectedVal = MaxVal; break;
	case EOmegaAttributeValueType::AttValue_Percent: SelectedVal = (MaxVal > 0.f) ? (CurVal / MaxVal) : 0.f; break;
	default:                                         SelectedVal = CurVal; break;
	}
	bool bResult;
	switch(Method)
	{
	case Compare_Equal:     bResult = SelectedVal == Value; break;
	case Compare_Great:     bResult = SelectedVal >  Value; break;
	case Compare_Less:      bResult = SelectedVal <  Value; break;
	case Compare_GreatEqual: bResult = SelectedVal >= Value; break;
	case Compare_LessEqual:  bResult = SelectedVal <= Value; break;
	default:                bResult = false; break;
	}
	Outcome = bResult;
	return SelectedVal;
}

void UCombatantFunctions::CopyCurrentAttributes(UCombatantComponent* From, UCombatantComponent* To)
{
	if (From && To)
	{
		To->SetCurrentAttributeValues(From->GetCurrentAttributeValues(true));
	}
}

void UCombatantFunctions::CopyCurrentXP(UCombatantComponent* From, UCombatantComponent* To)
{
	if (From && To)
	{
		To->XP_SetAll(From->XP_GetAll(), false);
	}
}

void UCombatantFunctions::CopyCurrentInventory(UCombatantComponent* From, UCombatantComponent* To)
{
	if (From && To)
	{
		To->Inventory_Set(From->Inventory_Get(), true);
	}
}

void UCombatantFunctions::CopyCurrentEquipment(UCombatantComponent* From, UCombatantComponent* To)
{
	if (From && To)
	{
		To->Equipment_SetAll(From->Equipment_Get());
	}
}



