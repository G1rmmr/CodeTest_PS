#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>

void CanMake(const std::string& S, const std::string& T)
{
    std::string Buffer;

    if (S == T)
    {
        std::cout << 1;
        exit(0);
    }

    if (S.length() >= T.length())
    {
        return;
    }

    if (*(T.end() - 1) == 'A')
    {
        Buffer = T;
        Buffer.erase(Buffer.end() - 1);
        CanMake(S, Buffer);
    }
        
    if (T[0] == 'B')
    {
        Buffer = T;
        Buffer.erase(Buffer.begin());

        std::reverse(Buffer.begin(), Buffer.end());
        CanMake(S, Buffer);
    }
}

int main()
{
    std::string S, T;
    std::cin >> S >> T;

    CanMake(S, T);

    std::cout << 0;
    return 0;
}