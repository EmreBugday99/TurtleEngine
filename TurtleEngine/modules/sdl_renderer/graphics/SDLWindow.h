#pragma once

#include "SDLRenderer.h"
#include "graphics/Window.h"

struct SDL_Window;

class SDLWindow : TurtleCore::Window
{
private:
	SDL_Window* Window;
	SDLRenderer Renderer;
	bool IsRunning;

public:
	SDLWindow();

	void Initialize(bool& success, const char* title, int width, int height) override;
	void HandleEvents() override;
	void Destroy() override;
	SDL_Window* GetWindow() const;
};
