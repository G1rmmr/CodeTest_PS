#include <iostream>

typedef long long LL;

inline LL Calc(const LL& n)
{
    return 4 * n;
}

int main()
{
    LL n = 0;
    std::cin >> n;

    std::cout << Calc(n);
    return 0;
}