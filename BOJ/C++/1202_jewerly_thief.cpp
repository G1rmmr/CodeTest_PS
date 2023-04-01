#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long LL;

LL GetMax(const int& N, const int& K,
    std::vector<std::pair<int, int>>& Jewerlies,
    std::vector<int>& Bag)
{
    std::priority_queue<int, std::vector<int>, std::less<int>>
        PriQueue;

    std::sort(Jewerlies.begin(), Jewerlies.end());
    std::sort(Bag.begin(), Bag.end());

    int index = 0;
    LL MaxSum = 0L;

    for (int i = 0; i < K; ++i)
    {
        while (index < N && Bag[i] >= Jewerlies[index].first)
        {
            PriQueue.push(Jewerlies[index].second);
            index++;
        }

        if (!PriQueue.empty())
        {
            MaxSum += PriQueue.top();
            PriQueue.pop();
        }
    }
    return MaxSum;
}

int main()
{
    int N = 0, K = 0;
    scanf("%d %d", &N, &K);

    std::vector<std::pair<int, int>> Jewerlies;
    int M = 0, V = 0;

    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d", &M, &V);
        Jewerlies.emplace_back(std::make_pair(M, V));
    }

    std::vector<int> Bag;
    int C = 0;

    for (int i = 0; i < K; ++i)
    {
        scanf("%d", &C);
        Bag.emplace_back(C);
    }

    LL MaxSum = GetMax(N, K, Jewerlies, Bag);

    printf("%lld", MaxSum);
    return 0;
}