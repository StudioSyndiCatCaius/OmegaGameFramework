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


UCLASS(Blueprintable,BlueprintType,EditInlineNew, Abstract, Const)
class OMEGAGAMEFRAMEWORK_API UOmegaInputActionScript : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Input")
	bool IsInputActive(const APlayerController* Controller) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Input")
	FVector GetAxisValue(const APlayerController* Controller) const;
};



UCLASS(EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaInputAction : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
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

	UFUNCTION(BlueprintPure, Category="InputAction")
	bool IsInputActive(APlayerController* Controller) const;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly,Category="Input")
	UOmegaInputActionScript* Script;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputTrigger, float, DeltaTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputCancel);

UCLASS( ClassGroup=("Input"), meta=(BlueprintSpawnableComponent), DisplayName="Local Input Component" )
class OMEGAGAMEFRAMEWORK_API UInputReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

	bool local_isInputDown();
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

	UPROPERTY(EditAnywhere, Category="Input", DisplayName="Input Action")
	UOmegaInputAction* OmegaInputAction;
	UPROPERTY(EditAnywhere, Instanced, Category="Input", DisplayName="Input Action (Custom)")
	UOmegaInputAction* OmegaInputAction_Custom;

	UFUNCTION(BlueprintCallable,Category="Input")
	UOmegaInputAction* GetInputAction() const
	{
		if(OmegaInputAction_Custom) { return OmegaInputAction_Custom; }
		if(OmegaInputAction) { return OmegaInputAction; }
		return nullptr;
	}
	
	UPROPERTY(EditAnywhere, Category="Input", AdvancedDisplay, DisplayName="UE Input Action (Depc)")
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

