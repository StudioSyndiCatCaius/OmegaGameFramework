using UnrealBuildTool;
 
public class OmegaInput : ModuleRules
{
	public OmegaInput(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"GameplayTags",
			"InputCore",
			"UMG"
		});
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate", 
			"SlateCore", 
			"UMG", 
			"DeveloperSettings"
		});
		
		PublicIncludePaths.AddRange(new string[] {"OmegaInput/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaInput/Private"});
	}
}