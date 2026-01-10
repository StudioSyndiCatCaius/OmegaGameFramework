// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once


#include "Condition/Condition_Actor.h"
#include "Functions/F_Component.h"
#include "modifiers_actor.generated.h"


UCLASS(DisplayName="(Actor Mod) * CONDITIONAL")
class OMEGADEMO_API UActorMod_Conditional : public UActorModifierScript
{
	GENERATED_BODY()
public:

	virtual bool OnAppliedToActor_Implementation(AActor* Actor) const override;

	UPROPERTY(EditAnywhere,Instanced,Category="ActorMod") TArray<UOmegaCondition_Actor*> Conditions;
	UPROPERTY(EditAnywhere,Instanced,Category="ActorMod") TArray<UActorModifierScript*> Modifiers;

};

inline bool UActorMod_Conditional::OnAppliedToActor_Implementation(AActor* Actor) const
{
	FOmegaConditions_Actor con;
	con.Conditions=Conditions;
	if(con.CheckConditions(Actor))
	{
		FActorModifiers mod;
		mod.Script=Modifiers;
		mod.ApplyMods(Actor);
	}
	return false;
}
