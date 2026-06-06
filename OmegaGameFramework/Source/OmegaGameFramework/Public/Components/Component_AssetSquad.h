// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "Component_AssetSquad.generated.h"

// Defines an identifiable squad group with an optional member cap. Used as a key to categorize asset assignments.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UAssetSquad_Identity : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Maximum number of members allowed in this squad. Set to -1 for unlimited.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad")
	int32 MaxMembers=-1;

};

// Holds the full squad assignment state: which squad is active, which assets belong to which squads, and their order.
USTRUCT(BlueprintType)
struct FOmegaAssetSquad_Data
{
	GENERATED_BODY()
	// The squad currently considered "active" or selected.
	UPROPERTY(EditAnywhere,Category="AssetSquad") UAssetSquad_Identity* CurrentSquad=nullptr;
	// Maps each asset to the squad it is assigned to.
	UPROPERTY(EditAnywhere,Category="AssetSquad") TMap<UPrimaryDataAsset*,UAssetSquad_Identity*> Assignments;
	// The ordered list of assets across all squads.
	UPROPERTY(EditAnywhere,Category="AssetSquad") TArray<UPrimaryDataAsset*> Order;
};

class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAssetSquadMembersChanged, UAssetSquadComponent*, Component, UAssetSquad_Identity*, Squad, UPrimaryDataAsset*, Member, bool, bInSquad);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetSquadMembersSwapped, UAssetSquadComponent*, Component, UPrimaryDataAsset*, A, UPrimaryDataAsset*, B);

// Manages assignment of data assets to named squads, supporting ordered rosters, membership limits, and save binding.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UAssetSquadComponent : public UActorComponent
{
	GENERATED_BODY()

	UAssetSquad_Identity* ValidateSquadID(UAssetSquad_Identity* override);
	int32 ValidateMember(UPrimaryDataAsset* member);
	void ValidateData();
	TArray<UAssetSquad_Identity*> L_GetListedSquads();

public:
	virtual void BeginPlay() override;
	// Fires when any asset is added to or removed from a squad.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnAssetSquadMembersChanged OnSquadMembersChanged;
	// Fires when two squad members swap positions.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnAssetSquadMembersSwapped OnAssetSquadMembersSwapped;

	// When true, an asset may only belong to one squad at a time.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad")
	bool OneSquadPerAsset=true;

	FOmegaAssetSquad_Data* L_GetSquadData();

	// When true, squad data is read from and written to the save system using SaveBinding as the key.
	UPROPERTY(EditAnywhere,Category="Squad")
	bool bBindToSave;
	// The save key used to persist squad data when bBindToSave is true.
	UPROPERTY(EditAnywhere,Category="Squad",meta=(EditCondition="bBindToSave"))
	FName SaveBinding;
	// The in-memory squad data used when not bound to a save slot.
	UPROPERTY(EditAnywhere,Category="Squad",meta=(EditCondition="!bBindToSave"))
	FOmegaAssetSquad_Data SquadData;

	// Initial squad member assignments set in the editor.
	UPROPERTY(EditAnywhere,Category="Squad")
	TMap<UPrimaryDataAsset*,UAssetSquad_Identity*> SquadMembers;

	// Sets the currently active squad.
	UFUNCTION(BlueprintCallable,Category="Squad")
	void CurrentSquad_Set(UAssetSquad_Identity* Squad);
	// Returns the currently active squad.
	UFUNCTION(BlueprintPure,Category="Squad")
	UAssetSquad_Identity* CurrentSquad_Get();

	// Replaces the entire squad data set with the supplied data.
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SetSquadData(FOmegaAssetSquad_Data Data);
	// Returns a copy of the current squad data.
	UFUNCTION(BlueprintCallable,Category="Squad")
	FOmegaAssetSquad_Data GetSquadData();

	// Removes all assets from the specified squad without destroying them.
	UFUNCTION(BlueprintCallable,Category="Squad")
	void RemoveAllMembersFromSquad(UAssetSquad_Identity* Squad);

	// Removes a single asset from every squad it belongs to.
	UFUNCTION(BlueprintCallable,Category="Squad")
	void RemoveMemberFromAllSquads(UPrimaryDataAsset* Member);

	// Adds or removes a single asset from the specified squad.
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SetMemberInSquad(UPrimaryDataAsset* Member, UAssetSquad_Identity* Squad,bool InSquad);

	// Adds or removes a list of assets from the specified squad in one call.
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SetMembersInSquad(TArray<UPrimaryDataAsset*> Members, UAssetSquad_Identity* Squad,bool InSquad);

	// Returns all assets currently assigned to the specified squad.
	UFUNCTION(BlueprintCallable,Category="Squad")
	TArray<UPrimaryDataAsset*> GetSquadMembers(UAssetSquad_Identity* Squad);

	// Returns the squad the given asset is currently assigned to, or null if unassigned.
	UFUNCTION(BlueprintPure,Category="Squad")
	UAssetSquad_Identity* GetMemberSquad(UPrimaryDataAsset* Member);

	// Returns the position (0-based) of the asset within the first squad it belongs to.
	UFUNCTION(BlueprintPure,Category="Squad")
	int32 GetMemberIndex_InFirstSquad(UPrimaryDataAsset* Member);

	// Returns true if the given asset is currently assigned to the specified squad.
	UFUNCTION(BlueprintPure,Category="Squad")
	bool IsMemberInSquad(UPrimaryDataAsset* Member,UAssetSquad_Identity* Squad);

	// Returns true if adding the asset to the squad would not exceed the squad's member limit.
	UFUNCTION(BlueprintPure,Category="Squad")
	bool CanAddMemberToSquad(UPrimaryDataAsset* Member,UAssetSquad_Identity* Squad);

	// Swaps the squad assignments and order positions of assets A and B.
	UFUNCTION(BlueprintCallable,Category="Squad",meta=(AdvancedDisplay="OrderOnly"))
	void SwapSquadMembers(UPrimaryDataAsset* A, UPrimaryDataAsset* B);

};
