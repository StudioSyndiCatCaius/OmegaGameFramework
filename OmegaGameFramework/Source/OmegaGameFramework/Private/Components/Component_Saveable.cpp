// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Saveable.h"

#include "Subsystems/OmegaSubsystem_Save.h"


void UOmegaSaveableComponent::BeginPlay()
{
	LoadFromEntity();
	Super::BeginPlay();
}

UOmegaSaveableComponent::UOmegaSaveableComponent()
{
#if WITH_EDITOR
	if(!EntityGuid.IsValid() && GetOwner())
	{
		EntityGuid=GetOwner()->GetActorGuid();
	}
#endif
	if(!EntityGuid.IsValid())
	{
		EntityGuid=FGuid::NewGuid();
	}

}

UOmegaSaveSubsystem* UOmegaSaveableComponent::GetSaveSys() const
{
	if(GetWorld()->GetGameInstance())
	{
		return GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	}
	return nullptr;
}

UOmegaSaveBase* UOmegaSaveableComponent::GetSaveObj() const
{
	if(UOmegaSaveSubsystem* sys=GetSaveSys())
	{
		return sys->GetSaveObject(bSaveToGlobal);
	}
	return nullptr;
}

FOmegaEntity UOmegaSaveableComponent::GetEntityData() const
{
	if(UOmegaSaveBase* sav=GetSaveObj())
	{
		return sav->Entities.Entities_Guid.FindOrAdd(EntityGuid);
	}
	return FOmegaEntity();
}

void UOmegaSaveableComponent::SetEntityData(FOmegaEntity data)
{
	if(UOmegaSaveBase* sav=GetSaveObj())
	{
		sav->Entities.Entities_Guid.Add(EntityGuid,data);
	}
}

void UOmegaSaveableComponent::SaveToEntity()
{
	FOmegaEntity E=GetEntityData();
	if(bSave_Transform)
	{
		E.Transform=GetOwner()->GetTransform();
	}
	if(bSave_ActorTags)
	{
		E.Tags_Named=GetOwner()->Tags;
	}
	SetEntityData(E);
}

void UOmegaSaveableComponent::LoadFromEntity()
{
	FOmegaEntity E=GetEntityData();
	if(bSave_Transform)
	{
		if(E.Flag_Get(flag_SavPos))
		{
			GetOwner()->SetActorTransform(GetEntityData().Transform);
		}
	}
	if(bSave_ActorTags)
	{
		GetOwner()->Tags=E.Tags_Named;
	}
}

bool UOmegaSaveableComponent::GetSaveParam_Bool(FName Param) const
{
	return GetEntityData().params_int32.FindOrAdd(Param)>=1;
}

void UOmegaSaveableComponent::SetSaveParam_Bool(FName Param, bool Value)
{
	FOmegaEntity E=GetEntityData();
	E.params_int32.Add(Param,Value);
	SetEntityData(E);
}

int32 UOmegaSaveableComponent::GetSaveParam_Int(FName Param) const
{
	return GetEntityData().params_int32.FindOrAdd(Param);
}

void UOmegaSaveableComponent::SetSaveParam_Int(FName Param, int32 Value)
{
	FOmegaEntity E=GetEntityData();
	E.params_int32.Add(Param,Value);
	SetEntityData(E);
}
