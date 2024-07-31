#pragma once
#include "DemoApp.h"

namespace LoadSprite
{
	struct LoadSpriteData abstract
	{
		std::wstring _key = L"";
		std::wstring _path = L"";
		SpriteData  _data = {};
		Resource::Sprite2D* Load()
		{
			return ResourceManager::AddSprite2D(_key, _path, _data);
		}
		void Release()
		{
			ResourceManager::ReleaseSprite2D(_key);
		}
		Resource::Sprite2D* Get()
		{
			return ResourceManager::GetSprite2D(_key);
		}
	};
	//==============Player==============
	struct PlayerFoot : public LoadSpriteData {
		PlayerFoot() {
			_key = L"S_PlayerFoot";
			_path = L"Sprite/Player/Foot.png";
			_data = SpriteData();
		}
	};
	struct SwordManSheet1 : public LoadSpriteData {
		SwordManSheet1() {
			_key = L"S_SwordManSheet1";
			_path = L"Sprite/Player/Swordman/Swordman_Sheet1.png";
			_data = SpriteData(Vector2(7, 6));
		}
	};
	struct SwordManSheet2 : public LoadSpriteData {
		SwordManSheet2() {
			_key = L"S_SwordManSheet2";
			_path = L"Sprite/Player/Swordman/Swordman_Sheet2.png";
			_data = SpriteData(Vector2(12, 12));
		}
	};
	struct GunnerSheet1 : public LoadSpriteData {
		GunnerSheet1() {
			_key = L"S_GunnerSheet1";
			_path = L"Sprite/Player/Gunner/Gunner_Sheet1.png";
			_data = SpriteData(Vector2(8, 7));
		}
	};
	struct GunnerSheet2 : public LoadSpriteData {
		GunnerSheet2() {
			_key = L"S_GunnerSheet2";
			_path = L"Sprite/Player/Gunner/Gunner_Sheet2.png";
			_data = SpriteData(Vector2(10, 10));
		}
	};
	// ==============Font==============
	struct TimerSheet1 : public LoadSpriteData {
		TimerSheet1() {
			_key = L"S_TimerSheet1";
			_path = L"Sprite/FontSprite/Timer_Sheet.png";
			_data = SpriteData(Vector2(12, 1));
		}
	};
	// ==============Effect==============
	struct HardAttackSheet1 : public LoadSpriteData {
		HardAttackSheet1() {
			_key = L"S_HardAttack";
			_path = L"Sprite/Effect/HardAttack/Sheet1.png";
			_data = SpriteData(Vector2(3, 2));
		}
	};
	struct UpperSlashSheet1 : public LoadSpriteData {
		UpperSlashSheet1() {
			_key = L"S_UpperSlash";
			_path = L"Sprite/Effect/UpperSlash/Sheet1.png";
			_data = SpriteData(Vector2(3, 3));
		}
	};
	struct VaneSlashSheet1 : public LoadSpriteData {
		VaneSlashSheet1() {
			_key = L"S_VaneSlashSheet1";
			_path = L"Sprite/Effect/VaneSlash/Sheet1.png";
			_data = SpriteData(Vector2(5, 4));
		}
	};
	struct VaneSlashSheet2 : public LoadSpriteData {
		VaneSlashSheet2() { 
			_key = L"S_VaneSlashSheet2";
			_path = L"Sprite/Effect/VaneSlash/Sheet2.png";
			_data = SpriteData(Vector2(3, 3));
		}
	};
	struct GunnerBulletSheet : public LoadSpriteData {
		GunnerBulletSheet() {
			_key = L"S_GunnerBulletSheet";
			_path = L"Sprite/Effet/UpperSlash/Bullet_Sheet.png";
			_data = SpriteData(Vector2(4, 1));
		}
	};
	// ==============Map==============
	struct Pup_Map : public LoadSpriteData {
		Pup_Map() {
			_key = L"S_Pup_Map";
			_path = L"Sprite/Map/Pup/pup_map.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct Pup_BackGround : public LoadSpriteData {
		Pup_BackGround() {
			_key = L"S_Pup_BG";
			_path = L"Sprite/Map/Pup/pup_bg.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	// ==============UI==============
	struct TimerBar : public LoadSpriteData {
		TimerBar() {
			_key = L"S_TimerBar";
			_path = L"Sprite/FontSprite/TimerBar.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct Pvp_List : public LoadSpriteData {
		Pvp_List() {
			_key = L"S_Pvp_List";
			_path = L"Sprite/UI/pvp_list.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct Select_Map : public LoadSpriteData {
		Select_Map() {
			_key = L"S_Select_Map";
			_path = L"Sprite/UI/select_map.png";
			_data = SpriteData(Vector2(4, 3));
		}
	};
	struct PlayerType : public LoadSpriteData {
		PlayerType() {
			_key = L"S_PlayerType";
			_path = L"Sprite/UI/player_type.png";
			_data = SpriteData(Vector2(2, 1));
		}
	};
	struct PMButton : public LoadSpriteData {
		PMButton() {
			_key = L"S_PM_BT";
			_path = L"Sprite/UI/p_m.png";
			_data = SpriteData(Vector2(2, 1));
		}
	};
	struct PlayerUpperHUD : public LoadSpriteData {
		PlayerUpperHUD() {
			_key = L"S_PlayerUpperHUD";
			_path = L"Sprite/UI/player_bar.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct HPBar : public LoadSpriteData {
		HPBar() {
			_key = L"S_HPBar";
			_path = L"Sprite/UI/hpbar.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct MPBar : public LoadSpriteData {
		MPBar() {
			_key = L"S_MPBar";
			_path = L"Sprite/UI/mpbar.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct ArrowSheet : public LoadSpriteData {
		ArrowSheet() {
			_key = L"S_ArrowSheet";
			_path = L"Sprite/UI/arrow.png";
			_data = SpriteData(Vector2(2, 2));
		}
	};
	struct ButtonSheet : public LoadSpriteData {
		ButtonSheet() {
			_key = L"S_ButtonSheet";
			_path = L"Sprite/UI/button_sheet.png";
			_data = SpriteData(Vector2(1, 6));
		}
	};
	struct CountDownSheet : public LoadSpriteData {
		CountDownSheet() {
			_key = L"S_CountDownSheet";
			_path = L"Sprite/UI/count_sheet.png";
			_data = SpriteData(Vector2(4, 4));
		}
	};
	struct SwordManSkillIcon : public LoadSpriteData {
		SwordManSkillIcon() {
			_key = L"S_SwordManSkillIcon";
			_path = L"Sprite/UI/Swordman_Icon.png";
			_data = SpriteData(Vector2(10, 1));
		}
	};
	struct ResultUI1 : public LoadSpriteData {
		ResultUI1() {
			_key = L"S_ResultUI1";
			_path = L"Sprite/UI/PVP_Result1.png";
			_data = SpriteData(Vector2(2, 1));
		}
	};
	struct HeadSheet : public LoadSpriteData {
		HeadSheet() {
			_key = L"S_HeadSheet";
			_path = L"Sprite/UI/HeadSheet.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	struct ResultUI2 : public LoadSpriteData {
		ResultUI2() {
			_key = L"S_ResultUI2";
			_path = L"Sprite/UI/PVP_Result2.png";
			_data = SpriteData(Vector2(1, 1));
		}
	};
	/*struct LightGuardian : public LoadSpriteData {
		LightGuardian() {
			_key = L"S_LightGuardian";
			_path = L"Sprite/Monster/Guard/LightGuard_Sheet.png";
			_data = SpriteData(Vector2(5, 5));
		}
	};
	struct LightGuardAwake : public LoadSpriteData {
		LightGuardAwake() {
			_key = L"S_LightGuardianAwake";
			_path = L"Sprite/Monster/Guard/LightGuardAwake_Sheet.png";
			_data = SpriteData(Vector2(4, 3));
		}
	};*/
}