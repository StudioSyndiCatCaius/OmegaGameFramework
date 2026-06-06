// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaSettings.h"
#include "MetasoundSource.h"
#include "Functions/F_Physics.h"

UMetaSoundSource* UOmegaSettings::GetMetaSoundSourceFromPath() const
{
	return Cast<UMetaSoundSource>(BgmMetasound.LoadSynchronous());
}


#include "OmegaGameplayConfig.h"
#include "OmegaGameManager.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Functions/F_File.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "Subsystems/Subsystem_Save.h"
#include "Widget/Menu.h"


UOmegaSettings::UOmegaSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    //Default_InteractTag=FGameplayTag::RequestGameplayTag("Event.Actor.Interact");
    
    CombatantConfig_Default.AttributeSet=TSoftObjectPtr<UOmegaAttributeSet>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Attributes/AttSet_OMEGA_Demo.AttSet_OMEGA_Demo")));
    
    
    
}


TSubclassOf<AOmegaGameplaySystem> UOmegaSettings::CorrectClass_System(TSubclassOf<AOmegaGameplaySystem> Class) const
{
    
    return Class;
}

TSubclassOf<UMenu> UOmegaSettings::CorrectClass_Menu(TSubclassOf<UMenu> Class) const
{
    
    return Class;
}

TSubclassOf<UHUDLayer> UOmegaSettings::CorrectClass_HUD(TSubclassOf<UHUDLayer> Class) const
{
    
    return Class;
}

TArray<TSubclassOf<UOmegaGameplayModule>> UOmegaSettings::GetGameplayModuleClasses() const
{
	TArray<TSubclassOf<UOmegaGameplayModule>> ModuleClasses;
    /*
	for(FSoftClassPath TempPath : RegisteredGameplayModules)
	{
		UClass* const LocalClass = TempPath.IsValid() ? LoadObject<UClass>(nullptr, *TempPath.ToString()) : nullptr;
		ModuleClasses.Add(LocalClass);
	}
	*/
	return ModuleClasses;
}


UClass* UOmegaSettings::GetOmegaGameSaveClass() const
{
	UClass* const LocalSaveClass = GameSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GameSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGame::StaticClass();
}

FOmegaCombatantConfig UOmegaSettings::L_GetCombatantConfigFromActor(AActor* Actor)
{
    if (Actor)
    {
        TSoftClassPtr<AActor> c=TSoftClassPtr<AActor>(Actor->GetClass());
        if (CombatantConfig_ByClass.Contains(c))
        {
            return CombatantConfig_ByClass[c];
        }
        return CombatantConfig_Default;
    }
    return FOmegaCombatantConfig();
}


UClass* UOmegaSettings::GetOmegaGlobalSaveClass() const
{
	UClass* const LocalSaveClass = GlobalSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GlobalSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGlobal::StaticClass();
}

UOmegaGameManager* UOmegaSettings::GetGameCore() const
{
    if (!GlobalSettingsClass.IsNull())
    {
        if (TSubclassOf<UOmegaGameManager> _temp=GlobalSettingsClass.LoadSynchronous())
        {
            if (UOmegaGameManager* _core=GetMutableDefault<UOmegaGameManager>(_temp))
            {
                return _core;
            }
        }
    }
    
	return GetMutableDefault<UOmegaGameManager>();
}


TMap<FGameplayTag, FOmegaInputConfig> UOmegaSettings::GetAllInputActionConfigs() const
{
    TMap<FGameplayTag, FOmegaInputConfig> out;
    for (auto* s : GetAllGameplaySettings())
    {
        if (s)
        {
            out.Append(s->InputActionConfigs);
        }
    }
    return out;
}

FOmegaInputConfig UOmegaSettings::GetInputActionConfig(FGameplayTag input_action) const
{
    TMap<FGameplayTag, FOmegaInputConfig> temp=GetAllInputActionConfigs();
    return temp.FindOrAdd(input_action);
}

UOmegaPhysicsSurfaceType* UOmegaSettings::GetSurfaceTypeFromMaterial(UPhysicalMaterial* mat)
{
    for (auto * g : GetAllGameplaySettings())
    {
        if (g)
        {
            TArray<UPhysicalMaterial*> materialP;
            g->PhysicsSurfaceTypes.GetKeys(materialP);
            for (auto* phys : materialP)
            {
                if (phys)
                {
                    return g->PhysicsSurfaceTypes[phys];
                }
            }
        }
    }
    if (UOmegaPhysicsSurfaceType* t=DefaultSurfaceTypeData.LoadSynchronous())
    {
        return t;
    }
    return nullptr;
}

TArray<UOmegaGameplayConfig*> UOmegaSettings::GetAllGameplaySettings() const
{
    TArray<UOmegaGameplayConfig*> out;
    for (auto set : Imported_GameplaySettings)
    {
        if (UOmegaGameplayConfig* s=set.LoadSynchronous())
        {
            out.Add(s);
        }
    }
    return out;
}

//BitFlag -------------------------------------------------------


void UOmegaSettings::OverrideActorLabel(AActor* actor,const FString& string)
{
    if (actor)
    {
#if WITH_EDITOR
        FString new_label="";
        if (!string.IsEmpty())
        {
            new_label=string;
        }
        else if (actor->GetActorLabel().Contains(actor->GetClass()->GetName()))
        {
            new_label=ActorLabelDefaultOverrides.FindOrAdd(TSoftClassPtr<AActor>(actor->GetClass()));
        }

        if (!new_label.IsEmpty())
        {
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
    
    if (Class->ImplementsInterface(UDataInterface_General::StaticClass()))
    {
        //if default object
        if (UObject* tempObj=GetMutableDefault<UObject>(Class))
        {
            bool b_override=false;

            static FOmegaBitmaskEditorData ed_dat;
            ed_dat = IDataInterface_General::Execute_Bitflags_Override(tempObj, b_override);
            if (b_override)
            {
                return &ed_dat;
            }
        }
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

    auto& mutableMap = const_cast<TMap<TSoftClassPtr<UObject>, FOmegaBitmaskEditorData>&>(ClassBitflagData);
    mutableMap.Add(TSoftClassPtr<UObject>(Class), GetGameCore()->Bitflags_GetByObject(Class));
    return mutableMap.Find(TSoftClassPtr<UObject>(Class));
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

