// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_InstancedActor.h"
#include "Functions/F_Common.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"



UInstanceActorComponent::UInstanceActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	InstancedActorClass = AOmegaInstanceActor::StaticClass();
}

void UInstanceActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInstanceActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Destroyed)
	{
		for(auto* i : _instanceOrder)
		{
			if(i) { i->K2_DestroyActor();}
		}
	}
	Super::EndPlay(EndPlayReason);
}

void UInstanceActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

AOmegaInstanceActor* UInstanceActorComponent::CreateInstance(UObject* Context, const FString& Flag, FTransform LocalTransform)
{
	UObject* LocalContext;
	if(!Context)
	{
		LocalContext = nullptr;
	}
	else
	{
		LocalContext = Context;
	}

	AOmegaInstanceActor* LocalActor = GetWorld()->SpawnActorDeferred<AOmegaInstanceActor>(InstancedActorClass, LocalTransform, nullptr);
	LocalActor->ContextObject = LocalContext;
	LocalActor->OwningComponent = this;
	UGameplayStatics::FinishSpawningActor(LocalActor, LocalTransform);
	LocalActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
	LocalActor->SetActorRelativeTransform(LocalTransform);
	LocalActor->OnInstanceCreated(LocalActor, Flag);
	OnInstanceCreated.Broadcast(LocalActor);
	_instanceOrder.AddUnique(LocalActor);
#if WITH_EDITOR
	LocalActor->SetActorLabel(Instance_NamePrefex.ToString()+LocalContext->GetName());
#endif
	
	return LocalActor;
}

TArray<AOmegaInstanceActor*>  UInstanceActorComponent::CreateInstances(TArray<UObject*> Contexts, const FString& Flag,
	FTransform LocalTransform)
{
	TArray<AOmegaInstanceActor*> out;
	for(auto* i : Contexts)
	{
		if(i)
		{
			if (AOmegaInstanceActor* a=CreateInstance(i,Flag,LocalTransform))
			{
				out.Add(a);	
			}
		}
	}
	return out;
}

AOmegaInstanceActor* UInstanceActorComponent::TryGetInstanceByContext(UObject* Context, bool CreateIfInvalid,
	TSubclassOf<AOmegaInstanceActor> Class, bool& Result)
{
	if(Context)
	{
		Result=true;
		for(auto* i : GetInstances())
		{
			if(i && i->ContextObject == Context && (!Class || i->GetClass()->IsChildOf(Class)))
			{
				return i;
			}
		}
		if(CreateIfInvalid)
		{
			return CreateInstance(Context,"TryGet",FTransform());
		}
	}
	Result=false;
	return nullptr;
}

AOmegaInstanceActor* UInstanceActorComponent::GetInstanceByIndex(int32 Index)
{
	if(GetInstances().IsValidIndex(Index))
	{
		return GetInstances()[Index];
	}
	else
	{
		return nullptr;
	}
}

