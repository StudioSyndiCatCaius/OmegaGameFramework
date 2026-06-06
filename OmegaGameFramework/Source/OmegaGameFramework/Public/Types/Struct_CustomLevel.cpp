#include "Struct_CustomLevel.h"
#include "EngineUtils.h"
#include "GameFramework/WorldSettings.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/PlayerController.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "Dom/JsonValue.h"
#include "GameFramework/GameSession.h"
#include "UObject/UnrealType.h"

void FOmegaCustomLevelWrapper::CachePackagePath()
{
    if (WorldReference)
        WorldPackagePath = WorldReference->GetPathName();
}

bool FOmegaCustomLevelWrapper::ResolveWorldReference()
{
    if (WorldPackagePath.IsEmpty()) return false;
    WorldReference = FindObject<UWorld>(nullptr, *WorldPackagePath);
    return WorldReference != nullptr;
}

// Shared helper — serializes non-default properties of any UObject into a JsonObject
static void SerializeObjectProperties(UObject* Object, UObject* CDO, TSharedPtr<FJsonObject>& OutObj)
{
    for (TFieldIterator<FProperty> PropIt(Object->GetClass()); PropIt; ++PropIt)
    {
        FProperty* Prop = *PropIt;
        if (!Prop->HasAnyPropertyFlags(CPF_Edit | CPF_BlueprintVisible)) continue;

        void* ObjValue = Prop->ContainerPtrToValuePtr<void>(Object);
        void* CDOValue = Prop->ContainerPtrToValuePtr<void>(CDO);
        if (Prop->Identical(ObjValue, CDOValue)) continue;

        FString ValueStr;
        Prop->ExportTextItem_Direct(ValueStr, ObjValue, CDOValue, Object, PPF_None);
        OutObj->SetStringField(Prop->GetName(), ValueStr);
    }
}

// Shared helper — applies saved properties back onto a UObject
static void DeserializeObjectProperties(UObject* Object, const TSharedPtr<FJsonObject>& PropsObj)
{
    if (!PropsObj.IsValid()) return;
    for (auto& KV : PropsObj->Values)
    {
        FProperty* Prop = FindFProperty<FProperty>(Object->GetClass(), *KV.Key);
        if (!Prop) continue;

        void* ValuePtr = Prop->ContainerPtrToValuePtr<void>(Object);
        FString ValStr;
        KV.Value->TryGetString(ValStr);
        Prop->ImportText_Direct(*ValStr, ValuePtr, Object, PPF_None);
    }
}

static const TArray<UClass*> ImplicitBlacklist =
{
    AGameSession::StaticClass(),
   // AGameplayDebuggerPlayerManager::StaticClass(),
    //AGameplayDebuggerCategoryReplicator::StaticClass(),
    //ADefaultPhysicsVolume::StaticClass()
};

