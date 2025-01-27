project "WindowsWindow"
	filter {}
	location ("../build/" .. _ACTION .. "/modules/%{prj.name}")
	language "C++"
	cppdialect "C++17"

	targetdir ("../build/".. _ACTION .. "/binaries/" .. outputdirectory .. "/modules/%{prj.name}")
	objdir ("../build/" .. _ACTION .. "/intermediate/" .. outputdirectory .. "/modules/%{prj.name}")

	files
	{
		"windows_window/**.h",
		"windows_window/**.hpp",
		"windows_window/**.cpp"
	}

    includedirs
    {
        "../core"
    }

	-- Defines without any filter
	defines "TURTLE_WINDOWS_WINDOW"

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