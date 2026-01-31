// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_GlobalParam.h"

#include "Dom/JsonObject.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Functions/F_Conv.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Gameplay.h"


FOmegaSoftParams* UOmegaFunctions_GlobalVars::GetParamStruct(UObject* WorldContextObject,
                                                             EOmegaGlobalParamTarget Target)
{
	if (WorldContextObject)
	{
		UGameInstance* GI=nullptr;
		if (WorldContextObject->GetWorld()->GetGameInstance())
		{
			GI=WorldContextObject->GetWorld()->GetGameInstance();
		}
		else
		{
			return nullptr;
		}
		
		switch (Target) {
		case WORLD:
			return &WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GlobalVars;
		case GAME_INSTANCE:
			if (GI)
			{
				return &GI->GetSubsystem<UOmegaGameManager>()->GlobalVars;	
			}
		case SAVE_GAME:
			if (GI)
			{
				return &GI->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(false)->GlobalVars;	
			}
		case SAVE_GLOBAL:
			if (GI)
			{
				return &GI->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(true)->GlobalVars;	
			}
		}
	}
	return nullptr;
}



void UOmegaFunctions_GlobalVars::SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
                                                        FName Variable, bool Value)
{
	GetParamStruct(WorldContextObject,Target)->params_bool.Add(Variable, Value);
}

bool UOmegaFunctions_GlobalVars::GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		return p->params_bool.FindOrAdd(Variable);
	}
	return false; 
}

void UOmegaFunctions_GlobalVars::SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable, int32 Value)
{
	GetParamStruct(WorldContextObject,Target)->params_int.Add(Variable, Value);
}

int32 UOmegaFunctions_GlobalVars::GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		return p->params_int.FindOrAdd(Variable);
	}
	return 0; 
}

void UOmegaFunctions_GlobalVars::SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable, float Value)
{
	GetParamStruct(WorldContextObject,Target)->params_float.Add(Variable, Value);
}

float UOmegaFunctions_GlobalVars::GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
                                                          FName Variable)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		return p->params_float.FindOrAdd(Variable);
	}
	return 0; 
}

void UOmegaFunctions_GlobalVars::SetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable, FString Value)
{
	GetParamStruct(WorldContextObject,Target)->params_string.Add(Variable, Value);
}

FString UOmegaFunctions_GlobalVars::GetGlobalVariable_String(UObject* WorldContextObject,
	EOmegaGlobalParamTarget Target, FName Variable)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		return p->params_string.FindOrAdd(Variable);
	}
	return ""; 
}

void UOmegaFunctions_GlobalVars::SetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable, FVector Value)
{
	GetParamStruct(WorldContextObject,Target)->params_float.Append(UOmegaFunctions_Conv::Vector_2_FloatMap(Variable,Value));
}

FVector UOmegaFunctions_GlobalVars::GetGlobalVariable_Vector(UObject* WorldContextObject,
	EOmegaGlobalParamTarget Target, FName Variable)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		return UOmegaFunctions_Conv::FloatMap_2_Vector(Variable,p->params_float);
	}
	return FVector(); 
}

void UOmegaFunctions_GlobalVars::SetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FName Variable, FRotator Value)
{
	GetParamStruct(WorldContextObject,Target)->params_float.Append(UOmegaFunctions_Conv::Rotator_2_FloatMap(Variable,Value));
}

FRotator UOmegaFunctions_GlobalVars::GetGlobalVariable_Rotator(UObject* WorldContextObject,
	EOmegaGlobalParamTarget Target, FName Variable)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		return UOmegaFunctions_Conv::FloatMap_2_Rotator(Variable,p->params_float);
	}
	return FRotator(); 
}

void UOmegaFunctions_GlobalVars::SetGlobalVariable_DataAsset(UObject* WorldContextObject,
	EOmegaGlobalParamTarget Target, FName Variable, UPrimaryDataAsset* Value)
{
	GetParamStruct(WorldContextObject,Target)->params_DataAsset.Add(Variable, Value);
}

UPrimaryDataAsset* UOmegaFunctions_GlobalVars::GetGlobalVariable_DataAsset(UObject* WorldContextObject,
	EOmegaGlobalParamTarget Target, FName Variable)
{
	
	return nullptr;
}

void UOmegaFunctions_GlobalVars::Bitflag_Set(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,FGameplayTag Tag, uint8 Flag, bool bValue)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		
		// Bounds check - int32 only has 32 bits (0-31)
		if (Flag >= 32)
		{
			UE_LOG(LogTemp, Warning, TEXT("Bitflag_Set: Flag %d out of range (max 31)"), Flag);
			return;
		}
    
		int32& Bitfield =  p->bitflags.FindOrAdd(Tag);
    
		if (bValue)
		{
			Bitfield |= (1 << Flag); // Set bit
		}
		else
		{
			Bitfield &= ~(1 << Flag); // Clear bit
		}
    
		// Optional: Remove entry if all bits are cleared
		if (Bitfield == 0)
		{
			p->bitflags.Remove(Tag);
		}	
	}
}

bool UOmegaFunctions_GlobalVars::Bitflag_Get(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,FGameplayTag Tag, uint8 Flag)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		if (Flag >= 32)
		{
			return false;
		}
    
		const int32* Bitfield = p->bitflags.Find(Tag);
		if (!Bitfield)
		{
			return false;
		}
    
		return (*Bitfield & (1 << Flag)) != 0;
	}
	return false;
}

void UOmegaFunctions_GlobalVars::Bitflag_Clear(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FGameplayTag Tag)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		p->bitflags.Remove(Tag);
	}
}

bool UOmegaFunctions_GlobalVars::Bitflag_HasAny(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FGameplayTag Tag)
{
	if (FOmegaSoftParams* p=GetParamStruct(WorldContextObject,Target))
	{
		const int32* Bitfield = p->bitflags.Find(Tag);
		return Bitfield && (*Bitfield != 0);
	}
	return false;
}

