// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Common.h"
//#include "OmegaGameFramework.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
//#include "EngineUtils.h"
#include "JsonBlueprintFunctionLibrary.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Player.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Misc/OmegaUtils_Enums.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonObject.h"
#include "LuaInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"


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



AActor* UOmegaGameFrameworkBPLibrary::GetPlayerMouseOverActor(APlayerController* Player, ETraceTypeQuery TraceChannel, float TraceSphereRadius)
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

float UOmegaGameFrameworkBPLibrary::GetPlayerCameraFadeAmount(APlayerController* Player)
{
	if(Player)
	{
		return Player->PlayerCameraManager->FadeAmount;
	}
	return 0;
}

FLinearColor UOmegaGameFrameworkBPLibrary::GetPlayerCameraFadeColor(APlayerController* Player)
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

// QUICK ACCESS
AOmegaGameplaySystem* UOmegaGameFrameworkBPLibrary::GetActiveGameplaySystem(const UObject* WorldContextObject,
	TSubclassOf<AOmegaGameplaySystem> SystemClass)
{
	bool LocalIsActive;
	if(WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetGameplaySystem(SystemClass, LocalIsActive))
	{
		return WorldContextObject->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetGameplaySystem(SystemClass, LocalIsActive);
	}
	return nullptr;
}

UOmegaGameplayModule* UOmegaGameFrameworkBPLibrary::GetGameplayModule(const UObject* WorldContextObject,
	TSubclassOf<UOmegaGameplayModule> ModuleClass)
{
	if(WorldContextObject && WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->GetGameplayModule(ModuleClass))
	{
		return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->GetGameplayModule(ModuleClass);
	}
	return nullptr;
}

void UOmegaGameFrameworkBPLibrary::FireGlobalEvent(const UObject* WorldContextObject, FName Event, UObject* Context)
{
	WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(Event, Context);
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

TArray<AActor*> UOmegaGameFrameworkBPLibrary::GetActorsFromComponents(TArray<UActorComponent*> Components)
{
	TArray<AActor*> OutActors;
	for(const auto* TempComp : Components)
	{
		if(TempComp)
		{
			OutActors.AddUnique(TempComp->GetOwner());
		}
	}
	return OutActors;
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
	TSubclassOf<UActorComponent> ComponentClass, TArray<AActor*> ExcludedActors)
{
	TArray<AActor*> OutActors;
	for(auto* TempActor : Actors)
	{
		if(TempActor && TempActor->GetComponentByClass(ComponentClass) && !ExcludedActors.Contains(TempActor))
		{
			OutActors.Add(TempActor);
		}
	}
	return OutActors;
}

UActorComponent* UOmegaGameFrameworkBPLibrary::TryGetComponentFromObject(UObject* Object,
	TSubclassOf<UActorComponent> Class, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(!Object || !Class)
	{
		Outcome = EOmegaFunctionResult::Fail;
		return nullptr;
	}
	
	if (Cast<AActor>(Object) && Cast<AActor>(Object)->GetComponentByClass(Class))
	{
		Outcome = EOmegaFunctionResult::Success;
		return Cast<AActor>(Object)->GetComponentByClass(Class);
	}
	
	if (Cast<UActorComponent>(Object))
	{
		UActorComponent* TempComp = Cast<UActorComponent>(Object);
		
		if(TempComp->GetClass()->IsChildOf(Class))
		{
			Outcome = EOmegaFunctionResult::Success;
			return TempComp;
		}
		
		if (TempComp->GetOwner()->GetComponentByClass(Class))
		{
			Outcome = EOmegaFunctionResult::Success;
			return TempComp->GetOwner()->GetComponentByClass(Class);
		}
	}
	Outcome = EOmegaFunctionResult::Fail;
	return  nullptr;
}

UActorComponent* UOmegaGameFrameworkBPLibrary::TryGetFirstComponentWithTag(UObject* Object,
	TSubclassOf<UActorComponent> Class, FName Tag, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	if(!Object || !Class)
	{
		Outcome = EOmegaFunctionResult::Fail;
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
		TArray<UActorComponent*> CompList = TargetActor->GetComponentsByTag(Class,Tag);
		if(CompList.IsValidIndex(0))
		{
			Outcome = EOmegaFunctionResult::Success;
			return CompList[0];
		}
	}
	
	Outcome = EOmegaFunctionResult::Fail;
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
	TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	UOmegaSaveSubsystem* SubsysRef = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	if(SubsysRef->SaveTagsMatchQuery(TagQuery, bGlobal))
	{
		Outcome = EOmegaFunctionResult::Success;
	}
	else
	{
		Outcome = EOmegaFunctionResult::Fail;
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

FText UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(UObject* Object)
{
	FText OutName;
	FText OutDescription;
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(Object,"",nullptr,OutName,OutDescription);
	}
	return OutName;
}

FText UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(UObject* Object)
{
	FText OutName;
	FText OutDescription;
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(Object,"",nullptr,OutName,OutDescription);
	}
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





