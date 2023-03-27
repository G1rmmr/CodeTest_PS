#include <iostream>
#include <array>
#include <numeric>

void Calc(const std::array<short, 3>& Angles)
{
    if (std::accumulate(
        Angles.begin(), Angles.end(), 0)
        != 180)
    {
        std::cout << "Error";
    }
    else
    {
        if (Angles[0] == Angles[1]
            && Angles[2] == Angles[0])
        {
            std::cout << "Equilateral";
        }
        else if (Angles[0] != Angles[1]
            && Angles[1] != Angles[2]
            && Angles[2] != Angles[0])
        {
            std::cout << "Scalene";
        }
        else
        {
            std::cout << "Isosceles";
        }
    }
}

int main()
{
    std::array<short, 3> Angles;

    for (auto& Angle : Angles)
    {
        std::cin >> Angle;
    }

    Calc(Angles);
    return 0;
}