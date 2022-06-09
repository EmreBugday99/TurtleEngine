#include "SDLWindow.h"
#include <iostream>

#include "Core.h"
#include "SDL.h"
#include "SDLRenderer.h"

SDLWindow::SDLWindow() : Window(nullptr), Running(false)
{
}

void SDLWindow::Initialize(bool& success, const char* title, int width, int height)
{
	success = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return;
	std::cout << "SDL Initialized" << std::endl;

	Window = SDL_CreateWindow(title, 50, 50, width, height, 0);
	if (Window == nullptr)
		return;
	std::cout << "SDL Window Created" << std::endl;

	Renderer.Initialize(success, this);
	if (success == false || Renderer.GetRenderer() == nullptr)
		return;

	std::cout << "SDL Renderer Created" << std::endl;
	SDL_SetRenderDrawColor(static_cast<SDL_Renderer*>(Renderer.GetRenderer()), 0, 0, 0, 255);

	Width = width;
	Height = height;
	Running = true;
	success = true;
}

void SDLWindow::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			Running = false;
			break;
		}
		case SDL_KEYDOWN:
		{
			Core->InputManager.Buffer.KeyDown(event.key.keysym.scancode);
			break;
		}
		case SDL_KEYUP:
		{
			Core->InputManager.Buffer.KeyRelease(event.key.keysym.scancode);
			break;
		}
		default:
			break;
		}
	}
}

void SDLWindow::Render()
{
	Renderer.Render();
}

void SDLWindow::Clear()
{
	Renderer.Clear();
}

bool SDLWindow::IsRunning()
{
	return Running;
}

void SDLWindow::Stop()
{
	Running = false;
}

void SDLWindow::Destroy()
{
	Running = false;
	Renderer.Destroy();

	SDL_DestroyWindow(Window);
	Window = nullptr;
	SDL_Quit();
}

void* SDLWindow::GetWindow() const
{
	return Window;
}

void* SDLWindow::GetRenderer() 
{
	return &Renderer;
}
