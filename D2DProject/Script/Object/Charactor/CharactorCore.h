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
	// 캐릭터 코어
	Charactor* charactor;
	// 변수
	CharactorState			state;			// 캐릭터 상태
	std::vector<SkillInfo*> skillList;
	SkillInfo*				skillSlot[12];  // 스킬 퀵슬롯 및 정보 (쿨타임 데미지 등)
	// 렌더링 관련
	Animator2D*				animator;		// 캐릭터 애니메이션
	Vector2					aniOffset;		// 애니메이터 오프셋
	SpriteRenderer2D*		footSprite;     // 발판 스프라이트
	// input관련
	CommandQueue			commandQueue;	// 커맨드 큐
	CustomInput				input;			// 사용자가 변경 가능하게끔 해주는 Input구조체. 기본값이 들어있다.

	// 무슨 키보드 입력 이벤트를 실행할 것인가? 
	// (플레이어는 키보드를 트리거로 삼지만, AI는 자체적인 인공지능을 트리거로 사용해야 한다.)
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