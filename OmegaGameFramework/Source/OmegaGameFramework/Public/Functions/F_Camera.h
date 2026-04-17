// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Actor.h"
#include "F_Camera.generated.h"

class AOmegaDynamicCamera;
class UCameraComponent;

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

	// -----------------------------------------------------------------------------------------------------------------
	// Dynamic Camera
	// -----------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="🎥Dynamic Camera - Set Active")
	static void DynamicCamera_SetActive(UObject* WorldContextObject, bool bActive,APlayerController* Player=nullptr);
	
	UFUNCTION(BlueprintPure,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="🎥Dynamic Camera - Is Active?")
	static bool DynamicCamera_IsActive(UObject* WorldContextObject, APlayerController* Player=nullptr);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player", ExpandBoolAsExecs = "Outcome"),DisplayName="🎥Dynamic Camera - Get MASTEE")
    static AOmegaDynamicCamera* GetDynamicCamera_Master(UObject* WorldContextObject, bool& Outcome, APlayerController* Player=nullptr);

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player", ExpandBoolAsExecs = "Outcome"),DisplayName="🎥Dynamic Camera - Get SOURCE")
	static AOmegaDynamicCamera* GetDynamicCamera_Source(UObject* WorldContextObject,bool& Outcome, APlayerController* Player=nullptr);

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="🎥Dynamic Camera - Set OVERRIDE")
	static bool SetDynamicCamera_Override(UObject* WorldContextObject, AOmegaDynamicCamera* SourceCamera, bool bSnapTo, APlayerController* Player=nullptr);
	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="🎥Dynamic Camera - Clear OVERRIDE")
	static bool ClearDynamicCamera_Override(UObject* WorldContextObject, APlayerController* Player=nullptr);

	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="🎥Dynamic Camera - Snap to SOURCE")
	static void DynamicCamera_SnapToSource(UObject* WorldContextObject, APlayerController* Player=nullptr);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Camera",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Player"),DisplayName="🎥Dynamic Camera - Snap View to MASTER")
	static bool SetViewTargetToDynamicCamera(UObject* WorldContextObject, APlayerController* Player=nullptr);
	
};
