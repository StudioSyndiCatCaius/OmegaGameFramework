// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_TurnBasedManager.h"

#include "Functions/F_ScriptedEffects.h"
#include "Misc/GeneralDataObject.h"
#include "DA_EffectsPreset.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_EffectsPreset : public UOmegaDemoDataAsset, public IDataInterface_ScriptedEffects, public IDataInterface_TurnEntity
{
	GENERATED_BODY()
public:


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

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Realtime")
	float Lifespan=5.0;
	
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
