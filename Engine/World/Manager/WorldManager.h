#pragma once
#include "../World.h"

class WorldManager
{
public:

	static void Release();

	static void FixedUpdate();
	static void EarlyUpdate();
	static void Update();
	static void LateUpdate();
	static void StateUpdate();
	static void Render();

	// World�� �߰��� �� World* Ÿ���� ��ȯ�մϴ�.
	template <typename T>
	static T* CreateWorld(std::string _key, WorldTag _tag)
	{
		T* _world = new T();
		if (!m_activeWorld) m_activeWorld = _world;
		_world->SetName(_key);
		_world->SetTag(_tag);
		_world->WorldLoad();
		m_worldList[(int)_tag].push_back(_world);
		return _world;
	}
	// World�� �˻��մϴ�.
	static World* FindWorld(std::string _key, WorldTag _tag = WorldTag::Default)
	{
		for (int i = (int)_tag; i < (int)WorldTag::SIZE; i++)
		{
			for (int j = 0; j < m_worldList[i].size(); j++)
			{
				if (m_worldList[i][j]->GetName() == _key)
					return m_worldList[i][j];
			}
		}
		return nullptr;
	}
	// �ش� World�� �����մϴ�.
	static bool DestroyWorld(std::string _key, WorldTag _tag = WorldTag::Default)
	{
		for (int i = (int)_tag; i < (int)WorldTag::SIZE; i++)
		{
			for (int j = 0; j < m_worldList[i].size(); j++)
			{
				if (m_worldList[i][j]->GetName() == _key)
				{
					m_DestroyWorld.push_back(m_worldList[i][j]);
					m_worldList[i].erase(m_worldList[i].begin() + j);
					return true;
				}
			}
		}
		return false;
	}

	static bool ChangeWorld(World* _world);
	static bool ChangeWorld(std::string _key, WorldTag _tag = WorldTag::Default);

	static World* GetActiveWorld() { return m_activeWorld; }
	static std::vector<World*>& GetWorldList(WorldTag _tag) { return m_worldList[(int)_tag]; }

private:

	static World* m_activeWorld;
	static World* m_loadWorld;
	static std::vector<World*> m_worldList[(int)LayerTag::SIZE];
	static std::vector<World*> m_DestroyWorld;

	static void LoadProcess();
};

