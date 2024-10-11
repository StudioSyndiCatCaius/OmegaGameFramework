// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Component_Skin.h"
#include "GameFramework/Character.h"
#include "SkeletalMergingLibrary.h"
#include "Animation/Skeleton.h"

USkinComponent::USkinComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USkinComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USkinComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkinComponent::Update_Skin()
{
	const ACharacter* charRef = Cast<ACharacter>(GetOwner());
	if(!charRef)
	{
		return;
	}
	const FTransform& temp_trans = charRef->GetMesh()->GetRelativeTransform();
	if(!skinComponent)
	{
		skinComponent = Cast<UChildActorComponent>(GetOwner()->AddComponentByClass(UChildActorComponent::StaticClass(),false,temp_trans,false));
	}
	if(skinComponent)
	{
		skinComponent->SetChildActorClass(Skin);
		skinComponent->SetRelativeTransform(temp_trans);
		if(Cast<AOmegaSkin>(skinComponent->GetChildActor()))
		{
			AOmegaSkin* skin_ref = Cast<AOmegaSkin>(skinComponent->GetChildActor());
		}
	}
}

AOmegaSkin* USkinComponent::SetSkin(TSubclassOf<AOmegaSkin> SkinClass)
{
	Skin=SkinClass;
	Assemble();
	return GetSkin();
}

AOmegaSkin* USkinComponent::GetSkin()
{
	if (skinComponent && skinComponent->GetChildActor())
	{
		return Cast<AOmegaSkin>(skinComponent->GetChildActor());
	}
	return nullptr;
}

void USkinComponent::Assemble()
{
	Update_Skin();
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

void AOmegaSkin::BuildSkin()
{
	if(Cast<ACharacter>(GetParentActor()))
	{
		ACharacter* charRef = Cast<ACharacter>(GetParentActor());

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
			charRef->GetMesh()->SetSkeletalMeshAsset(new_mesh);
			//Clean Mesh
			for(auto* tempComp : GetMeshMergeComponents())
			{
				tempComp->DestroyComponent();
			}
			local_applyModifiers(charRef->GetMesh());
		}
		else
		{
			if(MasterSkeleton)
			{
				charRef->GetMesh()->SetSkeletalMeshAsset(MasterSkeleton);
				if(MasterSkeletonOverrideMaterial)
				{
					for (int i = 0; i < charRef->GetMesh()->GetMaterials().Num(); ++i)
					{
						charRef->GetMesh()->SetMaterial(i,MasterSkeletonOverrideMaterial);
					}
				}
			}
			if(bForceFollowMasterComponent)
			{
				for(auto* tempComp : GetMeshMergeComponents())
				{
					if(tempComp)
					{
						tempComp->SetLeaderPoseComponent(charRef->GetMesh(),true);
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
		if(AnimationClass  && charRef->GetMesh()->GetAnimationMode()==EAnimationMode::Type::AnimationBlueprint)
		{
			charRef->GetMesh()->SetAnimInstanceClass(AnimationClass);
		}
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

