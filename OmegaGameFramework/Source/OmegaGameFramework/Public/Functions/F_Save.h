// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Subsystems/Subsystem_Save.h"

#include "F_Save.generated.h"


class UOmegaSaveGlobal;
class UOmegaSaveGame;
class USaveGame;


UENUM(BlueprintType)
enum EOmegaSaveDirectory : uint8
{
	OmegaSaveDir_UserData UMETA(DisplayName="User Data"), //saves to user AppData game folder (the normal save location)
	OmegaSaveDir_GameData UMETA(DisplayName="Game Folder"), //saves to the Project/packaged game local "Saved" folder
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Save",DisplayName="💾Save - Get Directory Path") 
	static FString GetSaveDirectoryPath(TEnumAsByte<EOmegaSaveDirectory> Directory);

	UFUNCTION(BlueprintPure,Category="Omega|Save",DisplayName="💾Save - Make File Path (Name)") 
	static FString MakeSaveFilePath_Name(TEnumAsByte<EOmegaSaveDirectory> Directory, const FString& Name);
	UFUNCTION(BlueprintPure,Category="Omega|Save",DisplayName="💾Save - Make File Path (Slot)")
	static FString MakeSaveFilePath_Slot(TEnumAsByte<EOmegaSaveDirectory> Directory, int32 Slot);
	
	
	UFUNCTION(BlueprintPure,Category="Omega|Save", meta = (WorldContext = "WorldContextObject",DeterminesOutputType="Class"),DisplayName="💾Save - Get GAME") 
	static UOmegaSaveGame* GetSave_Game(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGame> Class=nullptr);

	UFUNCTION(BlueprintPure,Category="Omega|Save", meta = (WorldContext = "WorldContextObject",DeterminesOutputType="Class"),DisplayName="💾Save - Get GLOBAL")
	static UOmegaSaveGlobal* GetSave_Global(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGlobal> Class=nullptr);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set TagParam <Int>")
	static void SetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 Value, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set TagParam <Bool>")
	static void SetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool Value, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get TagParam <Int>")
	static int32 GetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set TagParam <Bool>")
	static bool GetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Check TagParam <Bool>")
	static bool CheckSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Check TagParam <Int>")
	static int32 CheckSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 CheckValue, bool bGlobal, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome);

	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",meta = (WorldContext = "WorldContextObject"),DisplayName="💾Save - Create New Game")
	static UOmegaSaveGame* CreateGame(const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",meta = (WorldContext = "WorldContextObject"),DisplayName="💾Save - Start Game")
	static bool StartGame(const UObject* WorldContextObject,UOmegaSaveGame* Game, bool bLoadSaveLevel);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="💾Save - Save Game (Custom)")
	static bool Custom_SaveGame(USaveGame* SaveGameObject, const FString& path, const FString& file);

	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="💾Save - Load Game (Custom)")
	static USaveGame* Custom_LoadGame(const FString& path, const FString& file);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="💾Save - Load All Games in path")
	static TArray<USaveGame*> Custom_LoadGame_AllInPath(const FString& path);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Get",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
	static TArray<UPrimaryDataAsset*> DataList_Get(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List, bool bGlobal);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Has?",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
	static bool DataList_Has(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List,UPrimaryDataAsset* Asset, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Resize",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
    static void DataList_Resize(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List,int32 size, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Shuffle",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
	static void DataList_Shuffle(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Clear",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
	static void DataList_Clear(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Add Asset",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
	static void DataList_Add(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List,UPrimaryDataAsset* Asset, bool bInList, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|DataAssetList",DisplayName="💾Save - Data List - Add Assets",meta=(AdvancedDisplay="bGlobal",WorldContext = "WorldContextObject"))
	static void DataList_AddList(const UObject* WorldContextObject,UPARAM(meta = (Categories = "LIST")) FGameplayTag List,TArray<UPrimaryDataAsset*> Assets, bool bInList, bool bGlobal);
	
};

