#pragma once
#include "Renderer.h"


class RectRenderer
	: public Renderer
{
public:

	RectRenderer();
	virtual ~RectRenderer();

	virtual bool Draw(Camera2D* _camera) final;

	void SetLineColor(D2D1_COLOR_F _color);
	void SetFillColor(D2D1_COLOR_F _color);
	void SetLine(bool _val);
	void SetFill(bool _val);

	float lineWidth;  // 외곽선 두께

private:

	D2D1_COLOR_F m_linecolor; // 선
	D2D1_COLOR_F m_fillcolor; // 채우기
	bool isFill;			  // 채우기 여부	
	bool isLine;			  // 외곽선 여부
};

