// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Component_Skin.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Animation/AnimInstance.h"
#include "SkeletalMergingLibrary.h"
#include "Engine/SkeletalMesh.h"
#include "Materials/MaterialInstanceDynamic.h"


USkinComponent::USkinComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bAutoActivate=true;
	//ChildActorTarget.OtherActor=GetOwner();
}

void USkinComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USkinComponent::Deactivate()
{
	if(GetSkin())
	{
		GetSkin()->K2_DestroyActor();
	}
	Super::Deactivate();
}

void USkinComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkinComponent::Update_Skin()
{
	if(!Skin || !IsActive())
	{
		return;
	}
	
	//Set mesh from character if not set already
	if(!REF_SkelMesh)
	{
		if(const ACharacter* charRef = Cast<ACharacter>(GetOwner()))
		{
			REF_SkelMesh=charRef->GetMesh();
		}
	}

	if(Appearance.BodyType && Appearance.BodyType->DefaultSkin)
	{
		Skin=Appearance.BodyType->DefaultSkin;
	}
	if(REF_SkelMesh)
	{
		const FTransform& temp_trans = REF_SkelMesh->GetRelativeTransform();

		//if child actor valid
		if(REF_skinComponent)
		{
			//If no skin actor OR class oes not match input class
			if(!GetSkin() || GetSkin()->GetClass()!=Skin)
			{
				REF_skinComponent->SetChildActorClass(Skin);
			}
			//REF_skinComponent->SetRelativeTransform(temp_trans);
			if(GetSkin())
			{
				GetSkin()->owning_component=this;
				GetSkin()->BuildSkin();
				if(GetSkin()->bIsCompressedSkin)
				{
					REF_skinComponent->SetChildActorClass(nullptr);
				}
			}
		}
		
		TArray<UOmegaBodySlot*> BodySlot_List;
		Appearance.Params.GetKeys(BodySlot_List);
		for(auto* i : BodySlot_List)
		{
			if(i && i->Script)
			{
				FVector in_val=Appearance.Params.FindOrAdd(i);
				if(GetSkin())
				{
					i->Script->OnApplied_ToSkin(GetSkin(),in_val);
				}
				i->Script->OnApplied_ToMeshComponent(REF_SkelMesh,in_val);
			}
		}
	}
}

void USkinComponent::SetupLinkedComponents(USkeletalMeshComponent* SkeletalMesh, UChildActorComponent* ChildActor)
{
	if(SkeletalMesh) {REF_SkelMesh=SkeletalMesh;}
	if(ChildActor) {REF_skinComponent=ChildActor;}
}

void USkinComponent::SetLinkedChildActorComponent(UChildActorComponent* LinkedComp)
{
	if(LinkedComp)
	{
		REF_skinComponent=LinkedComp;
	}
}

AOmegaSkin* USkinComponent::SetSkin(TSubclassOf<AOmegaSkin> SkinClass)
{
	Skin=SkinClass;
	Assemble();
	return GetSkin();
}

AOmegaSkin* USkinComponent::GetSkin() const
{
	if (REF_skinComponent && REF_skinComponent->GetChildActor())
	{
		return Cast<AOmegaSkin>(REF_skinComponent->GetChildActor());
	}
	return nullptr;
}

void USkinComponent::Assemble(USkeletalMeshComponent* OverrideMesh)
{
	if(OverrideMesh)
	{
		REF_SkelMesh=OverrideMesh;
	}
	Update_Skin();
}

void USkinComponent::SetBodyAppearanceData(FOmegaBodyAppearanceInfo AppearanceData)
{
	Appearance=AppearanceData;
	Update_Skin();
}

void USkinComponent::SetBody_Type(UOmegaBodyType* BodyType)
{
	if(BodyType) {Appearance.BodyType=BodyType;}
	Update_Skin();
}

UOmegaBodyType* USkinComponent::GetBody_Type() const
{
	if(Appearance.BodyType) { return Appearance.BodyType; } return nullptr;
}

void USkinComponent::SetBodyParam_Vector(UOmegaBodySlot* Param, FVector Value)
{
	Appearance.Params.Add(Param,Value);
	Update_Skin();
}

FVector USkinComponent::GetBodyParam_Vector(UOmegaBodySlot* Param)
{
	return Appearance.Params.FindOrAdd(Param);
}

void USkinComponent::SetBodyParam_Bool(UOmegaBodySlot* Param, bool Value)
{
	SetBodyParam_Vector(Param,FVector(Value,0,0));
}

bool USkinComponent::GetBodyParam_Bool(UOmegaBodySlot* Param)
{
	return static_cast<bool>(GetBodyParam_Vector(Param).X);
}

void USkinComponent::SetBodyParam_Int(UOmegaBodySlot* Param, int32 Value)
{
	SetBodyParam_Vector(Param,FVector(Value,0,0));
}

int32 USkinComponent::GetBodyParam_Int(UOmegaBodySlot* Param)
{
	return GetBodyParam_Vector(Param).X;
}

