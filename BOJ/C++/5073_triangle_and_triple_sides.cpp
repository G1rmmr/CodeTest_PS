#include <iostream>
#include <algorithm>

void Calc(const short& A, const short& B, const short& C)
{
    short MaxSide = std::max(A, std::max(B, C));

    if ((A + B + C) > 2 * MaxSide)
    {
        if ((A == B) && (A == C))
        {
            std::cout << "Equilateral\n";
        }
        else if((A != B) && (B != C) && (C != A))
        {
            std::cout << "Scalene\n";
        }
        else
        {
            std::cout << "Isosceles\n";
        }
    }
    else
    {
        std::cout << "Invalid\n";
    }
}

int main()
{
    while (true)
    {
        short A = 0, B = 0, C = 0;
        std::cin >> A >> B >> C;

        if (A + B + C)
        {
            Calc(A, B, C);
        }
        else
        {
            break;
        }
    }
    return 0;
}