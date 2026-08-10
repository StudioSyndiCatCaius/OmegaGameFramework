// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Components/OmegaComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/Struct_Material.h"
#include "Types/Struct_Message.h"
#include "F_Message.generated.h"

class UUI_MessageSpeaker;
class USceneCaptureComponent2D;
class UCurveFloat;
class UGameplayActorComponent;
class UOmegaGameplayMessage;
class UMaterialInstanceDynamic;
class UOAsset_TransformPreset;
class UStaticMeshComponent;
class UTexture2D;
class AOmegaMessageActor;


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Message : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message - Send",meta=(WorldContext="WorldContextObject"))
	static UOmegaGameplayMessage* Send(UObject* WorldContextObject, UObject* Instigator,FText Text,UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag,FOmegaGameplayMessageMeta meta);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message - Finish (Category)",meta=(WorldContext="WorldContextObject"))
	static bool Finish(UObject* WorldContextObject,UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message - Get Current",meta=(WorldContext="WorldContextObject"))
	static UOmegaGameplayMessage* GetCurrent(UObject* WorldContextObject,UPARAM(meta=(Categories="Message")) FGameplayTag CategoryTag);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message Speaker - Get Add Widgets",meta=(WorldContext="WorldContextObject"))
	static TArray<UUI_MessageSpeaker*> SpeakerWidgets_GetAll(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message Speaker - Get Widget (From Speaker)",meta=(WorldContext="WorldContextObject"))
	static UUI_MessageSpeaker* SpeakerWidgets_GetBySpeaker(UObject* WorldContextObject,UPrimaryDataAsset* Speaker);
	UFUNCTION(BlueprintCallable,Category="Omega|Message",DisplayName="💬Message Speaker - Get Widget (From Position)",meta=(WorldContext="WorldContextObject"))
	static UUI_MessageSpeaker* SpeakerWidgets_GetByPosition(UObject* WorldContextObject,UOAsset_TransformPreset* Position);
};

// ==================================================================================================
// Interfaces
// ==================================================================================================

USTRUCT(BlueprintType)
struct FOmegaMessageInstigatorConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message") FSlateBrush DefaultPortrait;
};

UINTERFACE(MinimalAPI, BlueprintType, DisplayName="♎Data🔴 - Message Instigator") class UDataInterface_MessageInstigator : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_MessageInstigator
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Gameplay|Message",DisplayName="💬Message Speaker - Get Config")
	FOmegaMessageInstigatorConfig Speaker_GetConfig();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Gameplay|Message",DisplayName="💬Message Speaker - Get Message Brush")
	FSlateBrush GetMessageBrush(UOmegaGameplayMessage* Message);
};




// ==================================================================================================
// Stage
// ==================================================================================================

