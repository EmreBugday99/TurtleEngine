#include "WelcomeComponent.h"
#include "ec\Component.h"
#include "ec/Entity.h"
#include "ui\UIText.h"
#include "Core.h"
#include "module/ModuleManager.h"
#include "..\module\GameModule.h"
#include <speechapi_cxx.h>

WelcomeComponent::~WelcomeComponent() = default;

void WelcomeComponent::Initialize()
{
	std::cout << "Initialize" << std::endl;
	ContinueSpeechRecognition = true;

	auto& welcomeText = Owner->AddComponent<TurtleCore::UIText>();

	welcomeText.SetFont("assets/Roboto-Regular.ttf", 24);
	welcomeText.SetColor({ 255, 0, 0, 255 });
	welcomeText.SetText("Please say 'Start Game' to start the game");
	welcomeText.UpdateText();
}

void WelcomeComponent::Start()
{
	TurtleCore::Core* core = Owner->GetEngine();
	bool hasGameModule;
	core->ModuleManager.HasModule("Game", hasGameModule);
	if (hasGameModule == false)
		return;

	bool getModuleResult;
	Module = (GameModule*)core->ModuleManager.GetModule("Game", getModuleResult);
	if (getModuleResult == false)
		return;

	SpeechFutures.push_back(std::async(std::launch::async, SpeakText, Module, "Please say 'Start Game' to start the game"));
	RecognitionFuture = std::async(std::launch::async, RecognizeSpeech, Module, this);
}

void WelcomeComponent::Update()
{
	if (RecognizedSpeech == "Start game.")
	{
		Owner->Destroy();
		return;
	}
}

void WelcomeComponent::Destroy()
{
	ContinueSpeechRecognition = false;
	SpeechFutures.clear();
}

void WelcomeComponent::SpeakText(GameModule* gameModule, const char* speechText)
{
	gameModule->Synthesizer->SpeakTextAsync(speechText).get();
}

void WelcomeComponent::RecognizeSpeech(GameModule* gameModule, WelcomeComponent* welcomeComponent)
{
	using namespace Microsoft::CognitiveServices::Speech;
	using namespace Microsoft::CognitiveServices::Speech::Audio;

	// To prevent race condition do not modify ContinueSpeechRecognition. Just read it.
	while (welcomeComponent->ContinueSpeechRecognition)
	{
		std::cout << "Provide Input" << std::endl;
		auto result = gameModule->Recognizer->RecognizeOnceAsync().get();
		if (result->Reason == ResultReason::RecognizedSpeech)
			welcomeComponent->RecognizedSpeech = result->Text;
	}
}
