project "Core"
	filter {}
	location ("build/" .. _ACTION .. "/%{prj.name}")
	language "C++"
	cppdialect "C++17"

	targetdir ("build/".. _ACTION .. "/binaries/" .. outputdirectory .. "/%{prj.name}")
	objdir ("build/" .. _ACTION .. "/intermediate/" .. outputdirectory .. "/%{prj.name}")

	files
	{
		"core/**.h",
		"core/**.hpp",
		"core/**.cpp"
	}

	libdirs {"dependencies/sdl/lib"}
	includedirs 
	{
		"dependencies/sdl/include"
	}

	-- Defines without any filter
	defines "TURTLE_CORE"

	filter "system:windows"
		kind "SharedLib"
		systemversion "latest"
		links {"SDL2", "SDL2main"}
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