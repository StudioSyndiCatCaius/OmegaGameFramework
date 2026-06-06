// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Types/Struct_SortedClassPath.h"


UObject* FOmegaSortedClassPathData::getAssetFromPath(const FString& AssetPath, TSubclassOf<UObject> Class)
{
	for (auto* a : AssetScripts)
	{
		if (a)
		{
			// try get via script
			if (UObject* out=a->OnGetAssetByPath(AssetPath,Class))
			{
				return out;
			}
		}
	}
	return nullptr;
}
