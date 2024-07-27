#include "pch.h"
#include "SpriteRenderer2D.h"
#include "../../Resource/Sprite2D.h"
#include "../../World/Object/Actor/Actor.h"
#include "../Camera2D.h"
#include "../Transform2D.h"
#include "../../Resource/Manager/ResourceManager.h"

SpriteRenderer2D::SpriteRenderer2D()
	: m_sprite(nullptr)
{
	m_type = ComponentType::SpriteRenderer2D;
}

SpriteRenderer2D::~SpriteRenderer2D()
{
}

bool SpriteRenderer2D::Draw(Camera2D* _camera)
{
	if (!m_sprite) assert(false);

	ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();

	renderTarget->SetTransform(CalCulateMatrix(_camera));

	renderTarget->DrawBitmap(m_sprite->GetSprite(index),
		{ renderOffset.x,  renderOffset.y,
		renderOffset.x + size.x,
		renderOffset.y + size.y },
		alpha);

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	return true;
}

void SpriteRenderer2D::SetSprite(std::wstring _key)
{
	SetSprite(ResourceManager::GetSprite2D(_key));
}
void SpriteRenderer2D::SetSprite(std::wstring _key, int _index)
{
	SetSprite(ResourceManager::GetSprite2D(_key), _index);
}
void SpriteRenderer2D::SetSprite(Resource::Sprite2D* _sprite)
{
	m_sprite = _sprite;
	size.x = m_sprite->GetSprite(index)->GetSize().width;
	size.y = m_sprite->GetSprite(index)->GetSize().height;
}

void SpriteRenderer2D::SetSprite(Resource::Sprite2D* _sprite, int _index)
{
	m_sprite = _sprite;
	index = _index;
	size.x = m_sprite->GetSprite(index)->GetSize().width;
	size.y = m_sprite->GetSprite(index)->GetSize().height;
}
