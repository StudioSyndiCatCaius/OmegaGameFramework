// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once
#include "Functions/OmegaFunctions_CombatantFilter.h"

#include "script_CombatantFilter.generated.h"


class UFlowAsset;
// ====================================================================================================
// 
// ====================================================================================================
UCLASS(DisplayName="🎯(Combatant Filter) Faction Affinity")
class OMEGADEMO_API UCombatantFilter_FactionAffinity : public UCombatantFilterScript
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CombatantFilter") TArray<TEnumAsByte<EFactionAffinity>> AcceptedAffinities;
	
	virtual const TArray<UCombatantComponent*> FilterCombatants_Implementation(UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const override;
};

UCLASS(DisplayName="🎯(Combatant Filter) Effect Tags")
class OMEGADEMO_API UCombatantFilter_EffectTags : public UCombatantFilterScript
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CombatantFilter",meta=(Categories="EFFECT")) FGameplayTagContainer Effects_Required;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CombatantFilter",meta=(Categories="EFFECT")) FGameplayTagContainer Effects_Blocked;
	
	virtual const TArray<UCombatantComponent*> FilterCombatants_Implementation(UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const override;
};

UCLASS(DisplayName="🎯(Combatant Filter) Self")
class OMEGADEMO_API UCombatantFilter_Self : public UCombatantFilterScript
{
	GENERATED_BODY()
public:
	//True = include all BUT the instigator | False = ONLY include the instigator
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CombatantFilter",meta=(Categories="EFFECT")) bool bExcludeInstead;
	
	virtual const TArray<UCombatantComponent*> FilterCombatants_Implementation(UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const override;
};