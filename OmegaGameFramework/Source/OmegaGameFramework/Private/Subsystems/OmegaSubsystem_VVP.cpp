// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_VVP.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

UOmegaMatExp_GetVVP::UOmegaMatExp_GetVVP()
{
	// Default constructor logic
}
/*
TArray<FExpressionOutput>& UOmegaMatExp_GetVVP::GetOutputs()
{
	TArray<FExpressionOutput> Outputs;
	Outputs.Add(FExpressionOutput(TEXT("R"), 1, 1, 0, 0, 0));
	Outputs.Add(FExpressionOutput(TEXT("G"), 1, 1, 0, 0, 0));
	Outputs.Add(FExpressionOutput(TEXT("B"), 1, 1, 0, 0, 0));
	Outputs.Add(FExpressionOutput(TEXT("A"), 1, 1, 0, 0, 0));
	Outputs.Add(FExpressionOutput(TEXT("RGBA"), 4, 4, 1, 1, 1));
	return Outputs;
}
*/
int32 UOmegaMatExp_GetVVP::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
	
	
	OutputValue = FVector4(1, 0, 0, 1); // Default value if no valid world context	
	UWorld* World = nullptr;
	if (GEngine)
	{
		for (const FWorldContext& Context : GEngine->GetWorldContexts())
		{
			if (Context.World() && Context.WorldType == EWorldType::Game)
			{
				World = Context.World();
				break;
			}
			else
			{
				OutputValue = FVector4(1, 0, 1, 1); // Default value if no valid world context
			}
		}
	}
	if (World)
	{
		if (UOmegaVoxelVectorPaintSubsystem* Subsystem = World->GetSubsystem<UOmegaVoxelVectorPaintSubsystem>())
		{
			OutputValue = Subsystem->GetVector4Value();
		}
		else
		{
			OutputValue = FVector4(0, 0, 1, 1); // Default value if no valid world context
		}
	}
	else
	{
		//OutputValue = FVector4(1, 0, 0, 1); // Default value if no valid world context
	}
	
	
	switch (OutputIndex)
	{
	case 0: // R (X)
		return Compiler->Constant4(OutputValue.X, OutputValue.Y, OutputValue.Z, OutputValue.W);
	case 1: // G (Y)
		return Compiler->Constant(OutputValue.X);
	case 2: // B (Z)
		return Compiler->Constant(OutputValue.Y);
	case 3: // A (W)
		return Compiler->Constant(OutputValue.Z);
	case 4: // RGBA
		return Compiler->Constant(OutputValue.W);
	default:
		return Compiler->Errorf(TEXT("Invalid output index"));
	}
}

FName UOmegaMatExp_GetVVP::GetParameterName() const
{
	return TEXT("VoxelVectorPaint Value");
}

FVector4 UOmegaVoxelVectorPaintSubsystem::GetVector4Value() const
{
	FVector4 out=Vector4Value;
	for (auto* tempSource : sources)
	{
		out=tempSource->GetVoxelVertexPaintingData_Implementation(0,FVector(0,0,0));
	}
	//return out;
	return FVector4(0,1,0,1);
}

AOmegaVoxelVectorPaintedVolume::AOmegaVoxelVectorPaintedVolume()
{
	USceneComponent* RootRef = CreateDefaultSubobject<USceneComponent>("Root");
}

void AOmegaVoxelVectorPaintedVolume::OnConstruction(const FTransform& Transform)
{
	if(GetWorld() && !GetWorld()->GetSubsystem<UOmegaVoxelVectorPaintSubsystem>()->sources.Contains(this))
	{
		GetWorld()->GetSubsystem<UOmegaVoxelVectorPaintSubsystem>()->sources.AddUnique(this);
	}
	Super::OnConstruction(Transform);
}

FVector4 AOmegaVoxelVectorPaintedVolume::GetVoxelVertexPaintingData_Implementation(int32 index, FVector position)
{
	if(Script)
	{
		return Script->GetLocalVoxelVectorPaintData(this,index,position);
	}
	return FVector4();
}


