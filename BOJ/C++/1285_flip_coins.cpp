#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

int GetMin(const int& N, const int& Row,
    const std::vector<std::string>& Coins)
{
    int MinCount = 0;

    for (int i = 0; i < N; ++i)
    {
        int HeadCount = 0;

        for (int j = 0; j < N; ++j)
        {
            bool bIsHead = (Coins[i][j] == 'H');

            if ((Row & (1 << j)) != 0)
            {
                bIsHead = !bIsHead;
            }

            if (bIsHead)
            {
                HeadCount++;
            }
        }
        MinCount += std::min(HeadCount, N - HeadCount);
    }
    return MinCount;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<std::string> Coins(N);

    for (auto& Row : Coins)
    {
        std::cin.ignore();
        std::cin >> Row;
    }

    int MinCount = 1e7;

    for (int i = 0; i < (1 << N); ++i)
    {
        MinCount = std::min(MinCount, GetMin(N, i, Coins));
    }

    printf("%d", MinCount);
    return 0;
}