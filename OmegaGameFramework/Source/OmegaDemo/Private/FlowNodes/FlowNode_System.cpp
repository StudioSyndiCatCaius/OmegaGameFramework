// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_System.h"

#include "FlowAsset.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "OmegaGameplayConfig.h"
#include "Components/Component_CombatEncounter.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_GameManager.h"

UFlowNode_GameplaySystemBASE::UFlowNode_GameplaySystemBASE()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Shutdown")));
	OutputPins.Add(FFlowPin(TEXT("Failed")));
}


FString UFlowNode_SystemClassBASE::L_GetFlag() const
{
	return Flag+Flag_Append;
}

FOmegaCommonMeta UFlowNode_SystemClassBASE::L_GetMeta() const
{
	if (GetFlowAsset() && LocalMetaToUse.IsValid())
	{
		return GetFlowAsset()->LocalMeta.FindOrAdd(LocalMetaToUse);
	}
	return FOmegaCommonMeta();
}

TArray<FString> UFlowNode_SystemClassBASE::L_GetFlags()
{
	return OGF_GAME_CORE()->Object_GetDefaultFlags(this);
}

TSubclassOf<UObject> UFlowNode_GameplaySystemBASE::L_GetFlagClass() const
{
	return L_GetSystem();
}

void UFlowNode_GameplaySystemBASE::L_SystemEnd(UObject* context, FString _flag)
{
	TriggerOutput(TEXT("Shutdown"),true);
}


void UFlowNode_GameplaySystemBASE::ExecuteInput(const FName& PinName)
{
	if(L_GetSystem())
	{
		if(AOmegaGameplaySystem* sys=GetWorld()->GetSubsystem<UOmegaSubsystem_World>()
												 ->ActivateGameplaySystem(L_GetSystem(),L_GetContext(),L_GetFlag()))
		{
			l_sys=sys;
			l_sys->OnSystemShutdown.AddDynamic(this,&UFlowNode_GameplaySystem::L_SystemEnd);
		}
		else
		{
			TriggerOutput(TEXT("Failed"),true);
		}
	}
	else
	{
		TriggerOutput(TEXT("Failed"),true);
	}
}


// ==============================================================================================================
// -
// ==============================================================================================================

TArray<FName> UFlowNode_GameplaySystem::L_GetConstants() const
{
	TArray<FName> out;
	OGF_CFG()->Constant_Systems.GetKeys(out);
	return out;
}

TSubclassOf<AOmegaGameplaySystem> UFlowNode_GameplaySystem::L_GetSystem() const
{
	if (!Constant.IsNone())
	{
		if (TSubclassOf<AOmegaGameplaySystem> m=OGF_CFG()->Constant_Systems.FindOrAdd(Constant).LoadSynchronous())
		{
			return m;
		}
	}
	return System;
}


UObject* UFlowNode_GameplaySystem::L_GetContext() const
{
	if(Context)
	{
		return Context;
	}
	return nullptr;
}


#if WITH_EDITOR
FString UFlowNode_GameplaySystem::GetNodeDescription() const
{
	FString appnd=""; if(L_GetSystem()) { return L_GetSystem()->GetName(); }
	return "System: "+appnd+"\n("+L_GetFlag()+")";
}
#endif
// ==============================================================================================================
// -
// ==============================================================================================================

#if WITH_EDITOR
FString UFlowNode_System_Encounter::GetNodeDescription() const
{
	return "BATTLE: "+Encounter.GetAssetName()+"\n("+L_GetFlag()+")";
}
#endif

TSubclassOf<AOmegaGameplaySystem> UFlowNode_System_Encounter::L_GetSystem() const
{
	if(TSubclassOf<AOmegaGameplaySystem> _class=GetMutableDefault<UOmegaSettings>()->System_FlowEncounter.LoadSynchronous())
	{
		return _class;
	}
	return nullptr;
}


UObject* UFlowNode_System_Encounter::L_GetContext() const
{
	if(!Encounter.IsNull())
	{
		return Encounter.LoadSynchronous(); 
	}
	return nullptr;
}

void UFlowNode_System_DlgFlow::L_SystemEnd(UObject* context, FString flag)
{
	if(APawn* p=GetWorld()->GetFirstPlayerController()->K2_GetPawn())
	{
		if(TransitOnFinish.IsValid())
		{
			p->SetActorTransform(TransitOnFinish.LoadSynchronous()->GetActorTransform());
		}
	}
	Super::L_SystemEnd(context, flag);
}


#if WITH_EDITOR
FString UFlowNode_System_DlgFlow::GetNodeDescription() const
{
	return "DIALOGUE: "+FlowAsset.GetAssetName()+"\n("+L_GetFlag()+")";
}
#endif

