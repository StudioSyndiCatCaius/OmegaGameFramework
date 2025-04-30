// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_AVContext.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"

ULevelSequence* UOmegaContextAVFunctions::TryGetObjectContext_Sequence(UObject* Object, FGameplayTag ID, 
	ULevelSequence* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=Success; 
		if (ULevelSequence* output=IDataInterface_ContextAV::Execute_GetContextAVSequences(Object,ID))
		{
			return output;
		};
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

USoundBase* UOmegaContextAVFunctions::TryGetObjectContext_Sounds(UObject* Object, FGameplayTag ID,  USoundBase* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=Success; 
		if (USoundBase* output=IDataInterface_ContextAV::Execute_GetContextAVSounds(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

UNiagaraSystem* UOmegaContextAVFunctions::TryGetObjectContext_Niagara(UObject* Object, FGameplayTag ID, 
	UNiagaraSystem* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=Success; 
		if (UNiagaraSystem* output=IDataInterface_ContextAV::Execute_GetContextAVNiagara(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

TSubclassOf<AActor> UOmegaContextAVFunctions::TryGetObjectContext_ActorClass(UObject* Object, FGameplayTag ID, TSubclassOf<AActor> Fallback,
	TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextActor::StaticClass()))
	{
		Outcome=Success; 
		if (TSubclassOf<AActor> output=IDataInterface_ContextActor::Execute_GetContextAV_ActorClass(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

UStaticMesh* UOmegaContextAVFunctions::TryGetObjectContext_StaticMesh(UObject* Object, FGameplayTag ID,
	 UStaticMesh* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextMesh::StaticClass()))
	{
		Outcome=Success; 
		if (UStaticMesh* output=IDataInterface_ContextMesh::Execute_GetContextAV_StaticMesh(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

USkeletalMesh* UOmegaContextAVFunctions::TryGetObjectContext_SkelMesh(UObject* Object, FGameplayTag ID,
	USkeletalMesh* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextMesh::StaticClass()))
	{
		Outcome=Success; 
		if (USkeletalMesh* output=IDataInterface_ContextMesh::Execute_GetContextAV_SkeletalMesh(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

TSubclassOf<UAnimInstance> UOmegaContextAVFunctions::TryGetObjectContext_AnimClass(UObject* Object, FGameplayTag ID,
	TSubclassOf<UAnimInstance>  Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAnimation::StaticClass()))
	{
		Outcome=Success; 
		if (TSubclassOf<UAnimInstance> output=IDataInterface_ContextAnimation::Execute_GetContextAV_AnimClass(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

FSlateBrush UOmegaContextAVFunctions::TryGetObjectContext_SlateBrush(UObject* Object, FGameplayTag ID,
                                                                     FSlateBrush Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextSlate::StaticClass()))
	{
		FSlateBrush output=IDataInterface_ContextSlate::Execute_GetContextAV_SlateBrush(Object,ID);
		if(output.GetResourceObject())
		{
			Outcome=Success;
			return output;
		}
	}
	if(Fallback.GetResourceObject())
	{
		Outcome=Success;
		return Fallback;
	}
	Outcome=Fail; return FSlateBrush();
}

FText UOmegaContextAVFunctions::TryGetObjectContext_Text(UObject* Object, FGameplayTag ID, FText Fallback,
	TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextSlate::StaticClass()))
	{
		FText output=IDataInterface_ContextString::Execute_GetContextAV_Text(Object,ID);
		if(!output.IsEmpty())
		{
			Outcome=Success;
			return output;
		}
	}
	if(!Fallback.IsEmpty())
	{
		Outcome=Success;
		return Fallback;
	}
	Outcome=Fail; return FText();
}

UAnimMontage* UOmegaContextAVFunctions::TryGetObjectContext_Montages(UObject* Object, FGameplayTag ID, 
                                                                     UAnimMontage* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=Success; 
		if (UAnimMontage* output=IDataInterface_ContextAV::Execute_GetContextAVMontages(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}

UAnimSequence* UOmegaContextAVFunctions::TryGetObjectContext_AnimSequence(UObject* Object, FGameplayTag ID, 
	UAnimSequence* Fallback, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_ContextAV::StaticClass()))
	{
		Outcome=Success; 
		if (UAnimSequence* output=IDataInterface_ContextAV::Execute_GetContextAVAnimations(Object,ID)) { return output; }
	}
	if(Fallback) { Outcome=Success; return Fallback; };
	Outcome=Fail; return nullptr;
}
