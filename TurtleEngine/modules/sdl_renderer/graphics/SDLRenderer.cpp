#include "SDLRenderer.h"
#include "SDL_render.h"
#include "SDLWindow.h"

SDLRenderer::SDLRenderer(): Renderer(nullptr) {}


void SDLRenderer::Initialize(bool& success, const SDLWindow* window)
{
	success = false;

	Renderer = SDL_CreateRenderer(window->GetWindow(), -1, 0);
	if (Renderer == nullptr)
		return;

	success = true;
}

void SDLRenderer::Render()
{
	SDL_RenderClear(Renderer);

	SDL_RenderPresent(Renderer);
}

void SDLRenderer::Destroy()
{
	// Warning: It seems like SDL is de-allocating the memory for us.
	SDL_DestroyRenderer(Renderer);
	Renderer = nullptr;
}

SDL_Renderer* SDLRenderer::GetRenderer() const
{
	return Renderer;
}
