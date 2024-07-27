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

	// Ű���尡 ���ȴ��� Ȯ���մϴ�.
	static bool KeyDown(int handle, int _code);
	static bool KeyDown(int handle, char _code);
	// Ű���尡 ������ �ִ� ������ Ȯ���մϴ�.
	static bool KeyHold(int handle, int _code);
	static bool KeyHold(int handle, char _code);
	// Ű���带 �ô��� Ȯ���մϴ�.
	static bool KeyUp(int handle, int _code);
	static bool KeyUp(int handle, char _code);

private:

	static std::unordered_map<HANDLE, Keys> m_Keyboards;
	static std::vector<HANDLE> m_hTable; // �ڵ� ���̺�
};