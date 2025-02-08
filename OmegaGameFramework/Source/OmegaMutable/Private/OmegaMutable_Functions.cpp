// Fill out your copyright notice in the Description page of Project Settings.

#include "OmegaMutable_Functions.h"


void UOmegaMutablesFunctions::SetMutable_FromSource(UCustomizableSkeletalComponent* Component, UObject* Source)
{
	if(Component && Source && Source->GetClass()->ImplementsInterface(UDataInterface_MutableSource::StaticClass()))
	{
		Component->SetCustomizableObjectInstance(IDataInterface_MutableSource::Execute_GetCustomizableObjectInstance(Source));
	}
}
