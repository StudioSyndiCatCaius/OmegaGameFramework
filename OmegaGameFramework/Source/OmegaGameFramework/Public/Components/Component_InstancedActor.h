﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Component_InstancedActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInstanceNotify, AOmegaInstanceActor*, Instance, FName, Notify);

// Create several instances of single actor class
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UInstanceActorComponent : public UActorComponent, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInstanceActorComponent();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instanced Actor Component", meta=(ExposeOnSpawn))
	TSubclassOf<AOmegaInstanceActor> InstancedActorClass;

	UPROPERTY()
	TArray<AOmegaInstanceActor*> PrivateInstances;
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component", meta=(AdvancedDisplay="LocalTransform"))
	AOmegaInstanceActor* CreateInstance(UObject* Context, const FString& Flag, FTransform LocalTransform);
	
	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	AOmegaInstanceActor* GetInstanceByContext(UObject* Context);

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component")
	AOmegaInstanceActor* GetInstanceByName(const FString& Name);

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

	UFUNCTION(BlueprintPure, Category="Instanced Actor Component", DisplayName="Get Instance by Formation Index")
	AOmegaInstanceActor* GetInstanceByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Formation", DisplayName="Swap Instance Order")
	bool SwapInstanceIndecies(int32 A, int32 B);

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Formation")
	void SetInstanceOrder_ByLabels(TArray<FString> Labels);

	UFUNCTION(BlueprintCallable, Category="Instanced Actor Component|Formation")
	TArray<FString> GetInstanceOrder_ByLabels();

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
	
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor", VisibleInstanceOnly)
	UObject* ContextObject = nullptr;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly)
	FString ContextLabel;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly)
	FText Context_Name;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly)
	FSlateBrush Context_Icon;
	UPROPERTY(Category="InstanceActor", VisibleInstanceOnly)
	FText Context_Description;

	
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
