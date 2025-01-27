// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Actor.h"
#include "OmegaFunctions_Camera.generated.h"

UCLASS()
class UOmegaCameraFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="Ω Project World to Screen (From Camera)")
	static FVector2D ProjectWorldToScreen_FromCamera(UObject* WorldContextObject, UCameraComponent* Camera, FVector Location,APlayerController* Player=nullptr);

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="Ω Set View Target (From Actor Ref)")
	static void SetViewTarget_Actor(UObject* WorldContextObject, AActor* Actor, float BlendTime, APlayerController* Player=nullptr);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="Ω Set View Target (From Global Binding)")
	static void SetViewTarget_ActorBinding(UObject* WorldContextObject, FName Binding, float BlendTime, APlayerController* Player=nullptr);

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="Ω Set View Target (From Soft Actor Ref)")
	static void SetViewTarget_SoftActor(UObject* WorldContextObject, TSoftObjectPtr<AActor> Actor, float BlendTime, APlayerController* Player=nullptr);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="Ω Set View Target (From Actor Selector)")
    static void SetViewTarget_ActorSelector(UObject* WorldContextObject, FOmegaActorSelectorData Selector, float BlendTime, APlayerController* Player=nullptr);
};
