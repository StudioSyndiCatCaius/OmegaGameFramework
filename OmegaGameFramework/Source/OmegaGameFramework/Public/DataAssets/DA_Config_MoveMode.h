// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Config_MoveMode.generated.h"

class UPawnMovementComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComponentConfig_PawnMove_Modifier : public UOmegaInstancableObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Mdifier")
	bool OnModifyComponent(UPawnMovementComponent* Component) const;
};


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaComponentConfig_PawnMove : public UOmegaDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Config")
	TArray<UOmegaComponentConfig_PawnMove_Modifier*> Modifiers;

	UFUNCTION(BlueprintCallable,Category="Omega|Config|MoveMode")
	void ModifyComponent(UPawnMovementComponent* Component);
};

inline void UOmegaComponentConfig_PawnMove::ModifyComponent(UPawnMovementComponent* Component)
{
	if(Component)
	{
		for(auto* p : Modifiers)
		{
			if(p) { p->OnModifyComponent(Component); }
		}
	}
}

