#pragma once
#include "ec/Component.h"

class TestComponent final : public TurtleCore::Component
{
public:
	TestComponent();
	~TestComponent() override;

	API_EXPORT void Initialize() override;
	API_EXPORT void Start() override;
	API_EXPORT void Update() override;
	API_EXPORT void Destroy() override;

};