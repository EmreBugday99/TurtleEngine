#include "PlayerComponent.h"
#include "ec\Component.h"
#include "ec/Entity.h"
#include "ui\UIText.h"
#include "Core.h"
#include "module/ModuleManager.h"
#include "..\module\LevelModule.h"
#include <speechapi_cxx.h>
#include "components\TransformComponent.h"
#include "components\SpriteComponent.h"
#include "event\CoreEvents.h"
#include "event\EventData.h"

PlayerComponent::~PlayerComponent() = default;

void PlayerComponent::Initialize()
{
	ContinueSpeechRecognition = true;

	auto& levelText = Owner->AddComponent<TurtleCore::UIText>();

	levelText.SetFont("assets/Roboto-Regular.ttf", 24);
	levelText.SetColor({ 255, 0, 0, 255 });
	levelText.SetText("Level One");
	levelText.UpdateText();

	TurtleCore::CoreEvents::AddEvent("PlayerAction", &PlayerActionEvent);
}

void PlayerComponent::Start()
{
	TurtleCore::Core* core = Owner->GetEngine();
	bool hasGameModule;
	core->ModuleManager.HasModule("LevelOne", hasGameModule);
	if (hasGameModule == false)
		return;

	bool getModuleResult;
	Module = (LevelModule*)core->ModuleManager.GetModule("LevelOne", getModuleResult);
	if (getModuleResult == false)
		return;

	SpeechFutures.push_back(std::async(std::launch::async, SpeakText, Module, "Level One Started."));
	RecognitionFuture = std::async(std::launch::async, RecognizeSpeech, Module, this);
}

void PlayerComponent::Update()
{
	auto* transform = Owner->GetComponent<TurtleCore::TransformComponent>();

	if (RecognizedSpeech == "Move up.")
	{
		transform->Position.Y -= 25;
		PlayerActionEvent.Invoke(TurtleCore::EventData("Move up", this));
	}
	else if (RecognizedSpeech == "Move down.")
	{
		transform->Position.Y += 25;
		PlayerActionEvent.Invoke(TurtleCore::EventData("Move down", this));
	}
	else if (RecognizedSpeech == "Move right.")
	{
		transform->Position.X += 25;
		PlayerActionEvent.Invoke(TurtleCore::EventData("Move right", this));
	}
	else if (RecognizedSpeech == "Move left.")
	{
		transform->Position.X -= 25;
		PlayerActionEvent.Invoke(TurtleCore::EventData("Move left", this));
	}
	else if (RecognizedSpeech == "Stay put.")
	{
		transform->Position.X -= 25;
		PlayerActionEvent.Invoke(TurtleCore::EventData("Stay put", this));
	}

	if (RecognizedSpeech.empty() == false)
	{
		std::cout << "Recognized Command: " << RecognizedSpeech << std::endl;
	}

	RecognizedSpeech = "";
}

void PlayerComponent::Destroy()
{
	ContinueSpeechRecognition = false;
	SpeechFutures.clear();
}

void PlayerComponent::SpeakText(LevelModule* levelModule, const char* speechText)
{
	levelModule->Synthesizer->SpeakTextAsync(speechText).get();
}

void PlayerComponent::RecognizeSpeech(LevelModule* levelModule, PlayerComponent* playerComponent)
{
	using namespace Microsoft::CognitiveServices::Speech;
	using namespace Microsoft::CognitiveServices::Speech::Audio;

	// To prevent race condition do not modify ContinueSpeechRecognition. Just read it.
	while (playerComponent->ContinueSpeechRecognition)
	{
		std::cout << "Provide Input" << std::endl;
		auto result = levelModule->Recognizer->RecognizeOnceAsync().get();
		if (result->Reason == ResultReason::RecognizedSpeech)
			playerComponent->RecognizedSpeech = result->Text;
	}
}
