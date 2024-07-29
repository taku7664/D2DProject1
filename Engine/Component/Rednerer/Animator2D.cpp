#include "pch.h"
#include "Animator2D.h"
#include "../../World/Object/Actor/Actor.h"
#include "../Camera2D.h"
#include "../Transform2D.h"
#include "../../Render/D2DRender.h"

Animator2D::Animator2D()
	: m_activeAnimation(nullptr),
	currentFrame(0),
	isLoop(true),
	isStop(false),
	frameCount(0)
{
	m_type = ComponentType::Animator2D;
}

Animator2D::~Animator2D()
{
}

void Animator2D::Update()
{
	enterFrame = -1;
	if (m_activeAnimation)
	{
		if (!isStop)
		{
			// duration보다 크면
			if (frameCount > m_activeAnimation->GetFrameData()[currentFrame].duration)
			{
				while (frameCount > m_activeAnimation->GetFrameData()[currentFrame].duration)
				{
					if (End())
					{
						if (isLoop)
						{
							frameCount -= m_activeAnimation->GetFrameData()[currentFrame].duration;
							GotoAndPlay(0);
						}
						else
						{
							break;
						}
					}
					else if (!End())
					{
						frameCount -= m_activeAnimation->GetFrameData()[currentFrame].duration;
						currentFrame++;
						enterFrame = currentFrame;
						FiniteStateMachine* fsm = gameObject->GetComponent<FiniteStateMachine>();
						if (fsm) fsm->GetCurrentState()->OnAnimationEnter(currentFrame);
					}
				}
			}
			frameCount += Time::deltaTime * countScale;
		}
	}
}

bool Animator2D::Draw(Camera2D* _camera)
{
	
	if (!m_activeAnimation) return false;

	AnimationData& data = m_activeAnimation->GetFrameData()[currentFrame];
	size.x = m_activeAnimation->GetSprite(data.index)->GetSize().width;
	size.y = m_activeAnimation->GetSprite(data.index)->GetSize().height;
	
	ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();

	renderTarget->SetTransform(CalCulateMatrix(_camera));

	D2D1_RECT_F dstRect = D2D1::RectF(
		renderOffset.x + data.offset.x,  renderOffset.y + data.offset.y,
		renderOffset.x + data.offset.x + size.x,
		renderOffset.y + data.offset.y + size.y );

	renderTarget->DrawBitmap(
		m_activeAnimation->GetSprite(data.index), dstRect, alpha);

	if (Debug::IsActive())
	{
		ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
		D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
		float oldAlpha = brush->GetOpacity(); // 기존 색상 저장

		// 외곽선 출력
		brush->SetColor(D2D1::ColorF(D2D1::ColorF::Red));
		brush->SetOpacity(0.5f);
		renderTarget->DrawRectangle(dstRect, brush, 0.5f);
		// 중심점 출력
		renderTarget->DrawLine(
			D2D1::Point2F(dstRect.left, center.y),
			D2D1::Point2F(dstRect.right, center.y), brush);
		renderTarget->DrawLine(
			D2D1::Point2F(center.x, dstRect.top),
			D2D1::Point2F(center.x, dstRect.bottom), brush);

		brush->SetColor(oldColor); // 기존 색상 돌려놓기
		brush->SetOpacity(oldAlpha);
	}

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	return true;
}

void Animator2D::AddAnimation(std::string _key, Resource::Animation2D* _ani)
{
	if (_ani == nullptr)
		assert(false);

	if (this->FindAnimation(_key) != nullptr)
		return;

	m_animationList.insert(std::make_pair(_key, _ani));
}

Resource::Animation2D* Animator2D::FindAnimation(const std::string& _key)
{
	auto it = m_animationList.find(_key);
	if (it == m_animationList.end())
		return nullptr;
	return it->second;
}

void Animator2D::ChangeAnimation(const std::string& _key, bool _loop)
{
	Resource::Animation2D* _ani = FindAnimation(_key);
	if (_ani == nullptr)
		assert(false);
	if (_ani == m_activeAnimation)
		return;

	isLoop = _loop;
	currentFrame = 0;
	frameCount = 0.f;
	isStop = false;
	m_activeAnimation = _ani;
}

void Animator2D::GotoAndPlay(int _val)
{
	if (m_activeAnimation)
	{
		this->currentFrame = _val;
		this->isStop = false;
	}
}

void Animator2D::GotoAndStop(int _val)
{
	if (m_activeAnimation)
	{
		this->currentFrame = _val;
		this->isStop = true;
	}
}

void Animator2D::Play()
{
	if (m_activeAnimation)
		this->isStop = false;
}

void Animator2D::Stop()
{
	if (m_activeAnimation)
		this->isStop = true;
}

bool Animator2D::End()
{
	if (!m_activeAnimation) return false;
	else return (currentFrame >= m_activeAnimation->GetFrameData().size() - 1) && frameCount >= m_activeAnimation->GetFrameData()[currentFrame].duration;
}

int Animator2D::FrameSize()
{
	return m_activeAnimation->GetFrameData().size();
}

bool Animator2D::IndexEnter(int _index)
{
	return _index == enterFrame;
}
