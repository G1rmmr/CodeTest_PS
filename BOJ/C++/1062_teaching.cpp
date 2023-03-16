#include <iostream>
#include <algorithm>
#include <array>
#include <string>

static std::array<int, 50> gBWords;

void DFS(
    const short& N,
    const short& WordIndex,
    const int& Start,
    short& MaxCount,
    int& Bit)
{
    if (!WordIndex)
    {
        short WordCount = 0;

        for (short i = 0; i < N; ++i)
        {
            if ((gBWords[i] & Bit) == gBWords[i])
            {
                WordCount++;
            }
        }
        MaxCount = std::max(MaxCount, WordCount);
        return;
    }

    for (int i = Start; i < 26; ++i)
    {
        if (!(Bit & (1 << i)))
        {
            Bit |= (1 << i);
            DFS(N, WordIndex - 1, i, MaxCount, Bit);
            Bit &= ~(1 << i);
        }
    }
}

int main()
{
    short N = 0, K = 0;
    std::string Word;

    std::cin >> N >> K;

    for (short i = 0; i < N; ++i)
    {
        std::cin >> Word;

        int Bit = 0;
        for (const auto& E : Word)
        {
            Bit |= 1 << (E - 'a');
        }
        gBWords[i] = Bit;
    }

    if (K < 5)
    {
        std::cout << 0;
    }
    else if (K == 26)
    {
        std::cout << N;
    }
    else
    {
        short MaxCount = 0;
        int Bit = 0;

        Bit |= 1 << ('a' - 'a');
        Bit |= 1 << ('c' - 'a');
        Bit |= 1 << ('i' - 'a');
        Bit |= 1 << ('n' - 'a');
        Bit |= 1 << ('t' - 'a');

        DFS(N, K - 5, 0, MaxCount, Bit);
        std::cout << MaxCount;
    }
    return 0;
}