// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Camera.h"
#include "IPlatformFilePak.h"



FVector2D UOmegaCameraFunctions::ProjectWorldToScreen_FromCamera(UObject* WorldContextObject, UCameraComponent* Camera,
	FVector Location, APlayerController* Player)
{
	FVector2D out_vec;
	if (Camera)
	{
		APlayerController* PC = Player;
		if(!Player && WorldContextObject)
		{
			PC=WorldContextObject->GetWorld()->GetFirstPlayerController();  // We still need this for viewport info
		}
		if (PC)
		{
			FMinimalViewInfo ViewInfo;
			Camera->GetCameraView(0.0f, ViewInfo);
			
			const FMatrix ViewMatrix = FRotationMatrix(ViewInfo.Rotation) * FTranslationMatrix(-ViewInfo.Location);
			const FMatrix ProjectionMatrix = ViewInfo.CalculateProjectionMatrix();

			int32 viewsize_x;
			int32 viewsize_y;
			PC->GetViewportSize(viewsize_x,viewsize_y);
			const FIntRect ViewRect(0, 0, viewsize_x, viewsize_y);
        
			FSceneView::ProjectWorldToScreen(
				Location,
				ViewRect,
				ProjectionMatrix,
				out_vec,
				true
			);
		}
	}
	return out_vec;
}
