#pragma once


#include "FlowTypes.h"
#include "Actors/Actor_Quest.h"
#include "Functions/F_ScriptedEffects.h"
#include "Nodes/FlowNode.h"
#include "script_QuestTypes.generated.h"

class UFlowAsset;

UCLASS(DisplayName="(📜Quest Type) FlowAsset")
class OMEGADEMO_API UOmegaQuestType_FlowAsset : public UOmegaQuestTypeScript
{
	GENERATED_BODY()
public:
	//void L_StartQuestFlow(UFlowAsset* flow, FFlowAssetOverrideData data) const;
	
	UFlowAsset* L_GetFlowInstance() const;
	
	virtual void OnQuestStart_Implementation(AOmegaQuestInstance* Instance) const override;
	virtual void OnLoad_Implementation(AOmegaQuestInstance* Instance, FOmegaQuestData data) const override;
	virtual TArray<UObject*> GetActiveTasks_Implementation(AOmegaQuestInstance* Instance) const override;
	UFUNCTION() void L_OnFlowNodeEnter(UFlowAsset* FlowAsset, UFlowNode* Node, FName Input);
	UFUNCTION() void L_OnFlowFinish(UFlowAsset* FlowAsset, FName Output, const FString& Flag);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects")
	UFlowAsset* Flow_Asset;
};
