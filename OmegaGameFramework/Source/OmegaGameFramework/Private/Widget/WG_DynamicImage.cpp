// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget/WG_DynamicImage.h"

void UDynamicImage_Widget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	RefreshDynamicMaterial();
}

void UDynamicImage_Widget::RefreshDynamicMaterial()
{
	if (Material)
	{
		SetBrushFromMaterial(Material);
		MaterialParams.Apply(GetDynamicMaterial());
	}
}
