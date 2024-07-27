#pragma once

class Rect_F
{
public:
	float left;
	float top;
	float right;
	float bottom;

	Rect_F() : left(0.f), top(0.f), right(0.f), bottom(0.f) {}
	// 오버로딩된 생성자
	Rect_F(float _left, float _top = 0.f, float _right = 0.f, float _bottom = 0.f)
		: left(_left), top(_top), right(_right), bottom(_bottom) {}
	Rect_F(int _left, int _top = 0.f, int _right = 0.f, int _bottom = 0.f)
		: left((float)_left), top((float)_top), right((float)_right), bottom((float)_bottom) {}
	Rect_F(long _left, long _top = 0.f, long _right = 0.f, long _bottom = 0.f)
		: left((float)_left), top((float)_top), right((float)_right), bottom((float)_bottom) {}

	float Width()
	{
		return right - left;
	}
	float Height()
	{
		return bottom - top;
	}
	Vector2 Center()
	{
		return Vector2(Width() / 2, Height() / 2);
	}
	
	Rect_F& operator+=(const Rect_F& _val)
	{
		left	+= _val.left;
		top		+= _val.top;
		right	+= _val.right;
		bottom	+= _val.bottom;
		return *this;
	}
	Rect_F& operator-=(const Rect_F& _val)
	{
		left	-= _val.left;
		top		-= _val.top;
		right	-= _val.right;
		bottom	-= _val.bottom;
		return *this;
	}
	Rect_F& operator*=(const Rect_F& _val)
	{
		left	*= _val.left;
		top		*= _val.top;
		right	*= _val.right;
		bottom	*= _val.bottom;
		return *this;
	}
	Rect_F& operator/=(const Rect_F& _val)
	{
		left	/= _val.left;
		top		/= _val.top;
		right	/= _val.right;
		bottom	/= _val.bottom;
		return *this;
	}
	Rect_F operator+(const Rect_F& _val)
	{
		return Rect_F(
			left  + _val.left,
			top   + _val.top,
			right + _val.right,
			bottom  + _val.bottom);
	}
	Rect_F operator-(const Rect_F& _val)
	{
		return Rect_F(
			left  - _val.left,
			top   - _val.top,
			right - _val.right,
			bottom  - _val.bottom);
	}
	Rect_F operator*(const Rect_F& _val)
	{
		return Rect_F(
			left  * _val.left,
			top   * _val.top,
			right * _val.right,
			bottom  * _val.bottom);
	}
	Rect_F operator/(const Rect_F& _val)
	{
		return Rect_F(
			left  / _val.left,
			top   / _val.top,
			right / _val.right,
			bottom  / _val.bottom);
	}
	Rect_F& operator=(const Rect_F& _val)
	{
		left	= _val.left;
		top		= _val.top;
		right	= _val.right;
		bottom	= _val.bottom;
		return *this;
	}
	bool operator==(const Rect_F& _val)
	{
		return (
			left == _val.left &&
			top == _val.top &&
			right == _val.right &&
			bottom == _val.bottom);
	}
};

