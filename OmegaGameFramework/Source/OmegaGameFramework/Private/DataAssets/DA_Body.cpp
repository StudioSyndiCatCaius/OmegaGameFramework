// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_Body.h"

#include "SkeletalMergingLibrary.h"

FOmegaBodyOptionValue FOmegaBodyOptionValue::FromBodyData(FOmegaBodyAppearanceData data,FName s)
{
	FOmegaBodyOptionValue _val;
	_val.value_float=UOmegaBodyFunctions::GetBodyDataParam_float(data,s);
	_val.value_color=UOmegaBodyFunctions::GetBodyDataParam_Color(data,s);
	_val.value_vector=UOmegaBodyFunctions::GetBodyDataParam_Vector(data,s);
	return _val;
}

void UOmegaBodyType::Post_CompMod(USkeletalMeshComponent* comp,FOmegaBodyAppearanceData data)
{
	if(comp)
	{
		TArray<FSkeletalMaterial> skm=comp->GetSkeletalMeshAsset()->GetMaterials();
		//fix materials
		for(FSkeletalMaterial m : skm)
		{
			comp->SetMaterial(skm.Find(m),m.MaterialInterface);
		}
		TArray<FName> slot_names;
		TArray<UOmegaBodySlot*> _slots;
		BodySlots.GenerateValueArray(_slots);
		BodySlots.GetKeys(slot_names);
		//get meshes from slots
		for(FName n : slot_names)
		{
			if(BodySlots.Contains(n))
			{
				BodySlots[n]->PostComponentEdit(comp,FOmegaBodyOptionValue::FromBodyData(data,n));
			}
		}
	}
}

FOmegaBodyAppearanceData UOmegaBodyType::GenerateData_FromSeed(int32 seed)
{
	FOmegaBodyAppearanceData _data;
	TArray<FName> slot_names;
	BodySlots.GetKeys(slot_names);
	for(FName n : slot_names)
	{
		if(BodySlots.Contains(n))
		{
			if(UOmegaBodySlot* s=BodySlots[n])
			{
				FRandomStream stream=FRandomStream(seed+slot_names.Find(n));
				_data.params_float.Add(n,stream.RandRange(0,s->GetMaxValue().X));
			}
		}
	}
	return _data;
}

USkeletalMesh* UOmegaBodyType::GenerateMesh_FromParams(FOmegaBodyAppearanceData data)
{
	if(BaseSkeleton)
	{
		FOmegaBodyAppearanceData _data=data;
		FSkeletalMeshMergeParams MergeParams;
		TArray<USkeletalMesh*> mesh_list;

		TArray<FName> slot_names;
		TArray<UOmegaBodySlot*> _slots;
		BodySlots.GenerateValueArray(_slots);
		BodySlots.GetKeys(slot_names);
		//get meshes from slots
		for(FName n : slot_names)
		{
			if(BodySlots.Contains(n))
			{
				if(UOmegaBodySlot* s=BodySlots[n])
				{
					if(USkeletalMesh* m=s->GetMeshFromIndex(FOmegaBodyOptionValue::FromBodyData(data,n)))
					{
						if(m->GetSkeleton())
						{
							mesh_list.Add(m);	
						}
					}
				}
			}
		}
		
		//merge meshes
		MergeParams.Skeleton=BaseSkeleton;
		MergeParams.MeshesToMerge=mesh_list;
		
		if(USkeletalMesh* newm=USkeletalMergingLibrary::MergeMeshes(MergeParams))
		{
			for(FName s :slot_names)
			{
				if(BodySlots.Contains(s))
				{
					BodySlots[s]->PostMeshEdit(newm,FOmegaBodyOptionValue::FromBodyData(data,s));
				}
			}
			return newm;
		}
	}
	return nullptr;
}

USkeletalMesh* UOmegaBodyType::GenerateMesh_FromSeed(int32 seed)
{
	return GenerateMesh_FromParams(GenerateData_FromSeed(seed));
}

void UOmegaBodyType::GenerateOnComponent_FromParams(USkeletalMeshComponent* component, FOmegaBodyAppearanceData data)
{
	if(component)
	{
		if(USkeletalMesh* m=GenerateMesh_FromParams(data))
		{
			component->SetSkeletalMesh(m);
			Post_CompMod(component,data);
		}
	}
}

void UOmegaBodyType::GenerateOnComponent_FromSeed(USkeletalMeshComponent* component, int32 seed)
{
	if(component)
	{
		FOmegaBodyAppearanceData _data=GenerateData_FromSeed(seed);
		GenerateOnComponent_FromParams(component,_data);
	}
}

TArray<UOmegaBodySlot*> UOmegaBodyType::GetSlots() const
{
	TArray<UOmegaBodySlot*>	v;
	BodySlots.GenerateValueArray(v);
	return v;
}

FVector UOmegaBodySlot::GetDefaultValue()
{
	return FVector();
}

FVector UOmegaBodySlot::GetMaxValue() const
{
	if(Script) { return Script->GetMaxValue(); }
	return FVector();
}

