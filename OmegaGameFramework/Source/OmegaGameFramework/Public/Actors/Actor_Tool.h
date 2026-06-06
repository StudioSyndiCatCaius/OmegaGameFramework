// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/OmegaComponent.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Tool.generated.h"

class UArrowComponent;
class UCombatantComponent;
class USkeletalMeshComponent;

UENUM(BlueprintType)
enum EOmegaToolEvents : uint8
{
	ToolEvent_Equip UMETA(DisplayName="Equip"),
	ToolEvent_Unequip UMETA(DisplayName="Unequip"),
	ToolEvent_Activate UMETA(DisplayName="Activate"),
	ToolEvent_Deactivate UMETA(DisplayName="Deactivate"),
	ToolEvent_Trigger UMETA(DisplayName="Trigger"),
};

USTRUCT(BlueprintType)
struct FOmegaTool_Config
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tool") float RecoilTile=0.1;
	
};

USTRUCT(BlueprintType)
struct FOmegaTool_EventAssets
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tool") UAnimMontage* Montage=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tool") USoundBase* Sound=nullptr;
	
};

UINTERFACE(MinimalAPI,BlueprintType, DisplayName="♎Data🔴 - 🪓Tool") class UDataInterface_Tool : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Tool
{
	GENERATED_BODY()
public:

	//UFUNCTION(BlueprintNativeEvent,Category="♎I|Tool",DisplayName="Tool - On Construct")
	//int32 ToolActor_Construct(AOmegaToolActor* Tool);
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🪓Tool",DisplayName="🪓Tool - On BeginPlay")
	int32 ToolActor_BeginPlay(AOmegaToolActor* Tool);
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🪓Tool",DisplayName="🪓Tool - Can Trigger?")
	bool Tool_CanTrigger(AOmegaToolActor* Tool);
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🪓Tool",DisplayName="🪓Tool - On Trigger")
	int32 Tool_OnTrigger(AOmegaToolActor* Tool);
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🪓Tool",DisplayName="🪓Tool - On Activated")
	int32 Tool_OnActivate(AOmegaToolActor* Tool,bool bActivated);
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🪓Tool",DisplayName="🪓Tool - Get Event Assets")
	void GetTool_EventAssets(EOmegaToolEvents Animation, FOmegaTool_EventAssets& Assets);
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|🪓Tool",DisplayName="🪓Tool - Get Actor Class")
	TSubclassOf<AOmegaToolActor> GetToolActorClass();
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|🪓Tool",DisplayName="🪓Tool - Get Config")
	FOmegaTool_Config GetToolConfig();
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaToolActor : public AActor
{
	GENERATED_BODY()
	
	float f_recoilDur;
	bool b_isActive;
	
	UPROPERTY() USkeletalMeshComponent* OverrideOwnerMesh=nullptr;
	
protected:
	AOmegaToolActor();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	FOmegaTool_Config GetConfig() const;
public:
	UAnimMontage* L_PlayMontage(EOmegaToolEvents Anim);
	
	UPROPERTY(BlueprintReadOnly,Category="🪓Tool") UOmegaToolComponent* OwningComponent=nullptr;
	UPROPERTY(BlueprintReadOnly,Category="🪓Tool") UArrowComponent* TriggerRoot=nullptr;
	
	//Will automatically try to asign this as the tool owner mesh no override is set.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🪓Tool") FName SkeletalMeshTag="ToolHolder";
	
	UFUNCTION(BlueprintCallable,Category="🪓Tool") void SetToolOwnerSkeletalMesh(USkeletalMeshComponent* Mesh);
	UFUNCTION(BlueprintPure,Category="🪓Tool") USkeletalMeshComponent* GetToolOwnerSkeletalMesh() const;
	
	UFUNCTION(BlueprintPure,Category="Tool") AActor* GetToolOwner_Actor() const;
	UFUNCTION(BlueprintPure,Category="Tool") ACharacter* GetToolOwner_Character() const;
	UFUNCTION(BlueprintPure,Category="Tool") UCombatantComponent* GetToolOwner_Combatant() const;
	
	UFUNCTION(BlueprintCallable,Category="🪓Tool") bool SetToolActive(bool bActive);
	UFUNCTION(BlueprintPure,Category="🪓Tool") bool IsToolActive() const { return b_isActive; };
	UFUNCTION(BlueprintPure,Category="🪓Tool") bool CanTrigger();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🪓Tool")
	TScriptInterface<IDataInterface_Tool> Preset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🪓Tool")
	FOmegaTool_Config Config;
	
	UFUNCTION(BlueprintCallable,Category="Omega Tool") void SetPreset(TScriptInterface<IDataInterface_Tool> _preset);
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="Tool - Get Montages") void GetToolEventAssets(EOmegaToolEvents Animation, FOmegaTool_EventAssets& Assets);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="Tool - On Activate") void K2_OnActivate(bool bActivated);
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="Tool - On Trigger") void K2_OnTrigger();
	UFUNCTION(BlueprintNativeEvent,Category="Omega Tool",DisplayName="Tool - On Trigger") bool K2_CanTrigger();
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="Tool - Active Tick") void K2_ActiveTick(float DeltaTime);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOmegaToolComponentActorDelegate,UOmegaToolComponent*, Component,AOmegaToolActor*, Tool);



UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaToolComponent : public UOmegaComponent
{
	GENERATED_BODY()
	UPROPERTY() TMap<FGameplayTag,AOmegaToolActor*> ToolInstances;
	UPROPERTY() TArray<FGameplayTag> ChangingSlots;
	
	
public:
	
	void L_PlayMontageReturn(EOmegaToolEvents anim, FGameplayTag Slot,bool bSkip, TFunction<void()> OnComplete);
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaToolComponentActorDelegate OnToolEquip_Begin;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaToolComponentActorDelegate OnToolEquip_End;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaToolComponentActorDelegate OnToolUnequip_Begin;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaToolComponentActorDelegate OnToolUnequip_End;
	
	UFUNCTION(BlueprintCallable,Category="Omega Tool",DisplayName="Tool - Set Slot (From Class)")
	bool Slot_SetTool(TSubclassOf<AOmegaToolActor> Tool, TScriptInterface<IDataInterface_Tool> Preset, FGameplayTag Slot, bool bSkipUnequipAnim, bool bSkipEquipAnim);
	UFUNCTION(BlueprintCallable,Category="Omega Tool",DisplayName="Tool - Set Slot (From Preset)")
	bool Slot_SetToolFromPreset(TScriptInterface<IDataInterface_Tool> Preset, FGameplayTag Slot, bool bSkipUnequipAnim, bool bSkipEquipAnim);
	UFUNCTION(BlueprintCallable,Category="Omega Tool") bool Slot_Clear(FGameplayTag Slot);
	UFUNCTION(BlueprintPure,Category="Omega Tool") bool Slot_IsChangingTool(FGameplayTag Slot);
	UFUNCTION(BlueprintPure,Category="Omega Tool") AOmegaToolActor* Slot_GetToolInstance(FGameplayTag Slot);
	UFUNCTION(BlueprintCallable,Category="Omega Tool") void Slot_SetToolActive(FGameplayTag Slot,bool ToolActive);
};


// --------------------------------------------------------------------------------------------------------
// Iterations - Tool Actor
// --------------------------------------------------------------------------------------------------------

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaToolActor_FirstPerson : public AOmegaToolActor
{
	GENERATED_BODY()
	
public:
	AOmegaToolActor_FirstPerson();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components") USkeletalMeshComponent* ArmsMesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components") USceneComponent* GripRoot;
};