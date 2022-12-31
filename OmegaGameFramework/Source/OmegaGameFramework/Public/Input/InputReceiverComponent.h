// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedActionKeyMapping.h"
#include "Components/ActorComponent.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputReceiverComponent.generated.h"

class APlayerController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputTrigger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputCancel);


UCLASS( ClassGroup=("Input"), meta=(BlueprintSpawnableComponent), DisplayName="Local Input Component" )
class OMEGAGAMEFRAMEWORK_API UInputReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputReceiverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable, Category="Input")
	void OverrideInputOwner(AActor* NewOwner);

	UFUNCTION(Category="Input")
	FInputActionValue GetInputActionValue();
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	class UInputAction* InputAction;
	
	UPROPERTY()
	TArray<FEnhancedActionKeyMapping> KeyMappings;
	
	UPROPERTY()
	class UEnhancedInputComponent* OwnerInputComp;
	

	UFUNCTION()
	void Native_Started();
	UFUNCTION()
	void Native_Triggered();
	UFUNCTION()
	void Native_Complete();
	UFUNCTION()
	void Native_Cancel();
	UFUNCTION()
	void Native_Ongoing();

	UPROPERTY(BlueprintAssignable)
	FOnInputStart OnInputStarted;
	UPROPERTY(BlueprintAssignable)
	FOnInputTrigger OnInputTriggered;
	UPROPERTY(BlueprintAssignable)
	FOnInputComplete OnInputCompleted;
	UPROPERTY(BlueprintAssignable)
	FOnInputCancel OnInputCancel;

	UFUNCTION()
	void OnOwningControllerChange(APawn* Pawn, AController* OldController, AController* NewController);
	
};

