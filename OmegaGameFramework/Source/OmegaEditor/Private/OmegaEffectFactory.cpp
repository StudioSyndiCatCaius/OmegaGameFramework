// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaEffectFactory.h"
//The asset header file that we wish to create
#include "Actors/Actor_GameplayEffect.h"
//The asset type categories will let us access the various asset categories inside the Editor
#include "AssetTypeCategories.h"
#include "CanvasItem.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "CanvasTypes.h"
#include "TextureResource.h"
#include "GlobalRenderResources.h"
#include "Engine/Texture2D.h"
#include "UnrealClient.h"
#include "Interfaces/I_AssetThumbnail.h"
#include "Misc/GeneralDataObject.h"
#include "Widget/UI_Widgets.h"

UDataItemThumbnailRender::UDataItemThumbnailRender(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FSlateBrush local_GetIcon(UObject* object)
{
	if(!FUObjectThreadContext::Get().IsRoutingPostLoad)
	{
		if(object && !object->HasAllFlags(RF_NeedPostLoadSubobjects) &&  object->GetClass()->ImplementsInterface(UDataInterface_AssetThumbnail::StaticClass()))
		{
		
			return IDataInterface_AssetThumbnail::Execute_GetThumbnail_Brush(object);
		}
	}
	return FSlateBrush();
}


FText local_GetText(UObject* object)
{
	if(object && object->GetClass()->ImplementsInterface(UDataInterface_AssetThumbnail::StaticClass()))
	{
		return IDataInterface_AssetThumbnail::Execute_GetThumbnail_Text(object);
	}
	return FText();
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
				FLinearColor bkg_tint=FLinearColor::White;
				if(!FUObjectThreadContext::Get().IsRoutingPostLoad)
				{
					if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_AssetThumbnail::StaticClass()))
					{
						GridTexture=IDataInterface_AssetThumbnail::Execute_GetThumbnailBack_Texture(Object);
						bkg_tint=IDataInterface_AssetThumbnail::Execute_GetThumbnailBack_Tint(Object);
					}
				}
				if (GridTexture == nullptr)
				{
					GridTexture = LoadObject<UTexture2D>(nullptr, TEXT("/OmegaGameFramework/Textures/ui/T_UI_Omega_IconBack1.T_UI_Omega_IconBack1"), nullptr, LOAD_None, nullptr);
				}

				const bool bAlphaBlend = false;
				
				Canvas->DrawTile(
					(float)X,
					(float)Y,
					(float)Width,
					(float)Height,
					0.0f,
					0.0f,
					1.0f,
					1.0f,
					bkg_tint,
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
					
				Canvas->DrawShadowedText(5,5,local_GetText(Object),GEngine->GetMediumFont(),FLinearColor::White);
			
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

USlateStyleThumbnailRender::USlateStyleThumbnailRender(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void USlateStyleThumbnailRender::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height,
	FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	if (Object)
	{
		if (UOmegaSlateStyle* style=Cast<UOmegaSlateStyle>(Object))
		{
			DrawBrushToCanvas(style->GetMainSlateBrush(), X, Y, Width, Height, Canvas);
		}
	}
}

void USlateStyleThumbnailRender::DrawBrushToCanvas(const FSlateBrush& Brush, int32 X, int32 Y, uint32 Width,
	uint32 Height, FCanvas* Canvas)
{
	UObject* Resource = Brush.GetResourceObject();
	if (!Resource) return;

	const FLinearColor TintColor = Brush.TintColor.GetSpecifiedColor();
	const FVector2D DrawPosition(X, Y);
	const FVector2D DrawSize(Width, Height);

	// --- Case 1: Texture2D ---
	if (UTexture2D* Texture = Cast<UTexture2D>(Resource))
	{
		FTextureResource* TextureResource = Texture->GetResource();
		if (!TextureResource) return;

		// Just use full UVs — GetUVRegion() is inaccessible in UE5.5
		FCanvasTileItem TileItem(
			DrawPosition,
			TextureResource,
			DrawSize,
			FVector2D(0.f, 0.f),
			FVector2D(1.f, 1.f),
			TintColor
		);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
	// --- Case 2: Material ---
	else if (UMaterialInterface* Material = Cast<UMaterialInterface>(Resource))
	{
		FCanvasTileItem TileItem(DrawPosition, Material->GetRenderProxy(), DrawSize);
		//TileItem.SetColor(TintColor);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
}
