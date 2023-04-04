// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "OmegaModSubsystem.generated.h"


UCLASS(DisplayName="Omega Subsystm: Mods")
class OMEGAMOD_API UOmegaModSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

public:
	TArray<UOmegaMod*> ModList;

	UFUNCTION(BlueprintPure, Category="OmegaMods")
	TArray<FString> GetModListPaths();
	
	UFUNCTION(BlueprintPure, Category="OmegaMods")
	FString GetModsDirectory();
		
	UFUNCTION(BlueprintPure, Category="Omega|Mods")
	TArray<UOmegaMod*> GetInstalledMods();

	UFUNCTION(BlueprintPure, Category="Omega|Mods")
	TArray<UOmegaMod*> GetActiveMods();

	UFUNCTION(BlueprintCallable, Category="Omega|Mods")
	void SetModActive(UOmegaMod* Mod, bool IsActive);
	
};

UCLASS(Blueprintable,BlueprintType)
class OMEGAMOD_API UOmegaMod : public UObject, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	FText ModName;
	
	UPROPERTY()
	FText ModDescription;

	UPROPERTY()
	FSlateBrush ModThumbnail;

	UPROPERTY()
	FGameplayTag ModCategory;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
};
