#include <iostream>
#include <array>

typedef long long LL;

bool IsCont(
    const std::array<LL, 4>& Elements,
    const LL& K)
{
    LL A = Elements[0], B = Elements[1],
        C = Elements[2], D = Elements[3];

    return ((A * K + B) == (C * K + D));
}

int main()
{
    LL K = 0;
    std::cin >> K;

    std::array<LL, 4> Elements;

    for (auto& Element : Elements)
    {
        std::cin >> Element;
    }

    if (IsCont(Elements, K))
    {
        std::cout << "Yes ";
        std::cout << Elements[0] * K + Elements[1];
    }
    else
    {
        std::cout << "No";
    }
    return 0;
}