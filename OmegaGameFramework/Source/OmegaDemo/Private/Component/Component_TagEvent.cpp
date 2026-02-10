// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Component_TagEvent.h"

#include "Subsystems/Subsystem_Save.h"


UOmegaSaveGame* UComponent_TagEvent::L_GetSave() const
{
	return GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->ActiveSaveData;
}

bool UComponent_TagEvent::L_SaveBool_Get(const FString& name) const
{
	//return L_GetSave()->GuidJson.FindOrAdd(GetOwner()->GetActorGuid()).JsonObject->GetBoolField(name);
	return false;
}

void UComponent_TagEvent::L_SaveBool_Set(const FString& name, bool val) const
{
	///L_GetSave()->GuidJson.FindOrAdd(GetOwner()->GetActorGuid()).JsonObject->SetBoolField(name,val);
}
/*
void UTagEventComponent_Destroy::BeginPlay()
{
	Super::BeginPlay();
	if(L_SaveBool_Get(var_nam))
	{
		GetOwner()->K2_DestroyActor();
	}
}

void UTagEventComponent_Destroy::OnTagEvent_Implementation(FGameplayTag Event)
{
	if(Event==TagEvent)
	{
		if(SaveState)
		{
			L_SaveBool_Set(var_nam,true);
		}
		GetOwner()->K2_DestroyActor();
	}
	Super::OnTagEvent_Implementation(Event);
}
*/