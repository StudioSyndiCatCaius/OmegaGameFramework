// Copyright Studio Syndicat 2021. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "UObject/ObjectMacros.h"
#include <UObject/ScriptInterface.h>
#include <Tickable.h>

#include "ActionsModule.h"
#include "ActionsSubsystem.h"
#include "GameplayTagContainer.h"
#include "Action.generated.h"

class UWorld;

DECLARE_LOG_CATEGORY_EXTERN(ActionLog, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSucess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailure);

/**
 * Result of a node execution
 */
UENUM(Blueprintable, BlueprintType)
enum class EActionState : uint8
{
	Preparing UMETA(Hidden),
	Running   UMETA(Hidden),
	Success,
	Failure,
	Cancelled UMETA(Hidden),
};

FORCEINLINE FString ToString(EActionState Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EActionState"), true);
	return EnumPtr? EnumPtr->GetNameByValue((int64)Value).ToString() : TEXT("Invalid");
}

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActionActivatedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionFinishedDelegate, const EActionState, Reason);


/**
 *
 */
UCLASS(Blueprintable, EditInlineNew, meta = (ExposedAsyncProxy, DisplayName="Gameplay Action"))
class ACTIONS_API UAction : public UObject
{
	GENERATED_BODY()

	/************************************************************************/
	/* PROPERTIES														    */
	/************************************************************************/
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Action)
	bool bWantsToTick = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Action)
	FColor NodeColor = { 40, 30, 240 };

	//Tags
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
	FGameplayTag CategoryTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer ActionTags;
	
	UPROPERTY(BlueprintAssignable)
	FOnSucess OnSuccess;
	UPROPERTY(BlueprintAssignable)
	FOnFailure OnFailure;


protected:

	//Tick length in seconds. 0 is default tick rate
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Action, BlueprintGetter="GetTickRate")
	float TickRate = 0.15f;

private:

	UPROPERTY(Transient)
	EActionState State = EActionState::Preparing;

	UPROPERTY(SaveGame)
	TSet<UAction*> ChildrenActions;

public:

	/** Delegates */

	// Notify when the action is activated
	UPROPERTY()
	FActionActivatedDelegate OnActivationDelegate;

	// Notify when the action finished
	UPROPERTY()
	FActionFinishedDelegate OnFinishedDelegate;


	/************************************************************************/
	/* METHODS											     			    */
	/************************************************************************/

	/** Called to active an action if not already. */
	UFUNCTION(BlueprintCallable, Category = "GameplayAction", BlueprintInternalUseOnly)
	void Activate();

	/** Internal Use Only. Called when the action is stopped from running by its owner */
	void Cancel();

	/** Internal Use Only. Called by the subsystem when TickRate exceeds */
	void DoTick(float DeltaTime)
	{
		Tick(DeltaTime);
		ReceiveTick(DeltaTime);
	}

protected:

	virtual bool CanActivate() { return ReceiveCanActivate(); }

	virtual void OnActivation()
	{
		OnActivationDelegate.Broadcast();
		ReceiveActivate();
	}

	virtual void Tick(float DeltaTime) {}

	virtual void OnFinish(const EActionState Reason);

private:

	void Finish(bool bSuccess = true);

	void Destroy();

	void AddChildren(UAction* Child);
	void RemoveChildren(UAction* Child);


public:

	UFUNCTION(BlueprintCallable, Category = Action, meta = (KeyWords = "Finish"))
	void Succeed() { Finish(true); }

	UFUNCTION(BlueprintCallable, Category = Action, meta = (KeyWords = "Finish"))
	void Fail(FName Error = NAME_None)
	{
		UE_LOG(LogActions, Log, TEXT("Gameplay Action '%s' failed: %s"), *GetName(), *Error.ToString());
		Finish(false);
	}


	/** Events */
protected:

	/** Event called to check if an action can activate. */
	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "Can Activate"))
	bool ReceiveCanActivate();

	/** Called when this action is activated */
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Activate"))
	void ReceiveActivate();

	/** Called when tick is received based on TickRate */
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Tick"))
	void ReceiveTick(float DeltaTime);

	/** Called when this action finishes */
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Finished"))
	void ReceiveFinished(const EActionState Reason);

	/** Called when this action cancels */
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Cancelled"))
	void ReceiveCancel();


	/** Helpers */
