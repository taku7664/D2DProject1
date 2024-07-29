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

	T_StatP<int> hp = { 1,1 };		 // ü��
	T_StatP<int> mp = { 0,0 };	     // ����
	float atk = 0.f;
	float attackSpd = 1.f;			 // ���ݼӵ�
	float moveSpd = 0.f;			 // �̵��ӵ�
	float zPos = 0.f;

	float jumpPower = 0.f;
	Vector2 velocity = { 0,0 };		 // �߷� �� �˹� �� �������� ó���� ����
	float gravity = 0.f;
	float gravityScale = 1.f;        // �߷� ���� (ū �������� ������ �������� �����?)
	float weight = 1.f;	             // ���� (���ſ���� �� �ȶ�)
	bool isAirial = false;			 // ���߿� ���°�?

	float invTime = 0.f;			 // ���� �ð�
	float invCount = 0.f;			 // ���� �ð� ī����

};

