#include "pch.h"
#include "CollisionManager.h"

int CollisionManager::ProcessCycle = 0;
bool CollisionManager::m_collisionLayer[(int)LayerTag::SIZE] = {};
std::unordered_map<UINT64, bool> CollisionManager::m_collisionMap = {};
int CollisionManager::collisionCount = 0;
int CollisionManager::objectCount = 0;
std::vector<Layer*> CollisionManager::tempLayer;

void CollisionManager::SetCollsionLayer(LayerTag _layerTag, bool _isCheck)
{
	m_collisionLayer[(int)_layerTag] = _isCheck;
}

bool CollisionManager::GetCollisionID(Collider* left, Collider* right)
{
	// �� �浹ü��  ID Ȯ��
	CollisionID collisionID;

	if (left->GetID() > right->GetID())
	{
		collisionID.right = left->GetID();
		collisionID.left = right->GetID();
	}
	else
	{
		collisionID.left = left->GetID();
		collisionID.right = right->GetID();
	}

	// ���� �浹������ �˻��Ѵ�.
	auto iter = m_collisionMap.find(collisionID.id);

	// �浹������ ���ٸ� �浹������ ������ش�.
	if (iter == m_collisionMap.end())
	{
		m_collisionMap.insert(std::make_pair(collisionID.id, false));
		iter = m_collisionMap.find(collisionID.id);
	}
	return iter->second;
}

void CollisionManager::SetCollisionID(Collider* left, Collider* right, bool enable)
{
	// �� �浹ü��  ID Ȯ��
	CollisionID collisionID;

	if (left->GetID() > right->GetID())
	{
		collisionID.right = left->GetID();
		collisionID.left = right->GetID();
	}
	else
	{
		collisionID.left = left->GetID();
		collisionID.right = right->GetID();
	}
	

	// ���� �浹������ �˻��Ѵ�.
	auto iter = m_collisionMap.find(collisionID.id);

	iter->second = enable;
}

void CollisionManager::CollsionProcess()
{
	collisionCount = 0;
	objectCount = 0;
	tempLayer.clear();

	MergeCollisionLayer();

	IterateCollisionLayer();
	//Debug.Log("Total Object Count : " + std::to_string(objectCount));
	//Debug.Log("Total Collision Check : " + std::to_string(collisionCount));
}

void CollisionManager::MergeCollisionLayer()
{
	// �ӽ� ���Ϳ� ���극�̾�� �۽ý��Ͻ����̾ ��ħ (��ȸ�ϱ� ���Ϸ��� �׳� �Ѱ�)
	for (int i = 0; i < (int)LayerTag::SIZE; i++)
	{
		// �浹üũ�� �� ���̾ ��ġ�� �ʤ���
		if (m_collisionLayer[(int)i])
		{
			tempLayer.push_back(WorldManager::GetActiveWorld()->GetLayerList()[i]);
			objectCount += tempLayer.back()->GetObjectList().size(); // ������Ʈ �� ����
		}
	}
}

void CollisionManager::IterateCollisionLayer()
{
	// left���̾� ��ȸ
	for (int leftIndex = 0; leftIndex < tempLayer.size(); ++leftIndex)
	{
		// ��ȸ�� ���ʷ��̾��� ������Ʈ ����Ʈ�� ������
		auto& leftList = tempLayer[leftIndex]->GetObjectList();
		// ���̾��� ������Ʈ�� ��ȸ�ϸ� �˻��Ѵ�. 
		// left������Ʈ�� right������Ʈ�� ���Ǻб⸦ �� ������ �˻縦 ����
		for (auto _left = leftList.begin(); _left != leftList.end(); ++_left)
		{
			// ������Ʈ�� ���� �� �ִ� Actor���� Ȯ��
			Actor* left = dynamic_cast<Actor*>(*(_left));
			if (left)
			{
				// right���̾� ��ȸ. �̶� �ߺ� üũ�� ���԰� ���ÿ� �˻�ð��� �ٿ����Ѵ�.
				// (�̹� left������ �˻��� ���̾�� �����ؾߴ�� rightIndex = leftIndex�� ����)
				for (int rightIndex = leftIndex; rightIndex < tempLayer.size(); ++rightIndex)
				{
					// ��ȸ�� �����ʷ��̾��� ������Ʈ ����Ʈ�� ������
					auto& rightList = tempLayer[rightIndex]->GetObjectList();
					// �ڱ��ڽ��� �˻��ϴ� ���� ���ؾ��Ѵ�. ���� right������Ʈ�� left�� ������ �;��Ѵ�. (���� �������� �ߺ��˻縦 ���ϱ� ����).
					// left���̾�� right���̾ ������ right�ݺ��ڴ� left�� ������带 ����Ű�� �Ѵ�.(std::next()�Լ� �����µ� gpt���� �� ��)
					// left���̾�� right���̾ ���� ������ right�ݺ��ڴ� ������Ʈ ����Ʈ�� ó���� ����Ű�� �ȴ�.
					auto _right = (leftIndex == rightIndex) ? std::next(_left) : rightList.begin();
					// ������ right�ݺ��ڸ� �������� ������Ʈ��ȸ�� �����Ѵ�.
					for (; _right != rightList.end(); ++_right)
					{
						// ������Ʈ�� ���� �� �ִ� Actor���� Ȯ��
						Actor* right = dynamic_cast<Actor*>((*_right));
						if (right)
						{
							if(left->GetState() == GameState::Active && right->GetState() == GameState::Active)
							CheckCollider(left, right);
							//Debug.Log(std::to_string(collisionCount) + (collisionCount >= 10 ? "" : " ") +
								//"st CollisionCheck    " + left->GetName() + " : " + right->GetName());
						}
					}
				}
			}
		}
	}

}

