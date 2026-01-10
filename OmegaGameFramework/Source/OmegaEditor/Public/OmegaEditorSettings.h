// OmegaEditorSettings.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "OmegaEditorSettings.generated.h"

USTRUCT(BlueprintType)
struct FOmegaEditorCommandsList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Commands")
	TArray<FString> CommandNames;
};


DECLARE_MULTICAST_DELEGATE_TwoParams(FOnCommandEvent, UObject*, int32);

UCLASS(Config=Editor, DefaultConfig, meta=(DisplayName="Omega Editor Settings"))
class OMEGAEDITOR_API UOmegaEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "Commands")
	TMap<TSoftClassPtr<UObject>, FOmegaEditorCommandsList> ClassCommands;

	// Event fired when a command button is pressed
	FOnCommandEvent OnCommandEvent;

	void FireCommandEvent(UObject* Object, int32 CommandIndex)
	{
		OnCommandEvent.Broadcast(Object, CommandIndex);
	}

	static UOmegaEditorSettings* Get()
	{
		return GetMutableDefault<UOmegaEditorSettings>();
	}
};