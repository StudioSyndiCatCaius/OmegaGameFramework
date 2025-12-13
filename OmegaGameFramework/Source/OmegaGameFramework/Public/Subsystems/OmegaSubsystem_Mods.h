// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaGameplayModule.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "OmegaSubsystem_Mods.generated.h"


UCLASS(DisplayName="Omega Subsystem: Mods")
class OMEGAGAMEFRAMEWORK_API UOmegaModSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

	UFUNCTION()
	TSubclassOf<UOmegaMod> GetModClass();

public:

	UFUNCTION(BlueprintCallable,Category="Mods|Advanced")
	void InitializeMods();
	
	UPROPERTY()
	UOmegaModManager* ModManager;
	UPROPERTY()
	TArray<UOmegaMod*> ModList;

	UFUNCTION(BlueprintPure, Category="OmegaMods")
	TArray<FString> GetModListPaths(bool IncludeBaseOverride=false);
	
	UFUNCTION(BlueprintPure, Category="OmegaMods")
    TArray<FString> GetModAssetFile(const FString& filename, bool IncludeBaseOverride=true);
	
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
	UOmegaMod(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UPROPERTY() UWorld* WorldPrivate = nullptr;
	UPROPERTY() UGameInstance* GameInstanceRef = nullptr;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	
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

	UFUNCTION(BlueprintImplementableEvent,Category="Mods")
	void OnModInitialized(const FString& path);

	UFUNCTION(BlueprintImplementableEvent,Category="Mods")
	bool Get_IsModActive();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Mods")
	void Set_IsModActive(bool Loaded);
	
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