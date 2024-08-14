// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OmegaUtils_Actor.generated.h"


UCLASS(Blueprintable,EditInlineNew,Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaActorSelector : public UObject
{
	GENERATED_BODY()

	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	
	UOmegaActorSelector(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
public:
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor Selector")
	AActor* GetActor();

	UFUNCTION()
	AActor* Private_GetActor(UWorld* WorldContext);
};