// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "Modifiers/Modifier_Save.h"
#include "Selectors/Selector_DataAsset.h"
#include "modifiers_save.generated.h"


UCLASS(DisplayName="(Mod Save) Set Params")
class OMEGADEMO_API UOmegaModifier_Save_EditParams : public UOmegaModifier_Save
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,Category="Save") TMap<FName,int32> params_int;
	UPROPERTY(EditAnywhere,Category="Save") TMap<FName,float> params_float;
	UPROPERTY(EditAnywhere,Category="Save") TMap<FName,bool> params_bool;
	UPROPERTY(EditAnywhere,Category="Save") TMap<FName,FString> params_string;
	UPROPERTY(EditAnywhere,Category="Save") TMap<FName,TSoftObjectPtr<UPrimaryDataAsset>> params_asset;

	virtual bool Modify_Save_Implementation(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal) const override
	{
		if(Save && subsystem)
		{
			for(auto& p : params_int)
			{
				Save->GlobalVars.params_int.Add(p.Key,p.Value);
			}
			for(auto& p : params_float)
			{
				Save->GlobalVars.params_float.Add(p.Key,p.Value);
			}
			for(auto& p : params_bool)
			{
				Save->GlobalVars.params_bool.Add(p.Key,p.Value);
			}
			for(auto& p : params_string)
			{
				Save->GlobalVars.params_string.Add(p.Key,p.Value);
			}
			for(auto& p : params_asset)
			{
				Save->GlobalVars.params_DataAsset.Add(p.Key,p.Value.LoadSynchronous());
			}
		}
		return true;
	};
};

UCLASS(DisplayName="(Mod Save) Set Param - Data Asset")
class OMEGADEMO_API UOmegaModifier_Save_EditDataAssetParams : public UOmegaModifier_Save
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,Category="Save") FName ParamName;
	UPROPERTY(EditAnywhere,Category="Save") UOmegaSelector_DataAsset* Selector;

	virtual bool Modify_Save_Implementation(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal) const override
	{
		if(Save && subsystem)
		{
			if(Selector)
			{
				if(UPrimaryDataAsset* a=Selector->Get_DataAsset(subsystem))
				{
					Save->GlobalVars.params_DataAsset.Add(ParamName,a);
				}
			}
		}
		return true;
	};
};


UCLASS(DisplayName="(Mod Save) Edit Data Asset")
class OMEGADEMO_API UOmegaModifier_Save_EditDataAssets : public UOmegaModifier_Save
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,Category="Save") TArray<UPrimaryDataAsset*> CollectedAssets_Added;
	UPROPERTY(EditAnywhere,Category="Save") TArray<UPrimaryDataAsset*> CollectedAssets_Removed;
	UPROPERTY(EditAnywhere,Category="Save") TMap<UPrimaryDataAsset*,FGameplayTagContainer> Tags_Added;
	UPROPERTY(EditAnywhere,Category="Save") TMap<UPrimaryDataAsset*,FGameplayTagContainer> Tags_Removed;
	
	UPROPERTY(EditAnywhere,Category="Save") FGameplayTagContainer BulkAdd_Tags;
	UPROPERTY(EditAnywhere,Category="Save") TArray<UPrimaryDataAsset*> BulkAdd_Tags_List;
	UPROPERTY(EditAnywhere,Category="Save") FGameplayTagContainer BulkRemove_Tags;
	UPROPERTY(EditAnywhere,Category="Save") TArray<UPrimaryDataAsset*> BulkRemove_Tags_List;
	
	virtual bool Modify_Save_Implementation(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal) const override
	{
		if(Save && subsystem)
		{
			subsystem->SetDataAssetsCollected(CollectedAssets_Removed,bGlobal,false);
			subsystem->SetDataAssetsCollected(CollectedAssets_Added,bGlobal,true);
			for(auto& p : Tags_Removed)
			{
				subsystem->SetSaveTagsOnDataAsset(p.Key,p.Value,false,bGlobal);
			}
			for(auto& p : Tags_Added)
			{
				subsystem->SetSaveTagsOnDataAsset(p.Key,p.Value,true,bGlobal);
			}
			for(auto* a: BulkRemove_Tags_List)
			{
				subsystem->SetSaveTagsOnDataAsset(a,BulkRemove_Tags,false,bGlobal);
			}
			for(auto* a: BulkAdd_Tags_List)
			{
				subsystem->SetSaveTagsOnDataAsset(a,BulkAdd_Tags,true,bGlobal);
			}
		}
		return true;
	};
};

UCLASS(DisplayName="(Mod Save) Tags")
class OMEGADEMO_API UOmegaModifier_Save_EditTags : public UOmegaModifier_Save
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Save")
	FGameplayTagContainer SaveTags_Added;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Save")
	FGameplayTagContainer SaveTags_Removed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Save")
	FGameplayTag StoryState;
	
	virtual bool Modify_Save_Implementation(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal) const override
	{
		if(Save && subsystem)
		{
			subsystem->AddStoryTags(SaveTags_Added,bGlobal);
			subsystem->RemoveStoryTags(SaveTags_Removed,bGlobal);
		}
		if(StoryState.IsValid())
		{
			subsystem->SetStoryState(StoryState,bGlobal);
		}
		return true;
	};
};

