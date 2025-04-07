// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_ComponentMod.h"

#include "Kismet/KismetMathLibrary.h"

void UOmegaComponentModifierFunctions::ApplyModifierTo_SkeletalMesh(FComponentMod_SkeletalMesh mod,
	USkeletalMeshComponent* Component)
{
	if(Component && mod.Script)
	{
		mod.Script->OnAppliedToComponent(Component);
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_StaticMesh(FComponentMod_StaticMesh mod,
	UStaticMeshComponent* Component)
{
	if(Component && mod.Script)
	{
		mod.Script->OnAppliedToComponent(Component);
	}
}

void UOmegaComponentModifierFunctions::ApplyModifierTo_InstancedStaticMesh(FComponentMod_InstancedStaticMesh mod,
	UInstancedStaticMeshComponent* Component)
{
	if(Component && mod.Script)
	{
		mod.Script->OnAppliedToComponent(Component);
	}
}
