#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

int gCount = 0;

void ZTrace(const int& r, const int& c,
    const int& Y, const int& X, const int& N)
{
    if (Y == r && X == c)
    {
        printf("%d", gCount);
        return;
    }

    if ((r < Y + N && r >= Y) && (c < X + N && c >= X))
    {
        ZTrace(r, c, Y, X, N / 2);
        ZTrace(r, c, Y, X + N / 2, N / 2);
        ZTrace(r, c, Y + N / 2, X, N / 2);
        ZTrace(r, c, Y + N / 2, X + N / 2, N / 2);
    }
    else
    {
        gCount += N * N;
    }
}

int main()
{
    int N = 0, r = 0, c = 0;
    scanf("%d %d %d", &N, &r, &c);

    ZTrace(r, c, 0, 0, (1 << N));
    return 0;
}