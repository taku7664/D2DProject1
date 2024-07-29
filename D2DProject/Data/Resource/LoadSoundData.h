#pragma once
#include "../../DemoApp.h"

namespace LoadSound
{
	struct LoadSoundData abstract
	{
		std::wstring _key = L"";
		std::wstring _path = L"";
		bool isLoop = false;
		int group = 0;

		Resource::FMODSound* Load()
		{
			return ResourceManager::AddFMODSound(_key, _path, isLoop, group);
		}
		void Release()
		{
			ResourceManager::ReleaseFMODSound(_key);
		}
	};

	struct Odesa : public LoadSoundData { Odesa(); };
	struct Pub : public LoadSoundData { Pub(); };
	struct Town : public LoadSoundData { Town(); };
	struct Bwanga : public LoadSoundData { Bwanga(); };
}