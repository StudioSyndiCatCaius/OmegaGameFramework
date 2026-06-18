// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "F_Trace.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Physics.generated.h"

class UOmegaScriptedTraceLogic;
class AOmegaGameplayCue;

USTRUCT(BlueprintType)
struct FOmegaPhysicsEventData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Physics") TSubclassOf<AOmegaGameplayCue> Cue;
	
};

UCLASS()
class UOmegaPhysicsSurfaceType : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Physics",meta=(Categories="Physics.Event",ForceInlineRow))
	TMap<FGameplayTag,FOmegaPhysicsEventData> EventData;
	
};

UCLASS()
class UOmegaPhysicsEvent : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Physics",meta=(Categories="Physics.Event",ForceInlineRow)) FGameplayTag EventTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Physics") FOmegaScriptedTrace TraceEvent;
	
	virtual FHitResult GetHit(AActor* Instigator); 
	
};


UCLASS()
class UOmegaAnimNotify_PhysicsEvent : public UAnimNotify
{
	GENERATED_BODY()
public:
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	virtual FString GetNotifyName_Implementation() const override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Physics",meta=(Categories="Physics.Event",ForceInlineRow))
	TSoftObjectPtr<UOmegaPhysicsEvent> Event;
};

UCLASS()
class UOmegaFunctions_Physics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Text",meta=(WorldContext="WorldContextObject"),DisplayName="💥Physics - Run Event")
	static void RunEvent(AActor* Instigator, UOmegaPhysicsEvent* Event);
	
	// ============================================================
	// HitResult
	// ============================================================
	UFUNCTION(BlueprintPure,Category="Omega|HitResult",meta=(AdvancedDisplay="X,Y,Z"))
	static FVector OffsetVector_FromHitResult(FHitResult Hit, FVector Offset, FRotator ExtraRotationOffset, bool bImpact=true);
	
	UFUNCTION(BlueprintPure,Category="Omega|HitResult",meta=(AdvancedDisplay="X,Y,Z"))
	static FRotator GetRotationFromHitResultNormal(FHitResult Hit, bool bImpact=true,bool X=true,bool Y=true,bool Z=true);
};