AOmegaInstanceActor* UInstanceActorComponent::GetInstanceByContext(UObject* Context)
{
	for(auto* TempInst : GetInstances())
	{
		if(TempInst->ContextObject == Context)
		{
			return TempInst;
		}
	}
	return nullptr;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstancesByContexts(TArray<UObject*> Contexts)
{
	TArray<AOmegaInstanceActor*> out;
	for(auto* s : Contexts)
	{
		if(s)
		{
			if(AOmegaInstanceActor* i = GetInstanceByContext(s))
			{
				out.Add(i);
			}
		}
	}
	return out;
}

AOmegaInstanceActor* UInstanceActorComponent::GetInstanceByName(const FString& Name)
{
	for(auto* TempInst : GetInstances())
	{
		
		if(UOmegaGameFrameworkBPLibrary::GetObjectLabel(TempInst) == Name)
		{
			return TempInst;
		}
	}
	return nullptr;
}

TArray<UObject*> UInstanceActorComponent::GetAllInstanceContexts()
{
	TArray<UObject*> out;
	for(auto* TempObj : GetInstances())
	{
		if(TempObj)
		{
			out.Add(TempObj->ContextObject);
		}
	}
	return out;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstances()
{
	TArray<AOmegaInstanceActor*> out;
	for(auto* i : _instanceOrder)
	{
		if(i) { out.Add(i);}
	}
	return out;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstancesOfCategory(FGameplayTag CategoryTag, bool bExclude, bool bExact)
{
	TArray<AOmegaInstanceActor*> OutInstances;
	for(auto* TempInst : GetInstances())
	{
		bool LocalIsValid = false;
		FGameplayTagContainer InstTags;
		FGameplayTag _cat;
		IDataInterface_General::Execute_GetObjectGameplayTags(TempInst, _cat, InstTags);
		if(bExact)
		{
			LocalIsValid = InstTags.HasTagExact(CategoryTag);
		}
		else
		{
			LocalIsValid = InstTags.HasTag(CategoryTag);
		}

		if(LocalIsValid != bExclude)
		{
			OutInstances.Add(TempInst);
		}
	}
	return OutInstances;
}

TArray<AOmegaInstanceActor*> UInstanceActorComponent::GetInstancesWithGameplayTags(FGameplayTagContainer Tags, bool bExclude,
	bool bExact)
{
	TArray<AOmegaInstanceActor*> OutInstances;
	for(auto* TempInst : GetInstances())
	{
		bool LocalIsValid = false;
		FGameplayTagContainer InstTags;
		FGameplayTag _cat;
		IDataInterface_General::Execute_GetObjectGameplayTags(TempInst, _cat, InstTags);
		if(bExact)
		{
			LocalIsValid = InstTags.HasAnyExact(Tags);
		}
		else
		{
			LocalIsValid = InstTags.HasAny(Tags);
		}

		if(LocalIsValid != bExclude)
		{
			OutInstances.Add(TempInst);
		}
	}
	return OutInstances;
}

bool UInstanceActorComponent::SwapInstanceIndecies(int32 A, int32 B)
{
	if(GetInstances().IsValidIndex(A) &&GetInstances().IsValidIndex(B))
	{
		_instanceOrder.Swap(A, B);
		return true;
	}
	return false;
}

void UInstanceActorComponent::SetInstanceOrder_ByLabels(TArray<FString> Labels)
{
	// Sort the local TArray<AActor*> by the order of the input Labels array
	_instanceOrder.Sort([&](const AOmegaInstanceActor& A, const AOmegaInstanceActor& B) {
		int32 IndexA = Labels.Find(A.ContextLabel);
		int32 IndexB = Labels.Find(B.ContextLabel);

		// If either actor's label is not found in the input Labels array, keep their relative order
		if (IndexA == INDEX_NONE)
			return false;
		if (IndexB == INDEX_NONE)
			return true;

		// Otherwise, sort by the index of the label in the input Labels array
		return IndexA < IndexB;
	});
}

TArray<FString> UInstanceActorComponent::GetInstanceOrder_ByLabels()
{
	TArray<FString> out;
	for(auto* TempInst : _instanceOrder)
	{
		out.Add(UOmegaGameFrameworkBPLibrary::GetObjectLabel(TempInst));
	}
	return out;
}

void UInstanceActorComponent::SetInstanceOrder_ByContexts(TArray<UObject*> Objects)
{
	// Sort the local TArray<AActor*> by the order of the input Labels array
	_instanceOrder.Sort([&](const AOmegaInstanceActor& A, const AOmegaInstanceActor& B) {
		int32 IndexA = Objects.Find(A.ContextObject);
		int32 IndexB = Objects.Find(B.ContextObject);

		// If either actor's label is not found in the input Labels array, keep their relative order
		if (IndexA == INDEX_NONE)
			return false;
		if (IndexB == INDEX_NONE)
			return true;

		// Otherwise, sort by the index of the label in the input Labels array
		return IndexA < IndexB;
	});
}

TArray<UObject*> UInstanceActorComponent::GetInstanceOrder_ByContexts()
{
	TArray<UObject*> out;
	for(auto* i : _instanceOrder)
	{
		if(i->ContextObject)
		{
			out.Add(i->ContextObject);
		};
	}
	return out;
}

void UInstanceActorComponent::TriggerNotify_OnAll(FName Notify)
{
	for(auto* temp_inst : GetInstances())
	{
		if(temp_inst)
		{
			temp_inst->TriggerNotify(Notify);
		}
	}
}

// ===========================================================================================================
// Instance Actor
// ===========================================================================================================



AOmegaInstanceActor::AOmegaInstanceActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

bool AOmegaInstanceActor::L_ContextUsesInterface() const
{
	if (ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_InstanceActor::StaticClass()))
	{
		return true;
	}
	return false;
}


void AOmegaInstanceActor::BeginPlay()
{
	Super::BeginPlay();
	if(ContextObject)
	{
		ContextLabel = UOmegaGameFrameworkBPLibrary::GetObjectLabel(ContextObject);
		Context_Name = UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(ContextObject,FGameplayTag());
		Context_Description = UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(ContextObject,FGameplayTag());
		Context_Icon = UOmegaGameFrameworkBPLibrary::GetObjectIcon(ContextObject,FGameplayTag());
		
		if (L_ContextUsesInterface())
		{
			IDataInterface_InstanceActor::Execute_InstanceActor_BeginPlay(ContextObject,this);
		}
	}
}

// Called every frame
void AOmegaInstanceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// DATA INTERFACE

bool AOmegaInstanceActor::Local_SourceHasInterface() const
{
	return ContextObject && ContextObject->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass());	
}

void AOmegaInstanceActor::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	if(Local_SourceHasInterface())
	{
		IDataInterface_General::Execute_GetGeneralDataText(ContextObject, Tag, Name, Description, iconBrush, Color, Label, MetaConfig);
	}
}

