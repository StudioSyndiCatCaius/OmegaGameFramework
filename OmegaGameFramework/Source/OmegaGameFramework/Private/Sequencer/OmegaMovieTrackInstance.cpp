// Fill out your copyright notice in the Description page of Project Settings.


#include "Sequencer/OmegaMovieTrackInstance.h"

#include "EntitySystem/BuiltInComponentTypes.h"
#include "UObject/AssetRegistryTagsContext.h"


UOmegaSequencerSection::UOmegaSequencerSection(const FObjectInitializer& ObjInit)
	: Super(ObjInit)
{
	// This section must be public as the object animator system needs to reference it and it lives in a different package.
	// Without this flag, object reinstancing will clear out the pointer to the section with FArchiveReplaceOrClearExternalReferences
	SetFlags(RF_Public);
}


void UOmegaSequencerSection::ImportEntityImpl(UMovieSceneEntitySystemLinker* EntityLinker, const FEntityImportParams& Params, FImportedEntity* OutImportedEntity)
{
	using namespace UE::MovieScene;

	UOmegaSequencerTrack* CustomTrack = GetTypedOuter<UOmegaSequencerTrack>();
	if (CustomTrack->TrackInstanceType.Get())
	{
		FBuiltInComponentTypes* BuiltInComponents = FBuiltInComponentTypes::Get();

		FGuid ObjectBindingID = Params.GetObjectBindingID();
		OutImportedEntity->AddBuilder(
			FEntityBuilder()
			.Add(BuiltInComponents->TrackInstance, FMovieSceneTrackInstanceComponent{ decltype(FMovieSceneTrackInstanceComponent::Owner)(this), CustomTrack->TrackInstanceType })
			.AddConditional(BuiltInComponents->GenericObjectBinding, ObjectBindingID, ObjectBindingID.IsValid())
			.AddTagConditional(BuiltInComponents->Tags.Root, !ObjectBindingID.IsValid())
		);
	}
}

void UOmegaSequencerTrack::OnTrackEnd_Implementation(const FOmegaSequencerTrackInstanceInput& input, UOmegaSequencerTrackInstance* TrackInstance)
{
}

void UOmegaSequencerTrack::OnTrackUpdate_Implementation(UOmegaSequencerTrackInstance* TrackInstance)
{
}

void UOmegaSequencerTrack::OnTrackStart_Implementation(const FOmegaSequencerTrackInstanceInput& input, UOmegaSequencerTrackInstance* TrackInstance)
{
}


UMovieSceneSection* UOmegaSequencerTrack::CreateNewSection()
{
	if (UClass* Class = DefaultSectionType.Get())
	{
		return NewObject<UOmegaSequencerSection>(this, Class, NAME_None, RF_Transactional);
	}

	for (TSubclassOf<UOmegaSequencerSection> SupportedSection : SupportedSections)
	{
		if (UClass* Class = SupportedSection.Get())
		{
			return NewObject<UOmegaSequencerSection>(this, Class, NAME_None, RF_Transactional);
		}
	}

	ensureMsgf(false, TEXT("Track does not have any supported section types. Returning a base class to avoid crashing."));
	return NewObject<UMovieSceneSection>(this, NAME_None, RF_Transactional);
}

void UOmegaSequencerTrack::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
	PRAGMA_DISABLE_DEPRECATION_WARNINGS;
	Super::GetAssetRegistryTags(OutTags);
	PRAGMA_ENABLE_DEPRECATION_WARNINGS;
}

void UOmegaSequencerTrack::GetAssetRegistryTags(FAssetRegistryTagsContext Context) const
{
	Super::GetAssetRegistryTags(Context);
}


bool UOmegaSequencerTrackInstance::IsRuntime() const
{
	if (GetWorld())
	{
		if (GetWorld()->GetGameInstance())
		{
			return true;
		}
	}
	return false;
}

UOmegaSequencerTrack* UOmegaSequencerTrackInstance::GetOwningTrack()
{
	if (cachedTrack.Section.Get())
	{
		if (UOmegaSequencerTrack* t=Cast<UOmegaSequencerTrack>(cachedTrack.Section.Get()->GetOuter()))
		{
			return t;
		}
	}
	return nullptr;
}

UObject* UOmegaSequencerTrackInstance::GetAnimatedObject() const
{
	return Super::GetAnimatedObject();
}

