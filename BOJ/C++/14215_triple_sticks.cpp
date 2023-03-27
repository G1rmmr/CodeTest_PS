#include <iostream>
#include <algorithm>

short Calc(short& A, short& B, short& C)
{
    short MaxSide = std::max(A, std::max(B, C));
    
    while ((A + B + C) <= 2 * MaxSide)
    {
        C--, MaxSide--;
    }
    return A + B + C;
}

int main()
{
    short A = 0, B = 0, C = 0;
    std::cin >> A >> B >> C;

    std::cout << Calc(A, B, C);
    return 0;
}