// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataInterface_ContextAV.h"

// Add default functionality here for any IDataInterface_General functions that are not pure virtual.
ULevelSequence* UOmegaContextAVFunctions::TryGetObjectContext_Seqeunce(UObject* Object, FGameplayTag ID)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		TArray<FGameplayTag> IDList;
		TMap<FGameplayTag, ULevelSequence*> TempData = IDataInterface_ContextAV::Execute_GetContextAVSequences(Object);
		TempData.GetKeys(IDList);
		for(FGameplayTag TempID : IDList)
		{
			if(TempData.Contains(ID))
			{
				return TempData[ID];
			}
		}
	}
	return nullptr;
}

USoundBase* UOmegaContextAVFunctions::TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		TArray<FGameplayTag> IDList;
		TMap<FGameplayTag, USoundBase*> TempData = IDataInterface_ContextAV::Execute_GetContextAVSounds(Object);
		TempData.GetKeys(IDList);
		for(FGameplayTag TempID : IDList)
		{
			if(TempData.Contains(ID))
			{
				return TempData[ID];
			}
		}
	}
	return nullptr;
}

UNiagaraSystem* UOmegaContextAVFunctions::TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		TArray<FGameplayTag> IDList;
		TMap<FGameplayTag, UNiagaraSystem*> TempData = IDataInterface_ContextAV::Execute_GetContextAVNiagara(Object);
		TempData.GetKeys(IDList);
		for(FGameplayTag TempID : IDList)
		{
			if(TempData.Contains(ID))
			{
				return TempData[ID];
			}
		}
	}
	return nullptr;
}
