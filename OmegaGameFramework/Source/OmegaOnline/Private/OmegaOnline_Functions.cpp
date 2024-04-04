// Fill out your copyright notice in the Description page of Project Settings.

#include "OmegaOnline_Functions.h"


UOmegaSessionDataObject* UOmegaOnlineFunctions::CreateSessionObject(UObject* WorldContextObject,
	FBlueprintSessionResult Result)
{
	UOmegaSessionDataObject* out = NewObject<UOmegaSessionDataObject>(WorldContextObject);
	out->ResultData=Result;
	return out;
}

TArray<UOmegaSessionDataObject*> UOmegaOnlineFunctions::CreateSessionObjects(UObject* WorldContextObject,
	TArray<FBlueprintSessionResult> Results)
{
	TArray<UOmegaSessionDataObject*> out;
	for(FBlueprintSessionResult temp_result : Results)
	{
		out.Add(CreateSessionObject(WorldContextObject, temp_result));
	}
	return out;
}
