// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

};

UCLASS(EditInlineNew,Blueprintable,BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaQuestManagerScript : public UObject
{
	GENERATED_BODY()

	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	UOmegaQuestManagerScript(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;

	UPROPERTY()
	UOmegaQuestComponent* OwnerComp=nullptr;
	UPROPERTY()
	UOmegaSaveSubsystem* SaveSubsystem;

	UFUNCTION(BlueprintPure,Category="Quest")
	UOmegaQuestComponent* GetOwningComponent() const {return OwnerComp; }

	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	bool QuestLoaded(const FString& state_ID);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="Quest")
	FString GetQuestID() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	bool Try_StartQuest(UObject* Context);

	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	bool Try_EndQuest(bool bComplete);

	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	bool IsQuest_Active();

	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	bool IsQuest_Finished();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	UObject* Try_GetStateObject();
		
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	FString Try_GetStateID();

private:
	
};

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaQuestComponent : public UActorComponent
{
	GENERATED_BODY()
	//UOmegaQuestComponent();
	UPROPERTY()
	UOmegaSaveSubsystem* SaveSubsystem;

	UPROPERTY()
	UObject* QuestContext=nullptr;
	
public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable,Category="Omega|Quest")
	void SetQuestContext(UObject* Context)
	{
		if(Context)
		{
			QuestContext=Context;
		}
	}

	UFUNCTION(BlueprintPure,Category="Omega|Quest")
	UObject* GetQuestContext() const {return QuestContext;}
	
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite,Category="Quest")
	UOmegaQuestManagerScript* QuestManagerScript;
	
	UFUNCTION(BlueprintCallable,Category="Quest")
	bool StartQuest(UObject* Context);

	UFUNCTION(BlueprintCallable,Category="Quest")
	bool EndQuest(bool bComplete);
	
	UFUNCTION(BlueprintPure,Category="Quest")
	bool IsQuestActive();

	UFUNCTION(BlueprintPure,Category="Quest")
	bool IsQuestComplete();

	UFUNCTION(BlueprintPure,Category="Quest")
	UObject* GetState();
	/*
	UFUNCTION(BlueprintPure,Category="Quest")
	TArray<UObject*> GetState_Objectives();
	*/
	UFUNCTION(BlueprintPure,Category="Quest")
	FString GetState_ID();

	UFUNCTION(BlueprintCallable,Category="Quest",meta=(AdvancedDisplay="NewQuestContext"))
	void AttemptLoadState(UObject* NewQuestContext);

};

