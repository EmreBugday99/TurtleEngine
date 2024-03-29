#pragma once
#include <vector>
#include "../TurtleObject.h"
#include "../event/Listener.h"
#include "Component.h"
#include "../Core.h"
#include <iostream>

namespace TurtleCore
{
	class Entity : TurtleObject
	{
	private:
		friend class Scene;
		friend class ECMemory;

		std::vector<Component*> Components;
		std::vector<Component*> ComponentsToStart;

		Core* Engine;

		Entity(Core* core);
		~Entity() override;

	public:
		API_EXPORT void Initialize() override;
		API_EXPORT void Start() override;
		API_EXPORT void Update() override;

		API_EXPORT Core* GetEngine() const;
		API_EXPORT void Destroy() override;

		template<typename T>
		API_EXPORT void HasComponent(bool& hasComponent) const
		{
			hasComponent = false;

			for (Component* component : Components)
			{
				if (typeid(T) == typeid(component))
				{
					hasComponent = true;
					break;
				}
			}
		}

		template<typename T>
		API_EXPORT T* GetComponent()
		{
			for (Component* iteratedComponent : Components)
			{
				const type_info& typeInfoOne = typeid(*iteratedComponent);
				const type_info& typeInfoTwo = typeid(T);

				if (typeInfoOne == typeInfoTwo)
					return reinterpret_cast<T*>(iteratedComponent);
			}

			return nullptr;
		}

		template<typename T>
		API_EXPORT T& AddComponent()
		{
			T* component = new T();
			component->Owner = this;
			ComponentsToStart.push_back(component);

			component->Initialize();
			return *component;
		}

		template<typename T>
		API_EXPORT void RemoveComponent()
		{
			for (int i = static_cast<int>(Components.size()) - 1; i >= 0; i--)
			{
				const type_info& typeInfoOne = typeid(*Components[i]);
				const type_info& typeInfoTwo = typeid(T);

				if (typeInfoOne != typeInfoTwo)
					continue;

				Components[i]->Destroy();

				bool validScene;
				Scene& activeScene = Engine->SceneManager.GetActiveScene(validScene);
				if (validScene)
					activeScene.GetMemory().MarkObjectForGC(Components[i]);

				Components.erase(Components.begin() + i);
			}
		}
	};
}