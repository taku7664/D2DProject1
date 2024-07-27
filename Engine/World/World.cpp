#include "pch.h"
#include "World.h"


World::World()
    : m_WorldTag(WorldTag::Default)
{

    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        m_layers[i] = new Layer((LayerTag)i);
    }

    // 메인카메라 생성
    Actor* camera = CreateObject<Actor>("MainCamera", LayerTag::Defalut, ObjectTag::Camera);
    camera->AddComponent<Camera2D>();
}

World::~World()
{
    for (Layer* layer : m_layers)
    {
        delete layer;
    }
}

void World::Release()
{
}

void World::FixedUpdate()
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        if (m_layers[i]) 
            m_layers[i]->FixedUpdate();
    }
}

void World::EarlyUpdate()
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        if (m_layers[i])
            m_layers[i]->EarlyUpdate();
    }
}

void World::Update()
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        if (m_layers[i])
            m_layers[i]->Update();
    }
}

void World::LateUpdate()
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        if (m_layers[i])
            m_layers[i]->LateUpdate();
    }
}

void World::StateUpdate()
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        if (m_layers[i])
            m_layers[i]->StateUpdate();
    }
}

void World::Render()
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        if (m_layers[i])
            m_layers[i]->Render();
    }
}

void World::Clear(bool _isAll)
{
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        for (Object* obj : GetLayerList()[i]->GetObjectList())
        {
            if ((!_isAll && !obj->IsPersistent()) || _isAll)
            {
                delete obj;
            }
        }
        GetLayerList()[i]->GetObjectList().clear();
    }
}