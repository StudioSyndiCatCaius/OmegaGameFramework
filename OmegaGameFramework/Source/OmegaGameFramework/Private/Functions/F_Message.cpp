// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Message.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Component_GameplayActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"
#include "DataAssets/DA_TransformPreset.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_World.h"
#include "Engine/World.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Widget/UI_MessageSpeaker.h"


UOmegaSubsystem_World* L_GetWorldSub(UObject* WorldContext)
{
	if (WorldContext && WorldContext->GetWorld())
	{
		return WorldContext->GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	}
	return nullptr;
}


UOmegaGameplayMessage* UOmegaFunctions_Message::Send(UObject* WorldContextObject, UObject* Instigator, FText Text,
	FGameplayTag CategoryTag, FOmegaGameplayMessageMeta meta)
{
	if (UOmegaSubsystem_World* w=L_GetWorldSub(WorldContextObject))
	{
		return w->Message_Send(Instigator, Text, CategoryTag, meta);
	}
	return nullptr;
}

bool UOmegaFunctions_Message::Finish(UObject* WorldContextObject, FGameplayTag CategoryTag)
{
	if (UOmegaSubsystem_World* w=L_GetWorldSub(WorldContextObject))
	{
		if (UOmegaGameplayMessage* ms=w->Message_GetFirstOfCategory(CategoryTag))
		{
			ms->End();
		}
	}
	return false;
}

UOmegaGameplayMessage* UOmegaFunctions_Message::GetCurrent(UObject* WorldContextObject, FGameplayTag CategoryTag)
{
	if (UOmegaSubsystem_World* w=L_GetWorldSub(WorldContextObject))
	{
		return w->Message_GetFirstOfCategory(CategoryTag);
	}
	return nullptr;
}

TArray<UUI_MessageSpeaker*> UOmegaFunctions_Message::SpeakerWidgets_GetAll(UObject* WorldContextObject)
{
	TArray<UUI_MessageSpeaker*>  out;
	TArray<UUserWidget*> _widgets;
	//TopLevelOnly=false: speaker widgets are nested inside HUD/menu layouts, not added straight to the viewport
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(WorldContextObject,_widgets,UUI_MessageSpeaker::StaticClass(),false);

	for (UUserWidget* _w : _widgets)
	{
		if (UUI_MessageSpeaker* _s=Cast<UUI_MessageSpeaker>(_w))
		{
			out.AddUnique(_s);
		}
	}
	return out;
}

UUI_MessageSpeaker* UOmegaFunctions_Message::SpeakerWidgets_GetBySpeaker(UObject* WorldContextObject,
	UPrimaryDataAsset* Speaker)
{
	for (UUI_MessageSpeaker* wg : SpeakerWidgets_GetAll(WorldContextObject))
	{
		if (wg->SpeakerInstigator==Speaker) { return wg; }	
	}
	return nullptr;
}

UUI_MessageSpeaker* UOmegaFunctions_Message::SpeakerWidgets_GetByPosition(UObject* WorldContextObject,
	UOAsset_TransformPreset* Position)
{
	for (UUI_MessageSpeaker* wg : SpeakerWidgets_GetAll(WorldContextObject))
	{
		if (wg->position==Position) { return wg; }	
	}
	return nullptr;
}

UOmegaMessageStageComponent::UOmegaMessageStageComponent()
{
	AcceptedMessageCategories=FGameplayTag::RequestGameplayTag("Message.Dialog").GetSingleTagContainer();
}

void UOmegaMessageStageComponent::L_MessageBegin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta Meta)
{
	if (AcceptedMessageCategories.HasTagExact(MessageCategory))
	{
		if (Message)
		{
			if (UPrimaryDataAsset* speaker=Cast<UPrimaryDataAsset>(Message->GetMessageInstigator()))
			{
				if (AutoAddNewSpeakers)
				{
					AOmegaMessageActor* a= SpeakerActor_Get(speaker,true);
					a->Msg_Begin(Message, MessageCategory, Meta);
				}
			}
		}
	}
}

