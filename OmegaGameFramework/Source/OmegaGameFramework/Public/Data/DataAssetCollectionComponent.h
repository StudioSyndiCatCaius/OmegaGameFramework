// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "DataAssetCollectionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetAdded, UDataAsset*, Asset, int32, Amount, bool, IsFull);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetRemoved, UDataAsset*, Asset, int32, Amount, bool, IsEmpty);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDataAssetCollectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	bool NativeAddAsset(UDataAsset* Asset);

	UFUNCTION()
	bool NativeRemoveAsset(UDataAsset* Asset);

	UPROPERTY()
	TMap<UDataAsset*, int32> CollectionMap;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Ω|Data")
	void AddAsset(UDataAsset* Asset, int32 Amount=1);

	UFUNCTION(BlueprintCallable, Category = "Ω|Data")
	void RemoveAsset(UDataAsset* Asset, int32 Amount=1);

	UFUNCTION(BlueprintPure, Category = "Ω|Data")
	int32 GetAssetNumberOfType(UDataAsset* Asset);

	UFUNCTION(BlueprintPure, Category = "Ω|Data")
	int32 GetAssetNumberTotal();

	UFUNCTION(BlueprintPure, meta = (DeterminesOutputType="Asset"), Category = "Ω|Data")
	TArray<UDataAsset*> GetCollectionAsArray(UDataAsset* Asset);

	UFUNCTION(BlueprintCallable, Category = "Ω|Data")
	void SetCollectionMap(TMap<UDataAsset*, int32> Map);
	
	UFUNCTION(BlueprintPure, Category = "Ω|Data")
	TMap<UDataAsset*, int32> GetCollectionMap();

	UPROPERTY(BlueprintAssignable)
	FOnAssetAdded OnAssetAdded;
	UPROPERTY(BlueprintAssignable)
	FOnAssetRemoved OnAssetRemoved;
		
};
