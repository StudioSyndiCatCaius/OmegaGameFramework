// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Null.h"
#include "LuaCode.h"
#include "LuaInterface.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_BitFlag.h"
#include "Interfaces/I_Common.h"
#include "Interfaces/I_NamedLists.h"
#include "Types/Struct_ActorRelatives.h"
#include "Actor_Gameplay.generated.h"

class UBillboardComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayActor : public AOmegaBASEActor, public IDataInterface_BitFlag, public IDataInterface_NamedLists, public ILuaInterface, public IActorInterface_Relatives
{
	GENERATED_BODY()
	
	UPROPERTY() FLuaValue lua_value;

public:

	AOmegaGameplayActor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaBitflagsBase Flags;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaClassNamedLists Lists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay") FOmegaActorRelatives ActorRelatives;
	//A Lua script that returns from GetLuaValue() 
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaLuaCode Script;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UBillboardComponent* RootBillboard;
	
	virtual FOmegaActorRelatives ActorRelatives_Get_Implementation() override { return ActorRelatives; }
	virtual FOmegaBitflagsBase Bitflags_Get_Implementation() override { return Flags; };
	virtual FOmegaClassNamedLists GetClassNamedLists_Implementation() override { return Lists;};
	virtual FLuaValue GetValue_Implementation(const FString& Field) override;

};
