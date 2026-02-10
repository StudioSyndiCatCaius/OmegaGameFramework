// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Common.h"
//#include "OmegaGameFramework.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
//#include "EngineUtils.h"
#include "JsonBlueprintFunctionLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_Save.h"
#include "Misc/OmegaGameplayModule.h"
#include "Misc/OmegaUtils_Enums.h"
#include "JsonObjectWrapper.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "Dom/JsonObject.h"
#include "LuaInterface.h"
#include "OmegaSettings.h"
#include "OmegaGameplayConfig.h"
#include "OmegaGameCore.h"
#include "OmegaSettings_Assets.h"
#include "OmegaSettings_Slate.h"
#include "Functions/F_Assets.h"
#include "Functions/F_Combatant.h"
#include "Functions/F_File.h"
#include "Functions/F_Text.h"
#include "Functions/F_Utility.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/I_Common.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Misc/Paths.h"
#include "Statics/OMEGA_File.h"
#include "Subsystems/Subsystem_AssetHandler.h"
#include "Subsystems/Subsystem_Gameplay.h"


FText UOmegaGameFrameworkBPLibrary::L_TextFormatObject(UObject* obj,FText t)
{
	if(obj)
	{
		FOmegaCommonMeta m;
		m.Context=obj;
		return UOmegaTextFunctions::ApplyGameplayTextFormating(nullptr,t,FGameplayTag(),m);
	}
	return t;
}

UOmegaSettings* UOmegaGameFrameworkBPLibrary::GetSettings_Omega()
{
	return GetMutableDefault<UOmegaSettings>();
}

UOmegaStyleSettings* UOmegaGameFrameworkBPLibrary::GetSettings_Style()
{
	return GetMutableDefault<UOmegaStyleSettings>();
}

UOmegaAssetSettings* UOmegaGameFrameworkBPLibrary::GetSettings_Asset()
{
	return GetMutableDefault<UOmegaAssetSettings>();
}

bool UOmegaGameFrameworkBPLibrary::HasTags_Advance(FGameplayTagContainer Tags, FGameplayTagContainer Has, bool bAll, bool bExact)
{
	if(bAll)
	{
		if(bExact)
		{
			return Tags.HasAllExact(Has);
		}
		return Tags.HasAll(Has);
	}
	if(bExact)
	{
		return Tags.HasAllExact(Has);
	}
	return Tags.HasAny(Has);
}

FGameplayTagContainer UOmegaGameFrameworkBPLibrary::GetObjectGameplayTags(UObject* Object)
{
	FGameplayTagContainer OutTags;
	if(Object && Object->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		OutTags = IGameplayTagsInterface::Execute_GetObjectGameplayTags(Object);
	}
	return OutTags;
}

bool UOmegaGameFrameworkBPLibrary::IsObjectOfGameplayCategory(UObject* Object, FGameplayTag CategoryTag, bool bExact)
{
	if(Object && Object->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		const FGameplayTag LocalCategory = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(Object);
		if(bExact)
		{
			return LocalCategory.MatchesTagExact(CategoryTag);
		}
		return LocalCategory.MatchesTag(CategoryTag);
		
	}
	return false;
}

bool UOmegaGameFrameworkBPLibrary::DoesObjectHaveGameplayTag(UObject* Object, FGameplayTag GameplayTag, bool bExact)
{
	if(Object && Object->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		const FGameplayTagContainer LocalTags = IGameplayTagsInterface::Execute_GetObjectGameplayTags(Object);
		if(bExact)
		{
			return LocalTags.HasTagExact(GameplayTag);
		}
		return LocalTags.HasTag(GameplayTag);
	}
	
	return false;
}

bool UOmegaGameFrameworkBPLibrary::DoesObjectHaveGameplayTags(UObject* Object, const FGameplayTagContainer& GameplayTags,
	bool bExact, bool bValidIfEmpty)
{
	if(Object)
	{
		if(GameplayTags.IsEmpty())
		{
			return bValidIfEmpty;
		}
		for(const FGameplayTag temp_tag : GameplayTags.GetGameplayTagArray())
		{
			if(!DoesObjectHaveGameplayTag(Object,temp_tag,bExact))
			{
				return false;	
			}
		}
		return true;
	}
	return bValidIfEmpty;
}


bool UOmegaGameFrameworkBPLibrary::QueryObjectGameplayTags(UObject* Object, FGameplayTagQuery Query,
                                                           bool bEmptyReturnsTrue)
{
	if(Object && !Query.IsEmpty() && Object->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		return Query.Matches(IGameplayTagsInterface::Execute_GetObjectGameplayTags(Object));
	}
	return bEmptyReturnsTrue;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsByCategoryTag(TArray<UObject*> Assets,
                                                                          FGameplayTag CategoryTag, bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag)
{
	if(bIncludeOnEmptyTag && !CategoryTag.IsValid())
	{
		return Assets;
	}
	
	TArray<UObject*> OutAssets;
	for(auto* TempAsset : Assets)
	{
		if(TempAsset)
		{
			if(!CategoryTag.IsValid() || (!Class || (TempAsset->GetClass()->IsChildOf(Class))) && TempAsset->Implements<UGameplayTagsInterface>())
			{
				FGameplayTag TempAssetTag = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempAsset);
				bool bLocalIsValid;

				if(bExact)
				{
					bLocalIsValid = TempAssetTag.MatchesTagExact(CategoryTag);
				}
				else
				{
					bLocalIsValid = TempAssetTag.MatchesTag(CategoryTag);
				}
			
				if(bLocalIsValid != bExclude)
				{
					OutAssets.Add(TempAsset);
				}
			}
		}
	}
	return OutAssets;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsByGameplayTags(TArray<UObject*> Assets,
	FGameplayTagContainer GameplayTags, bool bExact, bool bExclude, TSubclassOf<UObject> Class, bool bIncludeOnEmptyTag)
{
	if(bIncludeOnEmptyTag && GameplayTags.IsEmpty())
	{
		return Assets;
	}
		
	TArray<UObject*> OutAssets;
	
	for(auto* TempAsset : Assets)
	{
		if(TempAsset)
		{
			if(GameplayTags.IsEmpty() || (!Class || (TempAsset->GetClass()->IsChildOf(Class))) && TempAsset->Implements<UGameplayTagsInterface>())
			{
				FGameplayTagContainer TempAssetTag = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempAsset);
				bool bLocalIsValid;

				if(bExact)
				{
					bLocalIsValid = TempAssetTag.HasAnyExact(GameplayTags);
				}
				else
				{
					bLocalIsValid = TempAssetTag.HasAny(GameplayTags);
				}
			
				if(bLocalIsValid != bExclude)
				{
					OutAssets.Add(TempAsset);
				}
			}
		}
	}
	return OutAssets;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsWithInterface(TArray<UObject*> Objects,
	TSubclassOf<UInterface> Interface, bool bExclude, TSubclassOf<UObject> Class)
{
	TArray<UObject*> out;
	if(Interface)
	{
		return out;
	}
	for(auto* o : Objects)
	{
		if(o && o->GetClass()->ImplementsInterface(Interface)!=bExclude && (!Class || o->GetClass()->IsChildOf(Class)))
		{
			out.Add(o);
		}
	}
	return out;
}

FGameplayTagContainer UOmegaGameFrameworkBPLibrary::FilterTagsByType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn)
{
	FGameplayTagContainer OutTags;
	TArray<FGameplayTag> TempTags;
	TagsIn.GetGameplayTagArray(TempTags);
	for(FGameplayTag TempTag : TempTags)
	{
		if(TempTag.MatchesTag(TypeTag))
		{
			OutTags.AddTag(TempTag);
		}
	}
	return OutTags;
}

