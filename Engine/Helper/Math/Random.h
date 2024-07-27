#pragma once

class Random
{
private:

    static std::random_device seed;
    static std::mt19937 engine;

public:
    Random() = delete; // 객체 생성 방지

    template<typename T>
    static T Range(T _min, T _max)
    {
        std::uniform_real_distribution<T> dist(_min, _max);
        return dist(engine);
    }

    // 정수 타입에 대한 Range 함수 특수화
    template<>
    static int Range(int _min, int _max)
    {
        std::uniform_int_distribution<int> dist(_min, _max);
        return dist(engine);
    }

    // 정규 분포 난수 생성
    static float NormalDist(float _mean, float _stdDev)
    {
        std::normal_distribution<float> dist(_mean, _stdDev);
        return dist(engine);
    }

    // 컨테이너의 요소를 무작위로 섞기
    template<typename T>
    static void Shuffle(std::vector<T>& _arr)
    {
        std::shuffle(_arr.begin(), _arr.end(), engine);
    }

    // 가중치 기반 랜덤 선택
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