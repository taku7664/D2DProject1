#pragma once
#include "DemoApp.h"

struct SkillData
{
	int         lv = 0;
	bool		cancelAble = false;
	float		coolTime = 0.f;
};

struct AttackInfo
{
	float					damagePer = 0.f;
	float					yHitRange = 0.f;
	float                   airPower = 0.f;
	float					staggerTime = 0.f;
	Vector2					vPower = {};
	bool                    isLow = false;
	bool                    singleTarget = false;
};

struct SkillInfo
{
	int id = -1;
	std::string key = ""; // FSM키 값을 주면 된다.
	SkillData data;
	std::unordered_map<std::string, AttackInfo> info;
	float coolCount = 0.f;

	SkillInfo(int _id, std::string _key, SkillData _data, std::unordered_map<std::string, AttackInfo>& _info)
	{
		id = _id;
		key = _key;
		data = std::move(_data);
		info = std::move(_info);
		coolCount = data.coolTime;
	}
	bool CanUse() { return (coolCount >= data.coolTime); }
	
};
