#include "Renderer.h"

class LineRenderer : public Component
{
public:

	LineRenderer();
	~LineRenderer();

	void SetLineColor(D2D1_COLOR_F _color);

	void SetLinePosition(Vector2 _startPos, Vector2 _endPos);
	void SetStartPosition(Vector2 _startpos);
	void SetEndPosition(Vector2 _endPos);

	virtual bool Draw(Camera2D* _camera) final;

	float lineWidth = 1.0f;
	float alpha = 1.0f;

private:

	D2D1_COLOR_F m_linecolor; // 선 색깔

	Vector2 m_startPos;	 // 시작지점	
	Vector2 m_endPos;	 // 끝지점

};
