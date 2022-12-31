// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widget/DataWidget.h"
#include "Widget/WidgetInterface_Input.h"
#include "Blueprint/UserWidget.h"
#include "MasterDataList.generated.h"


UCLASS(EditInlineNew, Const, BlueprintType)
class OMEGAUI_API UDataListType : public UObject
{
	GENERATED_BODY()

public:
	void Native_CreateListWidget();
	
};

UCLASS()
class OMEGAUI_API UMasterDataList : public UUserWidget, public IWidgetInterface_Input
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="List")
	UDataListType* ListType;
	
	UPROPERTY(EditAnywhere, Category="Entry")
	TSubclassOf<UDataWidget> EntryClass;

	UPROPERTY(EditAnywhere, Category="Entry")
	TArray<UObject*> DefaultEntries;
};