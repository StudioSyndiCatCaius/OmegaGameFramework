// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OmegaGameplaySystem.h"

#include "OmegaGameMode.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditDefaultsOnly, Category="Classes")
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoGameplaySystems;

	protected:
	virtual void BeginPlay() override;
};
