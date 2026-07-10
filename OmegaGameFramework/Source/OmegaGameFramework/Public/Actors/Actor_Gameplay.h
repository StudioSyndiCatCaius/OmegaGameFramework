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

// The primary gameplay actor class. Wraps UGameplayActorComponent to give an actor an identity, tags, save visibility, subscripts, and flow support.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayActor : public AOmegaActorBASE, public IDataInterface_General, public ILuaInterface, public IActorInterface_Relatives
{
	GENERATED_BODY()

	UPROPERTY() FLuaValue lua_value;

public:

	AOmegaGameplayActor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	// The core gameplay component that provides identity, tags, subscripts, and interaction logic.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="🎮Gameplay",meta = (ShowOnlyInnerProperties))
	UGameplayActorComponent* GameplayComponent;

	// Editor billboard for visibility in the viewport when no mesh is present.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UBillboardComponent* RootBillboard;

	virtual FLuaValue GetValue_Implementation(const FString& Field) override;

};
