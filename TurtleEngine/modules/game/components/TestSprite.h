#pragma once
#include "ec/Component.h"

class GameModule;
class TestSprite final : public TurtleCore::Component
{
public:
	void Initialize() override;
	void Start() override;
	void Update() override;
	void Destroy() override;
};