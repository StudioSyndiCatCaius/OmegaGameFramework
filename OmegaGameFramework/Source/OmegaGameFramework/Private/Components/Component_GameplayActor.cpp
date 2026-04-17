// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_GameplayActor.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "OmegaSettings.h"
#include "OmegaGameManager.h"
#include "Functions/F_Component.h"
#include "Functions/F_Lua.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_World.h"

const uint8 SUBSCRIPT_EVENT_BEGINPLAY=0;
const uint8 SUBSCRIPT_EVENT_ENDPLAY=1;
const uint8 SUBSCRIPT_EVENT_BEGINOVERLAP=2;
const uint8 SUBSCRIPT_EVENT_ENDOVERLAP=3;
const uint8 SUBSCRIPT_EVENT_TAGEVENT=4;
const uint8 SUBSCRIPT_EVENT_HIT=5;


void USubscript::ActorBeginOverlap_Implementation(UGameplayActorComponent* OwningComponent, AActor* OverlappedActor) const {}
void USubscript::ActorEndOverlap_Implementation(UGameplayActorComponent* OwningComponent, AActor* OverlappedActor) const {}
void USubscript::ActorHit_Implementation(UGameplayActorComponent* OwningComponent, AActor* SelfActor,
	AActor* OtherActor, FVector Vector, const FHitResult& hit) const {}
void USubscript::OnBeginPlay_Implementation(UGameplayActorComponent* OwningComponent) const {}
void USubscript::OnEndPlay_Implementation(UGameplayActorComponent* OwningComponent) const {}
void USubscript::Tick_Implementation(float Delta, UGameplayActorComponent* OwningComponent) const{}
void USubscript::OnTagEvent_Implementation(UGameplayActorComponent* OwningComponent, FGameplayTag Event) const {}

TArray<USubscript*> FOmegaSubscripts::GetSubscripts() const
{
	TArray<USubscript*> out;
	for (auto* p :Preset)
	{
		if (p)
		{
			out.Append(p->Subscripts);
		}
	}
	out.Append(Inline);
	return out;
}

void FOmegaSubscripts::EventCall(uint8 event, UGameplayActorComponent* component, AActor* other_actor,FGameplayTag tag,FHitResult hit)
{
	for (auto* p :GetSubscripts())
	{
		if (p)
		{
			switch (event)
			{
			case SUBSCRIPT_EVENT_BEGINPLAY: p->OnBeginPlay(component); break;
			case SUBSCRIPT_EVENT_ENDPLAY: p->OnEndPlay(component); break;
			case SUBSCRIPT_EVENT_BEGINOVERLAP: p->ActorBeginOverlap(component,other_actor); break;
			case SUBSCRIPT_EVENT_ENDOVERLAP: p->ActorEndOverlap(component,other_actor); break;
			case SUBSCRIPT_EVENT_TAGEVENT: p->OnTagEvent(component,tag); break;
			case SUBSCRIPT_EVENT_HIT: p->ActorHit(component,component->GetOwner(),other_actor,FVector(),hit); break;
			}		
		}
	}
}

void UGameplayActorComponent::L_Init()
{
	if(IdentitySource)
	{
		if(Local_IsSourceAssetValid())
		{
			IDataInterface_ActorIdentitySource::Execute_OnIdentityInit(IdentitySource,GetOwner(),this);
		}
	}
}


