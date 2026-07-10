// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Object.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "Functions/F_Common.h"


FLuaValue* FOmegaObjectMeta::ValidateMeta(UObject* WorldContext, UObject* TargetObject)
{
	if (TargetObject)
	{
		if (ObjectMap.Contains(TargetObject))
		{
			return &ObjectMap[TargetObject];
		}
		if (WorldContext)
		{
			FLuaValue new_tbl=ULuaBlueprintFunctionLibrary::LuaCreateTable(WorldContext,nullptr);
			ObjectMap.Add(TargetObject,new_tbl);
			return &ObjectMap[TargetObject];
		}
	}
	return nullptr;
}

FLuaValue FOmegaObjectMeta::GetParam(UObject* WC, UObject* obj, FName param)
{
	if (FLuaValue* l=ValidateMeta(WC,obj))
	{
		FLuaValue out=l->GetField(param.ToString());
		return out;
	}
	return FLuaValue();
}

const float UOmegaObjectUtilityScript::CheckUtility_Implementation(UObject* Object, FGameplayTag Utility,
	FOmegaCommonMeta meta)
{
	return 0.0f;
}

TArray<UObject*> UOmegaObjectFunctions::FilterObjectArray(const TArray<UObject*>& Objects,
                                                          FObjectFilterDelegate FilterDelegate)
{
	TArray<UObject*> Result;

	if (!FilterDelegate.IsBound()) return Objects; // passthrough if unbound

	for (UObject* Obj : Objects)
	{
		if (FilterDelegate.Execute(Obj))
		{
			Result.Add(Obj);
		}
	}

	return Result;
}

TArray<UObject*> UOmegaObjectFunctions::SortObjectArray(const TArray<UObject*>& Objects,
	FObjectSortDelegate SortDelegate)
{
	TArray<UObject*> Result = Objects;

	if (!SortDelegate.IsBound()) return Result; // passthrough if unbound

	Result.Sort([&SortDelegate](UObject& A, UObject& B)
	{
		return SortDelegate.Execute(&A, &B);
	});

	return Result;
}

UObject* UOmegaObjectFunctions::SelectObjectByWeight(
	const TArray<UObject*>& Objects,
	FObjectFloatCompareDelegate CheckDelegate, bool bReverse, float RandomOffsetRange)
{
	if (Objects.IsEmpty()) return nullptr;
	if (!CheckDelegate.IsBound()) return Objects[0];

	UObject* BestObject = nullptr;
	float BestScore = bReverse ? TNumericLimits<float>::Max() : TNumericLimits<float>::Lowest();

	for (UObject* A : Objects)
	{
		float Score = 0.f;
		for (UObject* B : Objects)
		{
			if (A != B)
			{
				Score += CheckDelegate.Execute(A, B);
			}
		}
		Score += FMath::FRandRange(-RandomOffsetRange, RandomOffsetRange);

		const bool bBetter = bReverse ? (Score < BestScore) : (Score > BestScore);
		if (bBetter)
		{
			BestScore = Score;
			BestObject = A;
		}
	}

	return BestObject;
}

UObject* UOmegaObjectFunctions::SelectObjectByUtilityAsset(
	const TArray<UObject*>& Objects,
	UOmegaObjectUtilityAsset* ScriptAsset, FGameplayTag UtilityTag, FOmegaCommonMeta meta,
	float& SelectedUtility, float& AverageUtility)
{
	SelectedUtility = 0.f;
	AverageUtility = 0.f;

	if (Objects.IsEmpty()) return nullptr;
	if (!ScriptAsset) return Objects[0];

	UObject* BestObject = nullptr;
	float BestSelectionScore = ScriptAsset->bReverse ? TNumericLimits<float>::Max() : TNumericLimits<float>::Lowest();
	float BestRawScore = 0.f;
	float TotalRawScore = 0.f;

	for (UObject* Obj : Objects)
	{
		float RawScore = 0.f;
		for (UOmegaObjectUtilityScript* Script : ScriptAsset->Scripts)
		{
			if (Script)
			{
				RawScore += Script->CheckUtility(Obj, UtilityTag, meta)*Script->ScaleWeight;
				if (Script->bInvert)
				{
					RawScore =1-RawScore ;
				}
			}
		}
		TotalRawScore += RawScore;

		const float SelectionScore = RawScore + FMath::FRandRange(-ScriptAsset->RandomOffsetRange, ScriptAsset->RandomOffsetRange);
		const bool bBetter = ScriptAsset->bReverse ? (SelectionScore < BestSelectionScore) : (SelectionScore > BestSelectionScore);
		if (bBetter)
		{
			BestSelectionScore = SelectionScore;
			BestRawScore = RawScore;
			BestObject = Obj;
		}
	}

	SelectedUtility = BestRawScore;
	AverageUtility = TotalRawScore / static_cast<float>(Objects.Num());
	return BestObject;
}

void UOmegaObjectFunctions::Rename_Object(UObject* object, FString NewName)
{
	if(object)
	{
		object->Rename(*NewName);
	}
}

UObject* UOmegaObjectFunctions::Duplicate_Object(UObject* object,UObject* NewOuter, UClass* Class)
{
	if(object && Class && NewOuter)
	{
		UObject* new_obj=DuplicateObject(object,NewOuter);
		if(new_obj && new_obj->GetClass()==Class)
		{
			return new_obj;
		}
	}
	return nullptr;
}


