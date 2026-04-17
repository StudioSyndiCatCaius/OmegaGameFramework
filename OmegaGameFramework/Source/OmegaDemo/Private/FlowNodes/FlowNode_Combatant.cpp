// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Combatant.h"

#include "FlowAsset.h"
#include "FlowMacros.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Functions/F_Common.h"
#include "Functions/F_Math.h"
#include "Functions/F_ScriptedEffects.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Macros.h"

void UFlowNode_CombatantBASE::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	L_Condition_Do();
}

UCombatantComponent* UFlowNode_CombatantBASE::L_AssetToCombatant(UPrimaryDataAsset* asset) const
{
	if (GetFlowAsset())
	{
		if (AActor* _actor=GetFlowAsset()->GetActorByBinding_Asset(asset,true))
		{
			if (UCombatantComponent* _comp=Cast<UCombatantComponent>(_actor->GetComponentByClass(UCombatantComponent::StaticClass())))
			{
				return _comp;
			}
		}
	}
	return nullptr;
}


void UFlowNode_CombatantBASE::L_Condition_Do()
{
	if (NodeType==0)
	{
		if (GetLinkedCombatant())
		{
			L_Condition_Run(GetLinkedCombatant());	
		}
		TriggerFirstOutput(true);
	}
	else if (NodeType==1)
	{
		bool _result=false;
        if (GetLinkedCombatant())
        {
        	_result=L_Condition_Check(GetLinkedCombatant());
        }
        if (_result)
        {
        	TriggerOutput(TEXT("true"),true);
        }
        else
        {
        	TriggerOutput(TEXT("false"),true);
        }
	}
	
}

UCombatantComponent* UFlowNode_CombatantBASE::GetLinkedCombatant() const
{
	return L_AssetToCombatant(ActorIdentity);
}


FSlateBrush UFlowNode_CombatantBASE::K2_GetNodeIcon_Implementation() const
{
	if(ActorIdentity)
	{
		FSlateBrush _brush=UOmegaGameFrameworkBPLibrary::GetObjectIcon(ActorIdentity,FGameplayTag());
		_brush.SetImageSize(FVector2D(50,50));
		return _brush;
	}
	return Super::K2_GetNodeIcon_Implementation();
}


UFlowNode_Combatant_Effects::UFlowNode_Combatant_Effects()
{
}

void UFlowNode_Combatant_Effects::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (UCombatantComponent* _comb=GetLinkedCombatant())
	{
		FOmegaCustomScriptedEffects ef;
		ef.CustomEffects=Effects;
		UOmegaScriptedEffectFunctions::ApplyCustomScriptedEffectToCombatant(ef,_comb,L_AssetToCombatant(InstigatorIdentity));
	}
	TriggerFirstOutput(true);
}

