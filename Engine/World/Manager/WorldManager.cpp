#include "pch.h"
#include "WorldManager.h"

World*				 WorldManager::m_activeWorld = nullptr;
World*				 WorldManager::m_loadWorld	 = nullptr;
std::vector<World*>  WorldManager::m_worldList[(int)LayerTag::SIZE]{};
std::vector<World*>  WorldManager::m_DestroyWorld{};

void WorldManager::Release()
{
	for (int i = 0; i < (int)LayerTag::SIZE; i++)
	{
		for (World* world : m_worldList[i])
		{
			delete world;
		}
	}
	World::Release();
}

void WorldManager::FixedUpdate()
{
	if (m_activeWorld)
		m_activeWorld->FixedUpdate();
}

void WorldManager::EarlyUpdate()
{
	if (m_activeWorld)
		m_activeWorld->EarlyUpdate();
}

void WorldManager::Update()
{
	if (m_activeWorld)
		m_activeWorld->Update();
}

void WorldManager::LateUpdate()
{
	if (m_activeWorld)
		m_activeWorld->LateUpdate();
}

void WorldManager::StateUpdate()
{
	if (m_activeWorld)
		m_activeWorld->StateUpdate();
}

void WorldManager::Render()
{
	if (m_activeWorld)
		m_activeWorld->Render();
	// load할 월드가 있으면 이때 바꿈
	if (m_loadWorld)
	{
		LoadProcess();
	}
	if (!m_DestroyWorld.empty())
	{
		for (World* world : m_DestroyWorld)
		{
			world->WorldDestroy();
			delete world;
		}
		m_DestroyWorld.clear();
	}
}

bool WorldManager::ChangeWorld(World* _world)
{
	if (_world == nullptr) return false;
	if (m_activeWorld == _world) return false;
	else
	{
		m_loadWorld = _world;
	}
}

bool WorldManager::ChangeWorld(std::string _key, WorldTag _tag)
{
	World* find = FindWorld(_key, _tag);
	bool check = ChangeWorld(find);
	return check;
}

void WorldManager::LoadProcess()
{
	if (m_activeWorld)
	{
		// Persistent객체를 옮겨준다.
		for (int i = 0; i < (int)LayerTag::SIZE; i++)
		{
			std::vector<Object*>& objList = m_activeWorld->GetLayerList()[i]->GetObjectList();
			for (auto iter = objList.begin(); iter != objList.end();)
			{
				if ((*iter)->IsPersistent())
				{
					m_loadWorld->GetLayerList()[i]->GetObjectList().push_back((*iter));
					iter = objList.erase(iter);
				}
				else
				{
					++iter;
				}
			}
		}
	}
	m_activeWorld->WorldExit();
	m_activeWorld = m_loadWorld;
	m_loadWorld = nullptr;
	m_activeWorld->WorldEnter();
}
