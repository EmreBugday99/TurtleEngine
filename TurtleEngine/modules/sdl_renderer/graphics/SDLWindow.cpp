#include "SDLWindow.h"

#include <iostream>

#include "SDL.h"
#include "SDLRenderer.h"

SDLWindow::SDLWindow() : Window(nullptr), Renderer(nullptr), IsRunning(false) {}

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

	bool rendererSuccess;
	Renderer = new SDLRenderer(rendererSuccess, this);
	if (rendererSuccess == false)
	{
		delete Renderer;
		return;
	}

	std::cout << "SDL Renderer Created" << std::endl;
	SDL_SetRenderDrawColor(Renderer->GetRenderer(), 255, 255, 255, 255);

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
	SDL_DestroyWindow(Window);
	Renderer->Destroy();

	delete Renderer;
	SDL_Quit();
}

SDL_Window* SDLWindow::GetWindow() const
{
	return Window;
}
