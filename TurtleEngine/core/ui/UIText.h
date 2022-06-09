#pragma once
#include "../ec/Component.h"
#include "../math/Vector4Int.h"
#include "../math/Vector2Int.h"

struct SDL_Texture;
struct _TTF_Font;
struct SDL_Renderer;

namespace TurtleCore
{
	class TransformComponent;

	class UIText : public Component
	{
	public:
		Vector2Int Position;

	private:
		Vector2Int Size;

		SDL_Texture* FontTexture;
		_TTF_Font* Font;
		Vector4Int Color;
		const char* Text;

		SDL_Renderer* SdlRenderer;
		TransformComponent* Transform;

	public:
		API_EXPORT void Initialize() override;
		API_EXPORT void Start() override;
		API_EXPORT void Update() override;
		API_EXPORT void Destroy() override;

		API_EXPORT void SetFont(const char* fontPath, int size);
		API_EXPORT void SetColor(const Vector4Int& color);
		API_EXPORT void SetText(const char* text);
		API_EXPORT void UpdateText();
	};
}