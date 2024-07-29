#include "UpperHUD.h"
#include "System/GameMode.h"
#include "Data/Resource/LoadSpriteData.h"
#include "Script/Object/Charactor/CharactorCore.h"

void HUD::UpperHUD::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::PlayerUpperHUD().Load());
	uiSprite->renderOffset = Vector2(100, 30);
	gameObject->transform->position = Vector2(0, 0);

	Actor* ui;
	ui = CreateObject<Actor>("Head", LayerTag::UI, ObjectTag::UI);
	ui->transform->SetParent(gameObject->transform);
	ui->transform->position = Vector2(10, 30);
	ui->depthsLevel = 5;
	head = ui->AddComponent<SpriteRenderer2D>();
	head->SetSprite(LoadSprite::HeadSheet().Load());
	head->centerOffset = Vector2(-head->size.x * 0.5f, 0.f);

	ui = CreateObject<Actor>("HPBar", LayerTag::UI, ObjectTag::UI);
	ui->transform->SetParent(gameObject->transform);
	ui->transform->position = Vector2(51, 33);
	ui->depthsLevel = 5;
	hpBar = ui->AddComponent<SpriteRenderer2D>();
	hpBar->SetSprite(LoadSprite::HPBar().Load());
	hpBar->centerOffset = Vector2(-hpBar->size.x * 0.5f, 0.f);

	ui = CreateObject<Actor>("MPBar", LayerTag::UI, ObjectTag::UI);
	ui->transform->SetParent(gameObject->transform);
	ui->transform->position = Vector2(51, 40);
	ui->depthsLevel = 5;
	mpBar = ui->AddComponent<SpriteRenderer2D>();
	mpBar->SetSprite(LoadSprite::MPBar().Load());
	mpBar->centerOffset = Vector2(-mpBar->size.x * 0.5f, 0.f);

	for (int i = 0; i < 20; i++)
	{
		Actor* ui = CreateObject<Actor>(
			"HUDCoolBar" + std::to_string(i),
			LayerTag::UI, ObjectTag::UI);
		ui->SetPersistent(true);
		ui->transform->SetParent(gameObject->transform);
		ui->transform->position = Vector2(20 + ((i % 7) * 25), 60 + ((i / 7) * 25));
		ui->transform->scale = Vector2(0.7f, 0.7f);
		coolBar[i] = ui->AddComponent<SkillCoolHUD>();
		coolBar[i]->id = i;
		coolBar[i]->owner = this;
	}
}

void HUD::UpperHUD::Update()
{
	if (targetObject)
	{
		hpBar->gameObject->transform->scale.x = MathF.Lerp<float>(
			hpBar->gameObject->transform->scale.x,
			(float)targetObject->hp._cur / (float)targetObject->hp._max,
			7 * Time::deltaTime);
		mpBar->gameObject->transform->scale.x = MathF.Lerp<float>(
			mpBar->gameObject->transform->scale.x,
			(float)targetObject->mp._cur / (float)targetObject->mp._max,
			7 * Time::deltaTime);
		for (auto sk : coolBar)
		{
			if (sk->id < targetObject->skillList.size() && targetObject->skillList[sk->id])
			{
				sk->gameObject->SetActive(true);
				sk->uiSprite->index = targetObject->skillList[sk->id]->id;
				sk->coolBar->size.y = sk->uiSprite->size.y *
					(1.f - targetObject->skillList[sk->id]->coolCount /
						targetObject->skillList[sk->id]->data.coolTime);
				sk->coolBar->renderOffset.y = sk->uiSprite->size.y / 2 - sk->coolBar->size.y / 2;
			}
			else
			{
				sk->gameObject->SetActive(false);
			}
		}
	}
}

void HUD::UpperHUD::OnEnable()
{
	hpBar->gameObject->SetActive(true);
	mpBar->gameObject->SetActive(true);
	head->gameObject->SetActive(true);
	for (auto sk : coolBar)
		sk->gameObject->SetActive(true);
}

void HUD::UpperHUD::OnDisable()
{
	hpBar->gameObject->SetActive(false);
	mpBar->gameObject->SetActive(false);
	head->gameObject->SetActive(false);
	for (auto sk : coolBar)
		sk->gameObject->SetActive(false);
}
