#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

long long gCount = 0;

void MergeSort(const int& Start, const int& End,
    std::vector<int>& A)
{
    int Mid = (Start + End) / 2;
    int Left = Start, Right = Mid + 1;

    std::vector<int> Buffer;

    if (Start == End)
    {
        return;
    }

    MergeSort(Start, Mid, A);
    MergeSort(Mid + 1, End, A);

    while (Left <= Mid && Right <= End)
    {
        if (A[Left] <= A[Right])
        {
            Buffer.emplace_back(A[Left++]);
        }
        else
        {
            Buffer.emplace_back(A[Right++]);
            gCount += (Mid + 1 - Left);
        }
    }

    while (Left <= Mid)
    {
        Buffer.emplace_back(A[Left++]);
    }

    while (Right <= End)
    {
        Buffer.emplace_back(A[Right++]);
    }

    for (std::size_t i = Start, j = 0; i <= End; ++i, ++j)
    {
        A[i] = Buffer[j];
    }
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<int> A(N);

    for (auto& Num : A)
    {
        scanf("%d", &Num);
    }

    MergeSort(0, N - 1, A);

    printf("%lld", gCount);
    return 0;
}