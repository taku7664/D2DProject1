#pragma once
#include "../Charactor/Charactor.h"
#include "../Interface/IObjectCore.h"
#include "../../CommandQueue.h"
#include "../../CustomInput.h"

struct SkillInfo;
class Charactor;

enum class CharactorState
{
	Idle,
	Move,
	Jump,
	Hit,
	Die,
	Attack,
	Skill,
	SIZE
};

class CharactorCore
	: public IObjectCore
{
private:
	
public:
	// ĳ���� �ھ�
	Charactor* charactor;
	// ����
	CharactorState			state;			// ĳ���� ����
	std::vector<SkillInfo*> skillList;
	SkillInfo*				skillSlot[12];  // ��ų ������ �� ���� (��Ÿ�� ������ ��)
	// ������ ����
	Animator2D*				animator;		// ĳ���� �ִϸ��̼�
	Vector2					aniOffset;		// �ִϸ����� ������
	SpriteRenderer2D*		footSprite;     // ���� ��������Ʈ
	// input����
	CommandQueue			commandQueue;	// Ŀ�ǵ� ť
	CustomInput				input;			// ����ڰ� ���� �����ϰԲ� ���ִ� Input����ü. �⺻���� ����ִ�.

	std::vector<Resource::FMODSound*> runSound;

	// ���� Ű���� �Է� �̺�Ʈ�� ������ ���ΰ�? 
	// (�÷��̾�� Ű���带 Ʈ���ŷ� ������, AI�� ��ü���� �ΰ������� Ʈ���ŷ� ����ؾ� �Ѵ�.)
	virtual bool TriggerKeyDown(int _trigger) = 0;
	virtual bool TriggerKeyHold(int _trigger) = 0;
	virtual bool TriggerKeyUp(int _trigger)   = 0;

	void UpdateCommandQueue();
	void SetMoveDirect();
	void SetVelocityDirect();
	void CalculateCoolTime();

	void Start();
	void Update();
	void LateUpdate();
	void OnCollisionEnter(Actor* _collision);

	void LoadResource();
	
	template <typename T>
	void SetCharactor()
	{
		if (charactor)
		{
			charactor->Release();
			delete charactor;
		}
		T* temp = new T(this);
		temp->Initialize();
		charactor = temp;
	}

};