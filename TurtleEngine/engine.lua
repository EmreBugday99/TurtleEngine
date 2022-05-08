project "Engine"
	filter {}
	location ("build/" .. _ACTION .. "/%{prj.name}")
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("build/".. _ACTION .. "/binaries/" .. outputdirectory .. "/%{prj.name}")
	objdir ("build/" .. _ACTION .. "/intermediate/" .. outputdirectory .. "/%{prj.name}")

	files
	{
		"engine/**.h",
		"engine/**.hpp",
		"engine/**.cpp",
	}

	includedirs 
	{
        "core"
	}

	-- Defines without any filter
	defines {"TURTLE_RUNTIME"}

	filter "system:windows"
		systemversion "latest"
		staticruntime "on"
		defines {"TURTLE_OS_WINDOWS"}
		links {"Core"}

	filter "configurations:Debug"
		runtime "Debug"
		defines {"TURTLE_DEBUG"}
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		defines {"TURTLE_RELEASE"}
		optimize "on"