// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedActionKeyMapping.h"
#include "Components/ActorComponent.h"
#include "Misc/GeneralDataObject.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Component_InputReceiver.generated.h"

class APlayerController;




UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaInputAction : public UInputAction, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",meta=(MultiLine)) FText DisplayDescription;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTagContainer GameplayTags;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override { return CategoryTag; };
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return GameplayTags; };
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputTrigger, float, DeltaTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputCancel);

UCLASS( ClassGroup=("Input"), meta=(BlueprintSpawnableComponent), DisplayName="Local Input Component" )
class OMEGAGAMEFRAMEWORK_API UInputReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

	
	UPROPERTY() float cached_dt;

public:	
	// Sets default values for this component's properties
	UInputReceiverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:	

	UFUNCTION(BlueprintCallable, Category="Input")
	void OverrideInputOwner(AActor* NewOwner);

	UFUNCTION(Category="Input")
	FInputActionValue GetInputActionValue();

	UPROPERTY() APlayerController* REF_OwningController;
	
	
	UPROPERTY(EditAnywhere, Category="Input", DisplayName="UE Input Action (Depc)")
	UInputAction* InputAction;
	
	UPROPERTY() TArray<FEnhancedActionKeyMapping> KeyMappings;
	UPROPERTY() class UEnhancedInputComponent* OwnerInputComp;

	UPROPERTY() bool bIsInputActive;

	UFUNCTION() void Native_Started();
	UFUNCTION() void Native_Triggered();
	UFUNCTION() void Native_Complete();
	UFUNCTION() void Native_Cancel();
	UFUNCTION() void Native_Ongoing();

	UPROPERTY(BlueprintAssignable, DisplayName="Input Start") FOnInputStart OnInputStarted;
	UPROPERTY(BlueprintAssignable, DisplayName="Input Update") FOnInputTrigger OnInputTriggered;
	UPROPERTY(BlueprintAssignable, DisplayName="Input End") FOnInputComplete OnInputCompleted;
	UPROPERTY(BlueprintAssignable) FOnInputCancel OnInputCancel;

	UFUNCTION()
	void OnOwningControllerChange(APawn* Pawn, AController* OldController, AController* NewController);

	UFUNCTION(BlueprintCallable, Category="Input")
	void BindToPawn(APawn* Pawn);
	
};

