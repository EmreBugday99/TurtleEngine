#pragma once
#include "ec/Component.h"
#include <string>
#include <vector>
#include <future>
#include "event/Event.h"

class LevelModule;
class PlayerComponent final : public TurtleCore::Component
{
private:
	std::string RecognizedSpeech;

	LevelModule* Module;
	std::vector<std::future<void>> SpeechFutures;
	std::future<void> RecognitionFuture;

	TurtleCore::Event PlayerActionEvent;
public:
	bool ContinueSpeechRecognition;
	~PlayerComponent() override;

	API_EXPORT void Initialize() override;
	API_EXPORT void Start() override;
	API_EXPORT void Update() override;
	API_EXPORT void Destroy() override;

private:
	static void SpeakText(LevelModule* levelModule, const char* speechText);
	static void RecognizeSpeech(LevelModule* levelModule, PlayerComponent* welcomeComponent);
};