void UGameplayActorComponent::L_TimerEnd()
{
	if(UOmegaSubsystem_World* sub=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
	{
		for(FGameplayTag t : DefaultConfig->AutoregisterToGroups)
		{
			sub->SetActorRegisteredToGroup(t,GetOwner(),true);
		}
			
		FActorModifiers amods;
		amods.Script=DefaultConfig->BeginPlay_Modifiers;
		amods.ApplyMods(GetOwner());
	}
}


void UGameplayActorComponent::SetConfig(UOmegaActorConfig* Config)
{
	if(Config)
	{
		DefaultConfig=Config;
	}
	else
	{
		DefaultConfig=nullptr;
	}
	if(DefaultConfig)
	{
		float _inVal=DefaultConfig->BeginPlayMod_Delay.GetValue();
		if(_inVal>0.0)
		{
			GetWorld()->GetTimerManager().SetTimer(timer_modDelay,this, &UGameplayActorComponent::L_TimerEnd,_inVal);	
		}
		else
		{
			L_TimerEnd();
		}
		
	}
}


bool UGameplayActorComponent::Local_IsSourceAssetValid() const
{
	if(IdentitySource && IdentitySource->GetClass()->ImplementsInterface(UDataInterface_ActorIdentitySource::StaticClass()))
	{
		return true;
	}
	return false;
}

bool UGameplayActorComponent::L_SourceUsesGeneralInterface() const
{
	if (IdentitySource && IdentitySource->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		return true;
	}
	return false;
}

void UGameplayActorComponent::Local_RunConstruct()
{
	if (!Guid.IsValid())
	{
		Guid=FGuid::NewGuid();
	}
	SetIdentitySourceAsset(IdentitySource);
	OGF_GAME_CORE()->ActorID_OnConstruct(GetOwner(),this);
	if(Local_IsSourceAssetValid())
	{
		IdentityFlags.override_source=IdentitySource;
		IDataInterface_ActorIdentitySource::Execute_OnActorConstruction(IdentitySource,GetOwner(),this);
		for(auto* i : Local_GetScripts())
		{
			if(i) { i->OnActorConstruction(GetOwner(),this); }
		}
	}
	else
	{
		IdentityFlags.override_source=nullptr;
	}
}

TArray<UActorIdentityScript*> UGameplayActorComponent::Local_GetScripts() const
{
	TArray<UActorIdentityScript*> out;
	if(Local_IsSourceAssetValid())
	{
		return IDataInterface_ActorIdentitySource::Execute_GetIdentityScripts(IdentitySource);
	}
	return out;
}

UOmegaActorConfig* UGameplayActorComponent::L_GetConfig()
{
	if (UOmegaActorConfig* _Newconfig= GetMutableDefault<UOmegaSettings>()->ActorConfig_PerClass
		.FindOrAdd(TSoftClassPtr<AActor>(GetOwner()->GetClass())).LoadSynchronous())
	{
		return _Newconfig;
	}
	return DefaultConfig;
}

void UGameplayActorComponent::OnRegister()
{
	Super::OnRegister();
	Local_RunConstruct();
}

UGameplayActorComponent::UGameplayActorComponent()
{
	PrimaryComponentTick.bCanEverTick=true;
}

void UGameplayActorComponent::SetIdentitySourceAsset(UPrimaryDataAsset* SourceAsset)
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

void UGameplayActorComponent::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	if (L_SourceUsesGeneralInterface())
	{
		Execute_GetGeneralDataText(IdentitySource,Tag,Name,Description);
	}
	if (!OverrideName.IsEmpty())
	{
		Name=OverrideName;
	}
}

void UGameplayActorComponent::GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture,
	class UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if (L_SourceUsesGeneralInterface())
	{
		Execute_GetGeneralDataImages(IdentitySource,Tag,Texture,Material,Brush);
	}
}

void UGameplayActorComponent::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if (L_SourceUsesGeneralInterface())
	{
		Execute_GetGeneralAssetLabel(IdentitySource,Label);
	}
}

void UGameplayActorComponent::OnTagEvent_Implementation(FGameplayTag Event)
{
	if(Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorTagEvent(IdentitySource,GetOwner(),this,Event);
	}
	IActorTagEventInterface::OnTagEvent_Implementation(Event);
	Subscripts.EventCall(SUBSCRIPT_EVENT_TAGEVENT,this,nullptr,Event);
}

void UGameplayActorComponent::OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if (Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorInteract(IdentitySource,GetOwner(),this,InteractInstigator,Tag,Context);
	}
}

