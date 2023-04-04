// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaModWorldSubsystem.generated.h"



UCLASS(DisplayName="Omega Subsystm: Mod World")
class OMEGAMOD_API UOmegaModWorldSubsystem : public UWorldSubsystem

{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

public:
	
	
};