USTRUCT(BlueprintType)
struct FOmegaMessageStageActorConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") UMaterialInterface* BaseMaterial=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") FOmegaDynamicMaterialParams InitMaterialParams;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") FName VisibilityScalarParam="Opacity";
	//texture parameter on the material that image changes (CG/portrait) are written to
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") FName ImageTextureParam="Texture";
	
	//curve for the blend type when the visibility is updated. if none use a constant float interp
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") TObjectPtr<UCurveFloat> VisibilityBlendCurve;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") float VisibilityBlendTime=0.2f;

	//curve for the blend type when the position is updated. if none use a constant float interp
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") TObjectPtr<UCurveFloat> PositionBlendCurve;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") float PositionBlendTime=0.2f;
};


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaMessageStageComponent : public UOmegaComponent
{
	GENERATED_BODY()

public:
	UOmegaMessageStageComponent();
	UFUNCTION() void L_MessageBegin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	UFUNCTION() void L_MessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	virtual  void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(VisibleAnywhere,Category="Stage") TArray<AOmegaMessageActor*> MessageActors;
	UPROPERTY(VisibleAnywhere,Category="Stage") TMap<UPrimaryDataAsset*,AOmegaMessageActor*> MessageActors_BySpeaker;
	
	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="Speaker Actor - Get")
	AOmegaMessageActor* SpeakerActor_Get(UPrimaryDataAsset* Instigator, bool CreateIfInvalid=false);
	
	//does not remove from list, only sets visibility to false UNLESS DestroyInstance is true
	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="Speaker Actor - Remove")
	bool SpeakerActor_Remove(UPrimaryDataAsset* Instigator, bool DestroyInstance=false);

	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="Speaker Actor - Remove All")
	bool SpeakerActor_RemoveAll(bool DestroyInstance=false);
	
	/*
	 * use to access stages for things like FlowNodes. 
	 * (Commonly you'll only use one stage for things like dialogue, in which case you can leave this blank, as it will
	 * always be the only one referenced
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Message Actor") FGameplayTag StageID;
	
	//if true, when a message begins, if its speaker/instigator does not already have a linked actor, will spawn one in.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") bool AutoAddNewSpeakers=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") FGameplayTagContainer AcceptedMessageCategories;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") TSubclassOf<AOmegaMessageActor> SpeakerActorClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stage") TMap<TSubclassOf<AOmegaMessageActor>,FOmegaMessageStageActorConfig> ActorConfig;
	
	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="Message Actor - Register")
	bool MsgActor_Register(AOmegaMessageActor* Actor, bool bRegisterActor);
	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="Message Actor - Create")
	AOmegaMessageActor* MsgActor_Create(TSubclassOf<AOmegaMessageActor> Class,UPrimaryDataAsset* Identity,UOAsset_TransformPreset* Position);
	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="Message Actor - Get from Tag")
	AOmegaMessageActor* MsgActor_GetFromID(FGameplayTag ID) const;

	UPROPERTY() USceneCaptureComponent2D* linked_scene_capture;
	//PrimitiveRenderMode the capture had before linking, restored on clear
	uint8 linked_capture_prev_mode=0;
	//applies/removes the "only & always visible in the linked capture" state on one actor
	void L_SetActorCaptureLinked(AOmegaMessageActor* Actor, bool bLinked);

	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="SceneCapture - Link")
	bool SceneCapture_Link(USceneCaptureComponent2D* Component);
	UFUNCTION(BlueprintCallable,Category="Message Stage",DisplayName="SceneCapture - Clear")
	void SceneCapture_Clear();
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaMessageActor : public AActor
{
	GENERATED_BODY()

public:
	AOmegaMessageActor();
	virtual void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type EndPlayReason);
	virtual void Tick(float DeltaSeconds) override;
	void InitPortrait();


	float visibility_blend_opacity=0.0f;

	float position_blend_alpha=1.0f;
	bool position_is_blending=false;
	FTransform position_blend_start;

	float image_blend_alpha=1.0f;
	bool image_is_blending=false;

	//current opacity from the visibility blend, remapped through the config curve
	float L_GetVisibilityOpacity() const;
	//writes the current front (and, while dual blending, back) opacities to the dynamic materials
	void L_ApplyOpacity();
	//if dual blending, moves the current material to the back mesh so the old image can fade out under the new one
	void L_Image_PreChange();

	//transform that "position" presets are relative to: the attach parent if attached, otherwise the owning stage component's actor
	FTransform GetPositionBaseTransform() const;

	UFUNCTION() virtual void Msg_Begin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	UFUNCTION() virtual void Msg_End(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	
	UPROPERTY() UOmegaMessageStageComponent* owning_component=nullptr;
	UPROPERTY() UMaterialInstanceDynamic* dyna_mat;
	//old image material, shown on the back mesh while dual blending
	UPROPERTY() UMaterialInstanceDynamic* dyna_mat_back;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components") UGameplayActorComponent* Identity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components") USceneComponent* MeshRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components") UStaticMeshComponent* Mesh_Front;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components") UStaticMeshComponent* Mesh_Back;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Message Actor") FGameplayTag SlotTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Message Actor") UOAsset_TransformPreset* position;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Message Actor") bool Visibility;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message Actor") bool VisibleOn_PositionSet=true;
	
	//If this speaker is the message instigator, but the message has no valid brush, revert to the speaker default portrait
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message Actor") bool PortraitUseDefaultOnMessageInvalid;
	
	/*
	 *  If TRUE, will use dual blend texture parameter on the main material to blend to the new texture over a set time,
	 *  fading out the back mesh and fading in the front mesh.
	 *  if FALSE, always do an instant image change, fully disabling the Back Mesh
	 *  
	 */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message Actor") bool Image_UseDualBlend=true;
	//Time it will take to blend from the Old material Texture to the NEW material texture
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message Actor") float Image_DualBlendTime=0.2f;
	
	
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Image - Set (Brush)")
	void Img_SetBrush(FSlateBrush Brush,FOmegaDynamicMaterialParams Params);
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Image - Set (Texture)")
	void Img_SetTexture(UTexture2D* Texture);
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Image - Set (Material)")
	void Img_SetMaterial(UMaterialInterface* Material);
	
	
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Position - Set")
	void Position_Set(UOAsset_TransformPreset* NewPosition);
	
	//sets the target visibility, so the message dynamic material can start blending to that
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Visibility - Set")
	void Visibility_Set(bool bIsVisible);

	//Forces the dynamic material's opacity to whatever this is. Used to set the initial visibility state, rather than blending/
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Visibility - Force")
	void Visibility_ForceOpacity(float Opacity);
	
	UFUNCTION(BlueprintPure,Category="Message Actor")
	UOmegaMessageStageComponent* GetOwningComponent();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Message Actor")
	FOmegaMessageStageActorConfig DefaultConfig;
	UFUNCTION(BlueprintPure,Category="Message Actor",DisplayName="Config - Get")
	FOmegaMessageStageActorConfig ActorConfig_Get() const;
	
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Mesh - Init")
	void Mesh_Init();
	
	UFUNCTION(BlueprintCallable,Category="Message Actor",DisplayName="Material - Create")
	UMaterialInstanceDynamic* MsgMaterial_Create();
	UFUNCTION(BlueprintPure,Category="Message Actor",DisplayName="Material - Get")
	UMaterialInstanceDynamic* MsgMaterial_Get();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Message Stage")
	void Msg_OnSpeakerInit(UPrimaryDataAsset* Speaker);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Message Stage")
	void Msg_OnPositionChanged(UOAsset_TransformPreset* NewPosition);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Message Stage")
	void Msg_OnVisibilityChange(bool bVisibility);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Message Stage")
	void Msg_OnImageChange_Texture(UTexture2D* Texture);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Message Stage")
	void Msg_OnImageChange_Material(UMaterialInterface* Material);
	
protected:

	UFUNCTION() virtual void Native_OnStageChanged(UOmegaMessageStageComponent* NewStageOwner);
};

