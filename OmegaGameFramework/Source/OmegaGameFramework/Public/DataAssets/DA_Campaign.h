// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem_Save.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Campaign.generated.h"



class UOmegaQuest;

UCLASS(Blueprintable, BlueprintType,Const,Abstract,EditInlineNew,meta=(ShowWorldContextPin),CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOAsset_Campaign_Script : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Campaign")
	void OnCampaign_Started(UOAsset_Campaign* Campaign, UOmegaSaveSubsystem* Subsystem) const;
	//UFUNCTION(BlueprintImplementableEvent,Category="Campaign")
	//void OnCampaign_Ended(UOAsset_Campaign* Campaign, UOmegaSaveSubsystem* Subsystem) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Campaign")
	void OnCampaign_Loaded(UOAsset_Campaign* Campaign, UOmegaSaveSubsystem* Subsystem) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Campaign")
	void OnCampaign_Saved(UOAsset_Campaign* Campaign, UOmegaSaveSubsystem* Subsystem) const;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_Campaign : public UOmegaDataAsset
{
	GENERATED_BODY()


public:
	void ScriptEvent(int32 event,UOmegaSaveSubsystem* subsystem);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Campaign")
	UOmegaQuest* PrimaryQuest;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Campaign")
	TArray<UOAsset_Campaign_Script*> Scripts;

};

inline void UOAsset_Campaign::ScriptEvent(int32 event, UOmegaSaveSubsystem* subsystem)
{
	if(subsystem)
	{
		for(auto* s : Scripts)
		{
			if(s)
			{
				switch (event)
				{
				case  0: s->OnCampaign_Started(this,subsystem); break;
					//case  1: s->OnCampaign_Ended(this,subsystem); break;
				case  2: s->OnCampaign_Loaded(this,subsystem); break;
				case  3: s->OnCampaign_Saved(this,subsystem); break;
				default: ;
				}
			}
		}
	}
}
