#pragma once

class ISoundSystem
{
public:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void SetGroup(int _num) = 0;

private:

};

