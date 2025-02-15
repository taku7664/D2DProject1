#pragma once
#include "../Object.h"
// ExtraComponent
#include "../../../Component/Transform2D.h"
#include "../../../Component/Camera2D.h"
#include "../../../Component/Script.h"
#include "../../../Component/FiniteStateMachine.h"
#include "../../../Component/Button.h"
#include "../../../Component/FMODPlayer.h"
// RenderComponent
#include "../../../Component/Rednerer/SpriteRenderer2D.h"
#include "../../../Component/Rednerer/Animator2D.h"
#include "../../../Component/Rednerer/RectRenderer.h"
#include "../../../Component/Rednerer/LineRenderer.h"
#include "../../../Component/Rednerer/TextRenderer.h"
// ColliderComponent
#include "../../../Component/Collider/BoxCollider2D.h"
#include "../../../Component/Collider/CircleCollider2D.h"

class Component;
class Layer;
class Object;
class LineRenderer;
class TextRenderer;

class Actor
	: public Object
{
public:
	Actor(std::string _name, ObjectTag _tag = ObjectTag::Defalut);
	~Actor();

	void FixedUpdate();
	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void Draw(Camera2D* _camera);
	void Render();

	std::vector<Component*>& GetComponentList(ComponentType _type) { return m_componentList[(int)_type]; }

	template <typename T>
	T* AddComponent()
	{
		T* temp = new T();
		temp->gameObject = this;
		ComponentType type = temp->GetType();
		m_componentList[(int)type].push_back(temp);
		temp->Initialize();
		return temp;
	}

	template <typename T>
	T* GetComponent(ComponentType _type = (ComponentType)0) {
		T* temp;
		for (int i = (int)_type; i < (int)ComponentType::SIZE; i++)
		{
			for (Component* comp : m_componentList[i])
			{
				if (comp)
				{
					if (temp = dynamic_cast<T*>(comp))
						return temp;
				}
			}
		}
		return nullptr;
	}
	template <typename T>
	std::vector<T*> GetComponentList(ComponentType _type = (ComponentType)0)
	{
		std::vector<T*> tempList; 
		for (Component* comp : m_componentList[(int)_type]) {
			if (T* cast = dynamic_cast<T*>(comp)) {
				tempList.push_back(cast);
			}
		}
		return tempList;
	}

	void		SetActive(bool _val);
	void		SetDestroy();
	
private:
	std::vector<Component*> m_componentList[(int)ComponentType::SIZE];

	void CallOnEnalbe();
	void CallOnDisalbe();
	void CallOnDestroy();

};

