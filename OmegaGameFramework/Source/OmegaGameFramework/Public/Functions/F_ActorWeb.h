// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "F_Math.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Types/Struct_ActorLink.h"
#include "F_ActorWeb.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaWebActor : public AActor
{
	GENERATED_BODY()

public:
	AOmegaWebActor();

	void InitID()
	{
		if (ID<=0)
		{
			ID=UKismetMathLibrary::RandomInteger(999999);
		}
	}
	virtual void OnConstruction(const FTransform& Transform) override
	{
		InitID();
	}
	virtual void BeginPlay() override
	{
		InitID();
	}

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") USceneComponent* Root;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Web") int32 ID;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Web") TArray<AOmegaWebActor*> Connections;
};

USTRUCT(BlueprintType)
struct FOmegaActorWeb_Cache
{
	GENERATED_BODY()
	
	UPROPERTY() TArray<FOmegaActorLink> links;
	
	TArray<AOmegaWebActor*> GetActors();
	
	static FVector2D GetLinePointFromActor(AOmegaWebActor* actor);
};


UCLASS()
class UOmegaFunctions_ActorWeb : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static bool CacheHasLink(FOmegaActorWeb_Cache cache, AOmegaWebActor* a,AOmegaWebActor* b);
	
	UFUNCTION(BlueprintPure,Category="Omega|ActorWeb",DisplayName="Actor Web - Create Cache")
	static FOmegaActorWeb_Cache CreateCache(TArray<AOmegaWebActor*> actors);
	
	UFUNCTION(BlueprintPure,Category="Omega|ActorWeb",DisplayName="Actor Web - Get Lines")
	static TArray<FOmegaLine> GetLines(FOmegaActorWeb_Cache cache);
	
};