// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Component_AssetSquad.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAssetSquad_Identity : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad")
	int32 MaxMembers=-1;


	
};




USTRUCT(BlueprintType)
struct FOmegaAssetSquad_Data
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Category="AssetSquad") TMap<UAssetSquad_Identity*,FOmegaList_DataAsset> SquadMembers;
};


class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAssetSquadMembersChanged, UAssetSquadComponent*, Component, UAssetSquad_Identity*, Squad, UPrimaryDataAsset*, Member, bool, bInSquad);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UAssetSquadComponent : public UActorComponent
{
	GENERATED_BODY()

	UAssetSquad_Identity* ValidateSquadID(UAssetSquad_Identity* override) const;
	int32 ValidateMember(UPrimaryDataAsset* member);
	void ValidateData();
	TArray<UAssetSquad_Identity*> L_GetListedSquads() const;
	
public:
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintAssignable) FOnAssetSquadMembersChanged OnSquadMembersChanged;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad")
	UAssetSquad_Identity* Default_SquadID;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad")
	bool OneSquadPerAsset=true;
	
	UPROPERTY(EditAnywhere,Category="Squad")
	FOmegaAssetSquad_Data SquadData;
	
	UPROPERTY(EditAnywhere,Category="Squad")
	TMap<UPrimaryDataAsset*,UAssetSquad_Identity*> SquadMembers;
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SetSquadData(FOmegaAssetSquad_Data Data);
	UFUNCTION(BlueprintCallable,Category="Squad")
	FOmegaAssetSquad_Data GetSquadData();


	UFUNCTION(BlueprintCallable,Category="Squad")
	void RemoveMemberFromAllSquads(UPrimaryDataAsset* Member);
	
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SetMemberInSquad(UPrimaryDataAsset* Member, UAssetSquad_Identity* Squad,bool InSquad);

	UFUNCTION(BlueprintCallable,Category="Squad")
	TArray<UPrimaryDataAsset*> GetSquadMembers(UAssetSquad_Identity* Squad);
	
	UFUNCTION(BlueprintPure,Category="Squad")
	UAssetSquad_Identity* GetMemberSquad(UPrimaryDataAsset* Member);

	UFUNCTION(BlueprintPure,Category="Squad")
	int32 GetMemberIndex_InFirstSquad(UPrimaryDataAsset* Member);
	
	UFUNCTION(BlueprintPure,Category="Squad")
	bool IsMemberInSquad(UPrimaryDataAsset* Member,UAssetSquad_Identity* Squad);
	
	UFUNCTION(BlueprintPure,Category="Squad")
	bool CanAddMemberToSquad(UPrimaryDataAsset* Member,UAssetSquad_Identity* Squad);
	
	UFUNCTION(BlueprintCallable,Category="Squad",meta=(AdvancedDisplay="OrderOnly"))
	void SwapSquadMembers(UPrimaryDataAsset* A, UPrimaryDataAsset* B);

};
