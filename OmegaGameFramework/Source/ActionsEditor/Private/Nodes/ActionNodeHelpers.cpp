// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "ActionNodeHelpers.h"

#include "K2Node_Action.h"
#include "ARFilter.h"
#include "AssetRegistryModule.h"


void FActionNodeHelpers::RegisterActionClassActions(FBlueprintActionDatabaseRegistrar& InActionRegister, UClass* NodeClass)
{
	UClass* TaskType = UAction::StaticClass();

	int32 RegisteredCount = 0;
	if (const UObject* RegistrerTarget = InActionRegister.GetActionKeyFilter())
	{
		if (const auto* TargetClass = Cast<UClass>(RegistrerTarget))
		{
			if (!TargetClass->HasAnyClassFlags(CLASS_Abstract) && !TargetClass->IsChildOf(TaskType))
			{
				UBlueprintNodeSpawner* NewAction = UBlueprintNodeSpawner::Create(NodeClass);
				check(NewAction != nullptr);

				TWeakObjectPtr<UClass> TargetClassPtr = const_cast<UClass*>(TargetClass);
				NewAction->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(SetNodeFunc, TargetClassPtr);

				if (NewAction)
				{
					RegisteredCount += (int32)InActionRegister.AddBlueprintAction(TargetClass, NewAction);
				}
			}
		}
	}
	else
	{
		for (TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt)
		{
			UClass* Class = *ClassIt;
			if (Class->HasAnyClassFlags(CLASS_Abstract) || !Class->IsChildOf(TaskType) || Class == TaskType)
			{
				continue;
			}

			RegisteredCount += RegistryActionClassAction(InActionRegister, NodeClass, Class);
		}

		//Registry blueprint classes
		/*TSet<TAssetSubclassOf<UAction>> BPClasses;
		GetAllBlueprintSubclasses<UAction>(BPClasses, false, "");
		for (auto& BPClass : BPClasses)
		{
			if (!BPClass.IsValid())
			{
				UClass* Class = BPClass.LoadSynchronous();
				if (Class)
				{
					RegisteredCount += RegistryActionClassAction(InActionRegister, NodeClass, Class);
				}
			}
		}*/
	}
	return;
}

void FActionNodeHelpers::SetNodeFunc(UEdGraphNode* NewNode, bool /*bIsTemplateNode*/, TWeakObjectPtr<UClass> ClassPtr)
{
	UE_LOG(LogTemp, Log, TEXT("Attempt Set Node Func"));
	UK2Node_Action* ActionNode = CastChecked<UK2Node_Action>(NewNode);
	if (ClassPtr.IsValid())
	{
		ActionNode->bShowClass = false;
		ActionNode->ActionClass = ClassPtr.Get();
		UE_LOG(LogTemp, Log, TEXT("Class PTR is Valid"));
	}
}

template<typename TBase>
void FActionNodeHelpers::GetAllBlueprintSubclasses(TSet<TAssetSubclassOf<TBase>>& Subclasses, bool bAllowAbstract, FString const& Path)
{
	static const FName GeneratedClassTag = TEXT("GeneratedClass");
	static const FName ClassFlagsTag = TEXT("ClassFlags");

	UClass* Base = TBase::StaticClass();
	check(Base);

	// Load the asset registry module
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked< FAssetRegistryModule >(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	FName BaseClassName = Base->GetFName();

	// Use the asset registry to get the set of all class names deriving from Base
	TSet< FName > DerivedNames;
	{
		
		TArray< FName > BaseNames;
		BaseNames.Add(BaseClassName);

		TSet< FName > Excluded;
		AssetRegistry.GetDerivedClassNames(BaseNames, Excluded, DerivedNames);
	}

	// Set up a filter and then pull asset data for all blueprints in the specified path from the asset registry.
	// Note that this works in packaged builds too. Even though the blueprint itself cannot be loaded, its asset data
	// still exists and is tied to the UBlueprint type.
	FARFilter Filter;
	Filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
	Filter.bRecursiveClasses = true;
	if (!Path.IsEmpty())
	{
		Filter.PackagePaths.Add(*Path);
	}
	Filter.bRecursivePaths = true;

	TArray< FAssetData > AssetList;
	AssetRegistry.GetAssets(Filter, AssetList);

	// Iterate over retrieved blueprint assets
	for (auto const& Asset : AssetList)
	{
		UE_LOG(LogTemp, Log, TEXT("ActionLoaded: %s"), Asset.GetFullName());
		// Get the the class this blueprint generates (this is stored as a full path)
		auto GeneratedClassPath = Asset.TagsAndValues.FindTag(GeneratedClassTag);
		if (GeneratedClassPath.IsSet())
		{
			// Convert path to just the name part
			const FString ClassObjectPath = FPackageName::ExportTextPathToObjectPath(GeneratedClassPath.GetValue());
			const FString ClassName = FPackageName::ObjectPathToObjectName(ClassObjectPath);

			// Check if this class is in the derived set
			if (!DerivedNames.Contains(*ClassName))
			{
				continue;
			}

			// Store using the path to the generated class
			Subclasses.Add(TAssetSubclassOf<TBase>{ FStringAssetReference(ClassObjectPath) });
		}
	}
}

int32 FActionNodeHelpers::RegistryActionClassAction(FBlueprintActionDatabaseRegistrar& InActionRegistar, UClass* NodeClass, UClass* Class)
{
	UBlueprintNodeSpawner* NewAction = UBlueprintNodeSpawner::Create(NodeClass);
	check(NewAction != nullptr);

	NewAction->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(SetNodeFunc, TWeakObjectPtr<UClass>{ Class });

	if (NewAction)
	{
		return (int32)InActionRegistar.AddBlueprintAction(Class, NewAction);
	}

	return 0;
}
