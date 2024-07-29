#pragma once
#include "Component.h"

class Transform2D;
class Object;

class Camera2D
	: public Component
{
public:

    Camera2D();
    virtual ~Camera2D();

    virtual void Initialize()final;
    virtual void LateUpdate()final;
    virtual void Render()final;

    void         SetLayerCulling(LayerTag _type, bool _isculling) { m_cullingLayer[(int)_type] = _isculling; }
    void         SetObjectTagCulling(ObjectTag _tag, bool _isculling) { m_cullingTag[(int)_tag] = _isculling; }
    void         SetBackGroundColor(D2D1_COLOR_F _color) { m_BackGroundColor = _color; }

    ID2D1BitmapRenderTarget* GetBitmapRenderTarget() { return m_bitmapRenderTarget; }
    D2D1_MATRIX_3X2_F CameraMatrix();               // 카메라 행렬
    Vector2 ScreenSize();                           // 카메라 화면 크기 (걍 윈도우 사이즈임)
    Vector2 ScreenPosition(Transform2D* _dest);     // 스크린 좌표계
    Vector2 ViewportPosition(Transform2D* _dest);   // 스크린좌표계를 정규화해서 나타냄.

    Vector2 viewRectPosition;   // 화면에 배치할 카메라 위치
    D2D_SIZE_F viewportSize;    // 화면에 배치할 카메라 사이즈

private:

    bool                        m_cullingLayer[(int)LayerTag::SIZE]{ false, };  // true일 시 렌더링에서 제외한다.
    bool                        m_cullingTag[(int)ObjectTag::SIZE]{ false, };   // true일 시 렌더링에서 제외한다.
    D2D1_COLOR_F                m_BackGroundColor;                              // 카메라 렌더타겟 Clear색깔
    ID2D1BitmapRenderTarget*    m_bitmapRenderTarget;                           // 카메라의 고유 렌더타겟
    ID2D1Bitmap*                m_bitmap;                                       // 렌더타겟을 비트맵으로 바꾸기 위해

};

