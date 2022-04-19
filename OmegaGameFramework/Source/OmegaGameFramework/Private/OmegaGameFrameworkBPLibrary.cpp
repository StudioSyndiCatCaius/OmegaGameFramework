// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameFrameworkBPLibrary.h"
#include "OmegaGameFramework.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/GameplayTagsInterface.h"


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

/*AOmegaGameplaySystem* UOmegaGameFrameworkBPLibrary::GetGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive)
{
	bIsActive = false;
	if(GEngine->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>())
	{
		UOmegaGameplaySubsystem* SubRef = GEngine->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
		if(SubRef->GetGameplaySystem(Class, bIsActive))
		{
			return SubRef->GetGameplaySystem(Class, bIsActive);
		}
	}
	return nullptr;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag Category)
{
	TArray<UObject*> OutObjects;
	for (UObject* TempObject : Assets)
	{
		if (TempObject->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass())&&Category.IsValid())
		{
			if (Category == IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempObject))
			{
				OutObjects.Add(TempObject);
			}
		}
	}
	return OutObjects;
}

TArray<UObject*> UOmegaGameFrameworkBPLibrary::FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer Category)
{
	return TArray<UObject*>();
}*/
void UOmegaGameFrameworkBPLibrary::SetWidgetVisibilityWithTags(FGameplayTagContainer Tags, ESlateVisibility Visibility)
{
	TArray<UUserWidget*> TempWidgets; 
	UWidgetBlueprintLibrary::GetAllWidgetsWithInterface(GetOuter(), TempWidgets, UGameplayTagsInterface::StaticClass(), true);
	for(UUserWidget* TempWidget : TempWidgets)
	{
		TempWidget->SetVisibility(Visibility);
	}
}
