// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "Input/InputReceiverComponent.h"

#include "OmegaAbility.generated.h"
//
// 
// Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEnd, bool, bCancelled);

// Forward Declarations
class UCombatantComponent;
class ACharacter;
class UCharacterMovementComponent;
class UEnhancedInputComponent;

UENUM()
enum class EAbilityActivateInput
{
	/** Description. */
	AbilityActivateOn_Started            UMETA(DisplayName = "Started"),
	/** Description. */
	AbilityActivateOn_Triggered             UMETA(DisplayName = "Triggered"),
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOmegaAbility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void TryAssignControlInput(APawn* Pawn, AController* Controller);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category="Ω|Ability")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, DisplayName="Activate", Category="Ω|Ability")
	void Execute(UObject* Context);

	UFUNCTION()
	void Native_Execute();

	UFUNCTION()
	void Native_Trigger();
	
	//**Start & End***//
	UFUNCTION(BlueprintImplementableEvent)
	void AbilityActivated(class UObject* Context);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void AbilityFinished(bool Cancelled);

	UFUNCTION(BlueprintImplementableEvent)
	void ActivatedTick(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
	bool CanActivate();
	
	UFUNCTION(BlueprintCallable, Category="Ability")
	bool SetInputEnabledForOwner(bool Enabled);

	//**Callable***//
	//Completes and Destroys this Ability.
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CompleteAbility();

	//Cancels and Destroys this Ability.
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CancelAbility();

	//Owner Gets//
	
	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class ACharacter* GetAbilityOwnerCharacter();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class UCharacterMovementComponent* GetAbilityOwnerCharacterMoveComponent();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class USkeletalMeshComponent* GetAbilityOwnerMesh();


	///TAGS///
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability|Tags")
	void AddBlockedAbilityTags(FGameplayTagContainer AddedTags);

	UFUNCTION(BlueprintCallable, Category = "Ω|Ability|Tags")
	void RemoveBlockedAbilityTags(FGameplayTagContainer RemovedTags);

	//### Input ###//
	UPROPERTY(VisibleAnywhere, Category="Input")
	class UInputReceiverComponent* DefaultInputReceiver;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bActivateOnStarted;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bActivateOnTriggered;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bFinishOnInputComplete;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bFinishOnInputCancel;

//### Properties ###//
// 

	UPROPERTY()
	bool bIsKilling;
	//Context Object//
	UPROPERTY(BlueprintReadOnly, DisplayName="Ability Context", meta = (ExposeOnSpawn = "true"), Category = "Ability")
	UObject* ContextObject = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Owner")
	class UCombatantComponent* CombatantOwner;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityEnd OnAbilityFinished;

	//Only one instance of this ability is allowed to run on this Owner at a time.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
		bool Singleton;

	//GameplayTags//
	//Tags assosiated with this ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer AbilityTags;

	//Cancel any of the owner's active abilities with any of these tags.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer CancelAbilities;

	//Prevent any abilites with any of these tags from being activated by the owner until this ability finishes.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer BlockAbilities;

	//The Owner Must have these gameplay tags for this ability to activate.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer RequiredOwnerTags;

	//The Owner must NOT have ANY of these gameplay tags in order for this ability to activate.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer RestrictedOwnerTags;

	class ACharacter* CachedCharacter;
	class UPawnMovementComponent* TempMoveComp;

private:

	UFUNCTION()
	void RecieveFinish(bool bCancel);
};
