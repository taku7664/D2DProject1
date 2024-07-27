#pragma once

class FiniteStateMachine;

class FSMState abstract
{
private:
public:
	FiniteStateMachine* FSM;

	virtual void Start() {}
	virtual void StateEnter() = 0;
	virtual void StateUpdate() = 0;
	virtual void StateExit() = 0;

	virtual void OnAnimationEnter(int _index) {}
};

template<typename T>
class Template_FSMState : public FSMState
{
private:
public:
	T* owner;
};