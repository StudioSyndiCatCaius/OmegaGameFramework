// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaComponent.h"
#include "Components/ActorComponent.h"
#include "Condition/Condition_Actor.h"
#include "Functions/F_Component.h"
#include "Functions/F_TagEvent.h"
#include "Interfaces/I_Interaction.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_RandomRange.h"
#include "Component_GameplayActor.generated.h"

class UOmegaActorConfig;
class UOmegaFlowAssetBase;

// =======================================================================================================================
// Config Script
// =======================================================================================================================

UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfigScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="ActorConfig")
	void OnActorConfigured(AActor* Actor) const;
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	TArray<FGameplayTag> AutoregisterToGroups;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UOmegaActorConfigScript*> Scripts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	FOmegaRandomRangeFloat BeginPlayMod_Delay;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UActorModifierScript*> BeginPlay_Modifiers;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FOmegaConditions_Actor CanInteract_Target;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FOmegaConditions_Actor CanInteract_Instigator;
};

// =======================================================================================================================
// Subscripts
// =======================================================================================================================

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API USubscript : public UObject
{
	GENERATED_BODY()

public:	

	//USubscript();

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void ActorBeginOverlap(UGameplayActorComponent* OwningComponent, AActor* OverlappedActor) const;
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void ActorEndOverlap(UGameplayActorComponent* OwningComponent, AActor* OverlappedActor) const;
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void ActorHit(UGameplayActorComponent* OwningComponent, AActor* SelfActor, AActor* OtherActor, FVector Vector, const FHitResult& hit) const;
	
	UPROPERTY(EditDefaultsOnly,Category="Subscript")
	bool bCanTick;
	
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnBeginPlay(UGameplayActorComponent* OwningComponent) const;
	
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnEndPlay(UGameplayActorComponent* OwningComponent) const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void Tick(float Delta,UGameplayActorComponent* OwningComponent) const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnTagEvent(UGameplayActorComponent* OwningComponent, FGameplayTag Event) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API USubscriptCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Default")
	TArray<USubscript*> Subscripts;
	
};

USTRUCT(BlueprintType)
struct FOmegaSubscripts
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="📜Subscripts",DisplayName="📜Subscripts (Preset)") TArray<USubscriptCollection*> Preset;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="📜Subscripts",DisplayName="📜Subscripts (Inline)") TArray<USubscript*> Inline;
	
	TArray<USubscript*> GetSubscripts() const;
	// 0=beginPlay | 1=EndPlay | 2=BeginOverlap | 3=EndOverlay | 4=TagEvent
	void EventCall(uint8 event, UGameplayActorComponent* component, AActor* other_actor=nullptr,FGameplayTag tag=FGameplayTag(),FHitResult hit=FHitResult());
};


// =======================================================================================================================
// COMPONENT
// =======================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorIdentityChanged, UPrimaryDataAsset*, IdentityAsset, UGameplayActorComponent*, Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UGameplayActorComponent : public UOmegaComponent, public IDataInterface_General, public IActorTagEventInterface, public IActorInterface_Interactable
{
	GENERATED_BODY()
	
	void L_Init();
	bool Local_IsSourceAssetValid() const;
	bool L_SourceUsesGeneralInterface() const;
	TArray<UActorIdentityScript*> Local_GetScripts() const;

	UPROPERTY() FTimerHandle timer_modDelay;
	UFUNCTION() void L_TimerEnd();
	virtual UOmegaActorConfig* L_GetConfig();
	virtual void OnRegister() override;
	
public:
	UGameplayActorComponent();
	void Local_RunConstruct();
	
	UPROPERTY(BlueprintReadOnly)
	FLuaValue temp_table;
	
	UPROPERTY(EditAnywhere,Category="Config") UOmegaActorConfig* DefaultConfig;
	UFUNCTION(BlueprintCallable,Category="Config") void SetConfig(UOmegaActorConfig* Config);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Gameplay") FText OverrideName;
	UPROPERTY(EditAnywhere,Category="Gameplay",DisplayName="Identity") UPrimaryDataAsset* IdentitySource;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay",DisplayName="Identity Flags") FOmegaBitflagsBase IdentityFlags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay") TSoftObjectPtr<UOmegaFlowAssetBase> DefaultFlow;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay") FGuid Guid;

	UPROPERTY(EditAnywhere,Category="Gameplay|Tags") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,Category="Gameplay|Tags") FGameplayTagContainer GameplayTags;
	UPROPERTY(EditAnywhere, Category="Gameplay|Tags") FGameplayTag PauseCategory;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay", meta=(ShowOnlyInnerProperties)) FOmegaSubscripts Subscripts;
	
	UPROPERTY(BlueprintAssignable) FOnActorIdentityChanged OnActorIdentityChanged;

	UFUNCTION(BlueprintCallable,Category="Actor")
	void SetIdentitySourceAsset(UPrimaryDataAsset* SourceAsset);
	UFUNCTION(BlueprintPure,Category="Actor")
	UPrimaryDataAsset*  GetIdentitySourceAsset() const
	{
		if(IdentitySource) {return IdentitySource;} return nullptr;
	};
	
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override { return CategoryTag; };
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return GameplayTags; };
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;
	
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION() void OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION() void OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION() void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	// -------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Bool") void SetBool(FString param, bool Value);
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Int") void SetInt(FString param, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Float") void SetFloat(FString param, float Value);
	UFUNCTION(BlueprintCallable,Category="Subscript",DisplayName="Subscript - Set Vector") void SetVector(FString param, FVector Value);
	
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Bool") bool GetBool(FString param);
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Int") int32 GetInt(FString param);
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Float") float GetFloat(FString param);
	UFUNCTION(BlueprintPure,Category="Subscript",DisplayName="Subscript - Get Vector") FVector GetVector(FString param);
	
};

UINTERFACE(MinimalAPI) class UDataInterface_ActorIdentitySource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Actor",DisplayName="Actor ID - Get Scripts")
	TArray<UActorIdentityScript*> GetIdentityScripts();

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Identity Init")
	bool OnIdentityInit(AActor* Actor, UGameplayActorComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Identity Uninit")
	bool OnIdentityUninit(AActor* Actor, UGameplayActorComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Construct")
	bool OnActorConstruction(AActor* Actor, UGameplayActorComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Begin Play")
	bool OnActorBeginPlay(AActor* Actor, UGameplayActorComponent* Component);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Tick")
	bool OnActorTick(AActor* Actor, UGameplayActorComponent* Component, float DeltaTime);

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Tag Event")
	bool OnActorTagEvent(AActor* Actor, UGameplayActorComponent* Component, FGameplayTag Event);

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - On Interact")
	bool OnActorInteract(AActor* Actor, UGameplayActorComponent* Component, AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Meta);
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Actor",DisplayName="Actor ID - Interact Blocked?")
	bool IsInteractBlocked(AActor* Actor, UGameplayActorComponent* Component, AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Meta);
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
	void OnActorConstruction(AActor* Actor, UGameplayActorComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorBeginPlay(AActor* Actor, UGameplayActorComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="ΩI|Actor")
	void OnActorTick(AActor* Actor, UGameplayActorComponent* Component, float DeltaTime) const;
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

UCLASS()
class OMEGAGAMEFRAMEWORK_API UActorIdentityComponent : public UGameplayActorComponent
{
	
	GENERATED_BODY()
public:
};