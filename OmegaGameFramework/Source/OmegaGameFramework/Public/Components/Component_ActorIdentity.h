// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaGameplayComponent.h"
#include "Components/ActorComponent.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "Misc/GeneralDataObject.h"
#include "Component_ActorIdentity.generated.h"

// =======================================================================================================================
// COMPONENT
// =======================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorIdentityChanged, UPrimaryDataAsset*, IdentityAsset, UActorIdentityComponent*, Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UActorIdentityComponent : public UOmegaGameplayComponent, public IGameplayTagsInterface, public IActorTagEventInterface
{
	GENERATED_BODY()

	void L_Init();
	bool Local_IsSourceAssetValid() const;
	TArray<UActorIdentityScript*> Local_GetScripts() const;

public:

	UPROPERTY(EditAnywhere,Category="Actor") UPrimaryDataAsset* IdentitySource;
	UPROPERTY(EditAnywhere,Category="Actor") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,Category="Actor") FGameplayTagContainer GameplayTags;
	
	UPROPERTY(BlueprintAssignable) FOnActorIdentityChanged OnActorIdentityChanged;

	UFUNCTION(BlueprintCallable,Category="Actor")
	void SetIdentitySourceAsset(UPrimaryDataAsset* SourceAsset);
	UFUNCTION(BlueprintPure,Category="Actor")
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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Actor",DisplayName="Actor ID - Get Scripts")
	TArray<UActorIdentityScript*> GetIdentityScripts();

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Identity Init")
	bool OnIdentityInit(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Identity Uninit")
	bool OnIdentityUninit(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Construct")
	bool OnActorConstruction(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Begin Play")
	bool OnActorBeginPlay(AActor* Actor, UActorIdentityComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Tick")
	bool OnActorTick(AActor* Actor, UActorIdentityComponent* Component, float DeltaTime);

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Tag Event")
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

	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorConstruction(AActor* Actor, UActorIdentityComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorBeginPlay(AActor* Actor, UActorIdentityComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
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
	
	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(WorldContext="WorldContextObject",ExpandBoolAsExecs = "Outcome",DeterminesOutputType="FilterClass"),DisplayName="Ω🔴 Get First Actor /w Identity")
	static AActor* GetFirstActorWithIdentity(UObject* WorldContextObject,UPrimaryDataAsset* Asset, TSubclassOf<AActor> FilterClass,  bool& Outcome);

	UFUNCTION(BlueprintCallable, Category="Omega|Actors", meta=(ExpandBoolAsExecs = "result",DeterminesOutputType="Class"))
	static UPrimaryDataAsset* GetActorIdentityAsset(AActor* Actor, bool& result,TSubclassOf<UPrimaryDataAsset> Class=nullptr);

};