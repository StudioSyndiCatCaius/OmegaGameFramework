// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"

#include "ListenFor_DataWidget.generated.h"

class UDataWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FListenDataWidgetDelegate, UDataWidget*, Widget, UListenFor_DataWidget*, Task );


UCLASS()
class OMEGAFLOW_API UListenFor_DataWidget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable, Category="Omega") FListenDataWidgetDelegate Selected;
	UPROPERTY(BlueprintAssignable, Category="Omega") FListenDataWidgetDelegate Hover;
	UPROPERTY(BlueprintAssignable, Category="Omega") FListenDataWidgetDelegate Unhover;
	UPROPERTY() const APlayerController* local_player;

	UFUNCTION()
	void OnEvent(UDataWidget* Widget, uint8 Event);
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable,Category="Task")
	void KillTask();
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Data Widget") 
	static UListenFor_DataWidget* ListenFor_DataWidget(const APlayerController* Player);
	
};
