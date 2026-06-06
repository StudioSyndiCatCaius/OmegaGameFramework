
#pragma once

#include "Subsystems/Subsystem_Save.h"
#include "script_StoryStates.generated.h"

UCLASS(DisplayName="Story Script - Load Sublevels")
class OMEGADEMO_API UStoryState_Sublevel : public UOmegaStoryStateScript
{
	GENERATED_BODY()
	
public:
	
	//levels the player must be on for the sublevels to be loaded
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="State") TArray<TSoftObjectPtr<UWorld>> ValidMainlevels;
	//Loaded sublevels
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="State") TArray<TSoftObjectPtr<UWorld>> Sublevels;
	
	void L_SetActive(UOmegaSaveSubsystem* ss, bool bActive);
	
	virtual void OnLevelChange_Implementation(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State, const FString& LevelName) override;
	virtual void OnStateBegin_Implementation(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State) override;
	virtual void OnStateEnd_Implementation(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State) override;
	
};