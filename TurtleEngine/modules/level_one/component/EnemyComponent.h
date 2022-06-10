#pragma once
#include "ec\Component.h"
#include "event\Listener.h"


class LevelModule;
class EnemyComponent final : public TurtleCore::Component
{
private:
	TurtleCore::Listener PlayerActionlistener;
	int movementAxis;

public:
	bool ContinueSpeechRecognition;
	~EnemyComponent() override;

	void Initialize() override;
	void Start() override;
	void Update() override;
	void Destroy() override;

	void OnPlayerAction(const TurtleCore::EventData& data);
};