// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LuaObject.h"
#include "OmegaAttribute.h"
#include "Obj_Lua.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLuaBaseObject : public ULuaObject, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly,Category="FieldNames") FString Param_AttributeMods="attributes";

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
};