void UOmegaMessageStageComponent::L_MessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta Meta)
{
	if (AcceptedMessageCategories.HasTagExact(MessageCategory) && Message)
	{
		if (UPrimaryDataAsset* speaker=Cast<UPrimaryDataAsset>(Message->GetMessageInstigator()))
		{
			if (AOmegaMessageActor* a=SpeakerActor_Get(speaker))
			{
				a->Msg_End(Message, MessageCategory, Meta);
			}
		}
	}
}

void UOmegaMessageStageComponent::BeginPlay()
{
	Super::BeginPlay();
	if (UOmegaSubsystem_World* w=OGF_Subsystems::oWorld(this))
	{
		w->OnGameplayMessage_Begin.AddDynamic(this,&UOmegaMessageStageComponent::L_MessageBegin);
		w->OnGameplayMessage_End.AddDynamic(this,&UOmegaMessageStageComponent::L_MessageEnd);
		w->message_stages.Add(StageID,this);
	}
}

void UOmegaMessageStageComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (UOmegaSubsystem_World* w=OGF_Subsystems::oWorld(this))
	{
		if (w->message_stages.Contains(StageID))
		{
			if (UOmegaMessageStageComponent* _s=w->message_stages[StageID])
			{
				if (_s==this)
				{
					w->message_stages.Remove(StageID);
				}
			}
		}
	}
}


AOmegaMessageActor* UOmegaMessageStageComponent::SpeakerActor_Get(
	UPrimaryDataAsset* Speaker, bool CreateIfInvalid)
{
	if (MessageActors_BySpeaker.Contains(Speaker))
	{
		if (AOmegaMessageActor* _a=MessageActors_BySpeaker[Speaker])
		{
			return _a;
		}
	}
	if (CreateIfInvalid)
	{
		TSubclassOf<AOmegaMessageActor> in_class=AOmegaMessageActor::StaticClass();
		if (SpeakerActorClass) { in_class=SpeakerActorClass; }
		AOmegaMessageActor* a= MsgActor_Create(in_class,Speaker,nullptr);
		MessageActors_BySpeaker.Add(Speaker,a);
		return a;
	}
	return nullptr;
}

bool UOmegaMessageStageComponent::SpeakerActor_Remove(UPrimaryDataAsset* Speaker, bool DestroyInstance)
{
	if (AOmegaMessageActor* _a=SpeakerActor_Get(Speaker))
	{
		_a->Visibility_Set(false);
		if (DestroyInstance)
		{
			MessageActors_BySpeaker.Remove(Speaker);
			const float _fade=_a->ActorConfig_Get().VisibilityBlendTime;
			if (_fade<=0.0f)
			{
				_a->Destroy();
			}
			else
			{
				// let the fade out play, then destroy. the actor unregisters itself on EndPlay
				_a->SetLifeSpan(_fade+0.05f);
			}
		}
		return true;
	}
	return false;
}

bool UOmegaMessageStageComponent::SpeakerActor_RemoveAll(bool DestroyInstance)
{
	bool _removed_any=false;
	TArray<UPrimaryDataAsset*> _speakers;
	MessageActors_BySpeaker.GetKeys(_speakers);
	for (UPrimaryDataAsset* _s : _speakers)
	{
		_removed_any = SpeakerActor_Remove(_s,DestroyInstance) || _removed_any;
	}
	return _removed_any;
}

AOmegaMessageActor* UOmegaMessageStageComponent::MsgActor_GetFromID(FGameplayTag ID) const
{
	// speaker actors have no SlotTag; an empty ID must not match them
	if (!ID.IsValid()) { return nullptr; }
	for (AOmegaMessageActor* _a : MessageActors)
	{
		if (_a && _a->SlotTag==ID)
		{
			return _a;
		}
	}
	return nullptr;
}