void CollisionManager::CheckCollider(Actor* _left, Actor* _right)
{

	collisionCount++; // �׳� �浹üũ�� ����ϴ��� ����

	// ������Ʈ�� �ݶ��̴��� �޾ƿ´�.
	Collider* _leftCollider = _left->GetComponent<Collider>();
	Collider* _rightCollider = _right->GetComponent<Collider>();

	// �Ѵ� �ݶ��̴��� ���� �ÿ��� �˻縦 �Ѵ�.
	if (_leftCollider && _rightCollider)
	{
		// ID���� ���� ������ �浹���¸� Ȯ��
		bool check = GetCollisionID(_leftCollider, _rightCollider);

		if (CheckCollision(_leftCollider, _rightCollider))
		{
			// �浹������ �ʾ����� Enter
			if (check == false)
			{
				_leftCollider->OnCollisionEnter(_right);
				_rightCollider->OnCollisionEnter(_left);
				SetCollisionID(_leftCollider, _rightCollider, true);
			}
			// �̹� �浹���̾����� Stay
			else if (check == true)
			{
				_leftCollider->OnCollisionStay(_right);
				_rightCollider->OnCollisionStay(_left);
			}
		}
		else
		{
			// �浹���� �ʾҴµ� ���� ƽ�� �浹���̾����� Exit
			if (check == true)
			{
				_leftCollider->OnCollisionExit(_right);
				_rightCollider->OnCollisionExit(_left);
				SetCollisionID(_leftCollider, _rightCollider, false);
			}
		}
	}
}

bool CollisionManager::CheckCollision(Collider* _left, Collider* _right)
{
	GameState leftState = _left->GetState();
	GameState rightState = _right->GetState();
	if (leftState == GameState::Active && rightState == GameState::Active)
	{
		// �ݶ��̴� Ÿ���� �޾ƿ´�.
		ComponentType _leftType = _left->GetType();
		ComponentType _rightType = _right->GetType();

		// �ݶ��̴��� ������ ���� �ٸ� �浹 �˰����� ȣ���Ѵ�.
		if (_leftType == ComponentType::BoxCollider2D && _rightType == ComponentType::BoxCollider2D)
			return (BoxToBox(dynamic_cast<BoxCollider2D*>(_left), dynamic_cast<BoxCollider2D*>(_right)));
	}
	else return false;
}

bool CollisionManager::BoxToBox(BoxCollider2D* _left, BoxCollider2D* _right)
{
	// �Ʒ��� �浹�˻� ����
	Vector2 leftTr = _left->gameObject->transform->WorldPosition() - _left->offset;
	Vector2 rightTr = _right->gameObject->transform->WorldPosition() - _right->offset;

	// self min,max
	float left_xmin = leftTr.x - _left->size.x / 2;
	float left_xmax = leftTr.x + _left->size.x / 2;
	float left_ymin = leftTr.y - _left->size.y / 2;
	float left_ymax = leftTr.y + _left->size.y / 2;

	// other min,max
	float right_xmin = rightTr.x - _right->size.x / 2;
	float right_xmax = rightTr.x + _right->size.x / 2;
	float right_ymin = rightTr.y - _right->size.y / 2;
	float right_ymax = rightTr.y + _right->size.y / 2;

	if (left_xmax < right_xmin ||  // �����ʿ� ������ ��ĥ���� ����
		left_xmin > right_xmax ||  // ���ʿ� ������ ��ĥ���� ����
		left_ymax < right_ymin ||  // �Ʒ��� ������ ��ĥ���� ����
		left_ymin > right_ymax)	  // ���� ������ ��ĥ���� ����
	{
		return false;
	}

	return true;
}