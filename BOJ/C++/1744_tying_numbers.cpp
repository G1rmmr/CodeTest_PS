#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int GetMax(
    const std::vector<int>& Naturals,
    const std::vector<int>& Negatives)
{
    int MaxSum = 0;

    for (int i = 0; i < Naturals.size(); i += 2)
    {
        MaxSum += Naturals[i] * Naturals[i + 1];
    }

    for (int i = 0; i < Negatives.size(); i += 2)
    {
        MaxSum += Negatives[i] * Negatives[i + 1];
    }
    return MaxSum;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<int> Naturals, Negatives;
    int NumZero = 0, NumOne = 0;

    while (N--)
    {
        int Num = 0;
        scanf("%d", &Num);

        if (Num == 0)
        {
            NumZero++;
        }
        else if (Num == 1)
        {
            NumOne++;
        }
        else if (Num > 0)
        {
            Naturals.emplace_back(Num);
        }
        else
        {
            Negatives.emplace_back(Num);
        }
    }

    std::sort(Naturals.begin(), Naturals.end(),
        std::greater<int>());

    std::sort(Negatives.begin(), Negatives.end());

    if (Naturals.size() % 2)
    {
        Naturals.emplace_back(1);
    }

    if (Negatives.size() % 2)
    {
        Negatives.emplace_back(NumZero > 0 ? 0 : 1);
    }

    int MaxSum = GetMax(Naturals, Negatives);

    printf("%d", MaxSum + NumOne);
    return 0;
}