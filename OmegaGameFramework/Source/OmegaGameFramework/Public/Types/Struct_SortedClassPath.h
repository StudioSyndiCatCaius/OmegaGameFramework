
#pragma once

#include "CoreMinimal.h"

#include "Struct_SortedClassPath.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSortedClassPathData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	FString AssetPrefex;
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	FString AssetSuffex;
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	TArray<FString> AssetPaths;
	
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	bool AutoscanPathsOnStartup=true;
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	FString ExternalFileDirectoryName;
	
	UPROPERTY(EditAnywhere,Instanced,Category="SortedClassData")
	TArray<UOmegaPathAssetScript*> AssetScripts;
	
	UObject* getAssetFromPath(const FString& AssetPath, TSubclassOf<UObject> Class);
};


UCLASS(Blueprintable,BlueprintType,Abstract,CollapseCategories,Const,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaPathAssetScript : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent,Category="Omega|Paths")
	UObject* OnGetAssetByPath(const FString& path, TSubclassOf<UObject> Class) const;
};

