#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>

int GetTransform(
    const short& N, const short& M,
    std::vector<std::vector<short>>& Matrix,
    const std::vector<std::vector<short>>& TransfMatrix)
{
    int Count = 0;

    for (short i = 0; i < N - 2; ++i)
    {
        for (short j = 0; j < M - 2; ++j)
        {
            if (Matrix[i][j] != TransfMatrix[i][j])
            {
                for (short k = i; k < i + 3; ++k)
                {
                    for (short s = j; s < j + 3; ++s)
                    {
                        Matrix[k][s] = Matrix[k][s] ? 0 : 1;
                    }
                }
                Count++;
            }
            else
            {
                continue;
            }
        }
    }

    for (short i = 0; i < N; ++i)
    {
        for (short j = 0; j < M; ++j)
        {
            if (Matrix[i][j] != TransfMatrix[i][j])
            {
                return -1;
            }
        }
    }
    return Count;
}

int main()
{
    short N = 0, M = 0;
    scanf("%hd %hd", &N, &M);

    std::vector<std::vector<short>> Matrix(
        N, std::vector<short>(M));

    std::vector<std::vector<short>> TransfMatrix(
        N, std::vector<short>(M));

    for (auto& Row : Matrix)
    {
        for (auto& Num : Row)
        {
            scanf("%1hd", &Num);
        }
    }

    for (auto& Row : TransfMatrix)
    {
        for (auto& Num : Row)
        {
            scanf("%1hd", &Num);
        }
    }

    int Count = GetTransform(N, M, Matrix, TransfMatrix);

    printf("%d", Count);
    return 0;
}