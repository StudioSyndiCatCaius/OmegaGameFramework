// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataTrait.h"

TMap<FGameplayTag, ULevelSequence*> UOmegaDataTrait::GetContextAVSequences_Implementation()
{
	return IDataInterface_ContextAV::GetContextAVSequences_Implementation();
}

TMap<FGameplayTag, USoundBase*> UOmegaDataTrait::GetContextAVSounds_Implementation()
{
	return IDataInterface_ContextAV::GetContextAVSounds_Implementation();
}

TMap<FGameplayTag, UNiagaraSystem*> UOmegaDataTrait::GetContextAVNiagara_Implementation()
{
	return IDataInterface_ContextAV::GetContextAVNiagara_Implementation();
}