bool UOmegaMessageStageComponent::MsgActor_Register(AOmegaMessageActor* Actor, bool bRegisterActor)
{
	if (Actor)
	{
		if (!MessageActors.Contains(Actor) && bRegisterActor)
		{
			MessageActors.AddUnique(Actor);
			// manually registered actors need the stage link too, or they fall back to DefaultConfig
			Actor->owning_component=this;
			L_SetActorCaptureLinked(Actor,true);
			return true;
		}
		if (MessageActors.Contains(Actor) && !bRegisterActor)
		{
			MessageActors.Remove(Actor);
			if (Actor->owning_component==this) { Actor->owning_component=nullptr; }
			L_SetActorCaptureLinked(Actor,false);
			return true;
		}
	};
	return false;
}

void UOmegaMessageStageComponent::L_SetActorCaptureLinked(AOmegaMessageActor* Actor, bool bLinked)
{
	if (!Actor || !linked_scene_capture) { return; }
	// linked actors render ONLY in scene captures, never in the main view
	TInlineComponentArray<UPrimitiveComponent*> _prims(Actor);
	for (UPrimitiveComponent* _p : _prims)
	{
		if (_p) { _p->SetVisibleInSceneCaptureOnly(bLinked); }
	}
	if (bLinked)
	{
		linked_scene_capture->ShowOnlyActors.AddUnique(Actor);
		linked_scene_capture->ShowOnlyActorComponents(Actor);
	}
	else
	{
		linked_scene_capture->ShowOnlyActors.Remove(Actor);
		linked_scene_capture->RemoveShowOnlyActorComponents(Actor);
	}
}

bool UOmegaMessageStageComponent::SceneCapture_Link(USceneCaptureComponent2D* Component)
{
	if (!Component) { return false; }
	if (linked_scene_capture==Component) { return true; }
	SceneCapture_Clear();
	linked_scene_capture=Component;
	linked_capture_prev_mode=static_cast<uint8>(Component->PrimitiveRenderMode);
	Component->PrimitiveRenderMode=ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
	for (AOmegaMessageActor* _a : MessageActors)
	{
		L_SetActorCaptureLinked(_a,true);
	}
	return true;
}

void UOmegaMessageStageComponent::SceneCapture_Clear()
{
	if (linked_scene_capture)
	{
		for (AOmegaMessageActor* _a : MessageActors)
		{
			L_SetActorCaptureLinked(_a,false);
		}
		linked_scene_capture->PrimitiveRenderMode=static_cast<ESceneCapturePrimitiveRenderMode>(linked_capture_prev_mode);
		linked_scene_capture=nullptr;
	}
}

// ==================================================================================================
// Message Actor
// ==================================================================================================

AOmegaMessageActor* UOmegaMessageStageComponent::MsgActor_Create(TSubclassOf<AOmegaMessageActor> Class,
	UPrimaryDataAsset* Identity, UOAsset_TransformPreset* Position)
{
	if (AOmegaMessageActor* _a=GetWorld()->SpawnActorDeferred<AOmegaMessageActor>(Class, FTransform(), GetOwner()))
	{
		MsgActor_Register(_a,true);
		_a->owning_component=this;
		if (_a->Identity)
		{
			_a->Identity->SetIdentitySourceAsset(Identity);
		}
		_a->FinishSpawning(FTransform());
		_a->Position_Set(Position);
		if (Identity)
		{
			_a->InitPortrait();
			_a->Msg_OnSpeakerInit(Identity);
		}
		
		return _a;
	}
	return nullptr;
}