UFlowNode_Combatant_Condition::UFlowNode_Combatant_Condition()
{
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Combatant_Condition::L_Condition_Check(UCombatantComponent* Combatant)
{
	FOmegaConditions_Combatant cond;
	cond.Conditions=Conditions;
	return cond.CheckConditions(Combatant);
}


TArray<FName> UFlowNode_Combatant_ParamBASE::L_GetParams() const
{
	UCombatantComponent* _in=nullptr;
	if (UCombatantComponent* _comb=GetLinkedCombatant())
	{
		_in=_comb;
	}
	return OGF_GAME_CORE()->L_GetCombatantParamKeys(_in,ParamType);
	
}

// ========================================================================================================
// BOOL
// ========================================================================================================
UFlowNode_Combatant_ParamBool_Edit::UFlowNode_Combatant_ParamBool_Edit()
{
	ParamType= Value ? 1 : 0;
}

void UFlowNode_Combatant_ParamBool_Edit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (UCombatantComponent* _comb=GetLinkedCombatant())
	{
		_comb->EntityParam_Bool_Set(Param,Value);
	}
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_Combatant_ParamBool_Edit::GetNodeDescription() const
{
	FString str="SET: "+Param.ToString()+" = "+UKismetStringLibrary::Conv_BoolToString(Value);
	return *str;
}
#endif

UFlowNode_Combatant_ParamBool_Check::UFlowNode_Combatant_ParamBool_Check()
{
	ParamType=0;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Combatant_ParamBool_Check::L_Condition_Check(UCombatantComponent* Combatant)
{
	return Combatant->EntityParam_Bool_Get(Param);
}

#if WITH_EDITOR
FString UFlowNode_Combatant_ParamBool_Check::GetNodeDescription() const
{
	FString str="IF: "+Param.ToString()+" == true";
	return *str;
}
#endif

// ========================================================================================================
// INT
// ========================================================================================================
UFlowNode_Combatant_ParamInt_Edit::UFlowNode_Combatant_ParamInt_Edit()
{
	ParamType=1;
}

void UFlowNode_Combatant_ParamInt_Edit::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (UCombatantComponent* _comb=GetLinkedCombatant())
	{
		_comb->EntityParam_Int_Set(Param,Value,bAdded);
	}
	TriggerFirstOutput(true);
}
#if WITH_EDITOR
FString UFlowNode_Combatant_ParamInt_Edit::GetNodeDescription() const
{
	FString edit_str=" == ";
	if (bAdded) { edit_str=" += "; }
	FString str=Param.ToString()+edit_str+UKismetStringLibrary::Conv_IntToString(Value);
	return *str;
}
#endif

UFlowNode_Combatant_ParamInt_Check::UFlowNode_Combatant_ParamInt_Check()
{
	ParamType=1;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Combatant_ParamInt_Check::L_Condition_Check(UCombatantComponent* Combatant)
{
	return UOmegaMathFunctions::Compare_Int(Combatant->EntityParam_Int_Get(Param),Method,Value);
}
#if WITH_EDITOR
FString UFlowNode_Combatant_ParamInt_Check::GetNodeDescription() const
{
	FString edit_str=" == ";
	switch (Method)
	{
	case 0: edit_str=" == ";
	case 1: edit_str=" > ";
	case 2: edit_str=" < ";
	case 3: edit_str=" >= ";
	case 4: edit_str=" <= ";
	default: edit_str=" == ";
	}
	
	FString str=Param.ToString()+edit_str+UKismetStringLibrary::Conv_IntToString(Value);
	return *str;
}
#endif


// ========================================================================================================
// Equipment
// ========================================================================================================


void UFlowNode_Combatant_Equip_Edit::L_Condition_Run(UCombatantComponent* Combatant)
{
	if (bClearAll)
	{
		Combatant->Equipment_SetAll(TMap<UEquipmentSlot*,UPrimaryDataAsset*>());
		if (UCombatantComponent* _comb=L_AssetToCombatant(CopyFrom))
		{
			Combatant->Equipment_SetAll(_comb->Equipment_Get());
		}
	}
	
	
	for (auto* s : SlotsCleared)
	{
		if (s)
		{
			Combatant->Equipment_ClearSlot(s);
		}
	}
		
	TArray<UEquipmentSlot*> _slot;
	EquipmentAdded.GetKeys(_slot);
	for (auto* s : _slot)
	{
		if (s)
		{
			Combatant->Equipment_SetInSlot(EquipmentAdded.FindOrAdd(s),s);
		}
	}
}

UFlowNode_Combatant_Equip_Check::UFlowNode_Combatant_Equip_Check()
{
	NodeType=1;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Combatant_Equip_Check::L_Condition_Check(UCombatantComponent* Combatant)
{

	if (Combatant)
	{
		for (auto* SlotToCheck : SlotsToCheck)
		{
			if (SlotToCheck && Combatant)
			{
				bool _dumBool;
		
				//check if has at least one required item
				if (!Accepted_Items.IsEmpty() && !Accepted_Items.Contains(Combatant->Equipment_GetInSlot(SlotToCheck,_dumBool)))
				{
					return false;
				}
		
				//check if has NONE of rejected item
				if (!Rejected_Items.IsEmpty() && Rejected_Items.Contains(Combatant->Equipment_GetInSlot(SlotToCheck,_dumBool)))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

// ========================================================================================================
// Inventory
// ========================================================================================================

void UFlowNode_Combatant_Inv_Edit::L_Condition_Run(UCombatantComponent* Combatant)
{
	if (bClearAll)
	{
		Combatant->Inventory_Set(TMap<UPrimaryDataAsset*, int32>());
		if (UCombatantComponent* _comb=L_AssetToCombatant(CopyFrom))
		{
			Combatant->Inventory_Set(_comb->Inventory_Get());
		}
	}
	
	if (bGiven_Added)
	{
		Combatant->Inventory_AddList(Given_Items,false);	
	}
	else
	{
		Combatant->Inventory_Set(Given_Items);
	}
	
	for (auto* i : Bulk_Items)
	{
		if (i)
		{
			Combatant->Inventory_Add(i,Bulk_Amount);
		}
	}
	
}

UFlowNode_Combatant_Inv_Check::UFlowNode_Combatant_Inv_Check()
{
	NodeType=1;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Combatant_Inv_Check::L_Condition_Check(UCombatantComponent* Combatant)
{
	if (Combatant)
	{
		return Combatant->Inventory_HasMinimum(MinimumItems);
	}
	return false;
}

// ========================================================================================================
// XP
// ========================================================================================================

UFlowNode_Combatant_XP_Check::UFlowNode_Combatant_XP_Check()
{
	NodeType=1;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

void UFlowNode_Combatant_XP_Edit::L_Condition_Run(UCombatantComponent* Combatant)
{
	TArray<UOmegaLevelingAsset*> _levelingAssets;
	XP_Added.GetKeys(_levelingAssets);
	for (auto i : _levelingAssets)
	{
		if (i)
		{
			Combatant->XP_Set(i,XP_Added.FindOrAdd(i));
		}
	}
	
	Levels_Set.GetKeys(_levelingAssets);
	for (auto i : _levelingAssets)
	{
		if (i)
		{
			Combatant->XP_SetLevel(i,Levels_Set.FindOrAdd(i));
		}
	}
}

bool UFlowNode_Combatant_XP_Check::L_Condition_Check(UCombatantComponent* Combatant)
{
	if (Combatant && LevelingAsset)
	{
		return UOmegaMathFunctions::Compare_Int(Combatant->XP_GetLevel(LevelingAsset),Method,CheckLevel);
	}
	return false;
}

// ========================================================================================================
// Skills
// ========================================================================================================

void UFlowNode_Combatant_Skills_Edit::L_Condition_Run(UCombatantComponent* Combatant)
{
	Super::L_Condition_Run(Combatant);
}

UFlowNode_Combatant_Skills_Check::UFlowNode_Combatant_Skills_Check()
{
	NodeType=1;
	FLOW_SETUP_PINS_OUTPUT_BOOL()
}

bool UFlowNode_Combatant_Skills_Check::L_Condition_Check(UCombatantComponent* Combatant)
{
	for (auto* i : RequiredSkills)
	{
		if (i)
		{
			if (bRequireAllSkills!=Combatant->GetAllSkills().Contains(i))
			{
				return !bRequireAllSkills;
			}
		}
	}
	return bRequireAllSkills;
}