FGameplayTag UOmegaGameFrameworkBPLibrary::GetFirstTagOfType(FGameplayTag TypeTag, FGameplayTagContainer TagsIn)
{
	TArray<FGameplayTag> LocalTags;
	FilterTagsByType(TypeTag, TagsIn).GetGameplayTagArray(LocalTags);
	FGameplayTag OutTag;
	if(LocalTags.IsValidIndex(0))
	{
		OutTag = LocalTags[0];
	}
	return OutTag;
}

void UOmegaGameFrameworkBPLibrary::SetGameplaySystemActive(const UObject* WorldContextObject, TSubclassOf<AOmegaGameplaySystem>
                                                           SystemClass, bool bActive, const FString Flag, UObject* Context)
{
	UObject* LocalContext = nullptr;
	if(Context)
	{
		LocalContext = Context;
	}
	UOmegaGameplaySubsystem* SubystemRef = WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	if(bActive)
	{
		SubystemRef->ActivateGameplaySystem(SystemClass, LocalContext, Flag);
	}
	else
	{
		SubystemRef->ShutdownGameplaySystem(SystemClass, LocalContext, Flag);
	}
}

void UOmegaGameFrameworkBPLibrary::SetGameplaySystemsActive(const UObject* WorldContextObject,
	TArray<TSubclassOf<AOmegaGameplaySystem>> SystemClasses, bool bActive, const FString Flag, UObject* Context)
{
	for(auto TempClass : SystemClasses)
	{
		if(TempClass)
		{
			
			SetGameplaySystemActive(WorldContextObject, TempClass, bActive, Flag, Context);
		}
	}
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::ResolveSoftArray_Object(TArray<TSoftObjectPtr<UObject>> List,
	TSubclassOf<UObject> Class)
{
	TArray<UObject*> out;
	TSubclassOf<UObject> _inclass=UObject::StaticClass();
	if(Class) { _inclass=Class;}
	for(TSoftObjectPtr<UObject> o : List)
	{
		if(UObject* _in = o.LoadSynchronous())
		{
			if(_in->GetClass()->IsChildOf(_inclass))
			{
				out.Add(_in);
			}
		}
	}
	return out;
}

TArray<TSubclassOf<UObject>> UOmegaGameFrameworkBPLibrary::ResolveSoftArray_Class(TArray<TSoftClassPtr<UObject>> List)
{
	TArray<TSubclassOf<UObject>> out;
	for(TSoftClassPtr<UObject> o : List)
	{
		if(TSubclassOf<UObject> _in = o.LoadSynchronous())
		{
			out.Add(_in);
		}
	}
	return out;
}

/*
void UOmegaGameFrameworkBPLibrary::SetWidgetVisibilityWithTags(FGameplayTagContainer Tags, ESlateVisibility Visibility)
{
	TArray<UUserWidget*> TempWidgets; 
	UWidgetBlueprintLibrary::GetAllWidgetsWithInterface(this, TempWidgets, UGameplayTagsInterface::StaticClass(), true);
	for(UUserWidget* TempWidget : TempWidgets)
	{
		TempWidget->SetVisibility(Visibility);
	}
}
*/
TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsByClass(TArray<UObject*> Objects, TSubclassOf<UObject> Class, bool bExclude)
{
	TArray<UObject*> OutObjects;
	for(auto* TempObj : Objects)
	{
		if(TempObj)
		{
			if(TempObj->GetClass()->IsChildOf(Class) && !bExclude)
			{
				OutObjects.Add(TempObj);
			}
		}
	}
	return OutObjects;
}

FGameplayTag UOmegaGameFrameworkBPLibrary::MakeGameplayTagFromString(const FString& String)
{
	if(FGameplayTag::IsValidGameplayTagString(String))
	{
		return FGameplayTag::RequestGameplayTag(FName(*String),false);
	}
	return FGameplayTag();
}

FGameplayTagContainer UOmegaGameFrameworkBPLibrary::MakeGameplayTagContainerFromStrings(TArray<FString> Strings)
{
	FGameplayTagContainer OutTags;
	for(FString TempString : Strings)
	{
		OutTags.AddTag(MakeGameplayTagFromString(TempString));
	}
	return OutTags;
}

FString UOmegaGameFrameworkBPLibrary::GetLastGameplayTagString(const FGameplayTag& GameplayTag)
{
	const FString TagString = GameplayTag.ToString();
	FString OutString;
	TagString.Split(".", nullptr, &OutString, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	return OutString;
}

UObject* UOmegaGameFrameworkBPLibrary::SelectObjectByName(TArray<UObject*> Objects, const FString& Name)
{
	for(auto* TempObj : Objects)
	{
		if(TempObj && TempObj->GetName() == Name)
		{
			return TempObj;
		}
	}
	return nullptr;
}

const TArray<FString> UOmegaGameFrameworkBPLibrary::GetDisplayNamesFromObjects(TArray<UObject*> Objects)
{
	TArray<FString> StringsOut;
	for(auto* TempObj : Objects)
	{
		if(TempObj)
		{
			StringsOut.Add(TempObj->GetName());
		}
	}
	return StringsOut;
}



TArray<UObject*> UOmegaGameFrameworkBPLibrary::ConvertSoftToHardReferences(
	const TArray<TSoftObjectPtr<UObject>>& SoftRefs, const TSubclassOf<UObject> ClassType)
{
	TArray<UObject*> HardRefs;
	HardRefs.Reserve(SoftRefs.Num());
    
	for (const TSoftObjectPtr<UObject>& SoftRef : SoftRefs)
	{
		if (UObject* LoadedObject = SoftRef.LoadSynchronous())
		{
			if (!ClassType || LoadedObject->IsA(ClassType))
			{
				HardRefs.Add(LoadedObject);
			}
		}
	}
    
	return HardRefs;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::GetAllAssetsOfClass(TSubclassOf<UObject> Class, bool bIncludeSubclasses)
{
	TArray<UObject*> LoadedAssets;
	if(Class)
	{
		// Access the asset registry
		const IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
	
		// Query the asset registry
		TArray<FAssetData> AssetList;
		AssetRegistry.GetAssetsByClass(Class->GetClassPathName(),AssetList,bIncludeSubclasses);

		// Iterate over the results and load each asset
		for (const FAssetData& Asset : AssetList)
		{
			if (UObject* LoadedAsset = Asset.GetAsset())
			{
				LoadedAssets.Add(LoadedAsset);
				UE_LOG(LogTemp, Warning, TEXT("Loaded asset: %s"), *LoadedAsset->GetName());
			}
		}

		//add sorted assets
		for(auto* a : GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->GetSortedAsset_All())
		{
			if(a && a->GetClass()->IsChildOf(Class))
			{
				LoadedAssets.AddUnique(a);
			}
		}
		
		return LoadedAssets;
	}
	return LoadedAssets;
}


UObject* UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(const FString& AssetPath, TSubclassOf<UObject> Class,
                                                         bool& Outcome)
{
	if (AssetPath.IsEmpty())
	{
		Outcome=false;
    	return nullptr;
	}
	
	// LOG - Start
	FString class_name="NONE";
	if (Class)
	{
		class_name=Class->GetName();
	}
	UE_LOG(LogTemp, Warning, TEXT("	LOADING ASSET of class '%s' from path: %s"), *class_name,  *AssetPath);
	
	//try load override
	if (UObject* obj=OGF_GAME_CORE()->Override_GetAssetFromPath(AssetPath,Class))
	{
		if (!Class || !obj->GetClass()->IsChildOf(Class))
		{
			Outcome=true;
			return obj;
		}
	}
	
	TArray<FString> in_path;
	in_path.Add(AssetPath);
	
	UOmegaSubsystem_AssetHandler* sub_ah=GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>();
	//USE = already imported override file if it exits.
	if(UObject* override_file = sub_ah->GetSortedAsset_FromLabel(AssetPath))
	{
		if(override_file->GetClass()->IsChildOf(Class) || !Class)
		{
			UE_LOG(LogTemp, Warning, TEXT("		✅ FOUND ASSET - In Sorted Assets"));
			Outcome=true;
			return override_file;
		}
	}
	//USE = external file imported as new sorted asset
	else
	{
		for(UOmegaGameplayConfig* set_path : OGF_CFG()->GetAllGameplaySettings())
		{	
			//add the paths from the OmegPathSettings Asset to list that needs checking
			in_path.Append(set_path->GetPathsFromAssetName(AssetPath,Class));
			
			if(set_path->ClassPaths.Contains(Class))
			{
				FOmegaSortedClassPathData path_data=set_path->GetAssetDataFromClass(Class);
				
				if (UObject* got_obj=path_data.getAssetFromPath(AssetPath,Class))
				{
					if (got_obj->GetClass()->IsChildOf(Class))
					{
						Outcome=true;
						UE_LOG(LogTemp, Warning, TEXT("		✅ FOUND ASSET - In Path Settings Scripted GET"));
						return got_obj;
					}
				}
			}
		}
	}
	in_path.Append(UOmegaGameCore::GetPathsFromAssetName(OGF_GAME_CORE()->ClassPaths,AssetPath,Class));

	//Run through path check list and return first valid asset.
	for (FString path_to_check : in_path)
	{
		path_to_check=OMEGA_File::PathCorrect(path_to_check);
		
		FSoftObjectPath SoftObjectPath(path_to_check);
		if (!path_to_check.IsEmpty() && SoftObjectPath.IsValid())
		{
			if(UObject* out = SoftObjectPath.TryLoad())
			{
				if(out->GetClass()->IsChildOf(Class) || !Class)
				{
					UE_LOG(LogTemp, Warning, TEXT("		✅ FOUND ASSET - By Soft Reference"));
					Outcome=true;
					return out;
				}
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("		❌ FAILED TO FIND ASSET"));
	Outcome=false;
	return nullptr;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::GetAssets_FromPath(const FString& path, bool bRecursive,
	TSubclassOf<UObject> Class)
{
TArray<UObject*> FoundAssets;
    
    // Get the Asset Registry Module
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
    
    // Create filter for asset search
    FARFilter Filter;
    Filter.PackagePaths.Add(FName(*path));
    Filter.bRecursivePaths = bRecursive;
    
    // If a specific class is provided, filter by class
    if (Class)
    {
        Filter.ClassPaths.Add(Class->GetClassPathName());
    }
    
    // Get asset data
    TArray<FAssetData> AssetDataArray;
    AssetRegistry.GetAssets(Filter, AssetDataArray);
    
    // Load and convert asset data to UObject*
    for (const FAssetData& AssetData : AssetDataArray)
    {
        // Load the asset
        UObject* LoadedAsset = AssetData.GetAsset();
        if (LoadedAsset)
        {
            // Double-check class type if specified
            if (!Class || LoadedAsset->IsA(Class))
            {
                FoundAssets.Add(LoadedAsset);
            }
        }
    }
    
    return FoundAssets;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::GetAssetList_FromPath(const TArray<FString> AssetPaths,
                                                                     TSubclassOf<UObject> Class)
{
	TArray<UObject*> out;
	for(const FString& temp_path : AssetPaths)
	{
		bool result;
        UObject* result_object = GetAsset_FromPath(temp_path,Class,result);
        if(result_object && result==true)
        {
        	out.Add(result_object);
        }
	}
	return out;
}


UClass* UOmegaGameFrameworkBPLibrary::GetClass_FromPath(const FString& AssetPath, TSubclassOf<UObject> Class, 
                                                        bool& Outcome)
{
	if(UClass* out_obj = UKismetSystemLibrary::Conv_SoftClassPathToSoftClassRef(UKismetSystemLibrary::MakeSoftClassPath(AssetPath)).LoadSynchronous())
	{
		Outcome=true;
		return out_obj;
	}
	Outcome=false;
	return nullptr;
}


UObject* UOmegaGameFrameworkBPLibrary::GetAsset_FromLuaField(FLuaValue Lua, const FString& Field,
	TSubclassOf<UObject> Class, bool& Outcome)
{
	//If the Field string arg is empty, treat the input Lu arg as the path to check
	FLuaValue field_data=Lua.GetField(Field);
	if(Field.IsEmpty())
	{
		field_data=Lua;
	}

	if(UObject* lua_found_obj = ULuaBlueprintFunctionLibrary::Conv_LuaValueToObject(field_data))
	{
		if(lua_found_obj->GetClass()->IsChildOf(Class) || !Class)
		{
			Outcome=true;
			return lua_found_obj;
		}
	}
	
	FString in_path = field_data.String;
	
	return GetAsset_FromPath(in_path,Class,Outcome);
}

UClass* UOmegaGameFrameworkBPLibrary::GetClass_FromLuaField(FLuaValue Lua, const FString& Field,
	TSubclassOf<UObject> Class, bool& Outcome)
{
	FLuaValue field_data=Lua.GetField(Field);
	if(Field.IsEmpty())
	{
		field_data=Lua;
	}

	if(UClass* lua_found_obj = ULuaBlueprintFunctionLibrary::Conv_LuaValueToClass(field_data))
	{
		if(lua_found_obj->IsChildOf(Class) || !Class)
		{
			Outcome=true;
			return lua_found_obj;
		}
	}
	
	FString in_path = field_data.String;
	

	if(UClass* out_obj = UKismetSystemLibrary::Conv_SoftClassPathToSoftClassRef(UKismetSystemLibrary::MakeSoftClassPath(in_path)).LoadSynchronous())
	{
		Outcome=true;
		return out_obj;
	}
	Outcome=false;
	return nullptr;
}


AActor* UOmegaGameFrameworkBPLibrary::GetPlayerMouseOverActor(const APlayerController* Player, ETraceTypeQuery TraceChannel, float TraceSphereRadius)
{
	FVector LocalStart;
	FVector LocalEnd;
	Player->DeprojectMousePositionToWorld(LocalStart, LocalEnd);
	LocalEnd = LocalEnd*Player->HitResultTraceDistance;

	FHitResult LocalHitResult;
	const TArray<AActor*> LocalIgnoreActors;
	if(UKismetSystemLibrary::SphereTraceSingle(Player, LocalStart, LocalEnd, TraceSphereRadius, TraceChannel, false, LocalIgnoreActors, EDrawDebugTrace::None, LocalHitResult, true))
	{
		if(LocalHitResult.GetActor())
		{
			return LocalHitResult.GetActor();
		}
	}
	
	return nullptr;
}

void UOmegaGameFrameworkBPLibrary::SetPlayerCustomInputMode(const UObject* WorldContextObject,
	APlayerController* Player, UOmegaInputMode* InputMode)
{
	if(!InputMode)
	{
		return;
	}
	const APlayerController* TempPlayer = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(Player)
	{
		TempPlayer = Player;
	}
	TempPlayer->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetCustomInputMode(InputMode);
}

float UOmegaGameFrameworkBPLibrary::GetPlayerCameraFadeAmount(const APlayerController* Player)
{
	if(Player)
	{
		return Player->PlayerCameraManager->FadeAmount;
	}
	return 0;
}

FLinearColor UOmegaGameFrameworkBPLibrary::GetPlayerCameraFadeColor(const APlayerController* Player)
{
	FLinearColor LocalColor;
	if(Player)
	{
		LocalColor = Player->PlayerCameraManager->FadeColor;
	}
	return LocalColor;
}

void UOmegaGameFrameworkBPLibrary::SetGlobalActorBinding(const UObject* WorldContextObject, FName Binding,
                                                         AActor* Actor)
{
	if (Binding.IsNone()) { return; }
	WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->SetGlobalActorBinding(Binding, Actor);
}

void UOmegaGameFrameworkBPLibrary::ClearGlobalActorBinding(const UObject* WorldContextObject, FName Binding)
{
	WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ClearGlobalActorBinding(Binding);
}

AActor* UOmegaGameFrameworkBPLibrary::GetGlobalActorBinding(const UObject* WorldContextObject, FName Binding)
{
	return WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetGlobalActorBinding(Binding);
}

void UOmegaGameFrameworkBPLibrary::SetTaggedActorBinding(const UObject* WorldContextObject, FGameplayTag Binding,
	AActor* Actor)
{
	if(WorldContextObject && Actor)
	{
		WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActorBindings_Tagged.Add(Binding,Actor);
	}
}

AActor* UOmegaGameFrameworkBPLibrary::CheckTaggedActorBinding(const UObject* WorldContextObject, FGameplayTag Binding,
	TSubclassOf<AActor> Class, bool& result)
{
	if(WorldContextObject)
	{
	 	AActor* _actor = WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActorBindings_Tagged.FindOrAdd(Binding);
		if(_actor && (!Class || _actor->GetClass()->IsChildOf(Class)))
		{
			result=true;
			return _actor;
		}
	}
	result=false;
	return nullptr;
}

// QUICK ACCESS
AOmegaGameplaySystem* UOmegaGameFrameworkBPLibrary::GetActiveGameplaySystem(const UObject* WorldContextObject,
	TSubclassOf<AOmegaGameplaySystem> SystemClass, bool& result)
{
	bool LocalIsActive;
	if(WorldContextObject && WorldContextObject->GetWorld())
	{
		if(UOmegaGameplaySubsystem* _sub=WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>())
		{
			if(AOmegaGameplaySystem* _sys=_sub->GetGameplaySystem(SystemClass, LocalIsActive))
			{
				result=true;
				return _sys;
			}
		}
	}
	result=false;
	return nullptr;
}

UActorComponent* UOmegaGameFrameworkBPLibrary::GetFirstActiveGameplaySystemWithComponent(
	const UObject* WorldContextObject, TSubclassOf<UActorComponent> Component, FName RequiredTag, AOmegaGameplaySystem*& system, bool& Outcome)
{
	if(WorldContextObject && WorldContextObject->GetWorld() && WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>())
	{
		for (AOmegaGameplaySystem* temp_sys : WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetActiveGameplaySystems())
		{
			if(temp_sys)
			{
				bool out_result;
				if(UActorComponent* temp_comp = TryGetFirstComponentWithTag(temp_sys,Component,RequiredTag,out_result))
				{
					Outcome=true;
					system=temp_sys;
					return temp_comp;
				}
			}
		}
	}
	Outcome=false;
	return nullptr;
}

UOmegaGameplayModule* UOmegaGameFrameworkBPLibrary::GetGameplayModule(const UObject* WorldContextObject,
                                                                      TSubclassOf<UOmegaGameplayModule> ModuleClass, bool bFallbackToDefault)
{
	if(ModuleClass)
	{
		//first get module from world
		if(WorldContextObject
		&& WorldContextObject->GetWorld()->GetGameInstance()
		&& WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->GetGameplayModule(ModuleClass))
		{
			return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->GetGameplayModule(ModuleClass);
		}

		//If nor world (I.E. Editor) get from settings
		for(UOmegaGameplayConfig* set : GetMutableDefault<UOmegaSettings>()->GetAllGameplaySettings())
		{
			for(auto* a : set->GetModules())
			{
				if(a && a->GetClass()==ModuleClass)
				{
					return a;
				}
			}
		}

		//if all else fails, fallback to default (to true)
		if(bFallbackToDefault)
		{
			return ModuleClass.GetDefaultObject();
		}
	}
	return nullptr;
}

UOmegaGameplayModule* UOmegaGameFrameworkBPLibrary::TryGetGameplayModule(const UObject* WorldContextObject,
	TSubclassOf<UOmegaGameplayModule> ModuleClass, bool& Outcome, bool bFallbackToDefault)
{
	if (UOmegaGameplayModule* m=GetGameplayModule(WorldContextObject,ModuleClass,bFallbackToDefault))
	{
		Outcome=true;
		return m;
	}
	Outcome=false;
	return nullptr;
}

void UOmegaGameFrameworkBPLibrary::FireGlobalEvent(const UObject* WorldContextObject, FName Event, UObject* Context, FOmegaCommonMeta meta)
{
	if(WorldContextObject)
	{
		WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(Event, Context,meta);
	}
	
}

void UOmegaGameFrameworkBPLibrary::FireTaggedGlobalEvent(const UObject* WorldContextObject, FGameplayTag Event,
	UObject* Context, FOmegaCommonMeta meta)
{
	if(WorldContextObject)
	{
		WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireTaggedGlobalEvent(Event, Context,meta);
	}
}

void UOmegaGameFrameworkBPLibrary::OnFlagActiveReset(const UObject* WorldContextObject, const FString& Flag, bool bDeactivateFlagOnActive, TEnumAsByte<EOmegaFlagResult>& Outcome)
{
	UOmegaGameManager* LocalMod = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>();
	if(LocalMod->IsFlagActive(Flag))
	{
		Outcome = EOmegaFlagResult::Flag_Active;
		if(bDeactivateFlagOnActive)
		{
			LocalMod->SetFlagActive(Flag, false);
		}
	}
	else
	{
		Outcome = EOmegaFlagResult::Flag_Inactive;
	}
}

void UOmegaGameFrameworkBPLibrary::SetActorTagActive(AActor* Actor, FName Tag, bool bIsActive)
{
	if(Actor)
	{
		if(bIsActive)
		{
			Actor->Tags.AddUnique(Tag);
		}
		else
		{
			Actor->Tags.Remove(Tag);
		}
	}
}

void UOmegaGameFrameworkBPLibrary::SetActorTagListActive(AActor* Actor, TArray<FName> Tags, bool bIsActive)
{
	if(Actor)
	{
		for(FName n : Tags)
		{
			SetActorTagActive(Actor,n,bIsActive);
		}
	}
}

void UOmegaGameFrameworkBPLibrary::SetComponentTagActive(UActorComponent* Component, FName Tag, bool bIsActive)
{
	if(Component)
	{
		if(bIsActive)
		{
			Component->ComponentTags.AddUnique(Tag);
		}
		else
		{
			Component->ComponentTags.Remove(Tag);
		}
	}
}

TArray<AActor*> UOmegaGameFrameworkBPLibrary::GetActorsFromComponents(TArray<UActorComponent*> Components,
	TSubclassOf<UActorComponent> Class)
{
	TArray<AActor*> OutActors;
	for(const auto* TempComp : Components)
	{
		if(TempComp && (!Class || TempComp->GetClass()->IsChildOf(Class)))
		{
			OutActors.AddUnique(TempComp->GetOwner());
		}
	}
	return OutActors;
}


TArray<AActor*> UOmegaGameFrameworkBPLibrary::GetActorsFromChildActorComponents(
	TArray<UChildActorComponent*> Components, TSubclassOf<AActor> ActorClass)
{
	TArray<AActor*> out;
	for (auto* TempComp : Components)
	{
		if(TempComp && TempComp->GetChildActor() && (!ActorClass || TempComp->GetChildActorClass()->IsChildOf(ActorClass)))
		{
			out.Add(TempComp->GetChildActor());
		}
	}
	return out;
}

TArray<UActorComponent*> UOmegaGameFrameworkBPLibrary::GetComponentsFromActors(TArray<AActor*> Actors, TSubclassOf<UActorComponent> ComponentClass)
{
	TArray<UActorComponent*> OutComps;
	for(const auto* TempComp : Actors)
	{
		if(TempComp && TempComp->GetComponentByClass(ComponentClass))
		{
			OutComps.AddUnique(TempComp->GetComponentByClass(ComponentClass));
		}
	}
	return OutComps;
}

TArray<FVector2D> UOmegaGameFrameworkBPLibrary::GetActorPositionVectors2D(TArray<AActor*> Actors,
                                                                          const APlayerController* Player, bool ViewportRelative)
{
	TArray<FVector2D> out;
	for(const auto* TempActor : Actors)
	{
		if(TempActor)
		{
			FVector2D new_out;
			UGameplayStatics::ProjectWorldToScreen(Player,TempActor->GetActorLocation(),new_out,ViewportRelative);
			out.Add(new_out);
		}
	}
	return out;
}

AActor* UOmegaGameFrameworkBPLibrary::GetClosestActorToPoint(TArray<AActor*> Actors, FVector Point)
{
	AActor* OutActor = nullptr;
	
	for(auto* TempActor : Actors)
	{
		if(OutActor)
		{
			const float CheckedActor_Point = UKismetMathLibrary::Vector_Distance(Point, TempActor->GetActorLocation());
			const float OutActor_Point = UKismetMathLibrary::Vector_Distance(Point, OutActor->GetActorLocation());
			if(CheckedActor_Point<OutActor_Point)	//Checked actor distance is less than last actopr
			{
				OutActor = TempActor;
			}
		}
		else
		{
			OutActor = TempActor;
		}
	}
	return OutActor;
}

AActor* UOmegaGameFrameworkBPLibrary::GetClosestOverlappingActor(UPrimitiveComponent* OverlappedComponent,
	TSubclassOf<AActor> FilterClass)
{
	if(OverlappedComponent)
	{
		TArray<AActor*> tempactors;
		OverlappedComponent->GetOverlappingActors(tempactors,FilterClass);

		return GetClosestActorToPoint(tempactors,OverlappedComponent->GetComponentLocation());
	}
	return  nullptr;
}

AActor* UOmegaGameFrameworkBPLibrary::GetClosestActorToViewportPoint2D(TArray<AActor*> Actors, FVector2D Point,
                                                                       const APlayerController* Player, bool ViewportRelative)
{
	if(Actors.IsValidIndex(0))
	{
		TArray<FVector2D> temp_vecs = GetActorPositionVectors2D(Actors,Player,ViewportRelative);
		FVector2D out_dump;
		return Actors[GetClosestVector2dToPoint(temp_vecs,Point,out_dump)];
	}
	return nullptr;
}

void UOmegaGameFrameworkBPLibrary::SetActorActive(AActor* Actor, bool bIsActive)
{
	if(Actor)
	{
		Actor->SetActorHiddenInGame(!bIsActive);
		Actor->CustomTimeDilation=bIsActive;
		Actor->SetActorEnableCollision(bIsActive);
	}
}

TArray<AActor*> UOmegaGameFrameworkBPLibrary::FilterActorsWithComponents(TArray<AActor*> Actors,
	TSubclassOf<UActorComponent> ComponentClass)
{
	TArray<AActor*> OutActors;
	for(auto* TempActor : Actors)
	{
		if(TempActor && TempActor->GetComponentByClass(ComponentClass))
		{
			OutActors.Add(TempActor);
		}
	}
	return OutActors;
}

AActor* UOmegaGameFrameworkBPLibrary::TryGetActorFromObject(UObject* Object, TSubclassOf<AActor> Class,
	bool& Outcome)
{
	if(!Object)
	{
		Outcome=false;
		return nullptr;
	}
	TSubclassOf<AActor> _target_class=AActor::StaticClass();
	if(Class) { _target_class=Class;}
	UObject* _check_object=Object;
	if(UActorComponent* _comp = Cast<UActorComponent>(Object))
	{
		_check_object=_comp->GetOwner();
	}
	if(_check_object && _check_object->GetClass()->IsChildOf(_target_class))
	{
		Outcome=true;
		return Cast<AActor>(_check_object);
	}
	Outcome=false;
	return nullptr;
}

UActorComponent* UOmegaGameFrameworkBPLibrary::TryGetComponentFromObject(UObject* Object,
                                                                         TSubclassOf<UActorComponent> Class, bool& Outcome)
{
	if(!Object || !Class)
	{
		Outcome=false;
		return nullptr;
	}
	
	if (Cast<AActor>(Object) && Cast<AActor>(Object)->GetComponentByClass(Class))
	{
		Outcome=true;
		return Cast<AActor>(Object)->GetComponentByClass(Class);
	}
	
	if (Cast<UActorComponent>(Object))
	{
		UActorComponent* TempComp = Cast<UActorComponent>(Object);
		
		if(TempComp->GetClass()->IsChildOf(Class))
		{
			Outcome=true;
			return TempComp;
		}
		
		if (TempComp->GetOwner()->GetComponentByClass(Class))
		{
			Outcome=true;
			return TempComp->GetOwner()->GetComponentByClass(Class);
		}
	}
	Outcome=false;
	return  nullptr;
}

UActorComponent* UOmegaGameFrameworkBPLibrary::TryGetFirstComponentWithTag(UObject* Object,
	TSubclassOf<UActorComponent> Class, FName Tag, bool& Outcome)
{
	if(!Object || !Class)
	{
		Outcome=false;
		return nullptr;
	}

	const AActor* TargetActor = nullptr;
	
	if (Cast<AActor>(Object) && Cast<AActor>(Object)->GetComponentByClass(Class))
	{
		TargetActor = Cast<AActor>(Object);
	}
	
	if (Cast<UActorComponent>(Object))
	{
		TargetActor = Cast<UActorComponent>(Object)->GetOwner();
	}
	
	if(TargetActor)
	{
		if(Tag.IsNone())
		{
			if(UActorComponent* out_comp= TargetActor->GetComponentByClass(Class))
			{
				Outcome=true;
				return out_comp;
			}
		}
		TArray<UActorComponent*> CompList = TargetActor->GetComponentsByTag(Class,Tag);
		if(CompList.IsValidIndex(0))
		{
			Outcome=true;
			return CompList[0];
		}
	}
	
	Outcome=false;
	return  nullptr;
}

TArray<AActor*> UOmegaGameFrameworkBPLibrary::FilterActorsWithTag(TArray<AActor*> Actors, FName Tag, bool bExclude,
	TSubclassOf<AActor> Class)
{
	TArray<AActor*> OutActors;
	for(auto* TempObject : Actors)
	{
		if(TempObject && TempObject->ActorHasTag(Tag)!=bExclude)
		{
			OutActors.Add(TempObject);
		}
	}
	return OutActors;
}

TArray<UActorComponent*> UOmegaGameFrameworkBPLibrary::FilterComponentsWithTag(TArray<UActorComponent*> Components,
	FName Tag, bool bExclude, TSubclassOf<UActorComponent> Class)
{
	TArray<UActorComponent*> OutActors;
	for(auto* TempObject : Components)
	{
		if(TempObject && TempObject->ComponentHasTag(Tag)!=bExclude)
		{
			OutActors.Add(TempObject);
		}
	}
	return OutActors;
}

AActor* UOmegaGameFrameworkBPLibrary::Quick_SpawnActor(UObject* WorldContextObject, TSubclassOf<AActor> Class,
	FTransform Transform, const TArray<FName> Tags)
{
	AActor* new_actor = WorldContextObject->GetWorld()->SpawnActorDeferred<AActor>(Class, Transform, nullptr);
	new_actor->Tags=Tags;
	UGameplayStatics::FinishSpawningActor(new_actor, Transform);
	return new_actor;
}

void UOmegaGameFrameworkBPLibrary::SetActorInputEnabled(UObject* WorldContextObject, AActor* Actor, bool bEnabled,
	APlayerController* Player)
{
	if(!Actor)
	{
		return;
	}
	APlayerController* temp_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(Player)
	{
		temp_player=Player;
	}
	if(bEnabled)
	{
		Actor->EnableInput(temp_player);
	}
	else
	{
		Actor->DisableInput(temp_player);
	}
}

AActor* UOmegaGameFrameworkBPLibrary::TryGetChildActorAsClass(UChildActorComponent* ChildActor, TSubclassOf<AActor> Class,
	bool& Outcome)
{
	if(ChildActor && ChildActor->GetChildActor() && ChildActor->GetChildActorClass()->IsChildOf(Class))
	{
		Outcome=true;
		return ChildActor->GetChildActor();
	}
	Outcome=false;
	return nullptr;
}

TArray<AActor*> UOmegaGameFrameworkBPLibrary::GetActorsFromHitResults(TArray<FHitResult> Hits,
	TSubclassOf<AActor> Class)
{
	TArray<AActor*> out;
	for(FHitResult tempHit : Hits)
	{
		if(tempHit.GetActor() && (!Class || tempHit.GetActor()->GetClass()->IsChildOf(Class)))
		{
			out.Add(tempHit.GetActor());
		}
	}
	return out;
}

void UOmegaGameFrameworkBPLibrary::RotateActorToLookLocation(AActor* Actor, FVector Location, bool X, bool Y, bool Z)
{
	if(Actor)
	{
		FRotator rot_target=UKismetMathLibrary::FindLookAtRotation(Actor->GetActorLocation(),Location);
		if(!X) { rot_target.Roll=Actor->GetActorRotation().Roll; }
		if(!Y) { rot_target.Pitch=Actor->GetActorRotation().Pitch; }
		if(!Z) { rot_target.Yaw=Actor->GetActorRotation().Yaw; }
		Actor->SetActorRotation(rot_target);
	}
}

void UOmegaGameFrameworkBPLibrary::RotateActorToLookTarget(AActor* Actor, AActor* LookTarget, bool X, bool Y, bool Z)
{
	if(Actor && LookTarget)
	{
		RotateActorToLookLocation(Actor,LookTarget->GetActorLocation(),X,Y,Z);
	}
}

void UOmegaGameFrameworkBPLibrary::RotateActorToLookTargetsMidpoint(AActor* Actor, TArray<AActor*> LookTargets, bool X,
	bool Y, bool Z)
{
	RotateActorToLookLocation(Actor,UGameplayStatics::GetActorArrayAverageLocation(LookTargets),X,Y,Z);
}

TArray<FVector> UOmegaGameFrameworkBPLibrary::GetLocationArrayFromActorList(TArray<AActor*> Actors)
{
	TArray<FVector> Locations;
	for (AActor* Actor : Actors)
	{
		if (Actor) // Ensure the Actor is valid
		{
			Locations.Add(Actor->GetActorLocation());
		}
	}
	return Locations;
}


//###############################################################################
// InterpActor
//###############################################################################

void UOmegaGameFrameworkBPLibrary::InterpActorLocation(AActor* Actor, FVector TargetLocation, float InterpSpeed)
{
	if(Actor)
	{
		Actor->SetActorLocation(UKismetMathLibrary::VInterpTo(Actor->GetActorLocation(), TargetLocation, UGameplayStatics::GetWorldDeltaSeconds(Actor), InterpSpeed));
	}
}

void UOmegaGameFrameworkBPLibrary::InterpActorRotation(AActor* Actor, FRotator TargetRotation, float InterpSpeed, bool X,
	bool Y, bool Z)
{
	FRotator LocalRot = TargetRotation;
	if(!X)
	{
		LocalRot.Roll = 0;
	}
	if(!Y)
	{
		LocalRot.Pitch = 0;
	}
	if(!Z)
	{
		LocalRot.Yaw = 0;
	}
	if(Actor)
	{
		Actor->SetActorRotation(UKismetMathLibrary::RInterpTo(Actor->GetActorRotation(), LocalRot, UGameplayStatics::GetWorldDeltaSeconds(Actor), InterpSpeed));
	}
	
}
//###############################################################################
// Save
//###############################################################################
void UOmegaGameFrameworkBPLibrary::SetTagsAddedToSaveGame(const UObject* WorldContextObject, FGameplayTagContainer Tags,
	bool Saved, bool bGlobal)
{
	if(WorldContextObject)
	{
		UOmegaSaveSubsystem* SubsysRef = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
		if(Saved)
		{
			SubsysRef->AddStoryTags(Tags, bGlobal);
		}
		else
		{
			SubsysRef->RemoveStoryTags(Tags, bGlobal);
		}
	}
}

void UOmegaGameFrameworkBPLibrary::SwitchOnSaveTagQuery(const UObject* WorldContextObject, FGameplayTagQuery TagQuery, bool bGlobal,
	bool& Outcome)
{
	UOmegaSaveSubsystem* SubsysRef = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	if(SubsysRef->SaveTagsMatchQuery(TagQuery, bGlobal))
	{
		Outcome=true;
	}
	else
	{
		Outcome=false;
	}
}

void UOmegaGameFrameworkBPLibrary::CombineJsonObjects(const TArray<FJsonObjectWrapper>& JsonObjects,
	FJsonObjectWrapper& CombinedObject)
{
	for (const FJsonObjectWrapper& JsonObject : JsonObjects)
	{
		const TSharedPtr<FJsonObject>& JsonObjectRoot = JsonObject.JsonObject;

		for (auto It = JsonObjectRoot->Values.CreateConstIterator(); It; ++It)
		{
			const FString& Key = It.Key();
			const TSharedPtr<FJsonValue>& Value = It.Value();
			
			CombinedObject.JsonObject->SetField(Key,Value);
		}
	}
}

FJsonObjectWrapper UOmegaGameFrameworkBPLibrary::CreateJsonField(const FString& FieldName, const int32& Value)
{
	const FJsonObjectWrapper NewJson;
	const TSharedPtr<FJsonValue> JsonValue = MakeShared<FJsonValueNumber>(Value);
	NewJson.JsonObject->SetField(FieldName,JsonValue);
	return NewJson;
}


FText UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(UObject* Object,bool FormatText)
{
	if(!Object) { return FText(); }
	FText OutName;
	FText OutDescription;
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(Object,"",nullptr,OutName,OutDescription);
	}
	if(FormatText) { L_TextFormatObject(Object,OutName);}
	return OutName;
}

FText UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(UObject* Object,bool FormatText)
{
	if(!Object) { return FText(); }
	FText OutName;
	FText OutDescription;
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(Object,"",nullptr,OutName,OutDescription);
	}
	
	if(FormatText) { L_TextFormatObject(Object,OutDescription);}
	return OutDescription;
}

FString UOmegaGameFrameworkBPLibrary::GetObjectLabel(UObject* Object)
{
	FString OutName;
	if(Object)
	{
		OutName=Object->GetName();
	}
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralAssetLabel(Object,OutName);
	}
	return OutName;
}

FSlateBrush UOmegaGameFrameworkBPLibrary::GetObjectIcon(UObject* Object)
{
	FSlateBrush out;
	UTexture2D* dum_txt=nullptr;
	UMaterialInterface* dum_mat=nullptr;
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataImages(Object," ",nullptr,dum_txt,dum_mat,out);
	}
	return out;
}

TArray<FString> UOmegaGameFrameworkBPLibrary::GetLabelsFromObjects(TArray<UObject*> Objects)
{
	TArray<FString> out;
	for(auto* temp_object : Objects)
	{
		if(temp_object)
		{
			out.Add(GetObjectLabel(temp_object));
		}
	}
	return out;
}

UObject* UOmegaGameFrameworkBPLibrary::SelectObjectFromLabel(TArray<UObject*> ObjectsIn, const FString& Label,
	TSubclassOf<UObject> Class,bool& Outcome)
{
	for(auto* temp_object : ObjectsIn)
	{
		if(temp_object && (temp_object->GetClass()->IsChildOf(Class) || !Class) && GetObjectLabel(temp_object)==Label)
		{
			Outcome=true;
			return temp_object;
		}
	}
	Outcome=false;
	return nullptr;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsFromLabels(TArray<UObject*> ObjectsIn, TArray<FString> Labels)
{
	TArray<UObject*> out;
	for(auto* temp_object : ObjectsIn)
	{
		if(temp_object && Labels.Contains(GetObjectLabel(temp_object)))
		{
			out.Add(temp_object);
		}
	}
	return out;
}

TArray<FName> UOmegaGameFrameworkBPLibrary::GetObjectMetatags(UObject* WorldContextObject, UObject* Object, bool bAppendActorTags, bool bAppendComponentTags)
{
	TArray<FName> out;
	if (Object)
	{
		if (Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
		{
			out.Append(IDataInterface_General::Execute_GetMetatags(Object));
		}
		UObject* dum_obj=nullptr;
		if (WorldContextObject)
		{
			dum_obj=WorldContextObject;
		}
		out.Append(GetMutableDefault<UOmegaSettings>()->GetGameCore()->Object_AppendMetatags(dum_obj,Object));
		if (bAppendActorTags)
		{
			if (AActor* a=Cast<AActor>(Object))
			{
				out.Append(a->Tags);
			}
		}
		if (bAppendComponentTags)
		{
			if (UActorComponent* a=Cast<UActorComponent>(Object))
			{
				out.Append(a->ComponentTags);
			}
		}
	}
	return out;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsWithMetatag(UObject* WorldContextObject,
	TArray<UObject*> Objects, FName tag, bool bAppendActorTags, bool bAppendComponentTags)
{
	TArray<UObject*> out;
	for (auto* o : Objects)
	{
		if (o && GetObjectMetatags(WorldContextObject,o,bAppendActorTags,bAppendComponentTags).Contains(tag))
		{
			out.Add(o);
		}
	}
	return out;
}

FGuid UOmegaGameFrameworkBPLibrary::GetObjectGUID(UObject* Object)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_GUID::StaticClass()))
	{
		return IDataInterface_GUID::Execute_GetObjectGuid(Object);
	}
	return  FGuid();
}

int32 UOmegaGameFrameworkBPLibrary::GetClosestVector2dToPoint(TArray<FVector2D> Vectors, FVector2D point,
                                                              FVector2D& out_point)
{
	if(Vectors.IsValidIndex(0))
	{
		FVector2D last_point=Vectors[0];
		int32 out_index = 0;
		for(FVector2D temp_vec: Vectors)
		{
			if(UKismetMathLibrary::Distance2D(last_point,point)>UKismetMathLibrary::Distance2D(temp_vec,point))
			{
				last_point=temp_vec;
				out_index=Vectors.Find(temp_vec);
			}
		}
		out_point=Vectors[out_index];
		return out_index;
	}
	return 0;
}

FLuaValue UOmegaGameFrameworkBPLibrary::GetLuaValueFromGameplayTag(UObject* WorldContextObject, FGameplayTag Tag,
	const FString& ParentTable, TSubclassOf<ULuaState> StateClass)
{
	FString Field_value=Tag.ToString();
	if(!ParentTable.IsEmpty())
	{
		Field_value=ParentTable+"."+Field_value;
	}
	return ULuaBlueprintFunctionLibrary::LuaGetGlobal(WorldContextObject,StateClass,Field_value);
}

UDataAsset* UOmegaGameFrameworkBPLibrary::CreateDataAssetFromLua(UObject* WorldContextObject, TSubclassOf<UDataAsset> Class, FLuaValue Value)
{
	if(Class && Class->ImplementsInterface(ULuaInterface::StaticClass()))
	{
		UDataAsset* new_obj = NewObject<UDataAsset>(WorldContextObject->GetWorld()->GetGameInstance(),Class);
		ILuaInterface::Execute_SetValue(new_obj,Value,"");
		return new_obj;
	}
	return nullptr;
}

TMap<UOmegaAttribute*, float> UOmegaGameFrameworkBPLibrary::LuaToOmegaAttributes(UObject* WorldContextObject,
	TSubclassOf<UDataAsset> Class, FLuaValue Value)
{
	TMap<UOmegaAttribute*, float> out;

	for(FLuaValue temp_val : ULuaBlueprintFunctionLibrary::LuaTableGetKeys(Value))
	{
		if(UOmegaAttribute* temp_att = UOmegaFunctions_Asset::GetNamed_Attribute(*temp_val.String))
		{
			out.FindOrAdd(temp_att,ULuaBlueprintFunctionLibrary::Conv_LuaValueToFloat(Value.GetField(temp_val.String)));
		}
	}
	return out;
}

TMap<UOmegaAttribute*, int32> UOmegaGameFrameworkBPLibrary::LuaToOmegaAttributes_int(UObject* WorldContextObject,
	TSubclassOf<UDataAsset> Class, FLuaValue Value)
{
	TMap<UOmegaAttribute*, int32> out;

	for(FLuaValue temp_val : ULuaBlueprintFunctionLibrary::LuaTableGetKeys(Value))
	{
		if(UOmegaAttribute* temp_att = UOmegaFunctions_Asset::GetNamed_Attribute(*temp_val.String))
		{
			out.FindOrAdd(temp_att,ULuaBlueprintFunctionLibrary::Conv_LuaValueToInt(Value.GetField(temp_val.String)));
		}
	}
	return out;
}

//###############################################################################
// State Tag
//###############################################################################
void UOmegaGameFrameworkBPLibrary::SetStateTagsActive_World(UObject* WorldContextObject, FGameplayTagContainer Tags,
	bool bActive)
{
	if(WorldContextObject)
	{
		if(bActive)
		{
			WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->StateTags.AppendTags(Tags);
		}
		else
		{
			WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->StateTags.RemoveTags(Tags);
		}
	}
}

FGameplayTagContainer UOmegaGameFrameworkBPLibrary::GetStateTagsActive_World(UObject* WorldContextObject)
{
	if(WorldContextObject)
	{
		return WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->StateTags;
	}
	return FGameplayTagContainer();
}

bool UOmegaGameFrameworkBPLibrary::AreStateTagsActive_World(UObject* WorldContextObject, FGameplayTagContainer Tags, bool bAll, bool bExact)
{
	return HasTags_Advance(GetStateTagsActive_World(WorldContextObject),Tags,bAll,bExact);
}

void UOmegaGameFrameworkBPLibrary::SetStateTagsActive_GameInstance(UObject* WorldContextObject,
	FGameplayTagContainer Tags, bool bActive)
{
	if(WorldContextObject)
	{
		if(bActive)
		{
			WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->StateTags.AppendTags(Tags);
		}
		else
		{
			WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->StateTags.RemoveTags(Tags);
		}
	}
}

FGameplayTagContainer UOmegaGameFrameworkBPLibrary::GetStateTagsActive_GameInstance(UObject* WorldContextObject)
{
	if(WorldContextObject)
	{
		return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->StateTags;
	}
	return FGameplayTagContainer();
}

bool UOmegaGameFrameworkBPLibrary::AreStateTagsActive_GameInstance(UObject* WorldContextObject,
	FGameplayTagContainer Tags, bool bAll, bool bExact)
{
	return HasTags_Advance(GetStateTagsActive_GameInstance(WorldContextObject),Tags,bAll,bExact);
}



float UOmegaStarRankFunctions::GetFloatFromStarRank(EOmegaStarRank Rank)
{
	float OutVal = 0;
	switch (Rank) {
	case Star5: OutVal=1; break;
	case Star4: OutVal=0.8; break;
	case Star3: OutVal=0.6; break;
	case Star2: OutVal=0.4; break;
	case Star1: OutVal=0.2; break;
	case Star0: OutVal=0; break;
	}
	return OutVal;
}

int32 UOmegaStarRankFunctions::GetIntFromStarRank(EOmegaStarRank Rank)
{
	int32 OutVal = 0;
	switch (Rank) {
	case Star5: OutVal=5; break;
	case Star4: OutVal=4; break;
	case Star3: OutVal=3; break;
	case Star2: OutVal=2; break;
	case Star1: OutVal=1; break;
	case Star0: OutVal=0; break;
	}
	return OutVal;
}

float UOmegaCurveFunctions::GetCurveValueFromTime(FRuntimeFloatCurve curve,float time)
{
	return curve.GetRichCurve()->Eval(time);
}






