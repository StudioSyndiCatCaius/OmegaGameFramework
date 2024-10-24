// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_AVContext.h"
#include "GameplayTagContainer.h"


ULevelSequence* UOmegaContextAVFunctions::TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID,
	ULevelSequence* Fallback)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		return IDataInterface_ContextAV::Execute_GetContextAVSequences(Object,ID);
	}
	
	return  Fallback;
}

USoundBase* UOmegaContextAVFunctions::TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID, USoundBase* Fallback)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		return IDataInterface_ContextAV::Execute_GetContextAVSounds(Object,ID);
	}
	return  Fallback;
}

UNiagaraSystem* UOmegaContextAVFunctions::TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID,
	UNiagaraSystem* Fallback)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		return IDataInterface_ContextAV::Execute_GetContextAVNiagara(Object,ID);
	}
	return  Fallback;
}

UAnimMontage* UOmegaContextAVFunctions::TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID,
	UAnimMontage* Fallback)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		return IDataInterface_ContextAV::Execute_GetContextAVMontages(Object,ID);
	}
	return  Fallback;
}

UAnimSequence* UOmegaContextAVFunctions::TryGetObjectContext_AnimSequence(UObject* Object, FGameplayTag ID,
	UAnimSequence* Fallback)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		return IDataInterface_ContextAV::Execute_GetContextAVAnimations(Object,ID);
	}
	return  Fallback;
}
