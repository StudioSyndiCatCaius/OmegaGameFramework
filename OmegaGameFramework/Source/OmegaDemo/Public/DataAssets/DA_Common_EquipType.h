// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Misc/GeneralDataObject.h"
#include "Condition/Condition_Actor.h"
#include "DA_Common_EquipType.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_Common_EquipType : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	UOAsset_Common_EquipType* ParentType;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TArray<UOAsset_Common_EquipType*> InheritedTypes;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Equipment")
	TArray<UOmegaCondition_Actor*> EquipConditions;

	bool AreConditionsValid(AActor* Actor) const;
	TArray<UOmegaCondition_Actor*> GetAllConditions() const;
};

inline bool UOAsset_Common_EquipType::AreConditionsValid(AActor* Actor) const
{
	if(Actor)
	{
		for(auto* c : GetAllConditions())
		{
			if(c && !c->CheckActorCondition(Actor))
			{
				return false;
			}
		}
	}
	return true;
}

inline TArray<UOmegaCondition_Actor*> UOAsset_Common_EquipType::GetAllConditions() const
{
	TArray<UOmegaCondition_Actor*> conds=EquipConditions;
	TArray<UOAsset_Common_EquipType*> inheritors=InheritedTypes;
	inheritors.Add(ParentType);
	for(auto* i : inheritors)
	{
		if(i && i!=this)
		{
			conds.Append(i->GetAllConditions());
		}
	}
	return conds;
}