AOmegaMessageActor::AOmegaMessageActor()
{
	PrimaryActorTick.bCanEverTick=true;
	
	RootComponent=CreateDefaultSubobject<USceneComponent>("ROOT");
	MeshRoot=CreateDefaultSubobject<USceneComponent>("Mesh Root");
	MeshRoot->SetupAttachment(RootComponent);
	MeshRoot->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));
	
	Mesh_Front=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh FRONT"));
	Mesh_Front->SetupAttachment(MeshRoot);
	Mesh_Front->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh_Back=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh BACK"));
	Mesh_Back->SetupAttachment(MeshRoot);
	Mesh_Back->SetRelativeLocation(FVector(1.0f,0.0f,0.0f));
	Mesh_Back->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	
	Identity=CreateDefaultSubobject<UGameplayActorComponent>(TEXT("Identity"));
}

void AOmegaMessageActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh_Init();
	// Msg_Begin/Msg_End are routed by the owning stage component to the actor matching
	// the message instigator. Do NOT subscribe to the world message events here, or every
	// stage actor will react to every message.
}

void AOmegaMessageActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (owning_component)
	{
		owning_component->MsgActor_Register(this,false);
	}
	Super::EndPlay(EndPlayReason);
}

void AOmegaMessageActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	const FOmegaMessageStageActorConfig _config=ActorConfig_Get();

	bool _opacity_dirty=false;

	// --- Visibility: blend the material opacity toward the target visibility ---
	const float _vis_target = Visibility ? 1.0f : 0.0f;
	if (visibility_blend_opacity != _vis_target)
	{
		if (_config.VisibilityBlendTime > 0.0f)
		{
			visibility_blend_opacity=FMath::FInterpConstantTo(visibility_blend_opacity,_vis_target,DeltaSeconds,1.0f/_config.VisibilityBlendTime);
		}
		else
		{
			visibility_blend_opacity=_vis_target;
		}
		_opacity_dirty=true;
	}

	// --- Image: dual blend, fade the new image in on the front mesh while the old fades out on the back ---
	if (image_is_blending)
	{
		if (Image_DualBlendTime > 0.0f)
		{
			image_blend_alpha=FMath::Min(image_blend_alpha+(DeltaSeconds/Image_DualBlendTime),1.0f);
		}
		else
		{
			image_blend_alpha=1.0f;
		}
		_opacity_dirty=true;
		if (image_blend_alpha >= 1.0f)
		{
			image_is_blending=false;
			dyna_mat_back=nullptr;
			if (Mesh_Back) { Mesh_Back->SetVisibility(false); }
		}
	}

	if (_opacity_dirty)
	{
		L_ApplyOpacity();
	}

	// --- Position: blend toward the target preset transform, relative to the base transform ---
	if (position_is_blending && position)
	{
		if (_config.PositionBlendTime > 0.0f)
		{
			position_blend_alpha=FMath::Min(position_blend_alpha+(DeltaSeconds/_config.PositionBlendTime),1.0f);
		}
		else
		{
			position_blend_alpha=1.0f;
		}
		float _alpha=position_blend_alpha;
		if (UCurveFloat* _curve=_config.PositionBlendCurve)
		{
			_alpha=_curve->GetFloatValue(position_blend_alpha);
		}
		const FTransform _relative=UKismetMathLibrary::TLerp(position_blend_start,position->Transform,_alpha);
		SetActorTransform(_relative*GetPositionBaseTransform());
		if (position_blend_alpha >= 1.0f)
		{
			position_is_blending=false;
		}
	}
}

void AOmegaMessageActor::InitPortrait()
{
	if (Identity->GetIdentitySourceAsset()->GetClass()->ImplementsInterface(UDataInterface_MessageInstigator::StaticClass()))
	{
		FOmegaMessageInstigatorConfig cfg=IDataInterface_MessageInstigator::Execute_Speaker_GetConfig(Identity->GetIdentitySourceAsset());
		Img_SetBrush(cfg.DefaultPortrait,FOmegaDynamicMaterialParams());
	}
}

