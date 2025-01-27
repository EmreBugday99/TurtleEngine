#include "graphics/Window.h"
#include <Windows.h>

class WindowsWindow : TurtleCore::Window
{
private:
	HWND WindowHandle;
	ATOM WindowClassId;
	HINSTANCE ModuleInstance;
	bool ShouldClose;

public:
	void Initialize(bool& success, const char* title, int width, int height) override;
	void CreateWindowsWindow(bool& success);
	void HandleEvents() override;
	void Render() override;
	void Clear() override;
	bool IsRunning() override;
	void Stop() override;
	void Destroy() override;
	void* GetWindow() const override;
	void* GetRenderer() override;

	static LRESULT CALLBACK WindowsProcessCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};