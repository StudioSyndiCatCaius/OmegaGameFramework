// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Save.h"

#include "Modifiers/Modifier_Save.h"
#include "Subsystems/OmegaSubsystem_Save.h"


void UFlowNode_SaveEdit::ExecuteInput(const FName& PinName)
{
	UOmegaSaveSubsystem* sub=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	if(sub)
	{
		FOmegaModifiers_Save mods;
		mods.Modifiers=Modifiers;
		mods.Modify(sub->GetSaveObject(bGlobal),sub,bGlobal);
	}
	TriggerFirstOutput(true);
}

UFlowNode_SaveCondition::UFlowNode_SaveCondition()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("True")));
	OutputPins.Add(FFlowPin(TEXT("False")));
	
	//NodeStyle = EFlowNodeStyle::Condition;
#if WITH_EDITOR
	Category = TEXT("Save");
#endif
}

void UFlowNode_SaveCondition::ExecuteInput(const FName& PinName)
{
	FOmegaSaveConditions con;
	con.Conditions=Conditions;
	if(bool LocalSuccess = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->CustomSaveConditionsMet(con))
	{
		TriggerOutput(FName("True"),true);
	}
	else
	{
		TriggerOutput(FName("False"),true);
	}
}

UFlowNode_SaveOnce::UFlowNode_SaveOnce()
{
	SaveParam=TEXT("flow_once");
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	InputPins.Add(FFlowPin(TEXT("Reset")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("First")));
	OutputPins.Add(FFlowPin(TEXT("Then")));
}

void UFlowNode_SaveOnce::ExecuteInput(const FName& PinName)
{
	UOmegaSaveSubsystem* sub=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	if(sub)
	{
		if(UOmegaSaveBase* sav=sub->GetSaveObject(bGlobal))
		{
			FOmegaEntity e=sav->Entities.Entities_Guid.FindOrAdd(GetGuid());
			if(e.params_int32.FindOrAdd(SaveParam)==0)
			{
				if(PinName.ToString()=="In")
				{
					e.params_int32.Add(SaveParam,1);
					sav->Entities.Entities_Guid.Add(GetGuid(),e);
					TriggerOutput(TEXT("First"),true);
					return;
				}
			}
			else
			{
				if(PinName.ToString()=="Reset")
				{
					e.params_int32.Add(SaveParam,0);
					sav->Entities.Entities_Guid.Add(GetGuid(),e);
					return;
				}
			}
		}
	}
	
	TriggerOutput(TEXT("Then"),true);
}
