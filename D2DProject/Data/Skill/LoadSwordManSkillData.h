#pragma once
#include "LoadSkillData.h"

namespace LoadSkill
{
	struct Guard : public LoadSkillData
	{
		Guard()
		{
			id = 0;
			key = "Guard";
			data =
			{
				{1}, // ����
				{true}, // ��Ÿ ĵ�� ���� ����
				{1}  // ��Ÿ��
			};
		}
	};
	struct BackStepCutter : public LoadSkillData
	{
		BackStepCutter()
		{
			id = 2;
			key = "BackStepCutter";
			data =
			{
				{1}, // ����
				{}, // ��Ÿ ĵ�� ���� ����
				{4}  // ��Ÿ��
			};
		}
	};
	struct UpperSlash : public LoadSkillData
	{
		UpperSlash()
		{
			id = 3;
			key = "Upper";
			data =
			{
				{1}, // ����
				{true}, // ��Ÿ ĵ�� ���� ����
				{2.0f}  // ��Ÿ��
			};
			info.insert(std::make_pair("Slash", AttackInfo() = {
				1.0f,
				60.0f,
				540.0f,
				7.0f,
				Vector2(120.0f,0.0f),
				true,
				false
			}));
		}
	};
	struct HardAttack : public LoadSkillData
	{
		HardAttack()
		{
			id = 4;
			key = "HardAttack";
			data =
			{
				{1}, // ����
				{}, // ��Ÿ ĵ�� ���� ����
				{6}  // ��Ÿ��
			};
			info.insert(std::make_pair("Slash", AttackInfo() = {
				3.0f,
				60.0f,
				300.0f,
				3.0f,
				Vector2(350.0f,0.0f),
				true,
				false
			}));
		}
	};
	struct VaneSlash : public LoadSkillData
	{
		VaneSlash()
		{
			id = 5;
			key = "VaneSlash";
			data =
			{
				{1}, // ����
				{true}, // ��Ÿ ĵ�� ���� ����
				{6}  // ��Ÿ��
			};
			info.insert(std::make_pair("Up_Down", AttackInfo() = {
				0.2f,
				50.0f,
				1.0f,
				0.0f,
				Vector2(0.0f,0.0f),
				false,
				true
			}));
			info.insert(std::make_pair("Wave", AttackInfo() = {
				1.5f,
				100.0f,
				150.0f,
				0.3f,
				Vector2(120.0f,0.0f),
				true,
				false
			}));
		}
	};
};