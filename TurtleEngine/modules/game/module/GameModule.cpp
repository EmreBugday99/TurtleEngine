#include "GameModule.h"
#include "ec/Entity.h"
#include "components/TransformComponent.h"
#include "ui/UIText.h"
#include "Core.h"
#include "../SecretKey.h"
#include "../component/WelcomeComponent.h"

GameModule::GameModule() : TurtleModule("Game") {}
GameModule::~GameModule() = default;

void GameModule::OnModuleLoad(TurtleCore::Core* core)
{
	using namespace Microsoft::CognitiveServices::Speech;
	using namespace Microsoft::CognitiveServices::Speech::Audio;

	SpeechConfig = SpeechConfig::FromSubscription(SubscriptionKey, ServiceRegion);
	SpeechConfig->SetSpeechRecognitionLanguage("en-US");
	SpeechConfig->SetSpeechSynthesisVoiceName("en-US-JennyNeural");

	AudioConfig = AudioConfig::FromDefaultMicrophoneInput();
	Recognizer = SpeechRecognizer::FromConfig(SpeechConfig, AudioConfig);

	Synthesizer = SpeechSynthesizer::FromConfig(SpeechConfig);
}

void GameModule::OnModuleUnload(TurtleCore::Core* core) {}

void GameModule::OnModuleStart(TurtleCore::Core* core)
{
	TurtleCore::Entity& welcomeEntity = core->CreateEntity();
	welcomeEntity.AddComponent<WelcomeComponent>();
}