// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_GlobalParams.h"

#include "Dom/JsonObject.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Subsystems/OmegaSubsystem_Save.h"

FOmegaGlobalVarsContainer& local_GetJsonFromTarget(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FOmegaGlobalVarsContainer dum)
{
	if(WorldContextObject)
	{
		switch (Target) {
		case SAVE_GAME:
			return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(false)->GlobalVars;
			break;
		case SAVE_GLOBAL:
			return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(true)->GlobalVars;
			break;
		case WORLD:
			return WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GlobalVars;
			break;
		case GAME_INSTANCE:
			return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->GlobalVars;
			break;
		}
	}
	return dum;
}

// ===================================================================================================
// GUID
// ===================================================================================================

// BOOL ------------------------------------
void UOmegaGlobalVariables_Guid::SetGlobalGuidVariable_Bool(UObject* WorldContextObject, FGuid GUID,
	EOmegaGlobalParamTarget Target, FString Variable, bool Value)
{
	FOmegaGlobalVarsContainer out;
	local_GetJsonFromTarget(WorldContextObject,Target,out).vars_guid[GUID].JsonObject->SetBoolField(Variable,Value);
}

bool UOmegaGlobalVariables_Guid::GetGlobalGuidVariable_Bool(UObject* WorldContextObject, FGuid GUID,
	EOmegaGlobalParamTarget Target, FString Variable)
{
	FOmegaGlobalVarsContainer out;
	return local_GetJsonFromTarget(WorldContextObject,Target,out).vars_guid.FindOrAdd(GUID).JsonObject->GetBoolField(Variable);
}

// INT32 ------------------------------------
void UOmegaGlobalVariables_Guid::SetGlobalGuidVariable_Int32(UObject* WorldContextObject, FGuid GUID,
	EOmegaGlobalParamTarget Target, FString Variable, int32 Value)
{
	FOmegaGlobalVarsContainer out;
	local_GetJsonFromTarget(WorldContextObject,Target,out).vars_guid[GUID].JsonObject->SetNumberField(Variable,Value);
}

int32 UOmegaGlobalVariables_Guid::GetGlobalGuidVariable_Int32(UObject* WorldContextObject, FGuid GUID,
	EOmegaGlobalParamTarget Target, FString Variable)
{
	FOmegaGlobalVarsContainer out;
	return local_GetJsonFromTarget(WorldContextObject,Target,out).vars_guid.FindOrAdd(GUID).JsonObject->GetNumberField(Variable);
}

// FLOAT ------------------------------------
void UOmegaGlobalVariables_Guid::SetGlobalGuidVariable_Float(UObject* WorldContextObject, FGuid GUID,
	EOmegaGlobalParamTarget Target, FString Variable, float Value)
{
	FOmegaGlobalVarsContainer out;
	local_GetJsonFromTarget(WorldContextObject,Target,out).vars_guid[GUID].JsonObject->SetNumberField(Variable,Value);
}

float UOmegaGlobalVariables_Guid::GetGlobalGuidVariable_Float(UObject* WorldContextObject, FGuid GUID,
	EOmegaGlobalParamTarget Target, FString Variable)
{
	FOmegaGlobalVarsContainer out;
	return local_GetJsonFromTarget(WorldContextObject,Target,out).vars_guid.FindOrAdd(GUID).JsonObject->GetBoolField(Variable);
}

// ===================================================================================================
// Named
// ===================================================================================================

// BOOL ------------------------------------
void UOmegaGlobalVariables_Named::SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FString Variable, bool Value)
{
	FOmegaGlobalVarsContainer out;
	local_GetJsonFromTarget(WorldContextObject,Target,out).main_vars.JsonObject->SetBoolField(Variable,Value);
}

bool UOmegaGlobalVariables_Named::GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FString Variable)
{
	FOmegaGlobalVarsContainer out;
	return local_GetJsonFromTarget(WorldContextObject,Target,out).main_vars.JsonObject->GetBoolField(Variable);
}

// INT ------------------------------------
void UOmegaGlobalVariables_Named::SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FString Variable, int32 Value)
{
	FOmegaGlobalVarsContainer out;
	local_GetJsonFromTarget(WorldContextObject,Target,out).main_vars.JsonObject->SetNumberField(Variable,Value);
}

int32 UOmegaGlobalVariables_Named::GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FString Variable)
{
	FOmegaGlobalVarsContainer out;
	return local_GetJsonFromTarget(WorldContextObject,Target,out).main_vars.JsonObject->GetNumberField(Variable);
}

// FLOAT ------------------------------------
void UOmegaGlobalVariables_Named::SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FString Variable, float Value)
{
	FOmegaGlobalVarsContainer out;
	local_GetJsonFromTarget(WorldContextObject,Target,out).main_vars.JsonObject->SetNumberField(Variable,Value);
}

float UOmegaGlobalVariables_Named::GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target,
	FString Variable)
{
	FOmegaGlobalVarsContainer out;
	return local_GetJsonFromTarget(WorldContextObject,Target,out).main_vars.JsonObject->GetNumberField(Variable);
}
