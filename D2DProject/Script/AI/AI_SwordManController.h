#pragma once
#include "DemoApp.h"

class AI;

class AI_SwordManController
	: public Script
{
private:

	AI* owner;
	int seed = 0;
	float targetTimer = 0.f;
	float moveTimer = 10.f;
	float seedTimer = 0.f;
	Vector2 targetDistance;

	int curLogic = 0;

	void Cmd_Dash(KeyType _key);
	bool MoveLogic(Vector2 _myPos, Vector2 _targetPos);
	void TargettingLogic();

	void State_Jump(int _seed);
	void State_BassicAttack1(int _seed);
	void State_BassicAttack2(int _seed);
	void State_BassicAttack3(int _seed);
	void State_UpperSlash(int _seed);
	void State_HardAttack(int _seed);
	void State_VaneSlash(int _seed);


public:

	void Start();
	void Update();

};

enum AI_Logic
{
	Idle,
	Move,
	Jump,
	BackStep,
	BassicAttack,
	JumpAttack,
	Attack1,
	Attack2,
	Attack3,
};