#include "CameraController.h"
#include "System/GameMode.h"
#include "Object/Charactor/CharactorCore.h"

void CameraController::Start()
{
	myCamera = gameObject->GetComponent<Camera2D>();
}

void CameraController::Update()
{
	Vector2 SetPos = Vector2::Zero;
	Vector2 SetSca = Vector2::One;
	if (targetActor)
	{
		SetPos = targetActor->transform->position + shakePos + offset;
	}
	else
	{
		if (!GameMode::playerList.empty())
		{
			Vector2 maxPos;
			Vector2 minPos = Vector2(9999.f, 9999.f);
			for (CharactorCore*& core : GameMode::playerList)
			{
				if (core->state == CharactorState::Die) continue;
				// 제일 작은 벡터와 큰 벡터 구하기
				if (core->gameObject->transform->position.x > maxPos.x) maxPos.x = core->gameObject->transform->position.x;
				if (core->gameObject->transform->position.x < minPos.x) minPos.x = core->gameObject->transform->position.x;
				if (core->gameObject->transform->position.y > maxPos.y) minPos.y = core->gameObject->transform->position.y;
				if (core->gameObject->transform->position.y < minPos.y) minPos.y = core->gameObject->transform->position.y;
			}
			// 포지션 조정
			// 최대값과 최소값 합의 중앙
			SetPos = (maxPos + minPos) / 2;
			// 화면 스케일 조정
			// 최대와 최소값 차이가 스크린사이즈보다 크면 스케일 조정
			if (maxPos.x - minPos.x > GameApp::GetScreenSize().x * 0.8f)
			{
				SetSca.x = (maxPos.x - minPos.x) / (GameApp::GetScreenSize().x * 0.8f);
				SetSca.y = SetSca.x;
			}
			if (maxPos.y - minPos.y > GameApp::GetScreenSize().y * 0.8f)
			{
				SetSca.x = (maxPos.y - minPos.y) / (GameApp::GetScreenSize().y * 0.8f);
				SetSca.y = SetSca.x;
			}
			SetSca -= (float)GameMode::isEnd * 0.5f;
		}
	}
	gameObject->transform->position =
		MathF.Lerp<Vector2>(gameObject->transform->position,
			SetPos, moveSpd * Time::deltaTime);

	Vector2 oldScale = gameObject->transform->scale;

	gameObject->transform->scale =
		MathF.Lerp<Vector2>(gameObject->transform->scale,
			SetSca, moveSpd * Time::deltaTime);

	if (limitRange.left != 0 && limitRange.right != 0)
	{
		Vector2 screenSize = myCamera->ScreenSize() * gameObject->transform->scale;
		float clampX = MathF.Clamp<float>(gameObject->transform->position.x
			, limitRange.left + screenSize.x / 2, limitRange.right - screenSize.x / 2);
		/*float clampY = MathF.Clamp<float>(gameObject->transform->position.y
			, limitRange.top + screenSize.y / 2, limitRange.bottom - screenSize.y / 2);*/

		gameObject->transform->position.x = clampX;
		//gameObject->transform->position.y = clampY;
		if (clampX == limitRange.left + screenSize.x / 2 ||
			clampX == limitRange.right - screenSize.x / 2)
		{
			gameObject->transform->scale = oldScale;
		}
	}
	
}

void CameraController::FixedUpdate()
{
	if (isShaking) 
		Shaking();
}

void CameraController::SetShake(bool _status, float _power)
{
	isShaking = _status;
	shakePower = _power;
}

void CameraController::Shaking()
{
	shakePos.x = (float)(rand() % 100 + 1) - 50;
	shakePos.y = (float)(rand() % 100 + 1) - 50;
	shakePos *= shakePower;
}

