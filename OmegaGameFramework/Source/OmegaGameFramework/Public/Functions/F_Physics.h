// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "F_Trace.h"
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
	UPROPERTY(EditAnywhere,BlueprintReadWrite) TSubclassOf<AOmegaGameplayCue> Cue;
	
};

UCLASS()
class UOmegaPhysicsSurfaceType : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(Categories="Physics.Event",ForceInlineRow))
	TMap<FGameplayTag,FOmegaPhysicsEventData> EventData;
	
};

UCLASS()
class UOmegaPhysicsEvent : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(Categories="Physics.Event",ForceInlineRow)) FGameplayTag EventTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FOmegaScriptedTrace TraceEvent;
	
	virtual FHitResult GetHit(AActor* Instigator); 
	
};


UCLASS()
class UOmegaAnimNotify_PhysicsEvent : public UAnimNotify
{
	GENERATED_BODY()
public:
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	virtual FString GetNotifyName_Implementation() const override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(Categories="Physics.Event",ForceInlineRow))
	TSoftObjectPtr<UOmegaPhysicsEvent> Event;
};

UCLASS()
class UOmegaFunctions_Physics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Text",meta=(WorldContext="WorldContextObject"),DisplayName="💥Physics - Run Event")
	static void RunEvent(AActor* Instigator, UOmegaPhysicsEvent* Event);
	
};