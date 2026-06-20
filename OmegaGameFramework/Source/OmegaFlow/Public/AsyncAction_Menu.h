// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Widget/Menu.h"
#include "AsyncAction_Menu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMenuClosed, FGameplayTagContainer, CloseTags, UObject*, CloseContext, FString, CloseFlag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMenuFailed);

USTRUCT(BlueprintType)
struct FOmegaAsyncSubmenuConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega") UMenu* ParentMenu=nullptr;
	//Offsets the new menus input priority based on the parent menu. if no parent just set directly
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega") int32 OffsetPriorityFromParent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega") int32 ParentSubstate_OnOpen=1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega") int32 ParentSubstate_OnClose=0;
	
};

UCLASS()
class OMEGAFLOW_API UAsyncAction_Menu : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnMenuClosed Closed;
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnMenuFailed Failed;
	
	UPROPERTY() APlayerController* PlayerRef;
	UPROPERTY() TSubclassOf<UMenu> MenuRef;
	UPROPERTY() FString FlagRef;
	UPROPERTY() UObject* ContextRef;
	UPROPERTY() FGameplayTagContainer TagsRef;
	UPROPERTY() FOmegaCommonMeta in_meta;
	UPROPERTY() FOmegaAsyncSubmenuConfig SubmenuMetaRef;

	UFUNCTION()
	void NativeShutdown(FGameplayTagContainer CloseTags, UObject* Context, const FString OutFlag);
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly, WorldContext="WorldContextObject", AdvancedDisplay="Player, OpenTags, OpenFlag"), Category="Omega|AsyncGameplayTasks"
		,DisplayName="Ω🔷 Open Menu")
	static UAsyncAction_Menu* OpenMenu(UObject* WorldContextObject, APlayerController* Player, const TSubclassOf<UMenu> MenuClass, UObject* Context, const FGameplayTagContainer OpenTags, const FString& OpenFlag,
		FOmegaCommonMeta meta,FOmegaAsyncSubmenuConfig SubmenuConfig);

	
};
