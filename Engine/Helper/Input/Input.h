#pragma once

using namespace std;

struct KeyState {
	bool IsDown = false;
	bool IsHold = false;
	bool IsUp = false;
};

struct MouseState {
	bool Left = false;
	bool Right = false;
	bool Mid = false;
};


class Key
{
private:

	static std::vector<short> KeyDown_Reset;
	static std::vector<short> KeyUp_Reset;

	static float Horizontal_Axis;
	static float Vertical_Axis;
	static int Horizontal_AxisRaw;
	static int Vertical_AxisRaw;
	static KeyState Key_Code[256];

	static void Axis();
	static void AxisRaw();

public:

	static void GetKey(UINT _msg, WPARAM _wParam);
	static void Update();
	static void ResetKey();

	// 키보드가 눌렸는지 확인합니다.
	static bool KeyDown(int _code);
	static bool KeyDown(char _code);
	static bool KeyDown(KeyType _code);
	// 키보드가 누르고 있는 중인지 확인합니다.
	static bool KeyHold(int _code);
	static bool KeyHold(char _code);
	static bool KeyHold(KeyType _code);
	// 키보드를 뗐는지 확인합니다.
	static bool KeyUp(int _code);
	static bool KeyUp(char _code);
	static bool KeyUp(KeyType _code);

	static float GetAxis(string _dir);
	static int GetAxisRaw(string _dir);

	static void SetAxis(string _dir, float value);
	static void SetAxisRaw(string _dir, int value);

};

class Mouse
{
private:

	static MouseState Cur_Mouse;
	static MouseState Pre_Mouse;

public:

	static Vector2 mousePosition;

	static void Update();

	static bool MouseDown(MouseType _code);
	static bool MouseHold(MouseType _code);
	static bool MouseUp(MouseType _code);
};
