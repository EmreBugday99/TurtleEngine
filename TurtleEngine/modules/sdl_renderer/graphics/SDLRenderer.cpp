#include "SDLRenderer.h"

#include <iostream>
#include <SDL_image.h>
#include "SDL_render.h"
#include "SDLWindow.h"


SDL_Texture* texture;
SDL_Rect sR, dR;

SDLRenderer::SDLRenderer(): Renderer(nullptr) {}


void SDLRenderer::Initialize(bool& success, const SDLWindow* window)
{
	success = false;

	Renderer = SDL_CreateRenderer(window->GetWindow(), -1, 0);
	if (Renderer == nullptr)
		return;

	success = true;

	SDL_Surface* tempSurface = IMG_Load("assets/boss.png");
	texture = SDL_CreateTextureFromSurface(Renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
}

void SDLRenderer::Render()
{
	SDL_RenderClear(Renderer);

	dR.h = 64;
	dR.w = 64;

	SDL_RenderCopy(Renderer, texture, nullptr, &dR);

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
