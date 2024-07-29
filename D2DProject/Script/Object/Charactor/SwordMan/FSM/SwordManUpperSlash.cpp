#include "SwordManUpperSlash.h"
#include "Contents.h"
#include "../../CharactorCore.h"
#include "../../../Effect/Skill/UpperSlash.h"

void FSM::SwordManUpperSlash::Start()
{
	__super::Start();
	voices.push_back(LoadSound::Voice_UpperSlash().Load());
}

void FSM::SwordManUpperSlash::StateEnter()
{
	owner->animator->ChangeAnimation("BasicAttack3", false);
	owner->animator->GotoAndPlay(0);
	owner->state = CharactorState::Attack;
	owner->soundPlayer->Play(voices.front());
}

void FSM::SwordManUpperSlash::StateUpdate()
{
	// =================�÷��̾� Ű �Է� �� �ִϸ��̼�=================
	if (ChangeState_To_AniEnd("Idle")) return;

	// =================�÷��̾� �����Ÿ� ����=================
	owner->dirVector.x = owner->bodyActor->transform->scale.x; // ���������� �����ִ� ����
	if (owner->animator->currentFrame >= 2 && owner->animator->currentFrame <= 5) {
		float factor = 0.7f; // ������ ���� (���� �������� �� ������ ����)
		owner->velocity.x = 30.0f * pow(factor, owner->animator->currentFrame - 2) * Time::GetDeltaTime(1000);
	}
	else owner->velocity.x = 0.f;
	// =================���� ��Ʈ�ڽ� ����=================
	if (owner->animator->IndexEnter(2))
	{
		Actor* effect = owner->CreateObject<Actor>("Ef_UpperSlash", LayerTag::Object, ObjectTag::Particle);
		UpperSlash* sk = effect->AddComponent<UpperSlash>();
		sk->Set(owner, LoadSkill::UpperSlash().GetInfo("Slash"));
		return;
	}
}