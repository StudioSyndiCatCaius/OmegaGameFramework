// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Components/ArrowComponent.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Component_Reference.generated.h"


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaReferenceComponent : public UArrowComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Reference") FGameplayTag Tag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Reference") int32 id=-1;


};