TArray<FOmegaSequencerTrackInstanceInput> UOmegaSequencerTrackInstance::GetInputs() const
{
	using namespace UE::MovieScene;

	TArray<FOmegaSequencerTrackInstanceInput> Result;

	TArrayView<const FMovieSceneTrackInstanceInput> InputsView = Super::GetInputs();
	Result.Reserve(InputsView.Num());

	for (const FMovieSceneTrackInstanceInput& Input : InputsView)
	{
		FOmegaSequencerTrackInstanceInput ThisInput;
		ThisInput.Section = CastChecked<UOmegaSequencerSection>(Input.Section);

		const FInstanceRegistry* InstanceRegistry = GetLinker()->GetInstanceRegistry();
		if (ensure(InstanceRegistry->IsHandleValid(Input.InstanceHandle)))
		{
			ThisInput.Context = InstanceRegistry->GetInstance(Input.InstanceHandle).GetContext();
		}

		Result.Add(ThisInput);
	}

	return Result;
}

int32 UOmegaSequencerTrackInstance::GetNumInputs() const
{
	return GetInputs().Num();
}


FOmegaSequencerTrackInstanceInput UOmegaSequencerTrackInstance::GetInput(int32 Index) const
{
	using namespace UE::MovieScene;

	TArrayView<const FMovieSceneTrackInstanceInput> InputsView = Super::GetInputs();
	if (!InputsView.IsValidIndex(Index))
	{
		FFrame::KismetExecutionMessage(*FString::Printf(TEXT("Attempting to acces input %d from an array of size %d."), Index, InputsView.Num()), ELogVerbosity::Error);
		return FOmegaSequencerTrackInstanceInput();
	}

	FMovieSceneTrackInstanceInput Input = InputsView[Index];

	FOmegaSequencerTrackInstanceInput Result;
	Result.Section = CastChecked<UOmegaSequencerSection>(Input.Section);

	const FInstanceRegistry* InstanceRegistry = GetLinker()->GetInstanceRegistry();
	if (ensure(InstanceRegistry->IsHandleValid(Input.InstanceHandle)))
	{
		Result.Context = InstanceRegistry->GetInstance(Input.InstanceHandle).GetContext();
	}

	return Result;
}

void UOmegaSequencerTrackInstance::OnInitialize()
{
}

void UOmegaSequencerTrackInstance::OnAnimate()
{
	if (IsRuntime())
	{
		if (UOmegaSequencerTrack* t=GetOwningTrack())
		{
			t->OnTrackUpdate(this);
		}
	}
}

void UOmegaSequencerTrackInstance::OnBeginUpdateInputs()
{
}

void UOmegaSequencerTrackInstance::OnInputAdded(const FMovieSceneTrackInstanceInput& InInput)
{
	using namespace UE::MovieScene;

	FOmegaSequencerTrackInstanceInput Result;
	Result.Section = CastChecked<UOmegaSequencerSection>(InInput.Section);
	cachedTrack=Result;
	const FInstanceRegistry* InstanceRegistry = GetLinker()->GetInstanceRegistry();
	if (ensure(InstanceRegistry->IsHandleValid(InInput.InstanceHandle)))
	{
		Result.Context = InstanceRegistry->GetInstance(InInput.InstanceHandle).GetContext();
	}
	
	if (IsRuntime())
	{
		if (UOmegaSequencerTrack* t=GetOwningTrack())
		{
			t->OnTrackStart(Result,this);
		}
	}
	
	//K2_OnInputAdded(Result);
}

void UOmegaSequencerTrackInstance::OnInputRemoved(const FMovieSceneTrackInstanceInput& InInput)
{
	using namespace UE::MovieScene;

	FOmegaSequencerTrackInstanceInput Result;
	Result.Section = CastChecked<UOmegaSequencerSection>(InInput.Section);

	const FInstanceRegistry* InstanceRegistry = GetLinker()->GetInstanceRegistry();
	if (ensure(InstanceRegistry->IsHandleValid(InInput.InstanceHandle)))
	{
		Result.Context = InstanceRegistry->GetInstance(InInput.InstanceHandle).GetContext();
	}
	
	
	//K2_OnInputRemoved(Result);
}

void UOmegaSequencerTrackInstance::OnEndUpdateInputs()
{
}


void UOmegaSequencerTrackInstance::OnDestroyed()
{
	using namespace UE::MovieScene;

	TArrayView<const FMovieSceneTrackInstanceInput> InputsView = Super::GetInputs();
	for (const FMovieSceneTrackInstanceInput& Input : InputsView)
	{
		FOmegaSequencerTrackInstanceInput ThisInput;
		ThisInput.Section = CastChecked<UOmegaSequencerSection>(Input.Section);

		const FInstanceRegistry* InstanceRegistry = GetLinker()->GetInstanceRegistry();
		if (ensure(InstanceRegistry->IsHandleValid(Input.InstanceHandle)))
		{
			ThisInput.Context = InstanceRegistry->GetInstance(Input.InstanceHandle).GetContext();
		}
		
		if (IsRuntime())
		{
			if (UOmegaSequencerTrack* t=GetOwningTrack())
			{
				t->OnTrackEnd(ThisInput,this);
			}
		}
		//K2_OnInputRemoved(ThisInput);
	}
	
	//K2_OnDestroyed();
}

