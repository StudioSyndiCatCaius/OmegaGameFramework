// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_DebugText.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Global.h"
#include "Misc/OmegaUtils_Macros.h"


void UComponent_DebugText::UpdateText()
{
	SetText(OGF_GLOBAL_SETTINGS()->Actor_GetDebugText(GetOwner()));
}

// Sets default values for this component's properties
UComponent_DebugText::UComponent_DebugText()
{
	bHiddenInGame=true;
	TextMaterial=LoadObject<UMaterialInterface>(nullptr,TEXT("/OmegaGameFramework/Materials/Shaders/Util/m_UTIL_TextOutline.m_UTIL_TextOutline"));
	SetRelativeLocation(FVector(0,-100,0));
	FText txt_in=FText::FromString("");
	SetText(txt_in);
}

#if WITH_EDITOR
void UComponent_DebugText::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	UpdateText();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif


// Called when the game starts
void UComponent_DebugText::BeginPlay()
{
	UpdateText();
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComponent_DebugText::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

