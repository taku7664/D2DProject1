#include "SwordMan.h"
#include "Contents.h"
#include "Data/Skill/LoadSwordManSkillData.h"
#include "../CharactorCore.h"
#include "FSM/SwordManIdle.h"
#include "../CommonFSM/CharactorWalk.h"
#include "../CommonFSM/CharactorRun.h"
#include "../CommonFSM/CharactorHit.h"
#include "../CommonFSM/CharactorDie.h"
#include "../CommonFSM/CharactorWin.h"
#include "FSM/SwordManGuard.h"
#include "FSM/SwordManJump.h"
#include "FSM/SwordManBackStep.h"
#include "FSM/SwordManBasicAttack1.h"
#include "FSM/SwordManBasicAttack2.h"
#include "FSM/SwordManBasicAttack3.h"
#include "FSM/SwordManDashAttack.h"
#include "FSM/SwordManJumpAttack.h"
#include "FSM/SwordManUpperSlash.h"
#include "FSM/SwordManHardAttack.h"
#include "FSM/SwordManVaneSlash.h"

void SwordMan::Initialize()
{
	core->hp = { 20000, 20000 };
	core->mp = { 500, 500 };
	core->atk = 350.f; // 350
	core->attackSpd = 2.0f;
	core->moveSpd = 150.f;
	core->jumpPower = 500.0f;
	core->weight = 1000.f;

	core->body->size = { 70.f, 60.f };
	core->body->offset = { 0.f, 40.f };

	core->hitVoice.push_back(core->soundPlayer->AddAudio("Hit1", LoadSound::Voice_SwordManHit1().Load()));
	core->hitVoice.push_back(core->soundPlayer->AddAudio("Hit2", LoadSound::Voice_SwordManHit2().Load()));
	core->hitVoice.push_back(core->soundPlayer->AddAudio("Hit3", LoadSound::Voice_SwordManHit3().Load()));
	core->soundPlayer->AddAudio("Jump",							 LoadSound::Voice_SwordManJump().Load());
	core->soundPlayer->AddAudio("BackStep",						 LoadSound::Voice_SwordManBackStep().Load());
	core->soundPlayer->AddAudio("JumpAttack1",					 LoadSound::Voice_SwordManJumpAttack1().Load());
	core->soundPlayer->AddAudio("JumpAttack2",					 LoadSound::Voice_SwordManJumpAttack2().Load());
	core->soundPlayer->AddAudio("Bassicattack1",				 LoadSound::Voice_SwordManBassicAttack1().Load());
	core->soundPlayer->AddAudio("Bassicattack2",				 LoadSound::Voice_SwordManBassicAttack2().Load());
	core->soundPlayer->AddAudio("Bassicattack3",				 LoadSound::Voice_SwordManBassicAttack3().Load());
	core->soundPlayer->AddAudio("DashAttack",					 LoadSound::Voice_SwordManDashAttack().Load());
	core->soundPlayer->AddAudio("Die",							 LoadSound::Voice_SwordManDie().Load());
	core->soundPlayer->AddAudio("Win",							 LoadSound::Voice_HardAttackVoice1().Load());
	core->soundPlayer->AddAudio("Guard",						 LoadSound::Voice_SwordManGuard().Load());
																 
	core->animator->AddAnimation("Idle",						 LoadAnimation::SwordManIdle().Load());
	core->animator->AddAnimation("Walk",						 LoadAnimation::SwordManWalk().Load());
	core->animator->AddAnimation("Run",							 LoadAnimation::SwordManRun().Load());
	core->animator->AddAnimation("Jump",						 LoadAnimation::SwordManJump().Load());
	core->animator->AddAnimation("Hit",							 LoadAnimation::SwordManHit().Load());
	core->animator->AddAnimation("Win",							 LoadAnimation::SwordManWin().Load());
	core->animator->AddAnimation("Guard",						 LoadAnimation::SwordManGuard().Load());
	core->animator->AddAnimation("BasicAttack1",				 LoadAnimation::SwordManBasicAttack1().Load());
	core->animator->AddAnimation("BasicAttack2",				 LoadAnimation::SwordManBasicAttack2().Load());
	core->animator->AddAnimation("BasicAttack3",				 LoadAnimation::SwordManBasicAttack3().Load());
	core->animator->AddAnimation("DashAttack",					 LoadAnimation::SwordManDashAttack().Load());
	core->animator->AddAnimation("JumpAttack",					 LoadAnimation::SwordManJumpAttack().Load());
	core->animator->AddAnimation("Attack1",						 LoadAnimation::SwordManAttack1().Load());
	core->animator->AddAnimation("Attack2",						 LoadAnimation::SwordManAttack2().Load());
	core->animator->AddAnimation("Attack3",						 LoadAnimation::SwordManAttack3().Load());
	core->animator->ChangeAnimation("Idle");
	core->aniOffset = { 40.f, -90.f };
	core->animator->renderOffset = { 40.f, -80.f };
	core->animator->centerOffset = { 20.f, 0.f };

	core->fsm->AddState<FSM::SwordManIdle>("Idle");
	core->fsm->AddState<FSM::CharactorWalk>("Walk");
	core->fsm->AddState<FSM::CharactorRun>("Run");
	core->fsm->AddState<FSM::CharactorHit>("Hit");
	core->fsm->AddState<FSM::SwordManJump>("Jump");
	core->fsm->AddState<FSM::SwordManBackStep>("BackStep");
	core->fsm->AddState<FSM::CharactorDie>("Die");
	core->fsm->AddState<FSM::CharactorWin>("Win");
	core->fsm->AddState<FSM::SwordManGuard>("Guard");
	core->fsm->AddState<FSM::SwordManBasicAttack1>("BasicAttack1");
	core->fsm->AddState<FSM::SwordManBasicAttack2>("BasicAttack2");
	core->fsm->AddState<FSM::SwordManBasicAttack3>("BasicAttack3");
	core->fsm->AddState<FSM::SwordManDashAttack>("DashAttack");
	core->fsm->AddState<FSM::SwordManJumpAttack>("JumpAttack");
	core->fsm->AddState<FSM::SwordManUpperSlash>("Upper");
	core->fsm->AddState<FSM::SwordManHardAttack>("HardAttack");
	core->fsm->AddState<FSM::SwordManVaneSlash>("VaneSlash");

	core->skillList.resize(LoadSprite::SwordManSkillIcon()._data.cut_by_grid.x);

	AddSkill(LoadSkill::Guard().Load());
	AddSkill(LoadSkill::BackStepCutter().Load());
	AddSkill(LoadSkill::UpperSlash().Load());
	AddSkill(LoadSkill::HardAttack().Load());
	AddSkill(LoadSkill::VaneSlash().Load());

	core->skillSlot[0] = core->skillList[LoadSkill::Guard().id];
	core->skillSlot[1] = core->skillList[LoadSkill::HardAttack().id];
	core->skillSlot[2] = core->skillList[LoadSkill::VaneSlash().id];

}

void SwordMan::Release()
{
	for (SkillInfo*& skillInfo : core->skillSlot)
	{
		delete skillInfo;
		skillInfo = nullptr;
	}

}