void USkinComponent::SetBodyParam_Float(UOmegaBodySlot* Param, float Value)
{
	SetBodyParam_Vector(Param,FVector(Value,0,0));
}

float USkinComponent::GetBodyParam_Float(UOmegaBodySlot* Param)
{
	return GetBodyParam_Vector(Param).X;
}

UMaterialInstanceDynamic* USkinModifier::CreateDynamicMaterial_FromSlot(USkeletalMeshComponent* MeshComp, FName Slot,
                                                                        bool ApplyToComponent)
{
	if(MeshComp)
	{
		if(MeshComp->GetMaterialSlotNames().Contains(Slot))
		{
			int32 mat_index = MeshComp->GetMaterialSlotNames().Find(Slot);
			UMaterialInterface* current_mat = MeshComp->GetMaterial(mat_index);
			UMaterialInstanceDynamic* new_mat;
			if(current_mat->GetClass()->IsChildOf(UMaterialInstanceDynamic::StaticClass()))
			{
				new_mat=Cast<UMaterialInstanceDynamic>(current_mat);
			}
			else
			{
				new_mat = MeshComp->CreateDynamicMaterialInstance(mat_index,MeshComp->GetMaterial(mat_index));
			}
			if(ApplyToComponent)
			{
				MeshComp->SetMaterial(mat_index,new_mat);
			}
			return new_mat;
		}
	}
	return nullptr;
}

void USkinModifier::ApplyModifier_Implementation(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent)
{
}

void USkinModifier_DynamicMaterial::ApplyModifierMaterial_Implementation(AOmegaSkin* Skin,
	USkeletalMeshComponent* MeshComponent, UMaterialInstanceDynamic* Material)
{
}

void USkinModifier_DynamicMaterial::ApplyModifier_Implementation(AOmegaSkin* Skin,
	USkeletalMeshComponent* MeshComponent)
{
	TArray<FName> target_slots = SlotsAppliedTo;
	if(SlotsAppliedTo.IsEmpty())
	{
		target_slots=MeshComponent->GetMaterialSlotNames();
	}
	for(FName mat_slot : target_slots)
	{
		UMaterialInstanceDynamic* new_mat = CreateDynamicMaterial_FromSlot(MeshComponent,mat_slot,true);
		ApplyModifierMaterial(Skin,MeshComponent,new_mat);
	}
}

USkeletalMesh* UOmegaSkinFunctions::MergeMeshes_Omega(TArray<USkeletalMesh*> Meshes, USkeletalMesh* BaseMesh)
{
	if(BaseMesh)
	{
		FSkeletalMeshMergeParams MergeParams;
		
		MergeParams.Skeleton = BaseMesh->GetSkeleton();
		
		for(auto* TempMesh : Meshes)
		{
			if(TempMesh && TempMesh->GetSkeleton()==MergeParams.Skeleton)
			{
				MergeParams.MeshesToMerge.Add(TempMesh);
			}
		}
		return USkeletalMergingLibrary::MergeMeshes(MergeParams);
		
	}
	
	return nullptr;
}

USkeletalMesh* UOmegaSkinFunctions::MergeComponentMeshes_Omega(TArray<USkeletalMeshComponent*> Meshes,
	USkeletalMesh* BaseMesh)
{
	TArray<USkeletalMesh*> IncomingMeshes;
	for(const auto* TempMesh : Meshes)
	{
		if(TempMesh)
		{
			IncomingMeshes.Add(TempMesh->GetSkeletalMeshAsset());
		}
	}
	return MergeMeshes_Omega(IncomingMeshes,BaseMesh);
}

void UOmegaSkinFunctions::SetSkinFromAsset(USkinComponent* SkinComponent, UObject* SourceAsset)
{
	if(SkinComponent && SourceAsset && SourceAsset->GetClass()->ImplementsInterface(UDataInterface_SkinSource::StaticClass()))
	{
		SkinComponent->SetSkin(IDataInterface_SkinSource::Execute_GetSkinClass(SourceAsset));
		if(SkinComponent->GetSkin())
		{
			SkinComponent->GetSkin()->SkinModifiers.Append(IDataInterface_SkinSource::Execute_GetSkinModifiers(SourceAsset));
		}
	}
}

AOmegaSkin::AOmegaSkin()
{
	bForceFollowMasterComponent=true;
	// Load the material asset at runtime
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BlankMaterial(TEXT("/OmegaGameFramework/Materials/m_Blank.m_Blank"));
	MasterSkeletonOverrideMaterial = BlankMaterial.Object;

}

void AOmegaSkin::OnConstruction(const FTransform& Transform)
{
	BuildSkin();
	Super::OnConstruction(Transform);
}

void AOmegaSkin::TrySetAnimation(USkeletalMeshComponent* TargetMesh)
{
	if(TargetMesh && AnimationClass && TargetMesh->GetAnimationMode()==EAnimationMode::Type::AnimationBlueprint)
	{
		TargetMesh->SetAnimInstanceClass(AnimationClass);
	}
}

