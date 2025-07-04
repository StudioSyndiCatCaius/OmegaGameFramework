// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_ComponentMod.h"

#include "Misc/GeneralDataObject.h"
#include "DA_ActorModifierCollection.generated.h"



UCLASS(Blueprintable, BlueprintType,EditInlineNew,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOAsset_ActorModifierCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor")
	TArray<UOAsset_ActorModifierCollection*> ImportedCollections;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor")
	TArray<UActorModifierScript*> Modifiers;

	UFUNCTION(BlueprintCallable,Category="ActorModifier")
	FActorModifiers GetAllModifiers();
	UFUNCTION(BlueprintCallable,Category="ActorModifier")
	bool ApplyAllModifiers(AActor* Actor);
};

inline FActorModifiers UOAsset_ActorModifierCollection::GetAllModifiers()
{
	FActorModifiers mods;
	mods.Script=Modifiers;
	for(auto* a : ImportedCollections)
	{
		if(a)
		{
			mods.Script.Append(a->Modifiers);
		}
	}
	return mods;
}

inline bool UOAsset_ActorModifierCollection::ApplyAllModifiers(AActor* Actor)
{
	if(Actor)
	{
		UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(GetAllModifiers(),Actor);
		return true;
	}
	return false;
}
