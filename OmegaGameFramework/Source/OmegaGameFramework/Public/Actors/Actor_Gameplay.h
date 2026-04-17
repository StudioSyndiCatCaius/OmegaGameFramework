// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Null.h"
#include "LuaCode.h"
#include "LuaInterface.h"
#include "OmegaActors.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_Common.h"
#include "Types/Struct_ActorRelatives.h"
#include "Actor_Gameplay.generated.h"

class UBillboardComponent;
class UGameplayActorComponent;
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayActor : public AOmegaActorBASE, public IDataInterface_General, public ILuaInterface, public IActorInterface_Relatives
{
	GENERATED_BODY()
	
	UPROPERTY() FLuaValue lua_value;

public:

	AOmegaGameplayActor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta = (ShowOnlyInnerProperties),Category="Gameplay")
	UGameplayActorComponent* GameplayComponent;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UBillboardComponent* RootBillboard;
	
	virtual FLuaValue GetValue_Implementation(const FString& Field) override;

};
