#pragma once
#include "../Sprite2D.h"
#include "../Animation2D.h"
#include "../FMODSound.h"
#include "../Font.h"

class ResourceManager
{
public:
	// ===================���ҽ� �߰�===================
	static Resource::Sprite2D*     AddSprite2D(const std::wstring& _key, const std::wstring& _path, SpriteData _data = SpriteData());
	static Resource::Animation2D*  AddAnimation2D(const std::wstring& _key, Resource::Sprite2D* _sprite, std::vector<AnimationData>& _data);
	static Resource::FMODSound*	   AddFMODSound(const std::wstring& _key, const std::wstring& _path, bool isLoop, int _group);
	static Resource::Font*		   AddFont(const std::wstring& _key, const std::wstring& _path);
	// ===================���ҽ� ��������===================
	static Resource::Sprite2D*     GetSprite2D(const std::wstring& _key);
	static Resource::Animation2D*  GetAnimation2D(const std::wstring& _key);
	static Resource::FMODSound*    GetFMODSound(const std::wstring& _key);
	static Resource::Font*   	   GetFont(const std::wstring& _key);
	// ===================���ҽ� ����===================
	static bool ReleaseSprite2D(const std::wstring& _key);
	static bool ReleaseAnimation2D(const std::wstring& _key);
	static bool ReleaseFMODSound(const std::wstring& _key);
	static bool ReleaseFont(const std::wstring& _key);

	// Asset�⺻ ���
	static void SetAssetPath(std::wstring _path) { m_assetPath = _path; }

	// ===================���ҽ� ��ü ����===================
	static void Clear();

private:

	static std::wstring m_assetPath;
	static std::unordered_map<std::wstring, Resource::Sprite2D*> m_spriteMap;
	static std::unordered_map<std::wstring, Resource::Animation2D*> m_animationMap;
	static std::unordered_map<std::wstring, Resource::FMODSound*> m_audioMap;
	static std::unordered_map<std::wstring, Resource::Font*> m_fontMap;

};
