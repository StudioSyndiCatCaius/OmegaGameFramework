#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/ThumbnailRenderer.h"
#include "GameAsset_ThumbnailRenderer.generated.h"

UCLASS()
class UGameplayAssetThumbnailRenderer : public UThumbnailRenderer
{
    GENERATED_BODY()

public:
    // UThumbnailRenderer interface
    virtual void Draw(UObject* Object, int32 X, int32 Y,
                      uint32 Width, uint32 Height,
                      FRenderTarget* RenderTarget,
                      FCanvas* Canvas,
                      bool bAdditionalViewFamily) override;

    virtual bool CanVisualizeAsset(UObject* Object) override;
    virtual EThumbnailRenderFrequency GetThumbnailRenderFrequency(UObject* Object) const override;
};