void AOmegaInstanceActor::GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags)
{
	if(Local_SourceHasInterface())
	{
		IDataInterface_General::Execute_GetObjectGameplayTags(ContextObject, OutCategoryTag, OutGameplayTags);
	}
}

void AOmegaInstanceActor::TriggerNotify(FName Notify)
{
	if(OwningComponent)
	{
		OwningComponent->OnInstanceNotify.Broadcast(this, Notify);
	}
	OnNotify(Notify);
}

AOmegaInstanceActor* UOmegaInstancedActorFunctions::GetFirstInstanceActorOfContext(UObject* WorldContextObject,
	UObject* Context, TSubclassOf<AOmegaInstanceActor> Class, bool& result)
{
	if(WorldContextObject)
	{
		TArray<AActor*> _instAcs;
		UGameplayStatics::GetAllActorsOfClass(WorldContextObject,AOmegaInstanceActor::StaticClass(),_instAcs);
		for(auto* a : _instAcs)
		{
			if(a && (a->GetClass()->IsChildOf(Class) || !Class))
			{
				if(AOmegaInstanceActor* _instA = Cast<AOmegaInstanceActor>(a))
				{
					if(_instA->ContextObject==Context)
					{
						result=true;
						return _instA;
					}
				}
			}
		}
	}
	result=false;
	return nullptr;
}

TArray<AOmegaInstanceActor*> UOmegaInstancedActorFunctions::GetInstanceActorsFromContexts(UObject* WorldContextObject,
	TArray<UObject*> Contexts, TSubclassOf<AOmegaInstanceActor> Class)
{
	TArray<AOmegaInstanceActor*> out;
	
	TArray<AActor*> _instAcs;
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject,AOmegaInstanceActor::StaticClass(),_instAcs);
	for(auto* a : _instAcs)
	{
		if(a && (a->GetClass()->IsChildOf(Class) || !Class))
		{
			if(AOmegaInstanceActor* _instA = Cast<AOmegaInstanceActor>(a))
			{
				if(Contexts.Contains(_instA->ContextObject))
				{
					out.Add(_instA);
				}
			}
		}
	}
	return out;
}

void AOmegaInstanceActor::OnNotify_Implementation(FName Notify)
{
}

