// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Player.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "F_Player.generated.h"

UCLASS()
class UOmegaPlayerFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Player")
	static FVector OffsetScreenPositionToWorld(APlayerController* Player, FVector2D ScreenPosition,FVector Offset);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Player",meta=(AdvancedDisplay="Start_Offset, End_Offset"))
	static FRotator GetRotationFrom2DDirection(APlayerController* Player, FVector2D Start,FVector2D Target, FVector Start_Offset,FVector End_Offset);

	UFUNCTION(BlueprintPure,Category="Omega|Player",meta=(WorldContext="WorldContextObject"))
	static AOmegaPlayer* GetOmegaPlayer(UObject* WorldContextObject, int32 Index);
	
	UFUNCTION(BlueprintPure,Category="Omega|Player",meta=(WorldContext="WorldContextObject"))
	static TArray<AOmegaPlayer*> GetAllOmegaPlayers(UObject* WorldContextObject);

	// =====================================================================================================================
	// Mouse
	// =====================================================================================================================
	
	UFUNCTION(BlueprintPure,Category="Omega|Mouse",meta=(AdvancedDisplay="TraceComplex, TraceDistance"))
	static FHitResult MouseHitForSceneCapture(APlayerController* Player, USceneCaptureComponent2D* SceneCapture, ETraceTypeQuery TraceType, 
		bool TraceComplex, bool OnlyVisibleActorsAndComponents, float TraceDistance=10000.0f);
	
	UFUNCTION(BlueprintPure,Category="Omega|Mouse",meta=(AdvancedDisplay="TraceComplex, TraceDistance"))
	static FVector2D Mouse_GetNormalizedPosition(APlayerController* PlayerController);
	
	// =====================================================================================================================
	// Keys
	// =====================================================================================================================
	
	// b1Clamped means it is clamped between -1 & 1
	UFUNCTION(BlueprintPure,Category="Omega|Keys",meta=(AdvancedDisplay="input"))
	static float Keys_CombinePressedWeights(TMap<FKey,float> Keys, bool b1Clamped, APlayerController* PlayerController);

};
