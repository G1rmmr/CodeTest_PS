#include <iostream>
#include <array>

typedef long double LD;

double GetRecurRelation(std::array<LD, 3>& Elements)
{
    LD B = Elements[0], C = Elements[1];

    int i = 1000000;
    while (i--)
    {
        Elements[2] = B + C / (Elements[2]);
    }
    return Elements[2];
}

int main()
{
    std::array<LD, 4> Elements;

    for (auto& Element : Elements)
    {
        std::cin >> Element;
    }

    std::array<LD, 3> NewElements = {
        Elements[0], Elements[1], Elements[3] / Elements[2]
    };
    std::cout << std::fixed;
    std::cout.precision(9);

    std::cout << GetRecurRelation(NewElements);
    return 0;
}