#pragma once

class Random
{
private:

    static std::random_device seed;
    static std::mt19937 engine;

public:
    Random() = delete; // ��ü ���� ����

    template<typename T>
    static T Range(T _min, T _max)
    {
        std::uniform_real_distribution<T> dist(_min, _max);
        return dist(engine);
    }

    // ���� Ÿ�Կ� ���� Range �Լ� Ư��ȭ
    template<>
    static int Range(int _min, int _max)
    {
        std::uniform_int_distribution<int> dist(_min, _max);
        return dist(engine);
    }
    static int Range(int _min, size_t _max)
    {
        std::uniform_int_distribution<int> dist(_min, _max);
        return dist(engine);
    }

    // ���� ���� ���� ����
    static float NormalDist(float _mean, float _stdDev)
    {
        std::normal_distribution<float> dist(_mean, _stdDev);
        return dist(engine);
    }

    // �����̳��� ��Ҹ� �������� ����
    template<typename T>
    static void Shuffle(std::vector<T>& _arr)
    {
        std::shuffle(_arr.begin(), _arr.end(), engine);
    }

    // ����ġ ��� ���� ����
    template<typename T>
    static T RandomByAccumulatedProb(const std::vector<std::pair<T, float>>& _arr)
    {
        std::vector<float> weights;
        for (const auto& item : _arr)
        {
            weights.push_back(item.second);
        }

        std::discrete_distribution<> dist(weights.begin(), weights.end());
        return _arr[dist(engine)].first;
    }
};