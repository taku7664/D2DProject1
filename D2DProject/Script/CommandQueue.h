#pragma once
#include <vector>
class CommandQueue
{
private:
	std::vector<int> m_queue;
public:

	float count = 0;

	CommandQueue(int _size = 5)
		: m_queue(_size, -1)
	{
	}
	~CommandQueue()
	{
	}
	void resize(int _size)
	{
		m_queue.clear();
		m_queue.resize(_size);
	}
	void push(char _data)
	{
		// 데이터를 뒤로 당김
		for (int i = m_queue.size() - 1; i != 0; i--)
		{
			m_queue[i] = m_queue[i - 1];
		}

		m_queue[0] = _data; // 새 데이터를 맨 앞에 추가
		count = 0.f;
	}
	void clear()
	{
		std::fill(m_queue.begin(), m_queue.end(), -1);
	}
	int& operator[](int _index)
	{
		return m_queue[_index];
	}
};