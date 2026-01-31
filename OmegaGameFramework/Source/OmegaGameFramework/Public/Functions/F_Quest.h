// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem_Quest.h"
#include "F_Quest.generated.h"


UENUM(BlueprintType)
enum EOmegaQuestConditionType
{
	QuestFilter_Startable UMETA(DisplayName="Can Start?"),
	QuestFilter_Active UMETA(DisplayName="Active?"),
	QuestFilter_Complete UMETA(DisplayName="Complete?"),
};


UCLASS()
class UOmegaFunctions_Quest : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="Quest - Start",meta=(WorldContext="WorldContext"))
	static bool Start(UObject* WorldContext, UOmegaQuest* quest);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="Quest - End",meta=(WorldContext="WorldContext"))
	static bool End(UObject* WorldContext, UOmegaQuest* quest, bool bComplete);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="Quest - Check Condition",meta=(WorldContext="WorldContext"))
	static bool CheckCondition(UObject* WorldContext, UOmegaQuest* in, EOmegaQuestConditionType Condition);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="Quests - Filter",meta=(WorldContext="WorldContext"))
	static TArray<UOmegaQuest*> Filter(UObject* WorldContext, TArray<UOmegaQuest*> in, EOmegaQuestConditionType Filter, bool NOT=false);
};


