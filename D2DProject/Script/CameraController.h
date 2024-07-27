#include "DemoApp.h"

class CameraController 
	: public Script
{
public:
	// 카메라 컴포넌트
	Camera2D* myCamera;
	// 카메라 범위 제한
	Rect_F limitRange;
	// 포커싱 오브젝트
	Actor* targetActor;
	// 카메라 옵셋
	Vector2 offset = Vector2(0, 0);
	// 카메라 스피드
	float moveSpd = 7.f;

	// 화면 흔들기
	bool isShaking;
	float shakePower;
	Vector2 shakePos;

	void Start();
	void Update();
	void FixedUpdate();

	void SetShake(bool _status, float _power = 1.f);
	void Shaking();
};