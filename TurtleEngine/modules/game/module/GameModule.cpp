#include "GameModule.h"
#include "ec/Entity.h"
#include "components/TransformComponent.h"
#include "ui/UIText.h"
#include "Core.h"
#include "../SecretKey.h"
#include "../component/WelcomeComponent.h"
#include "components/SpriteComponent.h"

GameModule::GameModule() : TurtleModule("Game")
{
	ModuleType = TurtleCore::ModuleTypes::GameModule;
}

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

void GameModule::OnModuleUnload(TurtleCore::Core* core)
{
	for (TurtleCore::Entity* entity : Entities)
	{
		entity->Destroy();
	}

	Entities.clear();
	Entities.shrink_to_fit();

	core->GetMemory().CollectGarbage();

	bool success = false;
	core->ModuleManager.HasModule("LevelOne", success);
	if (!success) return;
	
	TurtleModule* levelOne = core->ModuleManager.GetModule("LevelOne", success);
	if (!success) return;

	std::cout << "Loading Level One..." << std::endl;

	levelOne->OnModuleLoad(core);
	levelOne->OnModuleStart(core);
}

void GameModule::OnModuleStart(TurtleCore::Core* core)
{
	TurtleCore::Entity& welcomeEntity = core->CreateEntity();
	welcomeEntity.AddComponent<WelcomeComponent>();

	Entities.push_back(&welcomeEntity);
}