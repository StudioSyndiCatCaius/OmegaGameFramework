#include "script_CombatantSelector.h"

#include "Engine/Texture2D.h"
#include "UObject/ConstructorHelpers.h"

#define MAK_ICO(nam) \
{ \
static ConstructorHelpers::FObjectFinder<UTexture2D> IcoFinder( \
TEXT("/OmegaGameFramework/Textures/icons/" #nam "." #nam)); \
if (IcoFinder.Succeeded()) \
{ \
SelectorIcon.SetResourceObject(IcoFinder.Object); \
} \
}

UCombatantSelector_Single::UCombatantSelector_Single()
{
	SelectorName=FText::FromString("Single");
	MAK_ICO(T_ico_selector_one);
}

void UCombatantSelector_Single::CycleTarget(int32 amount)
{
	if (InputTargets.Num() == 0) return;
	currentTargetIndex = ((currentTargetIndex + amount) % InputTargets.Num() + InputTargets.Num()) % InputTargets.Num();
	Refresh();
	SetSelectorTargetActive(InputTargets[currentTargetIndex], true);
}

void UCombatantSelector_Single::OnSelectorBegin_Implementation()
{
	CycleTarget(0);
}

void UCombatantSelector_Single::OnSelectorEvent_Implementation(FGameplayTag Event)
{
	if (Event==Event_CycleL)
	{
		CycleTarget(-1);
	}
	else if (Event==Event_CycleR)
	{
		CycleTarget(1);
	}
}

bool UCombatantSelector_Single::IsTargetValid_Implementation(UCombatantComponent* Target) const
{
	if (InputTargets.Contains(Target))
	{
		return InputTargets.Find(Target)==currentTargetIndex;
	}
	return false;
}

UCombatantSelector_All::UCombatantSelector_All()
{
	SelectorName=FText::FromString("All");
	MAK_ICO(T_ico_selector_all);
}

void UCombatantSelector_All::OnSelectorBegin_Implementation()
{
	ActiveTargets=InputTargets;
}

TArray<UCombatantComponent*> UCombatantSelector_All::OnFinalizeTargets_Implementation(
	const TArray<UCombatantComponent*>& Targets) const
{
	return InputTargets;
}

UCombatantSelector_Random::UCombatantSelector_Random()
{
	SelectorName=FText::FromString("Random");
	MAK_ICO(T_ico_selector_random);
}

void UCombatantSelector_Random::OnSelectorBegin_Implementation()
{
	ActiveTargets=InputTargets;
}
