// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Enums.h"
#include "F_Preferences.generated.h"

class UGamePreference;
class UOmegaSubsystem_World;
class UOmegaSubsystem_GameInstance;

UENUM(BlueprintType)
enum class EGamePreferenceType : uint8
{
	PrefType_Bool		UMETA(DisplayName = "Bool"),
	PrefType_Float		UMETA(DisplayName = "Float"),
	PrefType_Int        UMETA(DisplayName = "Int"),
	PrefType_String		UMETA(DisplayName = "Option"),
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaPreferencePreset : public UOmegaDataAsset
{
	GENERATED_BODY()
	
	public:
	
	void Apply(UObject* WorldContextObject) const;
	
	//The baselevel of scalability applied before any commands or presets. Only Applied if >-1
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Preference Preset",meta=(MultiLine=true)) int32 BaseScalabilityQuality=-1;
	//List of console commands that will be fired when this preset is applied, seperated by line break
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Preference Preset",meta=(MultiLine=true)) FString CommandList;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Preference Preset",meta=(MultiLine=true)) TMap<UGamePreference*,int32> PreferencesPresets;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Preferences : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Get (Bool)")
	static bool Bool_Get(const UObject* WorldContextObject, UGamePreference* Preference);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Set (Bool)")
	static void Bool_Set(const UObject* WorldContextObject, UGamePreference* Preference, bool Value);
	
	UFUNCTION(BlueprintPure, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Get (Int)")
	static int32 Int_Get(const UObject* WorldContextObject, UGamePreference* Preference);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Set (Int)")
	static void Int_Set(const UObject* WorldContextObject, UGamePreference* Preference, int32 Value);
	
	UFUNCTION(BlueprintPure, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Get (Float)")
	static float Float_Get(const UObject* WorldContextObject, UGamePreference* Preference);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Set (Float)")
	static void Float_Set(const UObject* WorldContextObject, UGamePreference* Preference, float Value);	
	
	UFUNCTION(BlueprintPure, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Get (String*)")
	static FString String_Get(const UObject* WorldContextObject, UGamePreference* Preference);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Set (String*)")
	static void String_Set(const UObject* WorldContextObject, UGamePreference* Preference, FString Value);	
	
	UFUNCTION(BlueprintCallable, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs = "Outcome"),DisplayName="🔧Preference - Check (Bool)")
	static bool Check_Bool(const UObject* WorldContextObject, UGamePreference* Preference, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Preference", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome"),DisplayName="🔧Preference - Check (Int)")
	static int32 Check_Int(const UObject* WorldContextObject, UGamePreference* Preference, int32 CheckValue, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome);

	UFUNCTION(BlueprintCallable,Category="Omega|Preference",meta=(WorldContext = "WorldContextObject"),DisplayName="🔧Preference - Apply Preset")
	static void ApplyPreset(const UObject* WorldContextObject, UOmegaPreferencePreset* Preset);

	
};