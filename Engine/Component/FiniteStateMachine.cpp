#include "pch.h"
#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine()
	: m_stateMap(),
	m_curState(nullptr),
	m_preState(nullptr)
{
	m_type = ComponentType::FiniteStateMachine;
}

FiniteStateMachine::~FiniteStateMachine()
{
    for (auto& state : m_stateMap)
    {
        delete state.second;
    }
    m_stateMap.clear();
}

void FiniteStateMachine::Update()
{
    if (m_curState)
    {
        // �������¿� ������°� ������
        if (m_preState == m_curState)
        {
            m_curState->StateUpdate();
        }
        else
        {
            // �ٸ��� ���������� Exit, ���� ������ Enter�� ȣ��
            m_preState->StateExit();
            m_curState->StateEnter();
            m_preState = m_curState;
        }
    }
}

void FiniteStateMachine::ChangeState(std::string _key)
{
    auto it = m_stateMap.find(_key);
    if (it == m_stateMap.end())
        return;
    m_curState = it->second;
}
