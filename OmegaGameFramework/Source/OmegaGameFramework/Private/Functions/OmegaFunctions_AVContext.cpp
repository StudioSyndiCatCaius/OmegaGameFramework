// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_AVContext.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"

ULevelSequence* UOmegaContextAVFunctions::TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID, 
	ULevelSequence* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=true; 
		if (ULevelSequence* output=IDataInterface_ContextAV::Execute_GetContextAVSequences(Object,ID))
		{
			return output;
		};
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

USoundBase* UOmegaContextAVFunctions::TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID,  USoundBase* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=true; 
		if (USoundBase* output=IDataInterface_ContextAV::Execute_GetContextAVSounds(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

UNiagaraSystem* UOmegaContextAVFunctions::TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID, 
	UNiagaraSystem* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=true; 
		if (UNiagaraSystem* output=IDataInterface_ContextAV::Execute_GetContextAVNiagara(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

TSubclassOf<AActor> UOmegaContextAVFunctions::TryGetObjectContext_ActorClass(UObject* Object, FGameplayTag ID, TSubclassOf<AActor> Fallback,
	bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextActor::StaticClass()))
	{
		Outcome=true; 
		if (TSubclassOf<AActor> output=IDataInterface_ContextActor::Execute_GetContextAV_ActorClass(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

UStaticMesh* UOmegaContextAVFunctions::TryGetObjectContext_StaticMesh(UObject* Object, FGameplayTag ID,
	 UStaticMesh* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextMesh::StaticClass()))
	{
		Outcome=true; 
		if (UStaticMesh* output=IDataInterface_ContextMesh::Execute_GetContextAV_StaticMesh(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

USkeletalMesh* UOmegaContextAVFunctions::TryGetObjectContext_SkelMesh(UObject* Object, FGameplayTag ID,
	USkeletalMesh* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextMesh::StaticClass()))
	{
		Outcome=true; 
		if (USkeletalMesh* output=IDataInterface_ContextMesh::Execute_GetContextAV_SkeletalMesh(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

TSubclassOf<UAnimInstance> UOmegaContextAVFunctions::TryGetObjectContext_AnimClass(UObject* Object, FGameplayTag ID,
	TSubclassOf<UAnimInstance>  Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAnimation::StaticClass()))
	{
		Outcome=true; 
		if (TSubclassOf<UAnimInstance> output=IDataInterface_ContextAnimation::Execute_GetContextAV_AnimClass(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

FSlateBrush UOmegaContextAVFunctions::TryGetObjectContext_SlateBrush(UObject* Object, FGameplayTag ID,
                                                                     FSlateBrush Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextSlate::StaticClass()))
	{
		FSlateBrush output=IDataInterface_ContextSlate::Execute_GetContextAV_SlateBrush(Object,ID);
		if(output.GetResourceObject())
		{
			Outcome=true;
			return output;
		}
	}
	if(Fallback.GetResourceObject())
	{
		Outcome=true;
		return Fallback;
	}
	Outcome=false; return FSlateBrush();
}

FText UOmegaContextAVFunctions::TryGetObjectContext_Text(UObject* Object, FGameplayTag ID, FText Fallback,
	bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextSlate::StaticClass()))
	{
		FText output=IDataInterface_ContextString::Execute_GetContextAV_Text(Object,ID);
		if(!output.IsEmpty())
		{
			Outcome=true;
			return output;
		}
	}
	if(!Fallback.IsEmpty())
	{
		Outcome=true;
		return Fallback;
	}
	Outcome=false; return FText();
}

UAnimMontage* UOmegaContextAVFunctions::TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID, 
                                                                     UAnimMontage* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=true; 
		if (UAnimMontage* output=IDataInterface_ContextAV::Execute_GetContextAVMontages(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}

UAnimSequence* UOmegaContextAVFunctions::TryGetObjectContext_AnimSequence(UObject* Object, FGameplayTag ID, 
	UAnimSequence* Fallback,bool& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=true; 
		if (UAnimSequence* output=IDataInterface_ContextAV::Execute_GetContextAVAnimations(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=true; return Fallback; };
	Outcome=false; return nullptr;
}
