#pragma once
#include "ec/Component.h"

class TestComponent final : TurtleCore::Component
{
public:
	TestComponent(TurtleCore::Entity* entity);
	~TestComponent() override;

protected:
	API_EXPORT void Initialize() override;
	API_EXPORT void Start() override;
	API_EXPORT void Update() override;
	API_EXPORT void Destroy() override;

};