bool FOmegaCustomLevelWrapper::SaveToJson(FString& JsonString, const FOmegaCustomLevelSaveConfig& Config)
{
    if (!WorldReference)
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveToJson: WorldReference is null"));
        return false;
    }

    TArray<TSharedPtr<FJsonValue>> ActorArray;
    int32 ActorCount = 0;

    for (TActorIterator<AActor> It(WorldReference); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor) continue;

        UClass* ActorClass = Actor->GetClass();

        if (Actor->IsA<AWorldSettings>()) continue;
        if (ActorClass->HasAnyClassFlags(CLASS_NotPlaceable)) continue;

        bool bImplicitBlacklisted = false;
        for (UClass* BlackClass : ImplicitBlacklist)
        {
            if (Actor->IsA(BlackClass)) { bImplicitBlacklisted = true; break; }
        }
        if (bImplicitBlacklisted) continue;

        if (!Config.bSavePlayerPawn && Actor->GetInstigatorController()
            && Actor->GetInstigatorController()->IsA<APlayerController>()) continue;

        bool bClassBlacklisted = false;
        for (TSubclassOf<AActor> BlackClass : Config.BlacklistActorClasses)
        {
            if (BlackClass && Actor->IsA(BlackClass)) { bClassBlacklisted = true; break; }
        }
        if (bClassBlacklisted) continue;

        bool bTagBlacklisted = false;
        for (const FName& Tag : Config.BlacklistActorTags)
        {
            if (Actor->ActorHasTag(Tag)) { bTagBlacklisted = true; break; }
        }
        if (bTagBlacklisted) continue;

        if (!Config.WhitelistActorClasses.IsEmpty())
        {
            bool bClassAllowed = false;
            for (TSubclassOf<AActor> WhiteClass : Config.WhitelistActorClasses)
            {
                if (WhiteClass && Actor->IsA(WhiteClass)) { bClassAllowed = true; break; }
            }
            if (!bClassAllowed) continue;
        }

        if (!Config.WhitelistActorTags.IsEmpty())
        {
            bool bTagAllowed = false;
            for (const FName& Tag : Config.WhitelistActorTags)
            {
                if (Actor->ActorHasTag(Tag)) { bTagAllowed = true; break; }
            }
            if (!bTagAllowed) continue;
        }

        ActorCount++;

        TSharedPtr<FJsonObject> ActorObj = MakeShared<FJsonObject>();
        ActorObj->SetStringField("ActorClass", ActorClass->GetPathName());
        ActorObj->SetStringField("ActorName", Actor->GetName());

        // Transform
        FTransform T = Actor->GetActorTransform();
        TSharedPtr<FJsonObject> TransformObj = MakeShared<FJsonObject>();
        TransformObj->SetStringField("Position", T.GetLocation().ToString());
        TransformObj->SetStringField("Rotation", T.GetRotation().Rotator().ToString());
        TransformObj->SetStringField("Scale", T.GetScale3D().ToString());
        ActorObj->SetObjectField("Transform", TransformObj);

        // Actor properties (CDO diff)
        UObject* ActorCDO = ActorClass->GetDefaultObject();
        TSharedPtr<FJsonObject> PropsObj = MakeShared<FJsonObject>();
        SerializeObjectProperties(Actor, ActorCDO, PropsObj);
        ActorObj->SetObjectField("Properties", PropsObj);

        // Components
        TSharedPtr<FJsonObject> ComponentsObj = MakeShared<FJsonObject>();
        for (UActorComponent* Comp : Actor->GetComponents())
        {
            if (!Comp) continue;

            UObject* CompCDO = Comp->GetClass()->GetDefaultObject();
            TSharedPtr<FJsonObject> CompObj = MakeShared<FJsonObject>();
            SerializeObjectProperties(Comp, CompCDO, CompObj);

            // Only save component if it has non-default values
            if (CompObj->Values.Num() > 0)
            {
                ComponentsObj->SetObjectField(Comp->GetName(), CompObj);
            }
        }
        ActorObj->SetObjectField("Components", ComponentsObj);

        UE_LOG(LogTemp, Log, TEXT("SaveToJson: Actor [%s] | Components: %d"), *Actor->GetName(), ComponentsObj->Values.Num());
        ActorArray.Add(MakeShared<FJsonValueObject>(ActorObj));
    }

    UE_LOG(LogTemp, Log, TEXT("SaveToJson: Total actors captured: %d"), ActorCount);

    TSharedPtr<FJsonObject> Root = MakeShared<FJsonObject>();
    Root->SetStringField("WorldName", WorldName);
    Root->SetStringField("WorldPackagePath", WorldPackagePath);
    Root->SetArrayField("Actors", ActorArray);

    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
    bool bResult = FJsonSerializer::Serialize(Root.ToSharedRef(), Writer);
    Writer->Close();

    UE_LOG(LogTemp, Log, TEXT("SaveToJson: Output string length: %d"), JsonString.Len());
    return bResult;
}

