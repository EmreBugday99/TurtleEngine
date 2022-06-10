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
	//if (TTF_Init() != 0)
	//{
	//	std::cout << "Failed to Initialize TTF" << std::endl;
	//	return;
	//}

	//TTF_Font* testFont = TTF_OpenFont("assets/Roboto-Regular.ttf", 16);
	//if (testFont == nullptr)
	//{
	//	std::cout << "It aint working" << std::endl;
	//}

	//SDL_Color fontColor = { 255, 0, 0, 255 };

	//std::string a = "Number: ";
	//SDL_Surface* fontSurface = TTF_RenderUTF8_Solid(testFont, a.c_str(), fontColor);
	//SDL_Rect destRect;
	//destRect.h = 64;
	//destRect.w = 128;
	//destRect.y = 100;

	//SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(Renderer, fontSurface);
	//SDL_RenderCopy(Renderer, fontTexture, nullptr, &destRect);

	//TTF_CloseFont(testFont);
	//SDL_DestroyTexture(fontTexture);
	//SDL_FreeSurface(fontSurface);

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