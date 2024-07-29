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
