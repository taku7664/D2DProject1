#include "../Component.h"

class LineRenderer 
	: public Component
{
public:

	LineRenderer();
	virtual ~LineRenderer() {}

	void SetLineColor(D2D1_COLOR_F _color);

	virtual bool Draw(Camera2D* _camera) final;

	float lineWidth = 1.0f;
	float alpha = 1.0f;
	Vector2 startPos;	 // ��������	
	Vector2 endPos;		 // ������

private:

	D2D1_COLOR_F m_linecolor; // �� ����

};
