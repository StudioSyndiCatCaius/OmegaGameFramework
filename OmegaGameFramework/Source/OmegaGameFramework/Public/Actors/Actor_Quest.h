// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaActors.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_Common.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Quest.generated.h"

class AOmegaWorldManager;
class UOmegaQuest;



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaQuest : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	UOmegaQuest();
	
	//TRUE = a quest with a COMPLET or FAILED stat can still be started again
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Quest")
	bool Replayable;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Quest",meta=(ExposeOnSpawn))
	UOmegaQuestTypeScript* QuestScript;
	
};

UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaQuestTypeScript : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY() AOmegaQuestInstance* qInst;
	FOmegaQuestData local_data;
	
	FOmegaQuestData* L_GetQuestData();
	
	UFUNCTION(BlueprintCallable,Category="Quest") AOmegaQuestInstance* GetQuestInstance() const;
	UFUNCTION(BlueprintCallable,Category="Quest") UOmegaQuest* GetQuestAsset() const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Quest") void OnQuestStart(AOmegaQuestInstance* Instance) const;
	UFUNCTION(BlueprintNativeEvent,Category="Quest") void OnQuestEnd(AOmegaQuestInstance* Instance) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Overrides") void OnSave(AOmegaQuestInstance* Instance) const;
	UFUNCTION(BlueprintNativeEvent,Category="Overrides") void OnLoad(AOmegaQuestInstance* Instance, FOmegaQuestData data) const;
	UFUNCTION(BlueprintNativeEvent,Category="Overrides") void OnEndPlay(AOmegaQuestInstance* Instance) const;
	UFUNCTION(BlueprintNativeEvent,Category="Overrides") bool CanQuestStart() const;
	UFUNCTION(BlueprintNativeEvent,Category="Quest") TArray<UObject*> GetActiveTasks(AOmegaQuestInstance* Instance) const;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaQuestInstance : public AOmegaActorBASE, public IDataInterface_General
{
	GENERATED_BODY()
public:
	AOmegaQuestInstance();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY() UOmegaQuestTypeScript* script_copy;
	UPROPERTY() AOmegaWorldManager* WM;
	UPROPERTY() UObject* questContext;
	UPROPERTY(VisibleAnywhere,Category="Quest") UOmegaQuest* QuestAsset;
	bool b_ended=false;
	
	void StartQuest(bool bResumeFormSave);
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Quest") void TriggerQuestUpdate();
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Quest") void StopQuest(bool bFailed);
	
	UFUNCTION(BlueprintPure,Category="Quest") TArray<UObject*> GetActiveTasks();

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};
