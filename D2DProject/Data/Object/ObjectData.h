#pragma once
#include "DemoApp.h"

template<typename T>
struct T_StatP
{
	T _cur;
	T _max;
};
class ObjectData abstract
{
public:

	T_StatP<int> hp = { 1,1 };		 // 체력
	T_StatP<int> mp = { 0,0 };	     // 마나
	float atk = 0.f;
	float attackSpd = 1.f;			 // 공격속도
	float moveSpd = 0.f;			 // 이동속도
	float zPos = 0.f;

	float jumpPower = 0.f;
	Vector2 velocity = { 0,0 };		 // 중력 및 넉백 등 물리관련 처리용 변수
	float gravity = 0.f;
	float gravityScale = 1.f;        // 중력 배율 (큰 데미지를 입으면 높아지게 만들듯?)
	float weight = 1.f;	             // 무게 (무거울수록 잘 안뜸)
	bool isAirial = false;			 // 공중에 떴는가?

	float invTime = 0.f;			 // 무적 시간
	float invCount = 0.f;			 // 무적 시간 카운터

};

