// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Ability.h"
#include "DemoAbility_SkillAction.generated.h"

class UOmegaAssetLibrary_Animation;
class UDataInterface_Skill;

UCLASS(Abstract)
class OMEGADEMO_API ADemoAbility_SkillAction : public AOmegaAbility
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ADemoAbility_SkillAction();
	UPROPERTY() TScriptInterface<UDataInterface_Skill> ref_skill;
	UPROPERTY() UOmegaAssetLibrary_Animation* ref_AnimLib=nullptr;
	
	virtual bool CanActivate_Implementation(UObject* Context) override;
	virtual void AbilityActivated_Implementation(class UObject* Context) override;
};