void AOmegaMessageActor::Msg_Begin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
                                   FOmegaGameplayMessageMeta Meta)
{
	Position_Set(Meta.TransformPreset);
	if (!Meta.Brush.GetResourceObject() && PortraitUseDefaultOnMessageInvalid)
	{
		InitPortrait();
	}
	else
	{
		Img_SetBrush(Meta.Brush,FOmegaDynamicMaterialParams());
	}
}

void AOmegaMessageActor::Msg_End(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta Meta)
{
}

void AOmegaMessageActor::Position_Set(UOAsset_TransformPreset* NewPosition)
{
	if (NewPosition)
	{
		position=NewPosition;
		position_blend_start=GetActorTransform().GetRelativeTransform(GetPositionBaseTransform());
		position_blend_alpha=0.0f;
		position_is_blending=true;
		Msg_OnPositionChanged(NewPosition);
		if (VisibleOn_PositionSet)
		{
			Visibility_Set(true);
		}
	}
}

void AOmegaMessageActor::Visibility_Set(bool bIsVisible)
{
	if (Visibility==bIsVisible) { return; }
	Visibility=bIsVisible;
	Msg_OnVisibilityChange(Visibility);
}

void AOmegaMessageActor::Visibility_ForceOpacity(float Opacity)
{
	visibility_blend_opacity=Opacity;
	if (UMaterialInstanceDynamic* _mat=MsgMaterial_Get())
	{
		_mat->SetScalarParameterValue(ActorConfig_Get().VisibilityScalarParam,Opacity);
	}
}

FTransform AOmegaMessageActor::GetPositionBaseTransform() const
{
	if (RootComponent && RootComponent->GetAttachParent())
	{
		return RootComponent->GetAttachParent()->GetSocketTransform(RootComponent->GetAttachSocketName());
	}
	if (owning_component && owning_component->GetOwner())
	{
		return owning_component->GetOwner()->GetActorTransform();
	}
	return FTransform::Identity;
}

UOmegaMessageStageComponent* AOmegaMessageActor::GetOwningComponent()
{
	if (owning_component) { return owning_component; }
	return nullptr;
}

FOmegaMessageStageActorConfig AOmegaMessageActor::ActorConfig_Get() const
{
	if (owning_component)
	{
		// walk up the class chain so configs keyed to a parent class also apply to BP subclasses
		for (UClass* _c=GetClass(); _c && _c!=AActor::StaticClass(); _c=_c->GetSuperClass())
		{
			if(owning_component->ActorConfig.Contains(_c))
			{
				return owning_component->ActorConfig[_c];
			}
		}
	}
	return DefaultConfig;
}

void AOmegaMessageActor::Mesh_Init()
{
	if (UMaterialInstanceDynamic* d=MsgMaterial_Get())
	{
		if (Mesh_Front) { Mesh_Front->SetMaterial(0,d); }
	}
	if (Mesh_Back) { Mesh_Back->SetVisibility(false); }
	float vis_targ=0.0f;
	if (Visibility) { vis_targ=1.0f; }
	Visibility_ForceOpacity(vis_targ);
}

void AOmegaMessageActor::Native_OnStageChanged(UOmegaMessageStageComponent* NewStageOwner)
{
}


UMaterialInstanceDynamic* AOmegaMessageActor::MsgMaterial_Create()
{
	UMaterialInterface* mi=ActorConfig_Get().BaseMaterial;
	// no config material: fall back to whatever is already on the front mesh (e.g. set in the editor)
	if (!mi && Mesh_Front)
	{
		mi=Mesh_Front->GetMaterial(0);
	}
	if (mi)
	{
		dyna_mat=UMaterialInstanceDynamic::Create(mi,this);
		ActorConfig_Get().InitMaterialParams.Apply(dyna_mat);
		return dyna_mat;
	}
	return nullptr;
}

