#include <iostream>

std::pair<short, short> GetCalc(
    const short& a, const short& b, const short& c,
    const short& d, const short& e, const short& f)
{
    std::pair<short, short> Answer;

    for (short i = -999; i < 1000; ++i)
    {
        for (short j = -999; j < 1000; ++j)
        {
            if ((a * i + b * j == c)
                && (d * i + e * j == f))
            {
                Answer = std::make_pair(i, j);
            }
        }
    }
    return Answer;
}

int main()
{
    short a = 0, b = 0, c = 0;
    short d = 0, e = 0, f = 0;

    std::cin >> a >> b >> c;
    std::cin >> d >> e >> f;

    std::pair<short, short> Answer
        = GetCalc(a, b, c, d, e, f);

    std::cout << Answer.first << ' ' << Answer.second;
    return 0;
}