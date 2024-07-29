#pragma once
#include "Component.h"
#include "../FSMState/FSMState.h"

class Actor;

class FiniteStateMachine
	: public Component
{
public:

    FiniteStateMachine();
    virtual ~FiniteStateMachine();

	virtual void Update();

	template<typename T>
	void AddState(const std::string& _key)
	{
		T* state = new T();
		state->FSM = this;
 		state->Start();
		if (m_stateMap.empty())
			m_curState = m_preState = state;
		m_stateMap.insert(std::make_pair(_key, state));
	}
    template<typename T>
    T* GetState(const std::string& _key)
    {
        auto it = m_stateMap.find(_key);
        if (it != m_stateMap.end())
        {
            T* result = dynamic_cast<T*>(it->second);
            if (result) return result;
        }
        return nullptr;
    }

    template<typename T>
    T* ChangeStateAndReturn(std::string _key)
    {
        auto it = m_stateMap.find(_key);
        if (it == m_stateMap.end())
            return nullptr;
        m_curState = it->second;
        return dynamic_cast<T*>(m_curState);
    }

	void ChangeState(std::string _key);

	FSMState* GetCurrentState() { return m_curState; }

private:

    std::map<std::string, FSMState*> m_stateMap;
    FSMState* m_curState = nullptr;
    FSMState* m_preState = nullptr;

};

