// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaEffectFactory.h"
//The asset header file that we wish to create
#include "Actors/Actor_GameplayEffect.h"
//The asset type categories will let us access the various asset categories inside the Editor
#include "AssetTypeCategories.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "OmegaDataItem.h"
#include "CanvasTypes.h"
#include "TextureResource.h"
#include "GlobalRenderResources.h"
#include "Engine/Texture2D.h"
#include "UnrealClient.h"
#include "Misc/GeneralDataObject.h"

UDataItemThumbnailRender::UDataItemThumbnailRender(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FSlateBrush local_GetIcon(UObject* object)
{
	if(UOmegaDataItem* DataItem = Cast<UOmegaDataItem>(object))
	{
		return DataItem->Icon;
	}
	if(UOmegaDataAsset* DataItem = Cast<UOmegaDataAsset>(object))
	{
		return DataItem->Icon;
	}
	return FSlateBrush();
}

void UDataItemThumbnailRender::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	if (Object != nullptr)
	{
		FSlateBrush icon=local_GetIcon(Object);
		if(UTexture2D* ResTexture = Cast<UTexture2D>(icon.GetResourceObject()))
		{
			UTexture2D* TileSheetTexture = ResTexture;
		const bool bUseTranslucentBlend = TileSheetTexture->HasAlphaChannel();

		// Draw the grid behind the sprite
		if (bUseTranslucentBlend)
		{
			static UTexture2D* GridTexture = nullptr;
			if (GridTexture == nullptr)
			{
				GridTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Engine/EngineMaterials/DefaultWhiteGrid.DefaultWhiteGrid"), nullptr, LOAD_None, nullptr);
			}

			const bool bAlphaBlend = false;

			Canvas->DrawTile(
				(float)X,
				(float)Y,
				(float)Width,
				(float)Height,
				0.0f,
				0.0f,
				4.0f,
				4.0f,
				FLinearColor::White,
				GridTexture->GetResource(),
				bAlphaBlend);
		}

		// Draw the sprite itself
		const float TextureWidth = TileSheetTexture->GetSurfaceWidth();
		const float TextureHeight = TileSheetTexture->GetSurfaceHeight();

		const FMargin Margin = icon.Margin;

		float FinalX = (float)X;
		float FinalY = (float)Y;
		float FinalWidth = (float)Width;
		float FinalHeight = (float)Height;
		const float DesiredWidth = TextureWidth - Margin.GetDesiredSize().X;
		const float DesiredHeight = TextureHeight - Margin.GetDesiredSize().Y;

		const FLinearColor BlackBarColor(0.0f, 0.0f, 0.0f, 0.5f);

		if (DesiredWidth > DesiredHeight)
		{
			const float ScaleFactor = Width / DesiredWidth;
			FinalHeight = ScaleFactor * DesiredHeight;
			FinalY += (Height - FinalHeight) * 0.5f;

			// Draw black bars (on top and bottom)
			const bool bAlphaBlend = true;
			Canvas->DrawTile(X, Y, Width, FinalY-Y, 0, 0, 1, 1, BlackBarColor, GWhiteTexture, bAlphaBlend);
			Canvas->DrawTile(X, FinalY+FinalHeight, Width, Height-FinalHeight, 0, 0, 1, 1, BlackBarColor, GWhiteTexture, bAlphaBlend);
		}
		else
		{
			const float ScaleFactor = Height / DesiredHeight;
			FinalWidth = ScaleFactor * DesiredWidth;
			FinalX += (Width - FinalWidth) * 0.5f;

			// Draw black bars (on either side)
			const bool bAlphaBlend = true;
			Canvas->DrawTile(X, Y, FinalX-X, Height, 0, 0, 1, 1, BlackBarColor, GWhiteTexture, bAlphaBlend);
			Canvas->DrawTile(FinalX+FinalWidth, Y, Width-FinalWidth, Height, 0, 0, 1, 1, BlackBarColor, GWhiteTexture, bAlphaBlend);
		}

		// Draw the tile sheet 
		const float InvWidth = 1.0f / TextureWidth;
		const float InvHeight = 1.0f / TextureHeight;
		Canvas->DrawTile(
			FinalX,
			FinalY,
			FinalWidth,
			FinalHeight,
			Margin.Left * InvWidth,
			Margin.Top * InvHeight,
			(TextureWidth - Margin.Right) * InvWidth,
			(TextureHeight - Margin.Bottom) * InvHeight,
			FLinearColor::White,
			TileSheetTexture->GetResource(),
			bUseTranslucentBlend);
return;
		// Draw a label overlay
		//@TODO: Looks very ugly: DrawShadowedStringZ(Canvas, X, Y + Height * 0.8f, 1.0f, TEXT("Tile\nSet"), GEngine->GetSmallFont(), FLinearColor::White);
		}
	}
	//Super::Draw(Object, X, Y,  Width,  Height, Viewport, Canvas, bAdditionalViewFamily);
}

bool UDataItemThumbnailRender::CanVisualizeAsset(UObject* Object)
{
	FSlateBrush icon=local_GetIcon(Object);
	if(icon.GetResourceObject())
	{
		return true;
	}
	return false;
	return Super::CanVisualizeAsset(Object);
}