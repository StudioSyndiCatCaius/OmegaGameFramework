// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Interfaces/I_StandardInput.h"
#include "Actor_Ability.generated.h"

class UEquipmentSlot;
class UActorModifierScript;
class AOmegaAbility;
class UOmegaCondition_Actor;
class UCombatantComponent;
class UHUDLayer;

// Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEnd, bool, bCancelled);

// Forward Declarations

class ACharacter;
class UCharacterMovementComponent;
class UPawnMovementComponent;
class UEnhancedInputComponent;
class UTimelineComponent;
class UOmegaSubsystem_GameInstance;

UENUM()
enum class EAbilityActivateInput
{
	AbilityActivateOn_Started            UMETA(DisplayName = "Started"),
	AbilityActivateOn_Triggered             UMETA(DisplayName = "Triggered"),
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAbilityConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

	bool L_CanActivate(AOmegaAbility* ability, UObject* Context) const;
	void L_OnActivate(AOmegaAbility* ability, UObject* Context) const;
	void L_OnFinish(AOmegaAbility* ability, UObject* Context, bool cancelled) const;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Ability")
	TArray<UOmegaCondition_Actor*> OwnerConditions_CanActivate;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Ability")
	TArray<UActorModifierScript*> Modifiers_OnActivate;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Ability")
	TArray<UActorModifierScript*> Modifiers_OnFinish;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Ability")
	FGameplayTagContainer Required_SystemTags;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Ability")
	FGameplayTagContainer Restricted_SystemTags;
};


UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaAbility : public AActor, public IDataInterface_InputAction
{
	GENERATED_BODY()
	
	void L_Log(const FString& str);
	
	UPROPERTY() float f_cooldownTime;
	UPROPERTY() bool b_IsKilling;
	UPROPERTY() float f_activeTickAccumulator = 0.f;

	UPROPERTY() UPawnMovementComponent* rev_moveComp;
	
public:
	UPROPERTY() ACharacter* ref_character;
	
	AOmegaAbility();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void Local_TriggerEvents(TArray<FName> Events);
	
	UFUNCTION() void L_OnInput_Start(FVector Value);
	UFUNCTION() void L_OnInput_End(FVector Value);
	UFUNCTION() virtual void Native_AbilityActivated(class UObject* Context);
	UFUNCTION() virtual void Native_AbilityFinished(bool Cancelled);
	UFUNCTION() virtual void Native_ActivatedTick(float DeltaTime);
	UFUNCTION() virtual bool Native_CanActivate(UObject* Context);
	UFUNCTION() bool Native_Execute();
	UFUNCTION() void Native_Start();
	UFUNCTION() void TryAssignControlInput(APawn* Pawn, AController* Controller);
	UFUNCTION() void Local_SetInputEnabled(bool Enabled);
	UFUNCTION() void RecieveFinish(bool bCancel);

	UPROPERTY(EditDefaultsOnly, Category = "✊Ability",meta=(Categories="INPUT")) float CooldownTime;
	UPROPERTY(EditDefaultsOnly, Category = "✊Ability",meta=(Categories="INPUT")) float ActiveTickFrequency;
	UPROPERTY(EditDefaultsOnly, Category = "✊Ability",meta=(Categories="INPUT")) bool BlockAutoAbilitySelectorWhileActive;
	UPROPERTY(EditDefaultsOnly, Category = "✊Ability - Input",meta=(Categories="INPUT")) FGameplayTag LinkedInputAction;
	UPROPERTY(EditDefaultsOnly, Category = "✊Ability - Input") bool bStopAbilityOnInputActionEnd;
	// ------------------------------------------------------
	// Tags
	// ------------------------------------------------------
	
	//Tags assosiated with this ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "✊Ability - Tags", meta = (Categories = "ABILITY"))
	FGameplayTagContainer AbilityTags;

	//Cancel any of the owner's active abilities with any of these tags.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "✊Ability - Tags", meta = (Categories = "ABILITY"))
	FGameplayTagContainer CancelAbilities;

	//Cancels and Prevent any abilites with any of these tags from being activated by the owner until this ability finishes.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "✊Ability - Tags", meta = (Categories = "ABILITY"))
	FGameplayTagContainer BlockAbilities;

	//The Owner Must have these gameplay tags for this ability to activate.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "✊Ability - Tags", meta = (Categories = "ABILITY"))
	FGameplayTagContainer RequiredOwnerTags;

	//The Owner must NOT have ANY of these gameplay tags in order for this ability to activate.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "✊Ability - Tags", meta = (Categories = "ABILITY"))
	FGameplayTagContainer RestrictedOwnerTags;
	
	//Tags granted to owning combatant while ability is active
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "✊Ability - Tags", meta = (Categories = "ABILITY"))
	FGameplayTagContainer OwnerTagsWhileActive;
	
	//----------------------------------------------------------------------
	// State
	//----------------------------------------------------------------------

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category="✊Ability") TArray<FName> Substates;
	UPROPERTY(BlueprintReadOnly,Category="✊Ability - Substate") int32 Substate=-1;
	
	UFUNCTION() TArray<FName> L_Substates() const { return Substates; }
	
	UFUNCTION(BlueprintCallable,Category="✊Ability - Substate",DisplayName="Set Widget State (Name)") void SetSubstate_Name(UPARAM(meta=(GetOptions="L_Substates")) FName State);
	UFUNCTION(BlueprintCallable,Category="✊Ability - Substate",DisplayName="Set Widget State (index)") void SetSubstate_Index(int32 State);
	UFUNCTION(BlueprintPure,Category="✊Ability - Substate",DisplayName="Get Widget State (index)") int32 GetSubstate_Index() const { return Substate; };
	UFUNCTION(BlueprintPure,Category="✊Ability - Substate",DisplayName="Get Widget State (Name from index)") FName GetSubstate_NameFromIndex(int32 index) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="✊Ability - Substate") void OnSubstateChange(int32 NewState,FName NewState_N,int32 OldState,FName OldState_N);
	
	// ------------------------------------------------------
	// Blueprint Implementable
	// ------------------------------------------------------

	UFUNCTION(BlueprintNativeEvent, Category = "✊Ability")
	void AbilityActivated(class UObject* Context);
	
	UFUNCTION(BlueprintNativeEvent, Category = "✊Ability")
	void AbilityFinished(bool Cancelled);
	
	UFUNCTION(BlueprintNativeEvent, Category = "✊Ability")
	void ActivatedTick(float DeltaTime);
	
	UFUNCTION(BlueprintNativeEvent, Category = "✊Ability")
	bool CanActivate(UObject* Context);
	
	UFUNCTION(BlueprintNativeEvent, Category = "✊Ability")
	float UtilityCheck(const UCombatantComponent* Combatant, UObject*& ExecuteContext, int32& Priority);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "✊Ability")
	UTimelineComponent* GetAbilityActivationTimeline();

	UFUNCTION(BlueprintImplementableEvent, Category = "✊Ability")
	void OnCombatantNotify(UCombatantComponent* OwningCombatant, FName Notify, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	void OnActiveTargetChanged(UCombatantComponent* ActiveTarget, bool Valid);
	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	void OnRegisteredTarget(UCombatantComponent* OwnerCombatant, UCombatantComponent* Target, bool bRegistered);
	
	// ------------------------------------------------------
	// Blueprint Callable
	// ------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, DisplayName="Activate", Category="Ω|Ability")
	bool Execute(UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category="Ability")
	bool SetInputEnabledForOwner(bool Enabled);
	
	//Completes and Destroys this Ability.
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CompleteAbility();

	//Cancels and Destroys this Ability.
	UFUNCTION(BlueprintCallable, Category = "Ω|Ability")
	void CancelAbility();
	
	
	UFUNCTION(BlueprintPure, Category="Cooldown")
	bool IsAbilityInCooldown() const;
	
	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class ACharacter* GetAbilityOwnerCharacter();

	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	APlayerController* GetAbilityOwnerPlayer();
	
	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class USkeletalMeshComponent* GetAbilityOwnerMesh() const;

	UFUNCTION(BlueprintPure, Category="Cooldown")
	void GetRemainingCooldownValues(float& Normalized, float& Seconds);
	
	UFUNCTION(BlueprintPure, Category = "Ω|Ability|Owner")
	class UCharacterMovementComponent* GetAbilityOwnerCharacterMoveComponent();

	UFUNCTION(BlueprintPure,Category="Ω|Ability|",meta=(ExpandBoolAsExecs="bResult"))
	bool IsOwner_Falling(bool& bResult);
	
	UFUNCTION(BlueprintCallable,Category="Omega Ability",meta=(ExpandBoolAsExecs="bResult",DeterminesOutputType="Class"))
	UPrimaryDataAsset* GetEquipmentInOwnerSlot(UEquipmentSlot* Slot, TSubclassOf<UPrimaryDataAsset> Class, bool& bResult);
	
	//-###########################################################################################################-//
	//---- UPROPERTY
	//-###########################################################################################################-//

	// ------------------------------------------------------
	// BlueprintReadOnly
	// ------------------------------------------------------
	
	UPROPERTY(BlueprintReadOnly, Category="Ω|Ability")
	bool bIsActive;

	// ------------------------------------------------------
	// Editable
	// ------------------------------------------------------
	
	UPROPERTY() UOmegaAbilityConfig* Config;
	UPROPERTY() bool bEnableInputOnActivation;
	UPROPERTY() bool FlipFlopInput;
	UPROPERTY() TSubclassOf<UHUDLayer> HudClass;
	
	UPROPERTY(BlueprintReadOnly, DisplayName="Ability Context", meta = (ExposeOnSpawn), Category = "Ability")
	UObject* ContextObject = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Owner")
	class UCombatantComponent* CombatantOwner;

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnAbilityEnd OnAbilityFinished;
	
	
};
