#include "LoadSoundData.h"
#include "../../System/GameManager.h"

LoadSound::Odesa::Odesa()
{
	_key = L"Odesa";
	_path = L"Sound/BG/odesa_new.ogg";
	isLoop = true;
	group = BackGround;
}

LoadSound::Pub::Pub()
{
	_key = L"Pub";
	_path = L"Sound/BG/pvp_pub.ogg";
	isLoop = true;
	group = BackGround;
}

LoadSound::Town::Town()
{
	_key = L"Town";
	_path = L"Sound/BG/pvp_town.ogg";
	isLoop = true;
	group = BackGround;
}

LoadSound::Bwanga::Bwanga()
{
	_key = L"Bwanga";
	_path = L"Sound/BG/pvp_bwanga.ogg";
	isLoop = true;
	group = BackGround;
}

LoadSound::Room::Room()
{
	_key = L"Room";
	_path = L"Sound/BG/pvp_room.mp3";
	isLoop = true;
	group = BackGround;
}

LoadSound::Run1::Run1()
{
	_key = L"Run1";
	_path = L"Sound/run_stone_01.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::Run2::Run2()
{
	_key = L"Run2";
	_path = L"Sound/run_stone_02.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::Run3::Run3()
{
	_key = L"Run3";
	_path = L"Sound/run_stone_03.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::Count1::Count1()
{
	_key = L"Count1";
	_path = L"Sound/Voice/PVP/hk10_m_count_01.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Count2::Count2()
{
	_key = L"Count2";
	_path = L"Sound/Voice/PVP/hk10_m_count_02.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Count3::Count3()
{
	_key = L"Count3";
	_path = L"Sound/Voice/PVP/hk10_m_count_03.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Fight::Fight()
{
	_key = L"Fight";
	_path = L"Sound/Voice/PVP/hk10_m_count_fight.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManBassicAttack1::Voice_SwordManBassicAttack1()
{
	_key = L"Voice_SwordManBassicAttack1";
	_path = L"Sound/Voice/SwordMan/sm_atk_01.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManBassicAttack2::Voice_SwordManBassicAttack2()
{
	_key = L"Voice_SwordManBassicAttack2";
	_path = L"Sound/Voice/SwordMan/sm_atk_02.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManBassicAttack3::Voice_SwordManBassicAttack3()
{
	_key = L"Voice_SwordManBassicAttack3";
	_path = L"Sound/Voice/SwordMan/sm_atk_03.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManHit1::Voice_SwordManHit1()
{
	_key = L"Voice_SwordManHit1";
	_path = L"Sound/Voice/SwordMan/sm_dmg_01.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManHit2::Voice_SwordManHit2()
{
	_key = L"Voice_SwordManHit2";
	_path = L"Sound/Voice/SwordMan/sm_dmg_02.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManHit3::Voice_SwordManHit3()
{
	_key = L"Voice_SwordManHit3";
	_path = L"Sound/Voice/SwordMan/sm_dmg_03.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManJump::Voice_SwordManJump()
{
	_key = L"Voice_SwordManJump";
	_path = L"Sound/Voice/SwordMan/sm_jump.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManBackStep::Voice_SwordManBackStep()
{
	_key = L"Voice_SwordManBackStep";
	_path = L"Sound/Voice/SwordMan/sm_back.ogg";
	isLoop = false;
	group = Voice;
}


LoadSound::Voice_SwordManDie::Voice_SwordManDie()
{
	_key = L"Voice_SwordManDie";
	_path = L"Sound/Voice/SwordMan/sm_die.ogg";
	isLoop = false;
	group = Voice;
}


LoadSound::Voice_SwordManJumpAttack1::Voice_SwordManJumpAttack1()
{
	_key = L"Voice_SwordManJumpAttack1";
	_path = L"Sound/Voice/SwordMan/sm_jumpatk_01.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManJumpAttack2::Voice_SwordManJumpAttack2()
{
	_key = L"Voice_SwordManJumpAttack2";
	_path = L"Sound/Voice/SwordMan/sm_jumpatk_02.ogg";
	isLoop = false;
	group = Voice;
}


LoadSound::Voice_UpperSlash::Voice_UpperSlash()
{
	_key = L"Voice_UpperSlash";
	_path = L"Sound/Voice/SwordMan/sm_upslash.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_HardAttackVoice1::Voice_HardAttackVoice1()
{
	_key = L"Voice_HardAttackVoice1";
	_path = L"Sound/Voice/SwordMan/sm_gue_01.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_HardAttackVoice2::Voice_HardAttackVoice2()
{
	_key = L"Voice_HardAttackVoice2";
	_path = L"Sound/Voice/SwordMan/sm_gue_02.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManDashAttack::Voice_SwordManDashAttack()
{
	_key = L"Voice_SwordManDashAttack";
	_path = L"Sound/Voice/SwordMan/sm_thrust.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManvaneSlashUp::Voice_SwordManvaneSlashUp()
{
	_key = L"Voice_SwordManvaneSlashUp";
	_path = L"Sound/Voice/SwordMan/sm_yeolpa_up.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::Voice_SwordManvaneSlashDown::Voice_SwordManvaneSlashDown()
{
	_key = L"Voice_SwordManvaneSlashDown";
	_path = L"Sound/Voice/SwordMan/sm_yeolpa_down.ogg";
	isLoop = false;
	group = Voice;
}

LoadSound::HardAttack1::HardAttack1()
{
	_key = L"HardAttack1";
	_path = L"Sound/Effect/Skill/SwordMan/gue_sword_01.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::HardAttack2::HardAttack2()
{
	_key = L"HardAttack2";
	_path = L"Sound/Effect/Skill/SwordMan/gue_sword_02.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::HardAttack3::HardAttack3()
{
	_key = L"HardAttack3";
	_path = L"Sound/Effect/Skill/SwordMan/gue_sword_03.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::VaneSlash::VaneSlash()
{
	_key = L"VaneSlash1";
	_path = L"Sound/Effect/Skill/SwordMan/moon_atk_01.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::VaneSlash_Flash::VaneSlash_Flash()
{
	_key = L"VaneSlash2";
	_path = L"Sound/Effect/Skill/SwordMan/yeolpa_flash.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::VaneSlashHit::VaneSlashHit()
{
	_key = L"VaneSlash3";
	_path = L"Sound/Effect/Skill/SwordMan/yeolpa_wind_hit.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::VaneSlashWind::VaneSlashWind()
{
	_key = L"VaneSlash4";
	_path = L"Sound/Effect/Skill/SwordMan/yeolpa_wind.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::UpperSlash1::UpperSlash1()
{
	_key = L"UpperSlash1";
	_path = L"Sound/Effect/Skill/SwordMan/upper_slash_01.ogg";
	isLoop = false;
	group = Effect;
}

LoadSound::UpperSlash2::UpperSlash2()
{
	_key = L"UpperSlash2";
	_path = L"Sound/Effect/Skill/SwordMan/upper_slash_02.ogg";
	isLoop = false;
	group = Effect;
}
