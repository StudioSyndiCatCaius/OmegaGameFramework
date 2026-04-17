// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaCode.h"
#include "Interfaces/I_Common.h"
#include "Event/OmegaLinearEvent.h"
#include "Functions/F_SoftProperty.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "Styling/SlateBrush.h"
#include "Subsystems/Subsystem_World.h"
#include "UObject/Object.h"
#include "LinearEvent_SimpleMessage.generated.h"

class UOmegaSelector_LevelSequence;
class UOmegaSelector_Montage;
class UOmegaMessageTrait;
class UOmegaDataItem;

class UOAsset_TransformPreset;

// Fires the GlobalEvent "Message_Start" with this event as the context. Uses GetGeneralDataTexts to get event text. Finishes on GlobalEvent "Message_End";
UCLASS(DisplayName="(Event) Simple Message")
class OMEGADEMO_API ULinearEvent_SimpleMessage : public UOmegaLinearEvent, public IDataInterface_General
{
	GENERATED_BODY()
	UObject* local_GetInstigator() const;
	UFUNCTION() void Native_MessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	
public:
	virtual FString GetLogString_Implementation() const override;
	UPROPERTY() UOmegaGameplayMessage* msg;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(ExposeOnSpawn="true"),DisplayName="Instigator (Asset)")
	UPrimaryDataAsset* Instigator_Asset;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(MultiLine, ExposeOnSpawn="true"))
	FText Text;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message", meta=(ExposeOnSpawn="true"))
	FOmegaGameplayMessageMeta meta;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTag Message_Category  = FGameplayTag::RequestGameplayTag(FName("Message.Dialog"));
	
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override
	{
		Description = Text;
	};
	virtual void Native_Begin(const FString& Flag) override;
};

UCLASS(DisplayName="💬 Message")
class OMEGADEMO_API UFlowNode_SimpleMessage : public UFlowNode, public IOmegaSoftPropertyInterface, public IDataInterface_MessageContext
{
	GENERATED_BODY()

	bool CanPlayMessage();
	void getNodeIndexFromList(TArray<UFlowNode*> baseList);
	
	AActor* local_GetInstigatorActor() const;
	UObject* local_GetInstigator() const;
public:
	UFlowNode_SimpleMessage();

	virtual void ExecuteInput(const FName& PinName) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual  TMap<FName, FString> GetSoftPropertyMap_Implementation() override;

#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual FString GetNodeDescription() const override;
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override;
#endif
	virtual FSlateBrush K2_GetNodeIcon_Implementation() const override;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node", meta=(ExposeOnSpawn="true",DisallowCreateNew), DisplayName="🗣️Instigator")
	UPrimaryDataAsset* Instigator_Asset;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node",meta=(MultiLine),DisplayName="💬Text")
	FText Text;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	FGameplayTagContainer Tags;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node")
	UMaterialInterface* Portrait=nullptr;

	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node",AdvancedDisplay)
	FName MessageKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node",AdvancedDisplay)
	TMap<FName,FString> ExtraParams;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node",AdvancedDisplay,DisplayName="🗒️Direction Notes") FString Direction;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Lua",meta=(MultiLine))
	FOmegaLuaCode LuaScript;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Lua",meta=(MultiLine))
	FOmegaLuaCode LuaCondition;
	
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Actor")
	UAnimMontage* Montage;
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Actor")
	ULevelSequence* Sequence;
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Actor")
	UOAsset_TransformPreset* Position;
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Actor",DisplayName="Target")
	UPrimaryDataAsset* LookAt;
	
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Look Aim")
	TArray<UPrimaryDataAsset*> Listeners;
	UPROPERTY(EditInstanceOnly,Instanced,BlueprintReadWrite, Category="Look Aim")
	UOmegaActorSelector* LookAt_Alt;
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Look Aim")
	bool ClearLookAt;

	UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor")
	void Autokey_ByNext();
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor")
	void Autokey_ByPosition();
	//UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor")
	//void Import();
	
	UFUNCTION()
	void LocalFinish(UOmegaLinearEvent* Event, const FString& Flag);

	virtual UOAsset_TransformPreset* GetMessage_TransformPreset_Implementation() override;
};
