#include "WindowsModuleLoader.h"

#ifdef TURTLE_OS_WINDOWS

#include <filesystem>
#include <iostream>
#include <Windows.h>

unsigned int TurtleEngine::WindowsModuleLoader::GetModuleCount()
{
	namespace fs = std::filesystem;
	unsigned int moduleCount = 0;

	try
	{
		const std::string modulePath = fs::current_path().string() + "\\modules";

		for (auto& file : fs::directory_iterator(modulePath))
		{
			if (file.path().extension() != ".dll")
				continue;

			moduleCount++;
		}
	}
	catch (std::filesystem::filesystem_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return moduleCount;
}

std::vector<std::string> TurtleEngine::WindowsModuleLoader::GetModuleNames()
{
	namespace fs = std::filesystem;
	std::vector<std::string> modules;

	try
	{
		const std::string modulePath = fs::current_path().string() + "\\modules";

		for (auto& file : fs::recursive_directory_iterator(modulePath))
		{
			if (file.path().extension() != ".dll")
				continue;

			std::string moduleFileName = file.path().filename().string();

			modules.push_back(moduleFileName.c_str());
		}

		return modules;
	}
	catch (std::filesystem::filesystem_error& ex)
	{
		std::cout << ex.what() << std::endl;
		return modules;
	}
}

TurtleCore::TurtleModule* TurtleEngine::WindowsModuleLoader::LinkModule(std::string moduleName)
{
	using ModuleFactory = TurtleCore::TurtleModule* (__cdecl*)();

	std::mbstate_t state = { 0 };
	const char* name = moduleName.c_str();
	size_t len = 0;
	wchar_t wtext[50];

	if (mbsrtowcs_s(&len, wtext, 50, &name, 49, &state) != 0)
		return nullptr;

	HINSTANCE hinstLib = LoadLibrary(wtext);
	if (hinstLib == NULL)
	{
		std::cout << "Module Linking Error: Failed to load library -> " << moduleName << std::endl;
		std::cout << GetLastError() << std::endl;
		return nullptr;
	}

	ModuleFactory ProcAdd = (ModuleFactory)GetProcAddress(hinstLib, "?CreateModule@ModuleFactory@@SAPEAVTurtleModule@TurtleCore@@XZ");
	if (ProcAdd == NULL)
	{
		std::cout << "Module Linking Error: Failed to obtain ModuleFactory function ->" << moduleName << std::endl;
		std::cout << GetLastError() << std::endl;
		return nullptr;
	}

	TurtleCore::TurtleModule* newModule = (ProcAdd)();
	return newModule;
}

#endif // TURTLE_OS_WINDOWS