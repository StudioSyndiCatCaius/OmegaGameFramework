// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_ActorWeb.h"

AOmegaWebActor::AOmegaWebActor()
{
}

TArray<AOmegaWebActor*> FOmegaActorWeb_Cache::GetActors()
{
	TArray<AOmegaWebActor*> out;
	for (FOmegaActorLink L : links)
	{
		if (!out.Contains(L.A) && !out.Contains(L.B))
		{
			out.AddUnique(Cast<AOmegaWebActor>(L.A));
			out.AddUnique(Cast<AOmegaWebActor>(L.B));
		}
	}
	return out;
}

FVector2D FOmegaActorWeb_Cache::GetLinePointFromActor(AOmegaWebActor* actor)
{
	if (actor)
	{
		FVector2D point;
		point.X=actor->GetActorLocation().X;
		point.Y=actor->GetActorLocation().Y;
		return point;
	}
	return FVector2D();
}

bool UOmegaFunctions_ActorWeb::CacheHasLink(FOmegaActorWeb_Cache cache, AOmegaWebActor* a, AOmegaWebActor* b)
{
	if (a && b)
	{
		for (FOmegaActorLink link: cache.links)
		{
			if (link.Has(a) && link.Has(b))
			{
				return true;
			}
		}
	}
	return false;
}

FOmegaActorWeb_Cache UOmegaFunctions_ActorWeb::CreateCache(TArray<AOmegaWebActor*> actors)
{
	FOmegaActorWeb_Cache out;
	
	for (auto a : actors)
	{
		if (a)
		{
			for (auto a2 : a->Connections)
			{
				if (a2)
				{
					if (!CacheHasLink(out,a,a2))
					{
						FOmegaActorLink _newLink;
						_newLink.A=a; _newLink.B=a2;
						out.links.Add(_newLink);
					}
				}
			}
		}
	}
	return out;
}

TArray<FOmegaLine> UOmegaFunctions_ActorWeb::GetLines(FOmegaActorWeb_Cache cache)
{
	TArray<FOmegaLine> out;
	for (FOmegaActorLink link : cache.links)
	{
		FOmegaLine _newLine;
		_newLine.Start=FOmegaActorWeb_Cache::GetLinePointFromActor(Cast<AOmegaWebActor>(link.A));
		_newLine.End=FOmegaActorWeb_Cache::GetLinePointFromActor(Cast<AOmegaWebActor>(link.B));
		out.Add(_newLine);
	}
	return out;
}

