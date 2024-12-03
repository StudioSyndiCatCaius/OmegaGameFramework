// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Graphics.h"

#include "Kismet/GameplayStatics.h"

float UOmegaGraphicsFunctions::RHIManagerSampleFunction(float Param)
{
	return -1;
}

void UOmegaGraphicsFunctions::SetGraphicsRHI(EGraphicsRHI GraphicsRHI)
{
	
	FString TargetPlataform = UGameplayStatics::GetPlatformName();
	FString DefaultGraphicsRHI;
	FString RHI_DX11(TEXT("DefaultGraphicsRHI_DX11"));
	FString RHI_DX12(TEXT("DefaultGraphicsRHI_DX12"));
	FString RHI_VULKAN(TEXT("DefaultGraphicsRHI_Vulkan"));

	if (TargetPlataform == "Windows")
	{
		GConfig->GetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), DefaultGraphicsRHI, GEngineIni);
		switch (GraphicsRHI)
		{
			case EGraphicsRHI::RHI_DX11 :
				if (DefaultGraphicsRHI != "DefaultGraphicsRHI_DX11")
				{
					GConfig->SetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), *RHI_DX11, GEngineIni);
					GConfig->Flush(true, GEngineIni);
					return;
				}
				return;

			case EGraphicsRHI::RHI_DX12 :
				if (DefaultGraphicsRHI != "DefaultGraphicsRHI_DX12")
				{
					GConfig->SetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), *RHI_DX12, GEngineIni);
					GConfig->Flush(true, GEngineIni);
					return;
				}
				return;

			case EGraphicsRHI::RHI_VULKAN :
				if (DefaultGraphicsRHI != "DefaultGraphicsRHI_Vulkan")
				{
					GConfig->SetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), *RHI_VULKAN, GEngineIni);
					GConfig->Flush(true, GEngineIni);
					return;
				}
				return;
		}
	}
	return;
}

EGraphicsRHI UOmegaGraphicsFunctions::GetCurrentGraphicsRHI()
{
	FString TargetPlataform = UGameplayStatics::GetPlatformName();
	FString DefaultGraphicsRHI;

	GConfig->GetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), DefaultGraphicsRHI, GEngineIni);

	if (DefaultGraphicsRHI == "DefaultGraphicsRHI_DX11")
	{
		return EGraphicsRHI::RHI_DX11;
	}
	else if (DefaultGraphicsRHI == "DefaultGraphicsRHI_DX12")
	{
		return EGraphicsRHI::RHI_DX12;
	}
	return EGraphicsRHI::RHI_VULKAN;
}