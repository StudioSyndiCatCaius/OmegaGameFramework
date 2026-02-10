// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "Subsystems/Subsystem_Save.h"
#include "Modifier_Save.generated.h"



UCLASS(Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaModifier_Save : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	bool Modify_Save(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal) const;
};

inline bool UOmegaModifier_Save::Modify_Save_Implementation(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal) const
{
	return false;
}


USTRUCT(BlueprintType)
struct FOmegaModifiers_Save
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Selector")
	TArray<UOmegaModifier_Save*> Modifiers;

	void Modify(UOmegaSaveBase* Save, UOmegaSaveSubsystem* subsystem, bool bGlobal)
	{
		if(Save && subsystem)
		{
			for(auto* m : Modifiers)
			{
				if(m)
				{
					m->Modify_Save(Save,subsystem,bGlobal);
				}
			}
		}
	}
	
};


