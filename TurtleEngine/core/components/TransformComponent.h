#pragma once
#include "../ec/Component.h"
#include "../math/Vector2Int.h"

namespace TurtleCore
{
	class TransformComponent final : public Component
	{
	public:
		Vector2Int Position;
		Vector2Int Size;

		API_EXPORT void Initialize() override;
		API_EXPORT void Start() override;
		API_EXPORT void Update() override;
		API_EXPORT void Destroy() override;
	};
}