void AOmegaSkin::local_applyModifiers(USkeletalMeshComponent* MeshComp)
{
	if(MeshComp)
	{
		for(auto* TempMod : SkinModifiers)
		{
			if(TempMod)
			{
				TempMod->ApplyModifier(this, MeshComp);
			}
		}
	}
}

USkeletalMeshComponent* AOmegaSkin::GetCompressedMeshComponent_Implementation()
{
	if(UActorComponent* out = GetComponentByClass(USkeletalMeshComponent::StaticClass()))
	{
		return Cast<USkeletalMeshComponent>(out);
	}
	return nullptr;
}

USkeletalMeshComponent* AOmegaSkin::GetMeshComponentBySlot_Implementation(FGameplayTag Slot)
{
	return nullptr;
}

void AOmegaSkin::BuildSkin()
{
	if(owning_component && owning_component->GetTargetMesh())
	{
		USkeletalMeshComponent* TargetMesh = owning_component->GetTargetMesh();

		if(bIsCompressedSkin)
		{
			if(GetCompressedMeshComponent())
			{
				TargetMesh->SetSkeletalMesh(GetCompressedMeshComponent()->GetSkeletalMeshAsset());
				TArray<UMaterialInterface*> mat_list = GetCompressedMeshComponent()->GetMaterials();
				for(UMaterialInterface* Mat : mat_list)
				{
					TargetMesh->SetMaterial(mat_list.Find(Mat),Mat);
				}
				//TargetMesh->SetRelativeLocation(GetCompressedMeshComponent()->GetRelativeLocation());
				TargetMesh->SetRelativeScale3D(GetCompressedMeshComponent()->GetRelativeScale3D());
				TrySetAnimation(TargetMesh);
			}
			return;
		}
		
		// create merged mesh
		if(!MasterSkeleton)
		{
			return;
		}

		FSkeletalMeshMergeParams MergeParams;
		MergeParams.Skeleton=MasterSkeleton->GetSkeleton();
		for(auto* tempComp : GetMeshMergeComponents())
		{
			if (tempComp && tempComp->GetSkeletalMeshAsset() && tempComp->GetSkeletalMeshAsset()->GetSkeleton()==MasterSkeleton->GetSkeleton())
			{
				MergeParams.MeshesToMerge.Add(tempComp->GetSkeletalMeshAsset());
			}
		}

		USkeletalMesh* new_mesh=USkeletalMergingLibrary::MergeMeshes(MergeParams);
		
		// Apply mesh
		if(bMerge && new_mesh)
		{
			TargetMesh->SetSkeletalMeshAsset(new_mesh);
			local_applyModifiers(TargetMesh);
			//Clean Mesh
			for(auto* tempComp : GetMeshMergeComponents())
			{
				tempComp->DestroyComponent();
			}
		}
		else
		{
			if(MasterSkeleton)
			{
				TargetMesh->SetSkeletalMeshAsset(MasterSkeleton);
				if(MasterSkeletonOverrideMaterial)
				{
					for (int i = 0; i < TargetMesh->GetMaterials().Num(); ++i)
					{
						TargetMesh->SetMaterial(i,MasterSkeletonOverrideMaterial);
					}
				}
			}
			if(bForceFollowMasterComponent)
			{
				for(auto* tempComp : GetMeshMergeComponents())
				{
					if(tempComp)
					{
						tempComp->SetLeaderPoseComponent(TargetMesh,true);
						local_applyModifiers(tempComp);
					}
					
				}
			}
			if(bHideBaseMesh)
			{
				//charRef->GetMesh()->SetHiddenInGame(true);
				//add blank material here
			}
		}
		//Set Anim Instance
		TrySetAnimation(TargetMesh);
	}
	else //Typicall for preview only
	{
		for(auto* tempComp : GetMeshMergeComponents())
		{
			if (tempComp && AnimationClass)
			{
				tempComp->SetAnimInstanceClass(AnimationClass);
				local_applyModifiers(tempComp);
			}
		}
	}
	OnSkinBuildFinished();
}

FVector UOmegaBodySlot::GetDefaultValue()
{

	return FVector();
}

FVector UOmegaBodySlot::GetMaxValue()
{
	if(Script)
	{
		return Script->GetMaxValue();
	}
	return FVector(1,0,0);
}

EOmegaBodySlotType UOmegaBodySlot::GetSlotType()
{
	if(Script)
	{
		return Script->GetScriptSlotType();
	}
	return EOmegaBodySlotType::BODYSLOT_INTEGER;
}

TArray<USkeletalMeshComponent*> AOmegaSkin::GetMeshMergeComponents_Implementation()
{
	TArray<USkeletalMeshComponent*> out;

	for(auto* TempComp : K2_GetComponentsByClass(USkeletalMeshComponent::StaticClass()))
	{
		out.Add(Cast<USkeletalMeshComponent>(TempComp));
	}
	return out;
}

