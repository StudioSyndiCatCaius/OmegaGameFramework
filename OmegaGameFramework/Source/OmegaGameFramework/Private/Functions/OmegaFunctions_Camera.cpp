// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Camera.h"
#include "IPlatformFilePak.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"


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

void UOmegaCameraFunctions::SetViewTarget_Actor(UObject* WorldContextObject, AActor* Actor, float BlendTime,
	APlayerController* Player)
{
	APlayerController* in_player = nullptr;
	if(Player) { in_player=Player; }
	else if(WorldContextObject)
	{
		in_player=WorldContextObject->GetWorld()->GetFirstPlayerController();
	}
	if(Actor && in_player)
	{
		in_player->SetViewTargetWithBlend(Actor,BlendTime,VTBlend_Cubic,BlendTime/2);
	}
}

void UOmegaCameraFunctions::SetViewTarget_ActorBinding(UObject* WorldContextObject, FName Binding, float BlendTime,
	APlayerController* Player)
{
	if(WorldContextObject)
	{
		AActor* in_actor=WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetGlobalActorBinding(Binding);
		SetViewTarget_Actor(WorldContextObject,in_actor,BlendTime,Player);
	}
}

void UOmegaCameraFunctions::SetViewTarget_SoftActor(UObject* WorldContextObject, TSoftObjectPtr<AActor> Actor,
	float BlendTime, APlayerController* Player)
{
	SetViewTarget_Actor(WorldContextObject,Actor.Get(),BlendTime,Player);
}

void UOmegaCameraFunctions::SetViewTarget_ActorSelector(UObject* WorldContextObject, FOmegaActorSelectorData Selector,
	float BlendTime, APlayerController* Player)
{
	AActor* in_actor=UOmegaActorUtilFunctions::GetSelectedActor(WorldContextObject,Selector);
	SetViewTarget_Actor(WorldContextObject,in_actor,BlendTime,Player);
}
