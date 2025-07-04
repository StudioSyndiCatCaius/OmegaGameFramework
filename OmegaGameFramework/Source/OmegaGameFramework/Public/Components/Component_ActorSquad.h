// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "Component_ActorSquad.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UActorSquad_Identity : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:


	
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSquadData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<AActor*> Members;
	
};


class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSquadMembersChanged, UActorSquadComponent*, Component, AActor*, Actor, bool, bInSquad);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent),DisplayName="*DEPRECATED* - Squad")
class OMEGAGAMEFRAMEWORK_API UActorSquadComponent : public UActorComponent
{
	GENERATED_BODY()

	UActorSquad_Identity* ValidateSquadID(UActorSquad_Identity* override) const;

public:
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintAssignable) FOnSquadMembersChanged OnSquadMembersChanged;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad")
	UActorSquad_Identity* Default_SquadID;

	UPROPERTY(VisibleInstanceOnly,Category="Squad")
	TMap<UActorSquad_Identity*,FOmegaSquadData> SquadData;
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	TArray<AActor*> GetSquadMembers(UActorSquad_Identity* Squad);

	UFUNCTION(BlueprintCallable,Category="Squad", meta=(AdvancedDisplay="SquadA"))
	TArray<UPrimaryDataAsset*> GetSquadMemberAssets(UActorSquad_Identity* Squad);

	UFUNCTION(BlueprintCallable,Category="Squad", meta=(AdvancedDisplay="SquadA"))
	void SetSquadOrder_FromAssets(TArray<UPrimaryDataAsset*> Order, UActorSquad_Identity* Squad);
	
	UFUNCTION(BlueprintCallable,Category="Squad", meta=(AdvancedDisplay="SquadA"))
	void SetActorInSquad(AActor* Actor, bool bInSquad, UActorSquad_Identity* Squad);

	UFUNCTION(BlueprintCallable,Category="Squad", meta=(AdvancedDisplay="SquadA"))
	void SwapSquadMembers_ByIndex(int32 A, int32 B, UActorSquad_Identity* Squad);
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SwapSquadMembers_ByAsset(UPrimaryDataAsset* A, UPrimaryDataAsset* B, UActorSquad_Identity* Squad);
	
	UFUNCTION(BlueprintCallable,Category="Squad", meta=(AdvancedDisplay="SquadA"))
	AActor* GetMember_ByAsset(UPrimaryDataAsset* Asset, UActorSquad_Identity* Squad);
	
	UFUNCTION(BlueprintCallable,Category="Squad", meta=(AdvancedDisplay="SquadA"))
	int32 GetMemberIndex_ByAsset(UPrimaryDataAsset* Asset, UActorSquad_Identity* Squad);
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API USquadSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


public:


	
};
