// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Materials.h"
#include "Engine/Texture2D.h"
#include "ImageUtils.h"
#include "RenderUtils.h"

void UOmegaMaterialFunctions::ApplyMaterialsToSlots(UPrimitiveComponent* Component,
	TMap<FName, UMaterialInterface*> Materials)
{
	if(Component)
	{
		TArray<FName> SlotList;
		Materials.GetKeys(SlotList);
		for (FName TempSlot : SlotList)
		{
			if(Component->GetMaterialSlotNames().Contains(TempSlot))
			{
				Component->SetMaterial(Component->GetMaterialSlotNames().Find(TempSlot),Materials[TempSlot]);
			}
		}
		
	}
}

void UOmegaMaterialFunctions::ApplyDynamicMaterialParams(UMaterialInstanceDynamic* Material,
	FOmegaDynamicMaterialParams params)
{
	if(Material)
	{
		params.Apply(Material);
	}
}

// Define a log category for your texture operations
DEFINE_LOG_CATEGORY_STATIC(LogTextureOperations, Log, All);

TArray<FLinearColor> UOmegaTextureFunctions::GetTexturePixelColors(UTexture2D* Texture)
{
	TArray<FLinearColor> PixelColors;

    // Check if the texture is valid
    if (!Texture)
    {
        UE_LOG(LogTextureOperations, Error, TEXT("Texture is null!"));
        return PixelColors;  // Return empty array if the texture is invalid
    }

    // Check if platform data is available
    if (!Texture->GetPlatformData())
    {
        UE_LOG(LogTextureOperations, Error, TEXT("Texture has no platform data!"));
        return PixelColors;  // Return empty array if no platform data
    }

    // Get the first mip level
    FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];
    FByteBulkData* RawImageData = &Mip.BulkData;

    // Check if Mip level has pixel data
    if (!RawImageData)
    {
        UE_LOG(LogTextureOperations, Error, TEXT("Mip level has no bulk data!"));
        return PixelColors;  // Return empty array if no mip data
    }

    // Lock the texture data for reading
    void* Data = RawImageData->Lock(LOCK_READ_ONLY);
    if (!Data)
    {
        UE_LOG(LogTextureOperations, Error, TEXT("Failed to lock bulk data!"));
        return PixelColors;  // Return empty array if locking fails
    }

    // Get texture width, height, and total pixels
    const int32 Width = Mip.SizeX;
    const int32 Height = Mip.SizeY;
    const int32 TotalPixels = Width * Height;

    if (TotalPixels == 0)
    {
        UE_LOG(LogTextureOperations, Error, TEXT("Texture has no pixel data (0 width or height)!"));
        RawImageData->Unlock();
        return PixelColors;  // Return empty array if there are no pixels
    }

    // Determine the pixel format of the texture
    EPixelFormat PixelFormat = Texture->GetPixelFormat();
    if (PixelFormat != PF_B8G8R8A8 && PixelFormat != PF_R8G8B8A8)
    {
        UE_LOG(LogTextureOperations, Error, TEXT("Unsupported pixel format!"));
        RawImageData->Unlock();
        return PixelColors;  // Return empty array if format is unsupported
    }

    UE_LOG(LogTextureOperations, Log, TEXT("Texture size: %d x %d"), Width, Height);
    UE_LOG(LogTextureOperations, Log, TEXT("Pixel format: %d"), PixelFormat);

    // Read pixel data according to the pixel format
    if (PixelFormat == PF_B8G8R8A8 || PixelFormat == PF_R8G8B8A8)
    {
        uint8* PixelPtr = static_cast<uint8*>(Data);
        for (int32 i = 0; i < TotalPixels; ++i)
        {
            // Read BGRA or RGBA depending on format
            uint8 B = PixelPtr[i * 4 + 0];
            uint8 G = PixelPtr[i * 4 + 1];
            uint8 R = PixelPtr[i * 4 + 2];
            uint8 A = PixelPtr[i * 4 + 3];

            // Convert to FLinearColor
            PixelColors.Add(FLinearColor(R / 255.0f, G / 255.0f, B / 255.0f, A / 255.0f));
        }

        UE_LOG(LogTextureOperations, Log, TEXT("Successfully read %d pixels"), PixelColors.Num());
    }

    // Unlock the data after reading
    RawImageData->Unlock();

    return PixelColors;
}
