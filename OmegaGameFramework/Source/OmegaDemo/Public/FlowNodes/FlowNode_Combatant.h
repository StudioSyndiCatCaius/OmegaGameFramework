// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Condition/Condition_Combatant.h"
#include "Nodes/FlowNode.h"
#include "Misc/OmegaUtils_Enums.h"
#include "FlowNode_Combatant.generated.h"


class UOmegaScriptedEffect;

UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_CombatantBASE : public UFlowNode
{
	GENERATED_BODY()
public:
	
	// 0=default | 1=bool
	uint8 NodeType=0;
	
	virtual void ExecuteInput(const FName& PinName) override;
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) { return true;};
	virtual void L_Condition_Run(UCombatantComponent* Combatant) {};
	UCombatantComponent* L_AssetToCombatant(UPrimaryDataAsset* asset) const;
	void L_Condition_Do();
	
	UFUNCTION(BlueprintCallable,Category="Combatant") UCombatantComponent* GetLinkedCombatant() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Combatant") UPrimaryDataAsset* ActorIdentity;
	virtual FSlateBrush K2_GetNodeIcon_Implementation() const override;
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override
	{
		return "Combatant";
	};
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override
	{
		OutColor=FLinearColor(FColor::Blue);
		return true;
	};
	
	
#endif
};


UCLASS(DisplayName="🤜 - Effects")
class OMEGADEMO_API UFlowNode_Combatant_Effects : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	UFlowNode_Combatant_Effects();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(BlueprintReadWrite, Instanced,EditAnywhere, Category="Effects")
	TArray<UOmegaScriptedEffect*> Effects;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Effects")
	UPrimaryDataAsset* InstigatorIdentity;
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	
#endif
};



UCLASS(DisplayName="🤜 - Condition?")
class OMEGADEMO_API UFlowNode_Combatant_Condition : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	UFlowNode_Combatant_Condition();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
	UPROPERTY(BlueprintReadWrite, Instanced,EditAnywhere, Category="Combatant")
	TArray<UOmegaCondition_Combatant*> Conditions;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	
#endif
};



UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_Combatant_ParamBASE : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
	
	
	UFUNCTION() TArray<FName> L_GetParams() const;
public:
	
	uint8 ParamType=0;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant",meta=(GetOptions="L_GetParams")) FName Param;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;

	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override
	{
		if (ParamType==0) { OutColor=FLinearColor(FColor::Red); }
		else if (ParamType==1) { OutColor=FLinearColor(FColor::Green); }
		else { OutColor=FLinearColor(FColor::White); }
		 
		return true;
	};
	
#endif
};

// ========================================================================================================
// BOOL
// ========================================================================================================

UCLASS(DisplayName="🤜 (Bool) - Edit")
class OMEGADEMO_API UFlowNode_Combatant_ParamBool_Edit : public UFlowNode_Combatant_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_Combatant_ParamBool_Edit();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") bool Value;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🤜 (Bool) - Check?")
class OMEGADEMO_API UFlowNode_Combatant_ParamBool_Check : public UFlowNode_Combatant_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_Combatant_ParamBool_Check();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

// ========================================================================================================
// INT
// ========================================================================================================

UCLASS(DisplayName="🤜 (Int32) - Edit")
class OMEGADEMO_API UFlowNode_Combatant_ParamInt_Edit : public UFlowNode_Combatant_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_Combatant_ParamInt_Edit();
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") int32 Value;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit") bool bAdded;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🤜 (Int32) - Check?")
class OMEGADEMO_API UFlowNode_Combatant_ParamInt_Check : public UFlowNode_Combatant_ParamBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_Combatant_ParamInt_Check();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Check") int32 Value;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Check") TEnumAsByte<EOmegaComparisonMethod> Method;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

// ========================================================================================================
// Equipment
// ========================================================================================================

UCLASS(DisplayName="🤜 Equipment - Edit")
class OMEGADEMO_API UFlowNode_Combatant_Equip_Edit : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	virtual void L_Condition_Run(UCombatantComponent* Combatant) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="First") bool bClearAll;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="First",meta=(EditCondition="bClearAll")) UPrimaryDataAsset* CopyFrom;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect") TArray<UEquipmentSlot*> SlotsCleared;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effect") TMap<UEquipmentSlot*, UPrimaryDataAsset*> EquipmentAdded;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🤜 Equipment - Check?")
class OMEGADEMO_API UFlowNode_Combatant_Equip_Check : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
	
public:
	UFlowNode_Combatant_Equip_Check();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TArray<UEquipmentSlot* > SlotsToCheck;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TArray<UPrimaryDataAsset*> Accepted_Items;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TArray<UPrimaryDataAsset*> Rejected_Items;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

// ========================================================================================================
// Inventory
// ========================================================================================================

UCLASS(DisplayName="🤜 Inventory - Edit")
class OMEGADEMO_API UFlowNode_Combatant_Inv_Edit : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	virtual void L_Condition_Run(UCombatantComponent* Combatant) override;
		
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="First") bool bClearAll;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="First",meta=(EditCondition="bClearAll")) UPrimaryDataAsset* CopyFrom;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Inventory") TMap<UPrimaryDataAsset*, int32> Given_Items;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Inventory") bool bGiven_Added=true;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Inventory") TArray<UPrimaryDataAsset*> Bulk_Items;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Inventory") int32 Bulk_Amount;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🤜 Inventory - Check?")
class OMEGADEMO_API UFlowNode_Combatant_Inv_Check : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	UFlowNode_Combatant_Inv_Check();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TMap<UPrimaryDataAsset*, int32> MinimumItems;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

// ========================================================================================================
// XP
// ========================================================================================================

UCLASS(DisplayName="🤜 XP - Edit")
class OMEGADEMO_API UFlowNode_Combatant_XP_Edit : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	virtual void L_Condition_Run(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="XP") TMap<UOmegaLevelingAsset*,float> XP_Added;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="XP") TMap<UOmegaLevelingAsset*,int32> Levels_Set;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🤜 Xp - Level Check?")
class OMEGADEMO_API UFlowNode_Combatant_XP_Check : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	UFlowNode_Combatant_XP_Check();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="XP") UOmegaLevelingAsset* LevelingAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") TEnumAsByte<EOmegaComparisonMethod> Method;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combatant") int32 CheckLevel;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

// ========================================================================================================
// Skills
// ========================================================================================================

UCLASS(DisplayName="🤜 Skills - Edit")
class OMEGADEMO_API UFlowNode_Combatant_Skills_Edit : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	virtual void L_Condition_Run(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skills") bool bRemoveAllFirst;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skills",meta=(EditCondition="!bRemoveAllFirst")) TArray<UPrimaryDataAsset*> Skills_Removed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skills") TArray<UPrimaryDataAsset*> Skills_Added;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};

UCLASS(DisplayName="🤜 Skills - Check?")
class OMEGADEMO_API UFlowNode_Combatant_Skills_Check : public UFlowNode_CombatantBASE
{
	GENERATED_BODY()
public:
	UFlowNode_Combatant_Skills_Check();
	virtual bool L_Condition_Check(UCombatantComponent* Combatant) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skills") TArray<UPrimaryDataAsset*> RequiredSkills;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skills") bool bRequireAllSkills=true;
	
#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
};
