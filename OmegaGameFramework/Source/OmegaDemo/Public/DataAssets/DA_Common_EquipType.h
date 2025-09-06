// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "DataAssets/DA_Appearance.h"
#include "Condition/Condition_Actor.h"
#include "DataAssets/DA_CombatSource.h"
#include "DA_Common_EquipType.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_Common_EquipType : public UOAsset_CombatSource, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()
public:
	float L_ScaleAttributeByRank(const UOmegaAttribute* Attribute, int32 rank);
	TArray<FOmegaAttributeModifier> L_ScaleAttributeByRank_All(int32 rank);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	UOAsset_Common_EquipType* ParentType;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TArray<UOAsset_Common_EquipType*> InheritedTypes;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Equipment")
	TArray<UOmegaCondition_Actor*> EquipConditions;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TMap<UOmegaAttribute*,FRuntimeFloatCurve> RankAttributeScales;
	//True=Value derived from 'RankAttributeScales' will me multiplied by the Attributes MaxValue;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	bool bRankAttributeScale_ToMax;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Appearance")
	bool DefaultToParentAppearance=true;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance;
	
	bool AreConditionsValid(AActor* Actor) const;
	TArray<UOmegaCondition_Actor*> GetAllConditions() const;

	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
};

inline float UOAsset_Common_EquipType::L_ScaleAttributeByRank(const UOmegaAttribute* Attribute, int32 rank)
{
	if(Attribute && RankAttributeScales.Contains(Attribute))
	{
		float out=RankAttributeScales[Attribute].GetRichCurve()->Eval(rank);
		if(bRankAttributeScale_ToMax)
		{
			return Attribute->MaxValue*out;
		}
		return out; 
	}	
	return 0.0;
}

inline TArray<FOmegaAttributeModifier> UOAsset_Common_EquipType::L_ScaleAttributeByRank_All(int32 rank)
{
	TMap<UOmegaAttribute*,float> att_out;
	for(auto& p : RankAttributeScales)
	{
		att_out.FindOrAdd(p.Key,L_ScaleAttributeByRank(p.Key,rank));
	}
	return FOmegaAttributeModifier::FromFlat(att_out);
}

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

inline UOAsset_Appearance* UOAsset_Common_EquipType::GetAppearanceAsset_Implementation()
{
	if(ParentType && DefaultToParentAppearance && !Appearance)
	{
		return Execute_GetAppearanceAsset(ParentType);
	}
	if(Appearance)
	{
		return Appearance;
	}
	return nullptr;
}