public:

	FORCEINLINE bool CanTick() const
	{
		return bWantsToTick && IsRunning() && !GetOuter()->IsPendingKill();
	}

	UFUNCTION(BlueprintPure, Category = Action)
	FORCEINLINE bool IsRunning() const { return !IsPendingKill() && State == EActionState::Running; }

	UFUNCTION(BlueprintPure, Category = Action)
	FORCEINLINE bool Succeeded() const { return !IsPendingKill() && State == EActionState::Success; }

	UFUNCTION(BlueprintPure, Category = Action)
	FORCEINLINE bool Failed()    const { return !IsPendingKill() && State == EActionState::Failure; }

	UFUNCTION(BlueprintPure, Category = Action)
	FORCEINLINE EActionState GetState() const { return State; }

	UFUNCTION(BlueprintPure, Category = Action)
	FORCEINLINE UObject* const GetParent() const { return GetOuter(); }

	UFUNCTION(BlueprintPure, Category = Action)
	FORCEINLINE UAction* GetParentAction() const { return Cast<UAction>(GetOuter()); }

	UFUNCTION(BlueprintGetter)
	FORCEINLINE float GetTickRate() const
	{
		// Reduce TickRate Precision to 0.1ms
		return FMath::FloorToFloat(TickRate * 10000.f) * 0.0001f;
	}

	/** @return the object that executes the root action */
	UFUNCTION(BlueprintPure, Category = Action)
	UObject* GetOwner() const;

	/** @return the actor if any that executes the root action */
	UFUNCTION(BlueprintPure, BlueprintPure, Category = Action)
	AActor* GetOwnerActor() const;

	/** @return the component if any that executes the root action */
	UFUNCTION(BlueprintPure, Category = Action)
	UActorComponent* GetOwnerComponent() const { return Cast<UActorComponent>(GetOwner()); }

	virtual UWorld* GetWorld() const override
	{
		// If we are a CDO, we must return nullptr to fool UObject::ImplementsGetWorld.
		if (HasAllFlags(RF_ClassDefaultObject))
			return nullptr;

		const UObject* const InOwner = GetOwner();
		return InOwner ? InOwner->GetWorld() : nullptr;
	}

#if WITH_GAMEPLAY_DEBUGGER
	void DescribeSelfToGameplayDebugger(class FGameplayDebugger_Actions& Debugger, int8 Indent) const;
#endif // WITH_GAMEPLAY_DEBUGGER

private:

	UActionsSubsystem* GetSubsystem() const
	{
		const UWorld* World = GetWorld();
		const UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
		return UGameInstance::GetSubsystem<UActionsSubsystem>(GI);
	}

public:

	/** STATIC */

	/**
	 * Creates a new actionC. Templated version
	 * @param ActionType
	 * @param Owner of the action. If destroyed, the action will follow.
	 * @param bAutoActivate if true activates the action. If false, Action->Activate() can be called later.
	 */
	template<typename ActionType>
	static ActionType* Create(UObject* Owner, bool bAutoActivate = false)
	{
		static_assert(!TIsSame<ActionType, UAction>::Value, "Instantiating UAction is not allowed. Use a child class.");
		static_assert(TIsDerivedFrom<ActionType, UAction>::IsDerived, "Provided class must inherit UAction.");
		return Cast<ActionType>(Create(Owner, ActionType::StaticClass(), bAutoActivate));
	}

	/**
	 * Creates a new actionA
	 * @param Owner of the action. If destroyed, the action will follow.
	 * @param Type of the action to create
	 * @param bAutoActivate if true activates the action. If false, Action->Activate() can be called later.
	 */
	static UAction* Create(UObject* Owner, const TSubclassOf<class UAction> Type, bool bAutoActivate = false);

	/**
	 * Creates a new actionB
	 * @param Owner of the action. If destroyed, the action will follow.
	 * @param Template whose properties and class are used to create the action.
	 * @param bAutoActivate if true activates the action. If false, Action->Activate() can be called later.
	 */
	static UAction* Create(UObject* Owner, class UAction* Template, bool bAutoActivate = false);
};
