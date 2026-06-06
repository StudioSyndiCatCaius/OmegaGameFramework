// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Camera.h"
#include "Actors/Actor_DynamicCamera.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_World.h"
#include "Camera/CameraComponent.h"


APlayerController* _TryGetPlayer(UObject* Context, APlayerController* lit) 
{
	if(lit)
	{
		return lit;
	}
	if(Context && Context->GetWorld())
	{
		return Context->GetWorld()->GetFirstPlayerController();
	}
	return nullptr;
}


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
		AActor* in_actor=WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetGlobalActorBinding(Binding);
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

void UOmegaCameraFunctions::DynamicCamera_SetActive(UObject* WorldContextObject, bool bActive,
	APlayerController* Player)
{
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_SetActive(bActive);
	}
}

bool UOmegaCameraFunctions::DynamicCamera_IsActive(UObject* WorldContextObject, APlayerController* Player)
{
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		return _player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_IsActive();
	}
	return false;
}

AOmegaDynamicCamera* UOmegaCameraFunctions::GetDynamicCamera_Master(UObject* WorldContextObject, bool& Outcome, 
                                                                    APlayerController* Player)
{
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		Outcome=true;
		return _player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_GetMaster();
	}
	Outcome=false;
	return nullptr;
}

AOmegaDynamicCamera* UOmegaCameraFunctions::GetDynamicCamera_Source(UObject* WorldContextObject, bool& Outcome, 
	APlayerController* Player)
{
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		Outcome=true;
		return _player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_GetSource();
	}
	Outcome=false;
	return nullptr;
}

bool UOmegaCameraFunctions::SetDynamicCamera_Override(UObject* WorldContextObject, AOmegaDynamicCamera* SourceCamera, bool bSnapTo,
	APlayerController* Player)
{
	if(SourceCamera)
	{
		if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
		{
			_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_SetOverride(SourceCamera,bSnapTo);
			return true;
		}
	}
	return false;
}

bool UOmegaCameraFunctions::ClearDynamicCamera_Override(UObject* WorldContextObject, APlayerController* Player)
{
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_ClearOverride();
		return true;
	}
	return false;
}

void UOmegaCameraFunctions::DynamicCamera_SnapToSource(UObject* WorldContextObject, APlayerController* Player)
{
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		UOmegaSubsystem_Player* _subsystem=_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
		if (_subsystem && _subsystem->DynaCam_IsActive())
		{
			_subsystem->DynaCam_SnapToCurrent();
		}
	}
}

bool UOmegaCameraFunctions::SetViewTargetToDynamicCamera(UObject* WorldContextObject, APlayerController* Player)
{
	//if (true) { return false;}
	if(APlayerController* _player = _TryGetPlayer(WorldContextObject,Player))
	{
		UOmegaSubsystem_Player* _subsystem=_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
		if (_subsystem && _subsystem->DynaCam_IsActive())
		{
			if(AOmegaDynamicCamera* mcam=_subsystem->DynaCam_GetMaster())
			{
				_player->SetViewTarget(mcam);
				return true;
			}
		}
	}
	return false;
}
