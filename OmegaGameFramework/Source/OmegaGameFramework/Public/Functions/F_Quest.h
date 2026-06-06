// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Quest.generated.h"


class UOmegaQuest;
class AOmegaQuestInstance;

/** Determines which state to test quests against when filtering or checking conditions. */
UENUM(BlueprintType)
enum EOmegaQuestConditionType
{
	QuestFilter_Startable UMETA(DisplayName="Can Start?"),  // Quest can currently be started (not active, prerequisites met)
	QuestFilter_Active    UMETA(DisplayName="Active?"),     // Quest is currently in progress
	QuestFilter_Complete  UMETA(DisplayName="Complete?"),   // Quest has been completed
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Quest : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/** Returns all currently active quest instances in the world. */
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="📜Quest - Get All Active (Instances)",meta=(WorldContext="WorldContext"))
	static TArray<AOmegaQuestInstance*> GetAllActiveInstances(UObject* WorldContext);

	/** Starts the given quest and returns its new instance. Returns null if the quest cannot be started. */
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="📜Quest - Start",meta=(WorldContext="WorldContext"))
	static AOmegaQuestInstance* Start(UObject* WorldContext, UOmegaQuest* quest);

	/** Ends the given quest. bComplete: true = mark as completed, false = abandon/fail. Returns true on success. */
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="📜Quest - End",meta=(WorldContext="WorldContext"))
	static bool End(UObject* WorldContext, UOmegaQuest* quest, bool bComplete);

	/** Checks a single quest against the given condition (startable / active / complete). Returns true if the condition is met. */
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="📜Quest - Check Condition",meta=(WorldContext="WorldContext"))
	static bool CheckCondition(UObject* WorldContext, UOmegaQuest* in, EOmegaQuestConditionType Condition);

	/** Filters a list of quests by the given condition. NOT=true inverts the filter (excludes matching quests). */
	UFUNCTION(BlueprintCallable,Category="Omega|Quest",DisplayName="📜Quests - Filter",meta=(WorldContext="WorldContext"))
	static TArray<UOmegaQuest*> Filter(UObject* WorldContext, TArray<UOmegaQuest*> in, EOmegaQuestConditionType Filter, bool NOT=false);
};


