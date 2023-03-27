#include <iostream>
#include <algorithm>

const short kMAX = 10001;

inline int Calc(const int& MinX, const int& MinY,
    const int& MaxX, const int& MaxY)
{
    return (MaxX - MinX) * (MaxY - MinY);
}

int main()
{
    int N = 0;
    std::cin >> N;

    int MinX = kMAX, MinY = kMAX;
    int MaxX = -kMAX, MaxY = -kMAX;

    while (N--)
    {
        int X = 0, Y = 0;
        std::cin >> X >> Y;

        MinX = std::min(MinX, X);
        MinY = std::min(MinY, Y);
        MaxX = std::max(MaxX, X);
        MaxY = std::max(MaxY, Y);
    }
 
    std::cout << Calc(MinX, MinY, MaxX, MaxY);
    return 0;
}