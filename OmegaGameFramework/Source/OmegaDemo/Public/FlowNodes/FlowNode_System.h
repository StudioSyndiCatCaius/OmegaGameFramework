// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDemo_Const.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Functions/F_Component.h"
#include "Selectors/Selector_Object.h"
#include "Nodes/FlowNode.h"
#include "Widget/Menu.h"
#include "FlowNode_System.generated.h"

class AOmegaQuestInstance;
class UOmegaEncounter_Asset;
class UOmegaQuestComponent;

UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_SystemClassBASE : public UFlowNode
{
	GENERATED_BODY()
	
public:
	
	virtual UObject* L_GetContext() const { return nullptr;};
	virtual FString L_GetFlag() const;
	virtual TSubclassOf<UObject> L_GetFlagClass() const { return nullptr;};
	virtual FOmegaCommonMeta L_GetMeta() const;
	
	UFUNCTION() virtual TArray<FString> L_GetFlags();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",meta=(GetOptions="L_GetLocalMetaList"),DisplayName="🇲Local META to use")
	FName LocalMetaToUse;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",meta=(GetOptions="L_GetFlags"),DisplayName="🚩Flag (Key)")
	FString Flag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",DisplayName="🚩Flag (Custom)")
	FString Flag_Append;
};


UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_GameplaySystemBASE : public UFlowNode_SystemClassBASE
{
	GENERATED_BODY()
	virtual TSubclassOf<AOmegaGameplaySystem> L_GetSystem() const { return nullptr;};
	UPROPERTY() AOmegaGameplaySystem* l_sys=nullptr;
	
	virtual TSubclassOf<UObject> L_GetFlagClass() const override;

public:
	UFUNCTION() virtual void L_SystemEnd(UObject* context, FString _flag);
	UFlowNode_GameplaySystemBASE();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_FLOW; return true;};
#endif
	
};


// ==============================================================================================================
// -
// ==============================================================================================================

UCLASS(DisplayName="Gameplay System",Category="Game")
class OMEGADEMO_API UFlowNode_GameplaySystem : public UFlowNode_GameplaySystemBASE
{
	GENERATED_BODY()

public:
	
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual FString GetNodeDescription() const override;
#endif
	
	virtual TSubclassOf<AOmegaGameplaySystem> L_GetSystem() const override;
	virtual UObject* L_GetContext() const override;

	UFUNCTION() TArray<FName> L_GetConstants() const;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",DisplayName="⚙️System (Constant)",meta=(GetOptions="L_GetConstants")) FName Constant;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",DisplayName="⚙️System") TSubclassOf<AOmegaGameplaySystem> System;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",DisplayName="🔷Context")
	UObject* Context;
};

UCLASS(DisplayName="⚔️System - Combat Encounter",Category="Game")
class OMEGADEMO_API UFlowNode_System_Encounter : public UFlowNode_GameplaySystemBASE
{
	GENERATED_BODY()

public:

#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual FString GetNodeDescription() const override;
#endif
	
	virtual TSubclassOf<AOmegaGameplaySystem> L_GetSystem() const override;
	virtual UObject* L_GetContext() const override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game")
	TSoftObjectPtr<UOmegaEncounter_Asset> Encounter;
};

UCLASS(DisplayName="💬System - Flow Asset",Category="Game")
class OMEGADEMO_API UFlowNode_System_DlgFlow : public UFlowNode_GameplaySystemBASE
{
	GENERATED_BODY()

	virtual void L_SystemEnd(UObject* context, FString flag) override;

public:
	
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual FString GetNodeDescription() const override;
#endif
	
	virtual TSubclassOf<AOmegaGameplaySystem> L_GetSystem() const override;
	virtual UObject* L_GetContext() const override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game")
	TSoftObjectPtr<UFlowAsset> FlowAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game")
	TSoftObjectPtr<AActor> TransitOnFinish;
};



// ==============================================================================================================
// -Menu
// ==============================================================================================================

UCLASS(DisplayName="Menu",Category="Game")
class OMEGADEMO_API UFlowNode_Menu : public UFlowNode_SystemClassBASE
{
	GENERATED_BODY()

	virtual UObject* L_GetContext() const override;
	virtual TSubclassOf<UObject> L_GetFlagClass() const override;
	TSubclassOf<UMenu> L_GetMenuClass() const;
	
	UPROPERTY() UMenu* l_menu=nullptr;
	UFUNCTION() void L_End(FGameplayTagContainer inTags, UObject* context, FString _flag);

public:
	UFlowNode_Menu();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Game"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_FLOW; return true;};
#endif
	
	UFUNCTION() TArray<FName> L_GetConstants() const;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",DisplayName="⚙️Menu (Constant)",meta=(GetOptions="L_GetConstants"))
	FName Constant;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game",DisplayName="⚙️Menu")
	TSubclassOf<UMenu> Menu;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game")
	UObject* Context;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Game")
	FGameplayTagContainer Tags;

};


// ==============================================================================================================
// -
// ==============================================================================================================

UCLASS(DisplayName="Level - Transit Check",Category="Gameplay")
class OMEGADEMO_API UFlowNode_LevelTransitCheck : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_LevelTransitCheck();

	virtual void ExecuteInput(const FName& PinName) override;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_FLOW; return true;};
#endif

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flow")
	TSoftObjectPtr<UWorld> Level;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flow")
	bool TransitIfNotOnLevel;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flow")
	FGameplayTag SpawnID;
};



UCLASS(DisplayName="Global Event - Named",Category="Await")
class OMEGADEMO_API UFlowNode_GlobalEvent_Named : public UFlowNode
{
	GENERATED_BODY()

	bool b_isAwaitingEvent;
	UFUNCTION() void L_OnGEvent(FName Event, UObject* context,FOmegaCommonMeta _meta);
	
public:
	UFlowNode_GlobalEvent_Named();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Await"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_AWAIT; return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Event") FName Event_ToSend;
	UPROPERTY(EditAnywhere,Category="Event") FName Event_ToReceive;
	
};
