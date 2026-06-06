// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Components/ArrowComponent.h"
#include "Component_Reference.generated.h"


// An arrow component that marks a named reference point on an actor, identifiable by gameplay tag and optional numeric ID.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaReferenceComponent : public UArrowComponent
{
	GENERATED_BODY()

public:

	// Tag used to identify or categorize this reference point when looked up at runtime.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Reference") FGameplayTag Tag;
	// Optional numeric index to distinguish multiple reference components that share the same tag.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Reference") int32 id=-1;


};
