// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "UObject/Object.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "OmegaSubsystem_Quest.generated.h"

UENUM(Blueprintable)
enum EOmegaQuestStatus
{
	Unstarted		UMETA(DisplayName = "Unstarted"),
	Active			UMETA(DisplayName = "Active"),
	Complete		UMETA(DisplayName = "Complete"),
	Failed			UMETA(DisplayName = "Failed"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOmegaQuestStart, UOmegaQuestComponent* ,Component, UOmegaQuest*, Quest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOmegaQuestEnd, UOmegaQuestComponent* ,Component, UOmegaQuest*, Quest);

UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract,Const,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaQuestTypeScript : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY() UOmegaQuestComponent* REF_Comp=nullptr;
	
	UFUNCTION(BlueprintCallable,Category="Quest")
	UOmegaQuestComponent* GetQuestComponent() const { return REF_Comp; };
	UFUNCTION(BlueprintCallable,Category="Quest")
	UOmegaQuest* GetQuestAsset() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	void OnQuestStart(UOmegaQuestComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	void OnQuestEnd(UOmegaQuestComponent* Component) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Overrides")
	FJsonObjectWrapper OnSave(UOmegaQuestComponent* Component, FJsonObjectWrapper Data) const;
	UFUNCTION(BlueprintNativeEvent,Category="Overrides")
	void OnLoad(UOmegaQuestComponent* Component, FJsonObjectWrapper Data) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Overrides")
	bool CanQuestStart() const;

	UFUNCTION(BlueprintNativeEvent,Category="Overrides")
	bool IsActive() const;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Overrides")
	void SetActive(bool bActive) const;
	UFUNCTION(BlueprintNativeEvent,Category="Overrides")
	bool IsComplete() const;
	UFUNCTION(BlueprintCallable,Category="Overrides")
	void EndQuest(bool bComplete) const;
	UFUNCTION(BlueprintNativeEvent,Category="Overrides")
	void SetComplete(bool bComplete) const;

	//Tasks
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	TArray<UObject*> GetActiveTasks(UOmegaQuestComponent* Component) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaQuest : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",meta=(MultiLine),DisplayName="Icon") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",meta=(MultiLine),DisplayName="Description") FText DisplayDescription;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FString CustomLabel;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTagContainer GameplayTags;
	OMACRO_ADDPARAMS_GENERAL()
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Quest")
	UOmegaQuestTypeScript* QuestScript;
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	TArray<UOmegaQuestComponent*> REF_QuestComps;
public:

	UFUNCTION()
	void local_RegisterQuestComponent(UOmegaQuestComponent* comp, bool comp_registered);
	
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestStart OnQuestStart;
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestEnd OnQuestEnd;

	UFUNCTION(BlueprintCallable,Category="OmegaQuestSubsystem",DisplayName="Get Quest (First w/ Asset)")
	UOmegaQuestComponent* GetQuest_FirstWithAsset(UOmegaQuest* Quest);
	
	UFUNCTION(BlueprintCallable,Category="OmegaQuestSubsystem",DisplayName="Start Quest (First w/ Asset)")
	bool StartQuest_FirstWithAsst(UOmegaQuest* Quest);

	UFUNCTION(BlueprintCallable,Category="OmegaQuestSubsystem")
	TArray<UOmegaQuestComponent*> GetQuests_Active();

	UFUNCTION(BlueprintCallable,Category="OmegaQuestSubsystem")
	TArray<UOmegaQuestComponent*> GetQuests_Complete();
};




UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaQuestComponent : public UActorComponent
{
	GENERATED_BODY()
	//UOmegaQuestComponent();
	UPROPERTY()
	UOmegaSaveSubsystem* SaveSubsystem;

	UPROPERTY()
	UObject* QuestContextObject=nullptr;
	
public:
	UPROPERTY(EditAnywhere,Category="Quest")
	bool bAutoLoadFromSaveJson;
	UFUNCTION(BlueprintCallable,Category="Quest")
	void TryLoadFromJsonSave();
	UFUNCTION(BlueprintCallable,Category="Quest")
	void TrySaveToJsonSave();
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(EditAnywhere,Category="Quest")
	UOmegaQuest* QuestAsset=nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Quest")
	FJsonObjectWrapper JsonSaveData;
	
	UFUNCTION(BlueprintCallable,Category="Omega|Quest")
	void SetQuestAsset(UOmegaQuest* Quest);

	UFUNCTION(BlueprintPure,Category="Omega|Quest")
	UOmegaQuest* GetQuestAsset() const {return QuestAsset;}
	
	UFUNCTION(BlueprintCallable,Category="Quest",meta=(AdvancedDisplay="Quest"))
	bool StartQuest(UOmegaQuest* Quest);

	UFUNCTION(BlueprintCallable,Category="Quest")
	bool EndQuest(bool bComplete);
	
	UFUNCTION(BlueprintPure,Category="Quest")
	bool IsQuestActive();

	UFUNCTION(BlueprintPure,Category="Quest")
	bool IsQuestComplete();

	// ======== TASKS =====
	UFUNCTION(BlueprintCallable,Category="Quest")
	TArray<UObject*> GetActiveQuestTasks();

	
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestStart OnQuestStart;
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestEnd OnQuestEnd;

};

