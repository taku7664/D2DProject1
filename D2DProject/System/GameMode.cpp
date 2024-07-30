#include "GameMode.h"
#include "../Script/Object/Charactor/CharactorCore.h"

GameProcess                 GameMode::curState = GameProcess::Ready;
std::vector<CharactorCore*>         GameMode::playerList{};
std::vector<CharactorCore*> GameMode::deadList{};
int                         GameMode::playerCount = 0;

float GameMode::atkSpeedPer = 1.f;
float GameMode::movSpeedPer = 1.f;
float GameMode::skillRangePer = 1.0f;
bool GameMode::isEnd = false;

CharactorCore* GameMode::CheckWinner()
{
    int count = 0;
    CharactorCore* temp = nullptr;
    for (CharactorCore* core : playerList)
    {
        if (core->hp._cur > 0.f)
        {
            ++count;
            temp = core;
        }
    }
    if (count == 1)
    {
        isEnd = true;
        return temp;
    }
    else return nullptr;
}
