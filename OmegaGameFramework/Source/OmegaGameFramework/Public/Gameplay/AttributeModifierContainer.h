// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "DataInterface_AttributeModifier.h"
#include "GameplayTagContainer.h"
#include "AttributeModifierContainer.generated.h"

class UOmegaAttribute;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAttributeModifierContainer : public UObject, public IDataInterface_AttributeModifier, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;

	UPROPERTY() UOmegaAttribute* Attribute;
	UPROPERTY() float IncValue;
	UPROPERTY() float MultiValue;
	UPROPERTY() FGameplayTag Category;
	UPROPERTY() FGameplayTagContainer Tags;
	

	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};
