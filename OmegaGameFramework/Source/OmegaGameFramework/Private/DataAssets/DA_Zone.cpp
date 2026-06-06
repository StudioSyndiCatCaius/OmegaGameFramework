// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_Zone.h"

#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

TSoftObjectPtr<UWorld> UOmegaLevelData::GetLevel() const
{
	FString path=UKismetSystemLibrary::GetPathName(this);
	path=UKismetStringLibrary::Replace(path,"_WorldData","");
	return TSoftObjectPtr<UWorld>(FSoftObjectPath(path));
}
