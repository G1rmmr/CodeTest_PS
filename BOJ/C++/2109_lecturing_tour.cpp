#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

const int kMAX = 10000;

std::vector<int> gSugestions[kMAX + 1];

int GetMax()
{
    std::priority_queue<int> PriQueue;
    int MaxSum = 0;

    for (int i = kMAX; i > 0; --i)
    {
        for (auto Sugestion : gSugestions[i])
        {
            PriQueue.push(Sugestion);
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
    int n = 0, p = 0, d = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &p, &d);
        gSugestions[d].emplace_back(p);
    }

    int MaxSum = GetMax();

    printf("%d", MaxSum);
    return 0;
}