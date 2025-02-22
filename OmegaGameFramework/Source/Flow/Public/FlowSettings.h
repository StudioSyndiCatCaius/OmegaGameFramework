// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "Engine/DeveloperSettings.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Templates/SubclassOf.h"
#include "FlowSettings.generated.h"

class UFlowNode;

/**
 *
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Flow"))
class UFlowSettings final : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

	static UFlowSettings* Get() { return CastChecked<UFlowSettings>(UFlowSettings::StaticClass()->GetDefaultObject()); }

	// Set if to False, if you don't want to create client-side Flow Graphs
	// And you don't access to the Flow Component registry on clients
	UPROPERTY(Config, EditAnywhere, Category = "Networking")
	bool bCreateFlowSubsystemOnClients;

	// How many nodes of given class should be preloaded with the Flow Asset instance?
	UPROPERTY(Config, EditAnywhere, Category = "Preload")
	TMap<TSubclassOf<UFlowNode>, int32> DefaultPreloadDepth;
	
	UPROPERTY(Config, EditAnywhere, Category = "SaveSystem")
	bool bWarnAboutMissingIdentityTags;
};


UCLASS()
class UFlowFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Flow")
	static TArray<UFlowAsset*> FilterFlowAssetsWithTrait(TArray<UFlowAsset*> in, TSubclassOf<UFlowAssetTrait> Trait);

	UFUNCTION(BlueprintCallable,Category="Flow",meta=(ExpandEnumAsExecs="Result",DeterminesOutputType="Class"))
	static UFlowAssetTrait* GetFirstAssetTrait(UFlowAsset* FlowAsset, TSubclassOf<UFlowAssetTrait> Class, TEnumAsByte<EOmegaFunctionResult>& Result);
};
