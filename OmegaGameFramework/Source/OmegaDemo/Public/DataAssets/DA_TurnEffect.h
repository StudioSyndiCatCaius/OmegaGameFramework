// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_TurnBasedManager.h"
#include "DataAssets/DA_CombatSource.h"
#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "DA_TurnEffect.generated.h"




UCLASS(Blueprintable, BlueprintType,DisplayName="Ω Turn Effect - Common")
class OMEGADEMO_API UOAsset_TurnEffect_Common : public UOAsset_CombatSource, public IOmegaScriptedEffectsInterface, public IDataInterface_TurnEntity
{
	GENERATED_BODY()
public:
	virtual FOmegaCustomScriptedEffects GetScriptedEffects_Implementation(FName Name) override
	{
		if(Name.IsValid())
		{
			if(Effects_Named.Contains(Name)) { return Effects_Named[Name];}
			return FOmegaCustomScriptedEffects();
		}
		FOmegaCustomScriptedEffects c;
		c.CustomEffects=Effects_Default;
		return c;
	}

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Effects")
	TArray<UOmegaScriptedEffect*> Effects_Default;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Effects")
	TArray<UOmegaScriptedEffect*> Effects_TurnStart;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Effects")
	TArray<UOmegaScriptedEffect*> Effects_TurnEnd;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	TMap<FName,FOmegaCustomScriptedEffects> Effects_Named;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="TurnBased")
	int32 Turns_Initial;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="TurnBased")
	int32 Turns_Max;

	virtual int32 GetTurns_Init_Implementation() override { return Turns_Initial; }
	virtual int32 GetTurns_Max_Implementation() override {return Turns_Max;}
	virtual void OnTurnStart_Implementation(UTurnTrackerComponent* EntityComponent, UTurnBasedManagerComponent* TurnComponent, UCombatantComponent* Member) override
	{
		UOmegaScriptedEffectFunctions::ApplyScriptedEffects_List(Effects_TurnStart,Member,nullptr);
	};
	virtual void OnTurnEnd_Implementation(UTurnTrackerComponent* EntityComponent, UTurnBasedManagerComponent* TurnComponent, UCombatantComponent* Member) override
	{
		UOmegaScriptedEffectFunctions::ApplyScriptedEffects_List(Effects_TurnEnd,Member,nullptr);
	};
	
};



UCLASS(Blueprintable, BlueprintType,DisplayName="Ω Turn Effect - Attribute Buff")
class OMEGADEMO_API UOAsset_TurnEffect_AttributeBuff : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effect")
	UOmegaAttribute* Attribute;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effect")
	float Increment;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effect")
	float Multiplier;
};
