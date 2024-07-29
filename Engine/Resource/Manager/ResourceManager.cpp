#include "pch.h"
#include "ResourceManager.h"

std::wstring ResourceManager::m_assetPath = L"Asset/";
std::unordered_map<std::wstring, Resource::Sprite2D*> ResourceManager::m_spriteMap;
std::unordered_map<std::wstring, Resource::Animation2D*> ResourceManager::m_animationMap;
std::unordered_map<std::wstring, Resource::FMODSound*> ResourceManager::m_audioMap;

Resource::Sprite2D* ResourceManager::AddSprite2D(const std::wstring& _key, const std::wstring& _path, SpriteData _data)
{
	std::wstring temp = m_assetPath + _path;
	Resource::Sprite2D* _sprite = GetSprite2D(_key);
	if (_sprite != nullptr)
	{
		return _sprite;
	}
	else
	{
		_sprite = new Resource::Sprite2D(_key, temp, ResourceType::Sprite2D, _data);
		m_spriteMap.insert(std::make_pair(_key, _sprite));
	}
	return _sprite;
}

Resource::Animation2D* ResourceManager::AddAnimation2D(const std::wstring& _key, Resource::Sprite2D* _sprite, std::vector<AnimationData>& _data)
{
	Resource::Animation2D* _anime = GetAnimation2D(_key);
	if (_anime != nullptr)
	{
		return _anime;
	}
	else
	{
		_anime = new Resource::Animation2D(_key, ResourceType::Animation2D, _sprite, _data);
		m_animationMap.insert(std::make_pair(_key, _anime));
	}
	return _anime;
}

Resource::FMODSound* ResourceManager::AddFMODSound(const std::wstring& _key, const std::wstring& _path, bool isLoop, int _group)
{
	std::wstring temp = L"Asset/" + _path;
	Resource::FMODSound* _audio = GetFMODSound(_key);
	if (_audio != nullptr)
	{
		return _audio;
	}
	else
	{
		_audio = new Resource::FMODSound(_key, temp, ResourceType::AudioClip, isLoop, _group);
		m_audioMap.insert(std::make_pair(_key, _audio));
	}
	return _audio;
}

Resource::Sprite2D* ResourceManager::GetSprite2D(const std::wstring& _key)
{
	auto it = m_spriteMap.find(_key);

	if (it == m_spriteMap.end())
		return nullptr;

	return it->second;
}

Resource::Animation2D* ResourceManager::GetAnimation2D(const std::wstring& _key)
{
	std::unordered_map<std::wstring, Resource::Animation2D*>::iterator it = m_animationMap.find(_key);

	if (it == m_animationMap.end())
		return nullptr;

	return it->second;
}

Resource::FMODSound* ResourceManager::GetFMODSound(const std::wstring& _key)
{
	std::unordered_map<std::wstring, Resource::FMODSound*>::iterator it = m_audioMap.find(_key);

	if (it == m_audioMap.end())
		return nullptr;

	return it->second;
}

bool ResourceManager::ReleaseSprite2D(const std::wstring& _key)
{
	auto it = m_spriteMap.find(_key);
	if (it == m_spriteMap.end())
		return false;
	delete (*it).second;
	m_spriteMap.erase(it);
	return true;
}

bool ResourceManager::ReleaseAnimation2D(const std::wstring& _key)
{
	auto it = m_animationMap.find(_key);
	if (it == m_animationMap.end())
		return false;
	m_animationMap.erase(it);
	return true;
}

bool ResourceManager::ReleaseFMODSound(const std::wstring& _key)
{
	auto it = m_audioMap.find(_key);
	if (it == m_audioMap.end())
		return false;
	m_audioMap.erase(it);
	return true;
}

void ResourceManager::Clear()
{
	// clear()로도 second값의 소멸자가 호출 된다네요? 
	// 안댐 
	m_spriteMap.clear();
	m_animationMap.clear();
}
