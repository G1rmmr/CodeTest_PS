#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

int GetMax(const int& N, const int& M)
{
    if (N == 1)
    {
        return 1;
    }
    else if (N == 2)
    {
        return std::min(4, (M + 1) / 2);
    }
    else if (N >= 3)
    {
        if (M <= 6)
        {
            return std::min(4, M);
        }
        else
        {
            return M - 2;
        }
    }
}

int main()
{
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);

    printf("%d", GetMax(N, M));
    return 0;
}