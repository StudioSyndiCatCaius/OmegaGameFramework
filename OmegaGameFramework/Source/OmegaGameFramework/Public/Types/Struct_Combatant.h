
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Struct_Combatant.generated.h"

class AOmegaGrid3D_Tile;
class UCombatantComponent;
class UOmegaAttribute;
class UOmegaDamageType;
class AOmegaGameplayEffect;

USTRUCT(BlueprintType)
struct FOmegaEffectContainer
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	TSubclassOf<AOmegaGameplayEffect> EffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	float Power = 1.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	FGameplayTagContainer AddedTags;
};

USTRUCT(BlueprintType)
struct FOmegaCombatantEventMeta
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatantEvent")
	UCombatantComponent* TargetSingle=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatantEvent")
	TArray<UCombatantComponent*> TargetList;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatantEvent")
	AOmegaGrid3D_Tile* TileSingle=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatantEvent")
	TArray<AOmegaGrid3D_Tile*> TileList;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatantEvent")
	FOmegaCommonMeta CommonMeta;
	
};

