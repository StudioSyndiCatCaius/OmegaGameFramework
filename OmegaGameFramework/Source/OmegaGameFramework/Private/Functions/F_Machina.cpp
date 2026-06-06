// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Machina.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"


bool L_UsesInterface(UObject* test_obj)
{
	if (test_obj &&  test_obj->GetClass()->ImplementsInterface(UObjectInterface_Machina::StaticClass()))
	{
	return true;	
	}
	return false;
}

// ===================================================================================================================
// Function Lib
// ===================================================================================================================
bool UOmegaFunctions_Machina::CanSetState(UObject* Object, FName state)
{
	if (state.IsValid() && L_UsesInterface(Object))
	{
		return true;
	}
	return false;
}

void UOmegaFunctions_Machina::SetState(UObject* Object, FName state, FOmegaCommonMeta Meta)
{
	if (state!=GetState(Object))
	{
		if (L_UsesInterface(Object) && state.IsValid())
		{
			StopState_Current(Object,Meta);
			if (UOmegaSubsystem_GameInstance* gi=OGF_Subsystems::oGameInstance(Object))
			{
				gi->machina_states.FindOrAdd(Object).current_state=state;
				IObjectInterface_Machina::Execute_Machina_StateBegin(Object,state,Meta);
				gi->OnMachinaState_Begin.Broadcast(Object,state,Meta);
			}
		}	
	}
}

void UOmegaFunctions_Machina::StopState_Current(UObject* Object, FOmegaCommonMeta Meta)
{
	FName current_state=GetState(Object);
	if (L_UsesInterface(Object) && current_state.IsValid())
	{
		if (UOmegaSubsystem_GameInstance* gi=OGF_Subsystems::oGameInstance(Object))
		{
			gi->machina_states.FindOrAdd(Object).current_state=FName();
			IObjectInterface_Machina::Execute_Machina_StateEnd(Object,current_state,Meta);
			gi->OnMachinaState_End.Broadcast(Object,current_state,Meta);
		}
	}
}

FName UOmegaFunctions_Machina::GetState(UObject* Object)
{
	if (L_UsesInterface(Object))
	{
		if (UOmegaSubsystem_GameInstance* gi=OGF_Subsystems::oGameInstance(Object))
		{
			if (gi->machina_states.Contains(Object))
			{
				FOmegaMachinaState _stateData=gi->machina_states[Object];
				return _stateData.current_state;
			}
		}
	}
	return FName();
}

// ===================================================================================================================
// Async Task
// ===================================================================================================================
void UMachina_RunState::EventFinish(UObject* _TargetObject, FName _State, FOmegaCommonMeta Meta)
{
	if (_TargetObject==TargetObject && _State==TargetState)
	{
		Finished.Broadcast(Meta);
	}
}

void UMachina_RunState::Activate()
{
	Super::Activate();
	if (UOmegaFunctions_Machina::CanSetState(TargetObject,TargetState))
	{
		if (UOmegaSubsystem_GameInstance* gi=OGF_Subsystems::oGameInstance(TargetObject))
		{
			gi->OnMachinaState_End.AddDynamic(this,&UMachina_RunState::EventFinish);
			UOmegaFunctions_Machina::SetState(TargetObject,TargetState,TargetMeta);	
		}
		else
		{
			SetReadyToDestroy();
		}
	}
	else
	{
		SetReadyToDestroy();
	}
}

UMachina_RunState* UMachina_RunState::RunObjectMachinaState(UObject* Object, FName State,
                                                            FOmegaCommonMeta meta)
{
	UMachina_RunState* NewNode = NewObject<UMachina_RunState>();
	NewNode->TargetObject = Object;
	NewNode->TargetState = State;
	NewNode->TargetMeta = meta;
	return NewNode;
}
