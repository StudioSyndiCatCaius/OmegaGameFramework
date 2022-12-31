using UnrealBuildTool;
 
public class OmegaUI : ModuleRules
{
	public OmegaUI(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "UMG", "OmegaGameFramework"});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
		);
 
		PublicIncludePaths.AddRange(new string[] {"OmegaUI/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaUI/Private"});
	}
}