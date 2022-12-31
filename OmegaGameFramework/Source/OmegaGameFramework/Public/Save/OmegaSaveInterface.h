// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "UObject/Interface.h"
#include "OmegaSaveInterface.generated.h"

class UOmegaSaveGame;

// This class does not need to be modified.
UINTERFACE()
class UOmegaSaveInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IOmegaSaveInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save")
	bool OnGameFileSaved(UOmegaSaveGame* SaveFile);

	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save")
    void OnGameFileStarted(UOmegaSaveGame* SaveFile);


	// JSON
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	bool UseJsonSaveData();
	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	FString GetJsonPropertyName();
	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	FJsonObjectWrapper SaveJsonData();
	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	bool LoadJsonData(FJsonObjectWrapper SaveFile);
};
