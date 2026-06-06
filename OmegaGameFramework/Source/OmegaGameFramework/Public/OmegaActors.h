// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/I_StandardInput.h"
#include "Types/Struct_Message.h"
#include "OmegaActors.generated.h"

class UOmegaSubsystem_Engine;
class UOmegaSubsystem_GameInstance;
class UOmegaSubsystem_World;
class UOmegaSaveSubsystem;

USTRUCT(BlueprintType)
struct FOmegaActorBaseConfig
{
	GENERATED_BODY()
public:
	
	UPROPERTY() bool BindEvents_World_Message=false;
	
};

// Any actors derived from this will automatically have references to all SUBSYSTEMS, and hook calls to the GAME MANAGER.
UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaActorBASE : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY() UOmegaSubsystem_GameInstance* SS_GI=nullptr;
	UPROPERTY() UOmegaSubsystem_Engine* SS_Engine=nullptr;
	UPROPERTY() UOmegaSubsystem_World* SS_World=nullptr;
	UPROPERTY() UOmegaSaveSubsystem* SS_Save=nullptr;
	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void PreBeginPlay() {};
	virtual void PostBeginPlay() {};
	virtual void BeginPlay() override;
};

// Any actors derived from this will automatically have references to all SUBSYSTEMS, and hook calls to the GAME MANAGER.
UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaPawnBASE : public APawn, public IDataInterface_StandardInput
{
	GENERATED_BODY()
public:
	
	UPROPERTY() UOmegaSubsystem_GameInstance* SS_GI=nullptr;
	UPROPERTY() UOmegaSubsystem_Engine* SS_Engine=nullptr;
	UPROPERTY() UOmegaSubsystem_World* SS_World=nullptr;
	UPROPERTY() UOmegaSaveSubsystem* SS_Save=nullptr;

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void PreBeginPlay() {};
	virtual void PostBeginPlay() {};
	virtual void BeginPlay() override;
};

// Any actors derived from this will automatically have references to all SUBSYSTEMS, and hook calls to the GAME MANAGER.
UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaBaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	
	UPROPERTY() UOmegaSubsystem_GameInstance* SS_GI=nullptr;
	UPROPERTY() UOmegaSubsystem_Engine* SS_Engine=nullptr;
	UPROPERTY() UOmegaSubsystem_World* SS_World=nullptr;
	UPROPERTY() UOmegaSaveSubsystem* SS_Save=nullptr;

	virtual auto OnConstruction(const FTransform& Transform) -> void override;
	virtual void PreBeginPlay() {};
	virtual void PostBeginPlay() {};
	virtual void BeginPlay() override;
};