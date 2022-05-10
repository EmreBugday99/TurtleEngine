#pragma once
#include "../TurtleObject.h"

namespace TurtleCore
{
	class Entity;

	class Component : TurtleObject
	{
	private:
		Entity* Owner;

	protected:
		friend class Entity;

		API_EXPORT Component(Entity* owner);
		API_EXPORT virtual void Initialize() override;
		API_EXPORT virtual void Start() override;
		API_EXPORT virtual void Update() override;
		API_EXPORT virtual void Destroy() override;

		API_EXPORT void GetEntity(const Entity* entity) const;
	};
}