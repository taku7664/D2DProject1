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
public:

	static GameProcess curState;
	static std::vector<Actor*> playerList;
	static int   playerCount;

	static float skillRangePer;
	static float atkSpeedPer;
	static float movSpeedPer;

	static bool isEnd;

	static bool CheckGameEnd(); 

	template <typename T1, typename T2>
	static Actor* AddPlayer(World* _world)
	{
		Actor* actor = _world->CreateObject<Actor>("Player" + std::to_string(playerList.size())
			, LayerTag::Object, ObjectTag::Player);
		actor->SetPersistent(true);
		T1* p = actor->AddComponent<T1>();
		p->SetCharactor<T2>();
		playerList.push_back(actor);
		return actor;
	}
	static void RemovePlayer(int _index)
	{
		playerList[_index]->SetDestroy();
		playerList.erase(playerList.begin() + _index);
		playerCount = 0;
		for (Actor* actor : playerList)
		{
			Player* player = actor->GetComponent<Player>();
			if (player)
			{
				player->inputID = ++playerCount;
			}
		}
	}
};