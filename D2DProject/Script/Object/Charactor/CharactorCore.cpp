#include "CharactorCore.h"
#include "Script/CameraController.h"
#include "Contents.h"

void CharactorCore::Start()
{
	__super::Start();

	animator = bodyActor->AddComponent<Animator2D>();
	fsm		 = gameObject->AddComponent<FiniteStateMachine>();

	LoadResource();

	footSprite = gameObject->AddComponent<SpriteRenderer2D>();
	footSprite->SetSprite(LoadSprite::PlayerFoot().Get());
	footSprite->renderOffset = { 0 , -15 };

	foot->SetRenderInfo(D2D1::ColorF(D2D1::ColorF::DarkViolet), 1.5f);
	body->SetRenderInfo(D2D1::ColorF(D2D1::ColorF::DarkGreen), 1.5f);
	foot->size = { 65, 20 };
	foot->offset = { 0, 0 };

	body->size = { 65.f, 100.f };
	body->offset = { 0.f, 60.f };
	
	invTime = 1.0f;
}

// �ֿ� ������Ʈ�� FSM�� ���� ������Ʈ �ȴ�.
// �̰��� ��� ���¿����� ���������� ������Ʈ �� �κ��� �����.
// ex. ��������, hp, mp���� ��
// ������ ���� FSM�� Update���� Core�� Update�� ���� ȣ��ȴٴ°�
void CharactorCore::Update()
{
	__super::Update();
	UpdateCommandQueue();
	CalculateCoolTime();

	if (state == CharactorState::Idle ||
		state == CharactorState::Move ||
		state == CharactorState::Jump)
	{
		animator->countScale = 1.f;
	}
	else
	{
		animator->countScale = attackSpd;
	}
}

void CharactorCore::LateUpdate()
{
	__super::LateUpdate();
	if (hp._cur <= 0)
	{
		hp._cur = 0.f;
		if(zPos == 0.f) fsm->ChangeState("Die");
	}
	if (mp._cur <= 0)
	{
		mp._cur = 0.f;
	}
	// ���ǿ��� ��� Ǯ�� ȸ��
	if (GameMode::curState == GameProcess::Ready)
	{
		hp._cur = hp._max;
		mp._cur = mp._max;
	}
	if(state != CharactorState::Die)
		invCount -= Time::deltaTime;
	if (invCount <= 0.f)
	{
		body->SetState(GameState::Active);
	}
	else
	{
		body->SetState(GameState::Passive);
	}
}

void CharactorCore::UpdateCommandQueue()
{
	commandQueue.count += Time::deltaTime;
	if (TriggerKeyDown(input.left))				commandQueue.push(input.left);
	else if (TriggerKeyDown(input.right))		commandQueue.push(input.right);
	else if (TriggerKeyDown(input.up))			commandQueue.push(input.up);
	else if (TriggerKeyDown(input.down))		commandQueue.push(input.down);
	else if (TriggerKeyDown(input.space))		commandQueue.push(input.space);
	else if (TriggerKeyDown(input.z))			commandQueue.push(input.z);
	else if (TriggerKeyDown(input.x))			commandQueue.push(input.x);
	else if (TriggerKeyDown(input.c))			commandQueue.push(input.c);
	else if (commandQueue.count > 0.2)			commandQueue.clear();
}

void CharactorCore::SetMoveDirect()
{
	// ������ ���� �� ���� ���� ����
	if (TriggerKeyUp(input.left))
	{
		if (TriggerKeyHold(input.right))
			dirVector.x = 1;
		else dirVector.x = 0;
	}
	if (TriggerKeyUp(input.right))
	{
		if (TriggerKeyHold(input.left))
			dirVector.x = -1;
		else dirVector.x = 0;
	}
	if (TriggerKeyUp(input.up))
	{
		if (TriggerKeyHold(input.down))
			dirVector.y = 1;
		else dirVector.y = 0;
	}
	if (TriggerKeyUp(input.down))
	{
		if (TriggerKeyHold(input.up))
			dirVector.y = -1;
		else dirVector.y = 0;
	}
	// ������ �� ���⺤�� ����
	if (TriggerKeyDown(input.left))
	{
		dirVector.x = -1.f;
	}
	else if (TriggerKeyDown(input.right))
	{
		dirVector.x = 1.f;
	}
	if (TriggerKeyDown(input.up))
	{
		dirVector.y = -1.f;
	}
	if (TriggerKeyDown(input.down))
	{
		dirVector.y = 1.f;
	}
}

void CharactorCore::SetVelocityDirect()
{
	if (bodyActor->transform->scale.x == 1.f)
	{
		if (TriggerKeyHold(input.right))
		{
			dirVector.x = 1.f;
		}
		else if (TriggerKeyHold(input.left))
		{
			dirVector.x = 0.f;
		}
		else dirVector.x = 0.5f;
	}
	else if (bodyActor->transform->scale.x == -1.f)
	{
		if (TriggerKeyHold(input.left))
		{
			dirVector.x = -1.f;
		}
		else if (TriggerKeyHold(input.right))
		{
			dirVector.x = 0.f;
		}
		else dirVector.x = -0.5f;
	}
}

void CharactorCore::CalculateCoolTime()
{
	for (SkillInfo* info : skillList)
	{
		if (info)
		{
			info->coolCount += Time::deltaTime;
			if (info->coolCount >= info->data.coolTime)
				info->coolCount = info->data.coolTime;
		}
	}
}

void CharactorCore::OnCollisionEnter(Actor* _collision)
{
}

void CharactorCore::LoadResource()
{
	LoadSprite::PlayerFoot().Load();
	runSound.push_back(soundPlayer->AddAudio("Run1", LoadSound::Run1().Load()));
	runSound.push_back(soundPlayer->AddAudio("Run2", LoadSound::Run2().Load()));
	runSound.push_back(soundPlayer->AddAudio("Run3", LoadSound::Run3().Load()));
}