// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Misc/GeneralDataObject.h"
#include "DA_BGM.generated.h"

class USoundWave;

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBgmSoundData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BGM") USoundWave* SoundWave=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BGM") float Loop_BeginTime=0.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BGM") float Loop_EndTime=0.0f;
};

UCLASS(EditInlineNew,Blueprintable,BlueprintType,Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaBGMScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Bgm Script")
	FOmegaBgmSoundData GetBgmSoundData(UGameInstance* GameInstance, UOmegaBGM* BGM, const FString& style) const;
	
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBGM : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	UOmegaBGM();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio",meta=(ExposeOnSpawn))
	USoundWave* Sound;

	//The point in the Sound Wav where the bgm will begin when the loop ends
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BGM",meta=(ExposeOnSpawn))
	float LoopBeginTime;
	//The point in the Sound Wav where the bgm where it will restart the loop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BGM",meta=(ExposeOnSpawn))
	float LoopEndTime=-1;
	
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="BGM",meta=(ExposeOnSpawn))
	UOmegaBGMScript* BgmScript;

};