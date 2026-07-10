// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/Struct_InputConfig.h"

#include "F_Player.generated.h"

class AOmegaPlayer;

UCLASS()
class UOmegaPlayerFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Converts a 2D screen position to a world location then applies a 3D Offset, returning the final world position. */
	UFUNCTION(BlueprintCallable,Category="Omega|Player")
	static FVector OffsetScreenPositionToWorld(APlayerController* Player, FVector2D ScreenPosition,FVector Offset);

	/** Calculates the world-space rotation a player would need to look from Start to Target on screen,
	 *  optionally offsetting both points into 3D space via Start_Offset and End_Offset. */
	UFUNCTION(BlueprintCallable,Category="Omega|Player",meta=(AdvancedDisplay="Start_Offset, End_Offset"))
	static FRotator GetRotationFrom2DDirection(APlayerController* Player, FVector2D Start,FVector2D Target, FVector Start_Offset,FVector End_Offset);

	/** Returns the OmegaPlayer pawn for the given player Index (0 = first local player). */
	UFUNCTION(BlueprintPure,Category="Omega|Player",meta=(WorldContext="WorldContextObject",CompactNodeTitle="🕹️Player"))
	static AOmegaPlayer* GetOmegaPlayer(UObject* WorldContextObject, int32 Index);

	/** Returns all OmegaPlayer pawns currently in the world. */
	UFUNCTION(BlueprintPure,Category="Omega|Player",meta=(WorldContext="WorldContextObject",CompactNodeTitle="🕹️Players"))
	static TArray<AOmegaPlayer*> GetAllOmegaPlayers(UObject* WorldContextObject);

	// =====================================================================================================================
	// Mouse
	// =====================================================================================================================

	/** Performs a world-space trace originating from the mouse position as seen through a SceneCapture2D component.
	 *  Useful for clicking in a secondary render target (e.g. minimap or split view).
	 *  TraceDistance: maximum trace depth. Returns the closest hit result. */
	UFUNCTION(BlueprintPure,Category="Omega|Mouse",meta=(AdvancedDisplay="TraceComplex, TraceDistance"))
	static FHitResult MouseHitForSceneCapture(APlayerController* Player, USceneCaptureComponent2D* SceneCapture, ETraceTypeQuery TraceType,
		bool TraceComplex, bool OnlyVisibleActorsAndComponents, float TraceDistance=10000.0f);

	/** Returns the mouse cursor's position normalized to the viewport (0,0 = top-left, 1,1 = bottom-right). */
	UFUNCTION(BlueprintPure,Category="Omega|Mouse",meta=(AdvancedDisplay="TraceComplex, TraceDistance"))
	static FVector2D Mouse_GetNormalizedPosition(APlayerController* PlayerController);

	// =====================================================================================================================
	// Keys
	// =====================================================================================================================

	//if `Player` is invalid, get first player via WorldContextObject
	UFUNCTION(BlueprintCallable,Category="Omega|Input",meta=(ExpandBoolAsExecs="bResult",AdvancedDisplay="Player",WorldContext="WorldContextObject"))
	static bool WasKeyJustPressed(UObject* WorldContextObject,FKey Key,bool& bResult, APlayerController* Player) ;
	
	UFUNCTION(BlueprintCallable,Category="Omega|Input",meta=(ExpandBoolAsExecs="bResult",AdvancedDisplay="Player",WorldContext="WorldContextObject"))
	static bool WasInputActionJustPressed(UObject* WorldContextObject,UPARAM(meta=(Categories="INPUT")) FGameplayTag Input,bool& bResult, APlayerController* Player) ;
	
	/** Sums the weights of all currently pressed keys in the map.
	 *  b1Clamped: clamp the result to [-1, 1]. Useful for simulating analog input from digital keys. */
	UFUNCTION(BlueprintPure,Category="Omega|Keys",meta=(AdvancedDisplay="input"))
	static float Keys_CombinePressedWeights(TMap<FKey,float> Keys, bool b1Clamped, APlayerController* PlayerController);

	/** Adds or removes the Target object from the Enhanced Input system's active input targets for this player. */
	UFUNCTION(BlueprintCallable,Category="Omega|Keys",meta=(AdvancedDisplay="input"))
	static void SetInputActionTargetActive(APlayerController* Player, UObject* Target, bool bActive);

	/** Reads the axis value of a Key (e.g. a gamepad stick axis) into a 3D vector.
	 *  OutAxis receives the raw axis value. Deadzone filters out small unintended inputs. Returns true if above deadzone. */
	UFUNCTION(BlueprintCallable,Category="Omega|Keys",meta=(AdvancedDisplay="input"))
	static bool GetKeyAxis(APlayerController* Player, FKey Key, FVector& OutAxis, float Deadzone=0.05);

	/** Returns all keys currently bound to the input action identified by the given gameplay tag. */
	UFUNCTION(BlueprintCallable,Category="Omega|Keys",meta=(WorldContext="WorldContextObject"))
	static TArray<FKey> GetKeysFromInputAction(UObject* WorldContextObject,UPARAM(meta=(Categories="INPUT")) FGameplayTag InputAction);

	/** Returns the first bound key for the given input action tag that matches the desired device type (gamepad or keyboard/mouse). */
	UFUNCTION(BlueprintCallable,Category="Omega|Keys",meta=(WorldContext="WorldContextObject"))
	static FKey GetFirstDeviceKeyFromInputAction(UObject* WorldContextObject,UPARAM(meta=(Categories="INPUT")) FGameplayTag InputAction, bool bGamepad);

	/** Returns the full OmegaInputConfig (display name, icon, etc.) for the input action identified by the given gameplay tag. */
	UFUNCTION(BlueprintCallable,Category="Omega|Keys",meta=(WorldContext="WorldContextObject"))
	static FOmegaInputConfig GetInputActionConfig(UObject* WorldContextObject,UPARAM(meta=(Categories="INPUT")) FGameplayTag InputAction);

	UFUNCTION(BlueprintCallable,Category="Omega|Input")
	static bool SimulateInputAction(APlayerController* Player,UPARAM(meta=(Categories="INPUT")) FGameplayTag InputAction, float Duration=0.1f);
	
	/** Registers Object as the exclusive input hog for the given PlayerController, blocking all other input consumers until the hog is cleared. */
	UFUNCTION(BlueprintCallable,Category="Omega|Input|Hog",meta=(WorldContext="WorldContextObject"))
	static void ObjectHogInput_Set(UObject* Object, APlayerController* player);

	/** Releases the current input hog from the given PlayerController, restoring normal input routing. */
	UFUNCTION(BlueprintCallable,Category="Omega|Input|Hog",meta=(WorldContext="WorldContextObject"))
	static void ObjectHogInput_Clear(APlayerController* player);
};
