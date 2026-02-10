
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Struct_Combatant.generated.h"

class UCombatantComponent;
class UOmegaAttribute;
class UOmegaDamageType;
class AOmegaGameplayEffect;

USTRUCT(BlueprintType)
struct FOmegaEffectContainer
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	TSubclassOf<AOmegaGameplayEffect> EffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	float Power = 1.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	FGameplayTagContainer AddedTags;
};