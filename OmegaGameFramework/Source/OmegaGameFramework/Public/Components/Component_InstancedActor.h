// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "Components/ActorComponent.h"
#include "Component_InstancedActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInstanceNotify, AOmegaInstanceActor*, Instance, FName, Notify);

// Create several instances of single actor class
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UInstanceActorComponent : public UActorComponent, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()



protected:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UInstanceActorComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	UPROPERTY(VisibleInstanceOnly,Category="Instanced Actor Component") TArray<AOmegaInstanceActor*> _instanceOrder;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instanced Actor Component", meta=(ExposeOnSpawn))
	TSubclassOf<AOmegaInstanceActor> InstancedActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instanced Actor Component", meta=(ExposeOnSpawn))
	FName Instance_NamePrefex;
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component", meta=(AdvancedDisplay="LocalTransform"))
	AOmegaInstanceActor* CreateInstance(UObject* Context, const FString& Flag, FTransform LocalTransform);
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component", meta=(AdvancedDisplay="LocalTransform"))
	void CreateInstances(TArray<UObject*> Contexts, const FString& Flag, FTransform LocalTransform);
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component",DisplayName="Try Get Instance",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs="Result"))
    AOmegaInstanceActor* TryGetInstanceByContext(UObject* Context, bool CreateIfInvalid, TSubclassOf<AOmegaInstanceActor> Class, bool& Result);
	
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component",DisplayName="Get Instance (By Context)")
	AOmegaInstanceActor* GetInstanceByContext(UObject* Context);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesByContexts(TArray<UObject*> Contexts);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component",DisplayName="Get Instance (By Name)")
	AOmegaInstanceActor* GetInstanceByName(const FString& Name);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component",DisplayName="Get Instance (by order Index)")
	AOmegaInstanceActor* GetInstanceByIndex(int32 Index);
	
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<UObject*> GetAllInstanceContexts();

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstances();
	
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesOfCategory(FGameplayTag CategoryTag, bool bExclude, bool bExact);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	TArray<AOmegaInstanceActor*> GetInstancesWithGameplayTags(FGameplayTagContainer Tags, bool bExclude, bool bExact);

	UPROPERTY(BlueprintAssignable)
	FOnInstanceNotify OnInstanceNotify;

	// ==========================================
	// FORMATION
	// ==========================================
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order", DisplayName="Swap Instance Order")
	bool SwapInstanceIndecies(int32 A, int32 B);

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Set Instance Order (By Labels)")
	void SetInstanceOrder_ByLabels(TArray<FString> Labels);

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Get Instance Order (By Labels)")
	TArray<FString> GetInstanceOrder_ByLabels();

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Set Instance Order (By Context)")
	void SetInstanceOrder_ByContexts(TArray<UObject*> Contexts);

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Order",DisplayName="Get Instance Order (By Context)")
	TArray<UObject*> GetInstanceOrder_ByContexts();
	
	// ==========================================
	// Notify
	// ==========================================
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Notify")
	void TriggerNotify_OnAll(FName Notify);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaInstanceActor : public AActor, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaInstanceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category="InstanceActor")
	void OnInstanceCreated(UObject* Context, const FString& Flag);
	
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor", VisibleInstanceOnly) UObject* ContextObject = nullptr;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FString ContextLabel;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FText Context_Name;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FSlateBrush Context_Icon;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly) FText Context_Description;

	
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor")
	UInstanceActorComponent* OwningComponent;

	// INTERFACES
	bool Local_SourceHasInterface() const;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;

	//NOTIFY
	UFUNCTION(BlueprintCallable, Category="InstanceActor")
	void TriggerNotify(FName Notify);

	UFUNCTION(BlueprintNativeEvent, Category="InstanceActor")
	void OnNotify(FName Notify);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaInstancedActorFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|InstancesActor",meta=(WorldContext="WorldContextObject",DeterminesOutputType="Class", ExpandBoolAsExecs="result"))
	static AOmegaInstanceActor* GetFirstInstanceActorOfContext(UObject* WorldContextObject, UObject* Context, TSubclassOf<AOmegaInstanceActor> Class,bool& result);
	
	UFUNCTION(BlueprintCallable,Category="Omega|InstancesActor",meta=(WorldContext="WorldContextObject",DeterminesOutputType="Class"))
	static TArray<AOmegaInstanceActor*> GetInstanceActorsFromContexts(UObject* WorldContextObject, TArray<UObject*> Contexts, TSubclassOf<AOmegaInstanceActor> Class);
	
};
