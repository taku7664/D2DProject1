#pragma once

class CharactorCore;
struct SkillInfo;

class Charactor
{
public:
	CharactorCore* core;
	Charactor(CharactorCore* _core) : core(_core) {}
	virtual void Initialize() {}
	virtual void Release() {}

	void AddSkill(SkillInfo* _info);
};

