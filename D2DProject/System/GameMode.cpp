#include "GameMode.h"
#include "../Script/Object/Charactor/CharactorCore.h"

GameProcess GameMode::curState = GameProcess::Ready;

std::vector<Actor*> GameMode::playerList{};
int   GameMode::playerCount = 0;

float GameMode::atkSpeedPer = 1.f;
float GameMode::movSpeedPer = 1.f;
float GameMode::skillRangePer = 1.5f;
bool GameMode::isEnd = false;

bool GameMode::CheckGameEnd()
{
    int count = 0;
    for (Actor* p : playerList)
    {
        CharactorCore* core = p->GetComponent<CharactorCore>();
        if (core->hp._cur <= 0.f) ++count;
    }
    if (count <= 1)
    {
        isEnd = true;
        return true;
    }
    else return false;
}