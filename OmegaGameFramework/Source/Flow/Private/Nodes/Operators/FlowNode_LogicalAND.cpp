// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Nodes/Operators/FlowNode_LogicalAND.h"

#include "Subsystems/Subsystem_Save.h"

UFlowNode_LogicalAND::UFlowNode_LogicalAND(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Operators");
	NodeStyle = EFlowNodeStyle::Logic;
#endif

	SetNumberedInputPins(0, 1);
}

#if WITH_EDITOR
FText UFlowNode_LogicalAND::GetNodeTitle() const
{
	return Super::GetNodeTitle();
}
#endif

void UFlowNode_LogicalAND::ExecuteInput(const FName& PinName)
{
	if (bSaved)
	{
		UOmegaSaveSubsystem* sub=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
		FOmegaEntity _entity=sub->GetSaveObject(false)->Entities.Entities_Guid.FindOrAdd(GetGuid());
		_entity.Tags_Named.AddUnique(PinName);
		ExecutedInputNames=_entity.Tags_Named;
		sub->GetSaveObject(false)->Entities.Entities_Guid.Add(GetGuid(),_entity);
	}
	else
	{
		ExecutedInputNames.AddUnique(PinName);
	}

	if (ExecutedInputNames.Num() == InputPins.Num())
	{
		TriggerFirstOutput(true);
	}
}

void UFlowNode_LogicalAND::Cleanup()
{
	ExecutedInputNames.Empty();
}
