#pragma once
#include "module/TurtleModule.h"
#include <speechapi_cxx.h>

class LevelModule : TurtleCore::TurtleModule
{
public:
	std::shared_ptr<Microsoft::CognitiveServices::Speech::SpeechConfig> SpeechConfig;
	std::shared_ptr<Microsoft::CognitiveServices::Speech::Audio::AudioConfig> AudioConfig;
	std::shared_ptr<Microsoft::CognitiveServices::Speech::SpeechRecognizer> Recognizer;
	std::shared_ptr<Microsoft::CognitiveServices::Speech::SpeechSynthesizer> Synthesizer;

	LevelModule();
	~LevelModule() override;

	void OnModuleLoad(TurtleCore::Core* core) override;
	void OnModuleUnload(TurtleCore::Core* core) override;

	void OnModuleStart(TurtleCore::Core* core) override;
};
