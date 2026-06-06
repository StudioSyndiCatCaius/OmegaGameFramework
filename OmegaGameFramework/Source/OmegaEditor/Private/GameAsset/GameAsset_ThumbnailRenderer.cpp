#include "GameAsset/GameAsset_ThumbnailRenderer.h"
#include "OmegaGameAsset.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "Engine/Texture2D.h"
#include "Styling/SlateBrush.h"
#include "ThumbnailRendering/ThumbnailManager.h"

bool UGameplayAssetThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
    return Object != nullptr && Object->IsA<UOmegaGameAsset>();
}

EThumbnailRenderFrequency UGameplayAssetThumbnailRenderer::GetThumbnailRenderFrequency(UObject* Object) const
{
    return EThumbnailRenderFrequency::Realtime;
}

void UGameplayAssetThumbnailRenderer::Draw(UObject* Object,
                                            int32 X, int32 Y,
                                            uint32 Width, uint32 Height,
                                            FRenderTarget* RenderTarget,
                                            FCanvas* Canvas,
                                            bool bAdditionalViewFamily)
{
    UOmegaGameAsset* Asset = Cast<UOmegaGameAsset>(Object);
    if (!Asset) return;

    const FLinearColor Color     = Asset->GetAssetColor();
    const FSlateBrush  Thumbnail = Asset->GetAssetThumbnail();

    // ── Background color fill ─────────────────────────────────────────────────
    FCanvasTileItem BgTile(FVector2D(X, Y), FVector2D(Width, Height), Color);
    BgTile.BlendMode = SE_BLEND_Opaque;
    Canvas->DrawItem(BgTile);

    // ── Custom thumbnail texture (if set) ─────────────────────────────────────
    UTexture2D* Texture = Cast<UTexture2D>(Thumbnail.GetResourceObject());
    if (Texture)
    {
        // Fit the texture inside the thumbnail while preserving aspect ratio
        const float TexW = static_cast<float>(Texture->GetSizeX());
        const float TexH = static_cast<float>(Texture->GetSizeY());
        const float Scale = FMath::Min(Width / TexW, Height / TexH);
        const float DrawW = TexW * Scale;
        const float DrawH = TexH * Scale;
        const float DrawX = X + (Width  - DrawW) * 0.5f;
        const float DrawY = Y + (Height - DrawH) * 0.5f;

        FCanvasTileItem TextureTile(
            FVector2D(DrawX, DrawY),
            Texture->GetResource(),
            FVector2D(DrawW, DrawH),
            FLinearColor::White);
        TextureTile.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TextureTile);
    }

    // ── Asset name label at the bottom ────────────────────────────────────────
    const FText AssetName = FText::FromString(Asset->GetName());
    const float FontScale = Width / 256.f; // scale text with thumbnail size
    UFont* Font = GEngine ? GEngine->GetSmallFont() : nullptr;
    if (Font)
    {
        int32 TextW = 0, TextH = 0;
        Font->GetStringHeightAndWidth(AssetName.ToString(), TextH, TextW);
        const float TextX = X + (Width  - TextW * FontScale) * 0.5f;
        const float TextY = Y +  Height - TextH * FontScale - 4.f;

        // Shadow
        FCanvasTextItem ShadowText(
            FVector2D(TextX + 1.f, TextY + 1.f), AssetName, Font,
            FLinearColor(0.f, 0.f, 0.f, 0.6f));
        ShadowText.Scale = FVector2D(FontScale, FontScale);
        Canvas->DrawItem(ShadowText);

        // Label
        FCanvasTextItem LabelText(
            FVector2D(TextX, TextY), AssetName, Font, FLinearColor::White);
        LabelText.Scale = FVector2D(FontScale, FontScale);
        Canvas->DrawItem(LabelText);
    }
}
