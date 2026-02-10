// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_LevelSequence.h"

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
