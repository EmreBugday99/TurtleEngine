#pragma once
#include "../TurtleObject.h"

namespace TurtleCore
{
	class Entity;

	class Component : TurtleObject
	{
	public:
		friend class Entity;
		friend class ECMemory;

		Entity* Owner;

		API_EXPORT Component();
		API_EXPORT virtual void Initialize() override;
		API_EXPORT virtual void Start() override;
		API_EXPORT virtual void Update() override;
		API_EXPORT virtual void Destroy() override;

	public:
		API_EXPORT Entity& GetEntity() const;
	};
}