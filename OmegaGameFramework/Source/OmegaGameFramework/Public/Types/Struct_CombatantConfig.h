
#pragma once

#include "CoreMinimal.h"

#include "Struct_CombatantConfig.generated.h"

class UOmegaFaction;
class UOmegaAttributeSet;
class AOmegaAbility;
class UCombatantComponent;


USTRUCT(BlueprintType,Blueprintable)
struct FOmegaCombatantConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant") TSoftObjectPtr<UOmegaAttributeSet> AttributeSet;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant") TSoftObjectPtr<UOmegaFaction> Faction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant") TArray<TSoftClassPtr<AOmegaAbility>> Abilities;

	void Apply(UCombatantComponent* combatant);
};