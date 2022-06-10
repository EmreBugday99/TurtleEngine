#pragma once
#include "TransformComponent.h"
#include "../ec/Component.h"
#include "../API.h"

struct SDL_Texture;
struct SDL_Renderer;

namespace TurtleCore
{
	class SpriteComponent final : public Component
	{
	private:
		SDL_Texture* Texture;
		SDL_Renderer* SdlRenderer;
		TransformComponent* Transform;

	public:
		API_EXPORT ~SpriteComponent() override;
		API_EXPORT void Initialize() override;
		API_EXPORT void Start() override;
		API_EXPORT void Update() override;
		API_EXPORT void Destroy() override;

		API_EXPORT void SetTexture(const char* path);
	};
}