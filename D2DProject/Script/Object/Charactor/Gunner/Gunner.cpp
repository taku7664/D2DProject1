#include "Gunner.h"
#include "Contents.h"
#include "../CharactorCore.h"
#include "../CommonFSM/CharactorIdle.h"
#include "../CommonFSM/CharactorWalk.h"
#include "../CommonFSM/CharactorRun.h"
#include "../CommonFSM/CharactorHit.h"
#include "FSM/GunnerJump.h"
#include "FSM/GunnerBackStep.h"

void Gunner::Initialize()
{
	core->hp = { 15000, 15000 };
	core->mp = { 500, 500 };
	core->atk = 300.f;
	core->attackSpd = 1.7f;
	core->moveSpd = 170.f;
	core->jumpPower = 600.0f;
	core->weight = 1000.f;

	core->body->size = { 70.f, 60.f };
	core->body->offset = { 0.f, 40.f };

	core->animator->AddAnimation("Idle", LoadAnimation::GunnerIdle().Load());
	core->animator->AddAnimation("Walk", LoadAnimation::GunnerWalk().Load());
	core->animator->AddAnimation("Run",  LoadAnimation::GunnerRun().Load());
	core->animator->AddAnimation("Jump", LoadAnimation::GunnerJump().Load());
	core->animator->AddAnimation("Hit",  LoadAnimation::GunnerHit().Load());
	core->animator->ChangeAnimation("Idle");
	core->aniOffset = { 40.f, -90.f };
	core->animator->renderOffset = { 40.f, -120.f };
	core->animator->centerOffset = { 27.f, 0.f };

	core->fsm->AddState<FSM::CharactorIdle>("Idle");
	core->fsm->AddState<FSM::CharactorWalk>("Walk");
	core->fsm->AddState<FSM::CharactorRun>("Run");
	core->fsm->AddState<FSM::GunnerJump>("Jump");
	core->fsm->AddState<FSM::GunnerBackStep>("BackStep");
	core->fsm->AddState<FSM::CharactorHit>("Hit");

}