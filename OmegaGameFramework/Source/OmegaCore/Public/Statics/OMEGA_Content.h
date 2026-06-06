#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"

class UTexture2D;

class OMEGACORE_API OMEGA_Content
{
public:
	static UTexture2D* Load_Icon_AsTexture(UObject* outer, const FString IconName);
	static FSlateBrush Load_Icon_AsBrush(UObject* outer, const FString IconName,int32 size);
};
