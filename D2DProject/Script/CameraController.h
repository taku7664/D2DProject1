#include "DemoApp.h"

class CameraController 
	: public Script
{
public:
	// ī�޶� ������Ʈ
	Camera2D* myCamera;
	// ī�޶� ���� ����
	Rect_F limitRange;
	// ��Ŀ�� ������Ʈ
	Actor* targetActor;
	// ī�޶� �ɼ�
	Vector2 offset = Vector2(0, 0);
	// ī�޶� ���ǵ�
	float moveSpd = 7.f;

	// ȭ�� ����
	bool isShaking;
	float shakePower;
	Vector2 shakePos;

	void Start();
	void Update();
	void FixedUpdate();

	void SetShake(bool _status, float _power = 1.f);
	void Shaking();
};