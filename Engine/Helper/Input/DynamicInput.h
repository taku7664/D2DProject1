#pragma once

struct Keys
{
	KeyState Key_Code[256];
	std::vector<int> KeyDown_Reset;
	std::vector<int> KeyUp_Reset;
};

class DynamicInput
{
public:

	static void Initialize(HINSTANCE _hinstance);

	static void Update() {}

	static void ResetKey();
	 
	static void GetKey(HRAWINPUT _hri);

	static int  GetKeyDeviceCount() { return m_hTable.size(); }

	// 키보드가 눌렸는지 확인합니다.
	static bool KeyDown(int handle, int _code);
	static bool KeyDown(int handle, char _code);
	// 키보드가 누르고 있는 중인지 확인합니다.
	static bool KeyHold(int handle, int _code);
	static bool KeyHold(int handle, char _code);
	// 키보드를 뗐는지 확인합니다.
	static bool KeyUp(int handle, int _code);
	static bool KeyUp(int handle, char _code);

private:

	static std::unordered_map<HANDLE, Keys> m_Keyboards;
	static std::vector<HANDLE> m_hTable; // 핸들 테이블
};