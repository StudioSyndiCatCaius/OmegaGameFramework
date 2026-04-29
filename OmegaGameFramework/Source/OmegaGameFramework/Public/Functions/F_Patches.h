// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "F_Patches.generated.h"

class UOmegaSaveGame;

UCLASS(BlueprintType, Blueprintable,Abstract,meta=(ShowWorldContextPin))
class UOmegaGamePatch : public UObject
{
	GENERATED_BODY()

public:
	UOmegaGamePatch();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly) FGuid GUID;

	//Fired when this patch is first applied to a save game. This works for any new or loaded save games that don't have the patch GUID logged.
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnFirstApplied(UGameInstance* GameInstance,UOmegaSaveGame* Save);
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnGame_Start(UGameInstance* GameInstance);
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnGame_End(UGameInstance* GameInstance);
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnLevel_Start(UGameInstance* GameInstance);
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnLevel_End(UGameInstance* GameInstance);
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnSave_Created(UGameInstance* GameInstance,UOmegaSaveGame* Save);
	UFUNCTION(BlueprintNativeEvent,Category="Achievements") void OnSave_Started(UGameInstance* GameInstance,UOmegaSaveGame* Save);
	
};



UCLASS()
class UOmegaFunctions_Patch : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:


	
};


