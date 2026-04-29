// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "MovieSceneSection.h"
#include "EntitySystem/TrackInstance/MovieSceneTrackInstance.h"
#include "OmegaMovieTrackInstance.generated.h"


USTRUCT(BlueprintType)
struct FOmegaSequencerTrackInstanceInput
{
	GENERATED_BODY()

	FOmegaSequencerTrackInstanceInput()
		: Section(nullptr)
		, Context(FMovieSceneEvaluationRange(0, FFrameRate()))
	{}

	UPROPERTY(Category="Sequencer", BlueprintReadOnly)
	TObjectPtr<UOmegaSequencerSection> Section;

	FMovieSceneContext Context;
};



// ---------------------------------------------------------------------------------------------------------------------
// SECTION
// ---------------------------------------------------------------------------------------------------------------------

UCLASS(Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaSequencerSection
	: public UMovieSceneSection
	, public IMovieSceneEntityProvider
{
public:

	GENERATED_BODY()

	UOmegaSequencerSection(const FObjectInitializer& ObjInit);

private:

	virtual void ImportEntityImpl(UMovieSceneEntitySystemLinker* EntityLinker, const FEntityImportParams& Params, FImportedEntity* OutImportedEntity) override;
};

// ---------------------------------------------------------------------------------------------------------------------
// Track
// ---------------------------------------------------------------------------------------------------------------------

UENUM()
enum class EOmegaSequencerTrackType
{
	OmegaTrack_RootTrack,
	OmegaTrack_ObjectTrack,
};


UCLASS(Blueprintable, Abstract, DisplayName=SequencerTrack)
class OMEGAGAMEFRAMEWORK_API UOmegaSequencerTrack
	: public UMovieSceneNameableTrack
{
public:

	GENERATED_BODY()
	
	UFUNCTION(BlueprintNativeEvent,Category="Sequencer") void OnTrackStart(const FOmegaSequencerTrackInstanceInput& input, UOmegaSequencerTrackInstance* TrackInstance);
	UFUNCTION(BlueprintNativeEvent,Category="Sequencer") void OnTrackUpdate(UOmegaSequencerTrackInstance* TrackInstance);
	UFUNCTION(BlueprintNativeEvent,Category="Sequencer") void OnTrackEnd(const FOmegaSequencerTrackInstanceInput& input, UOmegaSequencerTrackInstance* TrackInstance);
	
	

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	bool bSupportsMultipleRows;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	bool bSupportsBlending;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	EOmegaSequencerTrackType TrackType;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable, meta=(EditCondition="TrackType==EOmegaSequencerTrackType::OmegaTrack_ObjectTrack"))
	TObjectPtr<UClass> SupportedObjectType;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	TSubclassOf<UOmegaSequencerSection> DefaultSectionType;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	TArray<TSubclassOf<UOmegaSequencerSection>> SupportedSections;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	TSubclassOf<UOmegaSequencerTrackInstance> TrackInstanceType;

	UPROPERTY(Category="Sequencer", EditDefaultsOnly, AssetRegistrySearchable)
	FSlateBrush Icon;

public:

	virtual bool SupportsMultipleRows() const override { return bSupportsMultipleRows; }
	virtual EMovieSceneTrackEasingSupportFlags SupportsEasing(FMovieSceneSupportsEasingParams& Params) const override { return bSupportsBlending ? EMovieSceneTrackEasingSupportFlags::All : EMovieSceneTrackEasingSupportFlags::None; }
	virtual bool SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const override { return DefaultSectionType == SectionClass || SupportedSections.Contains(SectionClass); }
	virtual UMovieSceneSection* CreateNewSection() override;

	virtual const TArray<UMovieSceneSection*>& GetAllSections() const override { return Sections; }
	virtual void AddSection(UMovieSceneSection& Section) override { Sections.AddUnique(&Section); }
	virtual void RemoveSection(UMovieSceneSection& Section) override { Sections.Remove(&Section); }
	virtual void RemoveSectionAt(int32 SectionIndex) override { Sections.RemoveAt(SectionIndex); }
	virtual bool HasSection(const UMovieSceneSection& Section) const override { return Sections.Contains(&Section); }
	virtual bool IsEmpty() const override { return Sections.Num() == 0; }

	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
	UE_DEPRECATED(5.4, "Implement the version that takes FAssetRegistryTagsContext instead.")
	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;

private:

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UMovieSceneSection>> Sections;
};


// ---------------------------------------------------------------------------------------------------------------------
// Instance
// ---------------------------------------------------------------------------------------------------------------------


UCLASS(Blueprintable, DisplayName=SequencerTrackInstance)
class OMEGAGAMEFRAMEWORK_API UOmegaSequencerTrackInstance
	: public UMovieSceneTrackInstance
{
public:

	GENERATED_BODY()

	/*~ Implementable interface */
/*
	UFUNCTION(Category="Sequencer", DisplayName="OnInitialize", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnInitialize();

	UFUNCTION(Category="Sequencer", DisplayName="OnUpdate", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnUpdate();

	UFUNCTION(Category="Sequencer", DisplayName="OnBeginUpdateInputs", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnBeginUpdateInputs();

	UFUNCTION(Category="Sequencer", DisplayName="OnInputAdded", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnInputAdded(FOmegaSequencerTrackInstanceInput Input);

	UFUNCTION(Category="Sequencer", DisplayName="OnInputRemoved", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnInputRemoved(FOmegaSequencerTrackInstanceInput Input);

	UFUNCTION(Category="Sequencer", DisplayName="OnEndUpdateInputs", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnEndUpdateInputs();

	UFUNCTION(Category="Sequencer", DisplayName="OnDestroyed", BlueprintImplementableEvent, meta=(CallInEditor=true))
	void K2_OnDestroyed();
*/
	FOmegaSequencerTrackInstanceInput cachedTrack;
	
	bool IsRuntime() const;
	UOmegaSequencerTrack* GetOwningTrack();
	
public:

	UFUNCTION(Category="Sequencer", BlueprintCallable)
	UObject* GetAnimatedObject() const;

	UFUNCTION(Category="Sequencer", BlueprintCallable)
	TArray<FOmegaSequencerTrackInstanceInput> GetInputs() const;

	UFUNCTION(Category="Sequencer", BlueprintCallable)
	int32 GetNumInputs() const;

	UFUNCTION(Category="Sequencer", BlueprintCallable, BlueprintPure=false)
	FOmegaSequencerTrackInstanceInput GetInput(int32 Index) const;

private:
	//init
	virtual void OnInitialize() override;
	//update
	virtual void OnAnimate() override;

	//begin updates
	virtual void OnBeginUpdateInputs() override;

	virtual void OnInputAdded(const FMovieSceneTrackInstanceInput& InInput) override;

	virtual void OnInputRemoved(const FMovieSceneTrackInstanceInput& InInput) override;
	
	//begin end updates
	virtual void OnEndUpdateInputs() override;

	//destroyed
	virtual void OnDestroyed() override;
};



