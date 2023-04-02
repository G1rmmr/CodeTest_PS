#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int GetMax(const int& N, const int& M, const int& K)
{
    int MaxTeam = 0;

    for (int i = 0; i <= K; ++i)
    {
        int WomenNum = (N - i) / 2;
        int ManNum = M - K + i;

        MaxTeam = std::max(MaxTeam,
            std::min(WomenNum, ManNum));
    }
    return MaxTeam;
}

int main()
{
    int N = 0, M = 0, K = 0;
    scanf("%d %d %d", &N, &M, &K);

    printf("%d", GetMax(N, M, K));
    return 0;
}