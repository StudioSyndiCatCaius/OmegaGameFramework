
#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Struct_Material.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FOmegaDynamicMaterialParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material") TMap<FName,float> params_scalar;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material") TMap<FName,FLinearColor> params_vector;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material") TMap<FName,UTexture2D*> params_texture;

	void Apply(UMaterialInstanceDynamic* mat)
	{
		if(mat)
		{
			for(auto& p : params_scalar)
			{
				mat->SetScalarParameterValue(p.Key,p.Value);
			}
			for(auto& p : params_vector)
			{
				mat->SetVectorParameterValue(p.Key,p.Value);
			}
			for(auto& p : params_texture)
			{
				mat->SetTextureParameterValue(p.Key,p.Value);
			}
		}
	}
};