UObject* UOmegaObjectFunctions::RunSelector_Object(UObject* WorldContextObject, FOmegaSelect_Object Selector)
{
	if(WorldContextObject && Selector.Selector)
	{
		return Selector.Selector->GetSelected_Obj(WorldContextObject);
	}
	return nullptr;
}

UPrimaryDataAsset* UOmegaObjectFunctions::RunSelector_DataAsset(UObject* WorldContextObject,
	FOmegaSelect_DataAsset Selector)
{
	if(WorldContextObject && Selector.Selector)
	{
		return Selector.Selector->Get_DataAsset(WorldContextObject);
	}
	return nullptr;
}

bool UOmegaObjectFunctions::CheckCondition_DataAsset(UPrimaryDataAsset* Asset, FOmegaConditions_DataAsset Selector,TArray<FText>& Reasons)
{
	if(Asset)
	{
		return Selector.CheckConditions(Asset,Reasons);
	}
	return false;
}

TArray<UObject*> UOmegaObjectFunctions::Conv_InterfaceArrayToObjects(TArray<TScriptInterface<IInterface>> Interfaces,
	TSubclassOf<UObject> FilterClass)
{
	TArray<UObject*> Result;
	for (const TScriptInterface<IInterface>& Entry : Interfaces)
	{
		UObject* Obj = Entry.GetObject();
		if (!Obj) continue;

		if (!FilterClass || Obj->IsA(FilterClass))
		{
			Result.Add(Obj);
		}
	}
	return Result;
}


void UOmegaObjectFunctions::Object_TagEvent(UObject* Object, FGameplayTag Event, FOmegaCommonMeta meta)
{
	if (UOmegaGameFrameworkBPLibrary::Object_UsesCommonInterface(Object))
	{
		IDataInterface_General::Execute_Tag_Event(Object, Event, meta);
	}
}

bool UOmegaObjectFunctions::Object_TagQuery(UObject* Object, FGameplayTag Event, FOmegaCommonMeta meta)
{
	if (UOmegaGameFrameworkBPLibrary::Object_UsesCommonInterface(Object))
	{
		return IDataInterface_General::Execute_Tag_Query(Object,Event,meta);
	}
	return false;
}

float UOmegaObjectFunctions::Object_TagUtility(UObject* Object, FGameplayTag Event, FOmegaCommonMeta meta)
{
	if (UOmegaGameFrameworkBPLibrary::Object_UsesCommonInterface(Object))
	{
		return IDataInterface_General::Execute_Tag_Utility(Object,Event,meta);
	}
	return 0.0;
}



UObject* UOmegaObjectFunctions::Object_SelectByTagUtility(TArray<UObject*> Objects, FGameplayTag Event,
	FOmegaCommonMeta meta, bool bReverse, float RandomOffsetRange)
{
	if (Objects.IsEmpty()) return nullptr;

	UObject* BestObject = nullptr;
	float BestScore = bReverse ? TNumericLimits<float>::Max() : TNumericLimits<float>::Lowest();

	for (UObject* Obj : Objects)
	{
		float Score = Object_TagUtility(Obj, Event, meta);
		Score += FMath::FRandRange(-RandomOffsetRange, RandomOffsetRange);

		const bool bBetter = bReverse ? (Score < BestScore) : (Score > BestScore);
		if (bBetter)
		{
			BestScore = Score;
			BestObject = Obj;
		}
	}

	return BestObject;
}

FLuaValue UOmegaObjectFunctions::Meta_GetTable(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		return *l;
	}
	return FLuaValue();
}

void UOmegaObjectFunctions::Meta_SetBool(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param,
                                         bool NewValue)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		l->SetField(param.ToString(), NewValue);
	}
}

void UOmegaObjectFunctions::Meta_SetInt(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param,
	int32 NewValue)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		l->SetField(param.ToString(), NewValue);
	}
}

void UOmegaObjectFunctions::Meta_SetFloat(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param,
	float NewValue)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		l->SetField(param.ToString(), NewValue);
	}
}

bool UOmegaObjectFunctions::Meta_GetBool(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param, bool Fallback)
{
	FLuaValue l=Meta.GetParam(WorldContextObject,Object,param);
	if (!l.IsNil())
	{
		return l.ToBool();
	}
	return Fallback;
}

int32 UOmegaObjectFunctions::Meta_GetInt(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param, int32 Fallback)
{
	FLuaValue l=Meta.GetParam(WorldContextObject,Object,param);
	if (!l.IsNil())
	{
		return l.ToInteger();
	}
	return Fallback;
}

float UOmegaObjectFunctions::Meta_GetFloat(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param, float Fallback)
{
	FLuaValue l=Meta.GetParam(WorldContextObject,Object,param);
	if (!l.IsNil())
	{
		return l.ToFloat();
	}
	return Fallback;
}

FString UOmegaObjectFunctions::GetNameParam_String(UObject* Object, uint8 param)
{
	if (Object)
	{
		TArray<FString> _vars;
		Object->GetName().ParseIntoArray(_vars,TEXT("_"),false);
		if (_vars.IsValidIndex(param))
		{
			return _vars[param];
		}
	}
	return "";
}

int32 UOmegaObjectFunctions::GetNameParam_Int(UObject* Object, uint8 param)
{
	return FCString::Atoi(*GetNameParam_String(Object,param));
}
