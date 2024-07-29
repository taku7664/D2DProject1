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
		Resource::FMODSound* Get()
		{
			return ResourceManager::GetFMODSound(_key);
		}
		void Release()
		{
			ResourceManager::ReleaseFMODSound(_key);
		}
	};
	// BackGround
	struct Odesa : public LoadSoundData { Odesa(); };
	struct Pub : public LoadSoundData { Pub(); };
	struct Town : public LoadSoundData { Town(); };
	struct Bwanga : public LoadSoundData { Bwanga(); };

	// Extra
	struct Run1 : public LoadSoundData { Run1(); };
	struct Run2 : public LoadSoundData { Run2(); };
	struct Run3 : public LoadSoundData { Run3(); };

	//SwordMan Voice
	struct Voice_SwordManHit1 : public LoadSoundData { Voice_SwordManHit1(); };
	struct Voice_SwordManHit2 : public LoadSoundData { Voice_SwordManHit2(); };
	struct Voice_SwordManHit3 : public LoadSoundData { Voice_SwordManHit3(); };
	struct Voice_SwordManJump : public LoadSoundData { Voice_SwordManJump(); };
	struct Voice_SwordManBackStep : public LoadSoundData { Voice_SwordManBackStep(); };

	struct Voice_SwordManJumpAttack1 : public LoadSoundData { Voice_SwordManJumpAttack1(); };
	struct Voice_SwordManJumpAttack2 : public LoadSoundData { Voice_SwordManJumpAttack2(); };
	struct Voice_SwordManBassicAttack1 : public LoadSoundData { Voice_SwordManBassicAttack1(); };
	struct Voice_SwordManBassicAttack2 : public LoadSoundData { Voice_SwordManBassicAttack2(); };
	struct Voice_SwordManBassicAttack3 : public LoadSoundData { Voice_SwordManBassicAttack3(); };
	struct Voice_SwordManDashAttack : public LoadSoundData { Voice_SwordManDashAttack(); };

	struct Voice_SwordManvaneSlashUp : public LoadSoundData { Voice_SwordManvaneSlashUp(); };
	struct Voice_SwordManvaneSlashDown : public LoadSoundData { Voice_SwordManvaneSlashDown(); };

	struct Voice_HardAttackVoice1 : public LoadSoundData { Voice_HardAttackVoice1(); };
	struct Voice_HardAttackVoice2 : public LoadSoundData { Voice_HardAttackVoice2(); };

	//Effect
	struct UpperSlash1 : public LoadSoundData			 { UpperSlash1(); };
	struct UpperSlash2 : public LoadSoundData			 { UpperSlash2(); };

	struct HardAttack1 : public LoadSoundData			 { HardAttack1(); };
	struct HardAttack2 : public LoadSoundData			 { HardAttack2(); };
	struct HardAttack3 : public LoadSoundData			 { HardAttack3(); };

	struct VaneSlash : public LoadSoundData				 { VaneSlash(); };
	struct VaneSlash_Flash : public LoadSoundData		 { VaneSlash_Flash(); };
	struct VaneSlashHit : public LoadSoundData			 { VaneSlashHit(); };
	struct VaneSlashWind : public LoadSoundData		 	 { VaneSlashWind(); };
}