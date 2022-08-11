// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "OmegaDataSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Data"))
class OMEGADATA_API UOmegaDataSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	UOmegaDataSettings();

public:

	UPROPERTY(EditAnywhere, config, Category = "DataItems")
	TArray<FDirectoryPath> DataItemScansPath;
	
};
