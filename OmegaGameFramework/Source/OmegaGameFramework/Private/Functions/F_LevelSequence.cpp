// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_LevelSequence.h"

#include "LevelSequence.h"
#include "MovieScene.h"


FMovieSceneMarkedFrame UOmegaLevelSequenceFunctions::DoesSequenceHaveMark(ULevelSequence* Sequence, const FString& Mark, bool& result)
{
	if(Sequence)
	{
		for(FMovieSceneMarkedFrame _mark : Sequence->GetMovieScene()->GetMarkedFrames())
		{
			if(_mark.Label==Mark)
			{
				result=true;
				return _mark;
			}
		}
	}
	result=false;
	return FMovieSceneMarkedFrame();
}

float UOmegaLevelSequenceFunctions::GetMarkedFrameTime(ULevelSequence* Sequence, const FString& Mark, float StartTime)
{
	if (Sequence)
	{
		UMovieScene* MovieScene = Sequence->GetMovieScene();
		for (const FMovieSceneMarkedFrame& MarkedFrame : MovieScene->GetMarkedFrames())
		{
			if (MarkedFrame.Label == Mark)
			{
				const FFrameRate TickResolution = MovieScene->GetTickResolution();
				return static_cast<float>(TickResolution.AsSeconds(MarkedFrame.FrameNumber)) - StartTime;
			}
		}
	}
	return 0.0f;
}
