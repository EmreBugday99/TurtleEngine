#include "SDLWindow.h"
#include <iostream>
#include "SDL.h"
#include "SDLRenderer.h"

SDLWindow::SDLWindow() : Window(nullptr), IsRunning(false)
{
}

void SDLWindow::Initialize(bool& success, const char* title, int width, int height)
{
	success = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return;
	std::cout << "SDL Initialized" << std::endl;

	Window = SDL_CreateWindow(title, 0, 0, width, height, 0);
	if (Window == nullptr)
		return;
	std::cout << "SDL Window Created" << std::endl;

	std::cout << "SDL Renderer Created" << std::endl;
	SDL_SetRenderDrawColor(Renderer.GetRenderer(), 255, 255, 255, 255);

	IsRunning = true;
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
		IsRunning = false;
		break;
	}

	default:
		break;
	}
}

void SDLWindow::Destroy()
{
	IsRunning = false;
	Renderer.Destroy();

	SDL_DestroyWindow(Window);
	Window = nullptr;
	SDL_Quit();
}

SDL_Window* SDLWindow::GetWindow() const
{
	return Window;
}