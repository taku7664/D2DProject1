#include "GameMode.h"

GameProcess GameMode::curState = GameProcess::Ready;

std::vector<Actor*> GameMode::playerList{};
int   GameMode::playerCount = 0;

float GameMode::atkSpeedPer = 1.f;
float GameMode::movSpeedPer = 1.f;
float GameMode::skillRangePer = 1.f;