// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_AVContext.h"
#include "GameplayTagContainer.h"

// Add default functionality here for any IDataInterface_General functions that are not pure virtual.
ULevelSequence* UOmegaContextAVFunctions::TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID)
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

UAnimMontage* UOmegaContextAVFunctions::TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		TArray<FGameplayTag> IDList;
		TMap<FGameplayTag, UAnimMontage*> TempData = IDataInterface_ContextAV::Execute_GetContextAVMontages(Object);
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

UAnimSequence* UOmegaContextAVFunctions::TryGetObjectContext_AnimSequence(UObject* Object, FGameplayTag ID)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		TArray<FGameplayTag> IDList;
		TMap<FGameplayTag, UAnimSequence*> TempData = IDataInterface_ContextAV::Execute_GetContextAVAnimations(Object);
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
