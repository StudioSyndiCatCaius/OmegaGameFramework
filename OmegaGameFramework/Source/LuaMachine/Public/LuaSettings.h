
#pragma once

#include "CoreMinimal.h"
#include "LuaState.h"
#include "Engine/DeveloperSettings.h"
#include "UObject/SoftObjectPath.h"
#include "LuaSettings.generated.h"

class ULuaObject;

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Lua"))
class LUAMACHINE_API ULuaSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(EditAnywhere, config, Category = "Default", meta = (MetaClass = "LuaState"))
	TSoftClassPtr<ULuaState> DefaultState;
	UPROPERTY(EditAnywhere, config, Category = "Default", meta = (MetaClass = "LuaState"))
	TSoftClassPtr<ULuaObject> DefaultObject;
	UPROPERTY(EditAnywhere, config, Category = "Default")
	bool bAutorunFiles=false;
	UPROPERTY(EditAnywhere, config, Category = "Default")
	FString Autorun_ContentPath="Lua";
	UPROPERTY(EditAnywhere, config, Category = "Default")
	FString Autorun_InitFile="main";
	UPROPERTY(EditAnywhere, config, Category = "Default")
	TArray<TSoftObjectPtr<ULuaCode>> AutorunCodeAssets;
};

