project "LevelTwo"
	filter {}
	location ("../build/" .. _ACTION .. "/modules/%{prj.name}")
	language "C++"
	cppdialect "C++17"

	targetdir ("../build/".. _ACTION .. "/binaries/" .. outputdirectory .. "/modules/%{prj.name}")
	objdir ("../build/" .. _ACTION .. "/intermediate/" .. outputdirectory .. "/modules/%{prj.name}")

	files
	{
		"level_two/**.h",
		"level_two/**.hpp",
		"level_two/**.cpp"
	}

    includedirs
    {
        "../core"
    }

	-- Defines without any filter
	defines "TURTLE_GAME"

	filter "system:windows"
		kind "SharedLib"
		systemversion "latest"
		links {"Core"}
		defines "TURTLE_OS_WINDOWS"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		defines "TURTLE_DEBUG"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		defines "TURTLE_RELEASE"

	filter "kind:SharedLib"
		defines "TURTLE_LIBRARY_SHARED"

	filter "kind:StaticLib"
		defines "TURTLE_LIBRARY_STATIC"