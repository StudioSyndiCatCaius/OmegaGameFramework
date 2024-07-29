// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SkinComponent.h"
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

void AOmegaSkin::OnConstruction(const FTransform& Transform)
{
	BuildSkin();
	Super::OnConstruction(Transform);
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
		}
		else
		{
			if(MasterSkeleton)
			{
				charRef->GetMesh()->SetSkeletalMeshAsset(MasterSkeleton);
			}
			if(bForceFollowMasterComponent)
			{
				for(auto* tempComp : GetMeshMergeComponents())
				{
					tempComp->SetLeaderPoseComponent(charRef->GetMesh(),true);
				}
			}
			if(bHideBaseMesh)
			{
				//charRef->GetMesh()->SetHiddenInGame(true);
				//add blank material here
			}
			
		}
		
		//Set Anim Instance
		if(AnimationClass)
		{
			charRef->GetMesh()->SetAnimInstanceClass(AnimationClass);
		}
	}
	else
	{
		for(auto* tempComp : GetMeshMergeComponents())
		{
			if (tempComp && AnimationClass)
			{
				tempComp->SetAnimInstanceClass(AnimationClass);
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

