// Copyright Studio Syndicat 2021. All Rights Reserved. 

#pragma once

#include <CoreMinimal.h>
#include <Kismet/BlueprintFunctionLibrary.h>

#include "Action.h"
#include "ActionLibrary.generated.h"


UCLASS()
class ACTIONS_API UActionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Action, meta = (DisplayName = "Create GameplayAction", BlueprintInternalUseOnly = "true", DefaultToSelf = "Owner", WorldContext = "Owner", AdvancedDisplay="Type"))
	static UAction* CreateAction(UObject* Owner, const TSubclassOf<UAction> Type, bool bAutoActivate = false)
	{
		return UAction::Create(Owner, Type.Get(), bAutoActivate);
	}
};