bool FOmegaCustomLevelWrapper::DeserializeFromJson(const FString& JsonString, TArray<TSharedPtr<FJsonValue>>& OutActorArray)
{
    if (JsonString.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("DeserializeFromJson: JsonString is empty"));
        return false;
    }

    FString CleanJson = JsonString;
    if (CleanJson.StartsWith(TEXT("\xEF\xBB\xBF")))
        CleanJson = CleanJson.RightChop(3);
    if (CleanJson[0] == 0xFEFF)
        CleanJson = CleanJson.RightChop(1);

    TSharedPtr<FJsonObject> Root;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(CleanJson);
    if (!FJsonSerializer::Deserialize(Reader, Root))
    {
        UE_LOG(LogTemp, Warning, TEXT("DeserializeFromJson: Failed — %s"), *Reader->GetErrorMessage());
        return false;
    }

    WorldName        = Root->GetStringField("WorldName");
    WorldPackagePath = Root->GetStringField("WorldPackagePath");
    OutActorArray    = Root->GetArrayField("Actors");

    return true;
}

bool FOmegaCustomLevelWrapper::SpawnActors(const TArray<TSharedPtr<FJsonValue>>& ActorArray)
{
    if (!WorldReference)
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnActors: WorldReference is null"));
        return false;
    }

    APlayerStart* FirstPlayerStart = nullptr;

    for (auto& Val : ActorArray)
    {
        TSharedPtr<FJsonObject> ActorObj = Val->AsObject();

        FString ClassName = ActorObj->GetStringField("ActorClass");
        TSharedPtr<FJsonObject> TransformObj = ActorObj->GetObjectField("Transform");

        UClass* ActorClass = LoadObject<UClass>(nullptr, *ClassName);
        if (!ActorClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("SpawnActors: Could not resolve class [%s]"), *ClassName);
            continue;
        }

        FVector Pos;   Pos.InitFromString(TransformObj->GetStringField("Position"));
        FRotator Rot;  Rot.InitFromString(TransformObj->GetStringField("Rotation"));
        FVector Scale; Scale.InitFromString(TransformObj->GetStringField("Scale"));

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        AActor* NewActor = WorldReference->SpawnActor<AActor>(ActorClass, FTransform(Rot, Pos, Scale), SpawnParams);

        if (!NewActor)
        {
            UE_LOG(LogTemp, Warning, TEXT("SpawnActors: Failed to spawn [%s]"), *ClassName);
            continue;
        }

        // Restore actor properties
        DeserializeObjectProperties(NewActor, ActorObj->GetObjectField("Properties"));

        // Restore component properties
        const TSharedPtr<FJsonObject>& ComponentsObj = ActorObj->GetObjectField("Components");
        if (ComponentsObj.IsValid())
        {
            for (UActorComponent* Comp : NewActor->GetComponents())
            {
                if (!Comp) continue;
                const TSharedPtr<FJsonObject>* CompObjPtr;
                if (ComponentsObj->TryGetObjectField(Comp->GetName(), CompObjPtr))
                {
                    DeserializeObjectProperties(Comp, *CompObjPtr);
                }
            }
        }

        // Track first PlayerStart for spawn positioning
        if (!FirstPlayerStart && NewActor->IsA<APlayerStart>())
        {
            FirstPlayerStart = Cast<APlayerStart>(NewActor);
        }
    }

    // Move player to first PlayerStart found
    if (FirstPlayerStart)
    {
        for (FConstPlayerControllerIterator It = WorldReference->GetPlayerControllerIterator(); It; ++It)
        {
            APlayerController* PC = It->Get();
            if (!PC) continue;

            APawn* Pawn = PC->GetPawn();
            if (Pawn)
            {
                Pawn->SetActorTransform(FirstPlayerStart->GetActorTransform());
            }
            else
            {
                // No pawn yet — restart at the PlayerStart location
                PC->SetInitialLocationAndRotation(
                    FirstPlayerStart->GetActorLocation(),
                    FirstPlayerStart->GetActorRotation());
            }
            break; // Only move first local player
        }
    }

    return true;
}

bool FOmegaCustomLevelWrapper::LoadFromJson(const FString& JsonString)
{
    TArray<TSharedPtr<FJsonValue>> ActorArray;
    return DeserializeFromJson(JsonString, ActorArray) && SpawnActors(ActorArray);
}