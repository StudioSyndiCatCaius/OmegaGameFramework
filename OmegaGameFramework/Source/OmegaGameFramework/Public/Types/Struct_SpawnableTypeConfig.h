
#pragma once

#include "CoreMinimal.h"
#include "LuaValue.h"
#include "Struct_Bitflag.h"


#include "Engine/Texture2D.h"
#include "Struct_SpawnableTypeConfig.generated.h"

class UOmegaSubsystem_World;

USTRUCT(BlueprintType, Atomic)
struct FOmegaSpawnableTypeConfig
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) TSoftClassPtr<AActor> Class;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FLinearColor Color=FLinearColor::White;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FVector RangeOffset;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FVector RangeSize=FVector(50,50,95);
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) float LineThickness=1;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) TSoftObjectPtr<UTexture2D> Icon;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) float IconSize=2;
	
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FOmegaBitmaskEditorData Bitmask_Config;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) TArray<FName> NamedLists;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) TArray<FName> ActorRelatives;
	
	void SetFromLua(FLuaValue lua);
};


