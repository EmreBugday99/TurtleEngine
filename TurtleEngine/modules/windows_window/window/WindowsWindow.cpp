#include "WindowsWindow.hpp"
#include <iostream>

void WindowsWindow::Initialize(bool& success, const char* title, int width, int height)
{
    RECT rc = { 0, 0, width, height };
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, false);
    ShouldClose = false;

    Width = rc.right - rc.left;
    Height = rc.bottom - rc.top;

    ModuleInstance = GetModuleHandle(nullptr);

    WNDCLASSEX wc = {};
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hInstance = ModuleInstance;
    wc.lpfnWndProc = WindowsProcessCallback;
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"TurtleWindowClass";
    wc.lpszMenuName = NULL;

    WindowClassId = RegisterClassEx(&wc);
    if (WindowClassId != 0)
        success = true;
    else
        success = false;
}

void WindowsWindow::CreateWindowsWindow(bool& success)
{
    WindowHandle = CreateWindowEx(NULL, MAKEINTATOM(WindowClassId), L"Hello World",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        Width, Height,
        NULL, NULL, ModuleInstance, NULL);

    if (WindowHandle == nullptr)
    {
        success = false;
        return;
    }

    ShowWindow(WindowHandle, SW_SHOW);
    success = true;
}

void WindowsWindow::HandleEvents()
{
    MSG msg = {};
    while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
    {
        switch (msg.message)
        {
            case WM_QUIT:
                Stop();
                break;
            case WM_KEYDOWN:
                std::cout << "Event Key Down" << std::endl;
                break;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void WindowsWindow::Render()
{
}

void WindowsWindow::Clear()
{
}

bool WindowsWindow::IsRunning()
{
    return ShouldClose == false;
}

void WindowsWindow::Stop()
{
    ShouldClose = true;
    DestroyWindow(WindowHandle);
    WindowHandle = nullptr;
}

void WindowsWindow::Destroy()
{
}

void* WindowsWindow::GetWindow() const
{
    return nullptr;
}

void* WindowsWindow::GetRenderer()
{
    return nullptr;
}

LRESULT WindowsWindow::WindowsProcessCallback(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(windowHandle, uMsg, wParam, lParam);
}