UMaterialInstanceDynamic* AOmegaMessageActor::MsgMaterial_Get()
{
	if (dyna_mat) { return dyna_mat; }
	if (UMaterialInstanceDynamic* mi=MsgMaterial_Create())
	{
		return mi;
	}
	return nullptr;
}

// ==================================================================================================
// Message Actor - Image
// ==================================================================================================

float AOmegaMessageActor::L_GetVisibilityOpacity() const
{
	const FOmegaMessageStageActorConfig _config=ActorConfig_Get();
	if (UCurveFloat* _curve=_config.VisibilityBlendCurve)
	{
		return _curve->GetFloatValue(visibility_blend_opacity);
	}
	return visibility_blend_opacity;
}

void AOmegaMessageActor::L_ApplyOpacity()
{
	const FName _param=ActorConfig_Get().VisibilityScalarParam;
	const float _vis=L_GetVisibilityOpacity();
	// two-phase image blend so the pair never dips below full coverage: the first half fades
	// the new front in over the still-opaque back, the second half fades the back out behind it
	const float _front_mult = image_is_blending ? FMath::Min(image_blend_alpha*2.0f,1.0f) : 1.0f;
	if (UMaterialInstanceDynamic* _mat=MsgMaterial_Get())
	{
		_mat->SetScalarParameterValue(_param,_vis*_front_mult);
	}
	if (image_is_blending && dyna_mat_back)
	{
		const float _back_mult=FMath::Min((1.0f-image_blend_alpha)*2.0f,1.0f);
		dyna_mat_back->SetScalarParameterValue(_param,_vis*_back_mult);
	}
}

void AOmegaMessageActor::L_Image_PreChange()
{
	if (Image_UseDualBlend && Image_DualBlendTime > 0.0f && Mesh_Back && dyna_mat)
	{
		// current material becomes the "old" image on the back mesh, fading out as the new one fades in
		dyna_mat_back=dyna_mat;
		Mesh_Back->SetMaterial(0,dyna_mat_back);
		Mesh_Back->SetVisibility(true);
		dyna_mat=nullptr;
		image_blend_alpha=0.0f;
		image_is_blending=true;
	}
	else
	{
		image_is_blending=false;
		dyna_mat_back=nullptr;
		if (Mesh_Back) { Mesh_Back->SetVisibility(false); }
	}
}

void AOmegaMessageActor::Img_SetTexture(UTexture2D* Texture)
{
	if (!Texture) { return; }
	L_Image_PreChange();
	if (UMaterialInstanceDynamic* _mat=MsgMaterial_Get())
	{
		_mat->SetTextureParameterValue(ActorConfig_Get().ImageTextureParam,Texture);
		if (Mesh_Front) { Mesh_Front->SetMaterial(0,_mat); }
		Msg_OnImageChange_Texture(Texture);
	}
	L_ApplyOpacity();
}

void AOmegaMessageActor::Img_SetMaterial(UMaterialInterface* Material)
{
	if (!Material) { return; }
	L_Image_PreChange();
	dyna_mat=UMaterialInstanceDynamic::Create(Material,this);
	ActorConfig_Get().InitMaterialParams.Apply(dyna_mat);
	if (Mesh_Front) { Mesh_Front->SetMaterial(0,dyna_mat); }
	Msg_OnImageChange_Material(Material);
	L_ApplyOpacity();
}

void AOmegaMessageActor::Img_SetBrush(FSlateBrush Brush, FOmegaDynamicMaterialParams Params)
{
	UObject* _resource=Brush.GetResourceObject();
	if (UMaterialInterface* _mi=Cast<UMaterialInterface>(_resource))
	{
		Img_SetMaterial(_mi);
	}
	else if (UTexture2D* _tex=Cast<UTexture2D>(_resource))
	{
		Img_SetTexture(_tex);
	}
	else
	{
		return;
	}
	if (UMaterialInstanceDynamic* _mat=MsgMaterial_Get())
	{
		Params.Apply(_mat);
	}
	L_ApplyOpacity();
}



