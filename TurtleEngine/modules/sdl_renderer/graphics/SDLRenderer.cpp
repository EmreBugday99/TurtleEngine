#include "SDLRenderer.h"
#include <SDL_ttf.h>
#include "SDL_render.h"
#include "SDLWindow.h"
#include "SDL_image.h"

SDLRenderer::SDLRenderer() : Renderer(nullptr), Window(nullptr) {}

void SDLRenderer::Initialize(bool& success, SDLWindow* window)
{
	success = false;
	IMG_Init(IMG_INIT_PNG);

	Renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(window->GetWindow()), -1, 0);
	if (Renderer == nullptr)
		return;

	Window = window;
	success = true;
}

void SDLRenderer::Render()
{
	SDL_RenderPresent(Renderer);
}

void SDLRenderer::Clear()
{
	SDL_RenderClear(Renderer);
}

void SDLRenderer::Destroy()
{
	// Warning: It seems like SDL is de-allocating the memory for us.
	SDL_DestroyRenderer(Renderer);
	Renderer = nullptr;
}

void* SDLRenderer::GetRenderer()
{
	return Renderer;
}