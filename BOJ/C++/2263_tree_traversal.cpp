#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const int kMAX = 100001;

std::vector<int> gTrace(kMAX), gInordered(kMAX), gPostordered(kMAX);

void DoPreorder(
    const std::size_t& InorderStart,
    const std::size_t& InorderEnd,
    const std::size_t& PostorderStart,
    const std::size_t& PostorderEnd)
{
    if (InorderStart > InorderEnd
        || PostorderStart > PostorderEnd)
    {
        return;
    }

    int Root = gPostordered[PostorderEnd];
    int Index = gTrace[Root], Length = Index - InorderStart;

    printf("%d ", Root);

    DoPreorder(InorderStart, Index - 1,
        PostorderStart, PostorderStart + Length - 1);

    DoPreorder(Index + 1, InorderEnd,
        PostorderStart + Length, PostorderEnd - 1);
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &gInordered[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &gPostordered[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        gTrace[gInordered[i]] = i;
    }

    DoPreorder(1, n, 1, n);
    return 0;
}