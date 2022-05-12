#include "SpriteComponent.h"
#include <SDL_image.h>
#include <SDL_surface.h>
#include "../ec/Component.h"
#include "../ec/Entity.h"
#include "../graphics/Renderer.h"
#include <iostream>

void TurtleCore::SpriteComponent::Initialize()
{
	Texture = nullptr;
	SdlRenderer = nullptr;
}

void TurtleCore::SpriteComponent::Start()
{
	Transform = Owner->GetComponent<TransformComponent>();
	Transform->Position.Set(0);
	Transform->Size.Set(32);

	Renderer* renderer = static_cast<Renderer*>(Owner->GetEngine()->Window->GetRenderer());
	SdlRenderer = static_cast<SDL_Renderer*>(renderer->GetRenderer());

	if (SdlRenderer == nullptr)
		std::cout << "SdlRenderer Null" << std::endl;

	if (renderer == nullptr)
		std::cout << "renderer Null" << std::endl;
}

void TurtleCore::SpriteComponent::Update()
{
	if (Texture == nullptr)
	{
		std::cout << "Texture Null" << std::endl;
		return;
	}

	SDL_Rect destinationRect;
	destinationRect.x = Transform->Position.X;
	destinationRect.y = Transform->Position.Y;
	destinationRect.w = Transform->Size.X;
	destinationRect.h = Transform->Size.Y;

	SDL_RenderCopy(SdlRenderer, Texture, nullptr, &destinationRect);
}

void TurtleCore::SpriteComponent::Destroy()
{
}

void TurtleCore::SpriteComponent::SetTexture(const char* path)
{
	Renderer* renderer = static_cast<Renderer*>(Owner->GetEngine()->Window->GetRenderer());

	SDL_Surface* textureSurface = IMG_Load(path);
	Texture = SDL_CreateTextureFromSurface(static_cast<SDL_Renderer*>(renderer->GetRenderer()), textureSurface);

	SDL_FreeSurface(textureSurface);
}