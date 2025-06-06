﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_InstancedActor.h"
#include "Functions/OmegaFunctions_Common.h"
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
	LocalActor->OnInstanceCreated(LocalContext, Flag);

	_instanceOrder.AddUnique(LocalActor);
	
	return LocalActor;
}

void UInstanceActorComponent::CreateInstances(TArray<UObject*> Contexts, const FString& Flag,
	FTransform LocalTransform)
{
	for(auto* i : Contexts)
	{
		if(i) { CreateInstance(i,Flag,LocalTransform);}
	}
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
		if(bExact)
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempInst).MatchesTagExact(CategoryTag); 
		}
		else
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempInst).MatchesTag(CategoryTag);
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
		if(bExact)
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempInst).HasAnyExact(Tags); 
		}
		else
		{
			LocalIsValid = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempInst).HasAny(Tags);
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



// Sets default values
AOmegaInstanceActor::AOmegaInstanceActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOmegaInstanceActor::BeginPlay()
{
	Super::BeginPlay();
	if(ContextObject)
	{
		ContextLabel = UOmegaGameFrameworkBPLibrary::GetObjectLabel(ContextObject);
		Context_Name = UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(ContextObject);
		Context_Description = UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(ContextObject);
		Context_Icon = UOmegaGameFrameworkBPLibrary::GetObjectIcon(ContextObject);
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

void AOmegaInstanceActor::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                            FText& Description)
{
	if(Local_SourceHasInterface())
	{
		IDataInterface_General::Execute_GetGeneralDataText(ContextObject, Label, Context, Name, Description);
	}
}

void AOmegaInstanceActor::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if(Local_SourceHasInterface())
	{
		IDataInterface_General::Execute_GetGeneralAssetLabel(ContextObject, Label);
	}
}

void AOmegaInstanceActor::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	if(Local_SourceHasInterface())
	{
		IDataInterface_General::Execute_GetGeneralAssetColor(ContextObject, Color);
	}
}

void AOmegaInstanceActor::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(Local_SourceHasInterface())
	{
		IDataInterface_General::Execute_GetGeneralDataImages(ContextObject, Label, Context, Texture, Material, Brush);
	}
}

FGameplayTag AOmegaInstanceActor::GetObjectGameplayCategory_Implementation()
{
	FGameplayTag LocalCategory;
	if(Local_SourceHasInterface())
	{
		LocalCategory = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(ContextObject);
	}
	return LocalCategory;
}

FGameplayTagContainer AOmegaInstanceActor::GetObjectGameplayTags_Implementation()
{
	FGameplayTagContainer LocalTags;
	if(Local_SourceHasInterface())
	{
		LocalTags = IGameplayTagsInterface::Execute_GetObjectGameplayTags(ContextObject);
	}
	return LocalTags;
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

