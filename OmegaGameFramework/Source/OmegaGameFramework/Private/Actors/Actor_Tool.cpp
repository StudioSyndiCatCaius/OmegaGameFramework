// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Tool.h"

#include "Components/ArrowComponent.h"
#include "Components/AudioComponent.h"
#include "Components/Component_Combatant.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AOmegaToolActor::AOmegaToolActor()
{
	RootComponent=CreateOptionalDefaultSubobject<USceneComponent>("Root");
	TriggerRoot=CreateOptionalDefaultSubobject<UArrowComponent>("TriggerRoot");
	PrimaryActorTick.bCanEverTick=true;
}

void AOmegaToolActor::BeginPlay()
{
	Super::BeginPlay();
	if (Preset.GetObject())
	{
		IDataInterface_Tool::Execute_ToolActor_BeginPlay(Preset.GetObject(),this);
	}
}

void AOmegaToolActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (f_recoilDur>0)
	{
		f_recoilDur-=DeltaSeconds;
	}
	
	if (b_isActive)
	{
		K2_ActiveTick(DeltaSeconds);
		if (f_recoilDur<=0)
		{
			if (CanTrigger())
			{
				f_recoilDur=GetConfig().RecoilTile;
				L_PlayMontage(ToolEvent_Trigger);
				if (Preset.GetObject())
				{
					IDataInterface_Tool::Execute_Tool_OnTrigger(Preset.GetObject(),this);
				}
				K2_OnTrigger();
			}
		}
	}
	
	
}

FOmegaTool_Config AOmegaToolActor::GetConfig() const
{
	if (Preset.GetObject()) { return IDataInterface_Tool::Execute_GetToolConfig(Preset.GetObject()); }
	return Config;
}

void AOmegaToolActor::SetToolOwnerSkeletalMesh(USkeletalMeshComponent* Mesh)
{
	if (Mesh)
	{
		OverrideOwnerMesh=Mesh;
	}
	else
	{
		OverrideOwnerMesh=nullptr;
	}
}

USkeletalMeshComponent* AOmegaToolActor::GetToolOwnerSkeletalMesh() const
{
	if (OverrideOwnerMesh) { return OverrideOwnerMesh; }
	if (GetAttachParentActor())
	{
		for (UActorComponent* s : GetAttachParentActor()->GetComponentsByTag(USkeletalMeshComponent::StaticClass(),SkeletalMeshTag))
		{
			if (s)
			{
				return Cast<USkeletalMeshComponent>(s);
			}
		}
	}
	return nullptr;
}

AActor* AOmegaToolActor::GetToolOwner_Actor() const
{
	if (OwningComponent) { return OwningComponent->GetOwner(); }
	if (GetAttachParentActor())
	{
		return GetAttachParentActor();
	}
	return nullptr;
}

ACharacter* AOmegaToolActor::GetToolOwner_Character() const
{
	if (ACharacter* c=Cast<ACharacter>(GetToolOwner_Actor()))
	{
		return c;
	}
	return nullptr;
}

UCombatantComponent* AOmegaToolActor::GetToolOwner_Combatant() const
{
	if (AActor* a=GetToolOwner_Actor())
	{
		if (UCombatantComponent* c=Cast<UCombatantComponent>(a->GetComponentByClass(UCombatantComponent::StaticClass())))
		{
			return c;
		}
	}
	return nullptr;
	
}

bool AOmegaToolActor::SetToolActive(bool bActive)
{
	if (bActive!=b_isActive)
	{
		b_isActive=bActive;
		
		K2_OnActivate(b_isActive);
		if (b_isActive)
		{
			if (Preset.GetObject())
			{
				IDataInterface_Tool::Execute_Tool_OnActivate(Preset.GetObject(),this,true);
			}
			L_PlayMontage(ToolEvent_Activate);
		}
		else
		{
			if (Preset.GetObject())
			{
				IDataInterface_Tool::Execute_Tool_OnActivate(Preset.GetObject(),this,false);
			}
			L_PlayMontage(ToolEvent_Deactivate);
		}
		return true;	
	}
	return false;
}

bool AOmegaToolActor::CanTrigger()
{
	if (Preset.GetObject()) { return IDataInterface_Tool::Execute_Tool_CanTrigger(Preset.GetObject(),this);}
	return K2_CanTrigger();
}

void AOmegaToolActor::SetPreset(TScriptInterface<IDataInterface_Tool> _preset)
{
	Preset=_preset;
}

bool AOmegaToolActor::K2_CanTrigger_Implementation()
{
	return true;
}

UAnimMontage* AOmegaToolActor::L_PlayMontage(EOmegaToolEvents Anim)
{
	UAnimMontage* out=nullptr;
	if (USkeletalMeshComponent* smc= GetToolOwnerSkeletalMesh())
	{
		FOmegaTool_EventAssets EventAssets;
		if (Preset.GetObject())
		{
			 IDataInterface_Tool::Execute_GetTool_EventAssets(Preset.GetObject(),Anim,EventAssets);
		}
		else
		{
			GetToolEventAssets(Anim,EventAssets);
		}
		
		if (EventAssets.Sound)
		{
			UAudioComponent* sc=UGameplayStatics::SpawnSoundAttached(EventAssets.Sound,this->GetRootComponent());
			if (sc)
			{
				sc->Play();
			}
		}
		
		if (EventAssets.Montage)
		{
			if (UAnimInstance* animInst=smc->GetAnimInstance())
			{
				animInst->Montage_Play(EventAssets.Montage);
				out=EventAssets.Montage;
			}
		}
	}
	return out;
}


