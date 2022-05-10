#include "SDLWindow.h"
#include <iostream>
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
	SDL_SetRenderDrawColor(Renderer.GetRenderer(), 0, 0, 0, 255);

	Running = true;
	success = true;
}

void SDLWindow::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
	{
		Running = false;
		break;
	}

	default:
		break;
	}
}

void SDLWindow::Render()
{
	Renderer.Render();
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

SDL_Window* SDLWindow::GetWindow() const
{
	return Window;
}