EOmegaBodySlotType UOmegaBodySlot::GetSlotType()
{
	return EOmegaBodySlotType::BODYSLOT_BOOL;
}

USkeletalMesh* UOmegaBodySlot::GetMeshFromIndex(FOmegaBodyOptionValue OptionValue) const
{
	if(Script) { return Script->GetMeshFromIndex(OptionValue); }
	return nullptr;
}


bool UOmegaBodySlot::PostMeshEdit(USkeletalMesh* Mesh, FOmegaBodyOptionValue OptionValue) const
{
	if(Mesh && Script)
	{
		Script->PostMeshCreationEdit(Mesh,OptionValue);
		for(FSkeletalMaterial m : Mesh->GetMaterials())
		{
			Script->PostMaterialSlotEdit(Mesh,Mesh->GetMaterials().Find(m),m.MaterialSlotName,m.MaterialInterface,OptionValue);
		}
		return true;
	}
	return false;
}

bool UOmegaBodySlot::PostComponentEdit(USkeletalMeshComponent* Mesh, FOmegaBodyOptionValue OptionValue) const
{
	if(Mesh && Script)
	{
		Script->OnApplied_ToMeshComponent(Mesh,OptionValue);
		return true;
	}
	return false;
}

void UOmegaBodyFunctions::SetBodyDataParam_Int(FOmegaBodyAppearanceData& data, FName param, int32 Value)
{
	data.params_float.Add(param,Value);
}

void UOmegaBodyFunctions::SetBodyDataParam_float(FOmegaBodyAppearanceData& data, FName param, float Value)
{
	data.params_float.Add(param,Value);
}

void UOmegaBodyFunctions::SetBodyDataParam_Vector(FOmegaBodyAppearanceData& data, FName param, FVector Value)
{
	FString p_x=param.ToString()+".x";
	FString p_y=param.ToString()+".y";
	FString p_z=param.ToString()+".z";
	data.params_float.Add(FName(*p_x),Value.X);
	data.params_float.Add(FName(*p_y),Value.Z);
	data.params_float.Add(FName(*p_z),Value.Y);
}

void UOmegaBodyFunctions::SetBodyDataParam_Color(FOmegaBodyAppearanceData& data, FName param, FLinearColor Value)
{
	FString p_r=param.ToString()+".r";
	FString p_g=param.ToString()+".g";
	FString p_b=param.ToString()+".b";
	FString p_a=param.ToString()+".a";
	data.params_float.Add(FName(*p_r),Value.R);
	data.params_float.Add(FName(*p_g),Value.G);
	data.params_float.Add(FName(*p_b),Value.B);
	data.params_float.Add(FName(*p_a),Value.A);
}

void UOmegaBodyFunctions::SetBodyDataParam_bool(FOmegaBodyAppearanceData& data, FName param, bool Value)
{
	data.params_float.Add(param,Value);
}

int32 UOmegaBodyFunctions::GetBodyDataParam_Int(FOmegaBodyAppearanceData data, FName param)
{
	FOmegaBodyAppearanceData _d=data;
	return _d.params_float.FindOrAdd(param);
}

float UOmegaBodyFunctions::GetBodyDataParam_float(FOmegaBodyAppearanceData data, FName param)
{
	FOmegaBodyAppearanceData _d=data;
	return _d.params_float.FindOrAdd(param);
}

FVector UOmegaBodyFunctions::GetBodyDataParam_Vector(FOmegaBodyAppearanceData data, FName param)
{
	FVector out;
	FOmegaBodyAppearanceData _d=data;
	FString p_x=param.ToString()+".x";
	FString p_y=param.ToString()+".y";
	FString p_z=param.ToString()+".z";
	out.X=_d.params_float.FindOrAdd(FName(*p_x));
	out.Y=_d.params_float.FindOrAdd(FName(*p_y));
	out.Z=_d.params_float.FindOrAdd(FName(*p_z));
	return out;
}

FLinearColor UOmegaBodyFunctions::GetBodyDataParam_Color(FOmegaBodyAppearanceData data, FName param)
{
	FLinearColor out;
	FOmegaBodyAppearanceData _d=data;
	FString p_x=param.ToString()+".r";
	FString p_y=param.ToString()+".g";
	FString p_z=param.ToString()+".b";
	FString p_a=param.ToString()+".a";
	out.R=_d.params_float.FindOrAdd(FName(*p_x));
	out.G=_d.params_float.FindOrAdd(FName(*p_y));
	out.B=_d.params_float.FindOrAdd(FName(*p_z));
	out.A=_d.params_float.FindOrAdd(FName(*p_a));
	return out;
}

bool UOmegaBodyFunctions::GetBodyDataParam_bool(FOmegaBodyAppearanceData data, FName param)
{
	FOmegaBodyAppearanceData _d=data;
	float _f=_d.params_float.FindOrAdd(param);
	return static_cast<bool>(_f);
}
