#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>

std::string GetMax(std::string& N)
{
    std::sort(N.begin(), N.end(),
        std::greater<char>());

    if (N[N.length() - 1] != '0')
    {
        return "-1";
    }
    else
    {
        long long MaxSum = 0;

        for (const auto& Digit : N)
        {
            MaxSum += Digit - '0';
        }

        if (!(MaxSum % 3))
        {
            return N;
        }
        else
        {
            return "-1";
        }
    }
}

int main()
{
    std::string N;
    std::cin >> N;

    std::cout << GetMax(N);
    return 0;
}