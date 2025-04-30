// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Component_ActorIdentity.generated.h"

// =======================================================================================================================
// COMPONENT
// =======================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorIdentityChanged, UPrimaryDataAsset*, IdentityAsset, UActorIdentityComponent*, Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorIdentityComponent : public UActorComponent, public IGameplayTagsInterface, public IActorTagEventInterface
{
	GENERATED_BODY()

	bool Local_IsSourceAssetValid() const;
	TArray<UActorIdentityScript*> Local_GetScripts() const;

public:

	UPROPERTY(EditAnywhere,Category="Actor Identity") UPrimaryDataAsset* IdentitySource;
	UPROPERTY(EditAnywhere,Category="Actor Identity") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,Category="Actor Identity") FGameplayTagContainer GameplayTags;
	
	UPROPERTY(BlueprintAssignable) FOnActorIdentityChanged OnActorIdentityChanged;


	UFUNCTION(BlueprintCallable,Category="Actor Identity")
	void SetIdentitySourceAsset(UPrimaryDataAsset* SourceAsset);
	UFUNCTION(BlueprintPure,Category="Actor Identity")
	UPrimaryDataAsset*  GetIdentitySourceAsset() const
	{
		if(IdentitySource) {return IdentitySource;} return nullptr;
	};

	
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override { return CategoryTag; };
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return GameplayTags; };
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;
	
	
protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	
};

UINTERFACE(MinimalAPI) class UDataInterface_ActorIdentitySource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actor Identity")
	TArray<UActorIdentityScript*> GetIdentityScripts();

	UFUNCTION(BlueprintNativeEvent,Category="Actor Identity")
	bool OnIdentityInit(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="Actor Identity")
	bool OnActorConstruction(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="Actor Identity")
	bool OnActorBeginPlay(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="Actor Identity")
	bool OnActorTick(AActor* Actor, UActorIdentityComponent* Component, float DeltaTime);

	UFUNCTION(BlueprintNativeEvent,Category="Actor Identity")
	bool OnActorTagEvent(AActor* Actor, UActorIdentityComponent* Component, FGameplayTag Event);
	
};

// =======================================================================================================================
// IDENTITY ASSET
// =======================================================================================================================


UCLASS()
class OMEGAGAMEFRAMEWORK_API UActorIdentityPreset : public UOmegaDataAsset, public IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()

public:

	virtual TArray<UActorIdentityScript*> GetIdentityScripts_Implementation() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|ActorIdentity")
	TArray<UActorIdentityPreset*> PreSetup_Scripts;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Omega|ActorIdentity")
	TArray<UActorIdentityScript*> Local_Scripts;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|ActorIdentity")
	TArray<UActorIdentityPreset*> PostSetup_Scripts;
};

// =======================================================================================================================
// IDENTITY SCRIPT
// =======================================================================================================================


UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UActorIdentityScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Actor Identity")
	void OnActorConstruction(AActor* Actor, UActorIdentityComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor Identity")
	void OnActorBeginPlay(AActor* Actor, UActorIdentityComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor Identity")
	void OnActorTick(AActor* Actor, UActorIdentityComponent* Component, float DeltaTime) const;
};



// =======================================================================================================================
// FUNCTIONS
// =======================================================================================================================

UCLASS()
class UOmegaActorIdentityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Omega|Actors",meta=(WorldContext="WorldContextObject",DeterminesOutputType="FilterClass"))
	static TArray<AActor*> GetAllActorsWithIdentity(UObject* WorldContextObject, UPrimaryDataAsset* Asset, TSubclassOf<AActor> FilterClass);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject",ExpandEnumAsExecs = "Outcome",DeterminesOutputType="FilterClass"),DisplayName="Ω🔴 Get First Actor /w Identity")
	static AActor* GetFirstActorWithIdentity(UObject* WorldContextObject,UPrimaryDataAsset* Asset, TSubclassOf<AActor> FilterClass,  TEnumAsByte<EOmegaFunctionResult>& Outcome);

};