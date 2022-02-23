// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"

#include "Action.h"

#include "BTT_RunAction.generated.h"


/**
 *
 */
UCLASS()
class ACTIONS_API UBTT_RunAction : public UBTTaskNode
{
	GENERATED_BODY()

public:

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Node", meta = (DisplayName = "Action"))
	UAction* ActionType;

	UPROPERTY()
	UAction* Action;

	UPROPERTY(Transient)
	UBehaviorTreeComponent* OwnerComp;


	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& InOwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& InOwnerComp, uint8* NodeMemory) override;
	virtual void DescribeRuntimeValues(const UBehaviorTreeComponent& InOwnerComp, uint8* NodeMemory, EBTDescriptionVerbosity::Type Verbosity, TArray<FString>& Values) const override;
	virtual FString GetStaticDescription() const override;

	UFUNCTION()
	void OnRunActionFinished(const EActionState Reason);
};
