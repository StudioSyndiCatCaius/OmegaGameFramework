using UnrealBuildTool;
 
public class OmegaAnim : ModuleRules
{
	public OmegaAnim(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PrecompileForTargets = PrecompileTargetsType.Any;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"DeveloperSettings", 
			"GameplayTags",
			"OmegaGameFramework", 
			"SlateCore", 
			"UMG"
		});
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AssetRegistry"
		});
		
		PublicIncludePaths.AddRange(new string[] {"OmegaAnim/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OmegaAnim/Private"});
	}
}