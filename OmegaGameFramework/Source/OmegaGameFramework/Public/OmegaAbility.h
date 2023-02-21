// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "Gameplay/CombatantComponent.h"

#include "Input/InputReceiverComponent.h"
#include "Widget/HUDLayer.h"

#include "OmegaAbility.generated.h"



// Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEnd, bool, bCancelled);

// Forward Declarations

class ACharacter;
class UCharacterMovementComponent;
class UEnhancedInputComponent;
class UHUDLayer;
class UTimelineComponent;
class UOmegaGameManager;

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
	UFUNCTION()
	virtual void Native_AbilityActivated(class UObject* Context);
	UFUNCTION()
	virtual void Native_AbilityFinished(bool Cancelled);
	UFUNCTION()
	virtual void Native_ActivatedTick(float DeltaTime);
	UFUNCTION()
	virtual bool Native_CanActivate(UObject* Context);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category="Ω|Ability")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, DisplayName="Activate", Category="Ω|Ability")
	void Execute(UObject* Context);

	UFUNCTION()
	void Native_Execute();

	UFUNCTION()
	void Native_InputTrigger();
	
	//**Start & End***//
	UFUNCTION(BlueprintImplementableEvent)
	void AbilityActivated(class UObject* Context);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void AbilityFinished(bool Cancelled);
	
	UFUNCTION(BlueprintImplementableEvent)
	void ActivatedTick(float DeltaTime);
	
	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
	bool CanActivate(const UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category="Ability")
	bool SetInputEnabledForOwner(bool Enabled);

	//**Callable***//
	//Completes and Destroys this Ability.
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CompleteAbility();

	//Cancels and Destroys this Ability.
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CancelAbility();

	//-###########################################################################################################-//
	//---- OWNER GETS
	//-###########################################################################################################-//
	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class ACharacter* GetAbilityOwnerCharacter();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	APlayerController* GetAbilityOwnerPlayer();
	
	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class UCharacterMovementComponent* GetAbilityOwnerCharacterMoveComponent();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class USkeletalMeshComponent* GetAbilityOwnerMesh();


	///TAGS///
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability|Tags")
	void AddBlockedAbilityTags(FGameplayTagContainer AddedTags);

	UFUNCTION(BlueprintCallable, Category = "Ω|Ability|Tags")
	void RemoveBlockedAbilityTags(FGameplayTagContainer RemovedTags);

	//-###########################################################################################################-//
	//---- INPUT
	//-###########################################################################################################-//
	UPROPERTY(VisibleAnywhere, Category="Input")
	class UInputReceiverComponent* DefaultInputReceiver;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	bool bEnableInputOnActivation;

protected:
	UFUNCTION()
	void Local_SetInputEnabled(bool Enabled)
	{
		if(GetAbilityOwnerPlayer())
		{
			if(Enabled)
			{
				EnableInput(GetAbilityOwnerPlayer());
			}
			else
			{
				DisableInput(GetAbilityOwnerPlayer());
			}
		}
	}

public:
	//FlipFlops the input
	UPROPERTY(EditDefaultsOnly, Category = "Input", DisplayName="Toggle Active on Input")
	bool FlipFlopInput;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bActivateOnStarted;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bActivateOnTriggered;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bFinishOnInputComplete;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	bool bFinishOnInputCancel;

	//-----------------------//
	// Cooldown
	//----------------------//
	UFUNCTION(BlueprintImplementableEvent, Category="Cooldown")
	float GetCooldownTime();

	UFUNCTION(BlueprintPure, Category="Cooldown")
	bool IsAbilityInCooldown() const;

	UFUNCTION(BlueprintPure, Category="Cooldown")
	void GetRemainingCooldownValues(float& Normalized, float& Seconds);
	
	UPROPERTY()
	float CooldownLerp;

	UPROPERTY(EditDefaultsOnly, Category="Cooldown")
	bool BeginInCooldown;
	
//### Properties ###//
// 

	//### HUD ###//
	UPROPERTY(EditDefaultsOnly, Category="HUD")
	TSubclassOf<UHUDLayer> HudClass = UHUDLayer::StaticClass();
	
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

	//-###########################################################################################################-//
	//---- Gameplay Tags
	//-###########################################################################################################-//
	
	//Tags assosiated with this ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer AbilityTags;

	//Cancel any of the owner's active abilities with any of these tags.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayTags")
	struct FGameplayTagContainer CancelAbilities;

	//Cancels and Prevent any abilites with any of these tags from being activated by the owner until this ability finishes.
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

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	UTimelineComponent* GetAbilityActivationTimeline();
	
	//NAME Tags given to the owning actor upon ability GRANTED and removed upon Ability UNGRANTED
	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TArray<FName> GrantedActorOwnerTags;
	//NAME Tags given to the owning actor upon ability Activation and removed upon Ability Finish
	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TArray<FName> ActiveActorOwnerTags;

	void Private_SetSoftTagsOnActor(TArray<FName> TagList, bool Active)
	{
		for(FName TempTag : TagList)
		{
			if(Active)
			{
				CombatantOwner->GetOwner()->Tags.Add(TempTag);
			}
			else
			{
				int32 TempIndex = CombatantOwner->GetOwner()->Tags.Find(TempTag);
				CombatantOwner->GetOwner()->Tags.RemoveAt(TempIndex);
			}
		}
	}
private:

	UFUNCTION()
	void RecieveFinish(bool bCancel);

public:

	//---------------------------------------------------------------------------------------------------------------//
	// NOTIFY //
	//---------------------------------------------------------------------------------------------------------------//

	UFUNCTION(BlueprintImplementableEvent)
	void OnCombatantNotify(UCombatantComponent* OwningCombatant, FName Notify, const FString& Flag);

	//---------------------------------------------------------------------------------------------------------------//
	// Combatant Owner Overrides //
	//---------------------------------------------------------------------------------------------------------------//

	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	void OnActiveTargetChanged(UCombatantComponent* ActiveTarget, bool Valid);
	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	void OnRegisteredTarget(UCombatantComponent* Target);
	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	void OnUnregisteredTarget(UCombatantComponent* Target);
/*
	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	void OnDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, UObject* Instigator);
*/	

	//-###########################################################################################################-//
	//---- EVENTS
	//-###########################################################################################################-//
	void Local_TriggerEvents(TArray<FName> Events);

	UPROPERTY(EditDefaultsOnly, Category="GlobalEvents")
	TArray<FName> EventsOnActivate;
	UPROPERTY(EditDefaultsOnly, Category="GlobalEvents")
	TArray<FName> EventsOnFinish;
	UPROPERTY(EditDefaultsOnly, Category="GlobalEvents")
	TArray<FName> EventsOnComplete;
	UPROPERTY(EditDefaultsOnly, Category="GlobalEvents")
	TArray<FName> EventsOnCancel;
};
