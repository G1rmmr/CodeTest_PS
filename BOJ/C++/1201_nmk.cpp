#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

void GetSeq(const int& N, const int& M, const int& K,
    std::vector<int>& Seq)
{
    int SeqStart = 0;

    for (int e = 1; e <= M; ++e)
    {
        int SeqEnd = std::min(SeqStart + K, N - M + e);
        
        std::reverse(Seq.begin() + SeqStart,
            Seq.begin() + SeqEnd);

        SeqStart = SeqEnd;
    }
}

int main()
{
    int N = 0, M = 0, K = 0;
    scanf("%d %d %d", &N, &M, &K);

    std::vector<int> Seq(N);

    for (int i = 1; i <= N; ++i)
    {
        Seq[i - 1] = i;
    }

    if (N < M + K - 1 || N > M * K)
    {
        printf("%d ", -1);
    }
    else
    {
        GetSeq(N, M, K, Seq);

        for (const auto& Num : Seq)
        {
            printf("%d ", Num);
        }
    }
    return 0;
}