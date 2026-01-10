// Copyright 2018-2023 - Roberto De Ioris

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LuaState.h"
#include "LuaValue.h"
#include  "LuaSettings.h"
#include "LuaTableAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/TextProperty.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Sound/SoundWave.h"
#include "LuaBlueprintFunctionLibrary.generated.h"

class UScriptStruct;

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FLuaHttpSuccess, FLuaValue, ReturnValue, bool, bWasSuccessful, int32, StatusCode);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FLuaHttpResponseReceived, FLuaValue, Context, FLuaValue, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLuaHttpError, FLuaValue, Context);

UENUM(BlueprintType)
enum class ELuaReflectionType : uint8
{
	Unknown,
	Property,
	Function,
};

UENUM(Blueprintable)
enum ELuaValueResult
{
	Valid		UMETA(DisplayName = "Valid"),
	Nil		UMETA(DisplayName = "Nil"),
};

UCLASS()
class LUAMACHINE_API ULuaBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION()
	static ULuaState* LOCAL_getLuaState(UObject* WorldContextObject, TSubclassOf<ULuaState> StateClass);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static TSubclassOf<ULuaState> GetDefaultLuaState();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaCreateNil();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaCreateString(const FString& String);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaCreateNumber(const float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaCreateInteger(const int32 Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaCreateBool(const bool bInBool);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaCreateTable(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaCreateThread(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Value /* Function */);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaCreateObject(UObject* InObject);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaCreateObjectInState(UObject* WorldContextObject, TSubclassOf<ULuaState> State, UObject* InObject);

	UFUNCTION(BlueprintCallable, meta=(AdvancedDisplay="State", WorldContext="WorldContextObject"), Category="Lua")
	static FLuaValue LuaGetGlobal(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Name);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static void LuaSetGlobal(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Name, FLuaValue Value);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static void LuaSetUserDataMetaTable(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue MetaTable);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue AssignLuaValueToLuaState(UObject* WorldContextObject, FLuaValue Value, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaTableGetField(FLuaValue Table, const FString& Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue GetLuaComponentAsLuaValue(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue GetLuaComponentByStateAsLuaValue(AActor* Actor, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue GetLuaComponentByNameAsLuaValue(AActor* Actor, const FString& Name);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue GetLuaComponentByStateAndNameAsLuaValue(AActor* Actor, TSubclassOf<ULuaState> State, const FString& Name);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaComponentGetField(FLuaValue LuaComponent, const FString& Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static FLuaValue LuaTableGetByIndex(FLuaValue Table, const int32 Index);

	/* Assigns a value to a table index, returned value is the table itself */
	UFUNCTION(BlueprintCallable, Category="Lua")
	static FLuaValue LuaTableSetByIndex(FLuaValue Table, const int32 Index, FLuaValue Value);

	/* Returns the array of keys in the table */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static TArray<FLuaValue> LuaTableGetKeys(FLuaValue Table);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static TArray<FLuaValue> LuaTableGetValues(FLuaValue Table);

	/* Assigns a value to a table key, returned value is the table itself */
	UFUNCTION(BlueprintCallable, Category="Lua")
	static FLuaValue LuaTableSetField(FLuaValue Table, const FString& Key, FLuaValue Value);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"), Category="Lua")
	static FLuaValue LuaGlobalCall(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Name, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"), Category="Lua")
	static TArray<FLuaValue> LuaGlobalCallMulti(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Name, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"), Category="Lua")
	static FLuaValue LuaGlobalCallValue(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Value, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"), Category="Lua")
	static TArray<FLuaValue> LuaGlobalCallValueMulti(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Value, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"), Category = "Lua")
	static ULuaState* LuaGetState(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	/* Calls a lua value (must be callable) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category="Lua")
	static FLuaValue LuaValueCall(FLuaValue Value, TArray<FLuaValue> Args);

	/* Calls a lua value (must be callable and not nil) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category="Lua")
	static FLuaValue LuaValueCallIfNotNil(FLuaValue Value, TArray<FLuaValue> Args);

	/* Calls a lua value taken from a table by key (must be callable) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category="Lua")
	static FLuaValue LuaTableKeyCall(FLuaValue InTable, const FString& Key, TArray<FLuaValue> Args);

	/* Calls a lua value taken from a table by key (must be callable), passing the table itself as the first argument (useful for table:function syntax) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category = "Lua")
	static FLuaValue LuaTableKeyCallWithSelf(FLuaValue InTable, const FString& Key, TArray<FLuaValue> Args);

	/* Calls a lua value taken from a table by index (must be callable) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category="Lua")
	static FLuaValue LuaTableIndexCall(FLuaValue InTable, const int32 Index, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static TArray<FLuaValue> LuaTableUnpack(FLuaValue InTable);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaTablePack(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TArray<FLuaValue> Values);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaTableMergePack(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TArray<FLuaValue> Values1, TArray<FLuaValue> Values2);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static TArray<FLuaValue> LuaTableMergeUnpack(FLuaValue InTable1, FLuaValue InTable2);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static void LuaTableFillObject(FLuaValue InTable, UObject* InObject);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaTableFromMap(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TMap<FString, FLuaValue> Map);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static TArray<FLuaValue> LuaTableRange(FLuaValue InTable, const int32 First, const int32 Last);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static TArray<FLuaValue> LuaValueArrayMerge(TArray<FLuaValue> Array1, TArray<FLuaValue> Array2);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static TArray<FLuaValue> LuaValueArrayAppend(TArray<FLuaValue> Array, FLuaValue Value);

	/* Calls a lua value with multiple return values (must be callable) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category="Lua")
	static TArray<FLuaValue> LuaValueCallMulti(FLuaValue Value, TArray<FLuaValue> Args);

	/* Resume a lua coroutine/thread with multiple return values (must be callable) */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category = "Lua")
	static TArray<FLuaValue> LuaValueResumeMulti(FLuaValue Value, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static ELuaThreadStatus LuaThreadGetStatus(FLuaValue Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static int32 LuaThreadGetStackTop(FLuaValue Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static int32 LuaValueLength(FLuaValue Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static bool LuaValueIsReferencedInLuaRegistry(FLuaValue Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static UClass* LuaValueToBlueprintGeneratedClass(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static UObject* LuaValueLoadObject(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static UClass* LuaValueLoadClass(const FLuaValue& Value, const bool bDetectBlueprintGeneratedClass);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Lua")
	static bool LuaValueFromJson(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Json, FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static FString LuaValueToJson(FLuaValue Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static FLuaValue LuaValueFromBase64(const FString& Base64);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static FString LuaValueToBase64(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static FLuaValue LuaValueFromUTF16(const FString& String);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static FString LuaValueToUTF16(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static FLuaValue LuaValueFromUTF8(const FString& String);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static FString LuaValueToUTF8(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static FLuaValue LuaValueFromUTF32(const FString& String);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static FString LuaValueToUTF32(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static int64 LuaValueToPointer(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FString LuaValueToHexPointer(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static int32 LuaGetTop(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static void LuaStateDestroy(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static void LuaStateReload(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaRunFile(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Filename, const bool bIgnoreNonExistent);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaRunNonContentFile(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Filename, const bool bIgnoreNonExistent);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaRunCodeAsset(UObject* WorldContextObject, TSubclassOf<ULuaState> State, ULuaCode* CodeAsset);
	
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaRunByteCode(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const TArray<uint8>& ByteCode, const FString& CodePath);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State, CodePath", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaRunString(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& CodeString, FString CodePath="");

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State, CodePath", WorldContext = "WorldContextObject"), Category="Lua")
	static FLuaValue LuaRunString_AsFunction(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& CodeString, TArray<FLuaValue> Args, FString CodePath="");
	
	/* Make an HTTP GET request to the specified URL to download the Lua script to run */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", AutoCreateRefTerm = "Headers"), Category = "Lua")
	static void LuaRunURL(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& URL, TMap<FString, FString> Headers, const FString& SecurityHeader, const FString& SignaturePublicExponent, const FString& SignatureModulus, FLuaHttpSuccess Completed);

	/* Make an HTTP GET request to the specified URL to download the Lua script to run */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", AutoCreateRefTerm = "Headers,Error,ResponseReceived"), Category = "Lua")
	static void LuaHttpRequest(UObject* WorldContextObject, TSubclassOf<ULuaState> State, const FString& Method, const FString& URL, TMap<FString, FString> Headers, FLuaValue Body, FLuaValue Context, const FLuaHttpResponseReceived& ResponseReceived, const FLuaHttpError& Error);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static UTexture2D* LuaValueToTransientTexture(const int32 Width, const int32 Height, const FLuaValue& Value, const EPixelFormat PixelFormat = EPixelFormat::PF_B8G8R8A8, bool bDetectFormat = false);


	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"), Category = "Lua")
	static void LuaValueYield(FLuaValue Value, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static bool LuaLoadPakFile(const FString& Filename, FString Mountpoint, TArray<FLuaValue>& Assets, FString ContentPath, FString AssetRegistryPath);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaNewLuaUserDataObject(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TSubclassOf<ULuaUserDataObject> UserDataObjectClass, bool bTrackObject=true);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static int32 LuaGetUsedMemory(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static void LuaGCCollect(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static void LuaGCStop(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category="Lua")
	static void LuaGCRestart(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaTableAssetToLuaTable(UObject* WorldContextObject, TSubclassOf<ULuaState> State, ULuaTableAsset* TableAsset);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static bool LuaTableImplements(FLuaValue Table, ULuaTableAsset* TableAsset);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static bool LuaTableImplementsAll(FLuaValue Table, TArray<ULuaTableAsset*> TableAssets);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static bool LuaTableImplementsAny(FLuaValue Table, TArray<ULuaTableAsset*> TableAssets);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsNil(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsOwned(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static TSubclassOf<ULuaState> LuaValueGetOwner(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsNotNil(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsTable(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsBoolean(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsNumber(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsInteger(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsString(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsFunction(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Lua")
	static bool LuaValueIsThread(const FLuaValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static FLuaValue LuaTableSetMetaTable(FLuaValue InTable, FLuaValue InMetaTable);



		UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "LuaValueTypes"), Category = "Lua")
	static void SwitchOnLuaValueType(const FLuaValue& LuaValue, ELuaValueType& LuaValueTypes);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "LuaReflectionTypes"), Category = "Lua")
	static void GetLuaReflectionType(UObject* InObject, const FString& Name, ELuaReflectionType& LuaReflectionTypes);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static void RegisterLuaConsoleCommand(const FString& CommandName, const FLuaValue& LuaConsoleCommand);

	UFUNCTION(BlueprintCallable, Category = "Lua")
	static void UnregisterLuaConsoleCommand(const FString& CommandName);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Lua")
	static ULuaState* CreateDynamicLuaState(UObject* WorldContextObject, TSubclassOf<ULuaState> LuaStateClass);

	UFUNCTION(BlueprintCallable,Category="Lua|Table",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "Outcome"))
	static FLuaValue GetLuaFieldValueFromTable(FLuaValue Table, const FString& Field, TEnumAsByte<ELuaValueResult>& Outcome);

	UFUNCTION(BlueprintCallable,Category="Lua|Table",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "Outcome"))
	static FLuaValue GetLuaFieldValueFromObject(UObject* Object, const FString& Field, TEnumAsByte<ELuaValueResult>& Outcome);
	
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Lua")
	static FLuaValue LuaCreateLazyTable(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Lua")
	static FLuaValue LuaCreateUFunction(UObject* InObject, const FString& FunctionName);
	
	// --------------------------------------------------
	// CONVERTORS
	// --------------------------------------------------

	// String
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Lua - -> String", BlueprintAutocast), Category="Lua")
	static FString Conv_LuaValueToString(const FLuaValue& Value,const FString& NilFallback="");
	UFUNCTION(BlueprintPure, meta = (DisplayName = "String -> Lua", BlueprintAutocast), Category="Lua")
	static FLuaValue Conv_StringToLuaValue(const FString& Value);

	// Text
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Text", BlueprintAutocast), Category="Lua")
	static FText Conv_LuaValueToText(const FLuaValue& Value,FText NilFallback=FText());
	UFUNCTION(BlueprintPure, meta = (BDisplayName = "Text -> Lua", lueprintAutocast), Category="Lua")
	static FLuaValue Conv_TextToLuaValue(const FText& Value);

	//Name
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Name", BlueprintAutocast), Category="Lua")
	static FName Conv_LuaValueToName(const FLuaValue& Value,FName NilFallback="");
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Name -> Lua", BlueprintAutocast), Category="Lua")
	static FLuaValue Conv_NameToLuaValue(const FName Value);

	//Object
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Object", BlueprintAutocast), Category="Lua")
	static UObject* Conv_LuaValueToObject(const FLuaValue& Value,UObject* NilFallback=nullptr);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Object -> Lua", BlueprintAutocast), Category="Lua")
	static FLuaValue Conv_ObjectToLuaValue(UObject* Object);

	//Class
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Class", BlueprintAutocast), Category="Lua")
	static UClass* Conv_LuaValueToClass(const FLuaValue& Value);

	//Float
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Float -> Lua", BlueprintAutocast), Category="Lua")
	static FLuaValue Conv_FloatToLuaValue(const float Value);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Float", BlueprintAutocast), Category="Lua")
	static float Conv_LuaValueToFloat(const FLuaValue& Value,float NilFallback=0.0);

	// Int
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Int", BlueprintAutocast), Category="Lua")
	static int32 Conv_LuaValueToInt(const FLuaValue& Value,int32 NilFallback=0);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Int -> Lua", BlueprintAutocast), Category="Lua")
	static FLuaValue Conv_IntToLuaValue(const int32 Value);
	
	//Vector
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua - -> Vector", BlueprintAutocast), Category = "Lua")
	static FVector Conv_LuaValueToFVector(const FLuaValue& Value,FVector NilFallback);
	UFUNCTION()
	static FVector LuaTableToVector(FLuaValue Value);
	
	//Bool
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua -> Bool", BlueprintAutocast), Category="Lua")
	static bool Conv_LuaValueToBool(const FLuaValue& Value,bool NilFallback=false);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Bool -> Lua", BlueprintAutocast), Category="Lua")
	static FLuaValue Conv_BoolToLuaValue(const bool Value);

	// --------------------------------------------------
	// Array
	// --------------------------------------------------
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua -> String [Array]", BlueprintAutocast, Keywords="to, convert"), Category="Lua")
	static TArray<FString> Conv_LuaValueToString_Array(const FLuaValue& Value);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "String -> Lua [Array]", BlueprintAutocast, Keywords="to, convert", WorldContext="WorldContextObject"), Category="Lua")
	static FLuaValue Conv_StringToLuaValue_Array(UObject* WorldContextObject, TArray<FString> Value);

	// --------------------------------------------------
	// Array
	// --------------------------------------------------
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Lua -> Name [Array]", BlueprintAutocast, Keywords="to, convert"), Category="Lua")
	static TArray<FName> Conv_LuaValueToName_Array(const FLuaValue& Value);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Name -> Lua [Array]", BlueprintAutocast, Keywords="to, convert", WorldContext="WorldContextObject"), Category="Lua")
	static FLuaValue Conv_NameToLuaValue_Array(UObject* WorldContextObject, TArray<FName> Value);
	
private:
	static void HttpRequestDone(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, TSubclassOf<ULuaState> LuaState, TWeakObjectPtr<UWorld> World, const FString SecurityHeader, const FString SignaturePublicExponent, const FString SignatureModulus, FLuaHttpSuccess Completed);
	static void HttpGenericRequestDone(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, TWeakPtr<FLuaSmartReference> Context, FLuaHttpResponseReceived ResponseReceived, FLuaHttpError Error);

};

UCLASS()
class LUAMACHINE_API ULuaTableFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Lua|Table",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"))
	static FLuaValue MergeTables(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TArray<FLuaValue> TablesToMerge);
	
	UFUNCTION(BlueprintCallable,Category="Lua|Table",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"))
	static FLuaValue CreateTableFromValues(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TMap<FString,FLuaValue> Values);
	
	UFUNCTION(BlueprintCallable,Category="Lua|Table",meta = (AdvancedDisplay="State,subfield_key", WorldContext = "WorldContextObject"))
	static FLuaValue MergeTablesFromObjects(UObject* WorldContextObject, TSubclassOf<ULuaState> State, TArray<UObject*> Objects, const FString& subfield_key);
};


UCLASS()
class LUAMACHINE_API ULuaValuesFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Globals - Get
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Get LUA Global <🔴Bool>")
	static bool GetLuaGlobal_AsBool(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, bool Fallback=false);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Get LUA Global <🔷Int>")
	static int32 GetLuaGlobal_AsInt(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, int32 Fallback=0);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Get LUA Global <📗Float>")
	static float GetLuaGlobal_AsFloat(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, float Fallback=0.0);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Get LUA Global <🌸String>")
	static FString GetLuaGlobal_AsString(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, const FString& Fallback="");

	// Globals - Set
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Set LUA Global <🔴Bool>")
	static void SetLuaGlobal_AsBool(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, bool Value);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Set LUA Global <🔷Int>")
	static void SetLuaGlobal_AsInt(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Set LUA Global <📗Float>")
	static void SetLuaGlobal_AsFloat(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, float Value);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Set LUA Global <🌸String>")
	static void SetLuaGlobal_AsString(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, const FString& Value);

	// Globals - Add
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Add To LUA Global (🔷Int)")
	static void AddLuaGlobal_AsInt(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State", WorldContext = "WorldContextObject"),DisplayName="Add To LUA Global (📗Float)")
	static void AddLuaGlobal_AsFloat(UObject* WorldContextObject, TSubclassOf<ULuaState> State,  const FString& Global, float Value);
	
	// Globals - Add
	UFUNCTION(BlueprintCallable,Category="Lua|Globals",meta = (AdvancedDisplay="State, bForceCreateTable", WorldContext = "WorldContextObject"))
	static FLuaValue AddValueToLuaGlobalTable(UObject* WorldContextObject, const FString& Global, FLuaValue value, TSubclassOf<ULuaState> State, bool bForceCreateTable);
	
	// Sets
	UFUNCTION(BlueprintCallable, Category="Lua|Table",DisplayName="Lua - Set Table Value (🔴Bool)")
	static FLuaValue LuaTableSetField_Bool(FLuaValue Table, const FString& Key, bool Value);
	UFUNCTION(BlueprintCallable, Category="Lua|Table",DisplayName="Lua - Set Table Value (🔷Int)")
	static FLuaValue LuaTableSetField_Int(FLuaValue Table, const FString& Key, int32 Value);
	UFUNCTION(BlueprintCallable, Category="Lua|Table",DisplayName="Lua - Set Table Value (📗Float)")
	static FLuaValue LuaTableSetField_Float(FLuaValue Table, const FString& Key, float Value);
	UFUNCTION(BlueprintCallable, Category="Lua|Table",DisplayName="Lua - Set Table Value (🌸String)")
	static FLuaValue LuaTableSetField_String(FLuaValue Table, const FString& Key, FString Value);
	UFUNCTION(BlueprintCallable, Category="Lua|Table",DisplayName="Lua - Set Table Value (⚪Object)")
	static FLuaValue LuaTableSetField_Object(FLuaValue Table, const FString& Key, UObject* Value);

	//Value call

	//Gets/Calls this lua value as a bool OR a function with a bool return. If neither, returns "NilReturn".
	UFUNCTION(BlueprintCallable, Category="Lua|ValueCall", meta = (AutoCreateRefTerm = "Args"),DisplayName="Lua - Value Call (🔴Bool)")
	static bool LuaValueCall_Bool(FLuaValue Value, TArray<FLuaValue> Args, bool NilReturn);
	//Gets/Calls this lua value as a int32 OR a function with a int32 return. If neither, returns "NilReturn".
	UFUNCTION(BlueprintCallable, Category="Lua|ValueCall", meta = (AutoCreateRefTerm = "Args"),DisplayName="Lua - Value Call (🔷Int)")
	static int32 LuaValueCall_Int(FLuaValue Value, TArray<FLuaValue> Args, int32 NilReturn);
	//Gets/Calls this lua value as a float OR a function with a float return. If neither, returns "NilReturn".
	UFUNCTION(BlueprintCallable, Category="Lua|ValueCall", meta = (AutoCreateRefTerm = "Args"),DisplayName="Lua - Value Call (📗Float)")
	static float LuaValueCall_Float(FLuaValue Value, TArray<FLuaValue> Args, float NilReturn);
	//Gets/Calls this lua value as a String OR a function with a String return. If neither, returns "NilReturn".
	UFUNCTION(BlueprintCallable, Category="Lua|ValueCall", meta = (AutoCreateRefTerm = "Args"),DisplayName="Lua - Value Call (🌸String)")
	static FString LuaValueCall_String(FLuaValue Value, TArray<FLuaValue> Args, FString NilReturn);
};