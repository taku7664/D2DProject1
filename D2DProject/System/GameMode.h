#pragma once
#include "DemoApp.h"
#include "../Script/Player/Player.h"
#include "../Script/AI/AI.h"
#include "../Script/Object/Charactor/SwordMan/SwordMan.h"
#include "../Script/Object/Charactor/Gunner/Gunner.h"

enum class GameProcess
{
	Ready,
	Zoom,
	Count,
	Start,
	End,
	Result
};

class GameMode
{
	template <typename T1, typename T2>
	static CharactorCore* CreatePlayer(World* _world)
	{
		T1* CharactorCore = _world->CreateObject<Actor>("Player" + std::to_string(playerList.size())
			, LayerTag::Object, ObjectTag::Player)->AddComponent<T1>();
		CharactorCore->gameObject->SetPersistent(true);
		CharactorCore->SetCharactor<T2>();
		return CharactorCore;
	}

public:

	static GameProcess curState;
	static std::vector<CharactorCore*> playerList;
	static std::vector<CharactorCore*> deadList;
	static int   playerCount;

	static float skillRangePer;
	static float atkSpeedPer;
	static float movSpeedPer;

	static bool isEnd;

	static CharactorCore* CheckWinner();

	template <typename T1, typename T2>
	static CharactorCore* AddPlayer(World* _world)
	{
		CharactorCore* core;
		core = CreatePlayer<T1, T2>(_world);
		playerList.push_back(core);
		return core;
	}

	static void RemovePlayer(int _index)
	{
		playerList[_index]->gameObject->SetDestroy();
		playerList.erase(playerList.begin() + _index);
		playerCount = 0;
		for (CharactorCore* CharactorCore : playerList)
		{
			Player* player = CharactorCore->gameObject->GetComponent<Player>();
			if (player)
			{
				player->inputID = ++playerCount;
			}
		}
	}
	template <typename T1, typename T2>
	static CharactorCore* RemoveAndAdd(int _index, World* _world)
	{
		playerList[_index]->gameObject->SetDestroy();
		CharactorCore* core = CreatePlayer<T1, T2>(_world);
		(*(playerList.begin() + _index)) = core;
		playerCount = 0;
		for (CharactorCore* CharactorCore : playerList)
		{
			Player* player = CharactorCore->gameObject->GetComponent<Player>();
			if (player)
			{
				player->inputID = ++playerCount;
			}
		}
		return core;
	}
	static void Clear()
	{
		for (CharactorCore* core : playerList)
		{
			core->pvpInfo.Clear();
		}
	}
};