void UOmegaToolComponent::L_PlayMontageReturn(EOmegaToolEvents anim, FGameplayTag Slot, bool bSkip, TFunction<void()> OnComplete)
{
	bool success=false;
	if (!bSkip)
	{
		if (AOmegaToolActor* inst=Slot_GetToolInstance(Slot))
		{
			if (UAnimMontage* montage=inst->L_PlayMontage(anim))
			{
				if (USkeletalMeshComponent* smc=inst->GetToolOwnerSkeletalMesh())
				{
					if (UAnimInstance* animInst=smc->GetAnimInstance())
					{
						animInst->Montage_Play(montage);
						FOnMontageBlendingOutStarted BlendOutDelegate;
						BlendOutDelegate.BindLambda([OnComplete](UAnimMontage*, bool)
						{
							OnComplete();
						});
						animInst->Montage_SetBlendingOutDelegate(BlendOutDelegate, montage);
						success=true;
					}
				}
			}
		}
	}
	if (!success)
	{
		OnComplete();
	}
}


void UOmegaToolComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UOmegaToolComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UOmegaToolComponent::Slot_IsChangingTool(FGameplayTag Slot)
{
	return ChangingSlots.Contains(Slot);
}

AOmegaToolActor* UOmegaToolComponent::Slot_GetToolInstance(FGameplayTag Slot)
{
	if (ToolInstances.Contains(Slot))
	{
		return ToolInstances[Slot];
	}
	return nullptr;
}

void UOmegaToolComponent::Slot_SetToolActive(FGameplayTag Slot, bool ToolActive)
{
	if (AOmegaToolActor* inst=Slot_GetToolInstance(Slot))
	{
		inst->SetToolActive(ToolActive);
	}
}

bool UOmegaToolComponent::Slot_SetTool(TSubclassOf<AOmegaToolActor> Tool, TScriptInterface<IDataInterface_Tool> Preset,
                                       FGameplayTag Slot, bool bSkipUnequipAnim, bool bSkipEquipAnim)
{
	if (Tool && !Slot_IsChangingTool(Slot))
	{
		ChangingSlots.Add(Slot);
		//unequip anim
		if (AOmegaToolActor* inst=Slot_GetToolInstance(Slot))
		{
			OnToolUnequip_Begin.Broadcast(this,inst);
		}
		L_PlayMontageReturn(ToolEvent_Unequip,Slot,bSkipUnequipAnim,[this, Slot, Tool, Preset, bSkipEquipAnim]()
		{
			//REMOVE old tool
			if (AOmegaToolActor* inst=Slot_GetToolInstance(Slot))
			{
				OnToolUnequip_End.Broadcast(this,inst);
				inst->K2_DestroyActor();
			}
			//SPAWN AND ADD new tool
			if (AOmegaToolActor* newInst=GetWorld()->SpawnActorDeferred<AOmegaToolActor>(Tool,FTransform()))
			{
				ToolInstances.Add(Slot,newInst);
				newInst->OwningComponent=this;
				newInst->SetPreset(Preset);
				
				newInst->FinishSpawning(FTransform());	
				newInst->AttachToActor(GetOwner(),FAttachmentTransformRules(EAttachmentRule::SnapToTarget,false));
				OnToolEquip_Begin.Broadcast(this,newInst);
			}	
			//play equip anim
			L_PlayMontageReturn(ToolEvent_Equip,Slot,bSkipEquipAnim,[this, Slot, Tool]()
			{
				if (AOmegaToolActor* inst=Slot_GetToolInstance(Slot))
				{
					OnToolEquip_End.Broadcast(this,inst);
				}
				//mark slot as no longer changing
				if (ChangingSlots.Contains(Slot))
				{
					ChangingSlots.Remove(Slot);
				}
			});
		});
	}
	return false;
}

bool UOmegaToolComponent::Slot_SetToolFromPreset(TScriptInterface<IDataInterface_Tool> Preset, FGameplayTag Slot, bool bSkipUnequipAnim, bool bSkipEquipAnim)
{
	if (Preset.GetObject())
	{
		if (TSubclassOf<AOmegaToolActor> toolClass=IDataInterface_Tool::Execute_GetToolActorClass(Preset.GetObject()))
		{
			return Slot_SetTool(toolClass,Preset,Slot, bSkipUnequipAnim, bSkipEquipAnim);
		}
	}
	return false;
}

bool UOmegaToolComponent::Slot_Clear(FGameplayTag Slot)
{
	if (ToolInstances.Contains(Slot))
	{
		if (AOmegaToolActor* inst=ToolInstances[Slot])
		{
			
		}
	}
	return false;
}

AOmegaToolActor_FirstPerson::AOmegaToolActor_FirstPerson()
{
	ArmsMesh=CreateOptionalDefaultSubobject<USkeletalMeshComponent>("ArmsMesh");
	ArmsMesh->SetupAttachment(RootComponent);
	if (USkeletalMesh* _sk=LoadObject<USkeletalMesh>(nullptr,TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/arms/SK_Mannequin_DEMO_Arms.SK_Mannequin_DEMO_Arms")))
	{
		ArmsMesh->SetSkeletalMesh(_sk);
	}
	GripRoot=CreateOptionalDefaultSubobject<USceneComponent>("GripRoot");
	GripRoot->SetupAttachment(ArmsMesh,"Slot_HandR");
}
