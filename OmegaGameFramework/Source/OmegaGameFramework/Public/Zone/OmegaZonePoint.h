// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaZone.h"
#include "VolumeUtils.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "OmegaZonePoint.generated.h"


class UBrushComponent;
class UBillboardComponent;
class UBoxComponent;
class UOmegaZoneSubsystem;

UCLASS(DisplayName="Zone Transit Transit")
class OMEGAGAMEFRAMEWORK_API AOmegaZoneTransit : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaZoneTransit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//virtual void OnConstruction(const FTransform& Transform) override;

	virtual void OnConstruction(const FTransform& Transform) override;
	
	
public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone", meta=(EditCondition="!bTransitToLevel"))
	AOmegaZonePoint* TransitPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone", DisplayName="Transit To Level?")
	bool bTransitToLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zone", meta=(EditCondition="bTransitToLevel"))
	TSoftObjectPtr<UWorld> TransitLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zone", meta=(EditCondition="bTransitToLevel"))
	FGameplayTag LevelTransitID;

	UPROPERTY()
	UBoxComponent* Box_Transit;
	UPROPERTY()
	UBoxComponent* Box_Notify;
	UPROPERTY()
	UTextRenderComponent* TextComponent;

	UPROPERTY(EditAnywhere, Category="Display")
	float Box_X = 500;
	UPROPERTY(EditAnywhere, Category="Display")
	float Box_Y = 500;


protected:
	void UpdateBoxes();

	UPROPERTY()
	UOmegaZoneSubsystem* SubsysRef;

	UFUNCTION()
	void OnBoxTransitOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxNotifyOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxNotifyOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	
};

//################################################################################################################
//ZONE POINT
//################################################################################################################


UCLASS(DisplayName="Zone Spawn Point")
class OMEGAGAMEFRAMEWORK_API AOmegaZonePoint : public AActor, public IDataInterface_General
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	AOmegaZonePoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	FText PointName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
	TSoftObjectPtr<UWorld> FromLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	FGameplayTag ZonePointID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zone")
	UOmegaZoneData* ZoneToLoad;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
};