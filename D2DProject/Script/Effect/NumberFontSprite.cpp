#include "NumberFontSprite.h"

void NumberFontSprite::Start()
{

}

void NumberFontSprite::Update()
{
	count += Time::deltaTime;
	
	if (count >= 0.4f)
	{
		gameObject->transform->position.y -= 50 * Time::deltaTime * (1.f + count * 2);
		for (SpriteRenderer2D* sp : spriteArr)
		{
			sp->alpha -= sp->alpha * 10.f * Time::deltaTime;
		}
	}
	else
	{
		gameObject->transform->position.y -= 30 * Time::deltaTime;
	}
	if (spriteArr.front()->alpha <= 0.1f)
	{
		Destroy(gameObject);
	}
}

void NumberFontSprite::Set(int _type, int _number)
{
	Resource::Sprite2D* image = ResourceManager::GetSprite2D(L"DamageFont" + std::to_wstring(_type));
	std::vector<int> arr;
	while (true)
	{
		int temp = _number % 10;
		_number /= 10;
		arr.push_back(temp);
		if (_number == 0) break;
	}
	int size = image->GetSprite()->GetSize().width * 0.7;
	for (int i = 0; i < arr.size(); i++)
	{
		SpriteRenderer2D* sprite = gameObject->AddComponent<SpriteRenderer2D>();
		sprite->SetSprite(image, arr[arr.size() - i - 1]);
		sprite->renderOffset.x = (i * size);
		sprite->renderOffset.x - ((arr.size() / 2) * size);
		spriteArr.push_back(sprite);
	}
}