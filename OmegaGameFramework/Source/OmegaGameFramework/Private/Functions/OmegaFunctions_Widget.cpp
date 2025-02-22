// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Widget.h"

#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Subsystems/OmegaSubsystem_Player.h"

void UOmegaWidgetFunctions::SetHUDLayerActive(UObject* WorldContextObject, TSubclassOf<UHUDLayer> HUD, bool bActive, UObject* Context, const FString& Flag,
                                             APlayerController* Player)
{
	APlayerController* ref_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(Player)
	{
		ref_player=Player;
	}
	UOmegaPlayerSubsystem* ref_subsystem = ref_player->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
	if(bActive)
	{
		ref_subsystem->AddHUDLayer(HUD,Context);
	}
	else
	{
		ref_subsystem->RemoveHUDLayer(HUD,Flag);
	}
}

void UOmegaWidgetFunctions::SetHUDLayersActive(UObject* WorldContextObject, TArray<TSubclassOf<UHUDLayer>> HUDs,
	bool bActive, UObject* Context, const FString& Flag, APlayerController* Player)
{
	for(TSubclassOf<UHUDLayer> temp_hud : HUDs)
	{
		SetHUDLayerActive(WorldContextObject,temp_hud,bActive,Context,Flag,Player);
	}
}

UHUDLayer* UOmegaWidgetFunctions::TryGetHudLayer(const UObject* WorldContextObject, TSubclassOf<UHUDLayer> Class,
	APlayerController* Player, TEnumAsByte<EOmegaFunctionResult>& Outcome)
{
	APlayerController* in_player=WorldContextObject->GetWorld()->GetFirstPlayerController();
	if(Player) { in_player=Player;}
	if(UHUDLayer* output = in_player->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->GetHUDLayerByClass(Class))
	{
		Outcome=Success;
		return output;
	}
	Outcome=Fail;
	return nullptr;
}

TArray<UObject*> UOmegaWidgetFunctions::GetSourceAssetsFromDataWidgets(TArray<UDataWidget*> Widgets, TSubclassOf<UObject> ObjectClass)
{
	TArray<UObject*> out;
	for (auto* temp_widget : Widgets)
	{
		if(temp_widget && (!ObjectClass || temp_widget->GetClass()->IsChildOf(ObjectClass))) { out.Add(temp_widget->ReferencedAsset);}
	}
	return out;
}
