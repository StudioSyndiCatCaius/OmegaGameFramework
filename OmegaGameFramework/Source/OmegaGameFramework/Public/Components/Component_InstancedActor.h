// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaActors.h"
#include "OmegaComponent.h"
#include "Interfaces/I_Common.h"
#include "Components/ActorComponent.h"
#include "Component_InstancedActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInstanceNotify, AOmegaInstanceActor*, Instance, FName, Notify);

// Spawns and manages a pool of AOmegaInstanceActor objects, each bound to a context object. Useful for UI entries, party members, or any per-object actor representation.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UInstanceActorComponent : public UOmegaComponent, public IDataInterface_General
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UInstanceActorComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	// Live list of spawned instance actors in their current order.
	UPROPERTY(VisibleInstanceOnly,Category="Instanced Actor Component") TArray<AOmegaInstanceActor*> _instanceOrder;

	// The actor class to spawn for each instance.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instanced Actor Component", meta=(ExposeOnSpawn))
	TSubclassOf<AOmegaInstanceActor> InstancedActorClass;
	// Optional prefix added to each spawned instance's name for easy identification.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instanced Actor Component", meta=(ExposeOnSpawn))
	FName Instance_NamePrefex;

	// Spawns a new instance actor bound to Context. Flag is forwarded to OnInstanceCreated. LocalTransform offsets from the component.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component", meta=(AdvancedDisplay="LocalTransform"))
	AOmegaInstanceActor* CreateInstance(UObject* Context, const FString& Flag, FTransform LocalTransform);

	// Spawns one instance per element in Contexts, all sharing the same Flag and LocalTransform.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component", meta=(AdvancedDisplay="LocalTransform"))
	TArray<AOmegaInstanceActor*> CreateInstances(TArray<UObject*> Contexts, const FString& Flag, FTransform LocalTransform);

	// Finds the instance bound to Context. If CreateIfInvalid is true and none exists, a new one is spawned.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component",DisplayName="Try Get Instance",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs="Result"))
    AOmegaInstanceActor* TryGetInstanceByContext(UObject* Context, bool CreateIfInvalid, TSubclassOf<AOmegaInstanceActor> Class, bool& Result);

	// Returns the instance currently bound to Context, or null if none exists.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component",DisplayName="Get Instance (By Context)")
	AOmegaInstanceActor* GetInstanceByContext(UObject* Context);

	// Returns all instances whose context objects match the supplied list.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesByContexts(TArray<UObject*> Contexts);

	// Returns the instance whose label string matches Name, or null if none found.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component",DisplayName="Get Instance (By Name)")
	AOmegaInstanceActor* GetInstanceByName(const FString& Name);

	// Returns the instance at the given position in the ordered list.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component",DisplayName="Get Instance (by order Index)")
	AOmegaInstanceActor* GetInstanceByIndex(int32 Index);

	// Returns the context objects of all currently spawned instances.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<UObject*> GetAllInstanceContexts();

	// Returns all currently spawned instance actors.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstances();

	// Returns instances whose context has the given category tag, optionally excluding them instead.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesOfCategory(FGameplayTag CategoryTag, bool bExclude, bool bExact);

	// Returns instances whose context has any of the given gameplay tags, optionally excluding matches instead.
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesWithGameplayTags(FGameplayTagContainer Tags, bool bExclude, bool bExact);

	// Fires when any spawned instance calls TriggerNotify, passing the notify name.
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnInstanceNotify OnInstanceNotify;

	// ==========================================
	// FORMATION
	// ==========================================

	// Swaps the order positions of the instances at indices A and B.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order", DisplayName="Swap Instance Order")
	bool SwapInstanceIndecies(int32 A, int32 B);

	// Reorders instances so their labels match the provided Labels array.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Set Instance Order (By Labels)")
	void SetInstanceOrder_ByLabels(TArray<FString> Labels);

	// Returns the current instance order as a list of label strings.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Get Instance Order (By Labels)")
	TArray<FString> GetInstanceOrder_ByLabels();

	// Reorders instances so their contexts match the provided Contexts array.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Set Instance Order (By Context)")
	void SetInstanceOrder_ByContexts(TArray<UObject*> Contexts);

	// Returns the current instance order as a list of context objects.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Get Instance Order (By Context)")
	TArray<UObject*> GetInstanceOrder_ByContexts();

	// ==========================================
	// Notify
	// ==========================================
	// Sends the given named notify to every spawned instance actor.
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Notify")
	void TriggerNotify_OnAll(FName Notify);
};

// Implement on context objects to receive a callback when their bound instance actor begins play.
UINTERFACE(MinimalAPI,BlueprintType, DisplayName="♎Data🔴 - Instance Actor") class UDataInterface_InstanceActor: public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_InstanceActor
{
	GENERATED_BODY()
public:

	// Called when the instance actor bound to this object has begun play. Return false to suppress default setup.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|💸Instance Actor",DisplayName="Instance Actor - On BeginPlay")
	bool InstanceActor_BeginPlay(AOmegaInstanceActor* Actor);

};




// An actor managed by UInstanceActorComponent that represents a single context object in the world.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaInstanceActor : public AOmegaActorBASE, public IDataInterface_General
{
	GENERATED_BODY()

public:
	AOmegaInstanceActor();

	bool L_ContextUsesInterface() const;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Called in Blueprint when this instance is first created and bound to a context.
	UFUNCTION(BlueprintImplementableEvent, Category="InstanceActor")
	void OnInstanceCreated(UObject* Context, const FString& Flag);

	// The context object this instance represents (e.g. a data asset or game object).
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor", VisibleInstanceOnly) UObject* ContextObject = nullptr;

	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FString ContextLabel;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FText Context_Name;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FSlateBrush Context_Icon;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FText Context_Description;


	// The component that spawned and owns this instance.
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor")
	UInstanceActorComponent* OwningComponent;

	// INTERFACES
	bool Local_SourceHasInterface() const;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override;

	// Sends a named notify from this instance to the owning component's OnInstanceNotify delegate.
	UFUNCTION(BlueprintCallable, Category="InstanceActor")
	void TriggerNotify(FName Notify);

	// Called in Blueprint or C++ when a notify is received on this instance.
	UFUNCTION(BlueprintNativeEvent, Category="InstanceActor")
	void OnNotify(FName Notify);
};


// Blueprint function library for searching the world for instance actors by their context object.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaInstancedActorFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Finds the first instance actor in the world whose context matches Context and returns it cast to Class.
	UFUNCTION(BlueprintCallable,Category="Omega|InstancesActor",meta=(WorldContext="WorldContextObject",DeterminesOutputType="Class", ExpandBoolAsExecs="result"))
	static AOmegaInstanceActor* GetFirstInstanceActorOfContext(UObject* WorldContextObject, UObject* Context, TSubclassOf<AOmegaInstanceActor> Class,bool& result);

	// Returns all instance actors in the world whose context objects are in the Contexts array.
	UFUNCTION(BlueprintCallable,Category="Omega|InstancesActor",meta=(WorldContext="WorldContextObject",DeterminesOutputType="Class"))
	static TArray<AOmegaInstanceActor*> GetInstanceActorsFromContexts(UObject* WorldContextObject, TArray<UObject*> Contexts, TSubclassOf<AOmegaInstanceActor> Class);

};
