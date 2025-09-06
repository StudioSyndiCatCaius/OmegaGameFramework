// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorIdentity.h"

#include "Misc/OmegaUtils_Enums.h"
#include "Subsystems/OmegaSubsystem_Actors.h"

void UActorIdentityComponent::L_Init()
{
	if(IdentitySource)
	{
		if(Local_IsSourceAssetValid())
		{
			IDataInterface_ActorIdentitySource::Execute_OnIdentityInit(IdentitySource,GetOwner(),this);
		}
	}
}

bool UActorIdentityComponent::Local_IsSourceAssetValid() const
{
	if(IdentitySource && IdentitySource->GetClass()->ImplementsInterface(UDataInterface_ActorIdentitySource::StaticClass()))
	{
		return true;
	}
	return false;
}

TArray<UActorIdentityScript*> UActorIdentityComponent::Local_GetScripts() const
{
	TArray<UActorIdentityScript*> out;
	if(Local_IsSourceAssetValid())
	{
		return IDataInterface_ActorIdentitySource::Execute_GetIdentityScripts(IdentitySource);
	}
	return out;
}

void UActorIdentityComponent::SetIdentitySourceAsset(UPrimaryDataAsset* SourceAsset)
{
	if(IdentitySource)
	{
		if(Local_IsSourceAssetValid())
		{
			IDataInterface_ActorIdentitySource::Execute_OnIdentityUninit(IdentitySource,GetOwner(),this);
		}
	}
	if(SourceAsset!=IdentitySource)
	{
		if(SourceAsset)
		{
			IdentitySource=SourceAsset;
			L_Init();
		}
		else
		{
			IdentitySource=nullptr;
		}
		OnActorIdentityChanged.Broadcast(IdentitySource,this);
	}
}

void UActorIdentityComponent::OnTagEvent_Implementation(FGameplayTag Event)
{
	if(Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorTagEvent(IdentitySource,GetOwner(),this,Event);
	}
	IActorTagEventInterface::OnTagEvent_Implementation(Event);
}

#if WITH_EDITOR
void UActorIdentityComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	SetIdentitySourceAsset(IdentitySource);
	if(Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorConstruction(IdentitySource,GetOwner(),this);
		for(auto* i : Local_GetScripts())
		{
			if(i) { i->OnActorConstruction(GetOwner(),this); }
		}
	}
	if(PropertyChangedEvent.GetPropertyName()=="IdentitySource")
	{
		L_Init();
	}
	//Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void UActorIdentityComponent::BeginPlay()
{
	GetWorld()->GetSubsystem<UOmegaActorSubsystem>()->local_RegisterActorIdComp(this,true);
	if(Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorBeginPlay(IdentitySource,GetOwner(),this);
		for(auto* i : Local_GetScripts())
		{
			if(i) { i->OnActorBeginPlay(GetOwner(),this); }
		}
	}
	Super::BeginPlay();
}

void UActorIdentityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Destroyed)
	{
		if(GetWorld() && GetWorld()->GetSubsystem<UOmegaActorSubsystem>())
		{
			GetWorld()->GetSubsystem<UOmegaActorSubsystem>()->local_RegisterActorIdComp(this,false);
		}
	}
	Super::EndPlay(EndPlayReason);
}

void UActorIdentityComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	if(Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorTick(IdentitySource,GetOwner(),this,DeltaTime);
		for(auto* i : Local_GetScripts())
		{
			if(i) { i->OnActorTick(GetOwner(),this,DeltaTime); }
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

TArray<UActorIdentityScript*> UActorIdentityPreset::GetIdentityScripts_Implementation()
{
	TArray<UActorIdentityScript*> out;
	for(auto* i : PreSetup_Scripts)
	{
		if(i) { out.Append(i->GetIdentityScripts_Implementation());}
	}
	for(auto* i : Local_Scripts)
	{
		if(i) { out.Add(i);}
	}
	for(auto* i : PostSetup_Scripts)
	{
		if(i) { out.Append(i->GetIdentityScripts_Implementation());}
	}
	return out;
}


TArray<AActor*> UOmegaActorIdentityFunctions::GetAllActorsWithIdentity(UObject* WorldContextObject,
                                                                       UPrimaryDataAsset* Asset, TSubclassOf<AActor> FilterClass)
{
	TArray<AActor*> out;
	if (WorldContextObject && Asset)
	{
		for (auto* c : WorldContextObject->GetWorld()->GetSubsystem<UOmegaActorSubsystem>()->GetAllActorIdentityComponents())
		{
			if(c && c->IdentitySource==Asset && (!FilterClass || c->GetOwner()->GetClass()->IsChildOf(FilterClass)))
			{
				out.Add(c->GetOwner());
			}
		}
	}
	return out;
}

AActor* UOmegaActorIdentityFunctions::GetFirstActorWithIdentity(UObject* WorldContextObject, UPrimaryDataAsset* Asset,
	TSubclassOf<AActor> FilterClass, bool& Outcome)
{
	TArray<AActor*> list=GetAllActorsWithIdentity(WorldContextObject,Asset,FilterClass);
	if(list.IsValidIndex(0))
	{
		Outcome=true;
		return list[0];
	}
	Outcome=false;
	return nullptr;
}

UPrimaryDataAsset* UOmegaActorIdentityFunctions::GetActorIdentityAsset(AActor* Actor, bool& result,
	TSubclassOf<UPrimaryDataAsset> Class)
{
	TSubclassOf<UPrimaryDataAsset> in_class=UPrimaryDataAsset::StaticClass();
	if(Class) { in_class=Class;}

	if(Actor)
	{
		if(UActorIdentityComponent* _comp = Cast<UActorIdentityComponent>(Actor->GetComponentByClass(UActorIdentityComponent::StaticClass())))
		{
			if(UPrimaryDataAsset* _asset=_comp->GetIdentitySourceAsset())
			{
				if(_asset->GetClass()->IsChildOf(in_class))
				{
					result=true;
					return _asset;
				}
			}
		}
	}
	result=false;
	return nullptr;
}

