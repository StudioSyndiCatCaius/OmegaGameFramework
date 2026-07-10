#pragma once

#include "Functions/F_CombatantSelector.h"
#include "script_CombatantSelector.generated.h"

UCLASS(DisplayName="♎ Target Selector - Single")
class OMEGADEMO_API UCombatantSelector_Single : public UCombatantSelector
{
	GENERATED_BODY()

public:
	
	UPROPERTY() int32 currentTargetIndex=0;
	
	UFUNCTION() void CycleTarget(int32 amount);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Selector") FGameplayTag Event_CycleR=FGameplayTag::RequestGameplayTag("INPUT.UI.Nav.Right");
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Selector") FGameplayTag Event_CycleL=FGameplayTag::RequestGameplayTag("INPUT.UI.Nav.Left");
	
	virtual void OnSelectorBegin_Implementation() override;
	virtual void OnSelectorEvent_Implementation(FGameplayTag Event) override;
	virtual bool IsTargetValid_Implementation(UCombatantComponent* Target) const override;
	
};

UCLASS(DisplayName="♎ Target Selector - All")
class OMEGADEMO_API UCombatantSelector_All : public UCombatantSelector
{
	GENERATED_BODY()

public:
	virtual void OnSelectorBegin_Implementation() override;
	virtual TArray<UCombatantComponent*> OnFinalizeTargets_Implementation(const TArray<UCombatantComponent*>& Targets) const override;
	
};

UCLASS(DisplayName="♎ Target Selector - Random")
class OMEGADEMO_API UCombatantSelector_Random : public UCombatantSelector
{
	GENERATED_BODY()

public:
	virtual void OnSelectorBegin_Implementation() override;
};