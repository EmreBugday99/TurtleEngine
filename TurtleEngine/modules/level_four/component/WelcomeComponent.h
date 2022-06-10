#pragma once
#include "ec/Component.h"
#include <string>
#include <vector>
#include <future>

class LevelModule;
class WelcomeComponent final : public TurtleCore::Component
{
private:
	std::string RecognizedSpeech;

	LevelModule* Module;
	std::vector<std::future<void>> SpeechFutures;
	std::future<void> RecognitionFuture;

public:
	bool ContinueSpeechRecognition;
	~WelcomeComponent() override;

	API_EXPORT void Initialize() override;
	API_EXPORT void Start() override;
	API_EXPORT void Update() override;
	API_EXPORT void Destroy() override;

private:
	static void SpeakText(LevelModule* levelModule, const char* speechText);
	static void RecognizeSpeech(LevelModule* levelModule, WelcomeComponent* welcomeComponent);
};