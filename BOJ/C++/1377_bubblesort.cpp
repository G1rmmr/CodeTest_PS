#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

int GetIndex(const int& N,
    std::vector<std::pair<int, int>>& A)
{
    std::sort(A.begin(), A.end());
    int Index = -1;

    for (int i = 0; i < N; ++i)
    {
        Index = std::max(Index, A[i].second - i);
    }
    return ++Index;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<std::pair<int, int>> A(N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }

    printf("%d", GetIndex(N, A));
    return 0;
}