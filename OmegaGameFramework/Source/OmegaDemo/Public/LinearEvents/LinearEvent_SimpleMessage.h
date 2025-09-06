// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Event/OmegaLinearEvent.h"
#include "Functions/OmegaFunctions_SoftProperty.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "Styling/SlateBrush.h"
#include "Subsystems/OmegaSubsystem_Message.h"
#include "UObject/Object.h"
#include "LinearEvent_SimpleMessage.generated.h"

class UOmegaSelector_LevelSequence;
class UOmegaSelector_Montage;
class UOmegaMessageTrait;
class UOmegaDataItem;


// Fires the GlobalEvent "Message_Start" with this event as the context. Uses GetGeneralDataTexts to get event text. Finishes on GlobalEvent "Message_End";
UCLASS(DisplayName="(Event) Simple Message")
class OMEGADEMO_API ULinearEvent_SimpleMessage : public UOmegaLinearEvent, public IDataInterface_General
{
	GENERATED_BODY()
	FOmegaGameplayMessageData msg;
	UObject* local_GetInstigator() const;
	
public:
	virtual FString GetLogString_Implementation() const override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(ExposeOnSpawn="true"),DisplayName="Instigator (Asset)")
	UPrimaryDataAsset* Instigator_Asset;
	UPROPERTY(Instanced, EditInstanceOnly, BlueprintReadOnly, Category="Event",DisplayName="Instigator (Actor)")
	UOmegaSelector_Object* Instigator_Alt;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(MultiLine, ExposeOnSpawn="true"))
	FText Text;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message", meta=(ExposeOnSpawn="true"))
	FOmegaGameplayMessageMeta meta;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTag MessageCategory  = FGameplayTag::RequestGameplayTag(FName("Message.Dialog"));

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void Native_Begin(const FString& Flag) override;

	UFUNCTION() void LocalGEvent(FName Event, UObject* Context);
};

UCLASS(DisplayName="Simple Message")
class OMEGADEMO_API UFlowNode_SimpleMessage : public UFlowNode, public IDataInterface_General, public IOmegaSoftPropertyInterface
{
	GENERATED_BODY()

	UObject* local_GetInstigator() const;
	UFUNCTION() void LocalGEvent(FName Event, UObject* Context);
public:
	UFlowNode_SimpleMessage();

	virtual void ExecuteInput(const FName& PinName) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual  TMap<FName, FString> GetSoftPropertyMap_Implementation() override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override { OutColor=FLinearColor::Yellow; return true; };
#endif
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Message", meta=(ExposeOnSpawn="true",DisallowCreateNew), DisplayName="Instigator")
	UPrimaryDataAsset* Instigator_Asset;
	UPROPERTY(Instanced, EditInstanceOnly, BlueprintReadOnly,AdvancedDisplay, Category="Message",DisplayName="Instigator (Alt)")
	UOmegaSelector_Object* Instigator_Alt;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Message",meta=(MultiLine))
	FText Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Message")
	FGameplayTagContainer Tags;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Message")
	UMaterialInterface* Portrait=nullptr;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Message")
	float FinishDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Message")
	TMap<FName,FString> ExtraParams;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Message",AdvancedDisplay="AdvancedDisplay")
	FGameplayTag MessageCategory  = FGameplayTag::RequestGameplayTag(FName("Message.Dialog"));
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Message",AdvancedDisplay)
	FName MessageKey;
	
	UPROPERTY(EditInstanceOnly,Instanced,BlueprintReadWrite, Category="Animation")
	UOmegaSelector_Montage* Montage;
	UPROPERTY(EditInstanceOnly,Instanced,BlueprintReadWrite, Category="Animation")
	UOmegaSelector_LevelSequence* Sequence;
	
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Animation")
	TSoftObjectPtr<UOAsset_TransformPreset> Position;
	
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor")
	void Autokey_ByNext();
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor")
	void Autokey_ByPosition();
	//UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor")
	//void Import();
	
	UFUNCTION()
	void LocalFinish(UOmegaLinearEvent* Event, const FString& Flag);
};
