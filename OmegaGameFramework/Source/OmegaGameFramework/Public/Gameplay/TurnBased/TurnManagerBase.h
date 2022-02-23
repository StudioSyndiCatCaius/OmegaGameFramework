// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/CombatantComponent.h"
#include "UObject/NoExportTypes.h"

#include "TurnManagerBase.generated.h"

/**
* 
*/
UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UTurnManagerBase : public UObject
{
	GENERATED_BODY()
	
	public:
	UFUNCTION(BlueprintImplementableEvent)
	bool ShouldTargetActFirst(UCombatantComponent* TargetCombatant, UCombatantComponent* ComparedCombatant);
};
