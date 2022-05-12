#pragma once

#include "SDLRenderer.h"
#include "graphics/Window.h"

namespace TurtleCore
{
	class Core;
}

struct SDL_Window;

class SDLWindow : TurtleCore::Window
{
private:
	friend class RendererModule;

	SDL_Window* Window;
	SDLRenderer Renderer;
	bool Running;
	TurtleCore::Core* Core;

public:
	SDLWindow();

	void Initialize(bool& success, const char* title, int width, int height) override;
	void HandleEvents() override;
	void Render() override;
	void Clear() override;
	bool IsRunning() override;
	void Stop() override;
	void Destroy() override;
	void* GetWindow() const override;
	void* GetRenderer()  override;
};
