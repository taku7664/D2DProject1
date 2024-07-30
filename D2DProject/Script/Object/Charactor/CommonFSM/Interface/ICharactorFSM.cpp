#include "ICharactorFSM.h"
#include "../../CharactorCore.h"

void ICharactorFSM::Start()
{
	owner = FSM->gameObject->GetComponent<CharactorCore>();
}

bool ICharactorFSM::CheckQuickKey(bool _isAttack)
{
	for (int i = 0; i < 12; i++)
	{
		if (owner->skillSlot[i])
		{
			// 여기 조건에 키입력 or 커맨드를 달면 될듯.
			if (owner->TriggerKeyDown(owner->input.QuickKey[i]))
			{
				if (owner->skillSlot[i]->CanUse())
				{
					if (!_isAttack || (_isAttack && owner->skillSlot[i]->data.cancelAble))
					{
						FSM->ChangeState(owner->skillSlot[i]->key);
						owner->skillSlot[i]->coolCount = 0.f;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool ICharactorFSM::ChangeState_To_AniEnd(const std::string& _fsmName)
{
	if (owner->animator->End())
	{
		FSM->ChangeState(_fsmName);
		return true;
	}
	return false;
}
