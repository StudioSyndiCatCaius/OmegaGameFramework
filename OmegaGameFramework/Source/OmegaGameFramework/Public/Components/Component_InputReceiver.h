// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedActionKeyMapping.h"
#include "Components/ActorComponent.h"
#include "Misc/GeneralDataObject.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "Interfaces/I_Common.h"
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputReceiverDelegate,FVector,Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInputReceiverTrigger, float, DeltaTime,FVector,Value);


UCLASS( ClassGroup=("Input"), meta=(BlueprintSpawnableComponent), DisplayName="Local Input Component" )
class OMEGAGAMEFRAMEWORK_API UInputReceiverComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY() float cached_dt;
	UPROPERTY() APlayerController* CachedPlayerController;
	UPROPERTY() AActor* ContextOwner;
	
	bool bIsInputActive;
	FVector cached_InputValue;
	
	APlayerController* GetContextPlayer();
	bool CheckKeysPressed() const;
	bool CheckPrerequisiteKeys() const;
	
	TMap<FKey,FVector> GetKeyValues() const;
	TArray<FKey> GetKeys() const;
	FVector GetKey_InputValue(FKey Key);
	
	UFUNCTION()
	TArray<FName> L_GetInputNames() const;
	
public:	
	UInputReceiverComponent();
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, DisplayName="Input Start") FOnInputReceiverDelegate OnInputStarted;
	UPROPERTY(BlueprintAssignable, DisplayName="Input Update") FOnInputReceiverTrigger OnInputTriggered;
	UPROPERTY(BlueprintAssignable, DisplayName="Input End") FOnInputReceiverDelegate OnInputCompleted;
	
	// At least ONE of these keys must be pressed to trigger input
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Input",meta=(GetOptions="L_GetInputNames"))
	FName InputPresetToUse;
	
	// At least ONE of these keys must be pressed to trigger input
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Input")
	TMap<FKey,FVector> Keys;

	// ALL of these keys must be held down for input to trigger (e.g., modifier keys like Ctrl, Shift)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Input")
	TArray<FKey> PrerequisiteKeys;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Input")
    float CooldownTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Input")
	bool bStartInCooldown;
	
	float f_cooldownTime;
	bool IsInputInCooldown() const;
	
	UFUNCTION(BlueprintCallable, Category="Input")
	void OverrideInputOwner(AActor* NewOwner);

	UFUNCTION(Category="Input")
	FInputActionValue GetInputActionValue();

	UPROPERTY() APlayerController* REF_OwningController;
	
	
	UPROPERTY(EditAnywhere, Category="Input", DisplayName="Input Action")
	UInputAction* InputAction;
	
	UPROPERTY() TArray<FEnhancedActionKeyMapping> KeyMappings;
	UPROPERTY() class UEnhancedInputComponent* OwnerInputComp;
	

	UFUNCTION() void Native_Started();
	UFUNCTION() void Native_Triggered();
	UFUNCTION() void Native_Complete();
	UFUNCTION() void Native_Cancel();
	UFUNCTION() void Native_Ongoing();

	
	UFUNCTION()
	void OnOwningControllerChange(APawn* Pawn, AController* OldController, AController* NewController);

	UFUNCTION(BlueprintCallable, Category="Input")
	void BindToPawn(APawn* Pawn);
	
	
	
};