bool UGameplayActorComponent::IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if (Local_IsSourceAssetValid())
	{
		return IDataInterface_ActorIdentitySource::Execute_IsInteractBlocked(IdentitySource,GetOwner(),this,InteractInstigator,Tag,Context);
	}
	return false;
}

#if WITH_EDITOR
void UGameplayActorComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Local_RunConstruct();
	if(PropertyChangedEvent.GetPropertyName()=="IdentitySource")
	{
		L_Init();
	}
	//Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void UGameplayActorComponent::BeginPlay()
{
	Super::BeginPlay();
	temp_table=ULuaBlueprintFunctionLibrary::LuaCreateTable(this,nullptr);
	SetConfig(L_GetConfig());
	Local_RunConstruct();
	GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->local_RegisterActorIdComp(this,true);
	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &UGameplayActorComponent::OnActorBeginOverlap);
	GetOwner()->OnActorEndOverlap.AddDynamic(this, &UGameplayActorComponent::OnActorEndOverlap);
	GetOwner()->OnActorHit.AddDynamic(this, &UGameplayActorComponent::OnActorHit);
	OGF_GAME_CORE()->ActorID_OnBeginPlay(GetOwner(),this);
	if(Local_IsSourceAssetValid())
	{
		IDataInterface_ActorIdentitySource::Execute_OnActorBeginPlay(IdentitySource,GetOwner(),this);
		for(auto* i : Local_GetScripts())
		{
			if(i) { i->OnActorBeginPlay(GetOwner(),this); }
		}
	}
	else
	{
	}
	Subscripts.EventCall(SUBSCRIPT_EVENT_BEGINPLAY,this);
}

void UGameplayActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Destroyed)
	{
		if(GetWorld() && GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
		{
			GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->local_RegisterActorIdComp(this,false);
		}
		Subscripts.EventCall(SUBSCRIPT_EVENT_ENDPLAY,this);
	}
	Super::EndPlay(EndPlayReason);
}

void UGameplayActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
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
	for (auto i : Subscripts.GetSubscripts())
	{
		if (i)
		{
			i->Tick(DeltaTime,this);
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGameplayActorComponent::OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Subscripts.EventCall(SUBSCRIPT_EVENT_BEGINPLAY,this,OverlappedActor);
}

void UGameplayActorComponent::OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Subscripts.EventCall(SUBSCRIPT_EVENT_ENDPLAY,this,OverlappedActor);
}

void UGameplayActorComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	Subscripts.EventCall(SUBSCRIPT_EVENT_HIT,this,OtherActor,FGameplayTag(),Hit);
}

void UGameplayActorComponent::SetBool(FString param, bool Value)
{
	temp_table.SetField(param,Value);
}

void UGameplayActorComponent::SetInt(FString param, int32 Value)
{
	temp_table.SetField(param,Value);
}

void UGameplayActorComponent::SetFloat(FString param, float Value)
{
	temp_table.SetField(param,Value);
}

void UGameplayActorComponent::SetVector(FString param, FVector Value)
{
	temp_table.SetField(param,ULuaBlueprintFunctionLibrary::Conv_VectorToLua(this,Value));
}

bool UGameplayActorComponent::GetBool(FString param)
{
	return temp_table.GetField(param).ToBool();
}

int32 UGameplayActorComponent::GetInt(FString param)
{
	return temp_table.GetField(param).ToInteger();
}

float UGameplayActorComponent::GetFloat(FString param)
{
	return temp_table.GetField(param).ToFloat();
}

FVector UGameplayActorComponent::GetVector(FString param)
{
	return ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(temp_table.GetField(param),FVector());
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
		for (auto* c : WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetAllActorIdentityComponents())
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
		if(UGameplayActorComponent* _comp = Cast<UGameplayActorComponent>(Actor->GetComponentByClass(UGameplayActorComponent::StaticClass())))
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

