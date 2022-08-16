#pragma once
#include "ec/Component.h"

class GameModule;
class TestText final : public TurtleCore::Component
{
public:
	void Initialize() override;
	void Start() override;
	void Update() override;
	void Destroy() override;
};