#pragma once
#include "graphics/Renderer.h"

struct SDL_Renderer;
class SDLWindow;

class SDLRenderer : TurtleCore::Renderer
{
private:
	SDL_Renderer* Renderer;

public:
	SDLRenderer();

	void Initialize(bool& success, const SDLWindow* window);
	void Render() override;
	void Destroy() override;
	SDL_Renderer* GetRenderer() const;
};
