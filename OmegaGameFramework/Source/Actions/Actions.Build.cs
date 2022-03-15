// Copyright 2015-2020 Piperift. All Rights Reserved.

using UnrealBuildTool;

public class Actions : ModuleRules
{
	public Actions(ReadOnlyTargetRules TargetRules) : base(TargetRules)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayTags",
			"GameplayTasks",
			"AIModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[]{});


		if (TargetRules.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.AddRange( new string[]	{
				"SlateCore",
				"Slate"
			});
		}

		if (TargetRules.bBuildDeveloperTools || (Target.Configuration != UnrealTargetConfiguration.Shipping && Target.Configuration != UnrealTargetConfiguration.Test))
		{
			PrivateDependencyModuleNames.Add("GameplayDebugger");
			PublicDefinitions.Add("WITH_GAMEPLAY_DEBUGGER=1");
		}
		else
		{
			PublicDefinitions.Add("WITH_GAMEPLAY_DEBUGGER=0");
		}
	}
}
