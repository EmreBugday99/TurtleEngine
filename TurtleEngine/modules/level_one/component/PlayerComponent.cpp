#include "PlayerComponent.h"
#include "ec\Component.h"
#include "ec/Entity.h"
#include "ui\UIText.h"
#include "Core.h"
#include "module/ModuleManager.h"
#include "..\module\LevelModule.h"
#include <speechapi_cxx.h>

PlayerComponent::~PlayerComponent() = default;

void PlayerComponent::Initialize()
{
	ContinueSpeechRecognition = true;

	auto& welcomeText = Owner->AddComponent<TurtleCore::UIText>();

	welcomeText.SetFont("assets/Roboto-Regular.ttf", 24);
	welcomeText.SetColor({ 255, 0, 0, 255 });
	welcomeText.SetText("Level One");
	welcomeText.UpdateText();
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
	if (RecognizedSpeech == "Start game.")
	{
		Owner->Destroy();
		return;
	}
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
