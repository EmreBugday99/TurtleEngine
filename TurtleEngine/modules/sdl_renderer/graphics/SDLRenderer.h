#pragma once
#include "graphics/Renderer.h"

struct SDL_Renderer;
class SDLWindow;

class SDLRenderer : TurtleCore::Renderer
{
private:
	SDL_Renderer* Renderer;
	SDLWindow* Window;

public:
	SDLRenderer();

	void Initialize(bool& success, SDLWindow* window);
	void Render() override;
	void Clear() override;
	void Destroy() override;
	void* GetRenderer() override;
};
