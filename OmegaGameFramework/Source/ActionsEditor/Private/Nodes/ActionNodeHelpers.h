// Copyright Studio Syndicat 2021. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "BlueprintNodeSpawner.h"
#include "BlueprintFunctionNodeSpawner.h"
#include "BlueprintActionDatabaseRegistrar.h"
//#include "Kismet2/BlueprintEditorUtils.h"

#include "Action.h"

class UK2Node_Action;

struct FActionNodeHelpers {
	static void RegisterActionClassActions(FBlueprintActionDatabaseRegistrar& InActionRegister, UClass* NodeClass);

	static void SetNodeFunc(UEdGraphNode* NewNode, bool /*bIsTemplateNode*/, TWeakObjectPtr<UClass> ClassPtr);


	static int32 RegistryActionClassAction(FBlueprintActionDatabaseRegistrar& InActionRegistar, UClass* NodeClass, UClass* Class);

	template < typename TBase >
	static void GetAllBlueprintSubclasses(TSet< TAssetSubclassOf< TBase > >& OutSubclasses, bool bAllowAbstract, FString const& Path);
};