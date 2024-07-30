#pragma once

class FiniteStateMachine;

class FSMState abstract
{
private:

	std::string m_name;

public:

	FiniteStateMachine* FSM;

	virtual void Start() {}				// 추가할 때 호출되는 함수
	virtual void StateEnter() = 0;		// 상태에 진입할 때 한번 호출되는 함수
	virtual void StateUpdate() = 0;		// 상태가 지속중일 때 매 업데이트마다 호출되는 함수
	virtual void StateExit() = 0;		// 상태를 벗어날 때 한번 호출되는 함수

	virtual void OnAnimationEnter(int _index) {}

	void SetName(const std::string& _name) { m_name = _name; }
	std::string GetName() const { return m_name; }
};

// owner를 편하게 쓰기 위해서 사용하는 함수
template<typename T>
class Template_FSMState : public FSMState
{
private:
public: T* owner;
};