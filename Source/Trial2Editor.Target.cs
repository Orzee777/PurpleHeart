

using UnrealBuildTool;
using System.Collections.Generic;

public class Trial2EditorTarget : TargetRules
{
	public Trial2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Trial2" } );
	}
}
