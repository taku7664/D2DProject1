#pragma once
#include "Component.h"

class Actor;
class WorldManager;

class Script : public Component
{
public:

	Script();
	virtual ~Script();

	virtual void Start() {} // 컴포넌트를 추가한 직후 바로 호출됩니다.

	virtual void Initialize() override
	{
		Start();
	}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void LateUpadte() {}

	// ============스크립트에서 사용하는 함수============
	void         Destroy(Object* _obj);
	void         SetPersistentObject(Object* _obj, bool _isPersistent);

	template<typename T>
	T*			 CreateObject(const std::string& _name = "", const LayerTag _layerTag = LayerTag::Defalut, ObjectTag _objectTag = ObjectTag::Defalut);
	template<typename T>
	T*			 FindObject(const std::string& _name, const LayerTag _tag = LayerTag::Defalut);

	void		 ChangeWorld(std::string _key);

	// ============외부에서 호출받는 함수 (충돌, 버튼, 활성화 등등)============
	virtual void OnEnable() {}; // 오브젝트가 활성화 되면 호출됩니다.
	virtual void OnDisable() {}; // 오브젝트가 비활성화 되면 호출됩니다.
	virtual void OnDestroy() {}; // 오브젝트가 파괴될 때 호출됩니다.
	virtual void OnCollisionEnter(Actor* _collision) {};
	virtual void OnCollisionStay(Actor* _collision) {};
	virtual void OnCollisionExit(Actor* _collision) {};
	virtual void OnMouseEnter() {}; // 마우스가 해당 버튼 내에 처음으로 들어왔을 때 호출됩니다.
	virtual void OnMouseStay() {}; // 마우스가 해당 버튼 내에 있는동안 매 업데이트마다 호출됩니다.
	virtual void OnMouseExit() {}; // 마우스가 해당 버튼에서 나올 시 호출됩니다.
	virtual void OnAnimationEnter(int _index) {};
};

template<typename T>
inline T* Script::CreateObject(const std::string& _name, const LayerTag _layerTag, ObjectTag _objectTag)
{
	return WorldManager::GetActiveWorld()->CreateObject<T>(_name, _layerTag, _objectTag);
}

template<typename T>
T* Script::FindObject(const std::string& _name, const LayerTag _tag)
{
	return WorldManager::GetActiveWorld()->FindObject<T>(_name, _tag);
}