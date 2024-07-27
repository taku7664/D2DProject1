#pragma once
#include "SkillData.h"

namespace LoadSkill
{
	class LoadSkillData abstract
	{
	public:
		int id = -1;
		std::string key = "";
		SkillData   data = {};
		std::unordered_map<std::string, AttackInfo> info;
		SkillInfo* Load()
		{
			SkillInfo* res = new SkillInfo(id, key, data, info);
			return res;
		}
		AttackInfo& GetInfo(const std::string& _key)
		{
			auto it = info.find(_key);
			if (it != info.end())
			{
				return it->second;
			}
			else return info.begin()->second;
		}
	};
}