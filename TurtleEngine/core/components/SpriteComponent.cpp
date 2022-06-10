#include "SpriteComponent.h"
#include <SDL_image.h>
#include <SDL_surface.h>
#include "../ec/Component.h"
#include "../ec/Entity.h"
#include "../graphics/Renderer.h"
#include <iostream>

TurtleCore::SpriteComponent::~SpriteComponent()
{
	std::cout << "Sprite deleted" << std::endl;
}

void TurtleCore::SpriteComponent::Initialize()
{
	Texture = nullptr;
	SdlRenderer = nullptr;

	std::cout << "Sprite Initialized" << std::endl;
}

void TurtleCore::SpriteComponent::Start()
{
	Transform = Owner->GetComponent<TransformComponent>();

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
	std::cout << "Sprite Texture Set" << std::endl;

	Renderer* renderer = static_cast<Renderer*>(Owner->GetEngine()->Window->GetRenderer());

	SDL_Surface* textureSurface = IMG_Load(path);
	if (textureSurface == nullptr)
		std::cout << "Failed to load image at " << path << std::endl;
	Texture = SDL_CreateTextureFromSurface(static_cast<SDL_Renderer*>(renderer->GetRenderer()), textureSurface);
	if (Texture == nullptr)
		std::cout << "Failed to create texture from image: " << path << std::endl;

	SDL_FreeSurface(textureSurface);
}