// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/DA_Appearance.h"
#include "Functions/F_Equipment.h"
#include "Interfaces/I_Combatant.h"
#include "DA_CommonRace.generated.h"



UCLASS(Blueprintable, BlueprintType,DisplayName="Ω-👽 Race")
class OMEGADEMO_API UOAsset_CommonRace : public UOmegaDemoDataAsset, public IDataInterface_Combatant
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Race", meta=(ExposeOnSpawn),DisplayName="Appearance (Default)")
	UOAsset_Appearance* Appearance_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Race", meta=(ExposeOnSpawn),DisplayName="Appearance (Gender)")
	TMap<EOmegaGender,UOAsset_Appearance*> Appearance_Gender;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Race", meta=(ExposeOnSpawn),DisplayName="Appearance (Tagged)")
	TMap<FGameplayTag,UOAsset_Appearance*> Appearance_Tagged;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant", meta=(ShowOnlyInnerProperties))
	FOmegaScripted_CombatantModifiers Modifiers;
	virtual FOmegaScripted_CombatantModifiers Combatant_GetScriptedModifiers_Implementation() override { return Modifiers; };
};
