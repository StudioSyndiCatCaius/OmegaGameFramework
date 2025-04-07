// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UserWidget_DynamicImage.h"

void UDynamicImage_Widget::NativePreConstruct()
{
	if(ImageMaterial && ImageTexture && GetWidget_Image())
	{
		GetWidget_Image()->SetBrushFromMaterial(ImageMaterial);
		GetWidget_Image()->GetDynamicMaterial()->SetTextureParameterValue(ImageParamName,ImageTexture);
	}
	if(USizeBox* _sb = GetWidget_SizeBox())
	{
		_sb->SetWidthOverride(Size_Default.X);
		_sb->SetHeightOverride(Size_Default.Y);
		if(Size_Max!=FVector2D::Zero())
		{
			_sb->SetMaxDesiredWidth(Size_Max.X);
			_sb->SetMaxDesiredHeight(Size_Max.Y);
		}
		if(Size_Min!=FVector2D::Zero())
		{
			_sb->SetMinDesiredWidth(Size_Min.X);
			_sb->SetMinDesiredHeight(Size_Min.Y);
		}
	}
	Super::NativePreConstruct();
}
