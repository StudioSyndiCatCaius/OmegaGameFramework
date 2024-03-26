// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaGameplayModule.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "OmegaSubsystem_Mods.generated.h"


UCLASS(DisplayName="Omega Subsystm: Mods")
class OMEGAGAMEFRAMEWORK_API UOmegaModSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

public:
	
	UPROPERTY()
	UOmegaModManager* ModManager;
	UPROPERTY()
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
class OMEGAGAMEFRAMEWORK_API UOmegaMod : public UObject, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, Category="Mod")
	FText ModName;
	
	UPROPERTY(BlueprintReadWrite, Category="Mod")
	FText ModDescription;

	UPROPERTY(BlueprintReadWrite, Category="Mod")
	FSlateBrush ModThumbnail;

	UPROPERTY(BlueprintReadWrite, Category="Mod")
	FGameplayTag ModCategory;

	UPROPERTY(BlueprintReadOnly, Category="Mod", DisplayName="Mod Path")
	FString ModStringData;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaModManager : public UOmegaGameplayModule
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	FString GetModFiletype();

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	void OnSetModActive(UOmegaMod* Mod, bool IsActive);

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	bool OnGetModActive(UOmegaMod* Mod);

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	void OnModInitialized(UOmegaMod* Mod);
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaModFileFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	FString GetModFiletype();

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	void OnSetModActive(UOmegaMod* Mod, bool IsActive);

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	bool OnGetModActive(UOmegaMod* Mod);

	UFUNCTION(BlueprintImplementableEvent, Category="Mods")
	void OnModInitialized(UOmegaMod* Mod);
	
};