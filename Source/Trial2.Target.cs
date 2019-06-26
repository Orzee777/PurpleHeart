

using UnrealBuildTool;
using System.Collections.Generic;

public class Trial2Target : TargetRules
{
	public Trial2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Trial2" } );
	}
}
