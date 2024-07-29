#include "../Component.h"

class LineRenderer 
	: public Component
{
public:

	LineRenderer();
	~LineRenderer();

	void SetLineColor(D2D1_COLOR_F _color);

	virtual bool Draw(Camera2D* _camera) final;

	float lineWidth = 1.0f;
	float alpha = 1.0f;
	Vector2 startPos;	 // 시작지점	
	Vector2 endPos;		 // 끝지점

private:

	D2D1_COLOR_F m_linecolor; // 선 색깔

};
