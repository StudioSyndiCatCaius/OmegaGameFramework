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
			"OmegaCore",
			"OmegaGameFramework",
			"OmegaSequence",
			"PropertyEditor",
			"RenderCore",
			"LuaMachine",
			"OmegaDebug",
			"OmegaDemo",
			"UMGEditor",
			"Slate",
			"SlateCore",
			"LevelEditor",
			"EditorStyle",
			"WorkspaceMenuStructure",
			"ToolMenus",
			"Blutility",
			"EditorFramework",
			"ApplicationCore",
			"ClassViewer",
			"GraphEditor",
			"AdvancedPreviewScene",
			"EditorInteractiveToolsFramework",
		});

		PrivateDependencyModuleNames.AddRange(
	new string[]
	{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"PlacementMode",
				"Projects",
				"PropertyEditor",
				"ToolWidgets",
				"UnrealEd",
				"BlueprintGraph",
				"KismetCompiler",
				"PropertyPath",
				"ContentBrowser",
				"DeveloperSettings",
				"AssetDefinition"
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