TSubclassOf<AOmegaGameplaySystem> UFlowNode_System_DlgFlow::L_GetSystem() const
{
	if(TSubclassOf<AOmegaGameplaySystem> _class=GetMutableDefault<UOmegaSettings>()->System_FlowAsset.LoadSynchronous())
	{
		return _class;
	}
	return nullptr;
}



UObject* UFlowNode_System_DlgFlow::L_GetContext() const
{
	return FlowAsset.LoadSynchronous();
}


// ==============================================================================================================
// -
// ==============================================================================================================

UObject* UFlowNode_Menu::L_GetContext() const
{
	if(Context)
	{
		return Context;
	}
	return nullptr;
}

TSubclassOf<UObject> UFlowNode_Menu::L_GetFlagClass() const
{
	return L_GetMenuClass();
}

TSubclassOf<UMenu> UFlowNode_Menu::L_GetMenuClass() const
{
	if (!Constant.IsNone())
	{
		if (TSubclassOf<UMenu> m=OGF_CFG()->Constant_Menus.FindOrAdd(Constant).LoadSynchronous())
		{
			return m;
		}
	}
	if (Menu)
	{
		return Menu;
	}
	return nullptr;
}


void UFlowNode_Menu::L_End(FGameplayTagContainer inTags, UObject* context, FString _flag)
{
	TriggerOutput(TEXT("Finished"),true);
}

UFlowNode_Menu::UFlowNode_Menu()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finished")));
	OutputPins.Add(FFlowPin(TEXT("Failed")));
}

void UFlowNode_Menu::ExecuteInput(const FName& PinName)
{
	if(Menu)
	{
		if(APlayerController* player=GetWorld()->GetFirstPlayerController())
		{
			if(UMenu* menu=player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->OpenMenu(L_GetMenuClass(),L_GetContext(),Tags,Flag))
			{
				l_menu=menu;
				l_menu->OnClosed.AddDynamic(this,&UFlowNode_Menu::L_End);
			}
		}
		else
		{
			TriggerOutput(TEXT("Failed"),true);
		}
	}
	else
	{
		TriggerOutput(TEXT("Failed"),true);
	}
}

TArray<FName> UFlowNode_Menu::L_GetConstants() const
{
	TArray<FName> out;
	OGF_CFG()->Constant_Menus.GetKeys(out);
	return out;
}

#if WITH_EDITOR

FString UFlowNode_Menu::GetNodeDescription() const
{
	FString appnd=""; if(L_GetFlagClass()) { return L_GetFlagClass()->GetName(); }
	return "MENU: "+appnd+"\n("+L_GetFlag()+")";
}


#endif

// ==============================================================================================================
// -
// ==============================================================================================================

UFlowNode_LevelTransitCheck::UFlowNode_LevelTransitCheck()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("true")));
	OutputPins.Add(FFlowPin(TEXT("false")));
	
}

void UFlowNode_LevelTransitCheck::ExecuteInput(const FName& PinName)
{
	if(Level.GetAssetName()==UGameplayStatics::GetCurrentLevelName(GetWorld()))
	{
		TriggerOutput(TEXT("true"),true);
	}
	else
	{
		if(TransitIfNotOnLevel)
		{
			GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetWorldManager()->Zone_TransitToLevel(Level,SpawnID);
		}
		TriggerOutput(TEXT("false"),true);
	}
	Super::ExecuteInput(PinName);
}

#if WITH_EDITOR
FString UFlowNode_LevelTransitCheck::GetNodeDescription() const
{
	return "Level Check: "+Level.GetAssetName();
}
#endif






void UFlowNode_GlobalEvent_Named::L_OnGEvent(FName Event, UObject* context,FOmegaCommonMeta _meta)
{
	if(b_isAwaitingEvent && Event_ToReceive==Event)
	{
		b_isAwaitingEvent=false;
		TriggerOutput(TEXT("Recieved"),true);
	}
}

UFlowNode_GlobalEvent_Named::UFlowNode_GlobalEvent_Named()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Send")));
	OutputPins.Add(FFlowPin(TEXT("Recieved")));
}

void UFlowNode_GlobalEvent_Named::ExecuteInput(const FName& PinName)
{
	if(UOmegaSubsystem_GameInstance* mang=OGF_Subsystems::oGameInstance(this))
	{
		if(Event_ToSend.IsValid())
		{
			mang->FireGlobalEvent(Event_ToSend,this, FOmegaCommonMeta());
		}
		TriggerOutput(TEXT("Send"),false);
		if(Event_ToReceive.IsValid())
		{
			b_isAwaitingEvent=true;
			mang->OnGlobalEvent.AddDynamic(this,&UFlowNode_GlobalEvent_Named::L_OnGEvent);
		}
		else
		{
			Finish();
		}
	}
}
