#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>

std::string GetString(const int& N, const int& K)
{
    std::string Buffer = "";

    if (K > (N / 2) * (N / 2 + N % 2))
    {
        return "-1";
    }
    else if (K == 0)
    {
        for(int i = 0; i < N - 1; ++i)
        {
            Buffer += 'B';
        }
        Buffer += 'A';
    }
    else
    {
        int i = 0, j = 1, Sum = 0;

        while (i < N)
        {
            if (N - j - i > 0 && Sum + N - (i + j) <= K)
            {
                Buffer += 'A';
                Sum += N - (i + j);
                j++;
            }
            else
            {
                Buffer += 'B';
            }
            i++;
        }
    }
    return Buffer;
}

int main()
{
    int N = 0, K = 0;
    scanf("%d %d", &N, &K);

    std::cout << GetString(N, K);
    return 0;
}