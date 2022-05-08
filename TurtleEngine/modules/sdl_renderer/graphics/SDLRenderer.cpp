#include "SDLRenderer.h"
#include "SDL_render.h"
#include "SDLWindow.h"

SDLRenderer::SDLRenderer(bool& success, SDLWindow* window) : Renderer(nullptr)
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
	SDL_DestroyRenderer(Renderer);
}

SDL_Renderer* SDLRenderer::GetRenderer() const
{
	return Renderer;
}
