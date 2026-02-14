// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Paths.h"

#include "OmegaSettings.h"
#include "Kismet/KismetStringLibrary.h"

TArray<FString> UOmegaSettings_Paths::GetPathsFromAssetName(const FString& AssetName, TSubclassOf<UObject> Class)
{
	TArray<FString> out;
	if(ClassPaths.Contains(Class))
	{
		FOmegaSortedClassPathData sort_data=ClassPaths[Class];
		for (FString temp_string : sort_data.AssetPaths)
		{
			FString new_asset_name=sort_data.AssetPrefex+AssetName+sort_data.AssetSuffex;
			FString new_path=temp_string+'/'+new_asset_name+'.'+new_asset_name;
			new_path=new_path.Replace(TEXT("//"),TEXT("/"));
			new_path=new_path.Replace(TEXT("///"),TEXT("/"));
			out.Add(new_path);
		}
	}
	for(auto* a : ImportedPaths)
	{
		if(a)
		{
			out.Append(a->GetPathsFromAssetName(AssetName,Class));
		}
	}
	return out;
}

UOmegaSettings_Paths* UOmegaSettings_PathFunctions::GetOmegaPathSettings()
{
	if(UOmegaSettings_Paths* out = Cast<UOmegaSettings_Paths>(GetMutableDefault<UOmegaSettings>()->DefaultSettings_Paths.TryLoad()))
	{
		return out;
	}
	return nullptr;
}
