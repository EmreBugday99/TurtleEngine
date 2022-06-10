#include "LevelModule.h"
#include "ec/Entity.h"
#include "components/TransformComponent.h"
#include "ui/UIText.h"
#include "Core.h"
#include "../SecretKey.h"
#include "../component/PlayerComponent.h"
#include "components/SpriteComponent.h"
#include "../component/EnemyComponent.h"

LevelModule::LevelModule() : TurtleModule("LevelOne")
{
	ModuleType = TurtleCore::ModuleTypes::CustomModule;
}

LevelModule::~LevelModule() = default;

void LevelModule::OnModuleLoad(TurtleCore::Core* core)
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

void LevelModule::OnModuleUnload(TurtleCore::Core* core) {}

void LevelModule::OnModuleStart(TurtleCore::Core* core)
{
	{
		TurtleCore::Entity& playerEntity = core->CreateEntity();
		auto& playerTransform = playerEntity.AddComponent<TurtleCore::TransformComponent>();
		playerEntity.AddComponent<PlayerComponent>();
		auto& playerSprite = playerEntity.AddComponent<TurtleCore::SpriteComponent>();
		playerSprite.SetTexture("assets/player.png");

		playerTransform.Position.X = 25;
		playerTransform.Position.Y = 100;
		playerTransform.Size.Set(50);
	}

	{
		TurtleCore::Entity& enemyEntity = core->CreateEntity();
		auto& enemyTransform = enemyEntity.AddComponent<TurtleCore::TransformComponent>();
		auto& enemySprite = enemyEntity.AddComponent<TurtleCore::SpriteComponent>();
		enemyEntity.AddComponent<EnemyComponent>();

		enemyTransform.Position.Set(10);
		enemyTransform.Size.Set(25);
		enemySprite.SetTexture("assets/enemy.png");
	}
}