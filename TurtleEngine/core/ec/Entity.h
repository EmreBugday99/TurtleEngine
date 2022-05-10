#pragma once
#include <vector>
#include "../TurtleObject.h"
#include "../event/Listener.h"
#include "Component.h"
#include "../Core.h"

namespace TurtleCore
{
	class Entity : TurtleObject
	{
	private:
		friend class Core;

		std::vector<Component*> Components;
		Core* Engine;

		Entity(Core* core);
		~Entity() override;

	protected:
		API_EXPORT void Initialize() override;
		API_EXPORT void Start() override;
		API_EXPORT void Update() override;
		API_EXPORT void Destroy() override;

	public:
		template<typename T>
		API_EXPORT void HasComponent(bool& hasComponent) const
		{
			hasComponent = false;

			for (Component* component : Components)
			{
				if (typeid(T) == typeid(component))
				{
					hasComponent = true;
					return;
				}
			}
		}

		template<typename T>
		API_EXPORT void GetComponent(T* component)
		{
			component = nullptr;
			for (Component* iteratedComponent : Components)
			{
				if (typeid(iteratedComponent) == typeid(T))
				{
					component = iteratedComponent;
					return;
				}
			}
		}

		template<typename T>
		API_EXPORT T& AddComponent()
		{
			T* component = new T(this);
			Components.push_back(reinterpret_cast<Component*>(component));

			return *component;
		}

		template<typename T>
		API_EXPORT void RemoveComponent()
		{
			for (int i = static_cast<int>(Components.size()) - 1; i >= 0; i--)
			{
				if (typeid(Components[i]) != typeid(T))
					continue;

				Components.erase(Components.begin() + i);
				Components[i]->Destroy();
				Engine->GetMemory().MarkObjectForGC(reinterpret_cast<TurtleObject*>(Components[i]));
			}
		}
	};
}