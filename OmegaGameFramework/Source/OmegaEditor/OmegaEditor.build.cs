using UnrealBuildTool;
 
public class OmegaEditor : ModuleRules
{
	public OmegaEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine",
			"AssetTools",
			"UnrealEd",
			"InputCore",
			"OmegaGameFramework", 
			"OmegaData",
			"OmegaDemo",
			"UMGEditor"
		});

		PrivateDependencyModuleNames.AddRange(
	new string[]
	{
				"CoreUObject",
				"Engine",
				"EditorStyle",
				"Slate",
				"SlateCore",
				"PlacementMode",
				"Projects",
				"UnrealEd",
				"BlueprintGraph",
				"KismetCompiler",
				"PropertyPath",
				"ContentBrowser",
				"AssetTools"
		// ... add private dependencies that you statically link with here ...	
	}
	);

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public dependencies that you statically link with here ...	
				
			}
			);
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add private dependencies that you statically link with here ...	
			
			})
			;
	}
}