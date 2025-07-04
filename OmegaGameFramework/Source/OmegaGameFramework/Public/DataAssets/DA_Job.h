
// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Job.generated.h"



UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Job : public UOmegaDataAsset, public IDataInterface_SkillSource
{
	GENERATED_BODY()
public:

	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Job")
	TArray<UPrimaryDataAsset*> Skills_Default;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Job")
	TMap<UPrimaryDataAsset*,int32> Skills_ByLevel;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Job")
	TMap<FGameplayTag,UPrimaryDataAsset*> Skills_ByTag;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="FLAGS")
	bool AutoGiveSkills_default;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="FLAGS")
	bool AutoGiveSkills_ByLevel;
};

inline TArray<UPrimaryDataAsset*> UOAsset_Job::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> out;
	if(AutoGiveSkills_default) { out.Append(Skills_Default);}
	if(AutoGiveSkills_ByLevel)
	{
		TArray<UPrimaryDataAsset*> tempskl;
		Skills_ByLevel.GetKeys(tempskl);
		for(auto* s : tempskl)
		{
			if(Combatant && s && Skills_ByLevel[s]>=Combatant->Level)
			{
				out.Add(s);
			}
		}
	}
	return out;
}
