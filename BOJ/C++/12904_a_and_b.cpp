#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>

bool CanMake(const std::string& S, std::string& T)
{
    while (true)
    {
        if (S.length() == T.length())
        {
            return S == T ? true : false;
        }
        else if (T[T.length() - 1] == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }
    }
    return false;
}

int main()
{
    std::string S, T;
    std::cin >> S >> T;

    std::cout << CanMake(S, T);
    return 0;
}