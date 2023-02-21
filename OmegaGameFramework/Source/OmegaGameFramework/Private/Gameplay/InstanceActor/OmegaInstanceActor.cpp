// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/InstanceActor/OmegaInstanceActor.h"

#include "Gameplay/InstanceActor/InstanceActorComponent.h"


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
	
}

// Called every frame
void AOmegaInstanceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// DATA INTERFACE

bool AOmegaInstanceActor::Local_SourceHasInterface() const
{
	return ContextObject->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass());	
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
}

