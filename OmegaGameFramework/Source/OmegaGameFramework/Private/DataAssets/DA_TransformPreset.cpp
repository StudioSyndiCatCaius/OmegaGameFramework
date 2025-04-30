// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_TransformPreset.h"

#include "Blueprint/UserWidget.h"
#include "Functions/OmegaFunctions_Utility.h"
#include "Kismet/KismetMathLibrary.h"

void UOAsset_TransformPreset::ApplyToWidget(UUserWidget* Widget)
{
	if(Widget)
	{
		Widget->SetRenderTransform(UOmegaMathFunctions::Conv_Transform3DToTransformWidget(Transform));
	}
}

void UOAsset_TransformPreset::ApplyToActor(AActor* Actor)
{
	if(Actor)
	{
		Actor->SetActorTransform(Transform);
	}
}
