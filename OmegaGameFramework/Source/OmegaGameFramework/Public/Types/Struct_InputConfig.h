
#pragma once

#include "CoreMinimal.h"
#include "InputModifiers.h"
#include "Struct_InputConfig.generated.h"

USTRUCT(BlueprintType)
struct FOmegaKeyConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	FVector Axis;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	bool Swizzle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input",meta=(EditCondition="Swizzle"))
	EInputAxisSwizzle SwizzleType;
	
	FVector ApplySwizzle(FVector v);
};

inline FVector FOmegaKeyConfig::ApplySwizzle(FVector v)
{
	if (Swizzle)
	{
		FVector in=Axis*v;
		switch (SwizzleType)
		{
		case EInputAxisSwizzle::XZY:
			return FVector(in.X, in.Z, in.Y);
		case EInputAxisSwizzle::YZX:
			return FVector(in.Y, in.Z, in.X);
		case EInputAxisSwizzle::YXZ:
			return FVector(in.Y, in.X, in.Z);
		case EInputAxisSwizzle::ZXY:
			return FVector(in.Z, in.X, in.Y);
		case EInputAxisSwizzle::ZYX:
			return FVector(in.Z, in.Y, in.X);
		}
	}
	return Axis*v;
}


USTRUCT(BlueprintType)
struct FOmegaInputConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	FText DisplayName;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	float Deadzone=0.05;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TMap<FKey,FOmegaKeyConfig> KeyInputs;
	
};


USTRUCT()
struct FOmegaInputKeyCacheData
{
	GENERATED_BODY()
	
	TMap<FGameplayTag,FOmegaKeyConfig> KeyInputs;
};