#include "UIText.h"
#include <iostream>
#include <SDL_ttf.h>
#include "../ec/Component.h"
#include "../ec/Entity.h"
#include "../components/TransformComponent.h"
#include "../graphics/Renderer.h"

void TurtleCore::UIText::Initialize()
{
	FontTexture = nullptr;
	Font = nullptr;
	Color = { 255, 255, 255 ,255 };
	Transform = nullptr;
	Text = "Text";
	SdlRenderer = nullptr;
}

void TurtleCore::UIText::Start()
{
	Transform = Owner->GetComponent<TransformComponent>();
	if (Transform == nullptr)
		std::cout << "UI Text Needs Transform Component To Function Properly" << std::endl;

	Renderer* renderer = static_cast<Renderer*>(Owner->GetEngine()->Window->GetRenderer());
	SdlRenderer = static_cast<SDL_Renderer*>(renderer->GetRenderer());
}

void TurtleCore::UIText::Update()
{
	if (FontTexture == nullptr)
	{
		std::cout << "Null UI" << std::endl;
		return;
	}

	SDL_Rect destinationRect;
	if (Transform != nullptr)
		destinationRect = { Transform->Position.X, Transform->Position.Y, Transform->Size.X, Transform->Size.Y };
	else
		destinationRect = { 0, 0, 64, 128 };

	SDL_RenderCopy(SdlRenderer, FontTexture, nullptr, &destinationRect);
}

void TurtleCore::UIText::Destroy()
{
	TTF_CloseFont(Font);
	SDL_DestroyTexture(FontTexture);

	Font = nullptr;
	FontTexture = nullptr;
}

void TurtleCore::UIText::SetFont(const char* fontPath, int size)
{
	if (Font != nullptr)
	{
		TTF_CloseFont(Font);
		Font = nullptr;
	}

	Font = TTF_OpenFont(fontPath, size);
	if (Font == nullptr)
		std::cout << "Failed to open Font at " << fontPath << std::endl;
}

void TurtleCore::UIText::SetColor(const Vector4Int& color)
{
	Color = { static_cast<uint8_t>(color.X), static_cast<uint8_t>(color.Y), static_cast<uint8_t>(color.Z), static_cast<uint8_t>(color.W) };
}

void TurtleCore::UIText::SetText(const char* text)
{
	Text = text;
}

void TurtleCore::UIText::UpdateText()
{
	if (FontTexture != nullptr)
	{
		SDL_DestroyTexture(FontTexture);
		FontTexture = nullptr;
	}

	Renderer* renderer = static_cast<Renderer*>(Owner->GetEngine()->Window->GetRenderer());
	SdlRenderer = static_cast<SDL_Renderer*>(renderer->GetRenderer());

	const SDL_Color color = { static_cast<uint8_t>(Color.X), static_cast<uint8_t>(Color.Y), static_cast<uint8_t>(Color.Z), static_cast<uint8_t>(Color.W) };

	SDL_Surface* fontSurface = TTF_RenderUTF8_Solid(Font, Text, color);
	if (fontSurface == nullptr)
	{
		std::cout << "Failed to create Surface for the UI Text" << std::endl;
		SDL_FreeSurface(fontSurface);
		return;
	}

	FontTexture = SDL_CreateTextureFromSurface(SdlRenderer, fontSurface);
	if (FontTexture == nullptr)
	{
		std::cout << "Failed to create Texture for the UI Text" << std::endl;
		SDL_FreeSurface(fontSurface);
		return;
	}
}