// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaSettings.h"

#include "OmegaSettings_Gameplay.h"
#include "OmegaSettings_Global.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Functions/F_File.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "Subsystems/Subsystem_Save.h"
#include "Widget/Menu.h"


UOmegaSettings::UOmegaSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RuntimeImport_BaseDirectory.Add("/Override/");
    Default_InteractTag=FGameplayTag::RequestGameplayTag("Event.Actor.Interact");
    
    System_FlowAsset=TSoftClassPtr<AOmegaGameplaySystem>(FSoftClassPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_Dialog.sys_OMEGA_E_Dialog")));
   // System_FlowAsset=TSoftClassPtr<AOmegaGameplaySystem>(FSoftClassPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_Dialog.sys_OMEGA_E_Dialog")));
    System_Interaction=TSoftClassPtr<AOmegaGameplaySystem>(FSoftClassPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_Dialog.sys_OMEGA_E_Dialog")));
}

TSubclassOf<AOmegaGameplaySystem> UOmegaSettings::CorrectClass_System(TSubclassOf<AOmegaGameplaySystem> Class) const
{
    TMap<TSoftClassPtr<AOmegaGameplaySystem>,TSoftClassPtr<AOmegaGameplaySystem>> _rep=Replacement_Systems;
    if (TSubclassOf<AOmegaGameplaySystem> _NewVal=_rep.FindOrAdd(TSoftClassPtr<AOmegaGameplaySystem>(Class)).LoadSynchronous())
    {
        return _NewVal;
    }
    return Class;
}

TSubclassOf<UMenu> UOmegaSettings::CorrectClass_Menu(TSubclassOf<UMenu> Class) const
{
    TMap<TSoftClassPtr<UMenu>,TSoftClassPtr<UMenu>> _rep=Replacement_Menus;
    if (TSubclassOf<UMenu> _NewVal=_rep.FindOrAdd(TSoftClassPtr<UMenu>(Class)).LoadSynchronous())
    {
        return _NewVal;
    }
    return Class;
}

TSubclassOf<UHUDLayer> UOmegaSettings::CorrectClass_HUD(TSubclassOf<UHUDLayer> Class) const
{
    TMap<TSoftClassPtr<UHUDLayer>,TSoftClassPtr<UHUDLayer>> _rep=Replacement_HUDLayers;
    if (TSubclassOf<UHUDLayer> _NewVal=_rep.FindOrAdd(TSoftClassPtr<UHUDLayer>(Class)).LoadSynchronous())
    {
        return _NewVal;
    }
    return Class;
}

TArray<TSubclassOf<UOmegaGameplayModule>> UOmegaSettings::GetGameplayModuleClasses() const
{
	TArray<TSubclassOf<UOmegaGameplayModule>> ModuleClasses;
	for(FSoftClassPath TempPath : RegisteredGameplayModules)
	{
		UClass* const LocalClass = TempPath.IsValid() ? LoadObject<UClass>(nullptr, *TempPath.ToString()) : nullptr;
		ModuleClasses.Add(LocalClass);
	}
	return ModuleClasses;
}

TSubclassOf<AOmegaGameplaySystem> UOmegaSettings::GetSystem_FlowAsset() const
{
    if(TSubclassOf<AOmegaGameplaySystem> a=System_FlowAsset.LoadSynchronous())
    {
        return a;
    }
    return nullptr;
}

TSubclassOf<AOmegaGameplaySystem> UOmegaSettings::GetSystem_Encounter() const
{
    if(TSubclassOf<AOmegaGameplaySystem> a=System_FlowEncounter.LoadSynchronous())
    {
        return a;
    }
    return nullptr;
}

TSubclassOf<AOmegaGameplaySystem> UOmegaSettings::GetSystem_Interact() const
{
    if(TSubclassOf<AOmegaGameplaySystem> a=System_Interaction.LoadSynchronous())
    {
        return a;
    }
    return nullptr;
}

UClass* UOmegaSettings::GetOmegaGameSaveClass() const
{
	UClass* const LocalSaveClass = GameSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GameSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGame::StaticClass();
}


UClass* UOmegaSettings::GetOmegaGlobalSaveClass() const
{
	UClass* const LocalSaveClass = GlobalSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GlobalSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGlobal::StaticClass();
}

UOmegaGlobalSettings* UOmegaSettings::GetGlobalSettings()
{
	if(TSoftClassPtr<UOmegaGlobalSettings> _cls=GetMutableDefault<UOmegaSettings>()->GlobalSettingsClass)
	{
		return Cast<UOmegaGlobalSettings>(_cls.LoadSynchronous()->GetDefaultObject());
	}
	return GetMutableDefault<UOmegaGlobalSettings>();
}

UOmegaFileManagerSettings* UOmegaSettings::GetSettings_File() const
{
    if (UOmegaFileManagerSettings* set=Cast<UOmegaFileManagerSettings>(DefaultSettings_FileManager.TryLoad()))
    {
        return set;
    }
    return nullptr;
}

TMap<FName, FOmegaInputConfig> UOmegaSettings::GetAllInputActionConfigs() const
{
    TMap<FName, FOmegaInputConfig> out;
    for (auto* s : GetAllGameplaySettings())
    {
        if (s)
        {
            out.Append(s->InputActionConfigs);
        }
    }
    return out;
}

FOmegaInputConfig UOmegaSettings::GetInputActionConfig(FName input_action) const
{
    TMap<FName, FOmegaInputConfig> temp=GetAllInputActionConfigs();
    return temp.FindOrAdd(input_action);
}

TArray<UOmegaSettings_Gameplay*> UOmegaSettings::GetAllGameplaySettings() const
{
    TArray<UOmegaSettings_Gameplay*> out;
    for (auto set : Imported_GameplaySettings)
    {
        if (UOmegaSettings_Gameplay* s=set.LoadSynchronous())
        {
            out.Add(s);
        }
    }
    return out;
}

//BitFlag -------------------------------------------------------


void UOmegaSettings::OverrideActorLabel(AActor* actor)
{
    if (actor)
    {
#if WITH_EDITOR
        if (actor->GetActorLabel().Contains(actor->GetClass()->GetName()))
        {
            FString new_label=ActorLabelDefaultOverrides.FindOrAdd(TSoftClassPtr<AActor>(actor->GetClass()));
            actor->SetActorLabel(new_label+"_"+FString::FromInt(FMath::RandRange(0,999)));
        }
#endif
    }
}


const FOmegaBitmaskEditorData* UOmegaSettings::GetEditorDataForClass(UClass* Class) const
{
    if (!Class)
    {
        return nullptr;
    }

    // First, try exact match
    TSoftClassPtr<UObject> SoftClassPtr(Class);
    if (const FOmegaBitmaskEditorData* Found = ClassBitflagData.Find(SoftClassPtr))
    {
        //Check if should CopyFromOther
        if (Found->CopyFrom.IsValid())
        {
            if (const FOmegaBitmaskEditorData* Found2 = ClassBitflagData.Find(Found->CopyFrom))
            {
                return Found2;
            }
        }
        return Found;
    }

    // If no exact match, check parent classes
    UClass* ParentClass = Class->GetSuperClass();
    while (ParentClass)
    {
        TSoftClassPtr<UObject> ParentSoftClassPtr(ParentClass);
        if (const FOmegaBitmaskEditorData* Found = ClassBitflagData.Find(ParentSoftClassPtr))
        {
            return Found;
        }
        ParentClass = ParentClass->GetSuperClass();
    }

    const FOmegaBitmaskEditorData output=GetGlobalSettings()->Bitflags_GetByObject(Class);
    return &output;
}

FText UOmegaSettings::GetBitflagName(UClass* Class, int32 BitIndex) const
{
    const FOmegaBitmaskEditorData* Data = GetEditorDataForClass(Class);
    
    if (Data && Data->Bitflags.IsValidIndex(BitIndex))
    {
        return Data->Bitflags[BitIndex].Title;
    }
    return FText::FromString("Unknown");
}

FText UOmegaSettings::GetBitEnumName(UClass* Class, int32 EnumIndex) const
{
    const FOmegaBitmaskEditorData* Data = GetEditorDataForClass(Class);
    
    if (Data && Data->BitEnums.IsValidIndex(EnumIndex))
    {
        return Data->BitEnums[EnumIndex].Title;
    }
    return FText::FromString("Unknown");
}

FText UOmegaSettings::GetBitEnumOptionName(UClass* Class, int32 EnumIndex, int32 OptionIndex) const
{
    const FOmegaBitmaskEditorData* Data = GetEditorDataForClass(Class);
    
    if (Data && Data->BitEnums.IsValidIndex(EnumIndex))
    {
        const FOmegaBitmaskEditorEnumData& EnumData = Data->BitEnums[EnumIndex];
        if (EnumData.Options.IsValidIndex(OptionIndex))
        {
            return EnumData.Options[OptionIndex].Title;
        }
    }
    return FText::FromString(FString::Printf(TEXT("%d"), OptionIndex));
}

#if WITH_EDITOR
FText UOmegaSettings::GetSectionText() const
{
    return FText::FromString("Omega Settings");
}

FText UOmegaSettings::GetSectionDescription() const
{
    return FText::FromString("Configure Omega system settings");
}

void UOmegaSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    
    SaveConfig();
}
#endif

