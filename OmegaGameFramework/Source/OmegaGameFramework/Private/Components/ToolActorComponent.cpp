// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ToolActorComponent.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

UAnimMontage* AOmegaTool::GetMontage_Equip_Implementation() { return DefaultMontage_Equip; }
UAnimMontage* AOmegaTool::GetMontage_Unequip_Implementation() { return  DefaultMontage_Unequip; }
UAnimMontage* AOmegaTool::GetMontage_Activate_Implementation() { return DefaultMontage_Activate; }
UAnimMontage* AOmegaTool::GetMontage_Deactivate_Implementation() { return DefaultMontage_Deactivate; }

void AOmegaTool::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(is_active)
	{
		OnActivatedTick(DeltaSeconds);
	}
}

void AOmegaTool::SetToolActive(bool bActive)
{
	if(bActive != is_active)
	{
		is_active=bActive;
		OnSetActive(bActive);
		if(is_active)
		{
			owning_component->local_playToolMontage(GetMontage_Activate());
		}
		else
		{
			owning_component->local_playToolMontage(GetMontage_Deactivate());
		}
	}
}

// Sets default values for this component's properties
UToolActorComponent::UToolActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UToolActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


USkeletalMeshComponent* UToolActorComponent::GetSkeletaMeshReference()
{
	if(!REF_SkelMesh && Cast<ACharacter>(GetOwner()))
	{
		REF_SkelMesh = Cast<ACharacter>(GetOwner())->GetMesh();
	}
	if(REF_SkelMesh)
	{
		return REF_SkelMesh;
	}
	return nullptr;
}

// Called every frame
void UToolActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UToolActorComponent::SetToolRegistered(TSubclassOf<AOmegaTool> Tool, bool is_registered)
{
	if(registered_tools.Contains(Tool) != is_registered)
	{
		if(is_registered) { registered_tools.AddUnique(Tool); }
		else { registered_tools.Remove(Tool); }
	}
}

void UToolActorComponent::SetCurrentToolActive(TSubclassOf<AOmegaTool> Tool, bool bActive)
{
	if(GetCurrentTool())
	{
		GetCurrentTool()->SetToolActive(bActive);
	}
}

void UToolActorComponent::SetCurrentTool_ByIndex(int32 index)
{
	if(registered_tools.IsValidIndex(index))
	{
		SetCurrentTool_ByClass(registered_tools[index]);
	}
}

void UToolActorComponent::SetCurrentTool_ByClass(TSubclassOf<AOmegaTool> Tool)
{
	if(Tool)
	{
		if(Current_tool)
		{
			Current_tool->SetToolActive(false);
			Current_tool->K2_DestroyActor();
		}
		
		Current_tool = GetWorld()->SpawnActorDeferred<AOmegaTool>(Tool, FTransform(), GetOwner());
		Current_tool->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
		Current_tool->owning_component=this;
		local_playToolMontage(Current_tool->GetMontage_Activate());
	}
}

void UToolActorComponent::CycleToolIndex(int32 index)
{
	int32 new_index = UKismetMathLibrary::Wrap(GetCurrentTool_Index()+index,0,registered_tools.Num()-1);
	SetCurrentTool_ByIndex(new_index);
}

AOmegaTool* UToolActorComponent::GetCurrentTool()
{
	return Current_tool;
}

TSubclassOf<AOmegaTool> UToolActorComponent::GetCurrentTool_Class()
{
	if(GetCurrentTool())
	{
		return GetCurrentTool()->GetClass();
	}
	return nullptr;
}

int32 UToolActorComponent::GetCurrentTool_Index()
{
	if(registered_tools.Contains(GetCurrentTool_Class()))
	{
		return registered_tools.Find(GetCurrentTool_Class());
	}
	return -1;
}

