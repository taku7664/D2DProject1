#include "CharactorWin.h"
#include "Contents.h"
#include "../CharactorCore.h"
#include "../../UI/PVPUI/ResultUI.h"
void FSM::CharactorWin::StateEnter()
{
	owner->animator->ChangeAnimation("Win", false);
	owner->state = CharactorState::Win;
	owner->soundPlayer->Play("Win");
}

void FSM::CharactorWin::StateUpdate()
{
	if (owner->animator->End())
	{
		GameMode::curState = GameProcess::Result;
		owner->CreateObject<Actor>("Result_UI", LayerTag::UI, ObjectTag::UI)
			->AddComponent<PVPUI::ResultUI>();
		FSM->ChangeState("Idle");
	}
}

void FSM::CharactorWin::StateExit()
{

}
