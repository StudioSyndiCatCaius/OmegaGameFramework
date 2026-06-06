#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EngineUtils.h"
#include "Dom/JsonObject.h"
#include "Struct_CustomLevel.generated.h"


USTRUCT(BlueprintType)
struct FOmegaCustomLevelSaveConfig
{
	GENERATED_BODY()

public:
	//if empty, allow all
	UPROPERTY(VisibleAnywhere,Category="CustomLevel") TArray<TSubclassOf<AActor>> WhitelistActorClasses;
	//if empty, allow all
	UPROPERTY(VisibleAnywhere,Category="CustomLevel") TArray<FName> WhitelistActorTags;
	UPROPERTY(VisibleAnywhere,Category="CustomLevel") TArray<TSubclassOf<AActor>> BlacklistActorClasses;
	UPROPERTY(VisibleAnywhere,Category="CustomLevel") TArray<FName> BlacklistActorTags;
	UPROPERTY() bool bSavePlayerPawn=false;
	
};


USTRUCT(BlueprintType)
struct FOmegaCustomLevelWrapper
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly,Category="CustomLevel") TObjectPtr<UWorld> WorldReference = nullptr;
	UPROPERTY(VisibleAnywhere,Category="CustomLevel") FString WorldName = "";
	UPROPERTY(VisibleAnywhere,Category="CustomLevel") FString WorldPackagePath = "";
	
	bool DeserializeFromJson(const FString& JsonString, TArray<TSharedPtr<FJsonValue>>& OutActorArray);
	bool SpawnActors(const TArray<TSharedPtr<FJsonValue>>& ActorArray);
	
	void CachePackagePath();
	bool ResolveWorldReference();
	bool SaveToJson(FString& JsonString, const FOmegaCustomLevelSaveConfig& Config = FOmegaCustomLevelSaveConfig());
	bool LoadFromJson(const FString& JsonString);
};

