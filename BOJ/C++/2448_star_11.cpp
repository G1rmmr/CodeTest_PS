#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <array>

const int kMAX = 3 * (1 << 10) + 1;

std::array<std::array<char, 2 * kMAX>, kMAX> gStars;

void SetStars(const int& Y, const int& X, const int& N)
{
    if (N == 3)
    {
        gStars[Y][X] = '*';
        
        gStars[Y + 1][X - 1] = '*';
        gStars[Y + 1][X + 1] = '*';

        for (int i = X - 2; i <= X + 2; ++i)
        {
            gStars[Y + 2][i] = '*';
        }
        return;
    }

    SetStars(Y, X, N / 2);
    SetStars(Y + N / 2, X - N / 2, N / 2);
    SetStars(Y + N / 2, X + N / 2, N / 2);
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    for (auto& Row : gStars)
    {
        std::fill(Row.begin(), Row.end(), ' ');
    }

    SetStars(0, N - 1, N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 2 * N - 1; ++j)
        {
            printf("%c", gStars[i][j]);
        }
        printf("\n");
    }
    return 0;
}