// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OmegaUtils_Enums.generated.h"

UENUM(Blueprintable,BlueprintType)
enum EOmegaGlobalParamTarget
{
	WORLD,
	GAME_INSTANCE,
	SAVE_GAME,
	SAVE_GLOBAL,
};

UENUM(Blueprintable, BlueprintType)
enum EFactionAffinity
{
	NeutralAffinity			UMETA(DisplayName = "Neutral"),
	FriendlyAffinity		UMETA(DisplayName = "Friendly"),
	HostileAffinity			UMETA(DisplayName = "Hostile"),
};


UENUM(Blueprintable)
enum EOmegaStarRank
{
	Star5	UMETA(DisplayName = "★★★★★"),
	Star4	UMETA(DisplayName = "★★★★☆"),
	Star3	UMETA(DisplayName = "★★★☆☆"),
	Star2	UMETA(DisplayName = "★★☆☆☆"),
	Star1	UMETA(DisplayName = "★☆☆☆☆"),
	Star0	UMETA(DisplayName = "☆☆☆☆☆"),
};

UENUM(Blueprintable)
enum EOmegaComparisonMethod
{
	Compare_Equal		UMETA(DisplayName = "="),
	Compare_Great		UMETA(DisplayName = ">"),
	Compare_Less		UMETA(DisplayName = "<"),
	Compare_GreatEqual	UMETA(DisplayName = ">="),
	Compare_LessEqual	UMETA(DisplayName = "<="),
};

UENUM(Blueprintable)
enum EOmegaComparisonMethodSimple
{
	IsGreater		UMETA(DisplayName = ">"),
	IsEqual			UMETA(DisplayName = "="),
	IsLess			UMETA(DisplayName = "<"),
};

UENUM(BlueprintType)
enum class EAddRemove : uint8
{
	Add				UMETA(DisplayName = "Add"),
	Remove          UMETA(DisplayName = "Remove"),
};

UENUM(BlueprintType)
enum class EOmegaGender : uint8
{
	NONE            UMETA(DisplayName = "N/A"),
	Male            UMETA(DisplayName = "Male"),
	Female            UMETA(DisplayName = "Female"),
};

// =============================
UENUM(BlueprintType)
enum class EOmegaGamepad_Facebuttons : uint8
{
	Facebutton_Bottom            UMETA(DisplayName = "Bottom"),
	Facebutton_Top            UMETA(DisplayName = "Top"),
	Facebutton_Left            UMETA(DisplayName = "Left"),
	Facebutton_Right            UMETA(DisplayName = "Right"),
};
// =============================

UENUM(BlueprintType)
enum class EOmegaGamepad_Shoulder : uint8
{
	Shoulder_L            UMETA(DisplayName = "Left"),
	Shoulder_R            UMETA(DisplayName = "Right"),
};
// =============================

UENUM(Blueprintable)
enum EOmegaQuestStatus
{
	Unstarted		UMETA(DisplayName = "Unstarted"),
	Active			UMETA(DisplayName = "Active"),
	Complete		UMETA(DisplayName = "Complete"),
	Failed			UMETA(DisplayName = "Failed"),
};

UENUM(BlueprintType)
enum class ELevelOpenType : uint8
{
	LvlOp_None		UMETA(DisplayName = "N/A"),
	LvlOp_Save		UMETA(DisplayName = "Saved"),
	LvlOp_Custom	UMETA(DisplayName = "Custom"),
};

UENUM(BlueprintType)
enum class EUniqueSaveFormats : uint8
{
	SaveFormat_Quicksave		UMETA(DisplayName = "Quicksave"),
	SaveFormat_Autosave			UMETA(DisplayName = "Autosave"),
	
};

UENUM(BlueprintType)
enum EBoolType 
{
	BoolType_And     UMETA(DisplayName = "All True"),
	BoolType_Or      UMETA(DisplayName = "One True"),
	BoolType_NONE     UMETA(DisplayName = "None True"),
};

